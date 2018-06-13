/*	@author 杜博识Dubos

NOIP 03.4 C++字符串string 
	以http://www.cplusplus.com/reference/string/string/为主；
	以C++ Primer第3章、《CCF基础篇》第2章、《新标准C++程序设计教程》第19.13节为辅；
	以《算法竞赛入门经典》第5.1.3节为参考；
	《信息学奥赛一本通》没有相关内容。 
 */

#include <cstdio>
#include <iostream>
#include <cctype> //这是个新的头文件，但不是重点，作用在下面例子里面讲 
#include <cstring>
	/*上一节我们知道：在C语言中，【字符串 (cstring)】存储在有空字符'\0'作为结束
	字符的字符数组中，而字符数组不一定有结束字符，所以字符串 (cstring)
	一定是字符数组，但字符数组不一定是字符串。要存储一个字符串 (cstring)时，
	要建立一个字符数组：
 	char s1 [100]; //s1最多只包含100个字符
	
	由于字符串 (cstring)是一种非常重要的数组，所以C语言中有一系列专门处理
	字符串 (cstring)的函数，这些函数在string.h头文件中，后来C++发展之后，
	C语言的string.h头文件里的各种函数依然可用，但是头文件名变成cstring，只
	需预处理命令中调用cstring： 
	#include <cstring>
	
	这里只介绍cstring中的一些函数，全部函数见C++网站 - 
	http://www.cplusplus.com/reference/cstring/
	
	注意：cstring库函数应用了指针，所以需要先了解指针的概念、引用和运算，
	以及指针与数组的关系，才能透彻理解cstring库函数。 */
#include <string>
	/*非常值得注意的是，上面所说的“C语言中的字符串 (cstring)”与C++语言中的
	字符串 (string)有区别。 
				
	在C++语言中，专门有一个string类(class)让我们可以直接建立一个string，
	它的长度是可变的，我们可以把它理解称为长度可变的“字符数组”（之后
	我们还会介绍其他长度可变的“数组”，例如vector等，这些都是基于数组拓展
	出来的）。长度可变使string更方便使用，也使string的运行速度比字符数组慢。 
	
	string还有很多函数功能可以使用，这些函数与cstring中的不一样，我们讲的时候
	会注明哪些函数属于cstring，哪些属于string。要建立string或使用string库函数， 
	需要在预处理命令调用string：
	#include <string>
	然后建立一个string：
	string s2;
	
	这里只介绍string中的一些函数，全部函数见C++网站 - 
	http://www.cplusplus.com/reference/string/string/
	
	综上，C语言只能用cstring处理字符串，而C++语言既可以用cstring也可以用string,
	两者对比，
		1. string更易学：而cstring函数需要基于指针理解； 
		2. string更安全：由于现实中字符串的长度很难预估或者计算准确，所以
			字符数组不方便使用，一旦实际字符数量大于cstring字符数组设定的
			长度，则会造成错误；
		3. 但string也更慢：string长度可以改变，而字符数组长度固定，所以
			cstring运行速度快一些。
		
	下面我们先介绍string，再学习cstring和指针。*/

using namespace std;

