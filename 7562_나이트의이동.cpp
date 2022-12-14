#include<iostream>
#include<queue>
using namespace std;
bool visited[300][300];
int l;
int endy,endx;
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int dx[8]={-2,-1,1,2,2,1,-1,-2};
void init(){
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			visited[i][j]=false;
		}
	}
}
int BFS(int yy,int xx){
	queue<pair<int,int>> q;
	q.push({yy,xx});
	visited[yy][xx]=true;
	int cnt=-1;
	while(!q.empty()){
		int qsize=q.size();
		for(int qs=0;qs<qsize;qs++){
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			if(y==endy&&x==endx){
				while(!q.empty()){
					q.pop();
				}
				break;
			}
			for(int d=0;d<8;d++){
				int ny=y+dy[d];
				int nx=x+dx[d];
				if(ny>=0&&ny<l&&nx>=0&&nx<l){
					if(!visited[ny][nx]){
						q.push({ny,nx});
						visited[ny][nx]=true;
					}
				}
			}
		}
		cnt++;
	}
	return cnt;
}
int main(void){
	int testcase;
	cin>>testcase;
	for(int t=0;t<testcase;t++){
		cin>>l;
		int starty,startx;
		cin>>starty>>startx;
		cin>>endy>>endx;
		int answer=BFS(starty,startx);
		cout<<answer<<'\n';
		init();
	}
}