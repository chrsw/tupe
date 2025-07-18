/* ttyin:  process response from /dev/tty (version 2) */

#include <stdio.h>
#include "efopen.h"

#define BUFSIZE 100

char ttyin(void) {

        char buf[BUFSIZE];
        FILE *efopen();
        static FILE *tty = NULL;
        
        if(tty == NULL)
            tty = efopen("/dev/tty", "r");
        for (;;) {
            if (fgets(buf,BUFSIZ,tty) == NULL || buf[0] == 'q')
                exit(0);
            else if (buf[0] == '!') {
                system(buf+1);      /* BUG here */
                printf("!\n");
            }
            else            /* ordinary line */
                return buf[0];
        }
}

