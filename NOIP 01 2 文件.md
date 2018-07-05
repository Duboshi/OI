时间紧张，先用一种最方便的方法：**文件重定向**。语句非常简单：
```cpp
freopen("输入文件名", "r", stdin);	//r代表read
freopen("输出文件名", "w", stdout);	//w代表write
```
