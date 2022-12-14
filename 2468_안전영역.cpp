#include<iostream>
#include<queue>
using namespace std;
int N;
int bulidingmap[100][100];
bool visited[100][100];
int maxanswer=1;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
void rain(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			bulidingmap[i][j]--;
		}
	}
}
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=false;
		}
	}
}
void BFS(int yy,int xx){
	queue<pair<int,int>> q;
	q.push({yy,xx});
	visited[yy][xx]=true;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int ny=y+dy[d];
			int nx=x+dx[d];
			if(ny>=0&&ny<N&&nx>=0&&nx<N){
				if(bulidingmap[ny][nx]>0&&!visited[ny][nx]){
					visited[ny][nx]=true;
					q.push({ny,nx});
				}
			}
		}
	}
}
int calzone(){
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(bulidingmap[i][j]>0&&!visited[i][j]){
				BFS(i,j);
				cnt++;
			}
		}
	}
	return cnt;
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>bulidingmap[i][j];
		}
	}
	for(int i=0;i<101;i++){
		rain();
		init();
		int tmpmax=calzone();
		if(tmpmax>maxanswer){
			maxanswer=tmpmax;
		}
		if(tmpmax==0){
			break;
		}
	}
	cout<<maxanswer;
	return 0;
}