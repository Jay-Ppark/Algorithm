#include<iostream>
using namespace std;
int op[4];
int number[11];
int N;
int answeroper[11];
int minans=1000000000;
int maxans=-1000000000;
int cal(){
	int result=number[0];
	for(int i=0;i<N-1;i++){
		if(answeroper[i]==0){
			result=result+number[i+1];
		}
		else if(answeroper[i]==1){
			result=result-number[i+1];
		}
		else if(answeroper[i]==2){
			result=result*number[i+1];
		}
		else{
			result=result/number[i+1];
		}
	}
	return result;
}
void dfs(int cnt){
	if(cnt==N-1){
		int tmp = cal();
		if(tmp>maxans){
			maxans=tmp;
		}
		if(tmp<minans){
			minans=tmp;
		}
		return;
	}
	for(int i=0;i<4;i++){
		if(op[i]>0){
			op[i]--;
			answeroper[cnt]=i;
			dfs(cnt+1);
			op[i]++;
		}
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		number[i]=tmp;
	}
	cin>>op[0]>>op[1]>>op[2]>>op[3];
	dfs(0);
	cout<<maxans<<'\n'<<minans;
	return 0;
}