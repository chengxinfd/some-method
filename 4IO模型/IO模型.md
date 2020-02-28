# IO模型

<font color=#FF6347 size=5 face="黑体">**1.IO模型**</font>

​		就是为了解决通信双方在通信过程中遇到的各种问题，比如一方没有响应/忙

+ <font color=\#00FFFF size=5 face="黑体">**阻塞**</font>

    双方通信的时候，如果一方资源不满足/忙，那么另一方进行等待，绝大多数交互的函数都默认阻塞

    read write accept sendto recv recvfrom send

+ <font color=\#00FFFF size=5 face="黑体">**非阻塞**</font>

+ <font color=\#00FFFF size=5 face="黑体">**多路复用**</font>

+ <font color=\#00FFFF size=5 face="黑体">**异步通知**</font>

![](C:\Users\chengxin\Desktop\io模型.png)