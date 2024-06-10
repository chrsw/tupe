/* efopen() fopen file, die if can't */

#include <stdio.h>
#include <stdlib.h>

FILE * efopen(const char *file, const char * mode) {

        FILE *fp;
        extern char *progname;

        if ((fp = fopen(file, "r")) != NULL)
                return fp;
        fprintf(stderr, "%s: can't open file %s mode %s\n",
                progname, file, mode);
        exit(1);
}
