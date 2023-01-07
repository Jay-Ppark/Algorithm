#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> v;
bool visited[8];
void dfs(int n,int cnt){
    if(cnt==M){
        for(int i=0;i<N;i++){
            if(visited[i]){
                cout<<v[i]<<" ";
            }
        }
        cout<<'\n';
        return;
    }
    for(int i=n;i<N;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i+1,cnt+1);
            visited[i]=false;
        }
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    dfs(0,0);
    return 0;
}