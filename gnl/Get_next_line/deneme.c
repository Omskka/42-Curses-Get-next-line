#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd;
	char *a;

	fd = open("a.txt",O_RDONLY,0777);
	read(fd, a, 3);
	printf("%s\n", a);
	}