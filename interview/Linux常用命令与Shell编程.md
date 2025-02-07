## Linux常用命令与Shell编程

### Linux常用命令
常用的选项：-f（force，强制）；-i（interactive，交互式）；-r（recursive，递归）；-v（verbose，详细）；-u（update，更新）

#### 1. ls指令：显示目录内容

| 选项   | 功能                                       |
| ---- | ---------------------------------------- |
| -a   | 显示包括隐藏文件（文件名以.开头的）在内的所有文件                |
| -F   | 在每个输出项后追加文件的类型标识符：`*`表示可执行文件；`/`表示目录；`@`表示符号链接；`|`表示命名管道FIFO；`=`表示sockets套接字；普通文件不输出任何标识符。 |
| -f   | 按照文件在磁盘上的存储顺序显示列表，对输出内容不行行排序。            |
| -i   | 显示文件的索引节点号（inode）。                       |
| -k   | 以KB为单位显示文件大小。                            |
| -l   | 以长格式显示目录下的内容列表。输出信息依次为文件名、文件类型、权限模式、硬链接数、所有者、组、文件大小和文件的最后修改时间等。 |
| -m   | 以水平方式显示文件（每个文件之间用`,`和空格隔开），已达到每行显示尽可能多的文件数。 |
| -t   | 按照文件的最后修改时间降序显示目录内容列表。                   |

实例：

```shell
ls -l    # 列出当前目录可见文件详细信息
ls -hl   # 列出详细信息并以可读大小显示文件大小
ls -al   # 列出所有文件（包括隐藏）的详细信息
```

#### 2. cp指令：复制文件或目录

**cp命令** 用来将一个或多个源文件或者目录复制到指定的目的文件或目录。它可以将单个源文件复制成一个指定文件名的具体的文件或一个已经存在的目录下。cp命令还支持同时复制多个文件，当一次复制多个文件时，目标文件参数必须是一个已经存在的目录，否则将出现错误。

| 选项   | 功能                                       |
| ---- | ---------------------------------------- |
| -a   | 此参数的效果和同时指定"-dpr"参数相同                    |
| -d   | 当复制符号连接时，把目标文件或目录也建立为符号连接，并指向与源文件或目录连接的原始文件或目录 |
| -f   | 当复制符号连接时，把目标文件或目录也建立为符号连接，并指向与源文件或目录连接的原始文件或目录 |
| -i   | 覆盖既有文件之前先询问用户                            |
| -p   | 保留源文件或目录的属性                              |
| -r   | 递归处理，将指定目录下的所有文件与子目录一并处理                 |
| -u   | 使用这项参数后只会在源文件的更改时间较目标文件更新时或是名称相互对应的目标文件并不存在时，才复制文件 |
| -v   | 详细显示命令执行的操作                              |

tips：**-r 是“递归”， -u 是“更新”，-v 是“详细”**

#### 3. mv命令：移动文件并改名

mv命令可以用来将源文件移至一个目标文件中，或将一组文件移至一个目标目录中。源文件被移至目标文件有两种不同的结果：

1. 如果目标文件是到某一目录文件的路径，源文件会被移到此目录下，且文件名不变。
2. 如果目标文件不是目录文件，则源文件名（只能有一个）会变为此目标文件名，并覆盖己存在的同名文件。如果源文件和目标文件在同一个目录下，mv的作用就是改文件名。当目标文件是目录文件时，源文件或目录参数可以有多个，则所有的源文件都会被移至目标文件中。所有移到该目录下的文件都将保留以前的文件名。

| 选项   | 功能                                       |
| ---- | ---------------------------------------- |
| -b   | 当文件存在时，覆盖前，为其创建一个备份                      |
| -f   | 若目标文件或目录与现有的文件或目录重复，则直接覆盖现有的文件或目录        |
| -i   | 交互式操作，覆盖前先行询问用户，如果源文件与目标文件或目标目录中的文件同名，则询问用户是否覆盖目标文件。用户输入”y”，表示将覆盖目标文件；输入”n”，表示取消对源文件的移动。这样可以避免误将文件覆盖。 |
| -u   | 当源文件比目标文件新或者目标文件不存在时，才执行移动操作。            |

实例：

