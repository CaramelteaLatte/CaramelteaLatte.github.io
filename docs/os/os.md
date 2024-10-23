# Operating System

## CH1 released version

- Computer startup
  - bootstrap program
    - stored in ROM, loads os kernel and starts execution
- 冯诺依曼架构中最重要的部分是 main memory

### Interrupt
- Computer system Operation
  - ![alt text](image.png)
  - IO 和 CPU 可以并发执行 concurrently
  - 每一个 device controller 都有一个 local buffer，执行前 CPU 将主内存中的数据移到 local buffer
  - local buffer 的作用是解决 CPU 和 controller 速度不适配speed mismatch的问题，因此controller 完成 operation的时候会告诉 CPU 一下，interrupt (通过 system bus)
  - IO 是 device 和 local buffer 之间的传输
- Interrupt
  - Interrupt 的请求会通过 interrupt vector（含有所有 service routine 地址） 传给 ISR（interrupt service routine）
  - incoming interrupt are disabled 当另外有interrupt在处理中，防止 lost interrupt
- interrupt 分为 IO 中断 和 trap 中断
  - Trap：软件引起的引发系统关注的中断（软中断）
    - 主动发出：user request 要去读一些内容
    - 被动发出：error
- interrupt handling
  - 操作系统通过存储寄存器 registers 和程序计数器 program counter 来保存CPU的状态
  - 如何知道是哪种 interrupt
    - 用一个通用例程进行轮询 polling
    - 向量中断系统 vectored interrupt system
    - 单独的代码段确定对每种类型的中断应采取什么操作
- IO structure：两种方式
  - 只有在 IO 完成后 返回 user program 同步 synchronous
  - user program 不等待 IO 处理 异步 asynchronous（一个进程里有多个线程，非阻塞式
  - ![alt text](image-1.png)
- Direct Memory Access Structure（DMA）
  - 用于能够以接近内存速度传输信息的高速 I/O 设备
  - 每个块 block 仅生成一个中断，而不是一个中断每字节中断
  - 不需要 CPU 干预，控制力度降低

### Storage
- Storage structure
  - Main memory：被看作是last cache for secondary storage
  - Secondary storage
  - Magnetic disks
  - ![alt text](image-2.png)
- speed，cost，volatility易失性
- caching
  - faster storage，解决速度适配的问题，用中的信息暂时从较慢的存储复制到较快的存储 
  - cache 小于被 caching 的内存
- data migration
  - ![alt text](image-3.png)

### Operating System Structure
- Operating System Structure
  - **multiprogramming**：efficiency （**CPU utilization**）
    - user 不能让 CPU 和 IO 一直 busy
    - multiprogramming 组织代码和数据，CPU 始终有一个要执行
    - One job selected and run via **job scheduling**
    - 当 job 在等待时，OS 做其他工作
  - **Timesharing (multitasking)**：Response time should be < 1 second（**interactivity**）
    - *process* 进程：at least one program executing in memory
    - *CPU scheduling* 调度: several jobs ready to run at the same time
    - *swap*: 如果进程不适合内存，交换会将它们移入和移出，来保证重要的 process 进行
    - *Virtual memory*：允许不完全在内存中执行进程
- Operating-System Operations
  - 来自外部硬件中断 interrupt
  - 来自软件的中断 trap: user request / error
  - 其他进程问题包括无限循环、进程相互修改或操作系统修改
- Protection for Operating-System Operations
  - **dual mode**: user mode / kernel mode(like `sudo`)
    - **Mode bit** provided by hardware 提供区分系统何时运行用户代码或内核代码的能力
  - kernel mode: **privileged**
  - **system calls** 将模式更改为内核，从调用返回将其重置为用户
  ![alt text](image-6.png)

### Resource Management

- Timer & Interrupt: to prevent infinite loop / process hogging resources
  - 在调度进程之前设置特定时间后中断。操作系统递减计数器，当计数器为零时产生中断，让 CPU 重新获得控制权或终止超出分配时间的程序
- Process Management：进程是操作系统中对于资源的抽象
  - **process** 进程: a program in execution. program 是被动 passive 实体，process 是主动 active 实体
  - 需要的 resource：CPU, memory，I/O，files，Initialization data
  - 进程终止要回收所有可重用资源
  - **Single-threaded process** 有一个程序计数器指定下一条要执行的指令的位置，进程按顺序执行指令，一次一个，依次完成
  - **Multi-threaded process** 每个线程有一个程序计数器
  - 通常系统有许多进程、一些用户、一些操作系统在*一个或多个* CPU 上同时运行
    - 通过在进程/线程之间复用 CPU 实现并发 Concurrency by **multiplexing the CPUs** among the processes / threads