int main()
{
	printf("例0：string的初始化、赋值、输入与输出\n");
		/*1. 初始化赋值*/ 
		string s1; //default initialization, s1 is an empty string
		string s2 = "0123456789"; //字符串常量(string literal)赋值 
		string s3("0123456789"); //equivalent to s2
		string s4("0123456789", 3); //s4 is "012" (copy the first 3 characters)
		string s5("0123456789", 2, 4); //s5 is "2345" (starting from index 2, copy of 4 characters)
		
		string s6(5, 'a'); //s6 is "aaaaa"
		string s7 = s6; //s7 is also "aaaaa"
		string s8(s6); //s8 is also "aaaaa"
		cout<<"s1: "<<s1
			<<"\ns2: "<<s2
			<<"\ns3: "<<s3
			<<"\ns4: "<<s4
			<<"\ns5: "<<s5
			<<"\ns6: "<<s6
			<<"\ns7: "<<s7
			<<"\ns8: "<<s6<<endl;
		cout<<endl;
		
		/*	上面介绍了8种初始化，除了第1种以外都有赋值。需要特殊说明的是字符串常量
			赋值：字符串常量(string literal)可以为string赋值，但它本身不是string，而
			是字符数组。 
		
		2. 【string& assign】函数
			除了初始化赋值，还可以用assign函数为string赋值。assign函数返回值是
			原字符串的索引，我们可以把函数结果当作字符串看待。*/ 
		
		cout<<"s1: "<<s1.assign("0123456789")<<endl; //s1 is "0123456789"
		cout<<"s1: "<<s1.assign("0123456789", 3)<<endl; //s1 is "012": start from index 0 and length is 3:  
		cout<<"s1: "<<s1.assign("0123456789", 2, 4)<<endl; //s1 is "2345": start from index 2 and length is 4
		cout<<"s1: "<<s1.assign(5, 'a')<<endl; //s1 is "aaaaa"
		s6 = "abcde";		
		cout<<"s1: "<<s1.assign(s6)<<endl<<endl; //s1 is "abcde"	
		
		/*3. 我们也可以用cin>>为s1赋值*/ 
		cin>>s1; //输入：Come on, man! 
		cout<<"s1: "<<s1<<endl; //却发现结果是s1: Come 
		
		/*4. 【getline(cin, s1)】函数
			由于cin遇到空格、tab、换行符都会停止，没法直接用cin把一句话赋值给s1，
			这时我们用getline(cin, s1)函数解决，这个函数一直读到换行符才停止，
			并把换行符前面的字符串赋值给s1 */
		getline(cin, s1); //这一行是为了把刚才换行符之前的字符串吃掉 
		getline(cin, s1); //再次输入：Come on, man! 
		cout<<"s1: "<<s1<<endl; //结果是s1: Come on, man!
		
	printf("\n");
	
	printf("例1：string库函数 - 字符串长度\n");
		/*1.【size_t size()】或【size_t length()】函数
			两个函数分别是size()和length()，它们的功能完全一样，结果都是字符串
			所包含字符的数量。值得注意的是，这两个函数返回的数据类型(return type)
			不是int，而是另一个整数类型size_t，这种数据类型没有符号，不能存储负
			整数。
			
			如果你只想用其中一个函数就选择size()，因为还有【max_size()】和
			【resize()】函数，但是没有max_length()或者relength()函数。
				
		2.【bool empty()】
		 	用于判断字符串是否为空字符串，是则结果为true(1)，否则结果为false(0)； 
			 
		3.【size_t max_size()】
			函数的结果是string所能包含字符数量的上限，这个与具体编程环境有关；
		
		4.【resize】函数有两种：
			void resize (size_t n)是将数组长度变为n，如果原长度大于n就保留前n个
				字符，如果原长度小于n则增补空字符； 
			void resize (size_t n, char c)也是将数组长度变为n，如果原长度大于n就
				保留前n个字符而c则没有用，如果原长度小于n则新增补若干个字符c；
			注意resize函数返回值是void，而不是string&，所以我们不能把函数结果当作
				字符串。*/
		
		s1 = ""; //s1 is empty
		cout<<"s1: "<<s1<<endl;
		cout<<"s1's size: "<<s1.size()<<endl; //0 
		cout<<"s1's length: "<<s1.length()<<endl; //0 
		cout<<"Is s1 empty?: "<<s1.empty()<<endl; //1 
		cout<<"s1's max size: "<<s1.max_size()<<endl; //4611686018427387897
		s1.resize(5, '0'); //"00000"：s1变为5位，多增加的用'0'填充，但resize返回类型为void，不能直接输出 
		cout<<"Now s1: "<<s1<<endl<<endl; //输出字符串s1："00000"
		
		//s2 is 0123456789
		cout<<"s2: "<<s2<<endl;
		cout<<"s2's size: "<<s2.size()<<endl; //10
		cout<<"s2's length: "<<s2.length()<<endl; //10
		cout<<"Is s2 empty?: "<<s2.empty()<<endl; //0
		cout<<"s2's max size: "<<s2.max_size()<<endl; //4611686018427387897
		s2.resize(15, '0'); //s1变为"012345678900000"，但不能直接输出函数结果 
		cout<<"Now s2: "<<s2<<endl; //输出字符串s2："012345678900000"
		s2.resize(5, '0'); //"01234"：只剩下前5位，多增加的用'0'填充，但是由于没有
			//多增加的位置，所以也没有填充'0'，所以这与s2.resize(5)效果一样 
		cout<<"Now s2: "<<s2<<endl; //输出字符串s2："01234"
	printf("\n");
	
	printf("例2：string库函数 - 字符串串联，子字符串，添加字符\n");
		/*1. 【+】运算符 
			把两个字符串串联成为一个字符串，最简单的方法就是用加号，例如s1 + s2。 
			注意：加号两端需至少有一个是string，两端都是字符串常量（例如"abc"）则 
				不行，因为字符串常量是字符数组。 */
		s1 = "123";
		s2 = "456";
		cout<<"s1+s2: "<<s1+s2<<endl<<endl; //结果是"123456"，但是s1和s2的值不变 
		//cout<<"\"123\"+\"456\": "<<"123"+"456"<<endl; //而"123"+"456"就不行
	
		/*2. 【+=】运算符 
			s1+=s2与s1=s1+s2是一样的，这里不再举例了 
		
		3.【string substr】函数
			s1.substr(1, 2)把字符串s1从序号为3的元素开始的5个元素复制为新字符串，
			这个新字符串是s1的子字符串。*/ 
		cout<<"s1.substr(1,2): "<<s1.substr(1,2)<<endl<<endl; //结果是"23" 
		
		/*4.【string& append】函数
			可以在字符串（例如s1）后面加字符串、字符串常量、子字符串或者若干个相同的
			字符，并且s1的值会发生改变。
			下面几种append函数返回值是string&，我们可以把函数结果看作字符串。*/
		cout<<s1.append(s2)<<endl; //结果也是"123456"，并且s1变成"123456" 
		cout<<s1.append(s2, 0, 2)<<endl; //结果是"12345645"，即从s2的第0位开始，复制两位
		cout<<s1.append("abc")<<endl; //结果是"12345645abc"，即在末尾加上字符串常量"abc" 
		cout<<s1.append("abc", 2)<<endl; //结果是"12345645abcab", 即在末尾加上字符串常量"abc"的前2位
		cout<<s1.append(3, '.')<<endl<<endl; //结果是"12345645abcab..."，即在末尾加上3个字符'.' 
		
		/*5. 【string& insert】函数
			在字符串（例如s1）指定位置插入字符串、字符串常量、子字符串或者若干个相同的字符，
			并且s1的值会发生改变。
			下面几种insert函数返回值是string&，我们可以把函数结果看作字符串。*/
		s1 = ".123.";
		s2 = "321";
		cout<<s1.insert(4, s2)<<endl; //s1变为".123321.",在s1序号为4的元素前插入s2 
		cout<<s1.insert(4, s2, 2, 1)<<endl; //s1变为".1231321."，在s1序号为4的
			//元素前插入s2的子字符串（从s2序号为2的元素开始，长度为1） 
		cout<<s1.insert(4, "2")<<endl; //s1变为".12321321."，在s1序号为4的元素前插入字符串常量"2"
		cout<<s1.insert(6, "22", 1)<<endl; //s1变为".123212321."，在s1序号为4的元素前插入字符串常量"22"的前1位
		cout<<s1.insert(0, 3, '?')<<endl<<endl; //s1变为"???.123212321."，在序号为1的元素前插入3个字符'?' 
		 
		/*6. 【void push_back】函数
			s1.push_back(c)表示在字符串s1后面加上字符c。
			注意push_back函数返回类型是void，我们不能把结果当作字符串。*/
		s1 = "Come on, man";
		s1.push_back('!'); //s1变成"Come on, man!", 但是不能直接输出函数结果 
		cout<<s1<<endl; //输出字符串s1: "Come on, man!" 
	printf("\n"); 
	
	printf("例3：string库函数 - 字符串的复制\n");
		/*【size_t copy】函数
			size_t copy (char* s, size_t len, size_t pos)函数的功能是将字符串的
			一部分拷贝到字符数组里，所以函数的第一个参数char* s是一个字符数组
			（学过指针就知道为什么char*是字符数组了），第二个参数len是长度，第三
			个参数pos表示从字符串的序号pos开始复制。例如： 
				s1.copy(s9, 5, 3)的功能是从字符串s1中序号为3的字符开始复制5位给字符
				数组s9
			注意copy函数不会在字符数组末尾符加'\0'; 
			注意copy函数返回值是size_t，值与复制长度len相等，我们不能把结果当作
			字符串或者字符数组。*/
		s1 = "0123456789";
		char s9 [10];
		cout<<s1.copy(s9, 5, 3)<<endl; //输出值为5，因为复制了5个字符 
		cout<<s9<<endl; //输出字符数组s9: "34567"，这还不是C string，因为不是以'\0'为结尾的 
	printf("\n"); 
	
	printf("例4：string库函数 - 删除字符\n");	
		/*1.【void clear】函数
			s1.clear()把字符串s1变回空字符串，由于函数返回类型是void，我们不能把
			函数结果当作字符串。*/
		s1.clear(); //s1变成空字符串了，但是不能直接输出函数结果
		cout<<"s1: "<<s1<<endl; //输出空字符串s1 
		
		/*2.【string& erase】函数
			erase函数把字符串指定位置的字符删掉，由于string可以变化长度，所以
			删掉字符后，整个字符串的长度也会对应减少。
			下面介绍的erase函数返回类型是string&，我们可以把它的结果当作字符串。*/
		s1 = "0123456789";
		cout<<"s1: "<<s1.erase(6, 4)<<endl; //结果是"012345", 从序号6开始删除4位 
	printf("\n"); 
	
	printf("例5：string库函数 - string的比较\n");
		/*1. 【int compare(const string& str)】函数
			括号里面应该是一个字符串，而函数结果是整数，具体比较规则如下：
			
			从头开始，逐个字符进行对比，字符串的比较顺序就以两者第一个不同的字符
			为判断依据； 
			字符顺序按照ASCII标准，A~Z的ASCII号码为65~90，a~z的则是97~122，所以
			小写字母排在大写字母后面；
			如果两个字符串长度不一样，其中一个与另一个的前几位完全一样，那么更长
			的那个排在后面。*/
		s1 = "ab";
		s2 = "abc";
		s3 = "Ab";
		s4 = "Zbc";
		
		cout<<s1.compare("ab")<<endl; //0：两个完全一样的字符串 
		cout<<s1.compare(s2)<<endl; //-1：s1与s2有重合的字符，但s1比s2长度小，所以排在s2前面 
		cout<<s1.compare(s3)<<endl; //1：s1与s3第一个字母就不一样，大写字母排在小写字母前面
		cout<<s1.compare(s4)<<endl; //1：s1与s3第一个字母不一样，大写字母Z排在小写字母a前面
		
		/*2.【relational operators】
		基于compare函数，两个字符串的关系可以用==, !=, <, <=, >, >=来表示； */
		s1 = "a", s2="Z";
		cout<<(s1<s2)<<endl; //0: false，表示a在Z之后，正确
		cout<<(s1.compare(s2))<<endl; //1: 表示a在Z后面，正确
		cout<<('a'<'Z')<<endl; //0: false，表示a在Z之后，正确
		cout<<("abc"<"Zbc")<<endl; //0: false，表示a在Z之后，正确 
	printf("\n");
	
	printf("例6：string库函数 - 位置、查找\n");
		/*1. []运算符
			与对数组类似，string也可以用序号对某个元素进行访问和操作*/
		s1 = "abcde";
		cout<<"s1[0]: "<<s1[0]<<endl<<endl; //输出序号为0的元素，'a'
		
		/*2.【char& at】函数
			s1.at(0)和s1[0]都是字符串s1中序号为0的元素*/
		cout<<"s1.at(0): "<<s1.at(0)<<endl<<endl; //结果还是'a'
		
		/*3.【iterator begin】和【iterator end】函数
			这两个函数返回类型是iterator迭代器，这是种新的数据类型，是在string类
			中定义的。迭代器可以用来表示字符串中元素的位置，例如s1.begin()就是
			字符串s1里最前面（序号为0）元素的位置。
			
			而值得注意的是s1.end()却不是指的字符串s1里最后面的元素的位置，而是
			指最后面的元素之后的位置，也就是一个并不存在的位置。这样设计是为了
			方便我们遍历字符串中所有的元素，就像长度为n的字符串没有序号为n的元素，
			但我们依然经常在遍历时用到n：for (int i=0; i<n; ++i) 
			
			迭代器存在的意义在于，之后我们会遇见很多数据结构不像string这样能用序号
			对元素进行操作，那时候就只能用迭代器了。在那些数据结构对应的类里面，
			都会定义相应的迭代器，功能跟我们现在所见string中的迭代器很类似。
			
			现在，我们用的是string类里面定义的iterator，而不是别的类里面定义的，
			所以要在代码中写出string::iterator而不能直接写iterator。:: */
		s1 = "abcde";
		cout<<"s1: "<<s1<<endl;
		string::iterator iter = s1.begin();
		*iter = 'A'; //*iter表示迭代器iter位置对应的元素，把它赋值为'A'
		cout<<"s1: "<<s1<<endl<<endl;
		
		for (iter=s1.begin(); iter!=s1.end(); ++iter)
			*iter = toupper(*iter); 
		cout<<"s1: "<<s1<<endl<<endl; //结果是"ABCDE" 
			/*注意使用迭代器遍历字符串时，由于迭代器没有<算符，所以我们用的
			不等于号，==、!=、++和--四种算符对于迭代器都适用。
			
			toupper(c)是cctype的库函数，作用是把字符c变成大写，类似还有cctype库函数 
			tolower(c)把字符c变成小写（如果没得变，就不会改变c）. 
		
		4. 查找函数：
			首先解释一下string::npos：
				以下各个查找函数的返回值类型都是size_t，查找目标在字符串中的
				对应序号是以size_t整数形式储存的，而当没找到的时候，以下各个查找
				函数的返回值都是string::npos，npos是个在string中定义的size_t类型
				常数，具体值为：
					static const size_t npos = -1;
				size_t是没有符号的整数类型，-1也是size_t所能表达的最大值。
			以下各函数返回值为查找所得位置的对应序号，没找到则结果为string::npos：  
			【size_t find】在字符串中查找参数第一次出现的位置； 
			【size_t rfind】在字符串中查找参数最后一次出现的位置；
			【size_t find_first_of】在字符串中查找参数中的任一字符第一次出现的位置； 
			【size_t find_last_of】在字符串中查找参数中的任一字符最后一次出现的位置； 
			【size_t find_first_not_of】在字符串中查找不符合参数所含任一字符的首个字符位置； 
			【size_t find_last_not_of】在字符串中查找不符合参数所含任一字符的最后一个字符的位置； 
		*/
		//find举例 
		s1 = "0123401234";
		s2 = "012";
		cout<<"s1.find(s2) = "<<s1.find(s2)<<endl; //结果是0
		cout<<"s1.find(\"012\") = "<<s1.find("012")<<endl; //结果是0
		cout<<"s1.find('0') = "<<s1.find('0')<<endl; //结果是0
		cout<<"s1.find(\"abc\") = "<<s1.find("abc")<<endl<<endl;
			//结果是string::npos，一个很大的数，是size_t所能取到的最大值
		
		//rfind举例 
		cout<<"s1.rfind(s2) = "<<s1.rfind(s2)<<endl; //结果是5
		cout<<"s1.rfind(\"0123\") = "<<s1.rfind("012")<<endl; //结果是5
		cout<<"s1.rfind('0') = "<<s1.rfind('0')<<endl<<endl; //结果是5
		
		//find_first_of举例（find_last_of类似，不举例了） 
		s1 = "Please, replace the vowels in this sentence by asterisks.";
		s2 = "aeiouAEIOU";
		cout<<"s1: "<<s1<<endl;
		size_t found = s1.find_first_of(s2);
		while (found!=string::npos)
		{
			s1[found] = '*';
			found = s1.find_first_of(s2, found+1); //从下一位继续搜索 
		}
		cout<<"s1: "<<s1<<endl<<endl; 
		
		//find_first_not_of举例（find_last_not_of类似，不举例了） 
		s1 = "The first non-alphabetic character in this string is: ";
		s2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		found = s1.find_first_not_of(s2);
		cout<<s1<<s1[found]<<" at position "<<found<<endl; 
	printf("\n"); 
	
	printf("例7：string库函数 - 替换"); 
		/*1.【string& replace】函数*/
		s1 = "0123456789";
		s2 = "abc";
		cout<<"s1:\n"<<s1<<endl<<endl;
		cout<<"s1.replace(7, 3, s2):\n"<<s1.replace(7, 3, s2)<<endl<<endl;
		/*	结果是"0123456abc":将字符串s1中从序号7开始的3个字符替换为s2的内容，
			s2长度可以不是3 */ 
		cout<<"s1.replace(7, 3, \"xyz\"):\n"<<s1.replace(7, 3, "xyz")<<endl<<endl;
			//结果是"0123456xyz"，原理与上面类似
		
		/*2.【void swap】函数
			注意swap函数返回类型为void，不能当作一个数组。*/
		s1 = "This is s1.";
		s2 = "This is s2.";
		s1.swap(s2);
		cout<<"s1: "<<s1<<endl; //"This is s2."
		cout<<"s2: "<<s2<<endl; //"This is s1."
		
	printf("\n"); 
		
	printf("例8：string库函数 - 与cstring的转换\n");
		/*1.【const char* c_str】函数
			返回值类型为c string，即有'\0'作为结束字符的字符数组*/
		s1 = "0123456789";
		cout<<s1.c_str()<<endl; //"0123456789"
	printf("\n");
				
	return 0;
}

/*	作业：
		这里只介绍了C++的string，在学习完c string之后才能做作业。 
*/
