# learnc
learning c and cpp <br />
<br />//======================================<br />
**The stack**
<br />//======================================<br />
- the **stack** together with the **CPU registers** define a **task**.
- **stack** consists of **stack frames**, each of which defines the (local) variables, parameters, data, and instructions for that particular instance of task execution. </br>
      <img src="resource/images/Stack.png" alt="Stack" width="300px" height="450px">
- The SP (ESP on x86) points to the top of the stack, with another pointer (Extended Base Pointer (EBP) for x86). Each frame contains a reference to the preceding frame (caller return address), as set by the OS.

<br />//======================================<br />

### Mastering C++ Multithreading

<br />//======================================<br />



#### Thread Synchronization and Communication
- Safety first
  - The central problem with concurrency is that of ensuring safe access to shared resources even when communicating between threads. 
  - There is also the issue of threads being able to communicate and synchronize themselves.
  - What makes multithreaded programming such a challenge is to be able to keep track of each interaction between threads, and to ensure that each and every form of access is secured while not falling into the trap of deadlocks and data races.
- **The essential idea behind the sharing of data between threads** is that the data to be shared exists somewhere in a way which is accessible to two threads or more. After this, we have to ensure that only one thread can modify the data, and that the data does not get modified while it's being read. Generally, we would use mutexes or similar to ensure this.
- Using r/w-locks： Read-write locks are a possible optimization here, because they allow multiple threads to read simultaneously from a single data source. If one has an application in which multiple worker threads read the same information repeatedly, it would be more efficient to use read-write locks than basic mutexes, because the attempts to read the data will not block the other threads. A read-write lock can thus be used as a more advanced version of a mutex, namely, as one which adapts its behavior to the type of access. Internally, it builds on mutexes (or semaphores) and condition variables.
- Using shared pointers： are an abstraction of memory management using reference counting for heap-allocated instances. 
#### Native C++ Threads and Primitives
- Starting with the 2011 revision of the C++ standard, a multithreading API is officially part of the C++ Standard Template Library (STL). This means that threads, thread primitives, and synchronization mechanisms are available to any new C++ application without the need to install a third-party library, or to rely on the operating system's APIs.
- The STL threading API
  - <thread> header from the STL
  - C++11 APIs:
    - std::thread
    - std::mutex
    - std::recursive_mutex
    - std::condition_variable
    - std::condition_variable_any
    - std::lock_guard
    - std::unique_lock
    - std::packaged_task
    - std::async
    - std::future
  - C++14 APIs: <shared_mutex> header file
    - std::shared_lock  : Since locks are based on mutexes, a shared lock is, therefore, reliant on a shared mutex.
    - std::shared_timed_mutex
  - Thread class: 
    - In header <thread>
    - The thread class is the core of the entire threading API; it wraps the underlying operating system's threads, and provides the functionality we need to start and stop threads.
    - Passing parameters: hese parameter values have to be move constructible, which means that it's a type which has a move or copy constructor (called for rvalue references).When passing references or pointers, things get more complicated with life cycle issues, data races, and such becoming a potential problem.
    - Return value: Any value returned by the function passed to the thread class constructor is ignored. To return information to the thread which created the new thread, one has to use inter-thread synchronization mechanisms (like mutexes) and some kind of a shared variable.
    - Moving threads: std::move in <utility> header, 
    - Thread ID: obtained by calling the get_id() function of the thread class instance, or by calling std::this_thread::get_id() to get the ID of the thread calling the function
    - Sleeping: 
      - sleep_for(), which delays execution by at least the specified duration, but possibly longer
      - sleep_until(), which takes a single parameter of type std::chrono::time_point<Clock, Duration>. Using this function, one can set a thread to sleep until the specified time point has been reached. Due to the operating system's scheduling priorities, this wake-up time might not be the exact time as specified.
    - Yield: std::this_thread::yield() indicate to the OS that the current thread can be rescheduled so that other threads can run instead. 
    - Detach: call detach() on the thread object. This effectively detaches the new thread from the calling thread, meaning that the former will continue executing even after the calling thread has exited.
    - Swap: Using swap(), either as a standalone method or as function of a thread instance, one can exchange the underlying thread handles of thread objects. The effect of this is that the state of each thread is swapped with that of the other thread, essentially exchanging their identities.
  - Mutex
    - The <mutex> header contains multiple types of mutexes and locks. The mutex type is the most commonly used type, and provides the basic lock/unlock functionality without any further complications.
    - At its core, the goal of a mutex is to exclude the possibility of simultaneous access so as to prevent data corruption, and to prevent crashes due to the use of non-thread-safe routines.
    - Non-blocking locking: It's possible to not want the thread to block and wait for the mutex object to become available, then use try_lock() 
    - Timed mutex: A timed mutex is a regular mutex type, but with a number of added functions which give one control over the time period during which it should be attempted to obtain the lock, that is, try_lock_for and try_lock_until.The former tries to obtain the lock during the specified time period (std::chrono object) before returning the result (true or false). The latter will wait until a specific point in the future before returning the result. The use of these functions mostly lies in offering a middle path between the blocking (lock) and non-blocking (try_lock) methods of the regular mutex. One may want to wait for a number of tasks using only a single thread without knowing when a task will become available, or a task may expire at a certain point in time at which waiting for it makes no sense any more.
    - Lock guard: A lock guard is a simple mutex wrapper, which handles the obtaining of a lock on the mutex object as well as its release when the lock guard goes out of scope. This is a helpful mechanism to ensure that one does not forget to release a mutex lock, and to help reduce clutter in one's code when one has to release the same mutex in multiple locations.
    - Unique lock: The unique lock is a general-purpose mutex wrapper. It's similar to the timed mutex, but with additional features, primary of which is the concept of ownership. Unlike other lock types, a unique lock does not necessarily own the mutex it wraps if it contains any at all. Mutexes can be transferred between unique lock instances along with ownership of the said mutexes using the swap() function.
    - Scoped lock: the scoped lock is a mutex wrapper which obtains access to (locks) the provided mutex, and ensures it is unlocked when the scoped lock goes out of scope. It differs from a lock guard in that it is a wrapper for not one, but multiple mutexes.
    - Recursive mutex: 
    - Recursive timed mutex:
  - Shared mutex
    - <shared_mutex> header
    - provide shared access to the mutex. This allows one to, for example, provide read access to a resource by multiple threads, while a writing thread would still be able to gain exclusive access. This is similar to the read-write locks of Pthreads.
    - APIs:
      - lock_shared()
      - try_lock_shared()
      - unlock_shared()
    - Shared timed mutex: This class is essentially an amalgamation of the shared mutex and timed mutex
  - Condition variable
    - In essence, a condition variable provides a mechanism through which a thread's execution can be controlled by another thread. This is done by having a shared variable which a thread will wait for until signaled by another thread.
    - <condition_variable> header
    - the condition variable is notified that any threads which are waiting on it can now continue using:
      - notify_one(): which will signal the first thread in the FIFO queue for this condition variable to continue. 
      - notify_all(): if there are multiple threads waiting for the same condition variable, the calling of notify_all() will allow all threads in the FIFO queue to continue.
    - Condition_variable_any
    - Notify all at thread exit:  std::notify_all_at_thread_exit() function 
  - Future
  - Shared future: A shared_future is just like a regular future object, but can be copied, which allows multiple threads to read its results.
  - Promise: A promise allows one to transfer states between threads.
  - Packaged_task: A packaged_task is a wrapper for any callable target (function, bind, lambda, or other function object). It allows for asynchronous execution with the result available in a future object. It is similar to std::function, but automatically transfers its results to a future object.
  - Async: A more straightforward version of promise and packaged_task can be found in std::async().  future<T> pFuture = std::async (<function pointer>, <parameters>);
  - Launch policy: 
  - Atomics









