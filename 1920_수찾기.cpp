#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int findNum(int N,int t){
	int start_index=0;
	int end_index=N;
	while(start_index<=end_index){
		int mid_index = (start_index+end_index)/2;
		int mid_value = arr[mid_index];
		if(mid_value<t){
			start_index=mid_index+1;
		}
		else if(mid_value>t){
			end_index=mid_index-1;
		}
		else{
			return 1;
		}
	}
	return 0;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		arr[i]=tmp;
	}
	sort(arr,arr+N);
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		cout<<findNum(N-1,tmp)<<'\n';
	}
	return 0;
}