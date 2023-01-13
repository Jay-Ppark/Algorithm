#include<iostream>
using namespace std;
int N,M,starty,startx,ordernum;
int dice[4][3];
int gamemap[20][20];
void rolldice(int d){
	int tmpdice[4][3];
	if(d==0){
		tmpdice[0][1]=dice[0][1];
		tmpdice[1][0]=dice[3][1];
		tmpdice[1][1]=dice[1][0];
		tmpdice[1][2]=dice[1][1];
		tmpdice[2][1]=dice[2][1];
		tmpdice[3][1]=dice[1][2];
	}
	else if(d==1){
		tmpdice[0][1]=dice[0][1];
		tmpdice[1][0]=dice[1][1];
		tmpdice[1][1]=dice[1][2];
		tmpdice[1][2]=dice[3][1];
		tmpdice[2][1]=dice[2][1];
		tmpdice[3][1]=dice[1][0];
	}
	else if(d==2){
		tmpdice[0][1]=dice[1][1];
		tmpdice[1][0]=dice[1][0];
		tmpdice[1][1]=dice[2][1];
		tmpdice[1][2]=dice[1][2];
		tmpdice[2][1]=dice[3][1];
		tmpdice[3][1]=dice[0][1];
	}
	else{
		tmpdice[0][1]=dice[3][1];
		tmpdice[1][0]=dice[1][0];
		tmpdice[1][1]=dice[0][1];
		tmpdice[1][2]=dice[1][2];
		tmpdice[2][1]=dice[1][1];
		tmpdice[3][1]=dice[2][1];
	}
	dice[0][1]=tmpdice[0][1];
	dice[1][0]=tmpdice[1][0];
	dice[1][1]=tmpdice[1][1];
	dice[1][2]=tmpdice[1][2];
	dice[2][1]=tmpdice[2][1];
	dice[3][1]=tmpdice[3][1];
	if(gamemap[starty][startx]==0){
		gamemap[starty][startx]=dice[3][1];
	}
	else{
		dice[3][1]=gamemap[starty][startx];
		gamemap[starty][startx]=0;
	}
	cout<<dice[1][1]<<'\n';
}
void movedice(int t){
	if(t==0){
		if(startx+1<M){
			startx++;
			rolldice(0);
		}
	}
	else if(t==1){
		if(startx-1>=0){
			startx--;
			rolldice(1);
		}
	}
	else if(t==2){
		if(starty-1>=0){
			starty--;
			rolldice(2);
		}
	}
	else{
		if(starty+1<N){
			starty++;
			rolldice(3);
		}
	}
}
int main(void){
	cin>>N>>M>>starty>>startx>>ordernum;
	dice[0][1]=0;
	dice[1][0]=0;
	dice[1][1]=0;
	dice[1][2]=0;
	dice[2][1]=0;
	dice[3][1]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>gamemap[i][j];
		}
	}
	for(int t=0;t<ordernum;t++){
		int tmporder;
		cin>>tmporder;
		movedice(tmporder-1);
	}
	return 0;
}