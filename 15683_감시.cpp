#include<iostream>
#include<vector>
using namespace std;
int N,M;
int cctvmap[8][8];
int copymap[8][8];
vector<pair<pair<int,int>,int>> cctv;
vector<int> angle;
int maxcnt=1000;
void init(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			copymap[i][j]=cctvmap[i][j];
		}
	}
}
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
void watch(int y,int x,int d){
	if(d==0){
		for(int i=x;i<M;i++){
			if(copymap[y][i]==0){
				copymap[y][i]=-1;
			}
			else if(copymap[y][i]==6){
				break;
			}
		}
	}
	else if(d==1){
		for(int i=y;i<N;i++){
			if(copymap[i][x]==0){
				copymap[i][x]=-1;
			}
			else if(copymap[i][x]==6){
				break;
			}
		}
	}
	else if(d==2){
		for(int i=x;i>=0;i--){
			if(copymap[y][i]==0){
				copymap[y][i]=-1;
			}
			else if(copymap[y][i]==6){
				break;
			}
		}
	}
	else{
		for(int i=y;i>=0;i--){
			if(copymap[i][x]==0){
				copymap[i][x]=-1;
			}
			else if(copymap[i][x]==6){
				break;
			}
		}
	}
}
int calcctv(){
	init();
	for(int i=0;i<cctv.size();i++){
		int y=cctv[i].first.first;
		int x=cctv[i].first.second;
		int a=cctv[i].second;
		if(a==1){
			if(angle[i]==0){
				watch(y,x,0);
			}
			else if(angle[i]==1){
				watch(y,x,1);
			}
			else if(angle[i]==2){
				watch(y,x,2);
			}
			else{
				watch(y,x,3);
			}
		}
		else if(a==2){
			if(angle[i]%2==0){
				watch(y,x,2);
				watch(y,x,0);
			}
			else{
				watch(y,x,1);
				watch(y,x,3);
			}
		}
		else if(a==3){
			if(angle[i]==0){
				watch(y,x,3);
				watch(y,x,0);
			}
			else if(angle[i]==1){
				watch(y,x,0);
				watch(y,x,1);
			}
			else if(angle[i]==2){
				watch(y,x,1);
				watch(y,x,2);
			}
			else{
				watch(y,x,2);
				watch(y,x,3);
			}
		}
		else if(a==4){
			if(angle[i]==0){
				watch(y,x,2);
				watch(y,x,3);
				watch(y,x,0);
			}
			else if(angle[i]==1){
				watch(y,x,3);
				watch(y,x,0);
				watch(y,x,1);
			}
			else if(angle[i]==2){
				watch(y,x,0);
				watch(y,x,1);
				watch(y,x,2);
			}
			else{
				watch(y,x,1);
				watch(y,x,2);
				watch(y,x,3);
			}
		}
		else if(a==5){
			watch(y,x,0);
			watch(y,x,1);
			watch(y,x,2);
			watch(y,x,3);
		}
	}
	int r=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(copymap[i][j]==0){
				r++;
			}
		}
	}
	return r;
}
void selectangle(int cnt){
	if(cnt==cctv.size()){
		int tmp=calcctv();
		if(tmp<maxcnt){
			maxcnt=tmp;
		}
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
			cin>>cctvmap[i][j];
			if(cctvmap[i][j]>=1&&cctvmap[i][j]<=5){
				cctv.push_back({{i,j},cctvmap[i][j]});
			}
		}
	}
	selectangle(0);
	cout<<maxcnt;
	return 0;
}