/* top10:  Print the most frequently occurring words.
 *
 * Simple word counting implementation in C for Exercise 4-4 
 * See ex4-4.txt.
 *
 * Print the 10 most frequently appearing words from the input stream.
 * The words are printed in increasing order along with their counts.
 * Started from K&R2 Section 6.5 Self-referential structures.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


#define MAXWORD 100

/* data types */
struct tnode {                  /* the tree node */
    char *word;                 /* points to the text */
    int count;                  /* number of occurrences */
    struct tnode *left;         /* left child */
    struct tnode *right;        /* right child */
};

/* globals */
struct tnode zero = {"", 0, NULL, NULL};
static char buf[BUFSIZ];
static int bufp = 0;
struct tnode *topwords[10];


/* functions */
int getch(void);
void ungetch(int);
struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
struct tnode *talloc(void);
void inserttop(struct tnode *);
void ranktree(struct tnode *);
void inittop(void);
void printtop(void);


/* word frequency count */
int main(int argc, char *argv[])
{
    struct tnode *root;                 /* for sorting alphabetically */
    char word[MAXWORD];

    (void)argc;
    (void)argv;

    root = NULL;

    inittop();
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    ranktree(root);                     /* Ranking the top 10 most */
                                        /* seen words on input */
    printtop();                         /* print top 10 most seen words */

    return EXIT_SUCCESS;
}


/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


/* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {                    /* a new word has arrived */
        p = talloc();                   /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;                     /* repeated word */
    else if (cond < 0)                  /* less than into left sub-tree */
        p->left = addtree(p->left, w);
    else                            /* greater than into right sub-tree */
        p->right = addtree(p->right, w);
    return p;
}


/* ranktree:  find top 10 words by frequency */
void ranktree(struct tnode *p)
{
    if (p != NULL) {
        ranktree(p->left);
        inserttop(p);
        ranktree(p->right);
    }
}


/* inserttop:  put a node in the top 10 list */
void inserttop(struct tnode *p)
{
    int i, j;

    for (i = 0; i < 10; i++)
        if (p->count > topwords[i]->count) {    /* a top 10 is found */
            for (j = 9; j >= i; j--)            /* put in correct place */
                topwords[j] = topwords[j-1];    /* and shift everything */
            topwords[i] = p;                    /* else down */
            return;
        }
}


/* printtop:  print top 10 common words, 10th first */
void printtop(void)
{
    for (int i = 9; i >= 0; i--)
        printf("%7d %s\n", topwords[i]->count, topwords[i]->word);
}


/* inittop:  initialize (clear) memory for points to top 10 word counts */
void inittop(void)
{
    for (int i = 0; i < 10; i++)
        topwords[i] = &zero;
}


/* talloc:  make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* getch:  Get a (possibly pushed back) character  */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch:  Push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

