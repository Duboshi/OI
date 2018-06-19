/*	@author 杜博识Dubos

NOIP 03.6 高精度计算 High Precision Computation
	（也称为“大整数计算”） 
	以《CCF基础篇》第7.2节为主；
	以《 程序设计导引及在线实践》第7章为辅；
	以《信息学奥赛一本通》第二部分第1章为参考； 
	另外《算法竞赛入门经典》第5.3节运用结构体建立了大整数类，但不是高精度算法。
	
	这一节需要指针、引用和函数的知识。如果不具备这些知识，可以暂时略过本节，之后
	回头再看。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;
int num1[205], num2[205], temp[205], result[205], result2[410], len_num1, len_num2, len_result;
string s1, s2;

/*这些是下面各个例题中将会调用的函数，请从main函数的例0开始读，然后就会明白这些
函数的作用。当main要调用这些函数时，在main之前必须要有这些函数的声明，而函数体
由于内容繁杂，放在main之前显得喧宾夺主，为方便同学阅读我们把函数体写在了main函数体
之后，所以需要阅读各个函数体时请到main之后找。 */ 
void assign (int *num, int &len);
void assign2(int *num, int &len);
void newTemp(int i);
bool noSmallThan();
void bigMinus(); 

int main() {
	printf("例0：高精度算法简介\n");
		/*C++语言的数据类型所能表达的最大整数就是
		2^64 - 1 = 18,446,744,073,709,551,615
		这是一个20位数。这是unsigned long long（无符号64位整型）数据类型的最大值，
		如何显示出这个值呢？
			1. 可以建立一个unsigned long long变量并赋值为-1，对于无符号整型变量，
				-1就会直接被转化为最大值；
			2. 调用climits头文件，这个头文件（确切讲是limits.h头文件）中定义了
				常数_UI64_MAX为unsigned long long的最大值。显然我们不太可能记得住
				这个头文件里各种数据类型最大值、最小值的名字，但是只要我们记得这个
				头文件climits，需要用的时候就可以去头文件里自己找所需要的值； 
		*/
		unsigned long long big = -1; 
		cout<<big<<endl;
		cout<<_UI64_MAX<<endl;
		/*有时候20位数是不够用的，所以我们需要引入其他方法来处理更大整数的计算。
		C++标准模板库STL里面的所有函数和类我们在信息学竞赛中都可以使用，但里面却 
		没有专门处理高精度计算的功能，微软公司开发的.NET Framework里面有处理
		高精度计算的BigInteger Structure，但是我们在比赛里不能直接用；
		其他语言例如Java的标准库有Class BigInteger，但国内中学信息学竞赛不支持
		Java语言。
		
		所以下面我们使用C++（包含STL）来实现大整数的加、减、乘、除运算。 */
	printf("\n");
	
	printf("例1：大整数加法\n");
		/*（《CCF基础篇》P172例7.1，《程序设计导引及在线实践》P136例7.1，
			《信息学奥赛一本通》P181例1.1
			在线测评 - http://noi.openjudge.cn/ch0106/10/）
			
		问题描述：求两个不超过200位的非负整数之和
		输入数据：两行，每行是一个不超过200位的非负整数，正整数不能以0开始 
		输出数据：一行，即结果，正整数不能以0开始
		解题思路：
			大整数加法是典型的数组应用，我们需要四个数组处理两个大整数的加法：
				两个数组int a1 [205]和int b1 [205]来存储加数和被加数；
				一个数组int c1 [205]存储进位情况，
				一个数组int result1 [205]存储结果。 
			例如123 + 678 = 801，我们赋值a = {3, 2, 1, 0...}, b = {8, 7, 6, 0...},
			注意赋值顺序是个位、十位、百位...这样子可以保证数位对齐，并且计算
			进位时不出差错。根据相加情况，c = {0, 1, 1, 0...}，表示个位无需进位、
			十位进位1、百位进位1、千位及以上无进位，然后 
				result[i] = a[i] + b[i] + c[i];
			并且result中任何两位数的元素都只保留个位。最后输出结果，输出时
			尤其需要注意0+0的情况，如果不特殊注意，这种情况可能无输出。 
		解答代码：
			https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的010610号题目，这里列出的相当于解法一（基于string和数组），另有
			解法二（基于cstring和数组），本质思想是一样的。 
			*/
		//把两个输入的大整数按数位逆序储存在数组里，这段代码在这一节里反复使用， 
		//所以我们建立了函数assign，后面的例题就不用重复写了
		string s1, s2;
		int i, j; //数组序号 
		cin >> s1;
		len_num1 = s1.length();
		for (i=0; i<len_num1; i++) num1[i] = s1[i] - '0';
		reverse(num1, num1+len_num1); //algorithms库函数，把数组前len_num1位元素逆序
	
		cin >> s2;
		len_num2 = s2.length();
		for (i=0; i<len_num2; i++) num2[i] = s2[i] - '0';
		reverse(num2, num2+len_num2);
		
		len_result = max(len_num1, len_num2) + 1; //和的位数要足够大 
		
		for (i=0; i<len_result; i++) //把result数组各个数位的值填对 
		{
			result[i] = num1[i] + num2[i] + temp[i];
			if (result[i]>9)
			{
				temp[i+1] += result[i]/10;
				result[i] %= 10;
			}
		}
		while (result[len_result-1]==0 && len_result>1) //消除前导0，并至少保留1位 
			len_result--;
		
		for (i=len_result-1; i>=0; i--) //输出结果 
			cout<<result[i]; 
	printf("\n\n"); 
	
	s1.clear(); s2.clear();
	memset(num1, 0, 205); memset(num2, 0, 205); memset(temp, 0, 205); memset(result, 0, 205);

	printf("例2：大整数减法\n");
		/*《CCF基础篇》P174例7.2，《信息学奥赛一本通》P183例1.2
			在线测评 - http://noi.openjudge.cn/ch0106/11/
		
		问题描述：求两个不超过200位的非负整数之差 
		输入数据：两行，每行是一个不超过200位的非负整数，正整数不能以0开始，
			前一个数大于等于第二个数 
		输出数据：一行，即结果，正整数不能以0开始
		解题思路：跟加法非常相似
		解题代码：https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的010611号题目，这里列出的相当于解法一（基于string和数组），另有
			解法二（基于cstring和数组），两者本质思想是一样的。 */ 
//		int i, j; //数组序号
		assign(num1, len_num1);
		assign(num2, len_num2);
		
		len_result = max(len_num1, len_num2); //algorithm库函数 
		
		for (i=0; i<len_result; i++) //把result数组各个数位的值填对 
		{
			result[i] = num1[i] - num2[i] + temp[i];
			if (result[i]<0)
			{
				temp[i+1]--;
				result[i]+=10;
			}
		}
		while (result[len_result-1]==0 && len_result>1) //消除前导0，并至少保留1位 
			len_result--;
		
		for (i=len_result-1; i>=0; i--) //输出结果 
			cout<<result[i]; 
	printf("\n\n"); 
	
	s1.clear(); s2.clear();
	memset(num1, 0, 205); memset(num2, 0, 205); memset(temp, 0, 205); memset(result, 0, 205);

	printf("例3：大整数乘法\n");
		/*（《CCF基础篇》P174例7.3，《程序设计导引及在线实践》P138例7.2，
			《信息学奥赛一本通》P184例1.3
			在线测评 - http://noi.openjudge.cn/ch0113/09/） 
		
		问题描述：求两个不超过200位的非负整数之乘积 
		输入数据：两行，每行是一个不超过200位的非负整数，正整数不能以0开始
		输出数据：一行，即结果，正整数不能以0开始
		解题思路：先笔算多位数乘以一位数，把结果的各个数位用方框画出来，计算时
			不要进位，这样结果有的数位会是两位数，把各个两位数填入对应数位，再进位；
			然后笔算多位数乘以多位数，同样先计算，填框，后进位。摸清过程之后用代码
			实现 
		解题代码：https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的011309号题目 */
		
//		int i, j; //数组序号
		assign(num1, len_num1);
		assign(num2, len_num2); //将输入的两个大整数存入数组
		
		len_result = len_num1 + len_num2; //这里要用result2，因为result只有205位可能不够用 
		
		for (i=0; i<len_num1; i++) //计算result数组各个数位的值，但不进位 
			for (j=0; j<len_num2; j++)
				result2[i+j] += num1[i] * num2[j];
				
		for (i=0; i<len_result; i++) //进位
		{
			if (result2[i]>9) 
			{
				result2[i+1] += result2[i]/10;
				result2[i] %= 10;
			}
		}
			
		while (result2[len_result-1]==0 && len_result>1) //消除前导0，并至少保留1位 
			len_result--;
			
		for (i=len_result-1; i>=0; i--) //输出结果 
			cout<<result2[i];
	printf("\n\n");
	
	s1.clear(); s2.clear();
	memset(num1, 0, 205); memset(num2, 0, 205); /*memset(temp, 0, 205);*/ memset(result2, 0, 205);

	printf("例4：大整数除法\n");
		/*（《CCF基础篇》P176例7.4，《程序设计导引及在线实践》P141例7.3，
			《信息学奥赛一本通》P186例1.5，
			在线测评 - http://noi.openjudge.cn/ch0113/47/）
			
		问题描述：求两个不超过200位的非负整数之商（不用管余数） 
		输入数据：两行，每行是一个不超过200位的非负整数，正整数不能以0开始
		输出数据：两行，第一行商，第二行余数，正整数不能以0开始
		解题思路：笔算整数除法，这个比较复杂，请看示意图 - https://github.com/Duboshi/NOIP
			上述文件夹里面的NOIP 03.6 高精度计算 除法.pdf
		解题代码：https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的011347题目 */
			
//		int i, j;	//数组序号，下面常用
		
		//将大整数存入num1和num2数组，各数组第0序号元素用于储存位数，第1位开始存储个位、十位、百位...
		assign2(num1, len_num1);
		assign2(num2, len_num2);
		
		//从被除数的最高位开始，逐位求商
		for (i=len_num1; i>=1; i--) 
			{
				//temp(i) = temp(i+1)*10 + num1[i];
				//大整数乘以10，以及大整数加一位整数，用newTemp函数实现
				newTemp(i);
				
//				//检验新余数temp
//				cout<<"temp: ";
//				for (j=temp[0]; j>=1; j--)
//					cout<<temp[j];
//				cout<<endl;
				
				//result[i] = temp(i)/num2; temp[i] %= num2;
				//需要反复用大整数减法minus()实现：只要temp(i)不小于num2就一直temp(i) -= num2，另外每减一次result[i]都加一 
				while (noSmallThan()) //用noSmallThan函数判断temp(i)是否不小于num2
				{
					bigMinus();
//						//检验bigMinus: 
//						cout<<"temp: ";
//						for (j=temp[0]; j>=1; j--)
//							cout<<temp[j];
//						cout<<endl;
					result[i]++;
				}
				
//				//检验每位运算后商数
//				cout<<"result: ";
//				for (j=num1[0]; j>=1; j--)
//					cout<<result[j];
//				cout<<endl;
				
//				//检验运算后余数 
//				cout<<"temp: ";
//				for (j=temp[0]; j>=1; j--)
//					cout<<temp[j];
//				cout<<endl<<endl;
			}
		
		//输出商
		if (num1[0]<num2[0]) result[0]=1; 
		else result[0] = num1[0]-num2[0]+1; //result最多有这么多位数：num1[0]-num2[0]+1
		while (result[result[0]]==0 && result[0]>1)
			result[0]--; //使result[0]显示确切的位数 
		for (i=result[0]; i>=1; i--) 
				cout<<result[i];
				
		//输出余数 
	printf("\n");
	
	return 0;
}

