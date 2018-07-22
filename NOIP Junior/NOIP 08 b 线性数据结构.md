NOIP 08 b 线性数据结构，STL顺序容器和容器适配器（未完成）  
======

|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|

本文是[NOIP 08 a 普及组数据结构和STL容器](/NOIP%20Junior/NOIP%2008%20a%20数据结构普及组.md)正文的一部分。  

------  

我们已经知道，数据结构可以按照逻辑分为集合、线性、树形、图状四类，也可以按存储分为顺序、链式两类。这一节我们介绍几种线性数据结构，他们的共同点是从逻辑上讲，在数据元素的非空有限集中：
* 存在唯一一个“**第一个first数据元素**”；
* 存在唯一一个“**最后一个last数据元素**”；
* 每个数据元素（first数据元素可以例外）只有一个**直接前驱immediate predecessor**；
* 每个数据元素（last数据元素可以例外）只有一个**直接后继immediate successor**。  

他们的不同点是：
* 其中有的属于顺序存储：逻辑上相邻的数据在硬件（例如内存）上占据的物理空间也相邻，寻秩访问；
* 另外一些属于链式存储：逻辑上相邻的数据在硬件（例如内存）上占据的物理空间不一定相邻，循链访问。  
我们学习每种数据结构都是先了解其功能， 然后用已有C++编程知识实现，最后学习如何直接使用STL相应容器。

* **数组array**：之前讲过，现在就不重复了
* 顺序表：r《基》P128-130  
	* 功能
		* 顺序表从逻辑来讲是线性数据结构，从存储来讲是顺序数据结构，所以它是用一组地址连续的存储单元（数组）一次存储线性数据结构。顺序表里逻辑上相邻的数据存储位置也相邻；
		* 插入：
		* 删除：
	* 实现：
	* 容器：没有对应STL容器，直接用数组即可
	
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```	

* 向量（或动态数组）vector
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```

* 链表list
	* r《基》P130-135 
	* 《入》P143-148，但是这两本书都没有用STL list的例题
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
* 队列queue
	* r《基》P138-141，P233例9.3
	* 《入》P117-119，例5-6 
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
* 双端队列deque
	* 《入》P139例6-1
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
* 优先队列priority_queue
	* 《入》P119-120，例5-7 
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
* 向量（或称动态数组）vector
	* 《基》P234-235、例9.4
	* 《入》P109-111
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
* 栈stack
	* 《入》P115-117
	```cpp
	#include<iostream>

	int main() 
	{
		return 0;
	}
	```
	
------

	【参考资料】
		《CCF中学生程序设计基础篇》第6和9章；
		《算法竞赛入门经典》第5.2、6.1、6.2节；
		《新标准C++程序设计教程》第19章；
		《数据结构（C语言）》（严蔚敏，吴伟民）第1-6章；
		《数据结构（C++语言）》（邓俊辉）第1-6章；
		Competitive Programming 3 第2章；
		Introduction to Algorithms 第1、第10章；
		C++ Primer 第9、11章；
		The C++ standard library 第6-12章。
