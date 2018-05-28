/*	@author 杜博识Dubos

NOIP 03.1 一维数组
	（包含顺序查找、简单排序、二分查找） 
	以《CCF入门篇》第5章5.1-5.3节为主；
	以《一本通》第一部分第5章第一节、第二部分第2章为辅； 
	以《入门经典》第3章为参考；
	
	后面还有二维数组、字符数组与字符串、高精度计算。 
 */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
int i, j, k, n;

//printArray函数是在例1建立的
void printArray(double arr [], int length) 
{
	for (i=0; i<length; i++)
    	printf("%.1f ", arr[i]);
 	printf("\n");
}

void printArray(int arr [], int length) 
{
	for (i=0; i<length; i++)
    	printf("%d ", arr[i]);
 	printf("\n");
}

void printArray(bool arr [], int length) 
{
	for (i=0; i<length; i++)
    	printf("%d ", arr[i]);
 	printf("\n");
}

int main()
{
	printf("NOIP 03.1 一维数组\n\n");
	
	printf("例1：一维数组\n");
		//本周七天平均气温（摄氏度）分别是：21, 20, 22, 23, 27, 29, 21, 将其转
		//化为华氏度并输出，只保留小数点后一位，中间用空格分隔， 
		//转换公式为Fahrenheit = Celsius * 1.8 + 32.0；
	
		//解法一：
		double a1=21, a2=20, a3=22, a4=23, a5=27, a6=29, a7=21;
		a1 = a1*1.8 + 32;
		a2 = a2*1.8 + 32;
		a3 = a3*1.8 + 32;
		a4 = a4*1.8 + 32;
		a5 = a5*1.8 + 32;
		a6 = a6*1.8 + 32;
		a7 = a7*1.8 + 32;
		printf("%.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", a1, a2, a3, a4, a5, a6, a7); 
	
		//解法二： 
		double a [7] = {21, 20, 22, 23, 27, 29, 21};
		for(i=0; i<7; i++)
		{
			a[i] = a[i]*1.8 + 32.0;
			printf("%.1f ", a[i]);
		}
		printf("\n");
		/*
		如果数据量很大的话，解法一就需要写很多行，但解法二就不会有很大变化，因为
		解法二将数据储存在数组里，再对数组中的每个元素执行相同或者类似的命令。 
		
		建立【一维数组】的写法是：
		type name [size];
		例如
		double a [7]; 
	
		1. 每个数组由多个数据类型相同（例如整数、实数、字符等）的元素组成；
		2. 建立数组时[]里面是元素个数，是定量（例如a[8]），不是变量（如a[i]）；
		3. 数组a中的元素以0, 1, 2...为序号，分别是a[0], a[1], ... a[length-1]，
			序号是从0开始注意； 
		4. 在调用数组中的元素时，[]里面可以是变量，例如a[i]； 
		5. 【数组越界】：编译器对数组不进行边界检查，只能靠程序员人工检查，
			若赋值发生越界则所赋的值就会超出数组的有效范围而赋给别的变量；
		6. 数组的初始化赋值可以写出全部元素的值，也可以写出部分元素的值，例如
			 double a [7] = {21, 20, 22, 23, 27, 29, 21};
			 而
			 double a [7] = {21, 20, 22, 23};
			 则是对前4个元素进行赋值，对其余三个元素赋值为0，还可以
			 double a [7] = {};
			 这样是对所有7个元素赋值为0； 
		7. 如果不进行初始化赋值的话，数组元素会取默认值，默认值不一定为0，例如 
			下面数组b的元素值是随机赋值的；
		8. 只能对数组中的元素赋值，而不能直接将数组b整个赋值给数组c，另外我们
			可以用cstring头文件中的memcpy函数将数组b的元素值复制并赋值给数组c，
			后面会讲； 
		*/
		int b [5];
		for(i=0; i<5; i++)
		{
			printf("%d ", b[i]); 
		}
		printf("\n");
		//输出数组是本章常用操作，在main前建立printArray函数以便使用
		//依次对数组中每个元素均做一次且仅做一次访问的做法叫做【遍历Traversal】 
	
		b[0] = 0;
		printArray(b, 5);
		//int c [5] = b;
		//printArray(c, 5);
		printf("\n");
	
	printf("例2：一维数组的应用 - 开关灯\n"); 
		/*《入门经典》p39和《一本通》p84例5.3。 
			有n盏灯，关着。现在进行k次操作： 
				第一次操作按将所有灯的开关； 
				第二次操作按所有编号为2的倍数的灯开关；
				第三次操作按所有编号为3的倍数的灯开关；
				...
				第k次操作按所有编号为k的倍数的灯开关； 
			其中k<=n<=1000； 
			输入n k，输出k次操作后开着的灯的编号，中间以空格分隔，开头和结尾、
			不可有空格。
			
			样例输入：
			7 3
			样例输出：
			1 5 6 7
			
			样例输入：
			100 100 
			样例输出：
			1 4 9 16 25 36 49 64 81 100 
		*/
		int first=1;
		bool light [1050] = {}; //所有都是false，对应数字0，把数组长度设得长一些 
		scanf("%d %d", &n, &k);
		
		//turn on/off the lights 
		for(i=1; i<=k; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(j%i == 0)
					light[j] = !light[j];
			}
		}
		
		//printArray(light, n);
		for(j=1; j<=n; j++)
		{
			if(light[j])
			{
				if(first)
					first = 0;
				else
					printf(" ");
				printf("%d", j);
			}
		}
		printf("\n");
		/*
		思考：
			1. 为什么当n = k时，输出的数字都是完全平方数？
			2. first=1的作用是什么？
		*/
	printf("\n");
	
	printf("例3：一维数组的应用 - 约瑟夫问题Josephus problem\n");
		/*《一本通》p85例5.4： 
		在罗马人占领乔塔帕特后，Josephus和他的朋友与39个犹太人躲到一个洞中，
		39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式：
			41个人排成一个圆圈，由第1个人开始报数，每报数到第3人该人就必须自杀； 
			然后再由下一个重新报数，直到所有人都自杀身亡为止。
		Josephus和他的朋友并不想遵从，于是他们站在第16和31位，最终活了下来。 
		
		以上是Josephus problem原本的陈述，现在我们要解决的是更普适的情况：
			n个人排成一个圆圈，每数到k就要被踢出，那么最后剩下的是第几位？
			其中 n <= 100. 
		*/
		bool martyr [105] = {}; //赋值均为false，表示未被踢出 
		scanf("%d %d", &n, &k);
		int count=0, index=0, call=0;
		
		do
		{
			index++; //来到下一个人 
			if(index == n+1)
				index = 1; //如果下一个序号超出n了，就从头来过； 
			if(!martyr[index]) 
				call++; //martyr[index]==false，未被踢出，就给点名数加一； 
			if(call == k)
			{
				martyr[index] = true;
				call = 0;
				count++; //如果点到第m个了，此人被踢，点名数归零，踢人计数加一； 
			}		
		}
		while(count < n-1);
		
		for(i=1; i<=n; i++)
			if(!martyr[i])
				printf("%d\n", i);
	printf("\n");
	
	printf("例4：一维数组的应用 - 埃拉托斯特尼筛法Sieve of Eratosthenes\n"); 
		/* 《一本通》p87例5.7，输入正整数n，输出n以内所有素数，中间用空格分隔。
			筛法步骤如下：
			1. 把2到n的自然数对应于数组num[2]至num[n]各元素，最开始均赋值true
				（当然0和1是false）;
			2. 找到当前true值元素排在最前的序号p（即当前最小素数），将后面所有
				序号为其倍数的元素值都改为false;
			3. p++，重复直至sqrt(n);
			4. 输出最终true值元素的序号。
		*/
		scanf("%d", &n);
		bool num [n+5] = {}; //赋值全部为false 
		for(i=2; i<=n; i++)
		{
			num[i] = true;
		}
		
		for(i=2; i<=sqrt(n); i++)
		{
			if(num[i])
				for(int j=2; j<=n/i; j++)
					num[i*j] = false;
		}
		
		for(i=2; i<=n; i++)
		{
			if(i==2)
				printf("2");
			else
				if(num[i])
					printf(" %d", i);
		}
		printf("\n");
	printf("\n");
	
	/*
	【排序】与【搜索】是算法与数据结构的重要问题，也在算法竞赛中占有重要地位，
	例5 - 例10是我们目前能够对一维数组实现的几种排序与搜索算法。
	
	为方便，我们在几个例题中都对同样的数组进行搜索或者排序：
	{98, 36, 890, 8, 0, -98, 98, 0, 0, 17} 
	
	实际题目中的数组初始化方法如下：
	 
		若题目要求输入若干个（不多于n个）数组成数组，但未制定具体个数，则
			int arr [n]; 
				while(scanf("%d", &arr[i]))
		
		若题目要求输入n个数作为数组，则赋值更容易：
			int arr [n];
			for(int i=0; i<n; i++)
				cin >> arr[i];
	*/
	
	printf("例5：一维数组的搜索 - 顺序搜索Sequential search\n"); 
		/*《CCF入门篇》p209, 输入整数k，在题目中搜索k，并输出两行：
			首行输出其出现的位置序号，用空格分隔；
			次行输出其出现次数;
		【顺序搜索】的思路非常直白：从头到尾把数组元素与目标对比一遍即可。
		*/
		scanf("%d", &k);
		count = 0;
		int seq [10] = {98, 36, 890, 8, 0, -98, 98, 0, 0, 17};
		for(i=0; i<10; i++)
		{
			if(seq[i]==k)
			{ 
				printf("%d ", i);
				count++;
			}
		}
		printf("\n%d\n", count);
		//顺序搜索对于乱序数组很有效，但对于有序数组就显得效率低下， 
		//下面我们先把上述数组排序，再看其他搜索方法。 
	printf("\n"); 
	
	printf("例6：一维数组的排序 - 选择排序Selection sort\n"); 
		/*《CCF入门篇》p205，【选择排序】思路如下（从小到大排序）：
			1. 找出数组中最小的元素（之一），将其与第0位元素交换；
			2. 找出从第1位至最后一位元素中最小的之一，将其与第1位元素交换；
			3. 以此类推，找出第i位至最后一位元素中最小的之一，将其与第i位元素交换；
			4. 最后比较最后两位元素，按照顺序放好。
		*/
		int selct [10] = {98, 36, 890, 8, 0, -98, 98, 0, 0, 17};
		int temp;
		for(i=0; i<10; i++)
		{
			index = i;
			for(j=i+1; j<10; j++)
				if(selct[index] > selct[j])
					index = j;
			if(index != i)
			{
				temp = selct[index];
				selct[index] = selct[i];
				selct[i] = temp;
			}
		}
		printArray(selct, 10);
	printf("\n"); 
	
	printf("例7：一维数组的排序 - 冒泡排序Bubble sort\n"); 
		/*《CCF入门篇》p206，【冒泡排序】的思路如下（从小到大排序）：
			1. 从第0位开始，逐个比较相邻两个元素直至第n-1位： 
				第0位与第1位；
				第1位与第2位；
				...
				第n-2位与第n-1位；
				小的放前面、大的放后面，这样就把最大的放在了第n-1位； 
			2. 从第0位开始，逐个比较相邻两个元素直至第n-2位： 
				第0位与第1位；
				第1位与第2位；
				...
				第n-3位与第n-2位；
				小的放前面、大的放后面，这样就把最大的放在了第n-2位； 
			3. 依此类推，直至最后从第0为开始，比较其与第1位的元素，
				小的放前面、大的放后面，这样就完成了排序。 
		*/
		int bubl [10] = {98, 36, 890, 8, 0, -98, 98, 0, 0, 17};
		for (i=9; i>0; i--)
			for(j=0; j<i; j++)
				if (bubl[j] > bubl[j+1])
				{
					temp = bubl[j];
					bubl[j] = bubl[j+1];
					bubl[j+1] = temp; 
				}
		printArray(bubl, 10);
	printf("\n"); 
	
	printf("例8：一维数组的排序 - 插入排序Insertion sort\n");
		/*《CCF入门篇》p208，【插入排序】的思路如下（从小到大排序）；
			1. 取第1位元素，与其前面的元素（第0位）相比，将较小的放前面，
				则第0位至第1位为从小到大排列；
			2. 取第2位元素，与第0、1位元素比，将其插在合适的位置，
				则第0位至第2位为从小到大排列； 
			3. 依此类推，取第i位元素，与其前面的各元素相比，将其插在合适的位置，
				则第0位至第i位为从小到大排列；
			4. 直至取第n-1位元素，与其前面的各元素相比，将其插在合适的位置，
				则排序完成。 
		*/
		int insr [10] = {98, 36, 890, 8, 0, -98, 98, 0, 0, 17};
		for (i=1; i<10; i++)
		{
			for (j=i-1; j>=0; j--)
				if (insr[j] < insr[i])
					break;
				if (j != i-1)
				{
					temp = insr[i];
					for (k=i-1; k>j; k--)
						insr[k+1] = insr[k];
					insr[j+1] = temp;
				}
		}
		printArray(insr, 10);
	printf("\n"); 
	
	printf("例9：一维数组的排序 - 计数排序Counting sort\n"); 
		/*《CCF入门篇》p197，前面排序都没有限制数组元素的取值范围，如果元素有
			取值范围[0, k]的话，我们可以使用【计数排序】：
			1. 建立计数数组int cnt [k+1]
			2. 对需要排序的原数组遍历一次，将每个值i出现的次数赋值给cnt[i]
			3. 对原数组重新赋值，排序完成 
			
			显然，计数排序是个对客观条件要求比较苛刻的排序方法。
		*/
		int cntSort [10] = {98, 36, 890, 8, 0, 98, 98, 0, 0, 17};
			//前面例题中一个元素-98在本题改成了98
		int cnt [1001] = {};
		
		for (i=0; i<10; i++)
			cnt[cntSort[i]]++;
			
		i = 0;
		for (j=0; j<1001; j++)
			if (cnt[j] > 0)
				for (k=cnt[j]; k>0; k--)
				{
					cntSort[i] = j;
					i++;
				}
	
		printArray(cntSort, 10);
	printf("\n"); 
	
	printf("例10：一维数组的搜索 - 二分搜索Binary search\n"); 
		/*《CCF入门篇》p210，输入整数k，在数组中搜索k，如果有则输出1，无则输出0
			
		对于有序数组，二分搜索比顺序搜索的效率高：
			1. 将有序数组平分为两半（如果不能刚好平分的话差一个也行），看k值是在
				哪一半；
			2. 依此类推，直至找到k值； 
		
		本题我们在直接用前面排好顺序的数组：
		*/
		int biSrch [10] = {-98, 0, 0, 0, 8, 17, 36, 98, 98, 890};
		/* int k; was declared in line 138*/
		scanf("%d", &k);
		int low=0, high=9, mid=(low+high)/2;
		
		while (biSrch[mid]!=k && low<high)
		{
			if (biSrch[mid]<k)
				low = mid + 1;
			else
				high = mid - 1;
			mid = (low+high) / 2;
		}
		
		if (biSrch[mid]==k)
			printf("%d", 1);
		else
			printf("%d", 0);		
	printf("\n"); 
	
	return 0;
}
	
/*	
	作业：
	1.6编程基础之一维数组（15题） http://noi.openjudge.cn/ch0106/
	1.9编程基础之顺序查找（15题） http://noi.openjudge.cn/ch0109/
	1.10编程基础之简单排序（10题） http://noi.openjudge.cn/ch0110/
	1.11编程基础之二分查找（10题） http://noi.openjudge.cn/ch0111/
	其中涉及大整数计算（例如多达100位的整数，2的100次幂等等）暂且略过 
*/
