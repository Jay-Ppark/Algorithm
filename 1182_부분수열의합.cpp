#include<iostream>
using namespace std;
bool visited[21];
int arr[21];
int arrSize;
int resultSum;
int cnt;
int len;
void findAll(int startIndex,int result){
	if(len>0){
		if(result==resultSum){
			cnt++;
		}
	}
	for(int i=startIndex;i<arrSize;i++){
		if(!visited[i]){
			len++;
			visited[i]=true;
			findAll(i,result+arr[i]);
			visited[i]=false;
		}
	}
}
int main(void){
	cin>>arrSize>>resultSum;
	for(int i=0;i<arrSize;i++){
		cin>>arr[i];
	}
	findAll(0,0);
	cout<<cnt;
	return 0;
}