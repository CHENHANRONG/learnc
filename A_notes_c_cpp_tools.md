

 <br />//====================================== <br />
 **Compile tools**
 - gcc 
   - g++ -Wall -o outfilename cppsource.cpp 
   - Use the g++ **-fdump-tree-original** main.cpp -std=c++17 command to see the **compiler-instantiated code for templates**.
 - The nm Unix utility will list the symbols in the symbol table
   - nm ./outfilename.o | grep some_express
 - c++filt utility:  Demangle C++ and Java symbols. Unix utility to help you interpret the function signatures without much struggle.
   - c++filt <_Z4sortIdLi5EEvPT_>  -> void sort<double>(double*, int)
- valgrind
  - valgrind --leak-check=full --show-leak-kinds=all ./outfilename.o 

 
 <br />//====================================== <br />
