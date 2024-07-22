/* pick: offer choice on each argument */

#include <stdio.h>
#include <string.h>

static void pick(char *);
char ttyin();
FILE * efopen(char, int);

#define BUFSIZE 100

char *progname;         /* program name for error messages */

int main(int argc, char *argv[]) {

        int i;
        char buf[BUFSIZE];

        progname = argv[0];
        if (argc == 2 && strcmp(argv[1],"-") == 0) /* pick - */
                while (fgets(buf, sizeof(buf), stdin) != NULL) {
                        buf[strlen(buf)-1] = '\0'; /* drop newline*/
                        pick(buf);
                }
        else
                for (i = 1; i < argc; i++)
                        pick(argv[i]);

        return 0;
}


void pick(char *s){

        fprintf(stderr, "", s);
        if(ttyin() == 'y')
                printf("%s\n", s);
}

