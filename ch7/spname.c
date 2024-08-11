/* spname:  return correctly spelled filename 
 * returns  -1 if no reasonable match to oldname,
 *           0 if exact match,
 *           1 if correctec.
 * stores corrected name in newname.
 */

#include <string.h>
#include <sys/types.h>
#include <sys/dir.h>
#include "spname.h"
#include "mindist.h"

int spname(char *oldname, char *newname)
{
    char *p, guess[DIRSIZ+1], best[DIRSIZ+1];
    char *new = newname, *old = oldname;

    for (;;) {
        while (*old == '/')                         /* skip slashes */
            *new++ = *old++;
        *new = '\0';
        if (*old == '\0')                           /* exact or corrected */
            return strcmp(oldname, newname) != 0;
        p = guess;                      /* copy next component */
                                        /* into guess */
        for (; *old != '/' && *old != '\0'; *old++)
            if (p < guess+DIRSIZ)
                *p++ = *old;
        *p = '\0';
        if (mindist(newname, guess, best) >= 3)
            return -1;  /* hopeless */
        for (p = best; *new = *p++;)                /* add to end */
            new++;                                  /* of newname */
    }
}
