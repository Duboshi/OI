/*	@author 杜博识Dubos

NOIP 05.a 函数
	以《CCF基础篇》第1章为主；
	以《新标准C++程序设计教程》第4章、C++ Primer第6章为辅；
	以	http://www.cplusplus.com/reference/cmath/
		http://www.cplusplus.com/reference/cctype/
		《信息学奥赛一本通》第一部分第6章、《算法竞赛入门经典》第4章为参考；
 */

#include <cstdio>
#include <cctype>
#include <cmath>
#include <iostream>
 
using namespace std;

int factorial (int n);	//例0 
void printFac (int n);	//例0
int facRef (int &n);	//例2
int facPoint (int *p);	//例3 
 
int main()
{
	printf("例0：函数的定义、声明和调用，返回值类型，参数\n");
		/*我们每一章都会见到main函数，另外还见过string库函数、cstring库函数，以及
		高精度计算中自己建立的几个函数。

		1. 函数的定义
			返回值类型 函数名(参数列表)
			{
				函数体
			}			
			例如：
			int main()	//main函数的返回值为整数，所以最后要return 0，
						//main函数没有参数，所以参数列表为空 
			{
				//函数体就是我们写的这些东西 
			} 
			【注意】我们设定main函数返回值为0，所以每次执行程序都会在最后看到
			Process exited after *** seconds with return value 0，但如果程序运行
			发生了错误，就会看到这行字最后return value变成其他数字。 
		
		2. 函数的声明
			返回类型 函数名(参数列表); 
			
			我们可以先声明函数，后定义函数。函数的声明其实就是省略了函数体，并加
			上分号。

		3. 参数：
			a. 参数相当于数学函数中的自变量，函数的返回值就像因变量；
			b. 但这里的参数数量可以为0，即参数列表为空，或者有多个参数。
				即使参数列表为空，函数名后的括号也不能省略；
				如有多个参数，则在参数列表中用逗号分隔：
				(参数1类型 参数1名, 参数2类型 参数2名称,...);
				例如
				(int n, char c, double x)

		4. 函数名：应该能够体现函数的功能

		5. 返回值类型：
			a. 如果函数有返回值，则函数执行结束于return语句，如果返回值类型是int
				那么函数就要返回一个整数值，例如return n (n是int); 若为double就
				返回实数值，若是char则返回字符，以此类推； 
			b. 如果函数不需要返回值（可能函数作用是改变了某个对象，无需另外返回
				新对象或新值，或者函数功能主要是在屏幕输出一些文字），则返回类型
				为void，这时函数无需有return语句。
		
			举例说明，我们想要输入一个1-10的整数，并输出n的阶乘(n factorial)
			n! = n*(n-1)*(n-2)*...*1
			我们既可以建立一个int factorial(int n)函数，然后输出factorial(n)，
			也可以建立一个void printFac(int n)函数，直接在函数中输出。 
			
		6. 函数的调用
			当我们调用函数时，函数必须在之前声明过或者定义过。
			
			main函数可以调用其他函数，其他函数也可以调用main函数（不过我们目前没
			有这么做的意义）。注意C++程序都是从main函数开始执行的，所以其他函数
			必须在main之前声明或者定义。由于这个文件是作为讲义阅读的，在main前面
			写太多函数定义会给同学们阅读造成不便，所以我们在main函数之前声明函数，
			在main函数之后定义函数。 
			
			下面我们将会用int factorial(int n)和void printFac(int n)函数，由于
			int factorial(int n)函数返回值为整数，所以我们可以把factorial(n)
			当作整数来用；而void printFac(int n)没有返回值，我们就不能把它当作
			一个值。 
			
			另外，如果一个文件里面有两个函数彼此调用，就只能先声明后定义，这是
			这种操作的必要性所在，否则一定会编译出错。	*/
		cout<<factorial(5)<<endl;	//这两个函数都声明在main之前，定义在main之后， 
		printFac(5);				//请比较两个函数的函数体和返回类型。
	printf("\n");
	
	printf("例1：全局变量，局部变量，作用域\n");
		/*这几个概念我们在NOIP 04 Pointer中已经介绍过了，现在复习一下。
		 
		1. 【全局变量global variable】是定义在函数外部的变量 
			作用域：全局变量的作用域从变量定义开始到文件结束，可在其定义之后的
				任何函数中使用；
			空间：全局变量存储在内存的全局区（或称为静态区static segment），空间
				限制较大，？？？；
			例如：我们在NOIP 04 Pointer中建立了几个大数组，它们的空间超过了栈区的
				空间限制（2M），所以我们把它们定义为全局变量，储存在全局区。
		
		2. 【局部变量local variable】是定义在函数内部乃至循环内部的变量
			作用域：局部变量的作用域仅限于函数中变量定义之后，在函数外无法访问。
				循环所建立的局部变量，其作用域仅限与循环内部，在循环所在的函数内
				其他区域也是无法访问的；如果局部变量与作用域以外的变量重名，那么
				内部作用域的变量会暂时屏蔽外部定义的变量； 
			空间：局部变量存储在内存的栈区stack segment，栈区空间限制较小，仅为2M，
				这个空间属于临时空间，函数执行完毕就会被系统释放然后用于其他函数
				或变量，所以某次调用函数产生的变量值无法在下一次调用时继续使用，
				而且占空间大于2M的变量不能定义为局部变量；
			例如：下面建立一个main函数局部变量int a，再建立一个for循环局部变量
				int a； */
		int a = 5;
		for (int a=5; a>0; a--)
			{
				cout<<"for loop local a = "<<a<<endl;	//内部局部变量a从5递减到1 
			}
		cout<<"main function local a = "<<a<<endl;		//外部局部变量a依然是5 
	printf("\n");
	
	printf("例2：参数传递\n");
		/*首先要区分形式参数与实际参数。
		【形式参数】
			函数定义中的参数，例如int factorial(int n)中的n，其实写成n还是m都一样，
			只是一个形式。 
		【实际参数】
			调用函数时传递给参数的实际值，如上文中factorial(5)中的5。
			 
		然后我们介绍两种参数传递机制：
		1. 【传值参数】
			例如
			int a = 5;
			factorial(a);
			之后a的值依然是5，即使在factorial函数里a的值被循环从5递减到1。
			因为这里int factorial(int n)采用了传值参数：当函数被调用时，a的值5被
			赋值给函数中新建的局部变量n，所以无论函数内部n有什么变化，对函数外面
			的a都没有影响。
			 
		2. 【引用参数】
			这个跟前面就不一样了。让我们建立一个int facRef(int &n)函数，函数体跟
			int factorial(int n)一模一样，但是 
			a = 5;
			facRef(a);
			之后a值会变成1。这是因为facRef采用了引用参数，其参数int &n是a的别名，
			在facRef函数内部并没有新建立局部变量int n，用的还是函数外面a的内存
			空间，所以循环递减也会发生在a身上。 
			*/
		a = 5;
		cout<<factorial(a)<<endl;			//120
		cout<<"a = "<<a<<endl<<endl;		//5，a值未改变 
		
		a = 5;
		cout<<facRef(a)<<endl;				//120
		cout<<"a = "<<a<<endl;				//1，a值改变了 
	printf("\n");	
	
	printf("例3：函数与指针\n");
		/*函数指针和函数指针数组在信息学竞赛中几乎用不到，所以我们不讲解这部分内
		容。下面说一下指针作为函数参数。
		
		指针参数属于传值参数，但是起到的作用却跟引用参数类似，下面举例说明：
		
		让我们建立一个采用指针参数的函数，int facPoint (int *q)，功能还是阶乘，
		在声明main函数之前，定义在main函数之后，请认真看它的参数和函数体。
		
		当我们这样调用int facPoint (int *q)函数时：
			facPoint(p);
		就会在facPoint函数中建立一个新指针int *q，并让指针q复制指针p的内容，所以
		指针参数属于传值参数。这时指针q就会指向整数a，之后每次对*q进行运算，
		就是对a进行运算，所以起到的作用是跟引用参数类似的，可以改变函数之外的变量
		（只是可以改变，但不一定会改变，这要看函数体中的命令是否改变指针参数所指
		的变量）。
		
		cstring库函数绝大多数都使用了指针参数，知道了指针参数的用法，以及指针与
		数组的关系之后，我们就可以透彻理解cstring库函数了。
		
		【注意】指针容易出错，所以如果可以避免使用的话，就不要用指针。	*/
		a = 5;
		int *p = &a;
		cout<<"p = "<<p<<endl; 
		cout<<facPoint(p)<<endl;			//120
		cout<<"a = "<<a<<endl;				//1，a值改变了
		cout<<"p = "<<p<<endl;				//但是指针p一直没变 
	printf("\n");
	
	printf("例4：函数重载\n");
		/*两个函数重同名但是参数列表不同（可能参数类型不同，也可能参数个数不同）
			的情况叫做函数重(chong)载function overloading。 
			例如char compare(int m, int n)和char compare(char a, char b)两个函数，
			一个用于比较两整数大小，另一个用于比较两字符前后，编译器根据调用时
			提供的变量数量和类型选择合适的函数。
			
			函数重载情况在信息学竞赛中不太常见，所以我们就不详细介绍了。但在IT
			业界还是非常常见的，同学们以后有时间要认真看一下相关的资料。 
			
		【注意】同名函数只有参数列表不同才算重载。如果同名函数的函数列表相同
			而返回值类型不同，则不是函数重载而是函数重复定义。函数重复定义是不被
			允许的。*/
	printf("\n");
	
	printf("例5：头文件和库函数，cmath库函数，ctype库函数\n");
		/*C++语言标准库中定义了一些常用功能的函数，不同函数定义在不同的头文件里，
			例如有关数学计算的函数就在<cmath>中，它们被称为<cmath>的库函数。所有厂商
			的C++编译器都会提供标准函数，你在电脑里面C++编译器文件夹中就能找到
			这些头文件。
			
		我们目前最常用的库函数有
			<cstdio>中的printf、scanf
			<iostream>中的cin、cout
		我们还学过下面字符串头文件的库函数：
			<string> 
			<cstring>
		现在我们再简单介绍两个头文件：<cmath>和<cctype>.
		
		1. cmath库函数：这是C++从C语言math.h头文件继承来的，顾名思义，cmath库函数
			主要是实现常见数学函数，例如：
			double abs (double x)函数：绝对值
			double sin (double x)函数：正弦
			double cos (double x)函数：余弦
			double exp (double x)函数：求自然常数（e=2.71828...）的幂e^x
			double log (double x)函数：求x的自然对数ln(x)
			double pow (double x, double y)函数：求x的y次幂 x^y
			double sqrt (double x)函数：平方根 
			double cbrt  (double x)函数：立方根
			double ceil (double x)函数：求刚好大于x的整数 
			double floor (double x)函数：求刚好小于x的整数 */
		cout<<
		"abs(-3.14) = "<<abs(-3.14)<<endl<<			//3.14
		"sin(-3.14) = "<<sin(-3.14)<<endl<<			//-0.00159265
		"cos(-3.14) = "<<cos(-3.14)<<endl<<			//-0.999999
		"exp(1) = "<<exp(1)<<endl<<					//2.71828
		"log(2.71828) = "<<log(2.71828)<<endl<<		//0.999999
		"pow(2, 10) = "<<pow(2, 10)<<endl<<			//1024
		"sqrt(100) = "<<sqrt(100)<<endl<<			//10
		"cbrt(1000) = "<<cbrt(1000)<<endl<<			//10
		"ceil(0.5) = "<<ceil(0.5)<<endl<<			//1
		"ceil(-0.5) = "<<ceil(-0.5)<<endl<<			//-0
		"floor(0.5) = "<<floor(0.5)<<endl<<			//0
		"floor(-0.5) = "<<floor(-0.5)<<endl<<endl;	//-1
		
		/*2. cctype库函数：这是从C语言ctype.h头文件继承来的，主要功能是对字符类型
			做出判断，以及切换字符的大小写
			int tolower (int c)函数：把整数c对应的字母（按照ASCII码进行对应）转换
				为小写字母，注意输出的是整数，所以要用(char)进行强制类型转换； 
			int toupper (int c)函数：转换为大写，还是要注意类型转换；
			int islower (int c)函数：判断整数c对应的字母是否为小写，是则结果为1，
				否则结果为0；
			int isupper (int c)函数：判断是否为大写字母；
			int isalpha (int c)函数：判断是否为英文字母，大写字母返回1，小写返回2，
				否则返回0； 
			int isdigit (int c)函数：判断是否为10进制数字。 */
		cout<<
		(char)tolower('A')<<endl<<					//a
		(char)toupper('a')<<endl<<					//A
		"isupper('A') = "<<isupper('A')<<endl<<		//1
		"isupper('a') = "<<isupper('a')<<endl<<		//0
		"isalpha('a') = "<<isalpha('a')<<endl<<		//2
		"isdigit('a') = "<<isdigit('a')<<endl;		//0  
	printf("\n");
	return 0;
}

int factorial (int n)
{
	int result=1;
	while (n>1)
	{
		result*=n;
		n--;
	}
	return result;
}

void printFac (int n)
{
	int result=1;
	while (n>1)
	{
		result*=n;
		n--;
	}
	cout<<result<<endl;
}

int facRef(int &n)
{
	int result=1;
	while (n>1)
	{
		result*=n;
		n--;
	}
	return result;
}

int facPoint (int *q)
{
	int result=1;
	while ((*q) > 1)
	{
		result *= (*q);
		(*q) --;
	}
	q = 0;	//这一行对于阶乘函数没有意义，我们特意在这里改变指针q，
			//以检验这个函数会否改变函数之外的指针p。 
	return result;
}

/*	作业：
		本章属于C++语言基础知识，没有单独作业题。NOIP 05 b递归之后会有作业。 
*/
