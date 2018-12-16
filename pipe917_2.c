#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
		int pfd[2]; /* 파이프용 파일 지시자 */
		char buf[30];

		/* 파이프 생성 */
		if(pipe(pfd) == -1 ) {
				perror("pipe error");
				exit(1);
		}

		if(!fork()){
			printf("CHILD(PID:%d) Writing to the pipe\n", getpid());
			
			/* 파이프 쓰기 */
			write(pfd[1],"pipe!",5);

			/* 자식프로세스 종료 */
			exit(0);
		}
		else{
			printf("PARENT(PID: %d); Reading from the pipe\n",getpid());

			/* 파이프에서 데이터 읽기*/
			read(pfd[0], buf, 5);
			printf("PARENT(PID: %d): %s\n",getpid(), buf);
			//12334
			wait(NULL);
		}

		return 0;
}
