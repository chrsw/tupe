/* pick2: offer choice on each argument (contains error) */

/* gcc -o pick2 pick.c efopen.c ttyin.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void pick(char *);
char ttyin();
FILE * efopen(char, int);


char *progname;         /* program name for error messages */

int main(int argc, char *argv[])
{
    int i;
    char buf[BUFSIZ];

    progname = argv[0];
    if (argc == 2 && strcmp(argv[1],"-") == 0) /* pick - */
        while (fgets(buf, sizeof(buf), stdin) != NULL) {
            buf[strlen(buf)-1] = '\0'; /* drop newline */
            pick(buf);
        }
    else
        for (i = 1; i < argc; i++)
            pick(argv[i]);
    exit(0);
}

/* pick:  offer choice of s */
void pick(char *s)
{
    fprintf("%s? ", s);
    if (ttyin() == 'y')
        printf("%s\n", s);
}

