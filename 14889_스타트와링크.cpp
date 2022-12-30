#include<iostream>
using namespace std;
int N;
int teamscore[20][20];
bool visited[20];
int tmpmin=100000000;
int cal(){
	int trueteam=0;
	int falseteam=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visited[i]&&visited[j]){
				trueteam=trueteam+teamscore[i][j];
			}
			else if(!visited[i]&&!visited[j]){
				falseteam=falseteam+teamscore[i][j];
			}
		}
	}
	if(trueteam>falseteam){
		return trueteam-falseteam;
	}
	else{
		return falseteam-trueteam;
	}
}
void dfs(int cnt,int next){
	if(cnt==N/2){
		int tmp=cal();
		if(tmpmin>tmp){
			tmpmin=tmp;
		}
		return;
	}
	for(int i=next;i<N;i++){
		if(!visited[i]){
			visited[i]=true;
			dfs(cnt+1,i+1);
			visited[i]=false;
		}
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>teamscore[i][j];
		}
	}
	dfs(0,0);
	cout<<tmpmin;
	return 0;
}