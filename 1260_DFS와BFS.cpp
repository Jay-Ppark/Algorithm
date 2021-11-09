#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v[1001];
bool visited[1001];
void init(){
	for(int i=0;i<=1000;i++){
		visited[i]=false;
	}
}
void BFS(int s){
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		cout<<tmp<<' ';
		for(int i=0;i<v[tmp].size();i++){
			if(!visited[v[tmp][i]]){
				q.push(v[tmp][i]);
				visited[v[tmp][i]]=true;
			}
		}
	}
}

void DFS(int s){
	if(visited[s]){
		return;
	}
	cout<<s<<' ';
	visited[s]=true;
	for(int i=0;i<v[s].size();i++){
		if(!visited[v[s][i]]){
			DFS(v[s][i]);
		}
	}
}

int main(void){
	int N,M,startV;
	cin>>N>>M>>startV;
	int tmpstart,tmpend;
	for(int i=0;i<M;i++){
		cin>>tmpstart>>tmpend;
		v[tmpstart].push_back(tmpend);
		v[tmpend].push_back(tmpstart);
	}
	for(int i=1;i<=N;i++){
		if(!v[i].empty()){
			sort(v[i].begin(),v[i].end());
		}
	}
	DFS(startV);
	cout<<'\n';
	init();
	BFS(startV);
	return 0;
}