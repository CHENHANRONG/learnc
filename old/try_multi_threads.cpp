#include "try_multi_threads.h"



int main(){
    values.push_back(42);
    
    thread tr1(threadFnc, 1);
    thread tr2(threadFnc, 2);
    thread tr3(threadFnc, 3);
    thread tr4(threadFnc, 4);
    
    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    
    cout << "Input: " << values[0] << ", Result 1: " << values[1] << ", Result 2: " << values[2] << ", Result 3: " << values[3] << ", Result 4: " << values[4] << "\n";
    
    return 1;
}
