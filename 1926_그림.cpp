#include<iostream>
#include<queue>
using namespace std;
int board[500][500];
int n,m;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int BFS(int yy,int xx){
	queue<pair<int,int>> q;
	q.push({yy,xx});
	board[yy][xx]=0;
	int cnt=1;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int ny=y+dy[d];
			int nx=x+dx[d];
			if(ny>=0&&ny<n&&nx>=0&&nx<m){
				if(board[ny][nx]==1){
					q.push({ny,nx});
					board[ny][nx]=0;
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	int pcnt=0;
	int maxcnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]==1){
				int tmp=BFS(i,j);
				if(tmp>maxcnt){
					maxcnt=tmp;
				}
				pcnt++;
			}
		}
	}
	cout<<pcnt<<'\n'<<maxcnt;
	return 0;
}