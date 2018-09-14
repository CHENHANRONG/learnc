#### 抽象类和接口的区别
- Abstract Classes Compared to Interfaces : https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html
  - Same points: 
    - Abstract classes are similar to interfaces. 
    - You cannot instantiate them, 
    - they may contain a mix of methods declared with or without an implementation. 
  - differences:
    - with abstract classes, you can declare fields that are not static and final, and define public, protected, and private concrete methods. 
    while With interfaces, all fields are automatically public, static, and final, and all methods that you declare or define (as default methods) are public. 
    - In addition, you can extend only one class, whether or not it is abstract, whereas you can implement any number of interfaces.

  - Which should you use, abstract classes or interfaces?
    - Consider using abstract classes if any of these statements apply to your situation:
      - You want to share code among several closely related classes.
      - You expect that classes that extend your abstract class have many common methods or fields, or require access modifiers other than public (such as protected and private).
      - You want to declare non-static or non-final fields. This enables you to define methods that can access and modify the state of the object to which they belong.
    - Consider using interfaces if any of these statements apply to your situation:
      - You expect that unrelated classes would implement your interface. For example, the interfaces Comparable and Cloneable are implemented by many unrelated classes.
      - You want to specify the behavior of a particular data type, but not concerned about who implements its behavior.
      - You want to take advantage of multiple inheritance of type.
#### 线程同步和异步的区别：
https://blog.csdn.net/u011033906/article/details/53840525

#### 泛型不支持建立泛型数组：
For historical and technical reasons beyond our scope, generic array creation is disallowed in Java. Instead, we need to use a cast:
```Java
public class FixedCapacityStack<Item>
a = new Item[cap]; // not allowed
a = (Item[]) new Object[cap];  // good
```


    
