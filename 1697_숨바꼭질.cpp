#include<iostream>
#include<queue>
using namespace std;
bool visited[100001];
int N,K;
int dx[3]={-1,1,2};
int main(void){
	cin>>N>>K;
	queue<int> q;
	q.push(N);
	visited[N]=true;
	int cnt=-1;
	while(!q.empty()){
		int qsize=q.size();
		for(int qs=0;qs<qsize;qs++){
			int x=q.front();
			q.pop();
			if(x==K){
				while(!q.empty()){
					q.pop();
				}
				break;
			}
			for(int d=0;d<3;d++){
				int nx=0;
				if(d==2){
					nx=x*dx[2];
				}
				else{
					nx=x+dx[d];
				}
				if(nx>=0&&nx<=100000){
					if(!visited[nx]){
						q.push(nx);
						visited[nx]=true;
					}
				}
			}
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}