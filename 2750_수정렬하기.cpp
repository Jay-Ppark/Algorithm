#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v;
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<'\n';
	}
	return 0;
}