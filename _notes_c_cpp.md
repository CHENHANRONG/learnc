# learnc
learning c and cpp <br />


//======================================<br />
**Managing memory**  <br />
//======================================<br />
- Conceptually 
  - Keep track of what memory belongs to your program, making sure:
    - all addresses you give to other functions are valid for those functions and 
    - you deallocate memory you are not using while you still know about it.
- While programming 
  - Use malloc to allocate memory on the heap if you will need it after the current function returns. 
  - Use free to free pointers before you reassign them and lose the pointer.
- Dynamic allocation and deallocation
  - Allocation: malloc is a C standard library function that finds a chunk of free memory of the desired size and returns a pointer to it.
  - Deallocation: free marks the memory associated with a specific address as no longer in use. (It keeps track of how much memory was associated with that address!)
- How you can produce memory errors
  - Program accesses memory it shouldn’t (not yet allocated, not yet freed, past end of heap block, inaccessible parts of the stack). 
  - Dangerous use of unitialized values. 
  - Memory leaks. 
  - Bad frees. 
- Manifestations of memory errors
  - “Junk” values. 
  - Segmentation fault–program crashes. 
  
  
//======================================<br />
**stack vs. heap.** <br />
//======================================<br />
- The C compiler lays out memory corresponding to functions (arguments, variables) on the stack. 
- C allows the programmer to allocate additional memory on the heap. 

SIG name      | **Stack**       | **Heap**
------------- |-------------| ------
Memory is allocated  |Upon entering function|With malloc 
Memory is deallocated |Upon function return |With free
Addresses are assigned|Statically|Dynamically

![Heap V.S. Stack](learnc/resource/images/heapandstack.png)

<br />
//======================================<br />
Using valgrind to detect memory leaks. <br />
//======================================<br />
- A simple tutorial: http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/   <br />
- valgrind program provides several performance tools:   <br />
including memcheck:   <br />
valgrind --tool=memcheck --leak-check=yes program.o  <br />
- memcheck runs program using virtual machine and tracks memory leaks    <br />
- Does not trigger on out-of-bounds index errors for arrays on the stack  <br />
- Can use to profile code to measure memory usage, identify execution bottlenecks <br />
- valgrind tools (use name in -tool= flag): <br />
   - cachegrind – counts cache misses for each line of code <br />
   - callgrind – counts function calls and costs in program <br />
   - massif – tracks overall heap usage  <br />
   
//====================================== <br />
Using malloc() <br />
//====================================== <br />
Minimize overhead – use fewer, larger allocations <br />
• Minimize fragmentation – reuse memory allocations as much as possible <br />
• Growing memory – using realloc() can reduce fragmentation <br />
• Repeated allocation and freeing of variables can lead to poor performance from unnecessary splitting/coalescing <br />
(depending on implementation of malloc())  <br />


• Mapping memory: mmap(), munmap(). Useful for demand paging. <br />
• Resizing heap: sbrk() <br />
• Designing malloc() <br />
• implicit linked list,explicit linked list <br />
• best fit,first fit,next fit <br />

• Problems:<br />
   • fragmentation<br />
   • memory leaks<br />
   • valgrind –tool=memcheck, checks for memory leaks.<br />


//====================================== <br />
malloc() for the real world <br />
//====================================== <br />
• Used in GNU libc version of malloc() <br />
• Details have changed, but nice general discussion can be found at <br />
http://g.oswego.edu/dl/html/malloc.html <br />
• Chunks implemented as in segregated free list, with pointers to previous/next chunks in free list in payload of free blocks <br />
• Lists segregated into bins according to size; bin sizes spaced logarithmically <br />
• Placement done in best-fit order <br />
• Deferred coalescing and splitting performed to minimize overhead  <br />

//====================================== <br />
When is memory unreferenced? <br />
//====================================== <br />
• Pointer(s) to memory no longer exist <br />
• Tricky when pointers on heap or references are circular <br />
(think of circular linked lists)
• Pointers can be masked as data in memory; garbage collector may free data that is still referenced (or not free unreferenced data)  <br />

//====================================== <br />
A garbage collector for C and C++ <br />
//====================================== <br />
http://www.hboehm.info/gc/
 <br />
 
   
 //====================================== <br />
 Parallel computing <br />
 //====================================== <br />
- Parallelism: Multiple computations are done simultaneously. <br />
  - Instruction level (pipelining) <br />
  - Data parallelism (SIMD) <br />
  - Task parallelism (embarrassingly parallel)  <br />
