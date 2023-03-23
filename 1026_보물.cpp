#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
vector<int> B;
bool comp(int &a,int &b){
	if(a>b){
		return true;
	}
	else{
		return false;
	}
}
int main(void){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		B.push_back(tmp);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end(),comp);
	int result=0;
	for(int i=0;i<N;i++){
		result=result+A[i]*B[i];
	}
	cout<<result;
	return 0;
}