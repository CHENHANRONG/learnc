# STL学习

## 1.顺序容器
**顺序容器**是将单一类型元素聚集起来成为容器，然后根据位置来存储和访问这些元素。标准库常用顺序容器如下：
- vector，可变大小数组。支持快速随机访问，在尾部之外的位置插入或删除元可能很慢。
- deque，双端队列。支持快速随机访问，在头尾部插入速度很快。
- list，双向链表。只支持双向顺序访问，在list中任何位置插入删除都很快。
- forward_list，单向链表。只支持单向顺序访问，在链表任何位置插入删除都很快。

容器只定义了少量操作，大多数额外操作则有算法库提供。容器类型的操作集合具有以下层次结构特点：一些操作适用于所有容器类型；另外一些操作则只适用于顺序或关联容器类型；还有一些操作只适用于顺序或关联容器类型的一个子集。

### 1.1 顺序容器定义与初始化
所有的容器都是类模版，要定义某种特殊的容器，必须在容器后的尖括号内提供存放元素的数据类型。容器元素类型必须满足以下两个约束：元素类型必须支持赋值运算；元素类型的对象必须可以复制。所有容器类型都定义了默认构造函数，用于创建指定类型的空容器对象。除了默认构造函数，容器类型还提供其他的构造函数，使程序员可以指定元素初值。**在C++11中，我们可以对容器进行列表初始化。**
```C++
vector<string> svec;  //默认构造函数
vector<string> svec2(svec);  //将一个容器复制给另一个容器时，类型必须匹配
list<string> slist(svec.begin(), svec.end());   //初始化为一段元素的副本

const list<int>::size_type list_size = 64; 
list<string> slist(list_size, "eh");  //分配和初始化指定数目的元素

list<string> authors = {"Qin","Li"};  //C++11列表初始化
```

### 1.2 顺序容器的常用操作
#### 1.2.1 添加元素

