#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,L,R;
int populationmap[50][50];
bool visited[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=false;
		}
	}
}
void BFS(int y,int x){
	queue<pair<int,int>> q;
	vector<pair<int,int>> calq;
	calq.push_back({y,x});
	q.push({y,x});
	visited[y][x]=true;
	int cnt=1;
	int sum=populationmap[y][x];
	while(!q.empty()){
		int yy=q.front().first;
		int xx=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=yy+dy[i];
			int nx=xx+dx[i];
			if(ny>=0&&ny<N&&nx>=0&&nx<N){
				int result=abs(populationmap[yy][xx]-populationmap[ny][nx]);
				if(!visited[ny][nx]&&result>=L&&result<=R){
					visited[ny][nx]=true;
					q.push({ny,nx});
					calq.push_back({ny,nx});
					cnt++;
					sum=sum+populationmap[ny][nx];
				}
			}
		}
	}
	int result=sum/cnt;
	for(int i=0;i<calq.size();i++){
		populationmap[calq[i].first][calq[i].second]=result;
	}
}
int main(void){
	cin>>N>>L>>R;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>populationmap[i][j];
		}
	}
	int days=-1;
	bool check=true;
	while(check){
		check=false;
		init();
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!visited[i][j]){
					for(int d=0;d<4;d++){
						int y=i+dy[d];
						int x=j+dx[d];
						if(y>=0&&y<N&&x>=0&&x<N){
							int result=abs(populationmap[i][j]-populationmap[y][x]);
							if(result>=L&&result<=R){
								BFS(i,j);
								check=true;
								break;
							}
						}
					}
				}
			}
		}
		days++;
	}
	cout<<days;
	return 0;
}