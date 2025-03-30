#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	char buf[11] = "Hello World";

	int fd = open("writefile.txt",O_CREAT |  O_WRONLY | O_TRUNC | O_APPEND);
	//O_CREAT tao tep neu ko ton tai
	//O_TRUNC xoa nd da ton tai
	lseek(fd, 0, SEEK_SET);
	write(fd,buf,strlen(buf) );
	close(fd);

	// du lieu luon duoc ghi o cuoi file do flag O_APPEND bat ke con tro dang o dau
}
