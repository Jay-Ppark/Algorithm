#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int cnt=0;
void BFS(int y){
    queue<int> q;
    q.push(y);
    visited[y]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<(int)v[x].size();i++){
            if(!visited[v[x][i]]){
                visited[v[x][i]]=true;
                q.push(v[x][i]);
            }
        }
    }
}
int main(void){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            BFS(i);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}