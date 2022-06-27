#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lab[50][50];
vector<pair<int,int>> virus;
bool viruscheck[10];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int N;
int M;
int virusnum;
int voidnum;
int mindays=1e9;
int calculatedays(){
    queue<pair<pair<int,int>,int>> q;
    int copylab[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            copylab[i][j]=lab[i][j];
        }
    }
    for(int i=0;i<virusnum;i++){
        if(viruscheck[i]){
            q.push({{virus[i].first,virus[i].second},0});
        }
        else{
            copylab[virus[i].first][virus[i].second]=-2;
        }
    }
    int copyvoidnum=voidnum;
    int maxday=0;
    while(!q.empty()){
        int frontqy = q.front().first.first;
        int frontqx = q.front().first.second;
        int frontqday = q.front().second;
        q.pop();
        if(maxday<frontqday){
            maxday=frontqday;
        }
        if(copyvoidnum==0){
            continue;
        }
        for(int i=0;i<4;i++){
            int qy=frontqy+dy[i];
            int qx=frontqx+dx[i];
            if(qy<N&&qy>=0&&qx<N&&qx>=0){
                if(copylab[qy][qx]!=-1){
                    if(copylab[qy][qx]==0){
                        q.push({{qy,qx},frontqday+1});
                        copylab[qy][qx]=frontqday+1;
                        copyvoidnum--;
                    }
                    else{
                        if(copylab[qy][qx]==-2){
                            q.push({{qy,qx},frontqday+1});
                            copylab[qy][qx]=frontqday+1;
                        }
                    }
                }
            }
        }
    }
    if(copyvoidnum==0){
        return maxday;
    }
    else{
        return -1;
    }
}
void pickvirus(int x,int cnt){
    if(cnt==M){
        int tmpmindays=calculatedays();
        if(tmpmindays!=-1){
            if(tmpmindays<mindays){
                mindays=tmpmindays;
            }
        }
        return;
    }
    for(int i=x;i<virusnum;i++){
        if(!viruscheck[i]){
            viruscheck[i]=true;
            pickvirus(i+1,cnt+1);
            viruscheck[i]=false;
        }
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>lab[i][j];
            if(lab[i][j]==2){
                virus.push_back({i,j});
                virusnum++;
            }
            else if(lab[i][j]==1){
                lab[i][j] = -1;
            }
            else{
                voidnum++;
            }
        }
    }
    if(voidnum==0){
        cout<<0;
    }
    else{
        pickvirus(0,0);
        if(mindays==1e9){
            cout<<-1;
        }
        else{
            cout<<mindays;
        }
    }
    
    return 0;
}