#### C++ Multithreading APIs
- different levels of C++ Multithreading API support
  - **native** multithreading implementation in the **Standard Template Library (STL)**
  - **OS-level** : Windows and POSIX (Portable Operating System Interface) threads
  - **framework-based** multithreading APIs : Qt, Boost, and POCO etc. (make cross-platform development easier)
- **PThreads thread management**
  - The main Pthreads header is **pthread.h**. 
  - all the functions which start with either **pthread_** or **pthread_attr_**.
    - **pthread_create**: int pthread_create(pthread_t _Nullable * _Nonnull __restrict,
		const pthread_attr_t * _Nullable __restrict,
		void * _Nullable (* _Nonnull)(void * _Nullable),
		void * _Nullable __restrict);
      - The first argument: thread ID. The thread ID is the handle to reference the thread in future calls.
      - The second argument: pthread_attr_t structure instance, or 0 if none. This allows for configuration characteristics of the new thread, such as the initial stack size. When zero is passed, default parameters are used, which differ per platform and configuration.
      - The third parameter: a pointer to the function which the new thread will start with. This function pointer is defined as a function which returns a pointer to void data (that is, custom data), and accepts a pointer to void data. 
      - The fourth parameter: parameter values for the input function of the third parameter above.
    - **pthread_join**: int pthread_join(pthread_t , void * _Nullable * _Nullable)
      -  The first argument: thread ID.
      -  The second argument: a buffer for the return value of the input function (or zero).
    - **pthread_exit**: void pthread_exit(void *value_ptr):
      - This function terminates the thread calling it, making the provided argument's value available to any thread calling pthread_join() on it.
    - **pthread_cancel**: int pthread_cancel(pthread_t thread):
      - This function requests that the specified thread will be canceled. Depending on the state of the target thread, this will invoke its cancellation handlers.
    - **pthread_attr_ functions**
      - manipulate and obtain information about a pthread_attr_t structure.
- **Mutexes**
  - functions prefixed with either **pthread_mutex_** or **pthread_mutexattr_**. They apply to mutexes and their attribute objects.
  - Mutexes in Pthreads can be initialized, destroyed, locked, and unlocked. They can also have their behavior customized using a pthread_mutexattr_t structure, which has its corresponding pthread_mutexattr_* functions for initializing and destroying an attribute on it.
    - PTHREAD_MUTEX_INITIALIZER macro: initializes the mutex for us without having to type out the code for it every time.
    - int pthread_mutex_lock(pthread_mutex_t *);
    - int pthread_mutex_unlock(pthread_mutex_t *);
    - int pthread_mutex_trylock(pthread_mutex_t *);
