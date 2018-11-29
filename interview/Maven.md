# Maven

## Understand Maven

### POM (project object model)
Elements:
  - artifactId: used for the name of the program.
  - groupId: ?
  - packaging: java-jar, cpp-?
  - version:
    
groupId+artifactId+version == coordinates of the project. (must be unique combination)

Features are enabled by using POM are:
  - dependency management.
  - remote repository.
  - universal reuse of build logic.
  - tool portability and integration.
  - easy searching and filtering of project artifacts.
 

### Maven life cycle
- validate: validate the proejct is correct.
- compile: compile the source code of the project.
- test:  test the compiled source code using a unit test framework.
- package: package the compiled code.
- integration-test: deploy the package into an environment where integration tests can be run.
- verify: run any checks to verify the package is valid.
- install: install the package to into local repository.
- deploy: copies the final package to the remote repository.

### Maven repository
- central repository that contains open-source components.
- maven create a local repository ~/.m2
  
### Maven's dependency management


## Maven plugins
plugins list: https://maven.apache.org/plugins/index.html  
### core plugins
goals: e.g. for complier plugin, there are two goals in page: https://maven.apache.org/plugins/maven-compiler-plugin/   "Goals Overview" section.  
call plugin goals: mvn \<plagin name\>:\<goal name\>
### packaging tools
### reporting plugins
### tools


## Create a project with Maven





## Resources:
- https://search.maven.org
- 
 