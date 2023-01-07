#include<iostream>
#include<vector>
using namespace std;
int N,M;
int zone[8][8];
vector<pair<pair<int,int>,int>> cctv;
vector<int> angle;
bool visited[8][8];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int minanswer=100;
void watch(int y,int x,int d){
	if(d==0){
		for(int i=y-1;i>=0;i--){
			if(zone[i][x]==6){
				break;
			}
			else if(zone[i][x]==0&&!visited[i][x]){
				visited[i][x]=true;
			}
		}
	}
	else if(d==1){
		for(int i=x+1;i<M;i++){
			if(zone[y][i]==6){
				break;
			}
			else if(zone[y][i]==0&&!visited[y][i]){
				visited[y][i]=true;
			}
		}
	}
	else if(d==2){
		for(int i=y+1;i<N;i++){
			if(zone[i][x]==6){
				break;
			}
			else if(zone[i][x]==0&&!visited[i][x]){
				visited[i][x]=true;
			}
		}
	}
	else{
		for(int i=x-1;i>=0;i--){
			if(zone[y][i]==6){
				break;
			}
			else if(zone[y][i]==0&&!visited[y][i]){
				visited[y][i]=true;
			}
		}
	}
}
int docctv(){
	for(int i=0;i<cctv.size();i++){
		int y=cctv[i].first.first;
		int x=cctv[i].first.second;
		int t=cctv[i].second;
		if(t==1){
			watch(y,x,angle[i]);
		}
		else if(t==2){
			if(angle[i]%2==0){
				watch(y,x,1);
				watch(y,x,3);
			}
			else{
				watch(y,x,0);
				watch(y,x,2);
			}
		}
		else if(t==3){
			if(angle[i]==0){
				watch(y,x,0);
				watch(y,x,1);
			}
			else if(angle[i]==1){
				watch(y,x,1);
				watch(y,x,2);
			}
			else if(angle[i]==2){
				watch(y,x,2);
				watch(y,x,3);
			}
			else{
				watch(y,x,3);
				watch(y,x,0);
			}
		}
		else if(t==4){
			if(angle[i]==0){
				watch(y,x,3);
				watch(y,x,0);
				watch(y,x,1);
			}
			else if(angle[i]==1){
				watch(y,x,0);
				watch(y,x,1);
				watch(y,x,2);
			}
			else if(angle[i]==2){
				watch(y,x,1);
				watch(y,x,2);
				watch(y,x,3);
			}
			else{
				watch(y,x,2);
				watch(y,x,3);
				watch(y,x,0);
			}
		}
		else{
			watch(y,x,0);
			watch(y,x,1);
			watch(y,x,2);
			watch(y,x,3);
		}
	}
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(zone[i][j]==0&&!visited[i][j]){
				cnt++;
			}
		}
	}
	return cnt;
}
void init(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			visited[i][j]=false;
		}
	}
}
void selectangle(int cnt){
	if(cnt==cctv.size()){
		int tmp=docctv();
		if(tmp<minanswer){
			minanswer=tmp;
		}
		init();
		return;
	}
	for(int i=0;i<4;i++){
		angle.push_back(i);
		selectangle(cnt+1);
		angle.pop_back();
	}
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>zone[i][j];
			if(zone[i][j]>=1&&zone[i][j]<=5){
				cctv.push_back({{i,j},zone[i][j]});
			}
		}
	}
	selectangle(0);
	cout<<minanswer;
	return 0;
}