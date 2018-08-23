//
//  try_concurrency.cpp
//  learnc
//
//  Created by hanrong chen on 8/22/18.
//  Copyright © 2018 hanrong chen. All rights reserved.

/* how we could pass a message from a Thread function to the caller function asynchronously */

#include <stdio.h>
#include <iostream>
#include <future>

using namespace std;

int add(int firstInput, int secondInput)
{
    return firstInput + secondInput;
}

void add2(int firstInput, int secondInput, promise<int> output)
{
    try
    {
        if ((INT_MAX == firstInput) || (INT_MAX == secondInput))
            output.set_exception(current_exception());
    }
    catch (...)
    {
    }

    output.set_value(firstInput + secondInput);
}

void sayHello(promise<string> promise_)
{
    promise_.set_value("Hello Concurrency support library!");
    // cout << endl << "Hello Concurrency support library!" << endl;
}

int main()
{
    /* 
    promiseObj is used by the sayHello() thread function 
    to pass the message to the main thread asynchronously. 
    Note that promise<string> implies that the sayHello() function 
    is expected to pass a string message, 
    hence the main thread retrieves future<string>. 
    The future::get() function call will be blocked until 
    the sayHello() thread function calls the promise::set_value() method.
    sayHello（）线程函数使用promiseObj将消息异步传递给主线程。 
    请注意，promise <string>意味着sayHello（）函数应该传递一个字符串消息，因此主线程会检索future<string>。 
    future :: get（）函数调用将被阻塞，直到sayHello（）线程函数调用promise :: set_value（）方法。
    */
    promise<string> promiseObj;
    future<string> futureObj = promiseObj.get_future();
    /* 
    The std::move() function basically transfers the ownership of promiseObj 
    to the sayHello() thread function, hence promiseObj must not be accessed 
    from the main thread after std::move() is invoked. 
    std :: move（）函数将promiseObj的所有权转移到sayHello（）线程函数，
    因此在调用std :: move（）之后，不能从主线程访问promiseObj。
    */
    async(launch::async, sayHello, move(promiseObj));
    cout << futureObj.get() << endl;
    // futureObj.wait( );

    // created a packaged_task instance called addTask. The packaged_task< int (int,int)>
    // instance implies that the add task will return an integer and take two integer arguments
    packaged_task<int(int, int)>
        addTask([](int firstInput, int secondInput) {
            return firstInput + secondInput;
        });

    future<int> output = addTask.get_future();
    addTask(15, 10);

    cout << "The sum of 15 + 10 is " << output.get() << endl;

    /* how to use a concurrent task with the thread support library */
    packaged_task<int(int, int)> addTask1(add);

    future<int> output1 = addTask1.get_future();

    thread addThread(move(addTask1), 15, 10);

    addThread.join();

    cout << "The sum of 15 + 10 is " << output1.get() << endl;

/* Exception handling with the concurrency library */
    try
    {
        promise<int> promise2_;
        future<int> output2 = promise2_.get_future();
        async(launch::deferred, add2, INT_MAX, INT_MAX, move(promise2_));
        cout << "The sum of INT_MAX + INT_MAX is " << output2.get() << endl;
    }
    catch (exception e)
    {
        cerr << "Exception occured" << endl;
    }
    return 0;
}

/* 
However, it is important to understand that future::get() must only be called once
as the corresponding promise object will be destructed 
after the call to the future::get() method invocation. 
但是，重要的是要理解future :: get（）只能被调用一次，因为在调用future :: get（）方法调用之后将破坏相应的promise对象。
*/
