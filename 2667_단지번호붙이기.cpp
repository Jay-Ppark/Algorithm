#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
char apart[25][25];
bool visited[25][25];
vector<int> answer;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int cnt=0;
void cal(int y,int x){
	cnt++;
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny>=0&&ny<N&&nx>=0&&nx<N){
			if(!visited[ny][nx]&&apart[ny][nx]=='1'){
				cal(ny,nx);
			}
		}
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>apart[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]&&apart[i][j]=='1'){
				cal(i,j);
				answer.push_back(cnt);
				cnt=0;
			}
		}
	}
	sort(answer.begin(),answer.end());
	cout<<answer.size()<<"\n";
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<'\n';
	}
	return 0;
}