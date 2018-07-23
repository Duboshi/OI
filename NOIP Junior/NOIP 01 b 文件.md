NOIP 01.b 文件（未完成）
======

|Author|杜博识Dubos|
|---|---
|E-mail|dubos@foxmail.com

------

我们在上一节介绍了标准输入输出（从键盘输入、从屏幕输出），平时在OJ做题也使用标准输入输出，但是这种做法有不便之处：每次重新运行都需要重新在键盘输入数据。如果能把需要输入的数据保存在文件中，并让程序直接读取文件中的数据，然后输入到另一个文件里，这样就解决了不方便的问题。实际上信息学竞赛中也是采用这种`文件输入输出`的方式。  

由于信息学竞赛的输入数据有时很大，所以数据文件的读取效率非常重要。我们下面介绍的是三种效率较高的文件输入输出方式：  

* **一、文件重定向方法：freopen + scanf/printf**
	* 这是最简单的方法，在main函数前两行加入freopen语句即可：
		```cpp
		#include <cstdio> //freopen是cstdio库函数

		using namespace std;
		int main ()
		{
			freopen("输入文件名", "r", stdin);	//r代表read
			freopen("输出文件名", "w", stdout);	//w代表write
			//正常该写什么就写什么
			return 0;
		}
		```  
	* 在[2010年NOIP之前](http://www.noi.cn/noi-news/noi/331-freopen)，国内信息学竞赛不允许使用这种方法，现在有些更新不及时的资料里还有“禁止使用重定向”的字样。[2010年主办方“应广大指导教师与选手的要求”解除了对文件重定向方法的限制](http://www.noi.cn/noi-news/noi/329-noip2010)。
	* 例1  
		* 输入（filename.in）:一个整数
		* 输出（filename.out）:该整数的平方   
		```cpp
		#include <cstdio>
		#include <iostream>
		using namespace std;
		int main ()
		{
			freopen("filename.in", "r", stdin);
			freopen("filename.out", "w", stdout);
			int n;
			scanf("%d", &n);
			printf("%d", n*n);
			return 0;
		}
		//输入输出文件与源代码在同一个文件夹里：可以自己新建一个文本文档，里面写一个整数，
		//然后把拓展名改为.in，之后运行代码，就会发现同一个文件夹里多了一个.out文件。  
		```

* **流文件方法：fstream + fin/fout**  
	* 这是第二种做法，未完成  
	
* **文件指针方法：FILE * + fscanf/fprintf**
	* 这是第二种做法，未完成
