# mysql高阶用法
* 排序<br>
    SELECT field1, field2,...fieldN FROM table_name1, table_name2...<br>
    ORDER BY field1, [field2...] [ASC [DESC]]
    - ASC/DESC：结果升序/降序输出
    ![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/sort.jpg)
* 分组
SELECT column_name, function(column_name)<br>
FROM table_name<br>
WHERE column_name operator value<br>
GROUP BY column_name;
    - function(column name)<br>
    对列采用的函数，进行的操作，如count,sum,avg等
![](https://github.com/sjtujw/os_learning_note/raw/master/mysql/img/group_by.jpg)
* 连接的使用