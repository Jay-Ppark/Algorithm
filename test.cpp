#include<iostream>
using namespace std;
bool visited[6];
int tcnt=0;
void dfs(int cnt,int y){
	if(cnt==3){
		for(int i=0;i<6;i++){
			if(visited[i]){
				cout<<i;
			}
		}
		tcnt++;
		cout<<"\n";
		return;
	}
	for(int i=y;i<6;i++){
		if(!visited[i]){
			visited[i]=true;
			dfs(cnt+1,i+1);
			visited[i]=false;
		}
	}
}
int main(void){
	dfs(0,0);
	cout<<tcnt;
	return 0;
}