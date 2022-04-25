#include<iostream>
using namespace std;
int N,M;
int starty,startx;
int dice[4][3];
int gamemap[20][20];
int ops[1000];
int main(void){
	int opnum;
	cin>>N>>M>>starty>>startx>>opnum;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>gamemap[i][j];
		}
	}
	for(int i=0;i<opnum;i++){
		cin>>ops[i];
	}
	for(int i=0;i<opnum;i++){
		//동
		if(ops[i]==1){
			if(startx+1>=M){
				continue;
			}
			else{
				startx=startx+1;
				int tmp=dice[1][1];
				dice[1][1]=dice[1][0];
				dice[1][0]=dice[3][1];
				dice[3][1]=dice[1][2];
				dice[1][2]=tmp;
				if(gamemap[starty][startx]==0){
					gamemap[starty][startx]=dice[3][1];
				}
				else{
					dice[3][1]=gamemap[starty][startx];
					gamemap[starty][startx]=0;
				}
			}
		}
		//서
		else if(ops[i]==2){
			if(startx-1<0){
				continue;
			}
			else{
				startx=startx-1;
				int tmp=dice[1][1];
				dice[1][1]=dice[1][2];
				dice[1][2]=dice[3][1];
				dice[3][1]=dice[1][0];
				dice[1][0]=tmp;
				if(gamemap[starty][startx]==0){
					gamemap[starty][startx]=dice[3][1];
				}
				else{
					dice[3][1]=gamemap[starty][startx];
					gamemap[starty][startx]=0;
				}
			}
		}
		//북
		else if(ops[i]==3){
			if(starty-1<0){
				continue;
			}
			else{
				starty=starty-1;
				int tmp=dice[1][1];
				dice[1][1]=dice[2][1];
				dice[2][1]=dice[3][1];
				dice[3][1]=dice[0][1];
				dice[0][1]=tmp;
				if(gamemap[starty][startx]==0){
					gamemap[starty][startx]=dice[3][1];
				}
				else{
					dice[3][1]=gamemap[starty][startx];
					gamemap[starty][startx]=0;
				}
			}
		}
		//남
		else{
			if(starty+1>=N){
				continue;
			}
			else{
				starty=starty+1;
				int tmp=dice[1][1];
				dice[1][1]=dice[0][1];
				dice[0][1]=dice[3][1];
				dice[3][1]=dice[2][1];
				dice[2][1]=tmp;
				if(gamemap[starty][startx]==0){
					gamemap[starty][startx]=dice[3][1];
				}
				else{
					dice[3][1]=gamemap[starty][startx];
					gamemap[starty][startx]=0;
				}
			}
		}
		cout<<dice[1][1]<<'\n';
	}
	return 0;
}