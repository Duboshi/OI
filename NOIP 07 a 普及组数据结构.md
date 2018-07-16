NOIP 07 a 普及组数据结构和STL容器简介（未完成）  
======

|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|

	以《CCF中学生程序设计基础篇》第6章、第9章为主；
	以《算法竞赛入门经典》第5.2、6.1、6.2节和《新标准C++程序设计教程》为辅；
	以 C++ Primer 第9章、第11章和The C standard library第6-12章为参考。
------  
## 简介  

普及组数据结构主要有线性数据结构、树、图三个部分，由于图的内容在后续课程会逐渐占据相当大的比例，所以我们把图论单列为一章，本章只讲**线性数据机构**和**树**。我们会运用已有的C++编程知识实现这些数据结构，虽然实现的原理我们应该掌握，但实际参加比赛或者日常编写程序时，我们直接使用STL模板，不用每次都重复“造轮子”。  
C++的标准模板库（Standard Template Library, 下面简称`STL`）是一些常用数据结构和算法模板的集合，主要由Alexander Stepanov和David Musser开发，于1998年被添加进C++标准。STL种有三个基本概念，容器、迭代器和算法：  
![](/diagrams/NOIP%2007%20STL%20Components.JPG)  
图片来自：Josuttis, N. M. (2015). The C++ standard library: A tutorial and reference. Upper Saddle River, NJ: Addison-Wesley.  
1. **容器Container**：用于存放数据的类模板，例如链表、双端队列等。容器可以分成4大类：
	* 1. 顺序容器Sequence containers：数组array，向量（或动态数组）vector，双端队列deque，链表list，前向链表（单向链表）forward_list
	* 2. 容器适配器Container adapters：栈stack，队列queue和优先队列priority_queue  
	* 3. 有序关联容器Associative containers：集合set，映射map
	* 4. 无序关联容器Unordered containers：无序集合unordered_set，无序映射unordered_map  
	* 我们用顺序容器和容器适配器实现线性数据结构，用关联容器实现树形数据结构  
2. **迭代器Iterator**：用于读取容器中元素的工具，作用类似于指针；  
3. **算法Algorithms**：用来操作容器中元素的函数模板，例如排序、查找等。  
![](/diagrams/NOIP%2007%20STL%20Container%20Types.png)  
图片来自：Josuttis, N. M. (2015). The C++ standard library: A tutorial and reference. Upper Saddle River, NJ: Addison-Wesley.  


## 正文
分为两部分：
* [线性数据结构，STL顺序容器和容器适配器](/NOIP%2007%20b%20线性数据结构.md)
* [树，STL关联容器](/NOIP%2007%20c%20树.md)  
