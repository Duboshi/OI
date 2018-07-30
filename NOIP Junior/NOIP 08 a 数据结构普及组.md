NOIP 08 a 数据结构普及组和STL容器
======

|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|  

------  

## 数据结构简介

1968年Donald E. Knuth（高德纳）的*The Art of Computer Programming*（简称TAOCP）第一卷Volume 1: Fundamental Algorithms出版，书中详细讨论了数据的逻辑结构和存储结构，开创了数据结构（他在书中称为信息结构Information structure）的最初体系。从那时起《数据结构》开始成为一门独立的课程，至今已经是计算机专业的核心课程之一。  
![](/diagrams/NOIP%2008%20a%20KnuthAtOpenContentAlliance.jpg)  
Knuth in 2005 (by Jacob Appelbaum)  

**数据结构Data structure**是指数据的存储和组织形式。依据不同的数据实际情况以及使用目的，我们可以选用乃至建立不同的数据结构。

数据结构之间的差别主要体现在两方面，一个是**逻辑**方面，另一个是**存储**方面。  
* 所谓逻辑方面的区别，就是不同数据结构中数据间的逻辑关系不一样。按照这个角度，数据结构可以分为四类：  
	* **集合（逻辑）结构**：如果我们记录学校各个社团的名单，但只关心每名同学是否属于某个社团，而不关心社团里各个同学之间的关系，这时候适合用集合结构；
	* **线性（逻辑）结构**：如果要把班级同学按照身高排序可以使用数组array，数组就是一种我们已经接触过的数据结构；多台电脑共用一台打印机时，打印机会按照各台电脑提交打印任务的先后顺序处理，这时候使用的数据结构是队列list，有先进先出(first-in-first-out, FIFO)的特性；浏览网页时我们不断点击“后退”按钮，浏览器就会不断逆向显示之前显示过的页面，这时存储历史记录的数据结构是栈stack，有后进先出(last-ink-first-out, LIFO)的特性。数组、队列、栈都是线性数据结构的具体例子；  
	* **树形（逻辑）结构**：计算机目录结构、互联网域名、企业、政府等都具有鲜明的层次化特征，使用树结构更为合适。树属于**非线性结构**，但由于在附加某种约束之后，也可以在树中的元素之间确定某种线性次序，因此树结构也被称为**半线性结构**；
	* **图状（逻辑）结构**：城市交通图中公交车站由街道连接，互联网中IP结点由路由器连接，这类结构使用图结构更为合适。图属于**非线性结构**，我们解决图的策略是将其转换为半线性结构。  
	* NOIP普及组主要涉及**线性、树、图**三种，由于图的内容在后续课程会逐渐占据相当大的比例，所以我们把图论单列为一章，本章只讲**线性数据机构**和**树**。我们会运用已有的C++编程知识实现这些数据结构，虽然实现的原理我们应该掌握，但实际参加比赛或者日常编写程序时，我们直接使用STL模板，不用每次都重复“造轮子”。  
* 所谓存储方面的区别，就是不同数据结构存储数据的形式不同，主要分成两类：
	* **顺序（存储）结构** 中逻辑上相邻的数据在硬件（例如内存）上占据的物理空间也相邻，于是我们只要知道第一个数据的内存地址，就能推知后面第n个数据的内存地址，所以顺序结构的元素访问方式是**寻秩访问（call-by-rank）**；
	* **链式（存储）结构** 中逻辑上相邻的数据在硬件（例如内存）上占据的物理空间不一定相邻，所以相关的两个数据之间必须要建立索引关系，以便访问，所以链式结构的元素访问方式是**循链访问（call-by-link）**;
	* 现在举例子就扯得太远了，讲到线性结构时我们再举例说明。

## STL简介

C++的标准模板库（Standard Template Library, 下面简称`STL`）是一些常用数据结构和算法模板的集合，主要由Alexander Stepanov和David Musser开发，于1998年被添加进C++标准，目前NOIP、NOI、IOI、ACM-ICPC、TopCoder、Codeforces、Google Code Jam、Facebook Hacker Cup等各类算法竞赛中都允许使用STL。STL中有三个基本概念，容器、迭代器和算法：  
![](/diagrams/NOIP%2007%20STL%20Components.JPG)  
图片来自：Josuttis, N. M. (2015). The C++ standard library: A tutorial and reference. Upper Saddle River, NJ: Addison-Wesley. 

