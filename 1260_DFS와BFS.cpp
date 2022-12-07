#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int N;
int startN;
void DFS(int s){
	cout<<s<<" ";
	visited[s]=true;
	for(int i=0;i<v[s].size();i++){
		if(!visited[v[s][i]]){
			DFS(v[s][i]);
		}
	}
}
void init(){
	for(int i=1;i<=N;i++){
		visited[i]=false;
	}
}
void BFS(){
	queue<int> q;
	q.push(startN);
	visited[startN]=true;
	while(!q.empty()){
		int topq=q.front();
		q.pop();
		cout<<topq<<" ";
		for(int i=0;i<v[topq].size();i++){
			if(!visited[v[topq][i]]){
				q.push(v[topq][i]);
				visited[v[topq][i]]=true;
			}
		}
	}
}
int main(void){
	cin>>N;
	int M;
	cin>>M>>startN;
	for(int i=0;i<M;i++){
		int tmps,tmpe;
		cin>>tmps>>tmpe;
		v[tmps].push_back(tmpe);
		v[tmpe].push_back(tmps);
	}
	for(int i=1;i<=N;i++){
		if(!v[i].empty()){
			sort(v[i].begin(),v[i].end());
		}
	}
	DFS(startN);
	init();
	cout<<'\n';
	BFS();
	return 0;
}