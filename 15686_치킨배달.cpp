#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
int N,M;
int citymap[50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
int housecnt[100];
bool chickenv[13];
int ccnt=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int result=5000000;
int calchicken(){
	int tmpresult=0;
	for(int i=0;i<house.size();i++){
		int mintmp=5000;
		for(int j=0;j<chicken.size();j++){
			if(chickenv[j]){
				int tmp=abs(house[i].first-chicken[j].first)+abs(house[i].second-chicken[j].second);
				if(tmp<mintmp){
					mintmp=tmp;
				}
			}
		}
		tmpresult=tmpresult+mintmp;
	}
	return tmpresult;
}
void selectchicken(int n,int cnt){
	if(cnt==M){
		int tmpmax = calchicken();
		if(tmpmax<result){
			result=tmpmax;
		}
		return;
	}
	for(int i=n;i<ccnt;i++){
		if(!chickenv[i]){
			chickenv[i]=true;
			selectchicken(i+1,cnt+1);
			chickenv[i]=false;
		}
	}
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>citymap[i][j];
			if(citymap[i][j]==2){
				chicken.push_back({i,j});
				ccnt++;
			}
			else if(citymap[i][j]==1){
				house.push_back({i,j});
			}
		}
	}
	selectchicken(0,0);
	cout<<result;
	return 0;
}