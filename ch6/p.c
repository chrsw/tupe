/* p:  print input in chunks (version 1) */
/* Section 6.4 A screen-at-a-time printer */
/* Modified for a more modern style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGESIZE 22
char *progname; 	/* program name for error messsages */


int main(int argc, char *argv[])
{
	int i;
	FILE *fp, *efopen();
	void print(FILE *, int);

	progname = argv[0];
	if (argc == 1)
		print(stdin, PAGESIZE);
	else
		for (i = 1; i < argc; i++) {
			fp = efopen(argv[i], "r");
			print(fp, PAGESIZE);
			fclose(fp);
		}
	return 0;
}


/* efopen:  fopen file, die if can't */
FILE *efopen(char *file, const char *mode)
{
	FILE *fp;
	if ((fp = fopen(file, mode)) != NULL)
		return fp;
	fprintf(stderr, "%s: can't open file %s mode %s\n",
			progname, file, mode);
	exit(1);
}


/* print:  print fp in pageize chunks */
void print(FILE *fp, int pagesize)
{
	static int lines = 0;		/* number of lines so far */
	char buf[BUFSIZ];

	char ttyin(void);
	while (fgets(buf, sizeof(buf), fp) != NULL)
		if (++lines < pagesize)
			fputs(buf, stdout);
		else {
			buf[strlen(buf)-1] = '\0';
			fputs(buf, stdout);
			fflush(stdout);
			ttyin();
			lines = 0;
		}
}


/* ttyin:  process response from /dev/tty (version 1) */
char ttyin(void)
{
	char buf[BUFSIZ];
	FILE *efopen();
	static FILE *tty = NULL;

	if (tty == NULL)
		tty = efopen("/dev/tty", "r");
	if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q')
		exit(0);
	else	/* ordinary line */
		return buf[0];
}
