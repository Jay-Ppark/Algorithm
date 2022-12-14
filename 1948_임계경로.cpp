#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<pair<int,int>> dest[10001];
vector<pair<int,int>> r_dest[10001];
int inDegree[10001];
int needtime[10001];
int startn,endn;
int topology(){
    queue<int> q;
    q.push(startn);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<dest[x].size();i++){
            int nx=dest[x][i].first;
            int t=dest[x][i].second;
            needtime[nx]=max(needtime[nx],needtime[x]+t);
            inDegree[nx]--;
            if(inDegree[nx]==0){
                q.push(nx);
            }
        }
    }
    bool visited[10001]={false,};
    q.push(endn);
    visited[endn]=true;
    int cnt=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<r_dest[x].size();i++){
            int nx=r_dest[x][i].first;
            int t=r_dest[x][i].second;
            if(needtime[x]-needtime[nx]==t){
                cnt++;
                if(!visited[nx]){
                    q.push(nx);
                    visited[nx]=true;
                }
            }
        }
    }
    return cnt;
}
int main(void){
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        dest[x].push_back({y,t});
        r_dest[y].push_back({x,t});
        inDegree[y]++;
    }
    cin>>startn>>endn;
    int tmp=topology();
    cout<<needtime[endn]<<'\n'<<tmp;
    return 0;
}