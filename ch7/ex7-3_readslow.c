/*
 * Description:
 *      Modify `readslow` to handle a filename argument if one is present.
 *      Add the option -e:
 *          $ readslow -e
 *      causes readslow to seek to the end of the input before beginning
 *      to read.  What does lseek do on a pipe?
 * 
 */

/* readslow:  keep reading, waiting for more */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SIZE 512 /* arbitrary */

int main(int argc, char *argv[])
{
    char buf[SIZE];
    int n;
    int fd = 0;

    if (argc == 2) {
        fd = open(argv[1], 0);
    }
        
    for (;;) {
        while ((n = read(fd, buf, sizeof(buf))) > 0)
            write(1, buf, n);
        sleep(10);
    }
}
