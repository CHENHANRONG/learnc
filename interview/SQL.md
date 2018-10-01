
```SQL
1.用一条SQL 语句 查询出每门课都大于80 分的学生姓名

name   kecheng   fenshu
张三    语文       81
张三     数学       75
李四     语文       76
李四     数学       90
王五     语文       81
王五     数学       100
王五     英语       90

A: select distinct name from table where name not in (select distinct name from table where fenshu<=80)
B: select name from table group by name having min(fenshu)>80


2. 
学生表 如下:
自动编号   学号   姓名 课程编号 课程名称 分数
1        2005001 张三 0001     数学    69
2        2005002 李四 0001      数学    89
3        2005001 张三 0001      数学    69

删除除了自动编号不同, 其他都相同的学生冗余信息
A: delete tablename where 自动编号 not in(select min( 自动编号) from tablename group by 学号, 姓名, 课程编号, 课程名称, 分数)

```

### Reference list:
- https://blog.csdn.net/hundan_520520/article/details/54881208
- https://blog.csdn.net/HD243608836/article/details/80189522
- https://blog.csdn.net/u012467492/article/details/46790205
