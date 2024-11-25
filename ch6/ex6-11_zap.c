/* zap:  interactive process killer
 *
 * Build:
 *  $ gcc -o zap zap.c strindex.c ttyin.c efopen.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "strindex.h"
#include "ttyin.h"

char *progname;             /* programe name for error message */
char *ps = "ps -ag";        /* system dependent */


int main(int argc, char *argv[])
{
    FILE *fin;
    char buf[BUFSIZ];
    int pid;

    progname = argv[0];
    if ((fin = popen(ps, "r")) == NULL) {
        fprintf(stderr, "%s, can't run %s", progname, ps);
        exit(1);
    }
    fgets(buf, sizeof(buf), fin);       /* get header line */
    fprintf(stderr, "%s", buf);
    while (fgets(buf, sizeof(buf), fin) != NULL)
        if (argc == 1 || strindex(buf, argv[1]) >= 0) {
            buf[strlen(buf)-1] = '\0';       /* supress \n */
            fprintf(stderr, "%s? ", buf);
            if (ttyin() == 'y') {
                sscanf(buf, "%d", &pid);
                kill(pid, SIGKILL);
            }
        }
    exit(0);
}
