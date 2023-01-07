#include<iostream>
using namespace std;
int N;
int num[11];
int opnum[4];
int opchosen[11];
int maxnum=-1000000000;
int minnum=1000000000;
int cal(){
	int result=num[0];
	for(int i=0;i<N-1;i++){
		if(opchosen[i]==0){
			result=result+num[i+1];
		}
		else if(opchosen[i]==1){
			result=result-num[i+1];
		}
		else if(opchosen[i]==2){
			result=result*num[i+1];
		}
		else{
			result=result/num[i+1];
		}
	}
	return result;
}
void dfs(int cnt){
	if(cnt==N-1){
		int tmp=cal();
		if(tmp>maxnum){
			maxnum=tmp;
		}
		if(tmp<minnum){
			minnum=tmp;
		}
	}
	for(int i=0;i<4;i++){
		if(opnum[i]>0){
			opnum[i]--;
			opchosen[cnt]=i;
			dfs(cnt+1);
			opnum[i]++;
		}
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		cin>>opnum[i];
	}
	dfs(0);
	cout<<maxnum<<'\n'<<minnum;
	return 0;
}