- Concurrency: Multiple computations that may be done in parallel.  <br />
- Concurrency vs. Parallelism <br />
http://tutorials.jenkov.com/java-concurrency/concurrency-vs-parallelism.html   <br />
 <br />

//====================================== <br />
Process vs. Threads <br />
//====================================== <br />
- Process:  <br />
An instance of a program that is being executed in its own address space. In POSIX systems, each process maintains its own heap, stack, registers, file descriptors etc. <br />
Communication: <br />
  - Shared memory <br />
  - Network <br />
  - Pipes, Queues <br />
- Thread:  <br />
A light weight process that shares its address space with others.In POSIX systems, each thread maintains the bare essentials: registers, stack, signals.  <br />
- Communication: <br />
shared address space.  <br />

<br />
  
  
//====================================== <br />
Multithreaded: <br /> 
 //====================================== <br />
- Program is organized as multiple and concurrent threads of execution.
- The main thread spawns multiple threads.
- The thread may communicate with one another.
- Advantages:
  - Improves performance
  - Improves responsiveness
  - Improves utilization
  - less overhead compared to multiple processes 
  <br />
  
- Even in C, multithread programming may be accomplished in several ways:   <br />
  - Pthreads: POSIX C library.   <br />
  - OpenMP   <br />
  - Intel threading building blocks   <br />
  - Cilk (from CSAIL!)   <br />
  - Grand central despatch   <br />
  - **CUDA (GPU)**   <br />
  - **OpenCL (GPU/CPU)**    <br />
  
- Thread: abstraction of parallel processing with shared memory
  - Program organized to execute multiple threads in parallel
  - Threads spawned by main thread, communicate via shared resources and joining
  - pthread library implements multithreading
    - int pthread_create ( pthread_t ∗ thread , const p t h r e a d _ a t tr _ t ∗ a t tr , void ∗(∗ s t a rt _ r o u t i n e ) ( void ∗) , void ∗ arg ) ;
    - void pthread_exit(void ∗value_ptr);
    - int pthread_join(pthread_t thread, void ∗∗value_ptr);
    - pthread_t pthread_self(void); 
- Resource sharing
  - Access to shared resources need to be controlled to ensure deterministic operation
  - Synchronization objects: mutexes, semaphores, read/write locks, barriers
  - Mutex: simple single lock/unlock mechanism
    - int pthread_mutex_init(pthread_mutex_t ∗mutex, const pthread_mutexattr_t ∗ attr);
    - int pthread_mutex_destroy(pthread_mutex_t ∗mutex);
    - int pthread_mutex_lock(pthread_mutex_t ∗mutex);
    - int pthread_mutex_trylock(pthread_mutex_t ∗mutex);
    - int pthread_mutex_unlock(pthread_mutex_t ∗mutex); 
- Condition variables
  - Lock/unlock (with mutex) based on run-time condition variable
  - Allows thread to wait for condition to be true
  - Other thread signals waiting thread(s), unblocking them
    - int pthread_cond_init(pthread_cond_t ∗cond, const pthread_condattr_t ∗attr);
    - int pthread_cond_destroy(pthread_cond_t ∗cond);
    - int pthread_cond_wait(pthread_cond_t ∗cond, pthread_mutex_t ∗mutex);
    - int pthread_cond_broadcast(pthread_cond_t ∗cond);
    - int pthread_cond_signal(pthread_cond_t ∗cond); 
- OS implements scheduler – determines which threads execute when. Scheduling may execute threads in arbitrary order. Without proper synchronization, code can execute non-deterministically. Non-determinism creates a race condition – where the
behavior/result depends on the order of executio.
- Race conditions:
Race conditions occur when multiple threads share a variable, without proper synchronization
  - Synchronization uses special variables, like a mutex, to ensure order of execution is correct
  - Example: thread T1 needs to do something before thread T2
    - condition variable forces thread T2 to wait for thread T1
    - producer-consumer model program 
  - Example: two threads both need to access a variable and modify it based on its value
    - surround access and modification with a mutex
    - mutex groups operations together to make them atomic treated as one unit 
- To make your code thread-safe:
  - Use synchronization objects around shared variables
  - Use reentrant functions
  - Use synchronization around functions returning pointers to shared memory (lock-and-copy):
    - lock mutex for function
    - call unsafe function
    - dynamically allocate memory for result; (deep) copy result into new memory
    - unlock mutex 
    
