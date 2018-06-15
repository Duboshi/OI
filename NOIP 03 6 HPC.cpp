/*	@author 杜博识Dubos

NOIP 03.6 高精度计算 High Precision Computation
	（也称为“大整数计算”） 
	以《CCF基础篇》第7.2节为主；
	以《程序设计导引及在线实践》第7章为辅；
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
int num1[205], num2[205], temp[205], result[205], len_num1, len_num2, len_result, i;
string s1, s2;

/*	不要从这里开始读，从例0开始，读到例1就会明白这里assign函数的作用。 
 
	assign函数把两个输入的大整数按数位逆序写入数组，个位在num1[0]、num2[0]，
	十位在num1[1]、num2[1]...
	
	参数用数组指针和整数引用是为了可以改变函数外的数组值和整数值，如果直接用数组
	和整数做参数，则函数以外的数组和整数值不会受到影响。 */
void assign (int *num, int &len)
{
	int i; //数组序号
 	string s;
	cin >> s;
	len = s.length();
	for (i=0; i<len; i++)
		num[i] = s[i] - '0';
	reverse(num, num+len); //algorithms库函数，把数组前len位元素逆序 
}

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
		//把两个输入的大整数逆序储存在数组里，这段代码在大整数减法、乘法、除法里
		//面还要用，所以我们建立了函数assign，后面的例题就不用重复写了 
		string s1, s2;
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
				temp[i+1] = result[i]/10;
				result[i] = result[i]%10;
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
		int i; //数组序号
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
		解题思路：笔算多位数乘法，琢磨规律之后再用代码模拟 
		解题代码：https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的011309号题目 */ 
		
		int j; //数组序号, 还有i但是上面建立过了 
		assign(num1, len_num1);
		assign(num2, len_num2); //将输入的两个大整数存入数组
		
		len_result = len_num1 + len_num2 - 1;
		
		for (i=0; i<len_num1; i++) //计算result数组各个数位的值，但不进位 
			for (j=0; j<len_num2; j++)
				result[i+j] += num1[i] * num2[j];
				
		for (i=0; i<len_result; i++) //进位 
		{
			if (result[i]>9) 
			{
				result[i+1] += result[i]/10;
				result[i] %= 10;
			}
		}
		
		while (result[len_result]) //消除前导0，并至少保留1位 
			len_result++;
		
		for (i=len_result-1; i>=0; i--) //输出结果 
			cout<<result[i];
	printf("\n\n");

	printf("例4：大整数除法\n");
		/*（《CCF基础篇》P176例7.4，《程序设计导引及在线实践》P141例7.3，
			《信息学奥赛一本通》P186例1.5，
			在线测评 - http://noi.openjudge.cn/ch0113/47/）
			
		问题描述：求两个不超过200位的非负整数之商（不用管余数） 
		输入数据：两行，每行是一个不超过200位的非负整数，正整数不能以0开始
		输出数据：一行，即结果，正整数不能以0开始
		解题思路：笔算整数除法，步骤较多，【未完成】
		解题代码：https://github.com/Duboshi/OJ-solutions/tree/master/noi.openjudge.cn
			中的011347题目 */
	printf("\n");
	return 0;
}
