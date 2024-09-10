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

    //initalize structure to store start and end time
    struct timeval start, end;
    //initialize process id
    pid_t pid;
    
    gettimeofday(&start, NULL); //start time
    pid = fork();

    //child process
    if(pid==0){
        execvp(argv[1], &argv[1]);
    }
    //parent process
    else{
        wait(NULL);//wait for child process to finish

        gettimeofday(&end, NULL);//end time 

        double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Elapsed time: %f seconds\n", time_taken);
    }

    return 0;
}