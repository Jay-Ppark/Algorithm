#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int N,M;
vector<int> v[10001];
vector<vector<int> > SCC;
stack<int> s;
bool finished[10001];
int d[10001];
int id=1;
//항상 처음 방문하는 노드만 실행 즉, N번 실행
int dfs(int x){
    d[x]=id;
    id++;
    s.push(x);
    int parent=d[x];
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        //아직 방문을 하지 않은 경우
        if(d[y]==0){
            parent=min(parent,dfs(y));
        }
        //방문은 했지만 처리중인 경우
        else if(!finished[y]){
            parent=min(parent,d[y]);
        }
    }
    //부모 노드가 자기 자신인 경우 SCC형성
    if(parent==d[x]){
        vector<int> tmpscc;
        while(1){
            int t=s.top();
            s.pop();
            tmpscc.push_back(t);
            finished[t]=true;
            if(t==x){
                break;
            }
        }
        sort(tmpscc.begin(),tmpscc.end());
        SCC.push_back(tmpscc);
    }
    //자신의 부모 값을 반환
    return parent;
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
    }
    for(int i=1;i<=N;i++){
        if(d[i]==0){
            dfs(i);
        }
    }
    cout<<SCC.size()<<'\n';
    sort(SCC.begin(),SCC.end());
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            cout<<SCC[i][j]<<" ";
        }
        cout<<"-1\n";
    }
    return 0;
}