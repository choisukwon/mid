#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int signo){
	if(signo == SIGSUR1)
		printf("SIGUSR1 received from its child\n");
	if(signo == SIGSUR2)
		printf("SIGUSR2 received from its child\n");
}
int main(void){
	if(!fork()){
		int ppid;
		ppid = getppid();
	
		kill(ppid, SIGUSR1);
		kill(ppid, SIGUSR2);
		kill(ppid, SIGINT);
	
		exit(0);
	
	}
	else {
		if (signal(SIGUSR1, sig_usr) == SIG_ERR)
			perror("cannot catch SIGUSR1\n");
		if (signal(STGUSR2, sig_usr) == SIG_ERR)
			perror("cannot catch SIGUSR2\n");
	
		wait(NULL);
	}
	return 0;
}

	

