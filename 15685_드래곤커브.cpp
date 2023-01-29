#include<iostream>
#include<vector>
using namespace std;
int N;
bool visited[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int countsquare(){
	int cnt=0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(visited[i][j]){
				if(i+1<=100&&j+1<=100){
					if(visited[i+1][j]&&visited[i][j+1]&&visited[i+1][j+1]){
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		vector<int> dragond;
		dragond.push_back(d);
		for(int j=1;j<=g;j++){
			int dsize=dragond.size();
			for(int k=dsize-1;k>=0;k--){
				dragond.push_back((dragond[k]+1)%4);
			}
		}
		visited[x][y]=true;
		for(int j=0;j<dragond.size();j++){
			x=x+dx[dragond[j]];
			y=y+dy[dragond[j]];
			visited[x][y]=true;
		}
	}
	cout<<countsquare();
	return 0;
}