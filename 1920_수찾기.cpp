#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int N;
bool findnum(int x){
	int startn=0;
	int endn=N-1;
	while(startn<=endn){
		int mid=(startn+endn)/2;
		if(v[mid]<x){
			startn=mid+1;
		}
		else if(v[mid]>x){
			endn=mid-1;
		}
		else{
			return true;
		}
	}
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		bool answ = findnum(tmp);
		if(answ){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}