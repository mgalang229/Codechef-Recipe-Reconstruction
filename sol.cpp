#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e7 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		// set 'sum' to 1
		int sum = 1;
		// create 'visited' boolean vector to mark the places that were visited
		vector<bool> visited((int) s.size(), false);
		for (int i = 0; i < (int) s.size(); i++) {
			// check if the current character is a question mark ('?') and it's not yet visited
			if (s[i] == '?' && !visited[i]) {
				// if yes, then get its palindrome letter equivalent in the string
				char equivalent = s[(int) s.size() - 1 - i];
				// check if it's equivalent is a question mark('?') and if it's not yet visited
				if (equivalent == '?' && !visited[i]) {
					// if yes, then multiply 26 to 'sum' (since any letter can be used)
					sum = (long long) sum * 26 % MOD;
					// mark the equivalent place of its palindrome equivalent as visited
					// (to avoid double calculation because they need to be matched)
					visited[(int) s.size() - 1 - i] = true;
				} else {
					// set the question mark to the appropriate letter that it should be
					s[i] = s[(int) s.size() - 1 - i];
				}
			}
		}
		// for the last step, check if the string is now a palindrome
		bool checker = true;
		for (int i = 0; i < (int) s.size() / 2; i++) {
			if (s[i] != s[(int) s.size() - 1 - i]) {
				checker = false;
			}
		}
		// output 'sum' if the string is a palindrome, otherwise 0
		cout << (checker ? sum : 0) << '\n';
	}
	return 0;
}
