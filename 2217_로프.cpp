#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
bool comp(int a,int b){
	if(a>b){
		return true;
	}
	else{
		return false;
	}
}
int main(void){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),comp);
	int maxw=v[0];
	int cnt=1;
	for(int i=1;i<N;i++){
		cnt++;
		int tmpw=cnt*v[i];
		if(tmpw>maxw){
			maxw=tmpw;
		}
	}
	cout<<maxw;
	return 0;
}