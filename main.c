#include "get_next_line.h"

int main()
{
	char *buf;
	int fd = open("test.txt", O_RDONLY);
	int rr = read (fd, buf, BUFFER_SIZE);
	buf[rr] = '\0';
	printf("%s", buf);
}