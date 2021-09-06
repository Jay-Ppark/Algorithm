#include<iostream>
#include<string>
using namespace std;
string white = "WBWBWBWB";
string black = "BWBWBWBW";
char board[50][50];
int height, width;
int calboard(int h, int w){
	if (h+8 > height || w+8 > width){
		return -1;
	}
	int cntW=0;
	int cntB=0;
	int sindex=0;
	for(int i=h;i<h+8;i++){
		sindex=0;
		for(int j=w;j<w+8;j++){
			if(i%2==0){
				if(board[i][j]!=white[sindex]){
					cntW++;
				}
				if(board[i][j]!=black[sindex]){
					cntB++;
				}
			}
			else{
				if(board[i][j]!=black[sindex]){
					cntW++;
				}
				if(board[i][j]!=white[sindex]){
					cntB++;
				}
			}
			sindex++;
		}
	}
	if(cntW>cntB){
		return cntB;
	}
	else{
		return cntW;
	}
}
int main(void){
	cin>>height>>width;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			cin>>board[i][j];
		}
	}
	int mincnt=65;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			int tmpcnt = calboard(i,j);
			if(tmpcnt!=-1){
				if(mincnt>tmpcnt){
					mincnt=tmpcnt;
				}
			}
		}
	}
	cout<<mincnt;
	return 0;
}