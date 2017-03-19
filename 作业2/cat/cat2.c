#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(void)
{
	int fd,size;
	char buffer[80];
	fd=open("./foo.text",O_RDONLY);
	if(fd==-1)
	{
		printf("open error");
	}
	else
	{
		size=read(fd,buffer,sizeof(buffer));
		close(fd);
		printf("%s",buffer);
	}
}
