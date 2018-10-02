### how to determine the dead lock in code.
- for c/c++: http://valgrind.org/docs/manual/hg-manual.html
- for Java: http://korhner.github.io/java/multithreading/detect-java-deadlocks-programmatically/
```Java
ThreadMXBean bean = ManagementFactory.getThreadMXBean();
long[] threadIds = bean.findDeadlockedThreads(); // Returns null if no threads are deadlocked.

if (threadIds != null) {
    ThreadInfo[] infos = bean.getThreadInfo(threadIds);

    for (ThreadInfo info : infos) {
        StackTraceElement[] stack = info.getStackTrace();
        // Log or store stack trace information.
    }
}
```


### how to find the root cause of 500 status code?


### difference between runnable and callable.
The Callable interface is similar to Runnable, in that both are designed for classes whose instances are potentially executed by another thread.   
A Runnable, however, does not return a result and cannot throw a checked exception.  

- Callable vs Runnable
  - For implementing Runnable, the run() method needs to be implemented which does not return anything, while for a Callable, the call() method needs to be implemented which returns a result on completion. Note that a thread can’t be created with a Callable, it can only be created with a Runnable.
  - Another difference is that the call() method can throw an exception whereas run() cannot


```Java

A Callable needs to implement call() method while a Runnable needs to implement run() method.
A Callable can return a value but a Runnable cannot.
A Callable can throw checked exception but a Runnable cannot.
A Callable can be used with ExecutorService#invokeXXX(Collection<? extends Callable<T>> tasks) methods but a Runnable cannot be.

public interface Runnable {
    void run();
}

public interface Callable<V> {
    V call() throws Exception;
}


public class HelloRunnable implements Runnable {

    public void run() {
        System.out.println("Hello from a thread!");
    }   

    public static void main(String args[]) {
        (new Thread(new HelloRunnable())).start();
    }

}



// Java program to illustrate Callable and FutureTask 
// for random number generation 
import java.util.Random; 
import java.util.concurrent.Callable; 
import java.util.concurrent.FutureTask; 
  
class CallableExample implements Callable 
{ 
  
  public Object call() throws Exception 
  { 
    Random generator = new Random(); 
    Integer randomNumber = generator.nextInt(5); 
  
    Thread.sleep(randomNumber * 1000); 
  
    return randomNumber; 
  } 
  
} 
  
public class CallableFutureTest 
{ 
  public static void main(String[] args) throws Exception 
  { 
  
    // FutureTask is a concrete class that 
    // implements both Runnable and Future 
    FutureTask[] randomNumberTasks = new FutureTask[5]; 
  
    for (int i = 0; i < 5; i++) 
    { 
      Callable callable = new CallableExample(); 
  
      // Create the FutureTask with Callable 
      randomNumberTasks[i] = new FutureTask(callable); 
  
      // As it implements Runnable, create Thread 
      // with FutureTask 
      Thread t = new Thread(randomNumberTasks[i]); 
      t.start(); 
    } 
  
    for (int i = 0; i < 5; i++) 
    { 
      // As it implements Future, we can call get() 
      System.out.println(randomNumberTasks[i].get()); 
  
      // This method blocks till the result is obtained 
      // The get method can throw checked exceptions 
      // like when it is interrupted. This is the reason 
      // for adding the throws clause to main 
    } 
  } 
} 


```
- reference: 
  - https://www.geeksforgeeks.org/callable-future-java/
  - https://docs.oracle.com/javase/7/docs/api/java/util/concurrent/Callable.html
  
