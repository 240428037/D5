/*

*˼·��

* 1. ���ַ�����ÿһ���ַ�����hashӳ��

* 2. ��˳����ÿһ���ַ��Ƿ�ֻ����һ��

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

	//���ַ�����ÿһ���ַ�����hashӳ��

	for (int i = 0; i < str.size(); ++i)

	{

		int index = Hash(str[i]);

		hashtable[index]++;

	}

	//��˳����ÿһ���ַ��Ƿ�ֻ����һ��

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

*˼·��

* 1. ��β���������з�ת

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

*˼·��

* 1. Ҫ����������

* 2. Ҫ���������Ƿ����

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

			flag = 1;//���str[i]Ϊ'+'��str[i]˳����ƣ������־flagΪ1����ʾΪ����   

		}

		else if (cstr[i] == '-')

		{

			i++;

			flag = -1;//���str[i]Ϊ'-'��str[i]˳����ƣ������־flagΪ-1����ʾΪ����   

		}

		long long num = 0;

		while (cstr[i] != '\0')

		{

			if (cstr[i] >= '0' && cstr[i] <= '9')

			{

				//ÿ����һ����0-9����ַ����ͽ������뵽num��       

				num = num * 10 + (cstr[i] - '0');//��һ�����뵽num��ʱҪ������һ��*10�Ľ��������һ�ε�������һλ��ʮ�����£� 



				//�������������򷵻�0

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