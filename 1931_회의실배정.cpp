#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int,int>> v;
bool comp(pair<int,int> &a, pair<int,int> &b){
	if(a.second<b.second){
		return true;
	}
	else if(a.second>b.second){
		return false;
	}
	else{
		if(a.first<b.first){
			return true;
		}
		else{
			return false;
		}
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		int s,e;
		cin>>s>>e;
		v.push_back({s,e});
	}
	sort(v.begin(),v.end(),comp);
	int cnt=1;
	int endt=v[0].second;
	for(int i=1;i<N;i++){
		if(endt<=v[i].first){
			endt=v[i].second;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}