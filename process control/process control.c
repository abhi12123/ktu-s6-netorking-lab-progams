#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void shp(int signo){
	printf("Interrupt ..  exiting parent\n");
	exit(0);
}

void shc(int signo){
	printf("Interrupt .. exiting Child\n");
	exit(0);
}

void shcd(int signo){
	printf("Child dead ..\n");
}

int main(){
	int i,p1,p2;
	p1=fork();
	if(p1==0){
		for(i=0;i<=3;i++){
			sleep(1);
			printf("Child Executing\n");
			signal(SIGINT,shc);
		}
	}
	else{
		for(;;){
			sleep(1);
			printf("Parent Executing\n");
			signal(SIGINT,shp);
			signal(SIGCHLD,shcd);
		}
	}
	return 0;
}