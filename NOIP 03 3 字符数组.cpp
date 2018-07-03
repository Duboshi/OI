/*	@author 杜博识Dubos

NOIP 03.3 字符数组Character Array 
	以《CCF入门篇》第5章5.4节、《CCF基础篇》第2章为主；
	以《一本通》第一部分第5章第三节为辅； 
	以《入门经典》第3章为参考； 
 */
 
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{ 

	printf("例1：字符数组\n");
		/*（《一本通》p97，《CCF入门篇》p221）
		1. 【字符数组】是指元素为字符的数组，也有一维、多维之分，与元素为整数、
			实数的数组的原理相同，但由于字符数组在计算机非数值处理中有重要作用，
			所以单独讲； 
		2. 字符数组的初始化赋值可以用
			int a [2] = {'a', 'b'};
			或者
			int b [2] = {};
			表示赋值为'\0'（空字符null character）。但是不能用
			b = a;
			赋值，会出现编译错误，与之前介绍过的数组是一样的； 
		3. 字符数组与字符串的关系：在C语言中，【字符串】是末尾有空字符作为结束
			字符的字符数组，而字符数组不一定有结束字符，所以，字符串一定是字符
			数组，但字符数组不一定是字符串。我们先讲字符数组，然后再讲字符串；
		4. 下面例子中charArr1和charArr2都是字符串，他们的值是完全相同的， 
			且都比charArr3多一个字符，charArr3则只是一个字符数组而非字符串。
			尤其注意charArr2，避免用字符串给字符数组赋值时造成数组越界； 
		*/
		char charArr1 [5] = {'a','b','c','d','\0'};
		char charArr2 [5] = "abcd";
			//注意charArray2与charArray1相同，比charArray3多一个字符 
		char charArr3 [4] = {'a','b','c','d'};
			//charArray3不是字符串 
		char charMat [3][4] = {"abc","def","ghi"};
			//这个二维数组中有3个字符串，每个字符串含有4个字符（但我们称这些字符
			//串的长度为3）
		printf("%s\n", charArr1);
		printf("%s\n", charArr2);
		printf("%s\n", charArr3);
		/*
		4. 字符数组的输入：
				scanf("%s", charArr3)，注意变量名称前不加&，由于scanf只读入
				，所以想用scanf读入中间有这三种符号间隔的一串字符，就得建立多个
				字符数组。 
				例如想要让计算机读入"Hello, world!"，就需要两个字符数组;
				
				cin也是遇到空格、回车符、tab三种符号就会停止读入，所以也要建立
				多个字符数组；
				
				如果想要把从键盘输入的中间有空格的一串字符（例如一句话）存储在
				一个字符数组里面，就需要用getchar()函数，NOIP 01 Introdution中
				曾经介绍过：
				
					getchar()只能接受一个字符（一个字母也按字符处理），多于
						一个字符时只接受第一个； 
					getchar()会把回车当作一个字符输入，所以如果曾在getchar()
						之前输入回车，则需要用一行getchar()接受之前的回车；
						如果程序中有连续多个getchar()，应一次性输入全部所需字符，
						再按回车；
					putchar()功能是输出单个字符数据；
		*/
		char charArr4 [10];
		char charArr5 [10]; 
		scanf("%s %s", charArr4, charArr5);
		printf("%s %s\n", charArr4, charArr5);
		
		cin>>charArr4>>charArr5;
		cout<<charArr4<<" "<<charArr5<<endl;
		
		/*
		5. 重温char与int的相互转换，这是在NOIP 01里面讲过 
		*/
		char c = 97;
			//赋值数据类型转换，将ASCII编码转为字符（《一本通》p26-27）；
		char d = 'a';
		cout<<c<<endl;
		cout<<d<<endl;
			//上面两行结果是一样的，都是输出字符a；
		c = 97 - 32;
		d = 'a' - 32;
		cout<<c<<endl;
		cout<<d<<endl;
		 	//上面两行结果也是一样的，都是输出字符A；
	printf("\n");
		
	printf("例3：字符数组的应用 - Palindrome（回文词）\n");
		/*《CCF入门篇》p220例5.18，《一本通》p94例5.12，《入门经典》p48 (UVa401)
			一个词，如果从左向右读和从右向左读完全相同，就是回文词。
			输入：一串字符（不超过10位） 
			样例：LEVEL
			输出：是则输出YES，否则输出NO
			样例：YES
		*/
		char charArr [100] = {};		
		int i, length=0;
		bool check=true;
		
		//先读入一个词 
		scanf("%s", charArr);
		
		//求出输入词的长度
		for (i=0; i<100; i++)
			if (charArr[i] != '\0')
				length++;
		
		//看看长度有否算对 
		//cout<<length<<endl;
		
		//开始检查
		for (i=0; i<length/2; i++)
			if (charArr[i] != charArr[length-1-i])
			{
				check=false;
				break;
			}
		
		//输出结果 
		if (check)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	printf("\n");
	getchar();//下道题用getchar()函数，这里先把之前输入的回车吃掉 

	printf("例4：字符数组的应用 - 替换功能\n");
		/*《CCF入门篇》p223例5.21，《一本通》p100例5.15
			输入：	两行，第一话为一句话（不超过100字符），第二行为两个字符，将
					首字符替换为尾字符 
			样例：	Oh baby, you know I love U so much.
					I U 
			输出：	一行，为替换后的结果
			样例：	Oh baby, you know U love U so much. 
			
		不像回文词只需输入一个词，这道题要考虑如何处理这句话的输入与存储。 
		*/
		char a, b;
		length=0;
		
		//输入第一行的一句话 
		while ( (charArr[length++]=getchar() ) != '\n');
		length--; //因为上面那行length计算时包含了最后的回车 
		
		//看看长度有否算对
		//printf("%d\n", length);
		 
		a = getchar();
		getchar();
		b = getchar(); 
		getchar();
		
		//替换并输出 
		for (i=0; i<length; i++)
		{
			if (charArr[i] == a)
				printf("%c", b);
			else
				printf("%c", charArr[i]);
		}
		printf("\n");
	printf("\n");
	
	printf("例4：字符数组的应用 - 搜索最长单词\n");
		/*（《CCF入门篇》p225例5.22） 
			输入：一句话，不含标点符号（不超过100个字符）
			样例：I love you
			输出：上句话中最长的词，空格，该词的长度
			样例：love 4
		*/
		
		int sizeOfWord=0, max=0, index=0;
		length=0; 
			//分别代表当前这个词的长度，最长词的长度，最长次的起始位置序号 
		
		//输入一句话，并计算这句话所包含字符的数量 
		while ( (charArr[length++]=getchar() ) != '\n');
		length--;
		
		//看看长度有否算对
		//printf("%d\n", length);
		
		//查找最长的词，并记录其长度 
		for (i=0; i<length+1; i++)
			//+1是为了包含最后的回车，否则如果最长的词在最后的话就没法计算 
		{
			if (charArr[i]!=' ' && charArr[i]!='\n')
				sizeOfWord++;
			else
			{
				if (sizeOfWord>max)
				{
					max = sizeOfWord;
					index = i - sizeOfWord;
				}
				sizeOfWord=0;
			}
		}
			
		//输出
		for (i=index; i<index+max; i++)
			printf("%c", charArr[i]);
		printf(" ");
		printf("%d\n", max);	
	printf("\n");
	
	printf("例5：字符数组的应用 - 加法计算器\n");
		/*(《CCF入门篇》p226例5.23）
			输入：任意两个整数（最多可以是九位整数）的加法表达式，中间有加号，
				不含空格
			样例：11+23 
			输出：结果 
			样例：34
		
		这道题输入的是字符，而输出的却是整数。另外，本题只能处理int取值范围内
		(-2^31=-2,147,483,648, 2^31-1=2,147,483,647)
		的整数加法，如果超出范围的话，就要用到后面介绍的高精度计算。 
		*/
		int size1=0, size2=0, power=1;
		length=0; a=0; b=0;
		
		//输入加法表达式，并计算表达式包含字符的数量 
		while ( (charArr[length++]=getchar() ) != '\n');
		length--; //不包含最后的回车 
		
		//看看长度有否算对
		//printf("%d\n", length);
		
		//判断第1个整数的位数size1，进而求出第2个整数的位数size2 
		for (i=0; i<length; i++)
		{
			if (charArr[i]!='+')
				size1++;
			else
				break;
				
		}
		size2 = length-1-size1;
		
		//看看size1有否算对
		//printf("%d\n", size1); 
		
		//算出第1个整数的值，赋值给a
		for (i=size1-1; i>=0; i--)
		{
			a += (charArr[i]-'0') * power;
			power *= 10;
		}
		power = 1;
		
		//算出第2个整数的值，赋值给b
		for (i=length-1; i>=length-size2; i--)
		{
			b += (charArr[i]-'0') * power;
			power *= 10;
		}
		
		//输出
		printf("%d\n", a+b);	
	printf("\n");
	
	return 0;
}

/*	作业：
		没有题目单独考查字符数组，学习完字符串之后才能做作业。 
*/
