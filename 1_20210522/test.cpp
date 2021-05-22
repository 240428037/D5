#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int>v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; i++){
			cin >> v[i];
		}
		std::sort(v.begin(), v.end());
		for (int i = 0; i < 3 * n;i++)
		{
			cout << v[i] <<" ";
		}
		int sum = 0;
		for (int i = n; i < 3 * n - 2; i += 2){
			sum += v[i];
		}
		cout << sum << endl;
	}
}




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int>v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long sum = 0;
		for (int i = n; i <= 3 * n - 2; i += 2){
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int count[256] = { 0 };
	for (int i = 0; i < s2.size(); i++){
		count[s2[i]]++;
	}
	string ret;
	for (int i = 0; i < s1.size(); i++){
		if (count[s1[i]] == 0){
			ret += s1[i];
		}
	}
	cout << ret << endl;
	return 0;
}




#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int count[256] = { 0 };
	for (int i = 0; i < s2.size(); i++){
		count[s2[i]]++;
	}
	string ret;
	for (int i = 0; i < s1.size(); i++){
		if (count[s1[i]] == 0){
			ret += s1[i];
		}
	}
	cout << ret << endl;
	return 0;
}



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto left = s.begin();
	while (left != s.end()){
		auto right = left;
		while (right != s.end() && *right != ' '){
			right++;
		}
		reverse(left, right);
		if (right != s.end()){
			left = right + 1;
		}
		else{
			left = right;
		}
	}
	cout << s << endl;
	return 0;
}



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto left = s.begin();
	while (left != s.end()){
		auto right = left;
		while (right != s.end() && *right != ' '){
			right++;
		}
		reverse(left, right);
		if (right != s.end()){
			left = right + 1;
		}
		else{
			left = right;
		}
	}
	cout << s << endl;
	return 0;
}