```shell
mv -uv *.txt /home/office   #源文件比目标文件新时才执行更新
mv -vn *.txt /home/office   #不要覆盖任何已存在的文件
mv -bv *.txt /home/office   #复制时创建备份
```

#### 4. rm命令：删除文件或目录

使用rm命令要格外小心。因为一旦删除了一个文件，就无法再恢复它。所以，在删除文件之前，最好再看一下文件的内容，确定是否真要删除。rm命令可以用-i选项，这个选项在使用文件扩展名字符删除多个文件时特别有用。使用这个选项，系统会要求你逐一确定是否要删除。这时，必须输入y并按Enter键，才能删除文件。如果仅按Enter键或其他字符，文件不会被删除。

| 选项   | 功能                       |
| ---- | ------------------------ |
| -f   | 强制删除文件或目录                |
| -i   | 删除已有文件或目录之前先询问用户         |
| -r   | 递归处理，将指定目录下的所有文件与子目录一并处理 |
| -v   | 显示指令的详细执行过程              |

#### 5. chmod指令：改变文件访问权限



#### 6. ln指令：为文件创建链接



#### 7. whereis指令：显示指令及相关文件的路径

**whereis命令** 用来定位指令的二进制程序、源代码文件和man手册页等相关文件的路径。

whereis命令只能用于程序名的搜索，而且只搜索二进制文件（参数-b）、man说明文件（参数-m）和源代码文件（参数-s）。如果省略参数，则返回所有信息。

```shell
$ whereis ls
ls: /bin/ls /usr/share/man/man1/ls.1.gz
```

#### 8. touch指令：设置文件的时间属性

**touch命令** 有两个功能：一是用于把已存在文件的时间标签更新为系统当前的时间（默认方式），它们的数据将原封不动地保留下来；二是用来创建新的空文件。

#### 9. dirname指令：去除文件名中的非目录部分

**dirname命令** 去除文件名中的非目录部分，仅显示与目录有关的内容。dirname命令读取指定路径名保留最后一个`/`及其后面的字符，删除其他部分，并写结果到标准输出。如果最后一个`<cite>/</cite>`后无字符，dirname 命令使用倒数第二个`/`，并忽略其后的所有字符。dirname 和 basename 通常在 shell 内部命令替换使用，以指定一个与指定输入文件名略有差异的输出文件名。

**basename命令** 用于打印目录或者文件的基本名称。

```sh
$ dirname /home/theseed/test/test.cpp
/home/theseed/test
$ basename /home/theseed/test/test.cpp
test.cpp
```



#### 10. cat指令：连接文件并显示内容

cat指令用于将多个文件连接，并将结果通过标准输出显示出来。通常用于显示文本文件。

| 选项 | 功能                                       |
| ---- | ------------------------------------------ |
| -b   | 在空行前面显示行号                         |
| -n   | 显示所有行的行号，包括空行                 |
| -s   | 压缩空行，多个空行连续出现时仅显示一个空行 |
| -v   | 显示不可打印字符                           |

#### 11. grep指令：在文件中搜索匹配的行



#### 12. tail指令：输出文件尾部内容

| 选项 | 功能                                       |
| ---- | ------------------------------------------ |
| -f   | 显示文件最新追加的内容                     |
| -n   | 输出文件的尾部N行内容，默认显示10行内容    |
| -s   | 与-f连用时，指定监视文件变化时间间隔的秒数 |

`tail -f`指令可以实现实时监控文件内容的增长，适合监控日志文件的变化。

#### 3. wc指令：统计文件的字节数、单词数和行数

| 选项 | 功能                                                         |
| ---- | ------------------------------------------------------------ |
| -c   | 统计字节数                                                   |
| -m   | 统计字符数                                                   |
| -l   | 统计行数                                                     |
| -w   | 统计字数， 一个字被定义为由空白、跳格或换行字符分隔的字符串。 |

wc指令经常和管道连用，用于统计上一个指令的输出内容的字节数、单词数和行数信息。

```sh
ps -aux | grep httpd | wc -l     # 统计当前系统中httpd进程的数目
```



#### 14. sort指令：对文件进行行排序

sort指令将文件进行行排序，并将排序结果输出到标准输出设备。



#### 15. uniq指令：报告或忽略文件中的重复行



