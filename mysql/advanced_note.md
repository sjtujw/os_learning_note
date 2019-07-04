# mysql高阶用法
* 排序<br>
    SELECT field1, field2,...fieldN FROM table_name1, table_name2...<br>
    ORDER BY field1, [field2...] [ASC [DESC]]
    - ASC/DESC：结果升序/降序输出
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/sort.jpg)
* 分组<br>
    SELECT column_name, function(column_name)<br>
    FROM table_name<br>
    WHERE column_name operator value<br>
    GROUP BY column_name;
    - function(column name)<br>
    对列采用的函数，进行的操作，如count,sum,avg等
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/group_by.jpg)
    - WITH ROLLUP<br>
    实现在分组统计数据基础上再进行相同的统计（SUM,AVG,COUNT…）<br>
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/with_rollup.jpg)
    - coalesce(a,b,c)<br>
    参数说明：如果a==null,则选择b；如果b==null,则选择c；如果a!=null,则选择a；如果a b c 都为null ，则返回为null（没意义）。
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/coalesce.jpg)
* 连接的使用
    - INNER JOIN（内连接，等值连接）获取两个表中字段匹配关系的记录
    - LEFT JOIN（左连接）获取左表所有记录，即使右表没有对应匹配的记录
    - RIGHT JOIN（右连接）获取右表所有记录，即使左表没有对应匹配的记录。
* NULL值处理
    - IS NULL
    - IS NOT NULL
    - <=>:比较运算符（不同于=赋值运算符），当比较的两个值为NULL时返回true
* 正则表达式<br>
    [^]（匹配开始），[$]（匹配结束），[.]（匹配除“\n”所有字符），[|]（或者），[...]（匹配字符集合），[^...]（反向匹配字符），[*]（匹配前面的子表达式0次或多次），[+]（匹配前面的子表达式1次或多次）
* 事务<br>
    一系列的数据操作语句，满足：原子性、稳定性、隔离性、可靠性
    - 开始一个事务：start transaction
    - 做保存点：savepoint 保存点名称
    - 操作
    - 可以回滚、可以提交，没有问题就提交，有问题就回滚
* ALTER命令
    - 删除、添加或修改表字段<br>
    ALTER TABLE tablename DROP i<br>
    ALTER TABLE tablename ADD i INT<br>
    FIRST 和 AFTER字段指定位置
    - 修改字段类型及名称<br>
    MODIFY：ALTER TABLE testalter_tbl MODIFY c CHAR(10);<br>
    CHANGE：ALTER TABLE testalter_tbl CHANGE i j BIGINT;<br>
    - 修改字段默认值

