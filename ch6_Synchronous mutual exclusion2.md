# os_learning_note
learning note of operating system from PeKing University
## Synchronous mutual exclusion 2
### monitor管程
* 管程是一种高级同步机制，定义为：<br>
是一个特殊的模块，有一个名字，由关于共享资源的数据结构及在其上操作的一组过程组成。<br>
进程只能通过调用管程中的过程来间接访问管程中的数据结构。
* 管程要解决的问题
    - 互斥<br>
        管程是互斥进入的————为了保证管程中数据结构的数据完整性，管程的互斥性是由编译器负责保证的。<br>
    - 同步<br>
        管程中设置条件变量及等待/唤醒操作以解决同步问题，可以让一个进程或线程在条件变量上等待（此时，应先释放管程的使用权）<br>
* HOARE管程
    - 缺点：两次额外的进程切换
* 管程的应用
    - 实现：<br>
    直接构造（效率高）；间接构造（用某种已经实现的同步机制去构造，例如用P、V）
    - 解决生产者消费者问题<br>
    ![pipeline_consumer](https://github.com/sjtujw/os_learning_note/raw/master/img/pipeline_consumer.jpg)
* MESA管程
* 管程小结
    - 管程：抽象数据类型<br>
    有一个明确定义的操作集合，通过它且只有通过它才能操纵该数据类型的实例<br>
    - 实现管程结构必须保证下面几点：<br>
    （1）只能通过管程的某个过程才能访问资源；<br>
    （2）管程是互斥的，某个时刻只能有一个进程或线程调用管程中的过程<br>
    - 条件变量：为提供进程与其他进程通信或同步而引入<br>
    wait/signal 或 wait/notify 或 wait/broadcast
### 进程间通信Inter-Process Communication
#### 基本通信方式
* 消息传递
![mesg_deliv](https://github.com/sjtujw/os_learning_note/raw/master/img/mesg_deliv.jpg)
* 共享内存
* 管道（pipe）
    - 利用一个缓冲传输介质————内存或文件链接两个相互通信的进程
    - 字符流方式写入读出
    - 先进先出顺序
    - 管道通信机制必须提供的协调能力————互斥、同步、判断对方进程是否存在
* 套接字
* 远程过程调用
### 典型操作系统的IPC机制
#### UNIX
管道、消息队列、共享内存、信号量、信号、套接字
#### Linux
管道、消息队列、共享内存、信号量、信号、套接字
* 内核同步机制<br>
原子操作、自旋锁、读写锁、信号量、屏障(矩阵运算)、BKL
#### Windows
同步对象：互斥对象、事件对象、信号量对象、临界区对象、互锁变量<br>
套接字、文件映射、管道、命名管道、邮件槽、剪贴板、动态数据交换、对象连接与嵌入、动态链接库、远程过程调用<br>