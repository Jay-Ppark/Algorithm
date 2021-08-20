#include<iostream>
#include<algorithm>
using namespace std;
bool visited[20000001];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
        cin>>tmp;
        visited[tmp+10000000]=true;
	}
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		if(visited[tmp+10000000]){
            cout<<"1"<<' ';
        }
        else{
            cout<<"0"<<' ';
        }
	}
	return 0;
}