- ![alt text](image-7.png)
- Memory Management
  - data：进程前或完成后必须在内存中
  - instructions：必须放在内存中来运行
  - Memory Management决定内存中的内容，优化CPU利用率和计算机对用户的响应
  - 设计：
    - 记录是谁在用内存分别用了多少内存
    - 分发和回收内存空间
    - 决定将哪些进程（或其部分）和数据移入和移出内存
- Storage Management
  - OS
    - **file**：将物理属性抽象为逻辑存储单元
    - control：每种介质均由设备（即磁盘驱动器、磁带驱动器）控制
  - File-System management
  - directories
  - **access control**：访问权限控制，privelege
- Mass-Storage Management：通常磁盘用于存储主存无法容纳的数据或必须长期保存的数据。
  - 计算机运行的整体速度取决于磁盘子系统及其算法Entire speed of computer operation hinges on disk subsystem and its algorithms
  - 操作系统的作用：storage分配，disk规划，free-space管理
- I/O Subsystem
  - 操作系统的目的之一是向用户隐藏硬件设备的特性——易于使用和编程 hide peculiarities of hardware devices from the user – ease of usage & programming 
  - IO 的内存管理包括了buffering（在传输数据时临时存储数据）caching（将部分数据保存在更快的存储中以提高性能）spooling（一项工作的输出与其他工作的输入重叠）

## CH2 Operating-System Structures
### Operating System Services
- a set of services
  - **user interface (UI)**: Command-Line(CLI), Graphics User Interface(GUI)
  - **program execution**: 系统必须能够将程序加载到内存中并运行该程序，结束执行，无论是正常还是异常（指示错误）
  - **IO operations**
  - **File-system manipulation**操纵
  - **Communication**：processes交换信息，通过computer（shared memory 或message passing这种需要通过操作系统）或者是在 同一网络环境下 的电脑
  - **Error detection**
  - **Resource allocation**
    - 许多类型的资源 - 一些（例如 CPU 周期、内存和文件存储）可能具有特殊的分配代码，其他（例如 I/O 设备）可能具有通用请求和释放代码
  - **accounting**：记账，跟踪哪些用户使用了多少计算机资源以及何种类型的计算机资源
  - **Protection and security**
    - protection: 确保所有对系统资源的access都是受控制的
    - security：要求user authentication，扩展到保护外部 I/O 设备免受无效访问尝试
### User Operating System Interface
- CLI allows direct command entry
  - Sometimes implemented in *kernel*, sometimes by *systems program*
# 补写！！！！

### System Calls
- Application Program Interface (API)：更为高层的程序接口的封装
  - system calls 低阶，不方便，用high-level language比较多
  ![alt text](image-8.png)
- System Call Implementation
    - 每个系统调用都有一个关联的号码。系统调用接口维护一个根据这些号码索引的表
    - ![alt text](image-9.png)
    - 
- System Call Parameter Passing
  - simpliest: **registers**
  - 当寄存器个数不够
    - **block**，或者table（linux系统或solaris系统使用这个方式）
    - parameters 被 push 到程序的 **stack** 中，被操作系统 pop 出去（压栈，OS 出栈，栈不一定共享）
- Types of System Calls
  ![alt text](image-10.png)
  
### System Programs系统程序
- File manipulation，Status information，File modification，Programming language support，Program loading and execution，Communications，Application programs

### Operating System Design and Implementation

- 操作系统的设计**not solvable**但是意味着**creative**，但是一些具体的 实现方式被证明是正确的
- Important principle to separate (2.6.2)
  - **Policy**:   What will be done?策略（确定具体做什么事）
  - **Mechanism**:  How to do it? 机制（定义做事方式）
    - Example: timer for CPU protection is a mechanism
- Example: Separation of Mechanism and Policy
  - hotel：card/keys
    - policy：什么人在什么时间可以使用card/keys进入
    - mechanisms：magnetic card readers, remote controlled locks, connections to a security server
  - The matrix data determines a policy, and the switching network is a mechanism
  ![alt text](image-11.png)

## CH3：Processes

### concept

- program
  - batch system 批处理系统：sequence of jobs
  - time-sharing system ：user program or tasks
    - multitasking
    - less turnaround, less CPU idle, user interaction
    ![alt text](image-12.png)
- process: **program in execution**
  - include:
    - text section(code)
    - data section(global vars)
    - stack(function parameters, local vars, return addresses)
    - heap (dynamically allocated memory)
    - program counter 

