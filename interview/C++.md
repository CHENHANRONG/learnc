# C++ 知识点总结
## 1. C++基础知识点
### 1.1 有符号类型和无符号类型
- 当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模之后的余数。**当我们赋给带符号类型一个超出它表示范围的值时，结果是未定义的**；此时，程序可能继续工作、可能崩溃。也可能生成垃圾数据。
- 如果表达式中既有带符号类型由于无符号类型那个，当带符号类型取值为负时会出现异常结果，这是因为带符号数会自动转换成无符号数。

```C++
int a = 1;unsigned int b = -2;
cout<<a+b<<endl;   // 输出4294967295
int c = a + b;   //c=-1;
a = 3;b = -2;
cout<<a+b<<endl;   // 输出1
```

### 1.2 引用与指针
引用并非对象，它只是为一个已经存在的对象起的一个别名。在定义引用时，程序把引用和它的初始值绑定在一起，而不是将初始值拷贝给引用。一旦初始化完成，应用将和它的初始值绑定在一起。以为无法令引用重新绑定到另外一个对象，因此引用必须初始化。

指针是指向另外一种类型的符合类型。与引用类似，指针也实现了对其他对象的简介访问。然而指针与引用相比又有许多不同点：
- 指针本身就是一个对象，允许对指针赋值和拷贝。而且在指针的生命周期内它可以先后指向几个不同的对象。引用不是对象，所以也不能定义指向引用的指针。
- 指针无须在定义时赋值。

`void*`是一种特殊的指针类型，可以存放任意对象的地址。但我们对该地址中存放的是什么类型的对象并不了解，所以也不能直接操作`void*`指针所指的对象。

### 1.3 static关键字
- 申明为static的局部变量，存储在静态存储区，其生存期不再局限于当前作用域，而是整个程序的生存期。
- 对于全局变量而言， 普通的全局变量和函数，其作用域为整个程序或项目，外部文件（其它cpp文件）可以通过extern关键字访问该变量和函数；static全局变量和函数，其作用域为当前cpp文件，其它的cpp文件不能访问该变量和函数。
- 当使用static修饰成员变量和成员函数时，表示该变量或函数属于一个类，而不是该类的某个实例化对象。

### 1.4 const限定符
const的作用
1. 在定义常变量时必须同时对它初始化，此后它的值不能再改变。常变量不能出现在赋值号的左边（不为“左值”）；
2. 对指针来说，可以指定指针本身为const，也可以指定指针所指的数据为const，或二者同时指定为const；
3. 在一个函数声明中，const可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值；
4. 对于类的成员函数，若指定其为const类型，则表明其是一个常函数，不能修改类的成员变量；
5. 对于类的成员函数，有时候必须指定其返回值为const类型，以使得其返回值不为"左值"。例如：
```C++
//operator*的返回结果必须是一个const对象，否则下列代码编译出错
const classA operator*(const classA& a1,const classA& a2);  
classA a, b, c;
(a*b) = c;  //对a*b的结果赋值。操作(a*b) = c显然不符合编程者的初衷，也没有任何意义
```

用const修饰的符号常量的区别：**const位于`（*）`的左边，表示被指物是常量；const位于`(*)`的右边，表示指针自身是常量（常量指针）。（口诀：左定值，右定向）**
```C++
const char *p;  //指向const对象的指针，指针可以被修改，但指向的对象不能被修改。
char const *p;  //同上
char * const p; //指向char类型的常量指针，指针不能被修改，但指向的对象可以被修改。
const char * const p;  //指针及指向对象都不能修改。
```

const与#define的区别
1. const常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查。而对后者只进行字符替换，没有类型安全检查，并且在字符替换可能会产生意料不到的错误（边际效应）。
2. 有些集成化的调试工具可以对const常量进行调试，但是不能对宏常量进行调试。
3. 在C++程序中只使用const常量而不使用宏常量，即const常量完全取代宏常量。

### 1.5 数组与指针的区别
1. 数组要么在静态存储区被创建（如全局数组），要么在栈上被创建。指针可以随时指向任意类型的内存块。
2. 用运算符sizeof可以计算出数组的容量（字节数）。sizeof(p)，p为指针得到的是一个指针变量的字节数，而不是p所指的内存容量。C/C++语言没有办法知道指针所指的内存容量，除非在申请内存时记住它。
3. C++编译系统将形参数组名一律作为指针变量来处理。实际上在函数调用时并不存在一个占有存储空间的形参数组，只有指针变量。

实参数组名a代表一个固定的地址，或者说是指针型常量，因此要改变a的值是不可能的。例如：`a++；`是错误的。形参数组名array是指针变量，并不是一个固定的地址值。它的值是可以改变的。例如：`array++；`是合法的。

