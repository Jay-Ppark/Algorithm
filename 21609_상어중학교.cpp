#include<iostream>
#include<queue>
using namespace std;
int N,M;
int blockmap[20][20];
bool tmpgroupblock[20][20];
bool groupblock[20][20];
bool visited[20][20];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int score;
int rainbowcnt;
void initcal(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmpgroupblock[i][j]=false;
        }
    }
}
void copygroup(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            groupblock[i][j]=tmpgroupblock[i][j];
        }
    }
}
int calblock(int y,int x){
    int stand=blockmap[y][x];
    bool tmpvisited[20][20]={false,};
    int cnt=1;
    queue<pair<int,int> > q;
    q.push({y,x});
    tmpvisited[y][x]=true;
    tmpgroupblock[y][x]=true;
    while(!q.empty()){
        int ny=q.front().first;
        int nx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nny=ny+dy[i];
            int nnx=nx+dx[i];
            if(nny>=0&&nny<N&&nnx>=0&&nnx<N){
                if(!tmpvisited[nny][nnx]){
                    if(blockmap[nny][nnx]==stand||blockmap[nny][nnx]==0){
                        tmpvisited[nny][nnx]=true;
                        tmpgroupblock[nny][nnx]=true;
                        cnt++;
                        q.push({nny,nnx});
                        if(blockmap[nny][nnx]==stand){
                            visited[nny][nnx]=true;
                        }
                        if(blockmap[nny][nnx]==0){
                            rainbowcnt++;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
bool findgroup(){
    bool isfind=false;
    int maxgroupcnt=0;
    int maxrainbowcnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]&&blockmap[i][j]>=1){
                initcal();
                rainbowcnt=0;
                int tmpcnt=calblock(i,j);
                if(tmpcnt>maxgroupcnt&&tmpcnt>=2){
                    isfind=true;
                    maxgroupcnt=tmpcnt;
                    maxrainbowcnt=rainbowcnt;
                    copygroup();
                }
                else if(tmpcnt==maxgroupcnt&&tmpcnt>=2){
                    if(rainbowcnt>=maxrainbowcnt){
                        isfind=true;
                        maxgroupcnt=tmpcnt;
                        maxrainbowcnt=rainbowcnt;
                        copygroup();
                    }
                }
                visited[i][j]=true;
            }
        }
    }
    if(isfind){
        score=score+maxgroupcnt*maxgroupcnt;
        return true;
    }
    else{
        return false;
    }
}
void deleteblock(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(groupblock[i][j]){
                groupblock[i][j]=false;
                blockmap[i][j]=-2;
            }
            visited[i][j]=false;
            tmpgroupblock[i][j]=false;
        }
    }
}
void gravity(){
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=1;j--){
            if(blockmap[j][i]==-2){
                for(int k=j-1;k>=0;k--){
                    if(blockmap[k][i]>=0){
                        blockmap[j][i]=blockmap[k][i];
                        blockmap[k][i]=-2;
                        break;
                    }
                    if(blockmap[k][i]==-1){
                        break;
                    }
                }
            }
        }
    }
}
void turnleft(){
    int tmpblockmap[20][20]={0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmpblockmap[N-1-j][i]=blockmap[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            blockmap[i][j]=tmpblockmap[i][j];
        }
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>blockmap[i][j];
        }
    }
    while(true){
        bool keepgoing=findgroup();
        if(!keepgoing){
            break;
        }
        deleteblock();
        gravity();
        turnleft();
        gravity();
    }
    cout<<score;
    return 0;
}