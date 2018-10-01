
```SQL
1.用一条SQL 语句 查询出每门课都大于80 分的学生姓名

name   kecheng   fenshu张三    语文       81张三     数学       75李四     语文       76李四     数学       90王五     语文       81王五     数学       100王五     英语       90
A: select distinct name from table where name not in (select distinct name from table where fenshu<=80)
B: select name from table group by name having min(fenshu)>80

```

### Reference list:
- https://blog.csdn.net/u012467492/article/details/46790205