![添加元素的方法.png](http://upload-images.jianshu.io/upload_images/53611-7530a110b1b41226.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```C++
vector<string> container;
string text_word; 
while (cin >> text_word) 
     container.push_back(text_word); 

list<int> ilist; 
for (size_t ix = 0; ix != 4; ++ix) 
     ilist.push_front(ix); 
```

任何insert或push操作都可能导致迭代器失效。当编写循环将元素插入到vector或deque容器中时，程序必须确保迭代器在每次循环后都得到更新。为了避免存储end迭代器，可以在每次做完插入运算后重新计算end迭代器值：
```c++
vector<int>::iterator first = v.begin();//不要令last = v.end();
while (first != v.end()) 
{ 
     first = v.insert(first, 42); // insert new value 
     ++first; // advance first just past the element we added 
} 
```
#### 1.2.2 添加元素
![添加元素的方法.png](http://upload-images.jianshu.io/upload_images/53611-7530a110b1b41226.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```C++
vector<string> container;
string text_word; 
while (cin >> text_word) 
     container.push_back(text_word); 

list<int> ilist; 
for (size_t ix = 0; ix != 4; ++ix) 
     ilist.push_front(ix); 
```

任何 insert 或 push 操作都可能导致迭代器失效。当编写循环将元素插入到 vector 或 deque 容器中时，程序必须确保迭代器在每次循环后都得到更新。为了避免存储 end 迭代器，可以在每次做完插入运算后重新计算 end 迭代器值：
```c++
vector<int>::iterator first = v.begin();//不要令last = v.end();
while (first != v.end()) 
{ 
     first = v.insert(first, 42); // insert new value 
     ++first; // advance first just past the element we added 
} 
```

#### 1.2.3 顺序容器大小的操作
为避免每次添加元素都会执行内存分配和释放的操作，vector和string每次获取新的内存空间时，都会分配比需求更大的空间作为备用，以此减少内存分配的次数。
```C++
vector<int> c(10,2);
int a = c.size();  //返回容器c中的元素个数
bool b = c.empty();  //判断容器是否为空

c.reserve(20)  //分配至少能容纳20个元素的内存空间
c.capacity()  //返回容器可以容纳的元素个数

c.resize(15)  //
```

#### 1.2.4 删除元素
![ 删除顺序容器内元素的操作.png](http://upload-images.jianshu.io/upload_images/53611-3ec234dfe170a12a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

pop_front 和 pop_back 函数的返回值并不是删除的元素值，而是 void。要获取删除的元素值，则必须在删除元素之前调用 front 或 back 函数。 
```
while (!ilist.empty()) { 
         process(ilist.front()); // do something with the current top of ilist 
         ilist.pop_front();      // done; remove first element 
     } 
```
erase 操作不会检查它的参数，因此必须确保用作参数的迭代器或迭代器范围是有效的。通常，程序员必须在容器中找出要删除的元素后，才使用 erase 操作。寻找一个指定元素的最简单方法是使用标准库的 find 算法。
```
string searchValue("Quasimodo"); 
list<string>::iterator iter = find(slist.begin(), slist.end(), searchValue); 
if (iter != slist.end())    slist.erase(iter); 
```

### 1.3 容器适配器
标准库来提供了三种容器适配器。实际上，适配器是根据原始的容器类型所提供的操作，通过定义新的操作接口，来适应基础的容器类型。顺序容器适配器包括stack、queue和priority_queue类型。

栈的常用操作：
- empty，判断栈是否为空，为空则返回true。
- size，返回栈中元素个数。
- pop，删除栈顶元素，但不返回其值。
- top，返回栈顶元素的值。
- push，在栈顶压入新元素。

队列的常用操作：
- empty,size 同栈
- pop，删除队首元素，但不返回其值。
- push，在队尾压入一个新元素。
- front，返回队首元素。
- back，返回队尾元素。

## 2. 关联容器
关联容器支持通过键来高效地查找和读取元素，两个基本的关联容器类型是map和set。map的元素以键-值（key-value）对的形式组织：键用于元素在map中的索引，而值则表示所存储和读取的数据。set仅包含一个键，并有效地支持关于某个键是否存在的查询。map可理解为字典，set可理解为一类元素的集合。

关联容器和顺序容器的本质差别在于：关联容器通过键（key）存储和读取元素，而顺序容器则通过元素在容器中的位置顺序存储和访问元素。

set 和 map 类型的对象所包含的元素都具有不同的键，不允许为同一个键添加第二个元素。如果一个键必须对应多个实例，则需使用 multimap 或 multi set，这两种类型允许多个元素拥有相同的键。

### 2.1 pair类型
pair 包含两个数据值。在创建 pair 对象时，必须提供两个类型名：pair 对象所包含的两个数据成员各自对应的类型名字。如果在创建 pair 对象时不提供初始化式，则调用默认构造函数对其成员采用值初始化。
```
pair <string, int> word_count;
typedef pair<string, string> Author;   //利用 typedef 简化其声明
Author joyce("James", "Joyce");
```

与其他标准库类型不同，对于 pair 类，可以直接访问其数据成员：其成员都是仅有的，分别命名为 first 和 second。只需使用普通的点操作符（成员访问标志）即可访问其成员：
```
string firstBook; 
if (author.first == "James" && author.second == "Joyce") 
    firstBook = "Stephen Hero"; 
```

除了构造函数，标准库还定义了一个 make_pair 函数，由传递给它的两个实参生成一个新的 pair 对象。可如下使用该函数创建新的 pair 对象，并赋给已存在的 pair 对象：
```
pair<string, string> next_auth; 
string first, last; 
while (cin >> first >> last) { 
    next_auth = make_pair(first, last); 
} 
```

### 2.2 map类型
map 对象的元素是键－值对，也即每个元素包含两个部分：键以及由键关联的值。map 的 value_type 就反映了这个事实。该类型比前面介绍的容器所使用的元素类型要复杂得多：value_type 是存储元素的键以及值的 pair 类型，而且键为 const。例如，word_count 数组的 value_type 为 pair<const string, int> 类型。 

```
map <string,int> word_count;
word_count.insert( make_pair("James", "Joyce") );
map<string, int>::iterator map_it = word_count.begin(); 
 cout << map_it->first; 
 cout << " " << map_it->second;
```

#### 2.2.1 给map添加元素

map容器中添加键－值元素对，可使用 insert 成员实现；或者，先用下标操作符获取元素，然后给获取的元素赋值。在这两种情况下，一个给定的键只能对应于一个元素这一事实影响了这些操作的行为。

用下标操作符来获取该键所关联的值。如果该键已在容器中，则返回该键所关联的值。只有在所查找的键不存在时，map 容器才为该键创建一个新的元素，并将它插入到此 map 对象中。此时，所关联的值采用值初始化：类类型的元素用默认构造函数初始化，而内置类型的元素初始化为 0。

```
map<string, int> word_count; // empty map from string to int 
string word; 
while (cin >> word) 
    ++word_count[word]; 
```

使用下标给 map 容器添加新元素时，元素的值部分将采用值初始化。通常，我们会立即为其赋值，其实就是对同一个对象进行初始化并赋值。而插入元素的另一个方法是：直接使用 insert 成员，其语法更紧凑： 
```
word_count.insert(map<string, int>::value_type("Anna", 1)); 
word_count.insert(make_pair("Anna", 1)); 
```
map 对象中一个给定键只对应一个元素。如果试图插入的元素所对应的键已在容器中，则 insert 将不做任何操作。但是，带有一个键－值 pair 形参的 insert 版本将返回一个值：包含一个迭代器和一个 bool 值的 pair 对象，其中迭代器指向 map 中具有相应键的元素，而 bool 值则表示是否插入了该元素。如果该键已在容器中，则其关联的值保持不变，返回的 bool 值为 true。在这两种情况下，迭代器都将指向具有给定键的元素。

```
map<string, int> word_count; 
string word; 
while (cin >> word) { 
    // inserts element with key equal to word and value 1; 
    // if word already in word_count, insert does nothing 
    pair<map<string, int>::iterator, bool> ret =  
         word_count.insert(make_pair(word, 1)); 
    if (!ret.second)          // word already in word_count 
        ++ret.first->second;  // increment counter 
} 
```

#### 2.2.2 查找并读取map中的元素 

不能使用下标来查找map中的某一元素是否存在，因为如果该键不在 map 容器中，那么下标操作会插入一个具有该键的新元素。map 容器提供了两个操作：count 和 find，用于检查某个键是否存在而不会插入该键。 

对于 map 对象，count 成员的返回值只能是 0 或 1。map 容器只允许一个键对应一个实例，所以 count 可有效地表明一个键是否存在。find 操作返回指向元素的迭代器，如果元素不存在，则返回 end 迭代器。
```
int occurs = 0;
map <string, int>::iterator it = word_count.find("foobar");
if(it != wor_count.end() )
    occurs = it->second;
```

#### 2.2.3 从map对象中删除元素

![从 map 对象中删除元素](http://upload-images.jianshu.io/upload_images/53611-4385de1ebe69a34d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```
if (word_count.erase(removal_word)) 
    cout << "ok: " << removal_word << " removed\n"; 
else cout << "oops: " << removal_word << " not found!\n"; 
```

#### 2.2.4 map对象的迭代遍历

与其他容器一样，map 同样提供 begin 和 end 运算，以生成用于遍历整个容器的迭代器。例如，可如下将 map 容器 word_count 的内容输出：
```
map<string, int>::const_iterator it = word_count.begin();
while(it != word_count.end()){
    cout<< it->first <<" occurs "
            << it->second << " times " <<endl;
    ++it;
}
```

## 2.3 set类型

map 容器是键－值对的集合，好比以人名为键的地址和电话号码。相反地，set 容器只是单纯的键的集合。例如，某公司可能定义了一个名为 bad_checks 的 set 容器，用于记录曾经给本公司发空头支票的客户。当只想知道一个值是否存在时，使用 set 容器是最适合的。例如，在接收一张支票前，该公司可能想查询 bad_checks 对象，看看该客户的名字是否存在。

set 容器支持大部分的 map 操作，包括上面描述的构造函数、 insert 操作、 count 和 find 操作、 erase 操作等。但是， **不支持下标操作符**，而且没有定义 mapped_type 类型。在 set 容器中，value_type 不是 pair 类型，而是与 key_type 相同的类型。它们指的都是 set 中存储的元素类型。这一差别也体现了 set 存储的元素仅仅是键，而没有所关联的值。**与 map 一样，set 容器存储的键也必须唯一，而且不能修改**。

```
vector<int> ivec;
for( vector<int>::size_type i = 0; i !=10; ++i){
    ivec.push_back(i);
    ivec.push_back(i);
}
set<int> iset(ivec.begin(), ivec.end());
cout << ivec.size() << endl;      // prints 20 
cout << iset.size() << endl;      // prints 10 

set<string> set1;
set1.insert("the");

set<int> iset2;
iset2. insert( ivec.begin(), ivec.end() );     // iset2 has 10 elements

iset.find(1);     // returns iterator that refers to the element with key == 1
iset.find(11);   // returns iterator == iset.end() 
 iset.count(1);    // returns 1 

set<int>::iterator set_it = isec.find(1);
cout<< *set_it <<endl;
```
正如不能修改 map 中元素的键部分一样，set 中的键也为 const。在获得指向 set 中某元素的迭代器后，只能对其做读操作，而不能做写操作。

## 2.4 multimap 和 multiset 类型 

map 和 set 容器中，一个键只能对应一个实例。而 multiset 和 multimap 类型则允许一个键对应多个实例。例如，在电话簿中，每个人可能有单独的电话号码列表。在作者的文章集中，每位作者可能有单独的文章标题列表。multimap 和 multiset 类型与相应的单元素版本具有相同的头文件定义：分别是 map 和 set 头文件。

multimap 和 multiset 所支持的操作分别与 map 和 set 的操作相同，只有一个例外：multimap 不支持下标运算。不能对 multimap 对象使用下标操作，因为在这类容器中，某个键可能对应多个值。为了顺应一个键可以对应多个值这一性质，map 和 multimap，或 set 和 multiset 中相同的操作都以不同的方式做出了一定的修改。在使用 multimap 或 multiset 时，对于某个键，必须做好处理多个值的准备，而非只有单一的值。

由于键不要求是唯一的，因此每次调用 insert 总会添加一个元素。

带有一个键参数的 erase 版本将删除拥有该键的所有元素，并返回删除元素的个数。而带有一个或一对迭代器参数的版本只删除指定的元素，并返回 void 类型。

关联容器 map 和 set 的元素是按顺序存储的， multimap 和 multset 也一样。因此，在 multimap 和 multiset 容器中，如果某个键对应多个实例，则这些实例在容器中将相邻存放。 在 multimap 和 multiset 中查找元素有三种策略，而且三种策略都基于一个事实——在 multimap 中，同一个键所关联的元素必然相邻存放。

> - 使用 find 和 count 操作
- lower_bound 和 upper_bound
- enual_range 函数 

![ 返回迭代器的关联容器操作 ](http://upload-images.jianshu.io/upload_images/53611-8f1ce74c79e913d3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

equal_range 函数返回存储一对迭代器的 pair 对象。如果该值存在，则 pair 对象中的第一个迭代器指向该键关联的第一个实例，第二个迭代器指向该键关联的最后一个实例的下一位置。如果找不到匹配的元素，则 pair 对象中的两个迭代器都将指向此键应该插入的位置。

```
pair<authors_it, authors_it> pos = authors.equal_range(search_item); 
while (pos.first != pos.second) { 
    cout << pos.first->second << endl; 
    ++pos.first; 
} 
```

## 3. 常用泛型算法
标准库为容器类型定义的操作很少，并没有为每个容器实现更多的操作。因为这部分操作可以抽象出来为所有的容器工作，那就是泛型算法。所谓“泛型”是指这些算法可以应用于多种容器类型上，而容器内的元素类型也可以多样化。标准库提供了100多个泛型算法，主要定义于头文件<algorithm>中，还有一组泛化的算术算法定义于头文件<numeric>中。
 
大多数泛型算法是工作于容器的一对迭代器所标识的范围，并完全通过迭代器来实现其功能。这段由迭代器指定的范围称为“输入范围”。带有输入范围参数的算法总是使用前两个参数标记该范围，分别指向要处理的第一个元素和最后一个元素的下一个位置。

### 3.1 查找
find 和 count 算法在输入范围中查找指定值。find 算法返回引用第一个匹配元素的迭代器，count 算法返回元素在输入序列中出现次数的计数。
```C++
find(beg, end, val) 
count(beg, end, val) 
```
在输入范围中查找等于 val 的元素，使用基础类型的相等（==）操作符。find 返回第一个匹配元素的迭代器，如果不存在在匹配元素就返回 end。count 返回 val 出现次数的计数。

find函数的源码如下：
```C++
template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
	while(first != last){
		if(*first == val)	return first;
		++first;
	}
	return last;
}
```
一个例子，查找数组中的某个值。由于指针就像内置数组上的迭代器一样，因此可以用find在数组中查找值。使用begin和end函数可以获取指向数组首尾元素的指针。
```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int myints[]={ 10, 20, 30, 40 };
    int* p;
    p=find(begin(myints), end(myints), 30);
    if(p!=myints+4)
        cout<<*p<<endl;
}
```

### 3.2 排序
c++中最经常使用的算法应该就是排序算法，也就是sort函数。当然还有partial_sort以及stable_sort。sort函数排序默认是从小到大，如果想给自定义类型排序，可以重载运算符或者自定义比较函数。

升序：sort(begin,end,less<data-type>());
降序：sort(begin,end,greater<data-type>()).
```C++
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int a[10]={2,4,1,23,5,76,0,43,24,65},i;
    for(i=0;i<10;i++)   cout<<a[i]<<" ";
    cout<<endl;
    sort(a,a+10,greater<int>());
    for(i=0;i<10;i++)   cout<<a[i]<<" ";
    cout<<endl;
}
```
当然，也可以自己写比较函数
```C++
#include <iostream>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
struct Data  
{  
    char data[100];   
}str[100];  
  
