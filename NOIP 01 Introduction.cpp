/*	@author 杜博识Dubos

NOIP 01. C++程序设计入门
	以《一本通》第一部分1、2章为主；
	以《入门经典》第1章（不包含1.4节）、第2.4节为辅（写得简略且用的C语言）；
	以《CCF入门篇》第1、2章为参考；

	首先阅读《一本通》p1 - 8，大致了解C++语言的特点（具体各种关键字、控制语句、
	运算符、数据类型我们随后会详细介绍），了解如何开始用Dev C++写代码。
 
	C++语言程序的结构主要有（《一本通》p13 - 14）：
		1. 【变量】：变量在使用之前必须先定义其数据类型，下面详细解释；
		2. 【函数】：可以有一个或者多个，但只有一个【主函数】main()；
		3. 【库函数】：如果需要调用系统提供的库函数，则需要使用【预处理命令】将
			对应【头文件】包含在程序中（这句话生词较多，看下面的例子就明白了）；
		4. 【段注释Paired comments/行注释Single-line commments】：注释是写给程序
			员看的，计算机执行代码而不会执行注释。现在这段就是段注释，由起止符号
			括起来，下文中有行注释，以//起始，到行末为止；
		5. 分号：每行程序以;作为结束，但预处理命令、函数头()、花括号{}之后不用；
		6. 缩进：缩进可以使代码和注释显得清晰易读（对程序员来讲易读，对计算机
			其实没区别，计算机不管缩进和分行的）。
 */

#include <cstdio>
	/*
	1. 为使用printf和scanf，getchar和putchar，需调用cstdio库，所以要将
		【头文件】iostream包括在本程序中，至于printf等库函数有什么用，随后会介绍
	2. 这种#打头的代码就叫做【预处理命令Preprocessor】
	*/
#include <iostream>
	//为使用cin和cout（这就是行注释）
#include <cmath>
	//为使用指数函数pow(x, y)，平方根函数sqrt(x)等
#include<string>
	//为使用字符串

using namespace std;
	//使用标准（std）名称空间，这么做的原因详见《入门经典》p102，读不懂暂且略过

