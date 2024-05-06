## Problem statement

Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent
philosophers.

Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left
and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not
being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so
that the forks become available to others. A philosopher can only take the fork on their right or the one on their left
as they become available and they cannot start eating before getting both forks.

Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand
are assumed.

## Problems

Avoid deadlock and avoid race condition.

### Deadlock situation:

Each philosopher can pick up their left fork, leading to a case where every philosopher has exactly one fork and no
others are available. Since each will only release their fork once they eat, and since they need two forks to eat, the
entire system stalls out.

### Race condition situation:

If no mutex is used then it cannot ensure that only one philosopher can pick up or put down at the save time, then
multiple philosophers may pick the same fork thus causing race condition.

## Solutions

### Resource hierarchy

Assigns a partial order to the resources and build the resource hierarchy.  
Assign philosopher with three states: THINKING, HUNGRY, and EATING;    
Use two kinds of semaphores: Mutex and a semaphore array for the philosophers. Mutex is used such that no two
philosophers may access the pickup or putdown at the same time. The array is used to control the behavior of each
philosopher.

### Arbitrator

Introduce an arbitrator(implement by mutex) to only allow one philosopher at a time to pick up forks while always
allowing putting down, which may decrease parallelism: one is eating and whose neighbor is requesting fork, all others
must wait while they could have been operating normally.

### Messages

Allow message communication, completely distributed and no central authority, solve starvation and guarantee no
deadlock.

## POSIX thread (pthread)

Pthread allows one to spawn a new concurrent process flow. It is most effective on multi-processor or multi-core systems
where the process flow can be scheduled to run on another processor thus gaining speed through parallel or distributed
processing. Threads require less overhead than "forking" or spawning a new process because the system does not
initialize a new system virtual memory space and environment for the process. While most effective on a multiprocessor
system, gains are also found on uniprocessor systems which exploit latency in I/O and other system functions which may
halt process execution. (One thread may execute while another is waiting for I/O or some other system latency.) Parallel
programming technologies such as MPI and PVM are used in a distributed computing environment while threads are limited
to a single computer system. All threads within a process share the same address space. A thread is spawned by defining
a function and it's arguments which will be processed in the thread. The purpose of using the POSIX thread library in
your software is to execute software faster.   

### Thread Basic:
* Thread operations include thread creation, termination, synchronization (joins,blocking), scheduling, data management and process interaction.
* A thread does not maintain a list of created threads, nor does it know the thread that created it.
* All threads within a process share the same address space.
* Threads in the same process share:
  * Process instructions
  * Most data
  * open files (descriptors)
  * signals and signal handlers
  * current working directory
  * User and group id
* Each thread has a unique:
  * Thread ID
  * set of registers, stack pointer
  * stack for local variables, return addresses
  * signal mask
  * priority
  * Return value: errno
* pthread functions return "0" if OK.

### Thread Creation and Termination:

int pthread_create(pthread_t * thread,
const pthread_attr_t * attr,
void * (*start_routine)(void *),
void *arg);

void pthread_exit(void *retval);

### Thread Synchronization:

Three synchronization mechanisms:

* mutexes - Mutual exclusion lock: Block access to variables by other threads. This enforces exclusive access by a thread to a variable or set of variables.
* joins - Make a thread wait till others are complete (terminated).
* condition variables - data type pthread_cond_t

### Thread Pitfalls:

* Race conditions
* Thread safety
* Mutex Deadlock


## Citation:

1. [Dining philosophers](https://en.wikipedia.org/wiki/Dining_philosophers_problem#:~:text=It_was_originally_formulated_in,the_problem_its_present_formulation/)
2. [Semaphore solution](https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/)
3. [Pthread](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)