#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void clock_tick ( int signo ) {
	printf("\r%ld" , time(NULL) ) ; /* overwrite prev . time with new */ /* time(NULL) = currnet_time U*/
	alarm( 1 ) ; /* re􀀀set alarm */
}
int main( void ) { /* a (UNIX time ) clock */
	setvbuf ( stdout , NULL, _IONBF , BUFSIZ ) ; /* avoid buffering */
	printf ("\e[2J\e[H") ; /* home and clear screen w/ ANSI ESC seqs */
	if ( signal (SIGALRM, clock_tick ) == SIG_ERR )
		perror ( " can ’ t catch SIGALRM" ) ;
	clock_tick (-1); /* print current time */
	alarm( 1 ) ;
	for ( ; ; ) /* wait /catch loop */
		pause ( ) ;
	exit ( EXIT_SUCCESS ) ;
}