int main()
	/*
	1. 主函数的起始声明，这个函数是整个程序运行的起始点，无论在代码中
		是位于前面还是中间或者后面，主函数的代码总是最先被执行；
	2. ()中间可以输入参数，但即使没有参数（例如此处）， 也不能将()省略；
	3. main的内容用{}括起来
	4. 主函数main()的返回语句表示程序结束。一般返回0代表顺利结束，返回其他值
		代表有异常；
	*/
{
	cout<<"NOIP 01. C++程序设计入门"<<endl<<endl;

	cout<<"例0：注释，库函数，头文件，主函数，名称空间，分号，缩进\n\n";

	cout<<"例1：cout函数，换行控制符\n";
		cout<<"Hello World!\n\n";
		/*（《一本通》p4：例1.1：Hello World！）
	
		【cout函数】（《一本通》p5, p31）
			1. cout是C++的iostream库提供的输出流函数，其用法如下：
				cout<<表达式1<<表达式2<<表达式3...;
				其作用是把表达式的值输出在屏幕上；
			2. 表达式可以是各种基本类型的常量、变量或者有它们组成的表达式
				（常量、变量、表达式下面会介绍）；
			3.  <<是【流插入运算符】，表示将数据从各表达式插入cout。
	
		【换行控制符】（一本通p5, p12，p32）
			1. 注意是endl不是end1，表示输入后换行显示后续内容;
			2. 除了endl以外，还可以用\n，这是一种转义字符（下面详细解释）；
	
		学会编译、运行程序（《一本通》p8-9）。*/

	cout<<"例2：标准数据类型，转义字符，常量，符号常量的定义\n";
		cout<<5<<endl;
		cout<<3.1415926<<endl;
		cout<<true<<endl;
		//cout<<"true"<<endl;
		cout<<'a'<<endl;
		//cout<<a<<endl;
		/*由此可见，cout<<后面的表达式可以是文字，也可以是整数、小数等，
			那么true与“true”、a与'a'区别何在？
			原来C++的【标准数据类型primitive types】主要有四类：
			（《一本通》p25-27）
			1. 整型：八进制以0开头，十六进制以0x开头，学会进制换算
			2. 实型：要会写科学记数法
			3. 布尔型（注意把bool单独列出来）：true输出1，false输出0；
			4. 字符型：一般字符都可用单引号括起来如'a'，或者用ASCII码，
				比较特殊的要用转义字符；
	
		【转义字符escape sequence】（《一本通》p27）
			1. 有些字符没法从键盘输入到单引号中间，需要转义字符表示，例如
				'\n' 表示换行；
				'/t' 表示水平制表位vertical tab；
				'\b' 表示退格backspace；
				'\0' 表示空字符null（啥字符也没有）；
			2. 有些字符作用特殊，直接用单引号括起来会被电脑误读，也要用转义字符
				表示，例如：
				'\"' 表示双引号；
				'\'' 表示单引号；
				'\\' 表示反斜杠backslash；
	
		以上几行代码cout后面的表达式均为【常量】（《一本通》p23），分别为
			整型常量、实型常量、布尔常量、字符常量。
		*/
		cout<<endl;
		cout<<(5>3)<<endl;
		cout<<(5<3)<<endl;
	
		cout<<endl;
		const double PI = 3.1415926;
		cout<<PI<<endl;
		/*【符号常量】的定义（《一本通》p23-24）：
			1. 这里我们给实型常量3.1415926起了个名字PI，用符号PI代表它，故称为
				符号常量，符号常量一般用大写字母；
			2. 定义符号常量的写法为：
				const 符号常量 = 常量值； 例如
				const double PI = 3.1415926;
			3. 每个符号常量的定义占据一行，且符号常量不能被再次赋值；
				PI = 3.1; （这是不行的）
			4. 符号常量的好处在于增强了代码的可读性和易改性
		*/
	cout<<endl;

	cout<<"例3：变量，赋值，数据类型转换，运算符，表达式，cin函数\n";
		/*(《一本通》p23例2.5：输入半径r的值，输出圆的周长)
	
		【变量】（《一本通》p24）：
			1. 每个变量都有三个要素：变量的类型，变量的值，变量的名；
			2. 顾名思义，变量的值是可以变的，例如本例的半径r；
			3. 变量的名必须以字母或者下划线_起始，之后可接字母或数字，名字最好
				起的有意义容易理解，长度尽量不要超过8个字符，一般用camelCase以便
				与全部大写的常量区分，在C++语言里大小写是有区别的；
			4. 学会变量的定义：声明与赋值；
			5. 变量的访问：变量被定义之后将在内存中占用一个存储空间，每当用到
				变量时计算机就到对应内存读写数据；
	
		【赋值】（《一本通》p16）
			1. 赋值的写法：
				变量名 = 变量值或表达式；
			2. =是赋值运算符，它表示为左边的变量附上右边的值，不能仅理解为相等，
				也不能反过来写；
			3. 如果右边的值不符合变量类型，系统会进行赋值【数据类型转换】，
				具体规则见《一本通》p28；
	
		【运算符】和【表达式】（《一本通》p18-22），内容有些多，不用马上记
			住，只需要先把例2.4做完即可，其他的随后以及课后作业会练习；
		*/
		char j = 97;
		//赋值数据类型转换，将ASCII编码转为字符（《一本通》p26-27）；
		char k = 'a';
		cout<<j<<endl;
		cout<<k<<endl;
			//上面两行结果是一样的，都是输出字符a；
		j = 97 - 32;
		k = 'a' - 32;
			//上面两行结果也是一样的，都是输出字符A；
		//（《一本通》p27例2.7）
		//运算数据类型转换（规则见《一本通》p28）：将char转化为ASCII码对应的int；
		//赋值数据类型转换：再把int运算结果转化为ASCII码对应的字符；
		cout<<j<<endl;
		cout<<k<<endl;
		//这两位结果是一样的，都是输出字符A；
		cout<<endl;
	
		double r = sqrt(10);
		//cmath头文件，常用的数学库函数见《一本通》p22；
		double s = PI * pow(r, 2);
		cout<<s<<endl; //31.41592
		double r2 = r = 10;
		//注意这样赋值的结果；
		cout<<r<<endl;
		cout<<r2<<endl;
		cout<<endl;
	
		cout<<99/10<<endl;
		//运算数据类型转换；
		cout<<(int)s<<endl;
		//强制数据类型转换；
		cout<<endl;
	
		cin>>r;
		//For convenience, input 10 and the result will be 314.159.
		s = PI * pow(r, 2);
		cout<<s<<endl;
		/*【cin函数】（《一本通》p33-34）
			1. cin是C++的iostream库提供的输如流函数，其用法如下：
				cin>>变量1>>变量2>>变量3...;
				其作用是从键盘读取数据，多个数据之间可用空格、回车、Tab键分隔；
			2. cin>>a>>b; 等同于
				cin>>a;
				cin>>b;
			3.  >>是【流读取运算符】，表示从cin读取数据到各变量。
		*/
		cout<<endl;
		cin>>r>>r2;
		s = PI * pow(r, 2);
		double s2 = PI * pow(r2, 2);
		cout<<s<<"\t"<<s2<<endl<<endl;
	
	cout<<endl;

	cout<<"例4：标准数据类型的存储空间"<<endl;
		//(《一本通》p27例2.6)
		short a;
		int b;
		long c;
		long long d;
		cout<<sizeof(a)<<"\t"<<sizeof(b)<<"\t"<<sizeof(c)<<"\t"<<sizeof(d)<<endl;
		/*
		1. 在不同系统、不同编译下，这几种数据类型的存储空间可能会不一样，所以
			不同教材写的可能有区别；
			http://www.agner.org/optimize/calling_conventions.pdf;
		2. 要注意不同数据类型的变量的取值范围不同，详见《一本通》p25；
		3. 最常用的是int；
		*/
		a = 32768;
		b = 32768;
		cout<<a<<endl<<b<<endl;
	
		float e;
		double f;
		long double g;
		cout<<sizeof(e)<<"\t"<<sizeof(f)<<"\t"<<sizeof(g)<<endl;
		/*
		1. float可以精确到小数点后6-7位，double到小数点后15-16位，long double
			则可能达到19位，这几种也因不同系统、不同编译而不同；
		2. 最常用的是double；
		*/
	
		bool h;
		cout<<sizeof(h)<<endl;
	cout<<endl;

	cout<<"例5. 逆序输出"<<endl;
		//（《一本通》p16例2.1）
		//题意：顺序输入整数a, b, c的值，然后逆序输出c, b, a的值。
		//这是一道典型题目，要交换n个变量的值，我们就需要n+1个变量；
		cin>>a>>b>>c;
		//赋值数据类型转换（之前定义a是short，b是int，c是long，d是long long）；
		d = c;
		c = a;
		a = d;
		cout<<a<<"\t"<<b<<"\t"<<c<<endl;
	cout<<endl; 

	cout<<"例6. 数位逆序输出"<<endl;
		//（《一本通》p39例2.18）
		//题意：输入三位整数（例如123），输出数位逆序的三位整数（例如321）
		cin>>d;
		a = d/100;
		b = (d%100)/10;
		c = d%10;
		d = c*100 + b*10 + a;
		cout<<d<<endl;
	cout<<endl;

	printf("例7：标准I/O，printf函数，scanf函数\n");
		printf("%d\n", 1);
		printf("%d\n", 1.5); //0, 注意小数的%d输出为0
		printf("%4d\n", 1);
		printf("%04d\n", 1);
		printf("%4d\n", 10000);
		printf("%04d\n", 10000);
		printf("\n");
	
		printf("%4d%4d%4d\n", 1, 12, 123);
		printf("%4d%4d%4d\n", 123, 12, 1);
		printf("\n");
	
		printf("%-4d%-4d%-4d\n", 1, 12, 123);
		printf("%-4d%-4d%-4d\n", 123, 12, 1);
		printf("\n");
		/*
		【标准输入输出】也称标准I/O，即直接从键盘输入、从屏幕输出，常调用的
			函数为cin, cout以及scanf, printf
		【printf函数】（《一本通》p35-37）
			1. prinf是C++的cstdio库提供的格式化输出函数，其用法如下：
				printf("格式控制符"，数据或表达式, 数据或表达式, ...);
			2. 【格式控制符】由双引号括起来，由格式说明和普通字符组成，例如
				%d就是格式说明，由%开始，d代表输出的数据格式是十进制整数，
				%4d代表输出4位十进制整数（如果不足4位则用空格占位，多于4位
					则按实际位数输出）；
				%04d代表输出4位十进制整数（如果不足4位则用0占位，多于4位则按
					实际位数输出）；
			3.  如果有多个数据或表达式，在格式控制符里要留出相应数量的格式说明，
				在格式控制符之后要用逗号分隔各个数据或表达式；
			4. 注意整数值不能用%f输出，long double也不能，否则都只会显示0；
				long double用%Lf输出，教材还有其他未尽之处，需参考
				http://www.cplusplus.com/reference/cstdio/printf/
			5. 如要输出百分号，则需"%%"；
		*/
		printf("%f\n", 2); //0.000 000
		printf("%f\n", 2.5); //2.500 000
		printf("%.4f\n", 2.5); //2.5 000
		printf("%05.2f\n", 2.5); //02.50
		printf("\n");
	
		char l[30] = "1234567890123";
		printf("%s\n", l);
		printf("%4s%4s%4s\n", "a", "ab", "abc");
		printf("%-4s%-4s%-4s\n", "a", "ab", "abc");
		printf("\n");
		/*
		1. 注意s格式说明代表输出的数据格式是字符数组（不是字符），需用双引号
			括起来，有关字符数组的更多知识在后面章节学习；
		2. 输入输出字符用scanf("%c", &ch), printf("%c", ch);
		*/
	
		scanf("%d", &a);
		printf("The integer you input is %d.\n", a);
		scanf("%*d%d", &a);
		/*【scanf函数】（《一本通》p34-35）
			1. scanf是C++的cstdio库提供的格式化输入函数，其用法如下：
				scanf("格式控制符", 数据或表达式, 数据或表达式, ...);
			2. 格式控制符和多个数据或表达式的书写格式与printf类似，具体见p34
				值得注意的细节是，double输入用%lf而输出用%f，字符串变量前不用&符号 
			3. 相关细节教材上也有未尽之处，需要参考
				http://www.cplusplus.com/reference/cstdio/scanf/
		*/
	
		printf("The integer you input is %d.\n", a);
		scanf("%d,%d", &a, &b);
		printf("The integers you input are %d and %d.\n", a, b);
		//除非题目或客观情况需要，这种格式控制符容易出错，应该避免；

		/*【对比cin cout和scanf printf】
		1. scanf和printf是C语言就有的，效率比cin cout高很多；
		2. cin cout是C++语言才有的，优点是不需写明变量类型，比较方便；
		3. 本章课后题多有对输出精确度、位数的要求，用printf更佳，cout也有对应
				功能，不过在算法竞赛中属于琐碎内容，就不详细讲述了，可参考
				http://www.cplusplus.com/reference/iomanip/
				http://www.cplusplus.com/reference/ios/
		*/
	printf("\n");
	
	printf("例8：鸡兔同笼\n");
		//(《一本通》p17例2.3)
		//题意：今有雉、兔同笼，上有三十五头，下九十四足。问雉、兔各几何？
		//我们的目的是写一个程序，让用户输入头数和足数，即可输出答案。
		int chick, rabbit, head, foot;
		printf("The number of heads = ");
		scanf("%d", &head);
		printf("The number of feet = ");
		scanf("%d", &foot);
		rabbit = foot / 2 - head;
		chick = head - rabbit;
		printf("There are %d chicken and %d rabbits.\n", chick, rabbit);
	printf("\n");

	printf("例9. 运算优先级：算术、关系、逻辑、赋值\n");
		/*（《一本通》p21-22）
		1. 运算优先级从高到低排序是：
				算术（加减乘除模）
				关系（大于等于小于）
				逻辑（或且非）
				简答赋值；
		2. 运算优先级靠记忆有可能出错，写代码时可用括号体现优先级，应尽量避免冗繁
				嵌套的运算；
		*/
		printf("%d\n", 2*7<15&&3*7>20);
		printf("%d\n", ((2*7)<15) && ((3*7)>20));
	printf("\n");

	printf("例10. getchar函数，putchar函数\n");
		/*（《一本通》p30-31）
		1. getchar()只能接受一个字符（一个字母也按字符处理），多于一个字符时
			只接受第一个
		2. getchar()会把回车当作一个字符输入，所以如果曾在getchar()之前输入
			回车，则需要用一行getchar()接受之前的回车；如果程序中有连续多个
			getchar()，应一次性输入全部所需字符，再按回车；
		3. putchar()功能是输出单个字符数据；
		*/
		getchar();
		j = getchar();
		k = getchar();
		putchar(j);
		putchar(k);
	printf("\n");

	return 0;
}

/*作业：
	1.1编程基础之输入输出(10题) http://noi.openjudge.cn/ch0101/
		选其中5题，需包括：
			05:输出保留12位小数的浮点数
			06:空格分隔输出

	1.2编程基础之变量定义、赋值及转换(10题) http://noi.openjudge.cn/ch0102/
		选其中5题，需包括：
			07:打印ASCII码

	1.3编程基础之算术表达式与顺序执行(20题) http://noi.openjudge.cn/ch0103/
		选其中10题，需包括：
			10:计算并联电阻的阻值
			15:苹果和虫子

	《入门经典》第1章的习题较少且无OJ，可以不做。
*/
