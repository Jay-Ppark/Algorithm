#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	int N;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;i++){
		v.push_back(i+1);
	}
	do{
		for(int i=0;i<N;i++){
			cout<<v[i]<<" ";
		}
		cout<<'\n';
	}
	while(next_permutation(v.begin(),v.end()));
	return 0;
}