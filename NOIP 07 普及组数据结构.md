NOIP 07 普及组数据结构，STL容器（未完成）  
======

|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|

------
	以《CCF中学生程序设计基础篇》第6章、第9章为主；
	以《算法竞赛入门经典》第5.2、6.1、6.2节和《新标准C++程序设计教程》为辅；
	以 C++ Primer 第9章、第11章为参考。
	
普及组数据结构主要有线性表、树、图三个部分，由于图相关的内容在后续课程会逐渐占据相当大的比例，所以我们把图论单列为一章，本章只讲**线性表**和**树**。我们会运用已有的C++编程知识实现这些数据结构，虽然实现的原理我们应该掌握，但实际参加比赛或者日常编写程序时，我们直接使用STL模板，不用每次都重复“造轮子”。  
C++的标准模板库（Standard Template Library, 下面简称`STL`）是一些常用数据结构和算法模板的集合，主要由Alexander Stepanov和David Musser开发，与1998年被添加进C++标准。STL种有三个基本概念，容器、迭代器和算法：  
* 1. 容器Container：用于存放数据的类模板，例如链表、双端队列等。容器可以分成4大类：
	* 1. 顺序容器Sequence containers：数组array，向量（或动态数组）vector，双端队列deque，链表list，前向链表（单向链表）forward_list
	* 2. 有序关联容器Associative containers：集合set，映射map
	* 3. 无序关联容器Unordered containers：无序集合unordered_set，无序映射unordered_map
	* 4. 容器适配器Container adapters：栈stack，队列queue和优先队列priority_queue  
	![](/diagrams/NOIP%2007%20STL%20Container%20Types.png)  
	Josuttis, N. M. (2015). The C standard library: A tutorial and reference. Upper Saddle River, NJ: Addison-Wesley.  
* 2. 迭代器Iterator：用于读取容器中元素的工具，作用类似于指针；  
* 3. 算法Algorithms：用来操作容器中元素的函数模板，例如排序、查找等。  

* 线性表和STL顺序容器Sequential Containers：《基》P126-127  
STL顺序容器包括向量vector、
	* 顺序表：r《基》P128-130 
	* 链表list
		* r《基》P130-135 
		* 《入》P143-148，但是这两本书都没有用STL list的例题
	* 队列queue
		* r《基》P138-141，P233例9.3
		* 《入》P117-119，例5-6 
	* 双端队列deque
		* 《入》P139例6-1
	* 优先队列priority_queue
		* 《入》P119-120，例5-7 
	* 向量（或称动态数组）vector
		* 《基》P234-235、例9.4
		* 《入》P109-111
	* 栈stack
		* 《入》P115-117
	* 集合set
		* 《入》P112-113
	* 映射map
		* 《基》P237-240
		* 《入》P113-115
* 树
	* 树
	* 二叉树
* 图（图论单开一章）
