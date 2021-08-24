#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> A;
vector<int> B;
int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < N; i++){
		int tmp;
		cin>>tmp;
		B.push_back(tmp);
	}
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(),B.end());
	int sum = 0;
	for (int i = 0; i < N; i++){
		sum = sum + A[i] * B[i];
	}
	cout << sum;
	return 0;
}