#include<iostream>
using namespace std;
int arr[100000];
int main(void){
	int N,S;
	cin>>N>>S;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	int en=0;
	int cursum=arr[0];
	int minL=100001;
	for(int st=0;st<N;st++){
		while(en<N&&cursum<S){
			en++;
			if(en<N){
				cursum+=arr[en];
			}
		}
		if(en==N){
			break;
		}
		if(minL>(en-st+1)){
			minL=en-st+1;
		}
		cursum-=arr[st];
	}
	if(minL==100001){
		cout<<0;
	}
	else{
		cout<<minL;
	}
	return 0;
}