为了节省内存，C/C++把常量字符串放到单独的一个内存区域。当几个指针赋值给相同的常量字符串时，它们实际上会指向相同的内存地址。但用常量内存初始化数组时，情况却有所不同。
```C++
char str1[] = “Hello World”;
char str2[] = “Hello World”;
char *str3[] = “Hello World”;
char *str4[] = “Hello World”;
```
其中，str1和str2会为它们分配两个长度为12个字节的空间，并把“Hello World”的内容分别复制到数组中去，这是两个初始地址不同的数组。str3和str4是两个指针，我们无须为它们分配内存以存储字符串的内容，而只需要把它们指向“Hello World”在内存中的地址就可以了。由于“Hello World”是常量字符串，它在内存中只有一个拷贝，因此str3和str4指向的是同一个地址。

### 1.6 sizeof运算符
sizeof是C语言的一种单目操作符，它并不是函数。操作数可以是一个表达式或类型名。数据类型必须用括号括住，`sizeof（int）;`变量名可以不用括号括住。
```C++
int a[50];  //sizeof(a)=200
int *a=new int[50];  //sizeof(a)=4;
Class Test{int a; static double c};  //sizeof(Test)=4
Test *s;  //sizeof(s)=4
Class Test{ };  //sizeof(Test)=1
int func(char s[5]);  //sizeof(s)=4;
```
操作数不同时注意事项：
1. **数组类型**，其结果是数组的总字节数；**指向数组的指针**，其结果是该指针的字节数。
2. 函数中的**数组形参**或**函数类型的形参**，其结果是指针的字节数。
3. **联合类型**，其结果采用成员最大长度对齐。
4. **结构类型或类类型**，其结果是这种类型对象的总字节数，包括任何填充在内。
 - 类中的静态成员不对结果产生影响，因为静态变量的存储位置与结构或者类的实例地址无关;
 - 没有成员变量的类的大小为1，因为必须保证类的每一个实例在内存中都有唯一的地址;
 - 有虚函数的类都会建立一张虚函数表，表中存放的是虚函数的函数指针，这个表的地址存放在类中，所以不管有几个虚函数，都只占据一个指针大小。

### 例题：
1、下列联合体的sizeof(sampleUnion)的值为多少。
```C++
union{
    char flag[3];
    short value;
} sampleUnion;
```
答案：4。联合体占用大小采用成员最大长度的对齐，最大长度是short的2字节。但char flag[3]需要3个字节，所以sizeof(sampleUnion) = 2*（2字节）= 4。注意对齐有两层含义，一个是按本身的字节大小数对齐，一个是整体按照最大的字节数对齐。

2、在32位系统中：
```C++
char arr[] = {4, 3, 9, 9, 2, 0, 1, 5};
char *str = arr;
sizeof(arr) = 8;
sizeof(str) = 4;
strlen(str) = 5;
```
答案：8，4，5。注意strlen函数求取字符串长度以ASCII值为0为止。

3、定义一个空的类型，里面没有任何成员变量和成员函数。
问题：对该类型求sizeof，得到的结果是什么？
答案：1。
问题：为什么不是0？
答案：当我们声明该类型的实例的时候，它必须在内存中占有一定的空间，否则无法使用这些实例。至于占用多少内存，由编译器决定。Visual Studio中每个空类型的实例占用1字节的空间。
问题：如果在该类型中添加一个构造函数和析构函数，结果又是什么？
答案：还是1。调用构造函数和析构函数只需要知道函数的地址即可，而这些函数的地址只与类型相关，而与类型的实例无关。
问题：那如果把析构函数标记为虚函数呢？
答案：C++的编译器一旦发现一个类型中有虚函数，就会为该类型生成虚函数表，并在该类型的每一个实例中添加一个指向虚函数表的指针。在32位的机器上，指针占用4字节，因此求sizeof得到4；如果是64位机器，将得到8。

### 1.7 四个强制类型转换
C++中有以下四种命名的强制类型转换：
- **static_cast**：任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast。
- **const_cast**：去const属性，只能改变运算对象的底层const。常用于有函数重载的上下文中。
- **reninterpret_cast**：通常为运算对象的位模式提供较低层次的重新解释，本质依赖与机器。
- **dynamic_cast**：主要用来执行“安全向下转型”，也就是用来决定某对象是否归属继承体系中的某个类型。主要用于多态类之间的转换

一般来说，如果编译器发现一个较大的算术类型试图赋值给较小的类型，就会给出警告；但是当我们执行了显式的类型转换之后，警告信息就被关闭了。
```C++
//进行强制类型转换以便执行浮点数除法
int j = 1,i = 2;
double slope = static_cast<double>(j)/i;

//任何非常量对象的地址都能存入void*，通过static_cast可以将指针转换会初始的指针类型
void* p = &slope;
double *dp = static_cast<double*>(p);
```

