#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
string s1, s2;
int arr[1001][1001];
int main(void) {
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s2[j - 1] == s1[i - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	int result = arr[s1.length()][s2.length()];
	cout << result << '\n';
	if(result!=0) {
		int cnt = 0;
		int s1len = s1.length();
		int s2len = s2.length();
		stack<char> s;
		while (cnt != result) {
			if (arr[s1len][s2len - 1] == arr[s1len][s2len]) {
				s2len--;
			}
			else if (arr[s1len - 1][s2len] == arr[s1len][s2len]) {
				s1len--;
			}
			else if (arr[s1len][s2len] - 1 == arr[s1len - 1][s2len - 1]) {
				s1len--;
				s2len--;
				cnt++;
				s.push(s2[s2len]);
			}
		}
		for (int i = 0; i < cnt; i++) {
			cout<<s.top();
			s.pop();
		}
	}
	
	return 0;
}