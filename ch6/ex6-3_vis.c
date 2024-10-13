/* ex6-3_vis:  make funny characters visible (version 2) 
 *              add an option to strip non-printing characters
 *
 * Build:
 *  $ gcc -o ex6-3_vis ex6-3_vis.c
 *
 * Run:
 *  $ cat ex6-3_test.txt | ./ex6-3_vis -s10
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char buf[4095];

int main(int argc, char *argv[])
{
    int c;
    int i = 0;
    size_t n;
    char *sn;

    if (argc > 1 && strncmp(argv[1], "-s", 2) == 0) {
        if (strlen(argv[1]) > 2) {          /* look for -sN */
            sn = argv[1];
            sn += 2;
            n = atoi(sn);
            //printf("n = %d\n", n);
        }
    }

    while ((c = getchar()) != EOF)
        if (isascii(c) && 
            (isprint(c) || c == '\n' || c == '\t' || c == ' '))
            buf[i++] = (char)c;
        else {
            buf[i] = '\0';
            if (strlen(buf) >= n )
                printf("%s\n", buf);
            i = 0;
        }

    /* TODO: is this necessary or is there a cleaner way to do this? */
    if (i > 0 && c != EOF) {
        buf[i] = '\0';
        printf("%s", buf);
        if (c != '\n')
            printf("\n");
    }

    return 0;
}