bool cmp(const Data &elem1, const Data &elem2)  
{  
    if (strcmp(elem1.data, elem2.data) < 0)  
        return true;  
    return false;  
}  
  
int main()  
{  
    int n, i;  
    while (cin>>n)  
    {  
        for (i=0; i<n; ++i)  
        {  
            cin>>str[i].data;  
        }  
          
        sort(str, str+n, cmp);  
          
        for (i=0; i<n; ++i)  
            cout<<str[i].data<<endl;  
    }  
    return 0;  
}  
```

### 3.3 去重unique
unique的作用是从输入序列中**删除”所有相邻的重复元素**。该算法删除相邻的重复元素，然后重新排列输入范围内的元素，并且返回一个迭代器（容器的长度没变，只是元素顺序改变了），表示无重复的值范围的结束。
```C++
sort(words.begin(), words.end());   //排序
vector<string>::iterator end_unique =  unique(words.begin(), words.end());  //去重
words.erase(end_unique, words.end());  //删除结尾元素
```
在STL中unique函数是一个去重函数， unique的功能是去除相邻的重复元素(只保留一个),其实它并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址，因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序。

源代码如下：
```C++
template <class ForwardIterator>
ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
	if (first==last) return last;
	ForwardIterator result = first;
	while (++first != last){
		if (!(*result == *first))	*(++result)=*first;
	}
	return ++result;
}
```

### 3.4 赋值fill
fill函数可以可以向容器当中的一定范围能赋值，一共接受3个参数，类似于memset函数。
fill(beg, end, val) 

## 4. Stirng常用操作
### 4.1 通过下标操作字符串：
```C++
//交换当前字符串与s2的值
void swap(string &s2);

