#include <stdio.h>
#include <string.h>
#include "ttyin.h"

/* print:  print fp in pagesize chunks */
void print(FILE *fp, int pagesize)
{
    static int lines = 0;       /* number of lines so far */
    char buf[BUFSIZ];

    while( fgets(buf, sizeof buf, fp) != NULL)
        if (++lines < pagesize)
            fputs(buf, stdout);
        else {
            buf[strlen(buf)-1] = '\0';
            fputs(buf, stdout);
            fflush(stdout);
            ttyin();
            lines = 0;
        }
}       
