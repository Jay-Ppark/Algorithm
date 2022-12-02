#include<iostream>
using namespace std;
int N;
int red[1000];
int green[1000];
int blue[1000];
int house[3][1000];
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>red[i]>>green[i]>>blue[i];
	}
	house[0][0]=red[0];
	house[1][0]=green[0];
	house[2][0]=blue[0];
	for(int i=1;i<N;i++){
		house[0][i]=red[i]+min(house[1][i-1],house[2][i-1]);
		house[1][i]=green[i]+min(house[0][i-1],house[2][i-1]);
		house[2][i]=blue[i]+min(house[0][i-1],house[1][i-1]);
	}
	cout<<min(house[2][N-1],min(house[0][N-1],house[1][N-1]));
	return 0;
}