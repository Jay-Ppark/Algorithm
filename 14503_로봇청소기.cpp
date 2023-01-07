#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
int fy,fx,fd;
bool visited[50][50];
int vaczone[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int answer=1;
void BFS(){
	queue<pair<pair<int,int>,int>> q;
	q.push({{fy,fx},fd});
	visited[fy][fx]=true;
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int d=q.front().second;
		q.pop();
		bool cleaned=false;
		for(int i=0;i<4;i++){
			d=d+3;
			d=d%4;
			int ny=y+dy[d];
			int nx=x+dx[d];
			if(ny>=0&&ny<N&&nx>=0&&nx<M){
				if(!visited[ny][nx]&&vaczone[ny][nx]==0){
					q.push({{ny,nx},d});
					visited[ny][nx]=true;
					answer++;
					cleaned=true;
					break;
				}
			}
		}
		if(!cleaned){
			int nd=(d+2)%4;
			int ny=y+dy[nd];
			int nx=x+dx[nd];
			if(ny>=0&&ny<N&&nx>=0&&nx<M){
				if(vaczone[ny][nx]==0){
					q.push({{ny,nx},d});
				}
			}	
		}
	}
}
int main(void){
	cin>>N>>M;
	cin>>fy>>fx>>fd;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>vaczone[i][j];
		}
	}
	BFS();
	cout<<answer;
	return 0;
}