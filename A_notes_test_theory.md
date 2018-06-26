<br/>=========================<br/>
**Software testability 可测试性**
<br/>=========================<br/>
- Software testability is the degree to which a software artifact (i.e. a software system, software module, requirements- or design document) supports testing in a given test context. If the testability of the software artifact is high, then finding faults in the system (if it has any) by means of testing is easier.
- Testability is not an intrinsic property of a software artifact and can not be measured directly (such as software size). Instead testability is an extrinsic property which results from interdependency of the software to be tested and the test goals, test methods used, and test resources (i.e., the test context).
- **A lower degree of testability results in increased test effort**. In extreme cases a lack of testability may hinder testing parts of the software or software requirements at all. In order to link the testability with the difficulty to find potential faults in a system (if they exist) by testing it, **a relevant measure to assess the testability** is how many test cases are needed in each case to form a complete test suite (i.e. a test suite such that, after applying all test cases to the system, collected outputs will let us unambiguously determine whether the system is correct or not according to some specification). If this size is small, then the testability is high. Based on this measure, a testability hierarchy has been proposed.
- Testability, a property applying to empirical hypothesis, involves two components. The **effort and effectiveness** of software tests depends on numerous factors including:
  - Properties of the software requirements
  - Properties of the software itself (such as size, complexity and testability)
  - Properties of the test methods used
  - Properties of the development- and testing processes
  - Qualification and motivation of the persons involved in the test process
- Testability of software components. <br/>
The testability of software components (modules, classes) is determined by factors such as: <br/>
  - Controllability: The degree to which it is possible to control the state of the component under test (CUT) as required for testing.
  - Observability: The degree to which it is possible to observe (intermediate and final) test results.
  - Isolateability: The degree to which the component under test (CUT) can be tested in isolation.
  - Separation of concerns: The degree to which the component under test has a single, well defined responsibility.
  - Understandability: The degree to which the component under test is documented or self-explaining.
  - Automatability: The degree to which it is possible to automate testing of the component under test.
  - Heterogeneity: The degree to which the use of diverse technologies requires to use diverse test methods and tools in parallel.
- The testability of software components can be improved by:
  - Test-driven development
  - Design for testability (similar to design for test in the hardware domain)
- Testability hierarchy <br/>
Based on the amount of test cases required to construct a complete test suite in each context (i.e. a test suite such that, if it is applied to the implementation under test, then we collect enough information to precisely determine whether the system is correct or incorrect according to some specification), a testability hierarchy with the following testability classes has been proposed: <br/>
  - Class I: there exists a finite complete test suite.
  - Class II: any partial distinguishing rate (i.e. any incomplete capability to distinguish correct systems from incorrect systems) can be reached with a finite test suite.
  - Class III: there exists a countable complete test suite.
   - Class IV: there exists a complete test suite.
   - Class V: all cases.
   - It has been proved that each class is strictly included into the next. For instance, testing when we assume that the behavior of the implementation under test can be denoted by a deterministic finite-state machine for some known finite sets of inputs and outputs and with some known number of states belongs to Class I (and all subsequent classes). However, if the number of states is not known, then it only belongs to all classes from Class II on. If the implementation under test must be a deterministic finite-state machine failing the specification for a single trace (and its continuations), and its number of states is unknown, then it only belongs to classes from Class III on. Testing temporal machines where transitions are triggered if inputs are produced within some real-bounded interval only belongs to classes from Class IV on, whereas testing many non-deterministic systems only belongs to Class V (but not all, and some even belong to Class I). The inclusion into Class I does not require the simplicity of the assumed computation model, as some testing cases involving implementations written in any programming language, and testing implementations defined as machines depending on continuous magnitudes, have been proved to be in Class I. Other elaborated cases, such as the testing framework by Matthew Hennessy under must semantics, and temporal machines with rational timeouts, belong to Class II.
- Testability of requirements <br/>
Requirements need to fulfill the following criteria in order to be testable: <br/>
  - consistent
  - complete
  - unambiguous
  - quantitative (a requirement like "fast response time" can not be verification/verified)
  - verification/verifiable in practice (a test is feasible not only in theory but also in practice with limited resources)
- references:
  - https://blog.csdn.net/vincetest/article/details/1463626
  
<br/>=========================<br/>
**Test strategy 测试策略**
1. Test levels
1. Roles and responsibilities
1. Environment requirements
1. Testing tools
1. Risks and mitigation
1. Test schedule
1. Regression test approach
1. Test groups
1. Test priorities
1. Test status collections and reporting
1. Test records maintenance
1. Requirements traceability matrix
1. Test summary
reference: https://en.wikipedia.org/wiki/Test_strategy
<br/>=========================<br/>
**测试策略** <br/>
一般来说，测试策略描述了软件开发过程中进行测试方法，用来告诉测试过程中所有可能的参与者，测试活动应该如何进行。其中主要会包括测试目标，测试新功能的方法，测试项目的时间和资源，以及测试环境等等。除此以外，测试策略应该描述测试过程中存在哪些风险，以及如何能够规避或者降低这些风险。同时，测试策略也会提到测试的级别，哪些测试应该被执行，入口出口条件是什么。创建测试策略时候我们可以参考各种需求文档和设计文档. <br/>
一般来说，测试策略在结构上可以包括以下一些要点：<br/>
  - 测试级别：常见的测试级别有单元测试，集成测试和系统测试。大部分的测试组织里面，单元测试由开发负责，而集成测试和系统测试由测试部门或者质量保证部门负责。
  - 角色与职责：需要在测试策略里面明确定义各个角色，以及该角色的职责。比如项目经理，测试组长，测试工程师…
  - 环境需求：这一点非常重要，它将描述测试时需要的系统环境，包括软硬件以及网络环境等等。在澄清环境需求的时候，测试组织可以识别出资源方面的风险。
  - 风险分析：影响测试过程的风险都应该尽早被识别出来，而且必须有相应的解决办法以便消除或者减轻这些风险。
  - 测试进度：测试进度将会评估完成测试所需要的时间。在设定进度的时候，首先需要明确测试范围，然后根据测试资源的多少来制定能被各方面认可的测试进度计划。做一个非常准确的进度计划是困难的事情，因为测试过程中充满了各种不确定性，所以一般计划者需要考虑增加一定的buffer。当然，制定进度计划的时候可以参考已有的项目的数据。如果是一个全新的软件项目，专家认为将初始计划的时间翻倍比较靠谱！
  - 回归测试方法：回归测试用来保证之前fix bug的代码不会影响软件的其他部分，这样需要我们选择已经执行过的测试用例重新运行。测试人员需要找到一个方法来确定哪些测试用例应该在回归测试中运行，用例不能太多，因为资源有限，用例也不能太少，否则会达不到必须的测试强度。不过，如果测试部门对待测系统以及软件架构非常了解的话，就比较容易找到合适的回归测试集合。
  - 测试范围：这个没啥好说的，就是你要测试的内容，可能是某些模块，可能是某些指标，比如功能，性能，易用性…
  - 测试优先级：测试范围内的东西不会都是一样重要的，加上测试资源各种有限，所以为测试排定优先级是十分的必要。
  
