#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int> v[1001];
int job[1001];
bool visited[1001];
void init(){
    for(int i=0;i<1001;i++){
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
        if(job[t]==0||dfs(job[t])){
            job[t]=x;
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
        for(int j=0;j<2;j++){
            init();
            if(dfs(i)){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}