- **Condition variables**
  - functions which are prefixed with either **pthread_cond_** or **pthread_condattr_**.
  - pthread_cond_wait(&, &); 
  - pthread_cond_signal(&count_cv); 
  - pthread_cond_broadcast()
- **Synchronization**
  - synchronization are prefixed with pthread_rwlock_ or pthread_barrier_. These implement read/write locks and synchronization barriers.
  - A read/write lock (rwlock) is very similar to a mutex, except that it has the additional feature of **allowing infinite threads to read simultaneously, while only restricting write access to a singular thread**.
  ```C++
  #include <pthread.h> 
  int pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr); 
  pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER; 
  
  int pthread_rwlock_rdlock(pthread_rwlock_t* rwlock); 
  int pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock); 
  
  int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock); 
  int pthread_rwlock_trywrlock(pthread_rwlock_t * rwlock); 
  ```
- **Barriers**
  - Barriers are another concept with Pthreads. These are synchronization objects which act like a barrier for a number of threads. All of these have to reach the barrier before any of them can proceed past it. In the barrier initialization function, the thread count is specified. Only once all of these threads have called the barrier object using the pthread_barrier_wait() function will they continue executing.
- **Semaphores**
  - declared in the semaphore.h
  - n essence, **semaphores are simple integers**, generally used as a **resource count**. To make them thread-safe, **atomic operations (check and lock)** are used. POSIX semaphores support the initializing, destroying, incrementing and decrementing of a semaphore as well as waiting for the semaphore to reach a non-zero value.
- **Thread local storage (TLC)**   ?


  



#### C++ Multithreading basis
- the **thread** and **mutex** includes are the core of multithreaded application; they provide the basic means for creating threads, and allow for thread-safe interactions between them.
- Defining processes and threads
  - essentially, to the operating system (OS), a process consists of one or more threads, each thread processing its own state and variables. One would regard this as a **hierarchical configuration**, with the OS as the foundation, providing support for the running of (user) processes. Each of these processes then consists of one or more threads. Communication between processes is handled by **inter-process communication (IPC)**, which is provided by the operating system.
<img src="resource/images/Processes and threads.png" alt="Processes and Threads" width="300px" height="300px">

  - Each process within the OS has its own state, with each thread in a process having its own state as well as the relative to the other threads within that same process. While IPC allows processes to communicate with each other, threads can communicate with other threads within the process in a variety of ways, this generally involves some kind of **shared memory** between threads.
  - The concept of **a process and a shared memory space between the threads contained within the said process** is at the very core of multithreaded systems from a software perspective. Though the hardware is often not aware of this--seeing just a single task to the OS. However, such a multithreaded process contains two or many more threads. Each of these threads then perform its own series of tasks.
  - In system languages such as C++, one can see how variables and other program state information within such a process are stored both on the **stack (variables exist within the scope)** and **heap (using the new operator)**. 
  -  The **stack is a section of memory (one allocated per thread), the size of which depends on the operating system and its configuration.** One can generally also set the stack size programmatically when creating a new thread.
  - In an operating system, a **process consists of a block of memory addresses, the size of which is constant and limited by the size of its memory pointers**. For a 32-bit OS, this would limit this block to 4 GB. **Within this virtual memory space, the OS allocates a basic stack and heap, both of which can grow until all memory addresses have been exhausted, and further attempts by the process to allocate more memory will be denied.**
  - The stack is a concept both for the operating system and for the hardware. In essence, it's a collection (stack) of so-called stack frames, each of which is composed of variables, instructions, and other data relevant to the execution frame of a task.
  - In hardware terms, the stack is part of the task (x86) or process state (ARM), which is how the processor defines an execution instance (program or thread). This hardware-defined entity contains the entire state of a singular thread of execution. See the following sections for further details on this.
