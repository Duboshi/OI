NOIP 01.b 文件（未完成）
======

|Author|杜博识Dubos|
|---|---
|E-mail|dubos@foxmail.com

------

我们在上一节介绍了标准输入输出（从键盘输入、从屏幕输出），平时在OJ做题也使用标准输入输出，但是这种做法有不便之处：每次重新运行都需要重新在键盘输入数据。如果能把需要输入的数据保存在文件中，并让程序直接读取文件中的数据，然后输出到另一个文件里，这样就解决了不方便的问题。**实际上信息学竞赛中就是采用文件输入输出（而非标准输入输出）的方式**。  

由于信息学竞赛的输入数据有时很大，所以数据文件的读取效率非常重要。我们下面介绍的是三种效率较高的文件输入输出方式：  

* **一、文件重定向方法：freopen + scanf/printf**
	* 这是最简单的方法，在main函数的前两行加入freopen语句即可：  
	
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
	
	* 这种方法是C++语言用freopen函数把标准输入stdin和标准输出stdout重新定向到相关文件，使标准输入输出变成了文件输入、输出。**【注意】重定向方法最好搭配scanf和printf，如果搭配cin和cout会很慢**。（江涛，宋新波，朱全民，2016，第117页）
	* 2010年NOIP之前，国内信息学竞赛不允许使用重定向方法，例如[2009年版的《NOI评测环境及对编程语言使用限制的规定》](http://www.noi.cn/newsview.html?id=67&hash=2DA1FD&type=6)，现在有些更新不及时的资料里还有“禁止使用重定向”的字样。实际上从2010年起[“应广大指导教师与选手的要求，NOIP放开对freopen函数与```<fstream>```头文件的限制”](http://www.noi.cn/newsview.html?id=204&hash=2E8B9A&type=1)，2011年版的[《关于NOI系列赛编程语言使用限制的规定》](http://www.noi.cn/newsview.html?id=229&hash=878FD2&type=6)已经删掉了有关重定向的限制，所以现在可以使用重定向方法。  
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
			freopen("filename1.out", "w", stdout);
			int n;
			scanf("%d", &n);
			printf("%d", n*n);
			return 0;
		}
		//输入输出文件与源代码在同一个文件夹里：可以自己新建一个文本文档，里面写一个整数，
		//然后把拓展名改为.in，之后运行代码，就会发现同一个文件夹里多了一个.out文件。  
		```

* **二、流文件方法：fstream + fin/fout**  
	* 这是第二简单的方法，需要：
		* 包含```<fstream>```头文件，因为输入流文件类型（ifstream）和输出流文件变量类型（ofstream）都在其中  
		* 再定义一个输入流文件变量fin和一个输出流文件变量fout  
		* 用fin（而不再是cin）输入，fout（而不再是cout）输出  
	* 与重定向方法相同，流文件方法在2010年NOIP之前也是不允许使用的，现在也已经放开使用了。
	* 例2
		* 输入（filename.in）:一个整数
		* 输出（filename.out）:该整数的平方   
	
		```cpp
		#include <fstream>	//包括<fstream>
		using namespace std;
		int main()
		{
			ifstream fin("filename.in");	//建立输入流文件变量fin
			ofstream fout("filename2.out");	//建立输出流文件变量fout
			
			int n;
			fin >>n;	//用fin（而不再是cin）输入
			fout <<n*n;	//用fout（而不再是cout）输出
			return 0;
		}
		//输入输出文件与源代码在同一个文件夹里：可以自己新建一个文本文档，里面写一个整数，
		//然后把拓展名改为.in，之后运行代码，就会发现同一个文件夹里多了一个.out文件。  
		```
		
	* 本文暂时没有介绍使用close函数关闭文件的方法，详见江涛等人（2016）第113页例5.3  
	
* **三、文件指针方法：FILE * + fscanf/fprintf**  
	* 这是第三简单的方法，需要：  
		* 包括```<cstdio>```头文件，因为FILE类型在其中，而fopen、fscanf、fprintf都是其库函数；  
		* 建立文件指针```FILE *fin, *fout;```；  
		* 打开输入文件和输出文件；  
		* 使用fscanf（而不再是scanf）输入，使用fprintf（而不再是printf）输出；  
	* 例3
		* 输入（filename.in）:一个整数
		* 输出（filename.out）:该整数的平方   
		
		```cpp
		#include <cstdio>

		using namespace std;

		int main()
		{
			FILE *fin, *fout;
			fin = fopen("filename.in", "r");	//打开一个输入文件 
			fout = fopen("filename3.out", "w");	//打开一个输出文件 

			int n;
			fscanf(fin, "%d", &n);		//使用fscanf输入
			fprintf(fout, "%d", n*n);	//使用fprintf输出

			return 0;
		}
		//输入输出文件与源代码在同一个文件夹里：可以自己新建一个文本文档，里面写一个整数，
  		//然后把拓展名改为.in，之后运行代码，就会发现同一个文件夹里多了一个.out文件。  
		```

###### 参考文献  
> |文献|章节|  
> |---|---|
> |江涛, 宋新波, 朱全民. (2016). CCF中学生计算机程序设计基础篇. 科学出版社.|第5章.|  
