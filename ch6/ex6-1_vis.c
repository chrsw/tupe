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

/* Escape sequences that will be used in this exercise are from this ASCII 
 * table snippet:
 *     007   7     07    BEL '\a' (bell)
 *     010   8     08    BS  '\b' (backspace)
 *     011   9     09    HT  '\t' (horizontal tab)
 *     012   10    0A    LF  '\n' (new line)
 *     013   11    0B    VT  '\v' (vertical tab)
 *     014   12    0C    FF  '\f' (form feed)
 *     015   13    0D    CR  '\r' (carriage ret)
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 4095

char blankbuf[MAX_LINE_LEN];

int main(void)
{
    int c;
    int i = 0;
	
    while ((c = getchar()) != EOF) {
        switch (c) {
            case 7:
                puts("\a");
                break;
            case 8:
                puts("\b");
                break;
            case 9:
                puts("\t");
                break;
            case 10:
                puts("\n");
                break;
            case 11:
                puts("\v");
                break;
            case 12:
                puts("\f");
                break;
            case 13:
                puts("\r");
                break;
            default:
                break;
        }

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
