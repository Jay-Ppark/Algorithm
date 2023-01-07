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
	if(next_permutation(v.begin(),v.end())){
		for(int i=0;i<N;i++){
			cout<<v[i]<<" ";
		}
	}
	else{
		cout<<-1;
	}
	return 0;
}