/*p:  print input in chunks (version 4) */
 
/* Build
 *  $ gcc -Wall -Wextra -Wpedantic -o p p.c spname.c spdist.c
 *     print.c mindist.c efopen.c ttyin.c
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include "spname.h"
#include "efopen.h"
#include "print.h"
#include "ttyin.h"

#define PAGESIZE    22
char *progname;     		/* program name for error message */

int main(int argc, char *argv[])
{
    FILE *fp, *efopen();
    int i, pagesize = PAGESIZE;
    char *p, *getenv(), buf[BUFSIZ];

    progname = argv[0];

    if ((p=getenv("PAGESIZE")) != NULL)
        pagesize = atoi(p);
    if (argc > 1 && argv[1][0] == '-') {
        pagesize = atoi(&argv[1][1]);
        argc--;
        argv++;
    }
    if (argc == 1)
        print(stdin, pagesize);
    else
        for (i = 1; i < argc; i++)
            switch (spname(argv[i], buf)) {
            case -1:        /* no match possible */
                fp = efopen(argv[i], "r");
                break;
            case 1:         /* coorected */
                fprintf(stderr, "\"%s\"? ", buf);
                if (ttyin() == 'n')
                    break;
                argv[i] = buf;
                /* fall through... */
            case 0:         /* exact match */
                fp = efopen(argv[i], "r");
                print(fp, pagesize);
                fclose(fp);
            }
    exit(0);
}
