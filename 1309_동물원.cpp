#include<iostream>
using namespace std;
int N;
int dp[3][100000];
int main(void){
	cin>>N;
	//0은 왼쪽,1은 오른쪽,2는 빈칸
	dp[0][0]=1;
	dp[1][0]=1;
	dp[2][0]=1;
	for(int i=1;i<N;i++){
		dp[0][i]=(dp[1][i-1]+dp[2][i-1])%9901;
		dp[1][i]=(dp[0][i-1]+dp[2][i-1])%9901;
		dp[2][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])%9901;
	}
	cout<<(dp[0][N-1]+dp[1][N-1]+dp[2][N-1])%9901;
	return 0;
}