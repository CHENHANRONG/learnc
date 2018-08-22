
<br />//======================================<br />
## Dependency injection
- references:
  - https://en.wikipedia.org/wiki/Dependency_injection
  - http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/dependency_injection.html
<br />//======================================<br />
- The Dependency Injection pattern  is based on the **"inversion of control" (IoC) principle**.
- It relates to the way in which an object obtains references to its dependencies - the object is passed its dependencies through constructor arguments or after construction through setter methods or interface methods.
- The pattern seeks to establish a level of abstraction via a public interface and to remove dependencies on components by supplying a 'plugin' architecture. This means that the individual components are tied together by the architecture rather than being linked together themselves. The responsibility for object creation and linking is removed from the objects themselves and moved to a factory.
- **3 forms of dependency injection: setter-, constructor- and interface-based injection. **
