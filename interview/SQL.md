
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


### SQL数据库面试题以及答案（50例题）
```SQL
Student(Sid,Sname,Sage,Ssex)学生表
Sid：学号
Sname：学生姓名
Sage：学生年龄
Ssex：学生性别
Course(Cid,Cname,T#)课程表
Cid：课程编号
Cname：课程名称
Tid：教师编号
SC(Sid,Cid,score)成绩表
Sid：学号
Cid：课程编号
score：成绩
Teacher(Tid,Tname)教师表
Tid：教师编号：
Tname：教师名字


问题：

1、查询“001”课程比“002”课程成绩高的所有学生的学号

select a.sid from 
(select sid,score from sc where cid='001')a,
(select sid,score from sc where cid='002')b 
where a.sid = b.sid and a.score>b.score;

2、查询平均成绩大于60分的同学的学号和平均成绩

select sid,avg(score) from sc
group by sid 
having avg(score)>60;

3、查询所有同学的学号、姓名、选课数、总成绩

select s.sid,s.sname,count_cid as 选课数, 
sum_score  as 总成绩
from student s
left join 
(select sid,count(cid) as count_cid,sum(score) as sum_score 
from sc group by sid )sc
on s.sid = sc.sid;

4、查询姓‘李’的老师的个数：

select count(tname)
from teacher 
where tname like '李%';

5、查询没有学过“叶平”老师可的同学的学号、姓名：

select s.sid,s.sname 
from student as s 
where s.sid not in (
    select DISTINCT sid 
    from sc as sc 
    where sc.cid in (
        select cid 
        from course as c 
        left join teacher as t on c.tid = t.tid 
        where t.tname = '叶平')
);


6、查询学过“叶平”老师所教的所有课的同学的学号、姓名：
select s.sid,s.sname 
from student as s 
where s.sid in (
    select distinct sc.sid 
  from sc as sc 
  where sc.cid in (
    select cid 
    from course as c 
    left join teacher as t on c.tid = t.tid 
    where t.tname = '叶平')
        group by sc.sid 
    HAVING count(cid)=
    (select count(cid) 
     from course as c left join teacher as t on c.tid = t.tid 
     where t.tname = '叶平')
);


7、查询学过“001”并且也学过编号“002”课程的同学的学号、姓名：
SELECT s.sid,s.sname 
from student as s 
left join sc as sc on s.sid = sc.sid
where sc.cid = '001'
and EXISTS(
  select * from sc as sc_2 
  where sc.sid = sc_2.sid 
  and sc_2.cid='002');

select s.sid,s.sname
from student as s 
left join sc as sc 
on sc.sid = s.sid
where sc.cid = '001'
and s.sid in (
  select sid from sc as sc_2 
  where sc_2.cid='002' 
  and sc_2.sid = sc.sid);


8、查询课程编号“002”的成绩比课程编号“001”课程低的所有同学的学号、姓名：
select sid,sname
from (select student.sid,student.sname,score,
     (select score from sc as sc_2 
      where sc_2.sid = student.sid 
      and sc_2.cid = '002') as score2 
      from student,sc 
      where student.sid=sc.sid and cid = '001') s_2
where score2<score;


9、查询所有课程成绩小于60的同学的学号、姓名：
select sid,sname
from student
where sid not in 
(select s.sid 
from student s,sc 
where s.sid=sc.sid and score>60 );

select sid,sname
from student s
where not EXISTS (
select s.sid from sc 
where sc.sid = s.sid and sc.score>60);


10、查询没有学全所有课的同学的学号、姓名：
select s.sid,s.sname
from student s ,sc sc 
where s.sid = sc.sid
group by s.sid,s.sname
having count(sc.cid)<(
select count(cid) 
from course);

select s.sid,s.sname
from student s 
right join sc sc on s.sid = sc.sid
group by s.sid,s.sname
having count(sc.cid)<
(select count(cid) from course);


11、查询至少有一门课与学号为“1001”同学所学相同的同学的学号和姓名：
select student.sid,sname
from student,sc 
where student.sid = sc.sid
and cid in 
(select cid from sc where sid='1001');

select s.sid,s.sname
from sc sc left join student as s
on sc.sid = s.sid
where sc.cid in (select cid from sc where sid='1001');

select sc_1.sid,s.sname
from sc sc_1 left join student as s
on sc_1.sid = s.sid
where 
exists (select sc_2.cid from sc as sc_2 
where sc_1.cid = sc_2.cid 
and sc_2.sid = '1001');


12、查询至少学过学号为“001”同学所有一门课的其他同学学号和姓名；

13、把“SC”表中“叶平”老师教的课的成绩都更改为此课程的平均成绩：

update sc set score = 
(select avg(sc_2.score) from sc sc_2  
where sc_2.cid = sc.cid)
where cid in 
(select c.cid from course c 
left join teacher t on t.tid = c.tid 
where t.tname = '叶平');

14、查询和“1002”号的同学学习的课程完全相同的其他同学学号和姓名：

select sc_1.sid 
from (select cid from sc where sid='1002')a
left join sc sc_1 on a.cid = sc_1.cid
where sc_1.sid<>'1002' 
group by sc_1.sid 
having count(sc_1.cid) = 
(select count(cid) from sc where sid='1002');

select a.sid,s.sname from 
(select sid,GROUP_CONCAT(cid order by cid separator ',') as cid_str 
from sc where sid='1002')b,
(select sid,GROUP_CONCAT(cid order by cid separator ',') as cid_str 
from sc group by sid)a
left join student s 
on a.sid = s.sid
where a.cid_str = b.cid_str and a.sid<>'1002';

15、删除学习“叶平”老师课的SC表记录：

delete from sc WHERE
cid in (
select c.cid from course c 
LEFT JOIN teacher t on c.tid=t.tid 
where t.tname = '叶平');

16、向SC表中插入一些记录，这些记录要求符合以下条件：没有上过编号“003”课程的同学学号、002号课的平均成绩：

insert into sc select sid,'002',
(select avg(score) from sc where cid='0022')
from student 
where sid not in (select sid from sc where cid='002');

17、按平均成绩从高到低显示所有学生的“数据库”、“企业管理”、“英语”三门的课程成绩，按如下形式显示：学生ID，数据库，企业管理，英语，有效课程数，有效平均分：

select sid as 学生id,
(SELECT score from sc 
where sc.sid = t.sid and cid='004') as 数据库,
(select score from sc 
where sc.sid = t.sid and cid='001') as 企业管理,
(select score from sc 
where sc.sid = t.sid and cid='015') as 英语,
count(cid) as 有效课程数, avg(t.score) as 平均成绩
from sc as t 
group by sid
order by avg(t.score);

18、查询各科成绩最高和最低的分：以如下的形式显示：课程ID，最高分，最低分

select l.cid as 课程id,l.score as 最高分,
r.score as 最低分
from sc l,sc r
where l.cid = r.cid
and l.score = 
(select max(t.score) from sc t 
where l.cid = t.cid group by t.cid)
and r.score = (select min(t.score) from sc t 
where r.cid = t.cid group by t.cid)
order by l.cid;

select cid as 课程id,max(score) as 最高分,
min(score) as 最低分
from sc 
group by cid;

19、按各科平均成绩从低到高和及格率的百分数从高到低顺序：

SELECT t.cid as 课程号,
c.cname as 课程名,
COALESCE(avg(score),0) as 平均成绩,
100*sum(case 
when COALESCE(score,0)>=60 
then 1 else 0 END)/count(*) as 及格百分数
from sc t
left join course c 
on t.cid = c.cid
group by t.cid
order by 100*sum(case 
when COALESCE(score,0)>=60 
then 1 else 0 END)/count(*);

20、查询如下课程平均成绩和及格率的百分数(用”1行”显示): 企业管理（001），马克思（002），OO&UML （003），数据库（004）：

21、查询不同老师所教不同课程平均分从高到低显示：

select t.tid as 教师id,
t.tname as 教师姓名,
sc.cid as 课程id,
avg(score) as 平均成绩
from sc as sc
LEFT JOIN course c on sc.cid = c.cid
left join teacher t on c.tid = t.tid
group by sc.cid 
order by avg(sc.score) desc;123456789

22、查询如下课程成绩第3名到第6名的学生成绩单：企业管理(001)，马克思(002)，UML(003)，数据库(004)：

23、统计下列各科成绩，各分数段人数：课程ID，课程名称，[100-85],[85-70],[70-60],[ 小于60] ：

select sc.cid as 课程id,cname as 课程名称,
sum(case when score between 85 and 100 then 1 else 0 end) as '[100-85]',
sum(case when score between 70 and 85 then 1 else 0 end) as '[85-70]',
sum(case when score between 60 and 70 then 1 else 0 end) as '[70-60]',
sum(case when score<60 then 1 else 0 end) as '[60-0]'
from sc as sc 
left join course as c
on sc.cid = c.cid
group by sc.cid;

24、查询学生平均成绩及其名次：

select 1+(select count(distinct 平均成绩) 
from (select sid,avg(score) as 平均成绩 
from sc group by sid)t1 
where 平均成绩>t2.平均成绩) as 名次,
sid as 学生学号,平均成绩 
from (select sid,avg(score) 平均成绩 from sc group by sid) as t2
order by 平均成绩 desc;

25、查询各科成绩前三名的记录（不考虑成绩并列情况）：

select sid,cid,score
from sc sc_1
where (
select count(3) from sc sc_2 
where sc_1.cid = sc_2.cid 
and sc_2.score>=sc_1.score)<=2 
order by sc_1.cid
);

26、查询每门课程被选修的学生数：

select cid, count(sid)
from sc 
group by cid;

27、查询出只选修一门课程的全部学生的学号和姓名：

select sc.sid,s.sname,
count(sc.cid) as 课程数
from sc as sc
LEFT JOIN student as s
on sc.sid = s.sid
group by sc.sid
having count(sc.cid)=1;

28、查询男生、女生人数：

select count(ssex) as 男生人数
from student
group by ssex
having ssex = '男';
select count(2) from student
where ssex = '女';

29、查询姓“张”的学生名单：

select sid,sname
from student 
where sname like '张%';

30、查询同名同姓的学生名单，并统计同名人数：

select sname,count(8)
from student 
group by sname
having count(8)>1;

31、1981年出生的学生名单（注：student表中sage列的类型是datetime）:

32、查询平均成绩大于85的所有学生的学号、姓名和平均成绩：

select s.sname,sc.sid,avg(sc.score) as 平均成绩
from sc as sc
left join student as s 
on sc.sid = s.sid
group by sc.sid 
having avg(sc.score)>85;

33、查询每门课程的平均成绩，结果按平均成绩升序排序，平均成绩相同时，按课程号降序排列：

select cid,avg(score)
from sc 
group by cid
order by avg(score),cid desc;

34、查询课程名称为“数据库”，且分数低于60的学生名字和分数：

select c.cname,s.sid,s.sname,sc.score
from course c
left join sc on sc.cid = c.cid
LEFT JOIN student s on s.sid = sc.sid
where c.cname = '数据库' and sc.score<60;

35、查询所有学生的选课情况：

select sc.sid,sc.cid,s.sname,c.cname
from sc 
LEFT JOIN course c on sc.cid = c.cid
left join student s on sc.sid = s.sid;

36、查询任何一门课程成绩在70分以上的姓名、课程名称和分数：

select distinct s.sid,s.sname,sc.cid,sc.score
from sc 
left join student s on sc.sid = s.sid
left join course c on sc.cid = c.cid
where sc.score>70;

37、查询不及格的课程，并按课程号从大到小的排列：

select cid
from sc 
where score<60
ORDER BY cid;

38、查询课程编号为“003”且课程成绩在80分以上的学生的学号和姓名：

select sc.sid,s.sname 
from sc 
left join student s on sc.sid = s.sid
where sc.cid = '003' and sc.score>80;

39、求选了课程的学生人数：

select count(2) from 
(select distinct sid from sc)a;

40、查询选修“叶平”老师所授课程的学生中，成绩最高的学生姓名及其成绩：

select s.sname,sc.score
from sc sc 
left join student s on sc.sid = s.sid
left join course c on sc.cid = c.cid
left join teacher t on c.tid = t.tid
where t.tname = '叶平'
and sc.score = (
select max(score) 
from sc sc_1 
where sc.cid = sc_1.cid);

41、查询各个课程及相应的选修人数：

select cid,count(*) from sc group by cid;1

42、查询不同课程成绩相同的学生和学号、课程号、学生成绩：

select DISTINCT a.sid,a.cid,a.score
from sc as a ,sc as b 
where a.score = b.score
and a.cid <> b.cid;

43、查询每门课程成绩最好的前两名：

44、统计每门课程的学生选修人数(超过10人的课程才统计)。要求输出课程号和选修人数，查询结果按人数降序排序，若人数相同，按课程号升序排序：

select cid as 课程号,count(8) as 选修人数
from sc
group by cid
HAVING count(sid)>10
order by count(8) desc,cid;

45、检索至少选修两门课程的学生学号：

select sid
from sc
group by sid
having count(8)>=2;

46、查询全部学生选修的课程和课程号和课程名：

select cid,cname
from course 
where cid in (select cid from sc group by cid);

47、查询没学过”叶平”老师讲授的任一门课程的学生姓名：

select sname 
from student 
where sid not in (
    select sid 
    from sc,course,teacher 
    where course.tid = teacher.tid and sc.cid = course.cid 
    and teacher.tname='叶平'
);

48、查询两门以上不及格课程的同学的学号以及其平均成绩：

select sid,avg(COALESCE(score,0))
from sc
where sid in (
    select sid 
    from sc 
    where score<60 
    group by sid 
    having count(8)>2
)
group by sid;

49、检索“004”课程分数小于60，按分数降序排列的同学学号：

select sid,score
from sc
where cid='004'
and score<60
order by score desc;

50、删除“002”同学的“001”课程的成绩：

delete from sc
where sid = '002'
and cid = '001';

```


### Reference list:
- https://blog.csdn.net/hundan_520520/article/details/54881208
- https://blog.csdn.net/HD243608836/article/details/80189522
- https://blog.csdn.net/u012467492/article/details/46790205
