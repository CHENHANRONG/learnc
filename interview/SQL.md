
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

```

### Reference list:
- https://blog.csdn.net/u012467492/article/details/46790205