void assign (int *num, int &len)
{/*assign函数把两个输入的大整数按数位逆序写入数组，个位在num1[0]、num2[0]，
十位在num1[1]、num2[1]...此函数用于大整数加、减、乘法运算，在除法中我们要用第0号
元素记录数组有效长度，所以使用assign2函数

参数用数组指针和整数引用是为了可以改变函数外的数组值和整数值，如果直接用数组
和整数做参数，则函数以外的数组和整数值不会受到影响。 */
	int i; //数组序号
 	string s;
	cin >> s;
	len = s.length();
	for (i=0; i<len; i++)
		num[i] = s[i] - '0';
	reverse(num, num+len); //algorithms库函数，把数组前len位元素逆序
}

void assign2(int *num, int &len)
{
	string s;
	cin >> s;
	len = s.length();
	for (int i=len; i>=1; i--)
		//s: 	0, 1, ... len-1; 依次存入 
		//num:	len, len-1, ... 2, 1. 
		num[i] = s[len-i] - '0';
	num[0] = len; //num1和num2的序号0元素都用于存储各自的位数，这个数字在这个问题中常用
}

void newTemp(int i)
{/*这个函数要得到的效果是：
	temp(i) = temp(i+1)*10 + num1[i]
	其中temp(i)指计算到num1[i]时的余数，而它是大整数，我们用temp数组处理它的
	乘10和加一位整数运算。
	 
最初计算到num1[len1]时，余数最多有1位，我们用temp[1]储存；
随后计算到num1[len1-1]时，余数最多有2位，我们用temp[1]至temp[2]储存；
... 
之后计算到num1[i+1]时，余数最多有len1-i位，我们用temp[1]至temp[len1-i]储存； 
所以计算到num1[i]位时，余数最多有len1+1-i位，我们用temp[1]至temp[len1+1-i]储存。

如何储存呢？ 
只需把前一步得到的余数temp[1]至temp[len1-i]挪到temp[2]至temp[len1+1-i]，并将
temp[1]赋值为num1[i]即可。

函数参数：int *temp用数组指针可以改变原数组的值，用int i不会改变原i的值。 */
	for (int j=len_num1-i; j>=1; j--)
		temp[j+1] = temp[j];
	temp[1] = num1[i];	
	temp[0]++;
	while (temp[0]>1 && temp[temp[0]]==0) temp[0]--; //记录temp位数可能发生的变化 
}