1. **容器Container**：用于存放数据的类模板，例如链表、双端队列等。容器可以分成4大类：
	1. **顺序容器Sequence containers**：数组array，向量（或称动态数组）vector，链表list，前向链表（单向链表）forward_list，双端队列deque  
		```cpp
		vector <int> a;
		//建立一个容器对象a，它的容器类是vector <int>，即元素为int类型的向量（或称动态数组）  
		//目前可以把向量理解成长度可以变化的数组（所以也叫动态数组）
		```  
	2. **容器适配器Container adapters**：栈stack，队列queue和优先队列priority_queue  
	3. **有序关联容器Associative containers**：集合set，映射map，  
	4. **无序关联容器Unordered containers**：无序集合unordered_set，无序映射unordered_map  
![](/diagrams/NOIP%2007%20STL%20Container%20Types.png)  
图片来自：Josuttis, N. M. (2015). The C++ standard library: A tutorial and reference. Upper Saddle River, NJ: Addison-Wesley.  

2. **迭代器Iterator**：用于访问容器中元素的工具。迭代器是个变量，指向容器中的某个元素，作用类似于指针，```* 迭代器```就表示迭代器指向的元素。迭代器按照定义方式可以分为以下4种：
	1. **正向迭代器**：能够修改其指向元素的值  
		```cpp 
		vector<int>::iterator i; //建立一个正向迭代器i，访问vector <int>容器中的元素  
		```  
	2. **常量正向迭代器**：不能修改其指向元素的值，注意其与**正向迭代器常量**的区别，详见下例  
		```cpp  
		vector <int> a;
		
		//一定要注意下面前两个概念（常量正向迭代器 vs. 正向迭代器常量）的差别，第三个（正向迭代器）是作为对比
		vector<int>::const_iterator i = a.begin(); //建立一个【常量正向迭代器】i，初始化赋值指向向量a的首位元素，之后可以访问vector <int>容器中的不同元素，但不能修改其指向元素的值
		const vector<int>::iterator j = a.begin(); //建立一个【正向迭代器常量】j，初始化赋值指向向量a的首位元素，之后不能访问vector <int>容器中的其他元素，但可以修改其指向元素的值
		vector<int>::iterator k = a.begin(); //作为对比，建立一个【正向迭代器】k，初始化赋值指向向量a的首位元素，之后既能访问vector <int>容器中的其他元素，又可以修改其指向元素的值  
		  
		*i += 1; //改变i所指向元素的值，不可以  
		*j += 1; //改变j所指向元素的值，可以 
		*k += 1; //改变k所指向元素的值，可以  
		
		++i; //让i指向其他元素，可以  
		++j; //让j指向其他元素，不可以  
		++k; //让k指向其他元素，可以  
		```  
		对于正向迭代器和常量正向迭代器，```++迭代器```都表示指向后一个元素，而```--迭代器```则表示指向前一个元素。下例演示了如何通过正向迭代器遍历一个vector <int>容器：
		```cpp	
		#include <iostream>  
		#include <vector>  
		using namespace std;  

		int main()
		{
			vector <int> a; //建立一个元素为int类型的向量a
			for (int n=0; n<5; ++n)
				a.push_back(n);
			//为向量a赋值5个元素：{0, 1, 2, 3, 4}，push_back是vector库函数，在向量尾部添加元素
			
			vector <int>::iterator i;
			//建立一个用于vector <int>向量的正向迭代器i

			for (i=a.begin(); i!=a.end(); ++i)
				cout << *i << " ";
			cout << endl;
			//从前向后遍历向量a，输出i所指向的元素*i，结果是"0 1 2 3 4 "
			//注意：begin()是指向容器中第一个元素的正向迭代器，而end()则是指向最后一个元素【之后一个位置】的正向迭代器
			
			for (i=a.end()-1; i!=a.begin()-1; --i)
				cout << *i << " ";
			cout << endl;
			//从后向前遍历向量a，输出i所指向的元素*i，结果是"4 3 2 1 0 "

			return 0;
		}
		```  
	3. **反向迭代器**：能够修改其指向元素的值  
		```cpp
		vector<int>::reverse_iterator r; //建立一个反向迭代器i，访问vector <int>容器中的元素
		```
	4. **常量反向迭代器**：不能修改其指向的元素，同理要注意与**反向迭代器**的区别，这里不赘述
		```cpp
		vector<int>::const_reverse_iterator r;
		//建立一个常量反向迭代器r，访问vector <int>容器中的元素，之后可以访问vector <int>容器中的不同元素，但不能修改其指向元素的值
		```
		下例演示了如何通过反向迭代器遍历一个vector容器：
		```cpp  
		#include <iostream>  
		#include <vector>  
		using namespace std;  

		int main()
		{  

			vector <int> a;
			//建立一个元素为int类型的向量a

			for (int n=0; n<5; ++n)
				a.push_back(n);
			//为向量a赋值5个元素：{0, 1, 2, 3, 4}，push_back是vector库函数，在向量尾部添加元素

			vector <int>::reverse_iterator r;
			//建立一个用于vector <int>向量的反向迭代器r

			for (r=a.rbegin(); r!=a.rend(); ++r)
				cout << *r << " ";
			cout << endl;
			//从后向前遍历向量a，输出r所指向的元素*r，结果是"4 3 2 1 0 "
			//注意：rbegin()是指向容器中最后一个元素的反向迭代器，而rend()则是指向第一个元素【之前一个位置】的反向迭代器
			//注意：rbegin()和rend()不能用于正向迭代器，begin()和end()不能用于反向迭代器

			for (r=a.rend()-1; r!=a.rbegin()-1; --r)
				cout << *r << " ";
			cout << endl;
			//从前向后遍历向量a，输出r所指向的元素*r，结果是"0 1 2 3 4 "

			return 0;
		}  
		```  

	以上按照定义方式将迭代器分为4类，而按照功能从弱到强还可以将迭代器分为3类（另有输入迭代器和输出迭代器目前不解释）：  
	1. **单向迭代器**：只能```++迭代器```移动  
	2. **双向迭代器**：可以```++迭代器```和```--迭代器```移动  
	3. **随机访问迭代器**：具备双向迭代器的功能，还支持```迭代器+=整数```、```迭代器-=整数```等移动方式。而且两个随机访问迭代器之间可以用>、<、>=、<=等进行比较以及-进行计算，"i1 < i2"的含义是i1指向元素的地址小于i2指向元素的地址，"i1-i2"的返回值是i1指向元素和i2指向元素的序号之差  

	不同容器上的迭代器功能不一样：  
	
		|容器|迭代器功能|  
		|---|---|  
		|vector|随机访问|  
		|deque|随机访问|  
		|list|双向|  
		|set/multiset|双向|  
		|map/multimap|双向|  
		|stack|无（不支持迭代器）|  
		|queue|无（不支持迭代器）|  
		|priority_queue|无（不支持迭代器）|  
		
3. **算法Algorithms**：用来操作容器中元素的函数模板，例如排序、查找等  

## 正文
分为两部分：
* [线性数据结构，STL顺序容器和容器适配器](/NOIP%20Junior/NOIP%2008%20b%20线性数据结构.md)
* [树，STL关联容器](/NOIP%20Junior/NOIP%2008%20c%20树.md)  

###### 参考资料  

> 《CCF中学生程序设计基础篇》第6和9章；  
> 《算法竞赛入门经典》第5.2、6.1、6.2节；  
> 《新标准C++程序设计教程》第19章；  
> 《数据结构（C语言）》（严蔚敏，吴伟民）第1-6章；  
> 《数据结构（C++语言）》（邓俊辉）第1-6章；  
> Competitive Programming 3 第2章；  
> Introduction to Algorithms 第1、10章；  
> C++ Primer 第9、11章；  
> The C++ standard library 第6-12章。  
