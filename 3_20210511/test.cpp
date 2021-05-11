namespace syc
{
	class string{
	public:
		string(const char* str = ""){
			if (nullptr == str){
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string&s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}
		string&operator=(string s){
			swap(_str, s._str);
			return *this;
		}
		~string(){
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
using namespace syc;
int main(){
	string s;
	return 0;
}



class string{
public:
	//构造
	string(const char* str = ""){
		if (nullptr == str){
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//拷贝构造
	string(const string&s)
		:_str(nullptr)
	{
		string tmp(s._str);
		swap(_str, tmp._str);
	}
	//赋值
	string&operator=(string s){
		swap(_str, s._str);
		return *this;
	}
	//析构
	~string(){
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

class string
{
public:
	string(const char*str = ""){
		if (nullptr == str){
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
	}
	//string(const string&s)
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}
	//string& operator=(const string&s){
	//	if (this != &s){
	//		char* pstr = new char[strlen(s._str) + 1];
	//		strcpy(pstr, s._str);
	//		delete[]_str;
	//		_str = pstr;
	//	}
	//	return *this;
	//}
	~string(){
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
void test(){
	string s1("hello");
	string s2(s1);
}





class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int value1 = 0, value2 = 0, next = 0;
		string retstr;
		while (end1 >= 0 || end2 >= 0){
			if (end1 >= 0){
				value1 = num1[end1] - '0';
			}
			else{
				value1 = 0;
			}
			if (end2 >= 0){
				value2 = num2[end2] - '0';
			}
			else{
				value2 = 0;
			}
			int valueret = value1 + value2 + next;
			if (valueret > 9){
				next = 1;
				valueret -= 10;
			}
			else{
				next = 0;
			}
			retstr += (valueret + '0');
			end1--;
			end2--;
		}
		if (next == 1){
			retstr += '1';
		}
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
};




class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int next = 0;
		string retstr;
		while (end1 >= 0 || end2 >= 0){
			int val1 = 0, val2 = 0;
			if (end1 >= 0){
				val1 = num1[end1] - '0';
			}
			if (end2 >= 0){
				val2 = num2[end2] - '0';
			}
			int ret = val1 + val2 + next;
			if (ret > 9){
				next = 1;
				ret -= 10;
			}
			else{
				next = 0;
			}
			//retstr.insert(retstr.begin(),ret+'0');-头插
			retstr += (ret + '0');
			end1--;
			end2--;
		}
		if (next == 1){
			//retstr.insert(retstr.begin(),'1');-头插
			retstr += '1';
		}
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
};