- **Tasks** in x86 (32-bit and 64-bit)
  - A task is a unit of work that a processor can dispatch, execute, and suspend. It can be used to execute a program, a task or process, an operating-system service utility, an interrupt or exception handler, or a kernel or executive utility.
  - The IA-32 architecture provides a mechanism for saving the state of a task, for dispatching tasks for execution, and for switching from one task to another. When operating in protected mode, all processor execution takes place from within a task. Even simple systems must define at least one task. More complex systems can use the processor's task management facilities to support multitasking applications.
  - It's important to realize here that, to the processor, there's no such thing as a process or thread. All it knows of are threads of execution, defined as a series of instructions. These instructions are loaded into memory somewhere, and the current position in these instructions is kept track of along with the variable data (variables) being created, as the application is executed within the data section of the process.
  - Each task also runs within a hardware-defined protection ring, with the OS's tasks generally running on ring 0, and user tasks on ring 3. Rings 1 and 2 are rarely used except for specific use cases with modern OSes on the x86 architecture. These rings are privilege-levels enforced by the hardware and allow for example for the strict separation of kernel and user-level tasks.
  - **Task State Structure (TSS)**: The **task structure** for 32-bit and 64-bit tasks:https://en.wikipedia.org/wiki/Task_state_segment
    - 64-bit x86 CPUs: </br>
      <img src="resource/images/TSS layout  for 64-bit x86_64 CPUs.png" alt="TSS layout  for 64-bit x86_64 CPUs" width="300px" height="450px">
      - RSPn: SP for privilege levels 0 through 2
      - ISTn: Interrupt stack table pointers
    - 32-bit x86 CPUs:</br>
      <img src="resource/images/TSS layout  for 32-bit x86 CPUs.png" alt="TSS layout  for 32-bit x86 CPUs" width="300px" height="450px">
      - SS0: The first stack segment selector field
      - ESP0: The first SP field
    - During a **software-based task switch** (usually via an interrupt), the ESP/RSP, and so on are stored in memory and replaced with the values for the next scheduled task. This means that once execution resumes, the TSS structure will now have the Stack Pointer (SP), segment pointer(s), register contents, and all other details of the new task.
  - Interrupt
    - The source of the interrupt can be based in hardware or software. 
    - A hardware interrupt is usually used by devices to signal to the CPU that they require attention by the OS. The act of calling a hardware interrupt is called an Interrupt Request, or **IRQ**.
    - A software interrupt can be due to an exceptional condition in the CPU itself, or as a feature of the CPU's instruction set. The action of switching tasks by the OS's kernel is also performed by triggering a software interrupt.
  - Process state in ARM
    - In ARM architectures, applications usually run in the unprivileged Exception Level 0 (EL0) level, which is comparable to ring 3 on x86 architectures, and the OS kernel in EL1. The ARMv7 (AArch32, 32-bit) architecture has the SP in the general purpose register 13. For ARMv8 (AArch64, 64-bit), a dedicated SP register is implemented for each exception level: SP_EL0, SP_EL1, and so on.
    - For task state, the ARM architecture uses Program State Register (PSR) instances for the Current Program State Register (CPSR) or the Saved Program State Register (SPSR) program state's registers. The PSR is part of the Process State (PSTATE), which is an abstraction of the process state information.
    - While the ARM architecture is significantly different from the x86 architecture, when using software-based task switching, the basic principle does not change: save the current task's SP, register state, and put the next task's detail in there instead before resuming processing.
