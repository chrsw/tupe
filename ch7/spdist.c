/* spdist:  return distance between two names */
/* 
 * very rough spelling metric:
 * 0 if the strings are identical
 * 1 if two chars are transposed
 * 2 if one char wrong, added or deleted
 * 3 otherwise
 */

#include <string.h>
#include "spdist.h"

#define EQ(s,t) (strcmp(s,t) == 0)

int spdist(char *s, char *t)
{
	while (*s++ == *t)
		if (*t++ == '\0')
			return 0;			/* exact match */
	if (*--s) {
		if (*t) {
			if (s[1] && t[1] && *s == t[1]
				&& *t == s[1] && EQ(s+2, t+2))
				return 1;		/* transposition */
			if (EQ(s+1, t+1))
				return 2;		/* 1 char mismatch */
		}
		if (EQ(s+1, t))
			return 2;			/* extra character */
	}
	if (*t && EQ(s, t+1))
		return 2;				/* missing character */
	return 3;
}
