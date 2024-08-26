/* wc:  simple word counting for Exercise 4-4 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int c;
    int wc = 0;
    
    /* read input until input ends */
    while ((c = getchar()) != EOF) {
        if (isblank(c) || c == '\n')
            wc++;
    }

    printf("%d\n", wc);
    return 0;
}
