# mysql常用语句及示例
* 连接：mysql -u root -p
* 创建数据库：mysqladmin -u root -p create DBname
* 删除数据库：mysqladmin -u root -p drop DBname
* 选择数据库：use DBname<br>
下面的操作都将在数据库DBname中完成
* 数据类型<br>
    - 日期和时间类型<br>
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/time_class.jpg)
    - 字符串类型<br>
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/char_class.jpg)
* 创建数据表：CREATE TABLE table_name (column_name column_type);
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/create_table.jpg)
* 删除数据表：DROP TABLE table_name ;
* 插入数据：<br>
INSERT INTO table_name ( field1, field2,...fieldN )<br>
                       VALUES<br>
                       ( value1, value2,...valueN );<br>
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/insert_data.jpg)
* 查询数据：<br>
SELECT column_name,column_name<br>
FROM table_name<br>
[WHERE Clause]<br>
[OFFSET M ][LIMIT N]<br>
* where子句：<br>
    - binary来区分大小写<br>
SELECT field1, field2,...fieldN FROM table_name1, table_name2...<br>
[WHERE condition1 [AND [OR]] condition2.....<br>
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/use_of_where.jpg)
* update子句：<br>
UPDATE table_name SET field1=new-value1, field2=new-value2<br>
[WHERE Clause]<br>
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/updata_usage.jpg)
* delete子句：<br>
DELETE FROM table_name [WHERE Clause]<br>
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/delete_usage.jpg)
* Like子句：<br>
    - Like可以替代=
    - 通常与%一同使用，类似于一个元字符的搜索<br>
SELECT field1, field2,...fieldN <br>
FROM table_name1, table_name2...<br>
WHERE field1 LIKE condition1 [AND [OR]] filed2 = 'somevalue'<br>
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/like_usage.jpg)