只有const_cast能够改变表达式的常量属性，其他形式的强制类型转换改变表达式的常量属性都将引发编译器错误。
```C++
//利用const_cast去除底层const
const char c = 'a';
const char *pc = &c;
char* cp = const_cast<char*>(pc);
*cp = 'c';
```

reinterpret_cast常用于函数指针类型之间进行转换。
```C++
int doSomething(){return0;};
typedef void(*FuncPtr)(); //FuncPtr是一个指向函数的指针，该函数没有参数，返回值类型为void
FuncPtr funcPtrArray[10]; //假设你希望把一个指向下面函数的指针存入funcPtrArray数组：

funcPtrArray[0] =&doSomething;// 编译错误！类型不匹配
funcPtrArray[0] = reinterpret_cast<FuncPtr>(&doSomething); //不同函数指针类型之间进行转换
```

dynamic_cast
有条件转换，动态类型转换，运行时类型安全检查(转换失败返回NULL)：
1. 安全的基类和子类之间转换。
2. 必须要有虚函数。
3. 相同基类不同子类之间的交叉转换。但结果是NULL。

```C++
class Base {
public:
int m_iNum;
virtualvoid foo(){}; //基类必须有虚函数。保持多态特性才能使用dynamic_cast
};

class Derive: public Base {
public:
char*m_szName[100];
void bar(){};
};

Base* pb =new Derive();
Derive *pd1 = static_cast<Derive *>(pb); //子类->父类，静态类型转换，正确但不推荐
Derive *pd2 = dynamic_cast<Derive *>(pb); //子类->父类，动态类型转换，正确

Base* pb2 =new Base();
Derive *pd21 = static_cast<Derive *>(pb2); //父类->子类，静态类型转换，危险！访问子类m_szName成员越界
Derive *pd22 = dynamic_cast<Derive *>(pb2); //父类->子类，动态类型转换，安全的。结果是NULL
```

### 1.8 结构体的内存对齐
内存对齐规则
- 每个成员相对于这个结构体变量地址的偏移量正好是该成员类型所占字节的整数倍。为了对齐数据，可能必须在上一个数据结束和下一个数据开始的地方插入一些没有用处字节。
- 且最终占用字节数为成员类型中最大占用字节数的整数倍。

```C++
struct AlignData1
{
    char c;
    short b;
    int i;
    char d;
}Node;
```
这个结构体在编译以后，为了字节对齐，会被整理成这个样子：
```C++
struct AlignData1
{
    char c;
    char padding[1];
    short b;
    int i;
    char d;
    char padding[3];
}Node;
```
所以编译前总的结构体大小为：8个字节。编译以后字节大小变为：12个字节。
但是，如果调整顺序：
```
struct AlignData2
{
    char c;
    char d;
    short b;
    int i;
}Node;
```
那么这个结构体在编译前后的大小都是8个字节。
那么编译后不用填充字节就能保持所有的成员都按各自默认的地址对齐。这样可以节约不少内存！一般的结构体成员按照默认对齐字节数递增或是递减的顺序排放，会使总的填充字节数最少。

### 1.9 malloc/free 与 new/delete的区别
1. malloc与free是C++/C语言的标准库函数，new/delete是C++的运算符。它们都可用于申请和释放动态内存。
2. 对于非内部数据类型的对象而言，用maloc/free无法满足动态对象的要求。对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由malloc/free是库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于malloc/free，因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，和一个能完成清理与释放内存工作的运算符delete。
3. new可以认为是malloc加构造函数的执行。new出来的指针是直接带类型信息的。而malloc返回的都是void*指针。new delete在实现上其实调用了malloc,free函数。
4. new 建立的是一个对象；malloc分配的是一块内存。

## 2. 面对对象编程
### 2.1 String类的实现


### 2.2 派生类中构造函数与析构函数，调用顺序
构造函数的调用顺序总是如下：
1. 基类构造函数。如果有多个基类，则构造函数的调用顺序是某类**在类派生表中出现的顺序**，而不是它们在成员初始化表中的顺序。
2. 成员类对象构造函数。如果有多个成员类对象则构造函数的调用顺序是对象**在类中被声明的顺序**，而不是它们出现在成员初始化表中的顺序。如果有的成员不是类对象，而是基本类型，则初始化顺序按照声明的顺序来确定，而不是在初始化列表中的顺序。
3. 派生类构造函数。

析构函数正好和构造函数相反。

### 2.3 虚函数的实现原理
虚函数表：
编译器会为每个有虚函数的类创建一个虚函数表，该虚函数表将被该类的所有对象共享。类的虚函数表是一块连续的内存，每个内存单元中记录一个JMP指令的地址。类的每个虚函数占据虚函数表中的一块，如果类中有N个虚函数，那么其虚函数表将有4N字节的大小。

