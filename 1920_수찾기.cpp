#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
bool bs(int n){
	int leftindex=0;
	int rightindex=v.size()-1;
	while(leftindex<=rightindex){
		int midindex=(leftindex+rightindex)/2;
		if(v[midindex]==n){
			return 1;
		}
		if(v[midindex]<n){
			leftindex=midindex+1;
		}
		else{
			rightindex=midindex-1;
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
		cout<<bs(tmp)<<'\n';
	}
	return 0;
}