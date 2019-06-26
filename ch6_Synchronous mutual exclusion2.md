# os_learning_note
learning note of operating system from PeKing University
## Synchronous mutual exclusion 2
### monitor管程
* 管程是一种高级同步机制，定义为：<br>
是一个特殊的模块，有一个名字，由关于共享资源的数据结构及在其上操作的一组过程组成。<br>
进程只能通过调用管程中的过程来间接访问管程中的数据结构。
* 管程要解决的问题
    - 互斥
        管程是互斥进入的————为了保证管程中数据结构的数据完整性，管程的互斥性是由编译器负责保证的。<br>
    - 同步
        管程中设置条件变量及等待/唤醒操作以解决同步问题，可以让一个进程或线程在条件变量上等待（此时，应先释放管程的使用权）<br>
* HOARE管程

* MESA管程
### 进程间通信Inter-Process Communication
### 典型操作系统的IPC机制