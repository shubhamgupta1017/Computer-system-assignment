
## Build Instructions

1. **Clean the Build Environment**
   ```bash
   make clean
   ```

2. **Build the Applications**
   ```bash
   make
   ```

## File structure
   src - contains c files for each application
      - time.c
      - part02_shared.c
      - part02_pipe.c
   bin - contains executable for each application
      - time
      - part02_shared
      - part02_pipe
   Readme.md - information about project
   Makefile - buildsystem commands
   
## Running the Applications

### Time Measurement

To measure the execution time of a command, using classic isolated technique:

**Example:**
```bash
cd bin
./time "ls"
```

### Shared Memory Application

For the shared memory communication application, use the following command:

**Example:**
```bash
cd bin
./part02_shared "ls"
```

### Message Passing Using Pipes

For the message passing application using pipes, use the following command:

**Example:**
```bash
cd bin
./part02_pipe "ls"
```

## Performance Results

When running the `ls` command across different applications, the observed times were as follows:

- `./time` (no communication): `0.0024` seconds
- `./part02_shared` (shared memory communication): `0.0021` seconds
- `./part02_pipe` (message passing using pipes): `0.0020` seconds


## Performance Analysis

The observed performance differences between the various methods of inter-process communication are as follows:

1. **No Communication (`./time`):** 
   The baseline execution time with no inter-process communication is `0.0024` seconds. This represents the time required to execute the command and time to switch and schedule

2. **Shared Memory Communication (`./part02_shared`):** 
   The execution time improves to `0.0021` seconds with shared memory communication. This reduction is due to the efficiency of shared memory as it allows multiple processes to access a common memory space directly. This method removes time taken to schedule.

3. **Message Passing Using Pipes (`./part02_pipe`):** 
   The execution time is the lowest at `0.0020` seconds when using message passing with pipes. Pipes provide a structured mechanism for inter-process communication by creating a unidirectional channel through which data can be passed. This method is highly efficient due to its minimal overhead in data transfer and synchronization. 
   There is very less difference between shared memory and Message Passing Using Pipes

### Author:- Shubham Gupta
   entry number:- 2023aib1017
