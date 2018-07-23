NOIP 06 结构体（未完成）
======
  
|Author|杜博识Dubos|
|---|---|
|E-mail|dubos@foxmail.com|

------  

## 结构体的定义
* 定义
	* 第一种
  
	```cpp
	struct 结构体名 {
	成员表;
	成员函数;
	} 结构体变量表;
	```
	例如：
	```cpp
	struct student {				//结构体名为student
		string name;  
		int chinese, math, english;  
		int total;
	} students [110];				//变量是包含110个student的数组students
	```
	* 第二种
	```cpp
	struct 结构体名 {  
	成员表;  
	成员函数;
	};
	结构体名 结构体变量表
	```
	例如：
	```cpp
	struct student{				//结构体名为student
		string name;  
		int chinese, math, english;  
		int total;
	};
	student students [110];			//变量是包含110个student的数组students
	```
  

###### 参考资料
> 《CCF中学生程序设计基础篇》第3章；  
> 《信息学奥赛一本通》第一部分7.2节；  
> 《新标准C++程序设计教程》第8章。  
