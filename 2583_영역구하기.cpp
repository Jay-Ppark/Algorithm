#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int M,N,K;
bool rec[100][100];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
vector<int> v;
void BFS(int xx,int yy){
	int cnt=1;
	queue<pair<int,int>> q;
	q.push({xx,yy});
	rec[xx][yy]=true;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int ny=y+dy[d];
			int nx=x+dx[d];
			if(ny>=0&&ny<M&&nx>=0&&nx<N){
				if(!rec[nx][ny]){
					cnt++;
					rec[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	v.push_back(cnt);
}
int main(void){
	cin>>M>>N>>K;
	for(int t=0;t<K;t++){
		int tmpx,tmpy,ttmpx,ttmpy;
		cin>>tmpx>>tmpy>>ttmpx>>ttmpy;
		for(int i=tmpy;i<ttmpy;i++){
			for(int j=tmpx;j<ttmpx;j++){
				rec[j][i]=true;
			}
		}
	}
	int answer=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(!rec[j][i]){
				answer++;
				BFS(j,i);
			}
		}
	}
	cout<<answer<<'\n';
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}