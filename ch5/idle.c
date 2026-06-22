/* 
 * idle.c
 * 
 * Description:
 *      A do-nothing background process for testing process-management tools.
 *      Sleeps until killed. Uses only the standard C library.
 *      Written to test with `zap`, `zap2`, etc.
 *
 * Build:  
 *      gcc -O2 -o idle idle.c
 *
 * Run:    
 *      ./idle &
 *
 * Kill:   
 *      kill <pid>      (SIGTERM, default action terminates immediately)
 *      kill -9 <pid>   (SIGKILL, always immediate)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    printf("idle: pid=%d, sleeping forever\n", (int)getpid());
    fflush(stdout);

    struct timespec ts = { .tv_sec = 3600, .tv_nsec = 0 };

    for (;;) {
        nanosleep(&ts, NULL);
    }

    return 0;
}
