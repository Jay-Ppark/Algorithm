#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int M,N,H;
int tomatomap[100][100][100];
int nottomato;
int days;
int dz[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dx[6]={0,0,0,0,-1,1};
vector<pair<pair<int,int>,int>> tomato;
void BFS(){
	queue<pair<pair<int,int>,int>> q;
	for(int i=0;i<tomato.size();i++){
		q.push({{tomato[i].first.first,tomato[i].first.second},tomato[i].second});
	}
	while(!q.empty()){
		int qsize=q.size();
		days++;
		for(int qs=0;qs<qsize;qs++){
			int z=q.front().second;
			int y=q.front().first.first;
			int x=q.front().first.second;
			q.pop();
			for(int d=0;d<6;d++){
				int nz=z+dz[d];
				int ny=y+dy[d];
				int nx=x+dx[d];
				if(nz>=0&&nz<H&&ny>=0&&ny<N&&nx>=0&&nx<M){
					if(tomatomap[nz][ny][nx]==0){
						q.push({{ny,nx},nz});
						tomatomap[nz][ny][nx]=1;
						nottomato--;
					}
				}
			}
		}
	}
}
int main(void){
	cin>>M>>N>>H;
	for(int z=0;z<H;z++){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>tomatomap[z][i][j];
				if(tomatomap[z][i][j]==1){
					tomato.push_back({{i,j},z});
				}
				else if(tomatomap[z][i][j]==0){
					nottomato++;
				}
			}
		}
	}
	BFS();
	if(nottomato>0){
		cout<<-1;
	}
	else{
		cout<<days-1;
	}
	return 0;
}