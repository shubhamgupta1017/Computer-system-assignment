#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>


int main(int argc, char* argv[]) {
    //if invalid input
    if (argc < 2) {
        printf("invalid input\n");
        return 1;
    }

    // Shared memory file descriptor
    int shm_fd;
    // Pointer to shared memory object
    void* shared_data;
    // Structure to store start and end time
    struct timeval start, end;
    // Process ID
    pid_t pid;

    // Open & create shared memory object
    shm_fd = shm_open("/memory", O_CREAT | O_RDWR, 0666);
    
    // allocate the size of shared memory
    ftruncate(shm_fd, sizeof(struct timeval));

    // Map the shared memory into the process's address space
    shared_data = mmap(NULL, sizeof(struct timeval), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    pid = fork();

    //child process
    if (pid == 0) {
        gettimeofday((struct timeval*)shared_data, NULL);
        execvp(argv[1], &argv[1]);
    } 
    //parent process
    else {
        wait(NULL);
        gettimeofday(&end, NULL);

        start = *(struct timeval*)shared_data;

        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Elapsed time: %f seconds\n", elapsed_time);
    }

    return 0;
}
