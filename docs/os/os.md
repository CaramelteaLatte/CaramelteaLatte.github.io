# Operating System

## CH1 released version

- Computer startup
  - bootstrap program
    - stored in ROM, loads os kernel and starts execution

### Interrupt
- Computer system Operation
  - ![alt text](image.png)
  - IO 和 CPU 可以并发执行 concurrently
  - 每一个 device controller 都有一个 local buffer，执行前 CPU 将主内存中的数据移到 local buffer
  - local buffer 的作用是解决 CPU 和 controller 速度不适配speed mismatch的问题，因此controller 完成 operation的时候会告诉 CPU 一下，interrupt (通过 system bus)
  - IO 是 device 和 local buffer 之间的传输
- Interrupt
  - Interrupt 的请求会通过 interrupt vector 传给 ISR（interrupt service routine）
  - incoming interrupt are disabled 当另外有interrupt在处理中，防止 lost interrupt
- interrupt 分为 IO 中断 和 trap 中断
  - Trap：软件引起的引发系统关注的中断（软中断）
    - 主动发出：user request 要去读一些内容
    - 被动发出：error
- interrupt handling
  - os 会保存 CPU 的状态，register and counter
  - 
- IO structure：两种方式
  - 只有在 IO 完成后 返回 user program 同步 synchronous
  - user program 不等待 IO 处理 异步（一个进程里有多个线程，非阻塞式
  - ![alt text](image-1.png)
- Direct Memory Access Structure（DMA
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
  - 