#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MAX_SEND_SIGNUM 1000000 

int main(int argc, char *argv[])
{
	int i;
	pid_t pid;
		
	puts("insert PID");
	scanf("%d", &pid);
	getchar(); // fflush(stdin);

	for(int j = 0; j<3; j++){
		puts("insert number");
		scanf("%d", &number);
		printf("%s: sending signal %d to process %ld %d times\n", argv[0], number, (long)pid, MAX_SEND_SIGNUM);
		
		if(number == 10){
			for(i = 0; i < MAX_SEND_SIGNUM; i++)
				if(kill(pid, SIGUSR1) == -1);
		}
		else if(number == 12){ 
			for(i = 0; i < MAX_SEND_SIGNUM; i++)
				if(kill(pid, SIGUSR2) == -1);
	}
	fprintf(stderr, "kill error [%s]\n", strerror(errno));
									
	printf("%s: exiting\n", argv[0]);
										
	exit(EXIT_SUCCESS);
											
	return 0;
}
