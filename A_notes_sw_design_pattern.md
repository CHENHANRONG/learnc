
<br />//======================================<br />
### Dependency injection
- references:
  - https://en.wikipedia.org/wiki/Dependency_injection
  - http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/dependency_injection.html
  
<br />//======================================<br />
- The Dependency Injection pattern  is based on the **"inversion of control" (IoC) principle**.
- It relates to the way in which an object obtains references to its dependencies - the object is passed its dependencies through constructor arguments or after construction through setter methods or interface methods.
- The pattern seeks to establish a level of abstraction via a public interface and to remove dependencies on components by supplying a 'plugin' architecture. This means that the individual components are tied together by the architecture rather than being linked together themselves. The responsibility for object creation and linking is removed from the objects themselves and moved to a factory.
- **3 forms of dependency injection: setter-, constructor- and interface-based injection.**
- Easy for testing:
  - More flexibility is obtained especially for **testing** since dependencies on a particular deployment environment can be removed from the code making it much easier to test functionality in a simple stand-alone environment. Especially when using **mock-objects** this technique results in highly testable objects. Avoiding dependencies of collaborating classes makes it possible to produce controlled unit-tests that focus on exercising the behaviour of only the class undergoing the test. To achieve this, dependency injection is used to cause instances of the class under the test to interact with mock objects.
- Applicability / Uses:
  - the coupling between components needs to be reduced
  - you are expecting to run controlled unit tests. With dependency injection, testing can begin very early in the development cycle
  - you want to save time in that you don't have to write boilerplate factory creation code over and over again
  
<br />//======================================<br />
### Factory Method Pattern
- references:
  - http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/factory.html
  
  
<br />//======================================<br />
- **polymorphism**
- The factory method pattern deals with the problem of creating objects (products) without specifying the exact class of object that will be created. Factory method handles this problem by defining a separate method for creating the objects, which subclasses can then **override** to specify the **derived type** of product that will be created.
- Applicability / Uses:
  - a class can't anticipate the class of objects it must create.
  - a class wants its subclasses to specify the objects it creates.
  - classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.
- A Factory Method is often used in combination with the Interface Pattern. It is used heavily by generic Frameworks such as Spring.
- Different implementations of factory methods:
  - Parameterized Factory Method 
  - Factory Method is overridden in its subtyped (non-interface at root)
  - Factory Method is inherited, generics can help here (root class is an interface)


<br />//======================================<br />
### Interface Pattern
- references:
  - http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/interface.html
  
  
<br />//======================================<br />


