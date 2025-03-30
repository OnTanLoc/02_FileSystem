#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
	int fd1, fd3;
	fd1 = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	fd3 = open("file.txt", O_RDWR);
	write(fd1, "Hello,", 6);
	//in ra "Hello,"  trong file do noi dung in trong systemcall write la "Hello," so ki tu la 6

	write(fd2, "world", 6);
	//bao loi do khong tim thay fd2
	//error: ‘fd2’ undeclared (first use in this function); did you mean ‘fd3’?
	
	lseek(fd2, 0, SEEK_SET);
	//bao loi fd2 chua duoc khoi tao
	//error: ‘fd2’ undeclared (first use in this function); did you mean ‘fd3’?

	write(fd1, "HELLO,", 6);
	//in ra "Hello,HELLO," trong file do systemcall write cua fd1 ben tren khong loi se in ra "Hello," tuong tu in them "HELLO," cua systemcall write ben duoi

	write(fd3, "Gidday", 6);
	//in ra "GiddayHELLO do con tro cua fd1 la tu 0-12 con tro cua fd3 tu 0-6 nen se ghi de len du lieu cua fd1
}
