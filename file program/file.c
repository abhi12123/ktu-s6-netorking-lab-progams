#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int size,i=0,n=0;
	char value[30],buf[30];

	printf("enter the number of employees:\t");
	scanf("%d",&size);

	int fd=open("employee.txt",O_RDWR|O_CREAT,0700);
	if(fd==-1){
		printf("ERROR\n");
		exit(1);
	}
		
	printf("Enter the names of %d employees\n",size);

	while(size>0){
		scanf("%s",value);
		write(fd,value,strlen(value));
		write(fd,"\n",strlen("\n"));
		size--;
	}

	lseek(fd,0,SEEK_SET);
	while(read(fd,&buf[i],1)==1){
		if(buf[i]=='\n'){
			if(buf[0]=='s'){
				n++;
			}
			i=0;
			continue;
		}
		i++;
	}
	close(fd);
	printf("executed\n");
	printf("%d",n);
}
		
