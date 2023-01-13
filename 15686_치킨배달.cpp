#include<iostream>
#include<vector>
using namespace std;
int N,M;
int chickencnt;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
bool selectchicken[13];
int ansmin=1e9;
int cal(){
	int tmphouse[101];
	fill(tmphouse,tmphouse+100,5000);
	int chickensize=chicken.size();
	int housesize=house.size();
	for(int i=0;i<chickensize;i++){
		if(selectchicken[i]){
			for(int j=0;j<housesize;j++){
				int tmp=abs(chicken[i].first-house[j].first)+abs(chicken[i].second-house[j].second);
				if(tmphouse[j]>tmp){
					tmphouse[j]=tmp;
				}
			}
		}
	}
	int result=0;
	for(int i=0;i<housesize;i++){
		result=result+tmphouse[i];
	}
	return result;
}
void dfs(int cnt,int y){
	if(cnt==M){
		int tmpmin=cal();
		if(tmpmin<ansmin){
			ansmin=tmpmin;
		}
		return;
	}
	for(int i=y;i<chicken.size();i++){
		if(!selectchicken[i]){
			selectchicken[i]=true;
			dfs(cnt+1,i+1);
			selectchicken[i]=false;
		}
	}
}
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int tmp;
			cin>>tmp;
			if(tmp==2){
				chicken.push_back({i,j});
			}
			else if(tmp==1){
				house.push_back({i,j});
			}
		}
	}
	dfs(0,0);
	cout<<ansmin;
	return 0;
}