#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int N,M;
void BFS(int a){
    visited[a]=true;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<(int)v[x].size();i++){
            if(!visited[v[x][i]]){
                q.push(v[x][i]);
                visited[v[x][i]]=true;
            }
        }
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            BFS(i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}