#include<iostream>
#include<map>
using namespace std;
map<int,int> m;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
        int tmp;
		cin>>tmp;
        m.insert({tmp,tmp});
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