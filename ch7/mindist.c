#include <sys/types.h>
#include <sys/dir.h>
#include "spdist.h"
#include "mindist.h"

/* mindist:  search dir for guess */
int mindist(char *dir, char *guess, char *best)
{
	int d, nd, fd;
	struct {
		ino_t ino;
		char name[DIRSIZ+1];		/* 1 more than in dir.h */
	} nbuf;

	nbuf.name[DIRSIZ] = '\0';		/* +1 for terminal '\0' */
	if (dir[0] == '\0')				/* current dirctory */
		dir = ".";
	if ((fd=open(dir,0)) == -1)
		return d;
	while (read(fd,(char *)&nbuf,sizeof(struct dirent)) > 0)
		if (nbuf.ino) {
			nd = spdist(nbuf.name, guess);
			if (nd <= d && nd != 3) {
				strcpy(best, nbuf.name);
				d = nd;
				if (d == 0)			/* exact match */
					break;
			}
		}
	close(fd);
	return d;
}