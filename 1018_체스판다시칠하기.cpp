#include<iostream>
#include<string>
using namespace std;
string white = "WBWBWBWB";
string black = "BWBWBWBW";
char board[50][50];
int width, height;
int calculate(int h, int w){
	if(h+8>height || w+8>width){
		return -1;
	}
	int cntw = 0;
	int cntb = 0;
	for(int i=h;i<h+8;i++){
		int index=0;
		for(int j=w;j<w+8;j++){
			if(i%2==0){
				if(board[i][j]!=white[index]){
					cntw++;
				}
				if(board[i][j]!=black[index]){
					cntb++;
				}
			}
			else{
				if(board[i][j]!=white[index]){
					cntb++;
				}
				if(board[i][j]!=black[index]){
					cntw++;
				}
			}
			index++;
		}
	}
	if(cntw<=cntb){
		return cntw;
	}
	else{
		return cntb;
	}
}
int main(void){
	cin>>height>>width;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			cin>>board[i][j];
		}
	}
	int mincnt = 100;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			int tmpmin = calculate(i,j);
			if(tmpmin!=-1){
				if(mincnt>tmpmin){
					mincnt=tmpmin;
				}
			}
		}
	}
	cout<<mincnt;
	return 0;
}