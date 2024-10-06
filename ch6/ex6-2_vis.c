/* ex6-2_vis:  extend previous solution to fold long lines
 *
 * Description from text:
 *  See ex6-2.txt
 *
 * Design:
 *  Read in characters up to EOF
 *  Print non-printable character escapre sequence string
 *  If a character is blank, don't print add to buffer
 *  If character is non-blank, flush blank buffer
 *  Copy buffer to output
 *  Print non-blank character
 *
 * Build:
 *  $ gcc -o ex6-2_vis ex6-2_vis.c
 *
 * Run:
 *  $ cat ex6-2_test.txt | ./ex6-2_vis
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 4095
#define FOLD_LINE_LEN 79

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n',
               VTAB = '\v', FORMFEED = '\f', RETURN = '\r' };

char blankbuf[MAX_LINE_LEN];

void printfold(char *s);

int main(void)
{
    int c;
    /* column count */
    int cc = 0;
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
            cc = 0;
            putchar(c);
        }
        else {
            blankbuf[i] = '\0';
            //printf("%s", blankbuf);
            printfold(blankbuf);
            putchar(c);
            i = 0;
        }
        /* fold lone lines */
        if (cc++ == FOLD_LINE_LEN) {
            puts("");
            cc = 0;
        }
    }

    exit(0);
}

/* print a string but fold very long lines */
void printfold(char *s)
{
    int i = 0;
    int cc = 0;
    while (s[i] != '\0') {
        putc(s[i], stdout);
        if (cc++ == FOLD_LINE_LEN) {
            putc('\n', stdout);
            cc = 0;
        }
        i++;
    }
}
