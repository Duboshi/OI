NOIP 08 b 线性数据结构，STL顺序容器和容器适配器（未完成）  
======

|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|

本文是[NOIP 08 a 普及组数据结构和STL容器](/NOIP%20Junior/NOIP%2008%20a%20数据结构普及组.md)正文的一部分。  

------  

线性数据结构的特点是，在数据元素的非空有限集中：
* 存在唯一一个“**第一个first数据元素**”；
* 存在唯一一个“**最后一个last数据元素**”；
* 每个数据元素（first数据元素可以例外）只有一个**直接前驱immediate predecessor**；
* 每个数据元素（last数据元素可以例外）只有一个**直接后继immediate successor**。  

我们学习每种数据结构都是先了解其功能， 然后用已有C++编程知识实现，最后学习如何直接使用STL相应容器。

* **数组array**：之前讲过，现在就不重复了
* 顺序表：r《基》P128-130  
	水水水水水
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
