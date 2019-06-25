# os_learning_note
learning note of operating system from PeKing University
## 进程和线程
### 进程

#### 进程定义
进程是具有独立功能的程序关于某个数据集合上的一次运行活动，是系统进行资源分配和调度的独立单位<br>
#### PCB（process control block）进程控制块
- 操作系统用于管理控制进程的一个专门数据结构
- 记录进程的各种属性，描述进程的动态变化过程
- 进程与PCB一一对应
- 进程表：所有进程的PCB集合
#### PCB包括：<br>
- 进程描述信息：进程标识符（唯一的）、通常基于可执行文件名（不唯一）、用户ID、进程组关系；
- 进程控制信息：当前状态、优先级、代码执行入口地址、程序的磁盘地址、运行统计时间、进程间同步和通信、进程的队列指针、进程的消息队列指针；
- 所拥有的资源和使用情况：虚拟空间使用情况、打开的文件列表；
- CPU现场信息：寄存器值（通用寄存器、程序计数器PC、程序状态字PSW、栈指针）、指向该进程页表的指针；
#### 进程状态及状态转换<br>
- 三状态模型
    1. 运行态（占有CPU并在CPU上运行）、就绪态（具备运行条件但没有空闲CPU）、等待态（因等待某一事件而暂时不能运行）
    2. 模型及转换<br>
    ![three_state](https://github.com/sjtujw/os_learning_note/raw/master/img/three_state.jpg)
    3. 进程的其他状态<br>
    ![other_state](https://github.com/sjtujw/os_learning_note/raw/master/img/other_state.jpg)
- 五状态模型
    创建、就绪、阻塞、运行、终止<br>
    ![five_state](https://github.com/sjtujw/os_learning_note/raw/master/img/five_state.jpg)
- 七状态模型
    创建、就绪、阻塞、就绪挂起、阻塞挂起、运行、退出<br>
    ![seven_state](https://github.com/sjtujw/os_learning_note/raw/master/img/seven_state.jpg)
- linux状态示意图<br>
![linux_state](https://github.com/sjtujw/os_learning_note/raw/master/img/linux_state.jpg)
#### 进程队列
- 操作系统为每一类进程建立一个或多个队列
- 队列元素为PCB
- 随着进程状态变化，其PCB从一个队列进入另一个队列
#### 进程控制
* 进程的创建<br>
给新进程分配一个唯一标识以及进程控制块；为进程分配地址空间；初始化PCB；设置对应的队列指针
* 进程的撤销<br>
收回进程占用的资源（关闭打开的文件、断开网络连接、回收分配的内存）；撤销该进程的PCB
* 进程阻塞<br>
处于运行状态的进程，等待事件发生。当被等待的事件未发生时，进程自己执行阻塞，切换至阻塞态
* UNIX的几个进程控制操作
    - fork()：复制调用进程来创建新的进程
    - exec()：新程序代码覆盖原来的地址空间，实现进程执行代码的转换
    - wait()：使一个进程等另一个进程结束
    - exit()：终止一个进程
* 例：UNIX下fork（）的实现
    - 为子进程分配一个空闲的进程描述符
    - 分配给子进程唯一标识 pid
    - 以一次一页的方式复制父进程地址空间（linux时改进，copy-on-write）
    - 从父进程处继承共享资源，如打开的文件和当前工作目录等
    - 将子进程的状态设为就绪，插入到就绪队列
    - 对子进程返回标识符 0
    - 向父进程返回子进程的 pid
* pid
    父进程的pid为子进程创建的pid号，一般不为0；子进程的pid为0。
#### 进程进一步讨论
* 分类
    系统进程和用户进程、前台进程和后台进程、CPU密集型进程和I/O密集型进程
* 和程序的区别
    - 程序是静态的，进程是动态的
    - 进程有生命周期，是短暂的；程序是相对长久的
    - 一个程序可能有多个进程；进程可以创建进程
* 进程地址空间<br>
    ![address_expla](https://github.com/sjtujw/os_learning_note/raw/master/img/address_expla.jpg)
* 上下文（context）切换
    - 定义：将CPU硬件状态从一个进程切换到另一个进程的过程
    - 进程运行时，其硬件状态保存在CPU的寄存器中，主要是（程序计数器PC，程序状态寄存器PSW，栈指针，通用寄存器，其他控制寄存器）
    - 进程不运行时，寄存器值保存在PCB中，运行时送入相应寄存器
#### 进程小结
![summary_of_process](https://github.com/sjtujw/os_learning_note/raw/master/img/address_expla.jpg)
### 线程
#### 概念
进程中的一个运行实体，是CPU的调度单位。进程仍然拥有资源，但线程是现在的CPU调度单位。
#### 属性
* 有标识符ID
* 有状态及状态转换 ——> 需要提供操作
* 不运行时需要保存上下文，上下文环境指：程序计数器等寄存器
* 有自己的栈和栈指针
* 共享所在进程的地址空间和其他资源
* 可以创建、撤销另一个线程
#### 线程的实现
* 用户级线程（主动让出CPU资源）
    - 优点
    1. 线程切换快
    2. 调度算法时应用程序特定的
    3. 用户级线程可运行在任何操作系统上（只需实现线程库）
    - 缺点
    1. 内核只将处理器分配给进程，同进程的线程不能运行于多个CPU上
    2. 大多数系统调用是阻塞的，由于内核阻塞进程，所有线程也会被阻塞
* 核心级线程（如，Windows）
    - 内核管理所有线程，并向应用程序提供API接口
    - 内核维护进程和线程的上下文
    - 线程的切换需要内核支持
    - 以线程为基础进行调度
* 混合模型（Solaris）
    - 线程创建在用户空间
    - 线程调度在核心态完成
    


