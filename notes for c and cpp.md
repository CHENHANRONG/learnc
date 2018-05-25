# learnc
learning c cpp <br />


//======================================<br />
Using valgrind to detect memory leaks. <br />
//======================================<br />
• A simple tutorial: http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/   <br />
• valgrind program provides several performance tools:   <br />
including memcheck:   <br />
valgrind --tool=memcheck --leak-check=yes program.o  <br />
• memcheck runs program using virtual machine and tracks memory leaks    <br />
• Does not trigger on out-of-bounds index errors for arrays on the stack  <br />
• Can use to profile code to measure memory usage, identify execution bottlenecks <br />
• valgrind tools (use name in -tool= flag): <br />
   • cachegrind – counts cache misses for each line of code <br />
   • callgrind – counts function calls and costs in program <br />
   • massif – tracks overall heap usage  <br />
   
//====================================== <br />
Using malloc() <br />
//====================================== <br />
Minimize overhead – use fewer, larger allocations <br />
• Minimize fragmentation – reuse memory allocations as much as possible <br />
• Growing memory – using realloc() can reduce fragmentation <br />
• Repeated allocation and freeing of variables can lead to poor performance from unnecessary splitting/coalescing <br />
(depending on implementation of malloc())  <br />


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
