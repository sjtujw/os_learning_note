# os_learning_note
learning note of operating system from PeKing University
## Schedule of CPU
### 相关概念
#### CPU调度
其任务是控制、协调进程对CPU的竞争，按照一定的调度算法从就绪队列中选择一个进程，把CPU的使用权交给被选中的进程
#### 要解决的问题
* 调度算法
    - 指标<br>
    吞吐量throughout————每单位时间完成的进程数目<br>
    周转时间TT（Turnaround Time）————每个进程从提出请求到运行完成的时间<br>
    响应时间RT（Response Time）————从提出请求到第一次回应的时间<br>
    CPU利用率（CPU Utilization）————CPU做有效工作的时间比例<br>
    等待时间（Waiting Time）————每个进程在就绪队列中等待的时间<br>
* 调度时机
    - 进程正常终止 或 由于某种错误终止
    - 新进程创建 或 一个等待进程变为就绪
    - 当一个进程从运行态进入阻塞态
    - 当一个进程从运行态进入就绪态
* 调度过程（进程的上下文切换）
    - 从就绪队列选择要运行的程序。
    - 切换主要是保存旧的状态和恢复新的状态
    - 进程切换包括：切换全局页目录以加载一个新的地址空间；切换内核栈和硬件上下文，后者包括CPU相关寄存器
    - 切换的具体步骤<br>
    ![process_of_switch](https://github.com/sjtujw/os_learning_note/raw/master/img/process_of_switch.jpg)
    - 切换的开销<br>
直接开销：内核完成切换所用的CPU时间（保存和恢复寄存器、切换地址空间）；<br>
间接开销：高速缓存、缓冲区缓存和TLB（translation Look-aside Buffer）失效
### 调度算法要点
* 进程优先级（数）<br>
静态优先级和动态优先级
* 进程就绪队列组织<br>
按优先级、按照先后顺序
* 抢占和非抢占<br>
指的是占用CPU的方式，抢占指可强行剥夺正在运行进程的CPU，分配给优先级更高的进程。
* I/O密集型与CPU密集型<br>
前者频繁进行I/O，大量的等待时间；后者大量的CPU计算时间
* 时间片<br>
一个时间段，分配给调度上CPU的进程，确定了允许该进程运行的时间长度。<br>
如何选择：进程切换的开销；对响应时间的要求；就绪进程个数；CPU能力；进程的行为。<br>
### 批处理系统的调度算法
* 先来先服务（FCFS-First Come First Serve）
    - 先进先出
    - 按照线程就绪的先后顺序使用CPU
    - 非抢占式的
    - 优缺点：实现简单、公平、长进程后面的短进程需要等很久
    - 例
    ![fcfs1](https://github.com/sjtujw/os_learning_note/raw/master/img/fcfs1.jpg)
    ![fcfs2](https://github.com/sjtujw/os_learning_note/raw/master/img/fcfs2.jpg)
* 最短作业优先（SJF-Shortest Job First）
    - 具有最短完成时间的进程优先执行
    - 非抢占式
    - 优缺点：最短的平均周转时间、不公平（长的任务长时间得不到运行，starvation）
* 最短剩余时间优先（SRTN-Shortest Remaining Time Next）
    - SJF的抢占式算法
    - 例
    ![sjf](https://github.com/sjtujw/os_learning_note/raw/master/img/sjf.jpg)
* 最高响应比优先（HRRN-Highest Response Ratio Next）
    - 调度时，首先计算每个进程的响应比R；之后，选择R最高的进程执行
    - R = 周转时间/处理时间<br>
        = （处理时间+等待时间）/处理时间<br>
        = 1+（等待时间/处理时间）<br>
### 交互式系统的调度算法
* 轮转调度（RR-Round Robin）
    - 思路：周期性切换，每个进程分配一个时间片，时钟中断——>轮换
    - 优缺点：公平、有利于交互式计算，响应快、开销较大
    - 对不同大小的进程有利，对相同大小的进程性能差
* 最高优先级调度（HPF—Highest Priority First）
    - 通常：系统进程优先级 高于 用户进程；前台进程优先级 高于 后台进程；I/O优先级一般较高
    - 实现简单、不公平
    - 优先级反转问题：低优先级进程持有高优先级进程的资源，使得高优先级进程等待<br>
    影响：系统错误；高优先级进程停滞，导致系统性能降低<br>
    解决方案：设置优先级上限；优先级继承；使用中断禁止<br>
* 多级反馈队列（Multiple feedback queue）
![mfq](https://github.com/sjtujw/os_learning_note/raw/master/img/mfq.jpg)
* 最短进程优先（Shortest Process Next）
### 各种调度算法的比较
![comparison](https://github.com/sjtujw/os_learning_note/raw/master/img/comparison.jpg)
### 典型操作系统采用的调度算法
* UNIX 动态优先数法
* 5.3BSD 多级反馈队列法
* Linux 抢占式调度
* Windows 基于优先级的抢占式多任务调度
* Solaris 综合调度算法

