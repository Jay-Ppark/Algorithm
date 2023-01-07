#include<iostream>
using namespace std;
int arr[9];
bool visited[9];
int N,M;
void dfs(int n,int cnt){
	if(cnt==M){
		for(int i=1;i<=N;i++){
			if(visited[i]){
				cout<<i<<" ";
			}
		}
		cout<<'\n';
		return;
	}
	for(int i=n+1;i<=N;i++){
		if(!visited[i]){
			visited[i]=true;
			dfs(i,cnt+1);
			visited[i]=false;
		}
	}
}
int main(void){
	cin>>N>>M;
	dfs(0,0);
	return 0;
}