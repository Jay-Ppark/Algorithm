#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> shark[51];
int eaten[51];
bool visited[51];
int sharkstat[51][3];
void init(){
    for(int i=0;i<=N;i++){
        visited[i]=false;
    }
}
bool dfs(int x){
    for(int i=0;i<shark[x].size();i++){
        int t=shark[x][i];
        if(visited[t]){
            continue;
        }
        visited[t]=true;
        if(eaten[t]==0||dfs(eaten[t])){
            eaten[t]=x;
            return true;
        }
    }
    return false;
}
int main(void){
    cin>>N;
    for(int i=1;i<=N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sharkstat[i][0]=a;
        sharkstat[i][1]=b;
        sharkstat[i][2]=c;
    }
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            if(sharkstat[i][0]==sharkstat[j][0]&&sharkstat[i][1]==sharkstat[j][1]&&sharkstat[i][2]==sharkstat[j][2]){
                shark[i].push_back(j);
            }
            else if(sharkstat[i][0]<=sharkstat[j][0]&&sharkstat[i][1]<=sharkstat[j][1]&&sharkstat[i][2]<=sharkstat[j][2]){
                shark[j].push_back(i);
            }
            else if(sharkstat[i][0]>=sharkstat[j][0]&&sharkstat[i][1]>=sharkstat[j][1]&&sharkstat[i][2]>=sharkstat[j][2]){
                shark[i].push_back(j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
            init();
            if(dfs(j)){
                cnt++;
            }
        }
    }
    cout<<N-cnt;
    return 0;
}