#include<iostream>
using namespace std;
int fib2(int n){
	if (n <= 2){
		return 1;
	}
	return fib2(n - 1) + fib2(n - 2);
}
int fib1(int n){
	if (n <= 2){
		return 1;
	}
	int f1 = 1, f2 = 1, f;
	for (int i = 3; i <= n; i++){
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	return f;
}
int main(){
	int n;
	int sum = 0;
	while (cin >> n){
		sum = fib1(n);
		cout << sum << endl;
	}
	return 0;
}




#include<iostream>
#include<string>
using namespace std;
bool match(const char*pattern, const char*str){
	if (*pattern == '\0'&&*str == '\0'){
		return true;
	}
	if (*pattern == '\0' || *str == '\0'){
		return false;
	}

	if (*pattern == '?'){
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*'){
		return match(pattern + 1, str + 1) || match(pattern + 1, str) || match(pattern, str + 1);
	}
	else if (*pattern == *str){
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main(){
	string pattern, str;
	while (cin >> pattern >> str){
		int ret = match(pattern.c_str(), str.c_str());
		if (ret){
			cout << "true" << endl;
		}
		else{
			cout << "false" << endl;
		}
	}
	return 0;
}