#include<iostream>
#include<string>
using namespace std;
char boardgame[50][50];
string wstart="WBWBWBWB";
string bstart="BWBWBWBW";
int cal(int N,int M){
	int wdiff=0;
	int bdiff=0;
	for(int i=N;i<N+8;i++){
		int index=0;
		for(int j=M;j<M+8;j++){
			if(i%2==0){
				if(wstart[index]!=boardgame[i][j]){
					wdiff++;
				}
				if(bstart[index]!=boardgame[i][j]){
					bdiff++;
				}
			}
			else{
				if(bstart[index]!=boardgame[i][j]){
					wdiff++;
				}
				if(wstart[index]!=boardgame[i][j]){
					bdiff++;
				}
			}
			index++;
		}
	}
	if(wdiff<bdiff){
		return wdiff;
	}
	else{
		return bdiff;
	}
}
int main(void){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>boardgame[i][j];
		}
	}
	int answer=65;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i+8<=N&&j+8<=M){
				int tmpmin = cal(i,j);
				if(tmpmin<answer){
					answer=tmpmin;
				}
			}
		}
	}
	cout<<answer;
	return 0;
}