//删除pos开始的n个字符，返回修改后的字符串
string &erase(int pos = 0, int n = npos);

//从pos开始查找字符c在当前字符串的位置
int find(char c, int pos = 0) const;

//从pos开始查找字符串s在当前串中的位置
int find(const char *s, int pos = 0) const;

//删除从p0开始的n0个字符，然后在p0处插入串s
string &replace(int p0, int n0,const char *s);

//删除从p0开始的n0个字符，然后在p0处插入串s
string &replace(int p0, int n0,const string &s);

string &insert(int p0, const char *s);
string &insert(int p0, const char *s, int n);
string &insert(int p0,const string &s);
```
一个示例
```C++
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "asdfghjklsdsdfgh";
	cout<<s.size()<<endl;
	cout<<s.find('s')<<endl;
	cout<<s.find('s',s.find('s')+1)<<endl;
	
	//将"sd"替换成"sb"
	int i = 0;
	while(i < s.size()){
		int pos = s.find("sd",i);
		if(pos == string::npos)	break;
		s.replace(pos,2,"mb");
		cout<<s<<endl;
		i = pos + 2;
	}
	
	string s2 = s; 
	s2.erase(0,3);
	cout<<s2<<" end"<<endl; 
}
```

###4.2 通过迭代器操作字符串 
```C++
//删除[first，last）之间的所有字符，返回删除后迭代器的位置
iterator erase(iterator first, iterator last);
//删除it指向的字符，返回删除后迭代器的位置
iterator erase(iterator it);
```

## 5. 深度探索vector
### 5.1 insert的实现
在插入元素之前，需要判断vector的备用空间大小是否大于插入元素个数，如果足够则在原序列进行插入操作；如果不够，则需要重新申请内存，将原数据和新增数据移动到新内存中（先是原数据插入点之前的数据移动到新内存中，然后是待插入数据，最后移动插入点之后的数据），然后析构元内存中的对象，最后再释放原内存。
```C++
////////////////////////////////////////////////////////////////////////////////
// 在指定位置插入n个元素
////////////////////////////////////////////////////////////////////////////////
//             insert(iterator position, size_type n, const T& x)
//                                   |
//                                   |---------------- 插入元素个数是否为0?
//                                   ↓
//              -----------------------------------------
//        No    |                                       | Yes
//              |                                       |
//              |                                       ↓
//              |                                    return;
//              |----------- 内存是否足够?
//              |
//      -------------------------------------------------
//  Yes |                                               | No
//      |                                               |
//      |------ (finish - position) > n?                |
//      |       分别调整指针                              |
//      ↓                                               |
//    ----------------------------                      |
// No |                          | Yes                  |
//    |                          |                      |
//    ↓                          ↓                      |
// 插入操作, 调整指针           插入操作, 调整指针          |
//                                                      ↓
//            data_allocator::allocate(len);
//            new_finish = uninitialized_copy(start, position, new_start);
//            new_finish = uninitialized_fill_n(new_finish, n, x);
//            new_finish = uninitialized_copy(position, finish, new_finish);
//            destroy(start, finish);
//            deallocate();
////////////////////////////////////////////////////////////////////////////////

