#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int findN(int x){
	int start_index=0;
	int end_index=v.size()-1;
	while(start_index<=end_index){
		int mid=(start_index+end_index)/2;
		if(v[mid]<x){
			start_index=mid+1;
		}
		else if(v[mid]>x){
			end_index=mid-1;
		}
		else{
			return 1;
		}
	}
	return 0;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
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
		cout<<findN(tmp)<<' ';
	}
	return 0;
}