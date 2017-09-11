/* ttyin() process response from /dev/tty (version 1) */

#include <stdio.h>

FILE * efopen(const char *, const char *);

#define BUFSIZE 100

char ttyin(void) {

        char buf[BUFSIZE];
        static FILE *tty = NULL;
        
        if(tty == NULL)
                tty = efopen("/dev/tty", "r");
        if((fgets(buf, BUFSIZE, tty) == NULL) || buf[0] == 'q')
                return 0;
        else /* ordinary line */
                return buf[0];
}