### process state

![alt text](image-13.png)

![alt text](image-14.png)

### Process Schedule

- Process Scheduling Queues
  - 主流：链表实现
  - **Job queue**任务堆叠 – 系统中所有进程的集合
  - **Ready queue**（最关心 – 等待使用 CPU 的进程序列
  - **Device queues** – 等待使用IO的
- scheduler
  - Long-term scheduler  (or **job scheduler**) 
    - selects which processes should be brought into memory (the ready queue)
  - Short-term scheduler  (or **CPU scheduler**) 
    - selects which process should be executed next and allocates CPU

# CH3 没写完

## CH4：Threads

## CH5：CPU Scheduling

### CPU Scheduling

goal：在 multiprogramming 下使 **CPU 利用率 utilization** 达到最高

（原因：进程在 IO burst 的时候 waiting 会降低 CPU 的使用率，在 IO burst的时候进行 CPU 调度）

![alt text](image-15.png)

histogram of CPU-burst times： CPU 调度非常频繁且大多非常快->**frequently and efficient**

- CPU Scheduler（区分longterm和shortterm）
  - 从内存中选择需要执行的进程，然后将 CPO 分配给其中一个
  - CPU 调度takeplace：
    - 进程从running到waiting（IO 或者 wait()），和反之（IO 完成）
    - 进程从running到ready（interrupt）
    - 进程结束
  - 以上原因发生的 CPU 调度是 **nonpreemptive** 的，非抢占式
  - 其他原因导致的调度是 **preemptive** 的，抢占式
- Dispatcher
  - 使 CPU 可以控制进程（在 short-term 调度下）
    - 转换内容、转入usermode、转入正确的新 user program 的地址
  - **dispatch latency**
    - stop 旧进程和 start 新进程之间的延迟时间
    - ![alt text](image-16.png)
- 调度法则 Scheduling Criteria
  - CPU utilization 利用率：让 CPU 尽量 busy（*使用到 CPU 的时间 / 全部进程完成的时间*）
  - Thoughtput 吞吐率：在单位时间内完成的进程数量（*进程数 / 全部进程完成的时间*）
  - Turnroundtime 周转时间：运行一个particular process的时间，要包括调度的时间！！（*终止减去起始的时间*）
  - Waitingtime 等待时间：进程在 ready queue里面等待 CPU 的时间（*注意不是等待 IO 的时间*）
  - Responsetime 响应时间：进程提交后第一次跟用户反馈结果第一次响应的时间，不指得到最终结果output
### FCFS SJF SRTF schedule算法
- First-Come, First-Served (FCFS) Scheduling 最常见
  - Arrival order makes difference!
  - 非抢占式
  - **Convoy effect（护航效应）**: 当短进程排在长进程后运行时，平均等待时间会较长，IO 和 CPU 就会很空闲
  - 有利于长作业，不利于短作业；有利于CPU繁忙型，不利于I/O繁忙型
- Shortest-Job-First (SJF) Scheduling
  - 将一个进程与它的下一个 CPU burst综合考虑来调度使得用最短的时间
  - 两种框架
    - 非抢占式：一旦 CPU 给了一个进程，CPU 就不能被抢占给其他进程直到这个进程的 CPU burst 结束
    - 抢占式**Shortest-Remaining-Time-First (SRTF)**：当一个新的进程来，这个新进程的 CPUburst时间比当前剩余的CPU burst
- Determining Length of Next CPU Burst
  - 我们无法知道下一次 burst 的长度，只能使用 estimate 的方式
  - *exponential averaging (指数平均法)*
  - ![alt text](image-17.png)
  - ![alt text](image-18.png)
  - ![alt text](image-19.png)
- SJF better，提供了最短的平均等待时长
  - 进程 startvation
- Priority Scheduling
  - 对每一个进程都有一个 integer 作为它的 **priority number** 与它联系，数字越小优先级越高
  - CPU 会被分配给最高优先级的进程（抢占式/非抢占式）
  - **SJF是优先级调度**，其中优先级是预测的下一个 CPU burst 时间
  - **Static Priority**：static=notchange，在进程创建的时候决定
  - Problem 约等于 Starvation - low priority processes may never execute
    - solution：**Dynamic Priority**  
      - solution 约等于 Aging - 随着时间的推移进程优先级提高

