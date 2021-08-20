#include<iostream>
#include<algorithm>
using namespace std;
int arr[500000];
int findNum(int target, int N){
	int startindex=0;
	int endindex=N;
	while(startindex<=endindex){
		int midindex = (startindex + endindex) / 2;
		int midval = arr[midindex];
		if(midval < target){
			startindex = midindex + 1;
		}
		else if(midval > target){
			endindex = midindex - 1;
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
		cin>>arr[i];
	}
	sort(arr,arr+N);
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		cout<<findNum(tmp,N-1)<<" ";
	}
	return 0;
}