#### 16. split指令：将文件分割成碎片



#### 17. date 指令：显示与设置系统日期时间

date指令用于显示当前系统的日期时间。如果使用`-s`选项则可以设置当前的系统日期时间。通过date指令显示日期时间时，可以灵活使用date指令支持的格式字符串，定义出自己需要的日期时间格式。

```sh
date "+%Y-%m-%d %T"  #以本地格式输出当前日期时间  
date -r eg.txt   #显示文件的最后修改时间
data -s "2018-6-14 20:00:00"   #设置当前时间
```

#### 18. sleep指令：暂停指定的时间

sleep指令的时间参数默认为秒，也支持后缀，以指定时间单位。通常应用与shell脚本中，以等待指定的时间后继续执行其他指令。

```sh
sleep 1m   #暂停一分钟
```

#### 19. df指令：报告磁盘空间使用情况

df指令用于显示磁盘分区上可用的磁盘信息，默认的显示单位为KB。`-a`选项用于显示所有文件系统包括伪文件系统；`-h`指令用于以容易阅读的方式显示磁盘空间使用情况。

```sh
df -h   #显示磁盘空间使用情况
```

#### 20. mount指令：挂载文件系统

mount指令加载文件系统时，要求加载点目录必须存在且为空。如果加载点目录不为空，则加载成功后加载点原目录下的文件将不能访问，直到文件系统卸载后才可访问。

```sh
mount /dev/hda1 /mnt        #将 /dev/hda1 挂在 /mnt 之下。
mount -o ro /dev/hda1 /mnt  #将 /dev/hda1 以只读模式挂在 /mnt 之下
mount -l                    #显示所有已加载的文件系统
```

umount指令则是用于卸载文件系统。如果文件系统正在被访问，则无法使用umount进行卸载。

#### 21. sync指令：刷新文件系统缓冲区

linux系统为了提高读写磁盘的效率，会先将数据放在一块buffer中。在写磁盘时并不是立即将数据写到磁盘中，而是先写入这块buffer中了。此时如果重启系统，就可能造成数据丢失。

sync命令用来flush文件系统buffer，这样数据才会真正的写到磁盘中，并且buffer才能够释放出来，flush就是用来清空buffer。sync命令会强制将数据写入磁盘中，并释放该数据对应的buffer，所以常常会在写磁盘后输入sync命令来将数据真正的写入磁盘。

如果不去手动的输入sync命令来真正的去写磁盘，linux系统也会周期性的去sync数据。

#### 22. kill指令：终止进程

**kill命令** 用来删除执行中的程序或工作。kill可将指定的信息送至程序。预设的信息为SIGTERM(15),可将指定程序终止。若仍无法终止该程序，可使用SIGKILL(9)信息尝试强制删除程序。程序或工作的编号可利用ps指令或job指令查看。

只有第9种信号(SIGKILL)才可以无条件终止进程，其他信号进程都有权利忽略， **下面是常用的信号：**

```
HUP     1    终端断线
INT     2    中断（同 Ctrl + C）
QUIT    3    退出（同 Ctrl + \）
TERM   15    终止
KILL    9    强制终止
CONT   18    继续（与STOP相反， fg/bg命令）
STOP   19    暂停（同 Ctrl + Z）
```

pkill用于根据进程名杀死进程，使用`-P`选项可以杀死指定进程所派生的所有子进程。

killall也是按照进程名称杀死进程，但此指令可以杀意一组同名进程。

```sh
kill -9 httpd
pkill httpd    #杀死"httpd"进程
```

#### 23. ps指令：报告当前系统的进程状态

**ps命令** 用于报告当前系统的进程状态。可以搭配kill指令随时中断、删除不必要的程序。使用该命令可以确定有哪些进程正在运行和运行的状态、进程是否结束、进程有没有僵死、哪些进程占用了过多的资源等等。



#### 24. top指令：实时报告系统整体性能情况



#### 25. free指令：显示内存的使用情况



#### 26. apt-get指令：APT包管理工具



#### 27. ifconfig指令：配置网络接口



#### 28. ping指令：测试主机之间网路连通性



#### 29. netstat指令：显示网络状态




#### 30. scp指令：安全远程文件复制



#### 31. ssh指令：安全连接客户端



