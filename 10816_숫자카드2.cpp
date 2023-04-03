#include<iostream>
using namespace std;
int arr[20000001];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		arr[tmp+10000000]++;
	}
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		cout<<arr[tmp+10000000]<<' ';
	}
	return 0;
}