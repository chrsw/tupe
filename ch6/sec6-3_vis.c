/* sec6-3_vis:  make funny characters visible (version 3) 
 *              specifiy files to open on command line
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void vis(FILE *);
int strip = 0;                  /* 1 => discard special characters */


int main(int argc, char *argv[])
{
    int i;
    FILE *fp;

    /* look for the strip argument */
    while (argc > 1 && argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 's':       /* -s: strip funny chars */
                strip = 1;
                break;
            default:
                fprintf(stderr, "%s: unknown arg %s\n", argv[0], argv[i]);
                exit(1);
        }
        argc--;
        argv++;

    }
    if (argc == 1)
        vis(stdin);
    else
        for (i = 1; i < argc; i++)
            if ((fp=fopen(argv[i], "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", argv[0], argv[i]);
                exit(1);
            } else {
                vis(fp);
                fclose(fp);
            }
    exit(0);
}


/* vis:  make "funny" characters visible */
void vis(FILE *fp)
{
    int c;

    while ((c = getc(fp)) != EOF)
        if (isascii(c) && 
            (isprint(c) || c == '\n' || c == '\t' || c == ' '))
            putchar(c);
        else if (!strip)
            printf("\\%03o", c);
}