编译器在有虚函数的类的实例中创建了一个指向这个表的指针，该指针通常存在于对象实例中最前面的位置（这是为了保证取到虚函数表的有最高的性能）。这意味着可以通过对象实例的地址得到这张虚函数表，然后就可以遍历其中函数指针，并调用相应的函数。

有虚函数或虚继承的类实例化后的对象大小至少为4字节（确切的说是一个指针的字节数；说至少是因为还要加上其他非静态数据成员，还要考虑对齐问题）；没有虚函数和虚继承的类实例化后的对象大小至少为1字节（没有非静态数据成员的情况下也要有1个字节来记录它的地址）。

**哪些函数适合声明为虚函数，哪些不能？**
- 当存在类继承并且析构函数中有必须要进行的操作时（如需要释放某些资源，或执行特定的函数）析构函数需要是虚函数，否则若使用父类指针指向子类对象，在delete时只会调用父类的析构函数，而不能调用子类的析构函数，从而造成内存泄露或达不到预期结果；
- 内联函数不能为虚函数：内联函数需要在编译阶段展开，而虚函数是运行时动态绑定的，编译时无法展开；
- 构造函数不能为虚函数：构造函数在进行调用时还不存在父类和子类的概念，父类只会调用父类的构造函数，子类调用子类的，因此不存在动态绑定的概念；但是构造函数中可以调用虚函数，不过并没有动态效果，只会调用本类中的对应函数；
- 静态成员函数不能为虚函数：静态成员函数是以类为单位的函数，与具体对象无关，虚函数是与对象动态绑定的。

### 2.4 虚继承的实现原理
为了解决从不同途径继承来的同名的数据成员在内存中有不同的拷贝造成数据不一致问题，将共同基类设置为虚基类。这时从不同的路径继承过来的同名数据成员在内存中就只有一个拷贝，同一个函数名也只有一个映射。这样不仅就解决了二义性问题，也节省了内存，避免了数据不一致的问题。

构造函数和析构函数的顺序：虚基类总是先于非虚基类构造，与它们在集成体系中的次序和位置无关。如果有多个虚基类，则按它们在派生列表中出现的顺序从左到右依次构造。
```C++
#include <iostream>
using namespace std;

class zooAnimal
{
public: zooAnimal(){cout<<"zooAnimal construct"<<endl;}
};
class bear : virtual public zooAnimal
{
public: bear(){cout<<"bear construct"<<endl;}
};
class toyAnimal
{
public: toyAnimal(){cout<<"toyAnimal construct"<<endl;}
};
class character
{
public: character(){cout<<"character construct"<<endl;}
};
class bookCharacter : public character
{
public: bookCharacter(){cout<<"bookCharacter construct"<<endl;}
};
class teddyBear : public bookCharacter, public bear, virtual public toyAnimal
{
public: teddyBear(){cout<<"teddyBear construct"<<endl;}
};

int main()
{
    teddyBear();
}
```
编译器按照直接基类的声明顺序依次检查，以确定其中是否含有虚基类。如果有，则先构造虚基类，然后按照声明顺序依次构造其他非虚基类。构造函数的顺序是：zooAnimal, toyAnimal, character, bookCharacter, bear, teddyBear。析构过程与构造过程正好相反。

