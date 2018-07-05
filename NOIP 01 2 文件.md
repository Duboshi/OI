时间紧张，先用一种最方便的方法：**文件重定向**。语句非常简单，在：
```cpp
#include <cstdio> //使用freopen函数必须调用cstdio

using namespace std;
int main ()
{
	freopen("输入文件名", "r", stdin);	//r代表read
	freopen("输出文件名", "w", stdout);	//w代表write
	//正常该写什么就写什么
	return 0;
}
```
例如：  
	输入（filename.in）:一个整数
	输出（filename.out）:该整数的平方
解答如下：
```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main ()
{
	freopen("filename.in", "r", stdin);
	freopen("filename.out", "w", stdout);
	
	int n;
	cin>>n;
	cout<<n*n;
	return 0;
}
```
输入输出文件与源代码在同一个文件夹里。
