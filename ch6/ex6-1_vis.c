/* ex6-1_vis:  make funny characters visible, Exercise 6-1 version
 *
 * Description from text:
 *  See ex6-1.txt
 *
 * Design:
 *  Read in characters up to EOF
 *  If a character is blank, don't print add to buffer
 *  If character is non-blank, flush blank buffer
 *  Copy buffer to output
 *  Print non-blank character
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 4096

char blankbuf[MAX_LINE_LEN];

int main(void)
{
    int c;
    int i = 0;
	
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            blankbuf[i++] = (char)c;
        else if (c == '\n'){
            i = 0;
            putchar(c);
        }
        else {
            blankbuf[i] = '\0';
            printf("%s", blankbuf);
            putchar(c);
            i = 0;
        }
    }

    exit(0);
}
