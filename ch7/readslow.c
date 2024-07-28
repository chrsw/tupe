/*
 * Description:
 *      Structurally, `readslow` is identical to `cat` except that it loops
 *      instead of quitting when it encounters the current end of input. It
 *      has to use low-level I/O because the standard library routines
 *      continue to report EOF after the first end of file.
 * 
 */

/* readslow:  keep reading, waiting for more */

#include <unistd.h>

#define SIZE 512 /* arbitrary */

int main()
{
    char buf[SIZE];
    int n;

    for (;;) {
        while ((n = read(0, buf, sizeof(buf))) > 0)
            write(1, buf, n);
        sleep(10);
    }
}