### 文本处理

#### 1. sed命令

sed是非交互式的编辑器。它不会修改文件，除非使用shell重定向来保存结果。默认情况下，所有的输出行都被打印到屏幕上。

sed编辑器逐行处理文件（或输入），并将结果发送到屏幕。具体过程如下：首先sed把当前正在处理的行保存在一个临时缓存区中（也称为模式空间），然后处理临时缓冲区中的行，完成后把该行发送到屏幕上。sed每处理完一行就将其从临时缓冲区删除，然后将下一行读入，进行处理和显示。处理完输入文件的最后一行后，sed便结束运行。sed把每一行都存在临时缓冲区中，对这个副本进行编辑，所以不会修改原文件。

**语法：** `sed [option]... {script} [input-file] `

**选项说明：**

- -n ：使用安静(silent)模式。在一般 sed 的用法中，所有来自 STDIN 的数据一般都会被列出到终端上。但如果加上 -n 参数后，则只有经过sed 特殊处理的那一行(或者动作)才会被列出来。
- -e ：直接在命令列模式上进行 sed 的动作编辑。
- -f ：直接将 sed 的动作写在一个文件内， -f filename 则可以运行 filename 内的 sed 动作。
- -r ：sed 的动作支持的是延伸型正规表示法的语法。(默认是基础正规表示法语法)。
- -i ：直接修改读取的文件内容，而不是输出到终端。

**动作说明：**

- a ：新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)。

- c ：取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行。

- d ：删除行。

- i  ：插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)。

- p ：打印，亦即将某个选择的数据印出。通常 p 会与参数 `sed -n` 配合使用。

- s ：取代，可以直接进行取代的工作，通常搭配正规表示法使用。

- q ：结束或退出sed。


**实例说明：**

1. 以行为单位的新增/删除

   ```sh
   # 将 /etc/passwd文件的内容列出并且列印行号，同时，请将第 2~5 行删除！
   nl /etc/passwd | sed '2,5d'

   # 删除第 3 到最后一行
   nl /etc/passwd | sed '3,$d'

   # 在第二行后(亦即是加在第三行)加上"drink tea?"
   nl /etc/passwd | sed '2a drink tea'

   # 在第二行前插入"drink tea?"
   nl /etc/passwd | sed '2i drink tea' 
   ```

2. 以行为单位的替换与显示

   ```shell
   # 将第2-5行的内容替换为"No. 2-5 rows"
   nl /etc/passwd | sed '2,5c No. 2-5 rows'

   # 仅列出 /etc/passwd 文件内的第 5-7 行
   nl /etc/passwd | sed -n '5,7p'
   ```

3. 匹配行的查找、显示与删除

   ```shell
   # 搜索 /etc/passwd 有root关键字的行
   nl /etc/passwd | sed -n '/root/p'

   # 删除/etc/passwd所有包含root的行，其他行输出
   nl /etc/passwd | sed  '/root/d'
   ```

4. 文本替换

   ```sh
   # 将/etc/passwd中所有root替换为father，并显示
   # 格式： 's/要被取代的字串/新的字串/'
   nl /etc/passwd | sed 's/root/father/'
   ```
#### 2. awk命令

awk是一个强大的文本分析工具，相对于grep的查找，sed的编辑，awk在其对数据分析并生成报告时，显得尤为强大。简单来说awk就是把文件逐行的读入，以空格为默认分隔符将每行切片，切开的部分再进行各种分析处理。awk有3个不同版本: awk、nawk和gawk，未作特别说明，一般指gawk，gawk 是 AWK 的 GNU 版本。

**使用方法1**：`awk '{pattern + action}' {filenames}`

```sh
# 以下为log.txt文件内容
# 2 this is a test
# 3 Are you like awk
# This's a test
# 10 There are orange,apple,mongo

# 每行按空格或TAB分割，输出文本中的1、4项
 $ awk '{print $1,$4}' log.txt
 ---------------------------------------------
 2 a
 3 like
 This's
 10 orange,apple,mongo
 # 格式化输出
 $ awk '{printf "%-8s %-10s\n",$1,$4}' log.txt
 ---------------------------------------------
 2        a
 3        like
 This's
 10       orange,apple,mongo
```
