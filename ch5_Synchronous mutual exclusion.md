# os_learning_note
learning note of operating system from PeKing University
## Synchronous mutual exclusion
### 进程的并发执行
* 并发是所有问题产生的基础，并发是操作系统设计的基础
* 进程的特征：并发，共享，不确定性
### 进程互斥
#### 一些概念
* 进程互斥：个进程要求使用共享资源，而这些资源需要排他性使用，各进程之间竞争使用这些资源。
* 临界资源：系统中某些资源一次只允许一个进程使用，又叫互斥资源或共享变量
* 临界区（互斥区）：各个进程对某个临界资源实施操作的程序片段。<br>
    使用原则如下：<br>
    - 没有进程在临界区时，想进入临界区的进程可进入
    - 不允许两个进程同时处于其临界区中
    - 临界区外运行的进程不得阻塞其他进程进入临界区
    - 不得使进程无限期等待进入临界区
#### 实现互斥
* 软件方案
    - Dekker解法
    ![dekker](https://github.com/sjtujw/os_learning_note/raw/master/img/dekker.jpg)
    - Peterson解法
    ![peterson](https://github.com/sjtujw/os_learning_note/raw/master/img/peterson.jpg)
* 硬件方案
    - 屏蔽中断<br>
        执行“关中断”操作<br>
            临界区操作<br>
        执行“开中断”操作<br>
        特点：简单高效；代价高，限制了CPU的并发能力；不适用于多处理器；适用于操作系统，不适用于用户进程<br>
    - TSL（XCHG）指令
### 进程同步
指系统中多个进程中发生的事件存在某种时序关系，需要相互合作，共同完成一项任务<br>
* Semaphore信号量及P、V
    - 一个特殊变量
    - P、V操作为原语操作，不可中断
    - 用于进程间传递信息的一个整数值
    - 对信号量可以实施的操作：初始化、P（test）和V（increment）
    ![p&v](https://github.com/sjtujw/os_learning_note/raw/master/img/pv.jpg)
    - 最初提出的是二元信号量（解决互斥问题）；之后推广到一般信号量（解决同步）
* 用P、V操作解决进程间互斥问题
    ![pv_mutex](https://github.com/sjtujw/os_learning_note/raw/master/img/pv_mutex.jpg)
* 用Semaphore解决生产者/消费者问题
    ![Sema_cons_produ](https://github.com/sjtujw/os_learning_note/raw/master/img/Sema_cons_produ.jpg)
    ![Sema_cons_produ2](https://github.com/sjtujw/os_learning_note/raw/master/img/Sema_cons_produ2.jpg)
* 读者/写者问题
    ![reader&writer](https://github.com/sjtujw/os_learning_note/raw/master/img/reader_writer.jpg)