#include<iostream>
#include<queue>
using namespace std;
int N,M;
char maze[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
bool visited[100][100];
int BFS(){
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},1});
	visited[0][0]=true;
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int cnt=q.front().second;
		q.pop();
		if(y==N-1&&x==M-1){
			return cnt;
		}
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny>=0&&ny<N&&nx>=0&&nx<M){
				if(maze[ny][nx]=='1' && !visited[ny][nx]){
					q.push({{ny,nx},cnt+1});
					visited[ny][nx]=true;
				}
			}
		}
	}
	return 0;
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>maze[i][j];
		}
	}
	cout<<BFS();
	return 0;
}