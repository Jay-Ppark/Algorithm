#include<iostream>
#include<vector>
using namespace std;
vector<int> v[201];
bool visited[201];
int d[201];
int N,M;
void init(){
    for(int i=0;i<201;i++){
        visited[i]=false;
    }
}
bool dfs(int x){
    for(int i=0;i<v[x].size();i++){
        int t=v[x][i];
        if(visited[t]){
            continue;
        }
        visited[t]=true;
        if(d[t]==0 || dfs(d[t])){
            d[t]=x;
            return true;
        }
    }
    return false;
}
int main(void){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        for(int j=0;j<tmp;j++){
            int t;
            cin>>t;
            v[i].push_back(t);
        }
    }
    int count=0;
    for(int i=1;i<=N;i++){
        init();
        if(dfs(i)){
            count++;
        }
    }
    cout<<count;
    return 0;
}