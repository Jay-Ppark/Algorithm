#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long cal(int n) {
	long long result = 0;
	for(int start=1,len=1;start<=n;start*=10,len++){
		int end = start * 10 - 1;
		if (end >= n) {
			result +=(long)((n - start + 1) * len);
		}
		else {
			result += (long)((end - start + 1) * len);
		}
	}
	return result;
}
int main(void) {
	int N, k;
	cin >> N >> k;
	if (cal(N) < k) {
		cout << -1;
		return 0;
	}
	int leftn = 1;
	int rightn = N;
	int ans = 0;
	while (leftn <= rightn) {
		int midn = (leftn + rightn) / 2;
		if (cal(midn) < k) {
			leftn = midn + 1;
		}
		else {
			ans = midn;
			rightn = midn - 1;
		}
	}
	//cout << cal(ans);
	string s = to_string(ans);
	long long l = cal(ans);
	//cout << s.size() << " " << l << " " << k << " " << ans;
	cout << s[s.size() - (l - k) - 1];
	return 0;
}