class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};



#include<iostream>
#include<cmath>
using namespace std;
bool Isprime(int m){
	for (int i = 2; i <= sqrt(m); i++){
		if (m%i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int num;
	while (cin >> num){
		for (int i = num / 2; i >= 0; i--){
			if (Isprime(i) && Isprime(num - i)){
				cout << i << endl << num - i << endl;
				break;
			}
		}
	}
	return 0;
}




class Solution {
public:
	bool Isletterornumber(char ch){
		return (ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'z');
	}
	bool isPalindrome(string s) {
		for (auto&ch : s){
			if (ch >= 'A'&&ch <= 'Z'){
				ch += 32;
			}
		}
		int begin = 0, end = s.size() - 1;
		while (begin < end){
			while (begin < end&&!Isletterornumber(s[begin])){
				begin++;
			}
			while (begin < end&&!Isletterornumber(s[end])){
				end--;
			}
			if (s[begin] != s[end]){
				return false;
			}
			else{
				begin++;
				end--;
			}
		}
		return true;
	}
};



class Solution {
public:
	bool Isletterornumber(char ch){
		return (ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'z');
	}
	bool isPalindrome(string s) {
		if (s.empty()){
			return true;
		}
		for (auto&ch : s){
			if (ch >= 'A'&&ch <= 'Z'){
				ch += 32;
			}
		}
		int begin = 0, end = s.size() - 1;
		while (begin < end){
			while (begin < end&&!Isletterornumber(s[begin])){
				begin++;
			}
			while (begin < end&&!Isletterornumber(s[end])){
				end--;
			}
			if (s[begin] != s[end]){
				return false;
			}
			else{
				begin++;
				end--;
			}
		}
		return true;
	}
};



