/* ex6-1_vis:  make funny characters visible, Exercise 6-1 version
 *
 * Description from text:
 *  See ex6-1.txt
 *
 * Design:
 *  Read in characters up to EOF
 *  Print non-printable character escape sequence string
 *  If a character is blank, don't print add to buffer
 *  If character is non-blank, flush blank buffer
 *  Copy buffer to output
 *  Print non-blank character
 *
 * Build:
 *  $ gcc -o ex6-1_vis ex6-1_vis.c
 *
 * Run:
 *  $ cat ex6-1_test3.txt | ./ex6-1_vis
 *  - or -
 *  $ printf "hello\x07aa\x08bb" | ./ex6-1_vis
 *
 * Test:
 * Dealing with non-printable characters in the Vim editor
 * https://stackoverflow.com/questions/4185707/how-do-i-paste-non-ascii-characters-into-vim
 * 
 * Escape sequences that will be used in this exercise are from this ASCII 
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

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n',
               VTAB = '\v', FORMFEED = '\f', RETURN = '\r' };

char blankbuf[MAX_LINE_LEN];

int main(void)
{
    int c;
    int i = 0;
	
    while ((c = getchar()) != EOF) {
        /* print "funny" character escape sequence */ 
        switch (c) {
            case BELL:
                fputs("\\a", stdout);
                break;
            case BACKSPACE:
                fputs("\\b", stdout);
                break;
            case TAB:
                fputs("\\t", stdout);
                break;
            case NEWLINE:
                fputs("\\n", stdout);
                break;
            case VTAB:
                fputs("\\v", stdout);
                break;
            case FORMFEED:
                fputs("\\f", stdout);
                break;
            case RETURN:
                fputs("\\r", stdout);
                break;
            default:
                break;
        }

        /* skip blank characters at end of line */
        if ((c == ' ' || c == '\t') && i < MAX_LINE_LEN)
            blankbuf[i++] = (char)c;
        else if (c == '\n') {
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
