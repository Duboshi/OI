/*	@author 杜博识Dubos

NOIP 02. 程序的控制结构 Flow control 
	以《一本通》第3、4章为主；
	以《入门经典》第1、2章为辅（这两章写的简略、用C语言、没有OJ题目）；
	以《CCF入门篇》第3、4章为参考；
	
	程序的控制结构可以分成3种（《一本通》p43）：
	1. 【顺序结构】：默认情况下计算机总是按照顺序逐行逐条执行代码，上一章里
		已经讲过了 ； 
	2. 【选择结构】（或称为【分支结构】）：面对不同情况要执行不同命令时，可
		用if语句、if-else语句和switch语句实现；
	3. 【循环结构】：有的代码需要重复执行多次，但不需要重复写多次，可用for
		语句、while语句和do-while语句实现；
 */

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	printf("NOIP 02. 程序的控制结构\n\n");
	
	printf("例1：选择结构 - if语句（输入一个数，判断是否大于1且小于100）\n");
		//（《一本通》p44例3.2：读入一个整数，若其大于1且小于100，则输出yes） 
		int a;
		scanf("%d", &a);
		if (a>1 && a<100)
			printf("yes\n");
		/*【if语句】的写法是：
			
			if(条件表达式)
			{
				语句1;
				语句2;
				... 
			} 
			
		其功能是如果条件表达式的值为真，则{}里面的语句将被执行，否则{}里面的
		语句都将被忽略。{}里若只有一个语句，则{}可以省略。 
		 */
		printf("\n"); 
	
	printf("例2：选择结构 - if语句的应用（三个整数由大到小排序）\n");
		/*（《一本通》p45例3.3：输入三个整数，按从大到小顺序输出，中间以空格分隔）
		这题有很多种解法，我们在这里是为了应用if语句，思路是：
		先将a与b相比，将相对较大值赋予a，较小值赋予b；
		再将新a与c相比，将相对较大值赋予a，较小值赋予c，此时a已经是最大的了；
		最后将新b与新c相比，将相对较大值赋予b，较小值赋予c，排序完成。
		*/
		int b, c, temp;
		scanf("%d%d%d", &a, &b, &c);
		if (a<b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		if (a<c)
		{
			temp = a;
			a = c;
			c = temp;
		}
		if (b<c)
		{
			temp = b;
			b = c;
			c = temp;
		}
		printf("%d %d %d\n", a, b, c);
		printf("\n");
		
	printf("例3：选择结构 - if-else语句（输入一个数，判断是否大于1且小于100）\n");
		//(例1稍作改动：读入一个整数，若其大于1且小于100则输出yes，否则输出no)
		cin>>a;
		if (a>1 && a<100)
			printf("yes\n");
		else
			printf("no\n");
		/*【if-else语句】的写法是：
			
			if(条件表达式)
			{
				语句a1;
				语句a2;
				... 
			}
			else
			{
				语句b1;
				语句b2;
				... 
			}
			
		其功能是如果条件表达式的值为真，则语句a1、a2...将被执行，否则语句b1、
		b2...将被执行。{}里若只有一个语句，则{}可以省略。
		 */
		printf("\n");
	
	printf("例4：选择结构 - if-else语句的嵌套（输出三个数中最大的）\n");
		//（《一本通》p47例3.5：输入三个数，输出其中最大的数）
		cin >> a >> b >> c;
		if (a>b && a>c)
			temp = a;
		else
			if (b>a && b>c)
				temp = b;
			else
				temp = c;
		printf("%d\n", temp);
		//以上是教材的解答，但是有错误（比如输入5 5 1会输出1），应该怎么改正？
		//当if-else语句嵌套时，else总是与其前面最近的一个if配对。
		printf("\n");
	
	printf("例5：选择结构 - 三目运算符（输出三个数中最大的）\n");
		 /*（《一本通》p49，【三目运算符】的写法是： 
		 	x = condition? a:b
		 	
		其功能等同于：
			if (condition)
				x = a;
			else
				x = b;
		试用三目运算符求解上个例题。 
		*/
		a = a>b? a:b;
		b = b>c? b:c;
		temp = a>b? a:b;
		printf("%d\n", temp); 
		printf("\n");
		
	printf("例6：选择结构 - switch语句，break语句（星期几）\n");
		//（《一本通》p52例3.9：输入1-7中一个数，输入是几就输出星期几，周一至
		//周五之后显示weekday，周六周日显示weekend）
		int n;
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				printf("Monday");
				break;
			case 2:
				printf("Tuesday");
				break;
			case 3:
				printf("Wednesday");
				break;
			case 4:
				printf("Thursday");
				break;
			case 5:
				printf("Friday");
				break;
			case 6:
				printf("Saturday");
				break;
			case 7:
				printf("Sunday");
				break;
			default:
				printf("Input error\n");
		}
		switch(n)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				printf(" weekday\n");
				break;
			case 6:
			case 7:
				printf(" weekend\n");
				break;
		}
		/* The typical syntax of【switch statment】 is:
		 
			switch (expression)
			{
				case constant1:
			    	group-of-statements-1;
			    	break;
				case constant2:
			    	group-of-statements-2;
				break;
				...
			  	default:
			    	default-group-of-statements
			}
		     
		switch evaluates expression and checks if it is equivalent to constant1;
		if it is, it executes group-of-statements-1 until it finds the 【break
		statement】 and then jumps to the end of the entire switch statement. 

		If expression was not equal to constant1, it is then checked against
		constant2. If it is equal to this, it executes group-of-statements-2
		until a break is found, when it jumps to the end of the switch.

		Finally, if the value of expression did not match any of the previously
		specified constants (there may be any number of these), the program
		executes the statements included after the default.
		
		注意：
		1. expression和各个constant都将被看作整型数据作比较，所以它们可以是
			整型、字符或者实型；
		2. switch语句可以有多个case和最多一个default
		3. 各case中的constant值不能相同，但各case后面的语句群内容可以相同，这时
			可将多条case列在语句群之前，表示这些case执行的语句群是相同的； 
		4. default可以没有，如果有的话最多有一个，default的语句不需要break，因为
			default已经在switch语句末尾了； 
		5. case和default后面的语句群，都可以不使用{}； 
		*/
		printf("\n");
	
	printf("例7：选择结构 - switch语句的应用（两个数的加减乘除）\n"); 
		//（《一本通》p53例3.10：输入两个数的加减乘除，中间用空格分隔，例如
		//100 / 25，输出结果；
		
		double x, y;
		char op;
		cin >> x >> op >> y;
		switch(op)
		{
			case '+':
				printf("%f\n", x + y);
				break; 
			case '-':
				printf("%f\n", x - y);
				break;
			case '*':
				printf("%f\n", x * y);
				break;
			case '/':
				if (y == 0)
					printf("The divisor cannot be zero.\n");
				else
					printf("%f\n", x / y);
				break;
			default:
				printf("Invalid operator!\n");
		}
		printf("\n"); 
	
	printf("例8：循环结构 - for语句（求和：1 + 2 + ... + 100 =）\n");
		//（《一本通》p57例4.1）
		int sum = 0;
		for(int i = 1; i <= 100; i++)
			sum += i;
		printf("%d\n", sum);
		printf("\n");
		/*
		The syntax of 【for loop】 is:

		for (initialization; condition; update)
		{
		group-of-statements;
		}
		
		1. Step 1: initialization executed. Generally, this declares a counter
			variable, and sets it to some initial value. This is executed a
			single time, at the beginning of the loop.
		2. Step 2: condition checked: If it is true, the loop continues;
			otherwise, the loop ends, and statement is skipped, going directly
			to step 5.
		3. Step 3: statement executed: As usual, it can be either a singl
			statement or a block enclosed in curly braces { }.
		4. Step 4: update executed and the loop gets back to step 2.
		5. Step 5: the loop ends.
		6. The three fields in a for-loop are optional. They can be left empty,
			but in all cases the semicolon signs between them are required.
		*/ 
	
	printf("例9：循环结构 - for语句的应用（求和：求1至n所有奇数和、偶数和）\n");
		//（《一本通》p57例4.3）
		int sumOdd = 0, sumEven = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			if(i%2 == 1)
				sumOdd += i;
			else
				sumEven += i;
		}
		printf("%d %d\n", sumOdd, sumEven);
		printf("\n");
		
	printf("例10：循环结构 - for语句的应用（阶乘）\n");
		//（《一本通》p59例4.4，输入int整数n，输出long long整数n!）
		int m;
		int fac1 = 1;
		long long fac2 = 1;
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
			{
				fac1 *= i;
				fac2 *= i;
			}
		printf("%lld\n%lld\n", fac1, fac2);
		//fac1能够计算到12!，而fac2能够计算到20!
		printf("\n");
			
	printf("例11：循环结构 - while语句（前多少个正整数的和刚好不超过1000？）\n");
		//（《一本通》p61例4.5）
		n = 0, sum = 0;
		while(sum <= 1000)
		{
			n++;
			sum += n;	
		}
		printf("%d\n", n-1);
		/*The typical syntax of【while loop】 is:
			
			while(condition)
			{
				group-of-statements
			}
		
		1. The while-loop simply repeats statement while expression is true.
		2. If there are more than one statements in expression, only the last
			statement will be checked.
		3. If, after any execution of statement, expression is no longer true,
			the loop ends, and the program continues right after the loop.
		*/
		printf("\n");
		
	printf("例12：循环结构 - while语句的应用（欧几里德算法）\n");	
		/*（《一本通》p62例4.6，输入两个整数，输出最大公约数）
		The Euclidean algorithm（辗转相除法）relies on the following theorem:
			for any nonnegative integer a and any positive integer b,
			gcd(a, b) = gcd(b, a mod b)
		
		To prove this theorem, we need to show that:
			gcd(a, b) | gcd(b, a mod b) and
			gcd(b, a mod b) | gcd(a, b)
		Two positive integers dividing each other must be equal.
			
		The detailed proof of the theorem can be found in:
			CLRS 2009, Introduction to Algorithms 3rd ed. p934
			K. Rosen 2012, Discrete Mathematics and Its Applications, 7th ed. p268
		
		Calculate gcd(300, 12) and gcd(300, 72) by hand to practice.
		*/
		cin >> a >> b;
		int r = a % b;
		while(r)
		{
			a = b;
			b = r;
			r = a % b;
		}
		printf("%d\n", b);
		printf("\n");
	
	printf("例13：循环结构 - do-while语句（欧几里德算法）\n");
		//（《一本通》p67例4.9：用do-while语句实现欧几里德算法）
		cin >> a >> b;
		do
		{
			r = a % b;
			a = b;
			b = r;
		}
		while(r != 0);
		printf("%d\n", a);
		/*The typical snytax of 【do-while lopp】 is:
		
			do
			{
				group-of-statements
			}
			while(condition);
			
		It behaves like a while-loop, except that condition is evaluated after
		the execution of statement instead of before, guaranteeing at least one
		execution of statement, even if condition is never fulfilled. 
		*/
		printf("\n");
	
	printf("例14：循环嵌套（输出1至10的阶乘之和）\n");
		//（《一本通》p70例4.12）
		
		//最直接的做法是： 
		sum = 0; 
		for(int i = 1; i <= 10; i++)
		{	
			int fac = 1;
			for(int j = 1; j <= i; j++)
				fac *= j;
			sum += fac;
		}
		printf("%d\n", sum);
		
		//上面的做法要进行65次循环，我们可以改进以下，需要10次循环： 
		sum = 0;
		int fac = 1;
		for(int i = 1; i <=10; i++)
		{
			fac *= i;
			sum += fac;
		}
		printf("%d\n", sum);
	printf("\n");
	
	printf("例15：循环嵌套（水仙花数）\n");
		//（《一本通》p73例4.15：若三位数abc = a^3 + b^3 + c^3则ABC为水仙花数，
		//输出全部水仙花数，中间用空格分隔）
		for(int a = 1; a <= 9; a++)
			for(int b = 0; b <=9; b++)
				for(int c = 0; c <=9; c++)
				{
					if(a*a*a + b*b*b + c*c*c == a*100 + b*10 + c)
					printf("%d ", a*100 + b*10 + c);
				}
				printf("\n");
	printf("\n");
	

	printf("例16：循环嵌套，continue语句（aabb完全平方数）\n"); 
		//（《一本通》p74例4.17：输入所有形如aabb的四位完全平方数） 
		for(int i = 1; ; i++)
		{
			int n = i*i;
			if(n<1000)
				continue;
				/*The 【continue statement】 causes the program to skip the rest
				of the loop in the current iteration, as if the end of the
				statement block had been reached, causing it to jump to the
				start of the following iteration.
				*/ 
			if(n>9999)
				break; //break表示退出循环 
			int aa = n/100, bb = n%100;
			if(aa/10 == aa%10 && bb/10 == bb%10)
				printf("%d ", n);
		}
		printf("\n");
		
		//上面的代码可以改成下面这样子：
		for(int i=32; i*i<10000; i++)
		{
			int aa = i*i/100, bb = i*i%100;
			if(aa/10 == aa%10 && bb/10 == bb%10)
				printf("%d ", i*i);
		}
		printf("\n");
		//for(int i=1; i*i>999 && i*i<10000; i++)是不行的，因为初始值与条件矛盾 	
	printf("\n");

	printf("例17：循环嵌套（分解质因数）\n"); 
		//（《一本通》p75例4.18：输入一个正整数，输出其分解质因数结果，
		//例如输入36，输入2 * 2 * 3 * 3）
		int i = 2; 
		scanf("%d", &n);
		do
		{
			while(n%i == 0)
			{
				printf("%d", i);
				n /= i;
				if(n != 1)
					printf(" * ");
			}
			i++;
		}
		while(n != 1);
		printf("\n");
	printf("\n");
	
	return 0;
}

/*	
	作业：
		1.4编程基础之逻辑表达式与条件分支（21题） http://noi.openjudge.cn/ch0104/
			选其中10题即可，需包括： 
				04:奇偶ASCII值判断； 
				20:求一元二次方程的根； 
				
		1.5编程基础之循环控制（45题） http://noi.openjudge.cn/ch0105/
			选其中20题即可，需包括：
				 
*/
