/* wc:  simple word counting for Exercise 4-4 */
/* from K&R2 Section 6.5 Self-referential structures */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


#define MAXWORD 100

/* data types */
struct tnode {                  /* the tree node */
    char *word;                 /* points to the text */
    int count;                  /* number of occurrances */
    int rank;
    struct tnode *left;         /* left child */
    struct tnode *right;        /* right child */
};

struct tnode zero = {"none", 0, 0, NULL, NULL};

static char buf[BUFSIZ];
static int bufp = 0;
int top[10] = {0};              /* ten highest counts */
int rcount = 0;                     /* iterate over tree */
struct tnode *topcounts[10];


/* functions */
int getch(void);
void ungetch(int);
struct tnode *addtree(struct tnode *, char *);
struct tnode *addrank(struct tnode *, struct tnode *);
void treeprint(struct tnode *);
void ranktree(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
int istop(struct tnode *);
void rankprint(struct tnode *p);
void inittopcounts(void);
void printtopten(void);

/* word frequency count */
int main(int argc, char *argv[])
{
    struct tnode *root;                 /* for sorting alphabetically */
    struct tnode *rank;                 /* for sorting by count */
    char word[MAXWORD];
    int wc = 0;

    root = NULL;
    rank = NULL;

    inittopcounts();
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0])) {
            root = addtree(root, word);
            wc++;
        }
    //treeprint(root);
    rankprint(root);
    printf("words = %d\n", wc);
    printtopten();
    //ranktree(rank);
    //rankprint(root);
    rank = malloc((sizeof(struct tnode *))*wc);
    if (rank == NULL)
        return -1;

    return 0;
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

    if (p == NULL) {                /* a new word has arrived */
        p = talloc();               /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;                 /* repeated word */
    else if (cond < 0)              /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                            /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}


/* addrank:  add a node with w, at or below p, count sort */
struct tnode *addrank(struct tnode *r, struct tnode *p)
{
    if (r == NULL) {                /* new sort */
        r = talloc();               /* make a new node */
        r->left = r->right = NULL;

    } else if (r->count > p->count)
        p->left = addrank(r, p);
    else                            /* less than into right subtree */
        p->right = addrank(r, p);
    return p;
}


/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


/* rankprint:  print tree and look at node counts */
void rankprint(struct tnode *p)
{
    if (p != NULL) {
        //printf("%4d %s\n", p->count, p->word);
        rankprint(p->left);
        printf("%4d %s", p->count, p->word);
        if (istop(p)) {
            printf("  --  top 10!\n");
        } else {
            printf("\n");
        }
        rankprint(p->right);
    }
}


/* ranktree:  build a tree based off count number */
void ranktree(struct tnode *p)
{
    if (p != NULL) {
        ranktree(p->left);
        //printf("%4d %s\n", p->count, p->word);
        addrank(p, p);
        ranktree(p->right);
    }
}


/* talloc: make a tnode */
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


/* istop:  is this count in the top 10? */
int istop(struct tnode *p)
{
    int i;
    int j;

    if (!p) return 0;
    for (i = 0; i < 10; i++)
        if (p->count > topcounts[i]->count) {
            for (j = 9; j >= i; j--)
                topcounts[j] = topcounts[j-1];
            topcounts[i] = p;
            return p->count;
        }
        return 0;
}


void inittopcounts(void)
{
    int i = 0;
    for (i = 0; i < 10; i++)
        topcounts[i] = &zero;
}

void printtopten(void)
{
    int i;
    for (int i = 0; i < 10; i++)
        printf("%4d %s\n", topcounts[i]->count, topcounts[i]->word);
}