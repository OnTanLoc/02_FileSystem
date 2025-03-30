#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

void main() 
{
	char *file = "example.txt";
	struct stat fileStat;
	int fd;

	fd = open("example.txt", O_RDWR);//mo file
	int rd_bytes = write(fd,"hello world",12);//ghi hello world vao file

    
    if (stat(file, &fileStat) == -1) {
        perror("loi doc trang file");
       
    }

    
    if (S_ISREG(fileStat.st_mode))
    {
        printf("File type: Regular file\n");
    }

    else if (S_ISDIR(fileStat.st_mode))
    {
        printf("File type: Directory\n");
    }

    else if (S_ISLNK(fileStat.st_mode))
    {
        printf("File type: Symbolic link\n");
    }

    else
    {
        printf("File type: Other\n");
    }
	printf("ten file: %s bytes\n", file);
	printf("kich thuoc: %ld bytes\n", fileStat.st_size);
	printf("thoi gian sua file lan cuoi: %s", ctime(&fileStat.st_mtime)); 

}

