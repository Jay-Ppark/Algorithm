#include<iostream>
using namespace std;
char arr[65][65];
bool check(int y,int x,int z){
	for(int i=y;i<y+z;i++){
		for(int j=x;j<x+z;j++){
			if(arr[y][x]!=arr[i][j]){
				return false;
			}
		}
	}
	return true;
}
void countarr(int y,int x,int z){
	if(check(y,x,z)){
		cout<<arr[y][x];
		return;
	}
	int n=z/2;
	cout<<"(";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			countarr(y+i*n,x+j*n,n);
		}
	}
	cout<<")";
}
int main(void){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	countarr(0,0,N);
	return 0;
}