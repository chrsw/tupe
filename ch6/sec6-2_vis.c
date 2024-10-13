/* sec6-2_vis:  make funny characters visible (version 2) 
 *              add an option to strip non-printing charcters
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int c, strip = 0;
    
    if (argc > 1 && strcmp(argv[1], "-s") == 0)
        strip = 1;
    while ((c = getchar()) != EOF)
        if (isascii(c) && 
            (isprint(c) || c == '\n' || c == '\t' || c == ' '))
            putchar(c);
        else if (!strip)
            printf("\\%03o", c);
    return 0;
}
