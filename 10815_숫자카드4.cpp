#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool> m;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
        int tmp;
		cin>>tmp;
        m[tmp]=true;
	}
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		if(m.find(tmp) == m.end()){
			cout<<"0"<<' ';
		}
		else{
			cout<<"1"<<' ';
		}
	}
	return 0;
}