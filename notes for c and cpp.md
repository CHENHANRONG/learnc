# learnc
learning c cpp


//======================================
Using valgrind to detect memory leaks.
//======================================
• A simple tutorial: http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
• valgrind program provides several performance tools:
including memcheck:
valgrind --tool=memcheck --leak-check=yes program.o
• memcheck runs program using virtual machine and tracks memory leaks
• Does not trigger on out-of-bounds index errors for arrays on the stack 
  
//======================================
Using malloc()
//======================================
Minimize overhead – use fewer, larger allocations
• Minimize fragmentation – reuse memory allocations as much as possible
• Growing memory – using realloc() can reduce fragmentation
• Repeated allocation and freeing of variables can lead to poor performance from unnecessary splitting/coalescing
(depending on implementation of malloc()) 


//======================================
malloc() for the real world
//======================================
• Used in GNU libc version of malloc()
• Details have changed, but nice general discussion can be found at
http://g.oswego.edu/dl/html/malloc.html
• Chunks implemented as in segregated free list, with pointers to previous/next chunks in free list in payload of free blocks
• Lists segregated into bins according to size; bin sizes spaced logarithmically
• Placement done in best-fit order
• Deferred coalescing and splitting performed to minimize overhead 
