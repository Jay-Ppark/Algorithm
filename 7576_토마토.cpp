#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M;
int tomatomap[1000][1000];
vector<pair<int,int>> tomato;
int nottomato;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int days=0;
void BFS(){
	queue<pair<int,int>> q;
	for(int i=0;i<tomato.size();i++){
		q.push({tomato[i].first,tomato[i].second});
	}
	while(!q.empty()){
		int qsize=q.size();
		days++;
		for(int qs=0;qs<qsize;qs++){
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			for(int d=0;d<4;d++){
				int ny=y+dy[d];
				int nx=x+dx[d];
				if(ny>=0&&ny<N&&nx>=0&&nx<M){
					if(tomatomap[ny][nx]==0){
						q.push({ny,nx});
						tomatomap[ny][nx]=1;
						nottomato--;
					}
				}
			}
		}
	}
}
int main(void){
	cin>>M>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>tomatomap[i][j];
			if(tomatomap[i][j]==1){
				tomato.push_back({i,j});
			}
			else if(tomatomap[i][j]==0){
				nottomato++;
			}
		}
	}
	if(nottomato>0){
		BFS();
		if(nottomato>0){
			cout<<-1;
		}
		else{
			cout<<days-1;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}