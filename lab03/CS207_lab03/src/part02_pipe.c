#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc , char* argv[]){
    //if invalid input
    if(argc==1){
        printf("invalid input\n");
        exit(1);
    }

    //create pipe file descriptors
    int pipe_fd[2];
    pipe(pipe_fd);
    //initalize structure to store start and end time
    struct timeval start, end;
    //initialize process id
    pid_t pid;

    pid = fork();

    //child process
    if(pid==0){
        close(pipe_fd[0]); 
        gettimeofday(&start, NULL);
        write(pipe_fd[1], &start, sizeof(struct timeval));
        execvp(argv[1], &argv[1]);
        // exit(1);
    }
    else{
        wait(NULL); //wait for child process to finish
        gettimeofday(&end, NULL); //end time
        close(pipe_fd[1]); //close write end of pipe
        read(pipe_fd[0], &start, sizeof(struct timeval));//read start time from pipe
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Elapsed time: %f seconds\n", elapsed_time);//print elapsed time
    }
    return 0;
}