- Deadlock: 
  - Deadlock – happens when every thread is waiting on another thread to unblock
  - Usually caused by improper ordering of synchronization objects
  - Tricky bug to locate and reproduce, since schedule-dependent
  - Can visualize using a progress graph – traces progress of threads in terms of synchronization objects
  
- Starvation and priority inversion
  - Starvation similar to deadlock
  - Scheduler never allocates resources (e.g. CPU time) for a thread to complete its task
  - Happens during priority inversion
  - example: highest priority thread T1 waiting for low priority thread T2 to finish using a resource, while thread T3, which has higher priority than T2, is allowed to run indefinitely. thread T1 is considered to be in starvation 
  
    
//====================================== <br />
**Sockets**  <br />
//====================================== <br />
- Socket: abstraction to enable communication across a network in a manner similar to file I/O
- Uses header <sys/socket.h> (extension of C standard library)
- Network I/O, due to latency, usually implemented asynchronously, using multithreading
- Sockets use client/server model of establishing connections 
 
 
-  Creating a socket
  - Create a socket, getting the file descriptor for that socket:
  int socket(int domain, int type, int protocol );
    - domain – use constant AF_INET, so we’re using the internet; might also use AF_INET6 for IPv6 addresses
    - type – use constant SOCK_STREAM for connection-based protocols like TCP/IP; use SOCK_DGRAM for connectionless datagram protocols like UDP (we’ll concentrate on the
former)
    - protocol – specify 0 to use default protocol for the socket type (e.g. TCP)
    - returns nonnegative integer for file descriptor, or −1 if couldn’t create socket
  - Don’t forget to close the file descriptor when you’re done! 
  
  
- Connecting to a server
  - Using created socket, we connect to server using:   <br />
  int connect(int fd, struct sockaddr ∗addr, int addr_len);
    - fd: the socket’s file descriptor
    - addr: the address and port of the server to connect to; for internet addresses, cast data of type struct
sockaddr_in, which has the following members:
      - sin_family – address family; always AF_INET
      - sin_port – port in network byte order (use htons() to convert to network byte order)
      - sin_addr.s_addr – IP address in network byte order (use htonl() to convert to network byte order)
    - addr_len – size of sockaddr_in structure
    - returns 0 if successful
- Associate server socket with a port
  - Using created socket, we bind to the port using:  <br />
  int bind(int fd, struct sockaddr ∗addr, int addr_len);
    - fd, addr, addr_len – same as for connect()
    - note that address should be IP address of desired interface (e.g. eth0) on local machine
    - ensure that port for server is not taken (or you may get “address already in use” errors)
    - return 0 if socket successfully bound to port 
    
- Listening for clients
  - Using the bound socket, start listening: <br />
  int listen (int fd, int backlog);
    - fd – bound socket file descriptor
    - backlog – length of queue for pending TCP/IP connections; normally set to a large number, like 1024
    - returns 0 if successful 
- Accepting a client’s connection
  - Wait for a client’s connection request (may already be queued):  <br />
  int accept(int fd, struct sockaddr ∗addr, int ∗addr_len);
    - fd – socket’s file descriptor
    - addr – pointer to structure to be filled with client address info (can be NULL)
    - addr_len – pointer to int that specifies length of structure pointed to by addr; on output, specifies the length of the stored address (stored address may be truncated if bigger than supplied structure)
    - returns (nonnegative) file descriptor for connected client socket if successful 
- Reading and writing with sockets
  - Send data using the following functions:  <br />
  int write(int fd, const void ∗buf, size_t len );    <br />
  int send(int fd, const void ∗buf, size_t len, int flags );    <br /> 
  - Receive data using the following functions: <br />
  int read(int fd, void ∗buf, size_t len ); <br />
  int recv(int fd, void ∗buf, size_t len, int flags ); <br />
    - fd – socket’s file descriptor
    - buf – buffer of data to read or write
    - len – length of buffer in bytes
    - flags – special flags; we’ll just use 0
  - all these return the number of bytes read/written (if successful) 
    
- Asynchronous I/O
  - Up to now, all I/O has been synchronous – functions do not return until operation has been performed
  - Multithreading allows us to read/write a file or socket without blocking our main program code (just put I/O functions in a separate thread)
  - Multiplexed I/O – use select() or poll() with multiple file descriptors
  
