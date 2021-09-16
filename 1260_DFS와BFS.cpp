#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[1001];
bool visited[1001];
void init(){
	for(int i=0;i<1001;i++){
		visited[i]=false;
	}
}
void DFS(int s){
	if(visited[s]){
		return;
	}
	cout<<s<<' ';
	visited[s]=true;
	for(int i=0;i<v[s].size();i++){
		DFS(v[s][i]);
	}
}
void BFS(int s){
	visited[s]=true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		cout<<tmp<<' ';
		for(int i = 0;i<v[tmp].size();i++){
			if(!visited[v[tmp][i]]){
				q.push(v[tmp][i]);
				visited[v[tmp][i]]=true;
			}
		}
	}
}
int main(void){
	int N,M;
	int startn;
	cin>>N>>M>>startn;
	for(int i=0;i<M;i++){
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for(int i=1;i<=N;i++){
		sort(v[i].begin(),v[i].end());
	}
	DFS(startn);
	cout<<'\n';
	init();
	BFS(startn);
	return 0;
}