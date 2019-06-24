# os_learning_note
learning note of operating system from PeKing University
## CH1 操作系统概述
### 操作系统的三个作用
* 资源的管理者<br>
* 向用户提供各种服务<br>
* 对硬件机器的扩展<br>
### 资源管理的五大功能
* 进程/线程管理（CPU管理）<br>
* 存储管理<br>
* 文件管理<br>
* 设备管理<br>
* 用户接口<br>
### OS的特征
* 并发<br>
并发：处理多个同时性活动的能力<br>
并行：多指不同程序同时在多个硬件部件上执行
* 共享<br>
操作系统与多个用户的程序共同使用计算机系统中的资源，操作系统对系统资源进行合理分配和使用，资源在一个时间段内交替被多个进程使用。<br>
互斥共享（如打印机）<br>
同时共享（如可重入代码、磁盘文件）<br>
* 虚拟<br>
一个物理实体映射为多个对应的逻辑实体————分时或分空间<br>
* 随机<br>
必须随时对以不可预见的次序发生的事件进行响应并处理。<br>
### 典型操作系统的架构
* windows架构
![structure_windows](https://github.com/sjtujw/os_learning_note/raw/master/img/structure_windows.jpg)
* UNIX架构
![structure_unix](https://github.com/sjtujw/os_learning_note/raw/master/img/structure_unix.jpg)
* LINUX架构
![structure_linux](https://github.com/sjtujw/os_learning_note/raw/master/img/structure_linux.jpg)
* Android架构
![structure_android](https://github.com/sjtujw/os_learning_note/raw/master/img/structure_android.jpg)
