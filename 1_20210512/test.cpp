/*

*思路：

* 1. 对字符串的每一个字符进行hash映射

* 2. 按顺序检测每一个字符是否只出现一次

*/

#include<iostream>

#include<string>

#include<list>

using namespace std;



int Hash(int key)

{

	return key - 'a';

}

int FirstTimeChar(string &str)

{

	int hashtable[26] = { 0 };

	//对字符串的每一个字符进行hash映射

	for (int i = 0; i < str.size(); ++i)

	{

		int index = Hash(str[i]);

		hashtable[index]++;

	}

	//按顺序检测每一个字符是否只出现一次

	for (int i = 0; i < str.size(); ++i)

	{

		int index = Hash(str[i]);

		if (hashtable[index] == 1)

			return str[i];

	}

	return -1;

}



int main()

{

	string str;

	while (getline(cin, str))

	{

		char res = FirstTimeChar(str);

		if (res == -1)

			cout << -1 << endl;

		else

			cout << res << endl;

	}

	return 0;

}




/*

*思路：

* 1. 收尾交换，进行翻转

*/

class Solution {

public:

	void reverseString(vector<char>& s)

	{

		if (s.empty())

			return;

		int start = 0;

		int end = s.size() - 1;

		while (start < end)

		{

			swap(s[start], s[end]);

			start++;

			end--;

		}

	}

};





/*

*思路：

* 1. 要考虑正负数

* 2. 要考虑数据是否溢出

*/

class Solution {

public:



	int StrToInt(string str)

	{

		int len = str.size();

		int flag = 1;

		if (len == 0)

			return 0;

		const char *cstr = str.c_str();

		if (cstr == NULL)

			return 0;

		int i = 0;

		if (cstr[i] == '+')

		{

			i++;

			flag = 1;//如果str[i]为'+'，str[i]顺序后移，并令标志flag为1，表示为正数   

		}

		else if (cstr[i] == '-')

		{

			i++;

			flag = -1;//如果str[i]为'-'，str[i]顺序后移，并令标志flag为-1，表示为负数   

		}

		long long num = 0;

		while (cstr[i] != '\0')

		{

			if (cstr[i] >= '0' && cstr[i] <= '9')

			{

				//每遍历一个在0-9间的字符，就将其输入到num中       

				num = num * 10 + (cstr[i] - '0');//下一次输入到num中时要加上上一次*10的结果，即上一次的数左移一位（十进制下） 



				//如果数据溢出，则返回0

				if ((flag > 0 && num > 0x7fffffff) || (flag<0 && num>0x80000000))

					return 0;

				i++;

			}

			else

			{

				return 0;

			}

		}

		if (flag < 0)

			num = num * -1;

		return (int)num;

	}

};