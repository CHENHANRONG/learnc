#include<iostream>
#include<thread>
#include<mutex>
#include<random>
#include <vector>


using namespace std;

//--- Globals
mutex values_mtx;
mutex cout_mtx;
vector<int> values;


int randGen(const int& min, const int& max){
    static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void threadFnc(int tid){
    //Calculate the result
    cout_mtx.lock();
    cout<< "Starting thread" << tid << ".\n";
    cout_mtx.unlock();

    values_mtx.lock();
    int val = values[0];
    values_mtx.unlock();

    int rval = randGen(1,10);
    val += rval;

    cout_mtx.lock();
    cout<< "Thread " << tid << " adding " << rval << ". New value: " << val << ".\n";
    cout_mtx.unlock();

    values_mtx.lock();
    values.push_back(val);
    values_mtx.unlock();
}

