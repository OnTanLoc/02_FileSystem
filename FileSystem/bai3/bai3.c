#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc,char *argv[])
{
	char *filename = argv[1];
	int num_bytes = atoi(argv[2]);
    	char mode = argv[3][0];//ki tu thu [0] cua argv[3]
    	char *text = argv[4];

	if(mode == 'r')
	{
		int fd1 = open("filename.txt",O_RDONLY);
		if (fd1 == -1)
		{
			perror("error read");
			exit(EXIT_FAILURE);
		}

		char *buf = (char*)malloc(num_bytes + 1);//+ 1 byte cua \0
		int bytes_rd = read(fd1,buf,num_bytes);//doc du lieu luu vao buf
		buf[bytes_rd] = '\0';
		printf("read %d byte: %s\n",bytes_rd,buf);//cap phat do read co kich thuoc xac dinh

		close(fd1);
		free(buf);
	}


        if(mode == 'w')
        {
                int fd2 = open(filename,O_WRONLY);
		if (fd2 == -1)
		{
			perror("error write");
			exit(EXIT_FAILURE);
		}
	
		int bytes_wr = write(fd2,text,num_bytes);
		printf("write %d bytes to file %s \n",bytes_wr,filename);

		close(fd2);
        }

	
}