bool noSmallThan()
{/*这个函数用于判断temp所储存的大整数是否大于等于num2所储存的大整数，判断过程如下：
	如果 (temp位数 < num2位数)，return false;
	如果 (temp位数 > num2位数)，return true;
	如果 (temp位数 = num2位数)，从最高位开始比较，至第一个不同的数字得出结果； 
	return true;	
*/
	
	if (temp[0]<num2[0]) return false;
	if (temp[0]>num2[0]) return true;
	
	int i;
	for (i=temp[0]; i>=1; i--)
	{
		if (temp[i]<num2[i]) return false;
		if (temp[i]>num2[i]) return true;
	}
	return true;
}

void bigMinus()
{/*这个函数用于实现temp所储存的大整数减去num2所储存的大整数，并记录temp位数变化情况*/
	for (int i=1; i<=num2[0]; i++)
	{
		temp[i] -= num2[i];
		if (temp[i]<0)
		{
			temp[i] += 10;
			temp[i+1]--;
		}
	}
	while (temp[0]>1 && temp[temp[0]]==0) temp[0]--; //记录temp位数可能发生的变化 
}

/*	作业：
		1.6编程基础之一维数组 http://noi.openjudge.cn/ch0106/
		1.13编程基础之综合应用 http://noi.openjudge.cn/ch0113/
		其中涉及大整数计算（例如多达100位的整数，2的100次幂等等）的题目 
*/
