#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool visited[1001];
vector<int> v[1001];
void DFS(int vertex){
	visited[vertex]=true;
	cout<<vertex<<" ";
	for(int i=0;i<v[vertex].size();i++){
		if(!visited[v[vertex][i]]){
			DFS(v[vertex][i]);
		}
	}
}
void Init(){
	for(int i=0;i<1001;i++){
		visited[i]=false;
	}
}
void BFS(int vertex){
	queue<int> q;
	q.push(vertex);
	visited[vertex]=true;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		cout<<tmp<<" ";
		for(int i=0;i<v[tmp].size();i++){
			if(!visited[v[tmp][i]]){
				q.push(v[tmp][i]);
				visited[v[tmp][i]]=true;
			}
		}
	}
}
int main(void){
	int N,M,startv;
	cin>>N>>M>>startv;
	for(int i=0;i<M;i++){
		int sv,ev;
		cin>>sv>>ev;
		v[sv].push_back(ev);
		v[ev].push_back(sv);
	}
	for(int i=1;i<=N;i++){
		if(!v[i].empty()){
			sort(v[i].begin(),v[i].end());
		}
	}
	DFS(startv);
	cout<<'\n';
	Init();
	BFS(startv);
	return 0;
}