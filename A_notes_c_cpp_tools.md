

 <br />//====================================== <br />
 **Compile tools**
 - gcc 
   - g++ -Wall -o outfilename cppsource.cpp 
   - Some options
     - -g - turn on debugging (so GDB gives more friendly output)
     - -Wall - turns on most warnings
     - -O or -O2 - turn on optimizations
     - -o <name> - name of the output file
     - -c output an object file (.o)
     - -I<include path> - specify an include directory
     - -L<library path> - specify a lib directory
     - -l<library> - link with library lib<library>.a
   - Use the g++ **-fdump-tree-original** main.cpp -std=c++17 command to see the **compiler-instantiated code for templates**.
 - The nm Unix utility will list the symbols in the symbol table
   - nm ./outfilename.o | grep some_express
 - c++filt utility:  Demangle C++ and Java symbols. Unix utility to help you interpret the function signatures without much struggle.
   - c++filt <_Z4sortIdLi5EEvPT_>  -> void sort<double>(double*, int)
- valgrind
  - valgrind --leak-check=full --show-leak-kinds=all ./outfilename.o 

#### Debugging Multithreaded Code
- Valgrind suite of tools
- Helgrind and DRD tools
 
 <br />//====================================== <br />
