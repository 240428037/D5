class Solution {
public:
	int fib(int n) {
		if (n == 0 || n == 1){
			return n;
		}
		int f, f1 = 0, f2 = 1;
		for (int i = 2; i <= n; i++){
			f = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = f;
		}
		return f;
	}
};



class Solution {
public:
	int fib(int n) {
		if (n == 0 || n == 1){
			return n;
		}
		vector<int>dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++){
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		}
		return dp[n];
	}
};


class Solution {
public:
	int fib(int n) {
		if (n == 0 || n == 1){
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}
};



class Solution {
public:
	int numWays(int n) {
		if (n == 0)return 1;
		if (n == 1 || n == 2){
			return n;
		}
		int f, f1 = 1, f2 = 2;
		for (int i = 3; i <= n; i++){
			f = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = f;
		}
		return f;
	}
};



class Solution {
public:
	int numWays(int n) {
		if (n == 0)return 1;
		if (n == 1)return 1;
		if (n == 2)return 2;
		int f, f1 = 1, f2 = 2;
		for (int i = 3; i <= n; i++){
			f = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = f;
		}
		return f;
	}
};


class Solution {
public:
	int fib(int n) {
		if (n == 0)return 0;
		if (n == 1)return 1;
		int f, f1 = 0, f2 = 1;
		for (int i = 2; i <= n; i++){
			f = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = f;
		}
		return f;
	}
};