#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1001];
int job[1001];
bool visited[1001];
int N,M,K;
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
    cin>>N>>M>>K;
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
    int extracnt=0;
    for(int i=1;i<=N&&extracnt<K;i++){
        init();
        if(dfs(i)){
            extracnt++;
        }
    }
    cout<<count+extracnt;
    return 0;
}