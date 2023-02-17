#include<iostream>
using namespace std;
int arr[20];
int arrSize;
int resultSum;
int cnt;
int len;
void findAll(int startIndex,int result){
	if(startIndex==arrSize){
		if(result==resultSum){
			cnt++;
		}
        return;
	}
	findAll(startIndex+1,result);
    findAll(startIndex+1,result+arr[startIndex]);
}
int main(void){
	cin>>arrSize>>resultSum;
	for(int i=0;i<arrSize;i++){
		cin>>arr[i];
	}
	findAll(0,0);
    if(resultSum==0){
        cout<<cnt-1;
    }
    else{
        cout<<cnt;
    }
	return 0;
}