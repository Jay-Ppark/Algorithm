#include<iostream>
using namespace std;
int arr[10001];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		arr[tmp]++;
	}
	for(int i=1;i<=10000;i++){
		if(arr[i]>0){
			for(int j=0;j<arr[i];j++){
				cout<<i<<'\n';
			}
		}
	}
	return 0;
}