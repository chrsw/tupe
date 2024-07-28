#include <sys/types.h>
#include <unistd.h>
#include "get.h"

/* get:  read any number of bytes from any place in a file */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) == -1)        /* get to pos */
        return -1;
    else
        return read(fd, buf, n);
}