template <class T, class Alloc>
void insert(iterator position, size_type n, const T& x)
{
	// 如果n为0则不进行任何操作
	if (n != 0)
	{
		if (size_type(end_of_storage - finish) >= n)
		{      // 剩下的备用空间大于等于“新增元素的个数”
			T x_copy = x;
			// 以下计算插入点之后的现有元素个数
			const size_type elems_after = finish - position;
			iterator old_finish = finish;
			if (elems_after > n)
			{
				// 插入点之后的现有元素个数 大于 新增元素个数
				uninitialized_copy(finish - n, finish, finish);
				finish += n;    // 将vector 尾端标记后移
				copy_backward(position, old_finish - n, old_finish);
				fill(position, position + n, x_copy); // 从插入点开始填入新值
			}
			else
			{
				// 插入点之后的现有元素个数 小于等于 新增元素个数
				uninitialized_fill_n(finish, n - elems_after, x_copy);
				finish += n - elems_after;
				uninitialized_copy(position, old_finish, finish);
				finish += elems_after;
				fill(position, old_finish, x_copy);
			}
		}
		else
		{   // 剩下的备用空间小于“新增元素个数”（那就必须配置额外的内存）
			// 首先决定新长度：就长度的两倍 ， 或旧长度+新增元素个数
			const size_type old_size = size();
			const size_type len = old_size + max(old_size, n);
			// 以下配置新的vector空间
			iterator new_start = data_allocator::allocate(len);
			iterator new_finish = new_start;
			__STL_TRY
			{
				// 以下首先将旧的vector的插入点之前的元素复制到新空间
				new_finish = uninitialized_copy(start, position, new_start);
				// 以下再将新增元素（初值皆为n）填入新空间
				new_finish = uninitialized_fill_n(new_finish, n, x);
				// 以下再将旧vector的插入点之后的元素复制到新空间
				new_finish = uninitialized_copy(position, finish, new_finish);
			}
#         ifdef  __STL_USE_EXCEPTIONS
			catch(...)
			{
				destroy(new_start, new_finish);
				data_allocator::deallocate(new_start, len);
				throw;
			}
#         endif /* __STL_USE_EXCEPTIONS */
			destroy(start, finish);
			deallocate();
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}
}
```