<br/>测试策略是对整个测试项目的整理规划，主要考虑如下内容：<br/>
1. 使用的测试标准：这个在实际过程中一般仅作参考，各企业在具体执行时差别较大。具体内容可参考软件产品测试标准
1. 测试风险: 这个是必须考虑的内容，具体规划和执行时可参考浅谈实施软件测试风险分析
1. 测试级别及内容:
    - 根据动态测试在软件开发过程中所处的阶段和作用分为
      - 单元测试
      - 集成测试
      - 系统测试
      - 验收测试（Alpha、Beta、用户验收、运营验收、功能验收）
      - 回归测试   
    - 从是否关心软件内部结构和具体实现的角度划分　　
      - 白盒测试
      - 黑盒测试
      - 灰盒测试
    - 黑盒测试分为功能测试和性能测试：
      - 功能测试（function testing），是黑盒测试的一方面，它检查实际软件的功能是否符合用户的需求。
        - 包括逻辑功能测试（logic function testing), 
        - 界面测试（UI testing）UI=User Interface),
        - 易用性测试（usability testing）：是指从软件使用的合理性和方便性等角度对软件系统进行检查，来发现软件中不方便用户使用的地方。
        - 兼容性测试（compatibility testing）：包括硬件兼容性测试和软件兼容性测试
      - 性能测试（performance testing）软件的性能主要有时间性能和空间性能两种.
        - 时间性能：主要指软件的一个具体事务的响应时间（respond time）。
        - 空间性能：主要指软件运行时所消耗的系统资源。
        - 软件性能测试分为：
          - 一般性能测试：指的是让被测系统在正常的软硬件环境下运行，不向其施加任何压力的性能测试。
          - 稳定性测试也叫可靠性测试（reliability testing）：是指连续运行被测系统检查系统运行时的稳定程度。
          - 负载测试（load testing）：是指让被测系统在其能忍受的压力的极限范围之内连续运行，来测试系统的稳定性。
          - 压力测试（stress testing）：是指持续不断的给被测系统增加压力，直到将被测系统压垮为止，用来测试系统所能承受的最大压力。
      - 其他测试类型：
        - 回归测试（regression testing）是指对软件的新的版本测试时，重复执行上一个版本测试时的用例。
        - 冒烟测试（smoke testing），是指在对一个新版本进行大规模的测试之前，先验证一下软件的基本功能是否实现，是否具备可测性。
        - 随机测试（random testing），是指测试中所有的输入数据都是随机生成的，其目的是模拟用户的真实操作，并发现一些边缘性的错误。
1. 测试入口／出口标准这个标准一般研发内部根据公司标准讨论确定，但一般在实际测试时很难完全遵照执行。
1. 测试用例设计技术
    - Behaviour-based，通常包括等价内划分、边界值划分、领域分析、决策表分析、因果分析、状态迁移表、用例场景等方法。
    - Structure-based: 这个更偏向白盒测试，包括语句、判定、条件、循环、路径分析等。
    - Experience-based: 通常包括错误猜测、检查表、探索性测试等方法；
    - Defect-based: 通常包括错误注入、随机测试等；
1. 测试环境包括功能测试环境、性能测试环境、自动化测试环境。如果有完整的业务测试要求还需要端到端的系统／解决方案测试环境。
1. 测试自动化
    - 功能测试自动化常用的工具有QTP, Selenium, Robotium;
    - 性能测试自动化工具： 传统的压力测试工具Load Runner功能很强大，但需要具备一定的开发基础，但局限性也很明显，很难适应互联网环境的在线业务性能测试。基于互联网的云测试工具包括SOASTA,压测宝等，可以对在线业务实施大规模并发测试，解决了很多传统测试无法解决的在线业务性能和用户体验性能等问题，比较适合移动互联网产品的测试和评估。
1. 测试度量测试部门需要规划从哪些方面去衡量当前产品的质量，对应的衡量要素的具体标准是什么范围，便于后期具体测试时进行评估。
1. 测试管理这个一般有质量管理平台软件来负责，实现对测试全生命周期的管理。常用的有商用软件Quality Center,开源软件JIRA, Redmine等。
1. 测试过程改进一般公司常参考CMMI/TMM/TPI Matrix等过程改进模型，结合公司具体的实际进行改进。