- I/O multiplexing with select()
  - To check if multiple files/sockets have data to read/write/etc: (include <sys/select.h>)
  int select(int nfds, fd_set ∗readfds, fd_set ∗writefds, fd_set ∗errorfds, struct timeval ∗timeout);
    - nfds – specifies the total range of file descriptors to be tested (0 up to nfds−1)
    - readfds, writefds, errorfds – if not NULL, pointer to set of file descriptors to be tested for being ready to read, write, or having an error; on output, set will contain a list of only those file descriptors that are ready
    - timeout – if no file descriptors are ready immediately, maximum time to wait for a file descriptor to be ready
    - returns the total number of set file descriptor bits in all the sets
  - Note that select() is a blocking function 
  - fd_set – a mask for file descriptors; bits are set (“1”) if in the set, or unset (“0”) otherwise Use the following functions to set up the structure:
    - FD_ZERO(&fdset) – initialize the set to have bits unset for all file descriptors
    - FD_SET(fd, &fdset) – set the bit for file descriptor fd in the set
    - FD_CLR(fd, &fdset) – clear the bit for file descriptor fd in the set
    - FD_ISSET(fd, &fdset) – returns nonzero if bit for file descriptor fd is set in the set 

- I/O multiplexing using poll()
  - Similar to select(), but specifies file descriptors differently: (include <poll.h>) 
  int poll (struct pollfd fds [], nfds_t nfds, int timeout);
    - fds – an array of pollfd structures, whose members fd, events, and revents, are the file descriptor, events to
check (OR-ed combination of flags like POLLIN, POLLOUT, POLLERR, POLLHUP), and result of polling with that file descriptor for those events, respectively
    - nfds – number of structures in the array
    - timeout – number of milliseconds to wait; use 0 to return immediately, or −1 to block indefinitely 
    
- Summary:
  - multithreading:
    - Race conditions
      - non-determinism in thread order.
      - can be prevented by synchronization
      - atomic operations necessary for synchronization
    - Mutex: Allows a single thread to own it
    - Semaphores: Generalization of mutex, allows N threads to acquire it at a time.
      - P(s) : acquires a lock
      - V(s) : releases lock
      - sem_init(),sem_destroy()
      - sem_wait(),sem_trywait(),sem_post()
    - Other problems: deadlock, starvation 
  - Sockets: 
    - <sys/socket.h>
    - enables client-server computing
    - Client: connect()
    - Server: bind(),listen(),accept()
    - I/O: write(),send(),read(),recv()
  
  <br />
  
  
  
//====================================== <br />
- Inter process communication
  - Signals
  - Fork
  - Pipes
  - FIFO <br />
//====================================== <br />
- Each process has its own address space. Therefore, individual processes cannot communicate unlike threads.
- Interprocess communication: Linux/Unix provides several ways to allow communications
  - signal
  - pipes
  - FIFO queues
  - shared memory
  - semaphores
  - sockets
- signal
  - void (*signal(int sig,void(*handler)(int )))( int)  <br />
  
SIG name      | explain       | comment
------------- |-------------| ------
SIGABRT |abnormal termination | 
SIGFPE |floating point error | 
SIGILL|illegal instruction  | 
SIGINT | interrupt||
SIGSEGV | segmentation fault |
SIGTERM|termination request |
SIGBUS|bus error|
SIGQUIT| quit|
  <br /> The two signals SIGSTOP,SIGKILL cannot be handled.
  - int raise( int sig)  <br />
  can be used to send signal sig to the program. 
    - Notes:
      - There can be race conditions.
      - signal handler itself can be interrupted.
      - use of non-reentrant functions unsafe.
      - sigprocmask can be used to prevent interruptions.
      - handler is reset each time it is called.
- Fork
  -  pid_t fork (void) 
    - fork() is a system call to create a new process
    - In the child process, it returns 0
    - In the parent process, it returns the PID (process id) of the child.
    - The child PID can be used to send signals to the child process.
    - returns -1 on failure (invalid PID) 
  <br />
  
  
  //====================================== <br />
 <br />
 //====================================== <br />
 
  <br />
  
  //====================================== <br />
 <br />
 //====================================== <br />
 
  <br />
  
  
//====================================== <br />
- How to get clear complex expression.  <br />
 Start with the leftmost identifier and work your way out, 
 **remembering that [] and () bind before *,** 
so   <br />
*a[] is an array of pointers, (*a)[] is a pointer to an array,   <br />
*f() is a function returning a pointer, and (*f)() is a pointer to a function  <br />
 <br />
//====================================== <br />
 
  <br />
  
  
  //====================================== <br />
 <br />
 //====================================== <br />
 
  <br />
