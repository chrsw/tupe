/*
 * cp:  minimal version, main()
 *
 * Description
 *      This file is the `cp` example from Section 7.1 of the text. This is
 *      a minimal `cp` implementation that copies a source file file1 to
 *      a destination file file2.
 *
 * Build:
 *      $ gcc -o cp cp_main.c error.c
 * Run:
 *      $ ./cp <file1> <file2>
 *
 * Notes:
 *      The issue with the text version of this application is the ues of the
 *      systems, error handling and reporting feature, error(), errno, etc.
 *      It seems modern systems have deprecated the text's usage of this
 *      feature so slight modifications need to be made to get the text
 *      version to build without warnings, link without errors and run without
 *      problems.
 *
 * TODO:
 *      Fix warnings:
 *      $ gcc -o cp cp.c
 *      /usr/bin/ld: /tmp/cc5Ns5Nd.o: in function `error':
 *      cp.c:(.text+0x20a): warning: `sys_errlist' is deprecated; use 
 *      `strerror' or `strerror_r' instead
 *      /usr/bin/ld: cp.c:(.text+0x1eb): warning: `sys_nerr' is deprecated; 
 *      use `strerror' or `strerror_r' instead
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"

#define PERMS 0644  /* RW for owner, R for group, others */
char *progname;
void error(char *, char *);


/*cp:  minimal version */
int main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[BUFSIZ];

    progname = argv[0];
    if (argc != 3)
        error("Usage: %s from to", progname);
    if ((f1 = open(argv[1], 0)) == -1)
        error("can't open %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS)) == -1)
        error("can't create %s", argv[2]);

    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error("write error", (char *) 0);
    exit(0);
}
