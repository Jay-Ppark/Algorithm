#include<iostream>
using namespace std;
int N,M,K;
int veg[50][50];
bool visited[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int cnt=0;
void DFS(int y,int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny>=0&&ny<N&&nx>=0&&nx<M){
			if(!visited[ny][nx]&&veg[ny][nx]==1){
				DFS(ny,nx);
			}
		}
	}
}
void init(){
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			visited[i][j]=false;
			veg[i][j]=0;
		}
	}
	cnt=0;
}
int main(void){
	int testcase;
	cin>>testcase;
	for(int t=0;t<testcase;t++){
		cin>>M>>N>>K;
		for(int i=0;i<K;i++){
			int tmpx,tmpy;
			cin>>tmpx>>tmpy;
			veg[tmpy][tmpx]=1;
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(!visited[i][j]&&veg[i][j]==1){
					DFS(i,j);
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
		init();
	}
	return 0;
}