- Symmetric versus asymmetric multiprocessing
  - Symmetric Multiprocessing (SMP) 
    - SMP system, each of the CPUs are peers having access to the same hardware resources, and set up in a cooperative fashion. Initially, SMP systems involved multiple physical CPUs, but later, multiple processor cores got integrated on a single CPU die
  - Asymmetric Multiprocessing (AMP) 
    - AMP's main defining feature is that a second processor is attached as a peripheral to the primary CPU. This means that it cannot run control software, but only user applications. This approach has also been used to connect CPUs using a different architecture to allow one to,
    </br>
    <img src="resource/images/SMP and AMP.png" alt="SMP and AMP" width="300px" height="300px">
  - General Purpose GPU (GPGPU) 

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
- when to use pointers 
  - When you have to allocate memory on heap. 
  - When passing a parameter whose value you want to allow the other function to change. 
  - Also for efficiency–to avoid copying data structures.
  
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
<img src="resource/images/heapandstack.png" alt="Heap V.S. Stack" width="300px" height="450px">


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
A closer look at the GCC compilation process <br />
//====================================== <br />
- Preprocessor:
  - Translation of # directives. 
    - Translates all macros (#DEFINE’s) into inline C code. 
    - Takes #include files and inserts them into the code. 
      - Get redefinition error if structs etc. are defined more than once! 
      - Use #ifndef directive to define things only if they have not been defined.
- Parsing and translation
  - Translates to assembly, performing optimizations.
- Assembler 
  - Translates assembly to machine instructions. 
- Linking 
  - Static. For each function called by the program, the assembly to that function is included directly in the executable, allowing function calls to directly address code. 
  - Dynamic. Function calls call a Procedure Linkage Table, which contains the proper addresses of the mapped memory.







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
 **Standard Template Library**
 - Architecture
   - Algorithms
   - Iterators
   - Containers
     - Sequence containers
       - Array
       - Vector
       - List
       - Forward List
       - Deque
     - Associative containers
       - Set
       - Map
       - Multiset
       - MultimapSet
       - Unordered set
       - Unordered multiset
       - Unordered map
       - Unordered multimap
     - Container adapters
       - Stack
       - Queue
       - Priority Queue
       
   - Functors
 <br />
 //====================================== <br />
 
- Associative containers <br />
  Associative containers store data in a sorted fashion.the order in which the data is inserted will not be retained by the associative containers. Associative containers are highly efficient in searching a value with O( log n ) runtime complexity. Every time a new value gets added to the container, the container will reorder the values stored internally if required. <br />
 
 Associative containers organize the data as key-value pairs. The data will be sorted based on the key for random and faster access. Associative containers come in two flavors:
  - Ordered 
  - Unordered. 
  <br /> The following associative containers come under ordered containers, as they are ordered/sorted in a particular fashion. Ordered associative containers generally use some form of Binary Search Tree (BST); usually, a red-black tree is used to store the data:
  - Set
    - Set allows only unique values to be stored.
    - in a sorted fashion
    - set organizes the values using the value itself as a key.
    - The set container is immutable, that is, the values stored in a set can't be modified;
    - the values can be deleted
    - A set generally uses a red-black tree data structure, which is a form of balanced BST
    - The time complexity of set operations are guaranteed to be O(log N). 
  - Map
  - Multiset
    - multiset lets you store duplicate values. 
    - the values themselves are used as keys to organize the data. 
    - A multiset container is just like a set; it doesn't allow modifying the values stored in the multiset.
  - Multimap
    - A multimap works exactly as a map, except that a multimap container will allow multiple values to be stored with the same key.
  <br /> The following associative containers come under unordered containers, as they are not ordered in any particular fashion and they use hash tables:
  - Unordered Set
    - An unordered set works in a manner similar to a set, except that the internal behavior of these containers differs. 
    - A set makes use of red-black trees while an unordered set makes use of hash tables. 
    - The time complexity of set operations is O(log N) while the time complexity of unordered set operations is O(1);
    hence, the unordered set tends to be faster than the set.
    - The values stored in an unordered set are not organized in any particular fashion, unlike in a set, which stores values in a sorted fashion. 
    - If performance is the criteria, then an unordered set is a good bet; however, if iterating the values in a sorted fashion is a requirement, then set is a good choice.
  - Unordered Map
    - An unordered map works in a manner similar to a map, except that the internal behavior of these containers differs. 
    - A map makes use of red-black trees while unordered map makes use of hash tables. 
    - The time complexity of map operations is O(log N) while that of unordered map operations is O(1); 
    hence, an unordered map tends to be faster than a map.
    - The values stored in an unordered map are not organized in any particular fashion, unlike in a map where values are sorted by keys.
  - Unordered Multiset
    - An unordered multiset works in a manner similar to a multiset, except that the internal behavior of these containers differs. 
    - A multiset makes use of red-black trees while an unordered multiset makes use of hash tables. 
    - The time complexity of multiset operations is O(log N) while that of unordered multiset operations is O(1). 
    Hence, an unordered multiset tends to be faster than a multiset.
    - The values stored in an unordered multiset are not organized in any particular fashion, unlike in a multiset where values are stored in a sorted fashion. 
    - If performance is the criteria, unordered multisets are a good bet; however, if iterating the values in a sorted fashion is a requirement, then multiset is a good choice.
  - Unordered Multimap
    - An unordered multimap works in a manner similar to a multimap, except that the internal behavior of these containers differs. 
    - A multimap makes use of red-black trees while an unordered multimap makes use of hash tables. 
    - The time complexity of multimap operations is O( log N) while that of unordered multimap operations is O(1); 
    hence, an unordered multimap tends to be faster than a multimap.
    - The values stored in an unordered multimap are not organized in any particular fashion, unlike in multimaps where values are sorted by keys. 
    - If performance is the criteria, then an unordered multimap is a good bet; however, if iterating the values in a sorted fashion is a requirement, then multimap is a good choice.
    
- Container adapters <br />
Container adapters adapt existing containers to provide new containers. In simple terms, STL extension is done with composition instead of inheritance. <br />
STL containers can't be extended by inheritance, as their constructors aren't virtual. 
Throughout the STL, you can observe that while static polymorphism is used both in terms of operator overloading and templates, dynamic polymorphism is consciously avoided for performance reasons. 
Hence, extending the STL by subclassing the existing containers isn't a good idea, as it would lead to memory leaks because container classes aren't designed to behave like base classes. <br />
The STL supports the following container adapters: <br />
  - Stack
    - Stack is not a new container; it is a template adapter class. 
    - The adapter containers wrap an existing container and provide high-level functionalities. 
    - The stack adapter container offers stack operations while hiding the unnecessary functionalities that are irrelevant for a stack. 
    - The STL stack makes use of a deque container by default; however, we can instruct the stack to use any existing container that meets the requirement of the stack during the stack instantiation.
    - Deques, lists, and vectors meet the requirements of a stack adapter.
    - A stack operates on the Last In First Out (LIFO) philosophy. 
  - Queue
    - A queue works based on the First In First Out (FIFO) principle. 
    - A queue is not a new container; it is a templatized adapter class that wraps an existing container and provides the high-level functionalities that are required for queue operations, while hiding the unnecessary functionalities that are irrelevant for a queue. 
    - The STL queue makes use of a deque container by default; however, we can instruct the queue to use any existing container that meets the requirement of the queue during the queue instantiation.
    - In a queue, new values can be added at the back and removed from the front. Deques, lists, and vectors meet the requirements of a queue adapter.
  - Priority Queue
    - A priority queue is not a new container; it is a templatized adapter class that wraps an existing container and provides high-level functionalities that are required for priority queue operations, while hiding the unnecessary functionalities that are irrelevant for a priority queue. 
    - A priority queue makes use of a vector container by default; however, a deque container also meets the requirement of the priority queue. Hence, during the priority queue instantiation, you could instruct the priority queue to make use of a deque as well. 
    - A priority queue organizes the data in such a way that the highest priority value appears first; in other words, the values are sorted in a descending order.
    - priority_queue is a special type of queue that reorders the inputs in such a way that the highest value appears first.

The deque and vector meet the requirements of a priority queue adaptor.
<br />
 
 
  
 <br />//====================================== <br />
**Template Programming**
- Generic programming
- Function templates
- Class templates
- Overloading function templates
- Generic classes
- Explicit class specializations
- Partial specializations
 <br/>//====================================== <br/>
 
- Generic programming.
  - Generic programming is a style of programming that helps you develop **reusable code or generic algorithms** that can be applied to a wide **variety of data types**. Whenever a generic algorithm is invoked, the data types will be supplied as parameters with a special syntax.  
  - C++ supports generic programming with templates, which has the following benefits:
    - We just need to write one function using templates
    - Templates support **static polymorphism**
    - Templates offer all the advantages of the two aforementioned approaches, without any disadvantages
    - Generic programming enables code reuse
    - The resultant code is object-oriented
    - The C++ compiler can perform type checking during compile time
    - Easy to maintain
    - Supports a wide variety of built-in and user-defined data types
  - However, the disadvantages are as follows:
    - Not all C++ programmers feel comfortable writing template-based coding, but this is only an initial hiccup
    - In certain scenarios, templates could bloat your code and increase the binary footprint, leading to performance issues
- Function templates
  - A function template lets you parameterize a data type. The reason this is referred to as generic programming is that a single template function will support many built-in and user-defined data types. A templatized function works like a **C-style macro**, except for the fact that the C++ compiler will **type check** the function when we supply an incompatible data type at the time of invoking the template function.
  - The **function overloading** rules and expectations from the C++ compiler are as follows: The overloaded function names will be the same.The C++ compiler will not be able to differentiate between overloaded functions that differ only by a return value. The number of overloaded function arguments, the data types of those arguments, or their sequence should be different. Apart from the other rules, at least one of these rules described in the current bullet point should be satisfied, but more compliance wouldn't hurt, though. The overloaded functions must be in the same namespace or within the same class scope. If any of these aforementioned rules aren't met, the C++ compiler will not treat them as overloaded functions. If there is any ambiguity in differentiating between the overloaded functions, the C++ compiler will report it promptly as a compilation error.  An important point to note is that, whenever C++ encounters a function call, it first looks for a non-template version; if C++ finds a matching non-template function version, its search for the correct function definition ends there. If the C++ compiler isn't able to identify a non-template function definition that matches the function call signature, then it starts looking for any template function that could support the function call and instantiates a specialized function for the data type required. 
- Class template 
<br/>A class template lets you parameterize the data type on the class level via a template type expression. <br/>
  - C++ template function overloading is a form of **static or compile-time polymorphism**.
  - Complete template class specialization
    - style: template<class T> class TemplateClassName
  - Explicit class specializations: 
    - explicit template specialization replaces the primary template class with its own complete definitions for a specific data type.
    - style: template<> class TemplateClassName<special type e.g. bool>
    - in above styple, class TemplateClassName<bool> is the explicit specialization.
  - Partial template specialization:
    - partial template specialization specialize a certain subset of template parameters supported by the primary template class, while the other generic types can be the same as the primary template class.
    - the primary template class name and the partially specialized class name are the same as in the case of full or explicit template class specialization. However, there are some syntactic changes in the template parameter expression. In the case of a complete template class specialization, the template parameter expression will be empty, whereas, in the case of a partially specialized template class, listed appears.
    - style: template <typename T1, typename T2, typename T3> class TemplateClassName< T1, T2*, T3*> : public TemplateClassName<T1, T2, T3> 
    - in above styple, class TemplateClassName< T1, T2*, T3*> is the partial specialization.
  


  <br />
  
 <br />//====================================== <br />
**Smart Pointers**
- Memory management
- Issues with raw pointers
- Cyclic dependency
- Smart pointers
  - auto_ptr
  - unique_ptr
  - shared_ptr
  - weak_ptr
<br/>//====================================== <br/>  
- **auto_ptr**
  - The auto_ptr smart pointer takes a raw pointer, wraps it, and ensures the memory pointed by the raw pointer is released back whenever the auto_ptr object goes out of scope. 
  - **At any time, only one auto_ptr smart pointer can point to an object**. Hence, whenever one auto_ptr pointer is assigned to another auto_ptr pointer, the ownership gets transferred to the auto_ptr instance that has received the assignment; the same happens when an auto_ptr smart pointer is copied.
  - **std::auto_ptr will be deprecated in favor of std::unique_ptr**. The choice of smart pointer will depend on your use case and your requirements, with std::unique_ptr with move semantics for single ownership that can be used inside containers (using move semantics) and std::shared_ptr when ownership is shared. You should try to use the smart pointer that best fits the situation, choosing the correct pointer type provides other programmers with insight into your design.
- **unique_ptr**
  - The unique_ptr smart pointer works in exactly the same way as auto_ptr, except that unique_ptr addresses the issues introduced by auto_ptr. Hence, **unique_ptr is a replacement of auto_ptr, starting from C++11**. The unique_ptr smart pointer allows only one smart pointer to exclusively own a heap-allocated object. The ownership transfer from one unique_ptr instance to another can be done **only via the std::move()** function.
- **shared_ptr**
  - The shared_ptr smart pointer is used when a group of shared_ptr objects shares the ownership of a heap-allocated object. The shared_ptr pointer releases the shared object when all the shared_ptr instances are done with the use of the shared object. The shared_ptr pointer uses the **reference counting mechanism** to check the total references to the shared object; whenever the reference count becomes zero, the last shared_ptr instance deletes the shared object. 
  - shared_ptr fails to clean up the memory when there is a **circular dependency** in the application design. Either the application design must be refactored to avoid cyclic dependency, or we can make use of weak_ptr to resolve the cyclic dependency issue. 
- **weak_ptr**
  - make use of weak_ptr to resolve the cyclic dependency issue. 
  
  
  
  
- Smart pointers let you use raw pointers safely. They take the responsibility of cleaning up the memory used by raw pointers.  
- The **auto_ptr** smart pointer was introduced in C++11. An auto_ptr smart pointer helps release the heap memory automatically when it goes out of scope. However, due to the way auto_ptr transfers ownership from one auto_ptr instance to another, it was deprecated and **unique_ptr** was introduced as its replacement. 
- The **shared_ptr** smart pointer helps multiple shared smart pointers reference the same object and takes care of the memory management burden.
- The **weak_ptr** smart pointer helps resolve memory leak issues that arise due to the use of **shared_ptr** when there is a **cyclic dependency issue** in the application design. 
- Other smart pointers:
  - owner_less
    - The owner_less smart pointer helps compare two or more smart pointers if they share the same raw pointed object.
  - enable_shared_from_this
    - The enable_shared_from_this smart pointer helps get a smart pointer of the this pointer.
  - bad_weak_ptr
    - The bad_weak_ptr smart pointer is an exception class that implies that shared_ptr was created using an invalid smart pointer. 
  - default_delete
    - The default_delete smart pointer refers to the default destruction policy used by unique_ptr, which invokes the delete statement, while partial specialization for array types that use delete[] is also supported.
 
  
  
  
<br />//====================================== <br />
**TDD: Test-Driven Developments** 
- how to automate Unit Test Cases, Integration Test Cases, and Interaction Test cases in a bottom-up approach
<br/>//====================================== <br/>  
- In TDD, we start with a test case and incrementally write the production code that is required to make the test case succeed.
- The idea is that one should focus on one test case or scenario at a time and once the test case passes, they can then move on to the next scenario. 
- In other words, in the process of developing a new feature or while fixing a bug, we can modify the production code only for two reasons: either to ensure the test case passes or to refactor the code. 
- The primary focus of TDD is unit testing; however, it can be extended to integration and interaction testing to some extent.
<img src="resource/images/TDD.png" alt="TDD" width="250px" height="200px">
- As per software engineering best practices, a good design is **loosely coupled and strongly cohesive** in nature. Though we all strive to write code that is loosely coupled, it isn't possible to write code that is absolutely independent all the time. Most times, the code has some type of dependency. In the case of application software, the dependency could be a database or a web server; in the case of embedded products, the dependency could be a piece of hardware. But using **dependency inversion**, **code under test (CUT)** can be isolated from its dependency, enabling us to test the code without its dependency, which is a powerful technique. So as long as we are open to refactoring the code to make it more modular and atomic, any type of code and project or product will benefit from the TDD approach.
- summary of the key takeaway points:
  - TDD is an Extreme Programming (XP) practice
  - TDD is a bottom-up approach that encourages us to start with a test case, hence it is commonly referred to as LowercaseTest-First Development
  - **Dependency Inversion technique** and how to unit test a code by isolating its dependency using the Google Mock Framework
  - The Google Test Framework supports Unit Testing, Integration Testing, Regression Testing, Performance Testing, Functional Testing, and so on
  - TDD mainly insists on Unit Testing, Integration Testing, and Interaction Testing while complex functional testing must be done with Behavior-Driven Development
  - refactor code smells into clean code while the unit test cases that you wrote give continuous feedback
  - You have learned TDD and how to automate Unit Test Cases, Integration Test Cases, and Interaction Test cases in a bottom-up approach. With BDD, you will learn the top-down development approach, writing end-to-end functionalities and test cases and other complex test scenarios that we did not cover while discussing TDD.


<br />//====================================== <br />
**BDD: Behavior-Driven Development**
- the top-down development approach, writing end-to-end functionalities and test cases and other complex test scenarios 
<br/>//====================================== <br/>  


<br />//====================================== <br />
**Code Smells and Clean Code**
- Code smells and the importance of refactoring code
- SOLID design principles:
  - Single responsibility principle
  - Open closed principle
  - Liskov substitution
  - Interface segregation
  - Dependency injection
- Various code smells:
  - Comments smell
  - Long method
  - Long parameter list
  - Duplicate code
  - Conditional complexity
  - Large class
  - Dead code
- Object-oriented code smells' primitive obsession
  - Data class
  - Feature envy
<br />//====================================== <br />  
- Agile is all about fail fast.
- Scrum has two sets of processes:
  - the project management process
  - the engineering side of the process:  TDD, BDD, ATDD, continuous integration, and DevOps in the product development
- SOLID design principle:
  - Single responsibility principle
    - SRP says that every class must have only one responsibility. In other words, every class must represent exactly one object. 
  - Open closed principle
    - An architecture or design is in compliance with the open closed principle (OCP) when the design supports the addition of new features with no code changes or without modifying the existing source code. 
  - Liskov substitution principle
    - Liskov substitution principle (LSP) stresses the importance of subclasses adhering to the contract established by the base class. In an ideal inheritance hierarchy, as the design focus moves up the class hierarchy, we should notice generalization; as the design focus moves down the class hierarchy, we should notice specialization.  
    - The technique to identify LSP violation is as follows:
      - Subclasses will have one or more overridden methods with empty implementations
      - The base class will have a specialized behavior, which will force certain subclasses, irrespective of whether those specialized behaviors are of the subclasses' interest or not
      - Not all generalized methods can be invoked polymorphically 
    - The following are the ways to refactor LSP violations:
      - Move the specialized methods from the base class to the subclass that requires those specialized behaviors.
      - Avoid forcing vaguely related classes to participate in an inheritance relationship. Unless the subclass is a base type, do not use inheritance for the mere sake of code reuse.
      - Do not look for small benefits, such as code reuse, but look for ways to use polymorphism or aggregation or composition when possible.
  - Interface segregation
    - Interface segregation design principle recommends modeling many small interfaces for a specific purpose, as opposed to modeling one bigger interface that represents many things. In the case of C++, an abstract class with pure virtual functions can be thought of as an interface.
  - Dependency inversion
    - A good design will be **strongly cohesive and loosely coupled**. Hence, our design must have less dependency. A design that makes a code dependent on many other objects or modules is considered a poor design. If Dependency Inversion (DI) is violated, any change that happens in the dependent modules will have a bad impact on our module, leading to a ripple effect. 
    - via an interface or an abstract class with pure virtual functions
- Code Smells
  - Comment Smell
    - Ideally, clean code should be self-explanatory, without any need for comments. 
    - A good comment will express why the code is written in a specific way rather than express how the code does something. 
    - A comment that conveys how the code does something is a code smell, whereas a comment that conveys the why part of the code is a good comment, as the why part is not expressed by the code; therefore, a good comment provides value addition.
  - Long method
    - A method is long when it is identified to have multiple responsibilities. 
    - smaller methods that have one single responsibility
    - Handling errors by returning error code isn't considered object-oriented code, hence error handling must be done using C++ exceptions.
  - Long parameter list
    - An object-oriented method takes fewer arguments, as a well-designed object will be strongly cohesive and loosely coupled. 
    - A method that takes too many arguments is a symptom that informs that the knowledge required to make a decision is received externally, which means the current object doesn't have all of the knowledge to make a decision by itself. This means the current object is weakly cohesive and strongly coupled, as it depends on too much external data to make a decision.
    - Member functions generally tend to receive fewer arguments, as the data members they require are generally member variables. Hence, the need to pass member variables to member functions sounds artificial.
    - some of the common reasons why a method tends to receive too many arguments. The most common symptoms and reasons are listed here:
      - The object is weakly cohesive and strongly coupled; that is, it depends too much on other objects 
      - It is a static method
      - It is a misplaced method; that is, it doesn't belong to that object
      - It is not object-oriented code
      - SRP is violated
    - The ways to refactor a method that takes **long parameter list (LPL)** are listed here:
      - Avoid extracting and passing data in bits and pieces; consider passing an entire object and let the method extract the details it requires
      - Identify the object that supplies the arguments to the method that receives LPL and consider moving the method there
      - Group the list of arguments and create a parameter object and move the method that receives LPL inside the new object
  - Duplicate code
  - Conditional complexity
    - Conditional complexity code smell is about complex large conditions that tend to grow larger and more complex with time. This code smell can be refactored with the **strategy design pattern**. As the strategy design pattern deals with many related objects, there is scope for using the **Factory method**, and the **null object design pattern** can be used to deal with unsupported subclasses in the Factory method: 
    ```cpp
    //Before refactoring
    void SomeClass::someMethod( ) {
      if (  ! conition1 && condition2 )
         //perform some logic
      else if ( ! condition3 && condition4 && condition5 )
         //perform some logic
      else
         //do something 
     } 

    //After refactoring
    void SomeClass::someMethod() {
         if ( privateMethod1() )
              //perform some logic
         else if ( privateMethod2() )
              //perform some logic
         else
             //do something
    }
    ```
  - Large class
    - A large class code smell makes the code difficult to understand and tougher to maintain. A large class can do too many things for one class. Large classes can be refactored by breaking them into smaller classes with a single responsibility.
  - Dead code
    - Dead code is commented code or code that is never used or integrated. It can be detected with code coverage tools. Generally, developers retain these instances of code due to lack of confidence, and this happens more often in legacy code. As every code is tracked in version control software tools, dead code can be deleted, and if required, can always be retrieved back from version control software.
- Object-oriented code smells
  - Primitive obsession
    - Primitive Obsession (PO) is a wrong design choice: use of a primitive data type to represent a complex domain entity. 
  - Data class
    - Data classes provide only getter and setter functions. Though they are very good for transferring data from one layer to another, they tend to burden the classes that depend on the data class. As data classes won't provide any useful functionalities, the classes that interact or depend on data classes end up adding functionalities with the data from the data class. In this fashion, the classes around the data class violate the SRP and tend to be a large class.
  - Feature envy
    - Certain classes are termed feature envy if they have too much knowledge about other internal details of other classes. Generally, this happens when the other classes are data classes. Code smells are interrelated; breaking one code smell tends to attract other code smells.
  
  
  
  
  
  
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
  
  
 
  <br />
