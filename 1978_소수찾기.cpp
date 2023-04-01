#include<iostream>
using namespace std;
bool isprime(int n){
	if(n==1){
		return false;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(void){
	int N;
	cin>>N;
	int answer=0;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		if(isprime(tmp)){
			answer++;
		}
	}
	cout<<answer;
	return 0;
}