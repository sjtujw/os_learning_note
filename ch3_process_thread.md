# os_learning_note
learning note of operating system from PeKing University
## 进程和线程
### 进程

* 进程定义<br>
    进程是具有独立功能的程序关于某个数据集合上的一次运行活动，是系统进行资源分配和调度的独立单位<br>
* PCB（process control block）进程控制块<br>
    1. 操作系统用于管理控制进程的一个专门数据结构
    2. 记录进程的各种属性，描述进程的动态变化过程
    3. 进程与PCB一一对应
    4. 进程表：所有进程的PCB集合
* PCB包括：<br>
    - 进程描述信息：进程标识符（唯一的）、通常基于可执行文件名（不唯一）、用户ID、进程组关系；
    - 进程控制信息：当前状态、优先级、代码执行入口地址、程序的磁盘地址、运行统计时间、进程间同步和通信、进程的队列指针、进程的消息队列指针；
    - 所拥有的资源和使用情况：虚拟空间使用情况、打开的文件列表；
    - CPU现场信息：寄存器值（通用寄存器、程序计数器PC、程序状态字PSW、栈指针）、指向该进程页表的指针；
* 进程状态及状态转换<br>
    - 三状态模型
        1. 运行态（占有CPU并在CPU上运行）、就绪态（具备运行条件但没有空闲CPU）、等待态（因等待某一事件而暂时不能运行）
        2. 模型及转换<br>
        ![three_state](https://github.com/sjtujw/os_learning_note/raw/master/img/three_state.jpg)
        3. 进程的其他状态<br>
        ![other_state](https://github.com/sjtujw/os_learning_note/raw/master/img/other_state.jpg)
    - 五状态模型
        1. 创建、就绪、阻塞、运行、终止<br>
        ![five_state](https://github.com/sjtujw/os_learning_note/raw/master/img/five_state.jpg)
    - 七状态模型
        1. 创建、就绪、阻塞、就绪挂起、阻塞挂起、运行、退出<br>
        ![seven_state](https://github.com/sjtujw/os_learning_note/raw/master/img/seven_state.jpg)

