/* printable:  display the names of printable files
 *
 * Description from text:
 *  See ex6-5.txt
 *
 * Build:
 *  $ gcc -o printable printable.c
 *
 * Run:
 *  $ printable *
 *
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isvis(FILE *fp);
int invert = 0;

int main(int argc, char *argv[])
{
    int i;
    FILE *fp;

    /* look for the invert argument */
    while (argc > 1 && argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 'v':       /* -v: invert behavior */
                invert = 1;
                break;
            default:
                fprintf(stderr, "%s: unknown arg %s\n", argv[0], argv[i]);
                exit(1);
        }
        argc--;
        argv++;

    }
    for (i = 1; i < argc; i++)
        if ((fp=fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "%s: can't open %s\n", argv[0], argv[i]);
            exit(1);
        } else {
            if (isvis(fp))
	           	printf("%s\n", argv[i]);
                fclose(fp);
        }
    exit(0);
}




/* isvis:  true if a file contains only printable characters */
bool isvis(FILE *fp)
{
    int c;

    while ((c = getc(fp)) != EOF)
        if (isascii(c) && 
            (isprint(c) || c == '\n' || c == '\t' || c == ' '))
            ;
        else
        	return false;
    return true;
}
