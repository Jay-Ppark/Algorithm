#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M;
int vmap[8][8];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
vector<pair<int,int>> virus;
int answer=0;
int spreadvirus(){
	int copyvmap[8][8]={0,};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			copyvmap[i][j]=vmap[i][j];
		}
	}
	queue<pair<int,int>> q;
	for(int i=0;i<virus.size();i++){
		q.push({virus[i].first,virus[i].second});
	}
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny>=0&&ny<N&&nx>=0&&nx<M){
				if(copyvmap[ny][nx]==0){
					q.push({ny,nx});
					copyvmap[ny][nx]=2;
				}
			}
		}
	}
	int result=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(copyvmap[i][j]==0){
				result++;
			}
		}
	}
	return result;
}
void DFS(int cnt){
	if(cnt==3){
		int tmp = spreadvirus();
		if(answer<tmp){
			answer=tmp;
		}
		return;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(vmap[i][j]==0){
				vmap[i][j]=1;
				DFS(cnt+1);
				vmap[i][j]=0;
			}
		}
	}
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>vmap[i][j];
			if(vmap[i][j]==2){
				virus.push_back({i,j});
			}
		}
	}
	DFS(0);
	cout<<answer;
	return 0;
}