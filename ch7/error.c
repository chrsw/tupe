/* error() intrduced in Section 7.1 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void error(char *s1, char *s2)
{
    extern int __thread errno;
    extern int sys_nerr;
    extern const char *const sys_errlist[];
    extern char *progname;

    if (progname)
        fprintf(stderr, "%s", progname);
    fprintf(stderr, s1, s2);
    if (errno > 0 && errno < sys_nerr)
        fprintf(stderr, " (%s)", sys_errlist[errno]);
    fprintf(stderr, "\n");
    exit(1);
}