- Highest Response Ratio Next （HRRN）
  - 高响应比优先
  - 算法工作原理
    - 初始化：记录每个进程的到达时间和所需的服务时间
    - 计算响应比：对每一个就绪队列中的进程，计算其响应比
    - 选择高响应比的进程：选择具有最高响应比的进程执行（如果有相同的最高响应比，就按照其他的规则比如FCFS等来选择
    - 更新等待时间和响应比：一次调度后就更新所有就绪队列中进程的等待时间，并重新计算所有进程的响应比
  - HRRN 是 FCFS 和 SJF 的折中
  - 注意计算响应时间本身是需要时间的
- Round Robin (RR) *（emmmm谷歌翻译成《循环赛》）*
  - 每个进程获得一个小的CPU时间单位（time quantum 时间量子），通常是10-100毫秒。经过该时间后，该进程将被抢占并添加到就绪队列的末尾。
  - 比 SJF 有更高的平均周转时间，但 CPU 利用率提高和better交互性不能同时实现
  - 对等待序列中的 n 个进程，时间量子为 q，因此每个进程都会获得1/n的 CPU 时间。
    - 不会有进程的等待时间会超过 (n-1)q。
    - 如果 q 的值大，选择 FCFS 算法 ——**Time-sharing system**
    - 如果 q 的值小，要要求 q 的值不能太小，否则context switch的次数会过高，overhead 开销太大 —— **Multitasking system**
    - ![alt text](image-20.png)
    - 周转时间由时间量子的大小决定
- Multilevel queue
  - ready queue 被分为两个 queue：foreground（交互性的）和 background（batch）
  - 对每个分开的 queue 使用不同的调度算法：foreground —— RR，background —— FCFS
  - ![alt text](image-21.png)
  - Multilevel Feedback Queue
    - ![alt text](image-22.png)
    - 设置多个就绪队列，优先级从第一级依次降低
    - 优先级高的队列，进程时间片越短
    - 每个队列都采用FCFS，若在该时间片完成，则撒离系统，未完成，转入下一级级队列
    - 按队列优先级调度，仅当上一级为空时，才运行下一级
# ppt32

## CH6: Process Synchronization

> 进程同步：确保多个进程可以按照**一定顺序或在一定条件下**正确访问**共享资源** Concurrent access to shared data may result in **data inconsistency** ，并发访问共享数据可能会导致数据不一致

### 6.1 critical-section problem 临界区问题

- race condition 竞态条件：同一个内存位置被*并发地访问*，且至少有一次访问进行了*写操作*。
- 非抢占式内核也会受到竞态条件的影响：**critical-section problem 临界区问题**
  - 临界资源：在多进程（或线程）中被共享的资源
    - 要使用一定的机制进行保护，来确保同一时刻只有一个进程（或线程）对他访问
  - 临界区：每个进程中访问临界资源的代码
- Solution 的目标
  - **互斥（Mutual Exclusion）**：在任何时刻，最多只能有一个进程或线程进入临界区。
    
  - **空闲让进（Progress）**：如果没有进程在临界区内且有其他进程想要进入，则应该允许这些进程最终进入临界区，而不能无限等待。
    
  - **有限等待（Bounded Waiting）**：每个进程都有一个有限的等待时间，不会发生饥饿（即一个进程永远不能进入临界区的情况）。

### 6.2 软件同步方式

#### 1 单标志法
  - 设置公共整型变量 turn，允许进入进阶去的进程编号 turn = i，表示允许进程 Pi 进入临界区；进程退出临界区的时候交给新进程 turn = j

(下图，如果 turn 不等于 i，进程 Pi 会等待；退出临界区时，将 turn 设为 j，允许 Pj 进入)

<img src="image-27.png" alt="alt text" style="zoom:80%;" />

#### 2 双标志后检查法
  - 设置布尔型数组 flag[2]，用来标记各进程进入临界区的意愿 flag[i] = true 表示进程 Pi 想进入
  - 先表达自己进入临界区意愿
  - 再轮询对方是否想进入，确定对方不想进入后再进入
  - 访问结束退出后设置 flag[i] = false，表示不想进入，允许对方进入

（下图，Pi 先表达想进入，轮询问 Pj 想不想进入，等待至 Pj 完成或者 Pj 不想进入，Pi 进入临界区）

<img src="image-28.png" alt="alt text" style="zoom: 67%;" />

可能导致双方都不能进入，违反了空闲让进和有限等待

#### 3 双标志先检查法

- 设置布尔型数组 flag[2]，用来标记各进程进入临界区的意愿 flag[i] = true 表示进程Pi想进入
- 进程进入临界区前先轮询对方是否想进入
- 确定对方不想进入后再进入
- 访问结束退出后设置 flag[i] = false，表示不想进入，允许对方进入

