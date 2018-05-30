# learnc
learning c cpp <br />


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
    
    
    
    
  //====================================== <br />
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
 <br />
 //====================================== <br />
 
  <br />
