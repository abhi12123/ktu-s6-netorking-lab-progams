
#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>

void main(){
	int msgid,p;
	struct mymsg{
		long mtype;
		char mtext[50];	
	}msg1,msg2;
	msgid=msgget(IPC_PRIVATE,0777|IPC_CREAT);
	if(msgid==2){
		printf("fail\n");
		exit(2);
	}
	p=fork();
	if(p==-1){
		printf("error\n");;
		exit(1);
	}
	while(1){
		if(p==0){
			sleep(1);
			printf("Child:\n");
			fgets(msg1.mtext,50,stdin);
			msg1.mtype=1;
			msgsnd(msgid,&msg1,50,0);
			sleep(1);
			msgrcv(msgid,&msg2,50,0,IPC_NOWAIT);
			printf("CHild to parent ->%s\n",msg2.mtext );
			sleep(1);
			printf("Parent:\n");
			fgets(msg2.mtext,50,stdin);
			msg2.mtype=2;
			msgsnd(msgid,&msg2,50,0);
			sleep(1);
			msgrcv(msgid,&msg1,50,0,IPC_NOWAIT);
			printf("parent to Chile->%s\n",msg1.mtext );
		}
	}
}