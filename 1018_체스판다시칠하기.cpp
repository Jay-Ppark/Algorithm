#include<iostream>
using namespace std;
char board[50][50];
int calboard(int h,int w){
	int whitestart=0;
	int blackstart=0;
	for(int i=h;i<h+8;i++){
		for(int j=w;j<w+8;j++){
			if(i%2==0){
				if(j%2==0){
					//W인경우
					if(board[i][j]!='W'){
						whitestart++;
					}
					//B인경우
					else{
						blackstart++;
					}
				}
				else{
					if(board[i][j]!='B'){
						whitestart++;
					}
					else{
						blackstart++;
					}
				}
			}
			else{
				if(j%2==0){
					//W인경우
					if(board[i][j]!='B'){
						whitestart++;
					}
					//B인경우
					else{
						blackstart++;
					}
				}
				else{
					if(board[i][j]!='W'){
						whitestart++;
					}
					else{
						blackstart++;
					}
				}
			}
		}
	}
	if(whitestart<=blackstart){
		return whitestart;
	}
	else{
		return blackstart;
	}
}
int main(void){
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>board[i][j];
		}
	}
	int maxans=1000;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(w-j>=8){
				if(h-i>=8){
					int tmp=calboard(i,j);
					if(tmp<maxans){
						maxans=tmp;
					}
				}
			}
		}
	}
	cout<<maxans;
	return 0;
}