## 3. 内存管理
### 3.1 程序加载时的内存分布
在多任务操作系统中，每个进程都运行在一个属于自己的虚拟内存中，而虚拟内存被分为许多页，并映射到物理内存中，被加载到物理内存中的文件才能够被执行。这里我们主要关注程序被装载后的内存布局，其可执行文件包含了代码段，数据段，BSS段，堆，栈等部分，其分布如下图所示。
![内存分布](http://i.imgur.com/6RnIyLw.png)

- 代码段(.text)：用来存放可执行文件的机器指令。存放在只读区域，以防止被修改。
- 只读数据段(.rodata)：用来存放常量存放在只读区域，如字符串常量、全局const变量等。
- 可读写数据段(.data)：用来存放可执行文件中已初始化全局变量，即静态分配的变量和全局变量。
- BSS段(.bss)：未初始化的全局变量和局部静态变量一般放在.bss的段里，以节省内存空间。
- 堆：用来容纳应用程序动态分配的内存区域。当程序使用malloc或new分配内存时，得到的内存来自堆。堆通常位于栈的下方。
- 栈：用于维护函数调用的上下文。栈通常分配在用户空间的最高地址处分配。
- 动态链接库映射区：如果程序调用了动态链接库，则会有这一部分。该区域是用于映射装载的动态链接库。
- 保留区：内存中受到保护而禁止访问的内存区域。

### 3.2 堆与栈的区别
#### 1. 申请管理方式
（1）栈：由编译器自动管理，无需我们手工控制。
（2）堆：堆的申请和释放工作由程序员控制，容易产生内存泄漏。
#### 2. 申请后系统的响应
（1）栈：只要栈的剩余空间大于所申请空间，系统将为程序提供内存，否则将报异常提示栈溢出。
（2）堆：首先应该知道操作系统有一个记录空闲内存地址的链表，当系统收到程序的申请时，会遍历该链表，寻找第一个空间大于所申请空间的堆结点，然后将该结点从空闲结点链表中删除，并将该结点的空间分配给程序，另外，对于大多数系统，会在这块内存空间中的首地址处记录本次分配的大小，这样，代码中的delete语句才能正确的释放本内存空间。另外，由于找到的堆结点的大小不一定正好等于申请的大小，系统会自动的将多余的那部分重新放入空闲链表中。
#### 3、申请大小的限制
（1）栈：在Windows下，栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统预先规定好的，在WINDOWS下，栈的大小是1M（可修改），如果申请的空间超过栈的剩余空间时，将提示overflow。因此，能从栈获得的空间较小。
（2）堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。
#### 4、申请效率的比较
（1）栈由系统自动分配，速度较快。但程序员是无法控制的。
（2）堆是由new分配的内存，一般速度比较慢，而且容易产生内存碎片，不过用起来最方便。另外，在WINDOWS下，最好的方式是用VirtualAlloc分配内存，他不是在堆，也不是在栈是直接在进程的地址空间中保留一块内存，虽然用起来最不方便。但是速度快，也最灵活。
#### 5、栈和堆中的存储内容
（1）栈：在函数调用时，第一个进栈的是主函数中后的下一条指令（函数调用语句的下一条可执行语句）的地址，然后是函数的各个参数，在大多数的C编译器中，参数是由右往左入栈的，然后是函数中的局部变量。注意静态变量是不入栈的。当本次函数调用结束后，局部变量先出栈，然后是参数，最后栈顶指针指向最开始存的地址，也就是主函数中的下一条指令，程序由该点继续运行。
（2）堆：一般是在堆的头部用一个字节存放堆的大小。堆中的具体内容由程序员安排。

**总结**：堆和栈相比，由于大量new/delete的使用，容易造成大量的内存碎片；并且可能引发用户态和核心态的切换，内存的申请，代价变得更加昂贵。所以栈在程序中是应用最广泛的，就算是函数的调用也利用栈去完成，函数调用过程中的参数，返回地址，ebp和局部变 量都采用栈的方式存放。所以，推荐大家尽量用栈，而不是用堆。虽然栈有如此众多的好处，但是向堆申请内存更加灵活，有时候分配大量的内存空间，还是用堆好一些。

### 3.3 常见的内存错误及其对策
1. 内存分配未成功，却使用了它，因为没有意识到内存分配会不成功。
  解决办法：在使用内存之前检查指针是否为NULL。如果指针p是函数的参数，那么在函数的入口处用assert(p!=NULL)进行检查。如果是用malloc或new来申请内存，应该用if(p==NULL) 或if(p!=NULL)进行防错处理。

2. 内存分配虽然成功，但是尚未初始化就引用它。犯这种错误主要有两个起因：一是没有初始化的观念；二是误以为内存的缺省初值全为零，导致引用初值错误（例如数组）。
  解决方法：不要忘记为数组和动态内存赋初值，即便是赋零值也不可省略。防止将未被初始化的内存作为右值使用。

3. 内存分配成功并且已经初始化，但操作越过了内存的边界。例如在使用数组时经常发生下标“多1”或者“少1”的操作。特别是在for循环语句中，循环次数很容易搞错，导致数组操作越界。
  解决方法：避免数组或指针的下标越界，特别要当心发生“多1”或者“少1”操作。

4. 忘记了释放内存，造成内存泄露。含有这种错误的函数每被调用一次就丢失一块内存。刚开始时系统的内存充足，你看不到错误。终有一次程序突然死掉，系统出现提示：内存耗尽。
  解决方法：动态内存的申请与释放必须配对，程序中malloc与free的使用次数一定要相同，否则肯定有错误（new/delete同理）。

5. 释放了内存却继续使用它。有三种情况：（1）程序中的对象调用关系过于复杂，实在难以搞清楚某个对象究竟是否已经释放了内存，此时应该重新设计数据结构，从根本上解决对象管理的混乱局面。（2）函数的return语句写错了，注意不要返回指向“栈内存”的“指针”或者“引用”，因为该内存在函数体结束时被自动销毁。（3）使用free或delete释放了内存后，没有将指针设置为NULL。导致产生“野指针”。
  解决方法：用free或delete释放了内存之后，立即将指针设置为NULL，防止产生“野指针”。

### 3.4 智能指针
智能指针是在 <memory> 标头文件中的std命名空间中定义的，该指针用于确保程序不存在内存和资源泄漏且是异常安全的。它们对RAII“获取资源即初始化”编程至关重要，RAII的主要原则是为将任何堆分配资源（如动态分配内存或系统对象句柄）的所有权提供给其析构函数包含用于删除或释放资源的代码以及任何相关清理代码的堆栈分配对象。大多数情况下，当初始化原始指针或资源句柄以指向实际资源时，会立即将指针传递给智能指针。在C++11中，定义了3种智能指针（unique_ptr、shared_ptr、weak_ptr），并删除了C++98中的auto_ptr。

智能指针的设计思想：**将基本类型指针封装为类对象指针（这个类肯定是个模板，以适应不同基本类型的需求），并在析构函数里编写delete语句删除指针指向的内存空间。**

unique_ptr 只允许基础指针的一个所有者。unique_ptr小巧高效；大小等同于一个指针且支持rvalue引用，从而可实现快速插入和对STL集合的检索。

shared_ptr采用引用计数的智能指针，主要用于要将一个原始指针分配给多个所有者（例如，从容器返回了指针副本又想保留原始指针时）的情况。当所有的shared_ptr所有者超出了范围或放弃所有权，才会删除原始指针。大小为两个指针；一个用于对象，另一个用于包含引用计数的共享控制块。最安全的分配和使用动态内存的方法是调用make_shared标准库函数，此函数在动态分配内存中分配一个对象并初始化它，返回对象的shared_ptr。

智能指针支持的操作
- 使用重载的`->`和`*`运算符访问对象。
- 使用get成员函数获取原始指针，提供对原始指针的直接访问。你可以使用智能指针管理你自己的代码中的内存，还能将原始指针传递给不支持智能指针的代码。
- 使用删除器定义自己的释放操作。
- 使用release成员函数的作用是放弃智能指针对指针的控制权，将智能指针置空，并返回原始指针。（只支持unique_ptr）
- 使用reset释放智能指针对对象的所有权。

智能指针的使用示例：
```C++
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class base
{
public:
    base(int _a): a(_a) {cout<<"构造函数"<<endl;}
    ~base() {cout<<"析构函数"<<endl;}
    int a;
};

int main()
{
    unique_ptr<base> up1(new base(2));
    // unique_ptr<base> up2 = up1;   //编译器提示未定义
    unique_ptr<base> up2 = move(up1);  //转移对象的所有权 
    // cout<<up1->a<<endl; //运行时错误 
    cout<<up2->a<<endl; //通过解引用运算符获取封装的原始指针 
    up2.reset(); // 显式释放内存 
    
    shared_ptr<base> sp1(new base(3));
    shared_ptr<base> sp2 = sp1;  //增加引用计数 
    cout<<"共享智能指针的数量："<<sp2.use_count()<<endl;  //2
    sp1.reset();  //
    cout<<"共享智能指针的数量："<<sp2.use_count()<<endl;  //1
    cout<<sp2->a<<endl; 
    auto sp3 = make_shared<base>(4);//利用make_shared函数动态分配内存 
}
```

## 4. C++对象内存模型
在C++中有两种类的数据成员：static和nonstatic，以及三种类的成员函数：static、nonstatic和virtual。在C++对象模型中，非静态数据成员被配置于每一个类的对象之中，静态数据成员则被存放在所有的类对象之外；静态及非静态成员函数也被放在类对象之外，虚函数则通过以下两个步骤支持：
1. 每一个类产生出一堆指向虚函数的指针，放在表格之中，这个表格被称为虚函数表（virtual table, vtbl）。
2. 每一个类对象被添加了一个指针，指向相关的虚函数表，通常这个指针被称为vptr。vptr的设定和重置都由每一个类的构造函数、析构函数和拷贝赋值运算符自动完成。另外，虚函数表地址的前面设置了一个指向type_info的指针，RTTI（Run Time Type Identification）运行时类型识别是由编译器在编译器生成的特殊类型信息，包括对象继承关系，对象本身的描述，RTTI是为多态而生成的信息，所以只有具有虚函数的对象在会生成。

### 4.1 继承下的对象内存模型
C++支持单一继承、多重继承和虚继承。在虚继承的情况下，虚基类不管在继承链中被派生多少次，永远只会存在一个实体。

单一继承，继承关系为`class Derived : public Base`。其对象的内存布局为：虚函数表指针、Base类的非static成员变量、Derived类的非static成员变量。

多重继承，继承关系为`class Derived : public Base1, public Base2`。其对象的内存布局为：基类Base1子对象和基类Base2子对象及Derived类的非static成员变量组成。基类子对象包括其虚函数表指针和其非static的成员变量。

重复继承，继承关系如下。Derived类的对象的内存布局与多继承相似，但是可以看到基类Base的子对象在Derived类的对象的内存中存在一份拷贝。这样直接使用Derived中基类Base的相关成员时，就会引发歧义，可使用多重虚拟继承消除之。
```c++
class Base1 : public Base
class Base2:  public Base
class Derived : public Base1, public Base2
```

虚继承，继承关系如下。其对象的内存布局与重复继承的类的对象的内存分布类似，但是基类Base的子对象没有拷贝一份，在对象的内存中仅存在在一个Base类的子对象。但是它的非static成员变量放置在对象的末尾处。
```c++
class Base1 : virtual public Base
class Base2:  virtual public Base
class Derived : public Base1, public Base2
```
![](http://i.imgur.com/MOJIXOz.png)

## 5. 常见的设计模式
### 5.1 单例模式
当仅允许类的一个实例在应用中被创建的时候，我们使用单例模式（Singleton Pattern）。它保护类的创建过程来确保只有一个实例被创建，它通过设置类的构造方法为私有（private）来实现。要获得类的实例，单例类可以提供一个方法，如GetInstance()，来返回类的实例。该方法是唯一可以访问类来创建实例的方法。

**优点**：（1）由于单例模式在内存中只有一个实例，减少了内存开支，特别是**一个对象需要频繁地创建、销毁**时，而且创建或销毁时性能又无法优化，单例模式的优势就非常明显。（2）减少了系统的性能开销，当**一个对象的产生需要比较多的资源**时，如读取配置、产生其他依赖对象时，则可以通过在应用启动时直接产生一个单例对象，然后永久驻留内存的方式来解决。（3）避免对资源的多重占用。如避免对同一个资源文件的同时写操作。（4）单例模式可以在系统设置全局的访问点，优化和共享资源访问。

**缺点**：单例模式一般没有接口，扩展困难。不利于测试。

**使用场景**：（1）在整个项目中需要一个共享访问点或共享数据。（2）创建一个对象需要消耗的资源过多，如要访问IO和数据库等资源。（3）需要定义大量的静态常量和静态方法的环境。

实现：懒汉实现与饿汉实现
**懒汉实现**，即实例化在对象首次被访问时进行。可以使用类的私有静态指针变量指向类的唯一实例，并用一个公有的静态方法获取该实例。同时需将默认构造函数声明为private，防止用户调用默认构造函数创建对象。
```C++
//Singleton.h
class Singleton
{
public:
    static Singleton* GetInstance();
private:
    Singleton() {}
    static Singleton *m_pInstance;
};
//Singleton.cpp
Singleton* Singleton::m_pInstance = NULL;
Singleton* Singleton::GetInstance()
{
    if (m_Instance == NULL)
    {
        Lock();
        if (m_Instance == NULL)
        {
            m_Instance = new Singleton();
        }
        UnLock(); 
    }
    return m_pInstance;
}
```

该类有以下特征：
1. 它的构造函数是私有的，这样就不能从别处创建该类的实例。
2. 它有一个唯一实例的静态指针m_pInstance，且是私有的。
3. 它有一个公有的函数，可以获取这个唯一的实例，并在需要的时候创建该实例。

此处进行了两次m_Instance == NULL的判断，是借鉴了Java的单例模式实现时，使用的所谓的“双检锁”机制。因为进行一次加锁和解锁是需要付出对应的代价的，而进行两次判断，就可以避免多次加锁与解锁操作，同时也保证了线程安全。

上面的实现存在一个问题，就是没有提供删除对象的方法。一个妥善的方法是让这个类自己知道在合适的时候把自己删除。程序在结束的时候，系统会自动析构所有的全局变量。事实上，系统也会析构所有的类的静态成员变量，就像这些静态成员也是全局变量一样。利用这个特征，我们可以在单例类中定义一个这样的静态成员变量，而它的唯一工作就是在析构函数中删除单例类的实例。如下面的代码中的CGarbo类（Garbo意为垃圾工人）：
```C++
class Singleton
{
public:
    static Singleton* GetInstance() {}
private:
    Singleton() {};
    static Singleton *m_pInstance;
    //CGarbo类的唯一工作就是在析构函数中删除CSingleton的实例
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (Singleton::m_pInstance != NULL)
                delete Singleton::m_pInstance;
        }
    };
    //定义一个静态成员，在程序结束时，系统会调用它的析构函数
    static CGarbo Garbo;
};
```
类CGarbo被定义为Singleton的私有内嵌类，以防该类被在其他地方滥用。程序运行结束时，系统会调用Singleton的静态成员Garbo的析构函数，该析构函数会删除单例的唯一实例。

**饿汉实现方法**：在程序开始时就自行创建实例。如果说懒汉实现是“时间换空间”，那么饿汉实现就是“空间换时间”，因为一开始就创建了实例，所以每次用到的之后直接返回就好了。
```C++
//Singleton.h
class Singleton
{
public:
    static Singleton* GetInstance();
private:
    Singleton() {}
    static Singleton *m_pInstance;
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if (Singleton::m_pInstance != NULL)
                delete Singleton::m_pInstance;
        }
    };
    static CGarbo garbo;
};
//Singleton.cpp
Singleton* Singleton::m_pInstance = new Singleton();
Singleton* Singleton::GetInstance()
{
    return m_pInstance;
}
```

### 5.2 简单工厂模式
简单工厂模式的主要特点是需要在工厂类中做判断，从而创造相应的产品。当增加新的产品时，就需要修改工厂类。
![](http://i.imgur.com/LYiicHO.png)

**例子**：有一家生产处理器核的厂家，它只有一个工厂，能够生产两种型号的处理器核。客户需要什么样的处理器核，一定要显式地告诉生产工厂。
```C++
enum CTYPE {COREA, COREB};
class SingleCore
{
public:
    virtual void Show() = 0;
};
//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout<<"SingleCore A"<<endl; }
};
//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show() { cout<<"SingleCore B"<<endl; }
};
//唯一的工厂，可以生产两种型号的处理器核，在内部判断
class Factory
{
public:
    SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if (ctype == COREA) //工厂内部判断
            return new SingleCoreA();  //生产核A
        else if (ctype == COREB)
            return new SingleCoreB();  //生产核B
        else
            return NULL;
    }
};
```
这样设计的主要缺点之前也提到过，就是要增加新的核类型时，就需要修改工厂类。这就违反了开放封闭原则：软件实体（类、模块、函数）可以扩展，但是不可修改。于是，工厂方法模式出现了。

### 5.3 工厂方法模式
工厂方法模式是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法模式使一个类的实例化延迟到其子类。
![](http://i.imgur.com/8eiZwAg.png)

**例子**：这家生产处理器核的厂家赚了不少钱，于是决定再开设一个工厂专门用来生产B型号的单核，而原来的工厂专门用来生产A型号的单核。这时，客户要做的是找好工厂，比如要A型号的核，就找A工厂要；否则找B工厂要，不再需要告诉工厂具体要什么型号的处理器核了。
```C++
class SingleCore
{
public:
    virtual void Show() = 0;
};
//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout<<"SingleCore A"<<endl; }
};
//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show() { cout<<"SingleCore B"<<endl; }
};
class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};
//生产A核的工厂
class FactoryA: public Factory
{
public:
    SingleCoreA* CreateSingleCore() { return new SingleCoreA(); }
};
//生产B核的工厂
class FactoryB: public Factory
{
public:
    SingleCoreB* CreateSingleCore() { return new SingleCoreB(); }
};
```
工厂方法模式也有缺点，每增加一种产品，就需要增加一个对象的工厂。如果这家公司发展迅速，推出了很多新的处理器核，那么就要开设相应的新工厂。在C++实现中，就是要定义一个个的工厂类。显然，相比简单工厂模式，工厂方法模式需要更多的类定义。

### 5.4 抽象工厂模式
抽象工厂模式的定义为提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
![](http://i.imgur.com/ZzgNtzX.png)

**例子**：这家公司的技术不断进步，不仅可以生产单核处理器，也能生产多核处理器。现在简单工厂模式和工厂方法模式都鞭长莫及。这家公司还是开设两个工厂，一个专门用来生产A型号的单核多核处理器，而另一个工厂专门用来生产B型号的单核多核处理器。
```C++
//单核
class SingleCore
{
public:
    virtual void Show() = 0;
};
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout<<"Single Core A"<<endl; }
};
class SingleCoreB :public SingleCore
{
public:
    void Show() { cout<<"Single Core B"<<endl; }
};
//多核
class MultiCore
{
public:
    virtual void Show() = 0;
};
class MultiCoreA : public MultiCore
{
public:
    void Show() { cout<<"Multi Core A"<<endl; }
};
class MultiCoreB : public MultiCore
{
public:
    void Show() { cout<<"Multi Core B"<<endl; }
};
//工厂
class CoreFactory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
    virtual MultiCore* CreateMultiCore() = 0;
};
//工厂A，专门用来生产A型号的处理器
class FactoryA :public CoreFactory
{
public:
    SingleCore* CreateSingleCore() { return new SingleCoreA(); }
    MultiCore* CreateMultiCore() { return new MultiCoreA(); }
};
//工厂B，专门用来生产B型号的处理器
class FactoryB : public CoreFactory
{
public:
    SingleCore* CreateSingleCore() { return new SingleCoreB(); }
    MultiCore* CreateMultiCore() { return new MultiCoreB(); }
};
```

## 6. 深入理解C++11
