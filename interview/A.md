## 没回答出来的：
### PMD, 静态代码检验，验证什么？通过标准是什么？
### GIT， 常规使用GIT的流程 （diff）
### 单元测试的通过标准
### mock， stub， 如果模块没有做好，怎么在测试其他模块时候处理依赖的部分没有完成
### 新功能，新特性，如果短期产生大量的bug，怎么跟踪，解决bug？ 如果极端情况是，中短期累计了巨量的bug，应如何处理？ （From PM）
### 介绍使用的自动化框架，列举几个最常用的对象及其API






## 如何测试快递柜
- 专项测试：
  - 性能测试
  - 安全性测试
  - 兼容性测试
  - 可靠性测试 + 疲劳测试
- 功能测试：
  - 界面测试
  - 容量测试： 
  - 易用性测试
  - 故障转移&恢复
  - 可用性测试
  - 等价类： 
  - 边界值
  - 因果图 & 状态转换图
  - 各种异常场景测试： 错误猜测+场景分析

## automation qa
### 公匙 私匙
- What is encryption?
  - Encryption in its simplest form is scrambling a message so that it cannot be read until it is unscrambled later by the receiver. The sender uses an algorithmic pattern (or key) to scramble (or encrypt) the message. The receiver has the decryption key. Encryption ensures privacy and confidentiality in transmissions sent over the Internet.

  - There are two kinds of keys that can be used for encryption:
      - Asymmetric keys
      With asymmetric keys, you create a key pair. The key pair is made up of a public key and a private key, which are different from each other. The private key holds more of the secret encryption pattern than the public key. Your private key should not be shared with anyone.    
      The server uses its private key to sign messages to clients. The server sends its public key to clients so that they can encrypt messages to the server, which the server decrypts with its private key. Only you can decrypt a message that has been encrypted with your public key, because only you have the private key. Key pairs are stored in a key database which is protected by a password.  
      - Symmetric keys
      Symmetric keys follow an age-old model of the sender and receiver sharing some kind of pattern. This same pattern is then used by the sender to encrypt the message and by the receiver to decrypt the message.  
      The risk involved with symmetric keys is that you have to find a safe transportation method to use when sharing your secret key with the people you want to communicate with.  

  - The Secure Sockets Layer (SSL) protocol uses both asymmetric and symmetric key exchange. 
    Asymmetric keys are used for the SSL handshake. During the handshake the master key, encrypted with the receiver's public key, is passed from the client to the server. The client and server make their own session keys using the master key. The session keys are used to encrypt and decrypt data for the remainder of the session. Symmetric key exchange is used during the exchange of the cipher specification (or encryption level) used.  
    To send its public key to clients, the server needs a digital certificate. This certificate is issued by a certificate authority (CA) who verifies the identity of the server.  
  
  - Related Information:
      - For more information about the SSL protocol, see What is the Secure Sockets Layer protocol?.
      - For details on supported key sizes, see Cipher specifications and key sizes.

- https://www-01.ibm.com/software/webservers/httpservers/doc/v1312/ibm/9atssl.htm
- https://docs.oracle.com/cd/E19509-01/820-3503/ggbgc/index.html

  

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
  - https://www.cnblogs.com/dolphin0520/p/3949310.html
  - https://docs.oracle.com/javase/7/docs/api/java/util/concurrent/Callable.html
  



## HashMap的实现

### Difference between HashMap and ConcurrentHashMap
- https://www.geeksforgeeks.org/difference-hashmap-concurrenthashmap/
  
### hashcode comes from where? how to calculate the hashcode ?
- https://stackoverflow.com/questions/2427631/how-is-hashcode-calculated-in-java
- https://www.cnblogs.com/dolphin0520/p/3681042.html

