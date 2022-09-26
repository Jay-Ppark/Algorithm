#include<iostream>
#include<queue>
using namespace std;
int gamemap[20][20];
int dicenum[4][3];
int dicecnt;
int N,M;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int starty, startx;
int score=0;
void movedice(int d){
    if(d==0){
        int tmp=dicenum[1][0];
        dicenum[1][0]=dicenum[3][1];
        dicenum[3][1]=dicenum[1][2];
        dicenum[1][2]=dicenum[1][1];
        dicenum[1][1]=tmp;
    }
    else if(d==1){
        int tmp=dicenum[0][1];
        dicenum[0][1]=dicenum[3][1];
        dicenum[3][1]=dicenum[2][1];
        dicenum[2][1]=dicenum[1][1];
        dicenum[1][1]=tmp;
    }
    else if(d==2){
        int tmp=dicenum[1][0];
        dicenum[1][0]=dicenum[1][1];
        dicenum[1][1]=dicenum[1][2];
        dicenum[1][2]=dicenum[3][1];
        dicenum[3][1]=tmp;
    }
    else{
        int tmp=dicenum[0][1];
        dicenum[0][1]=dicenum[1][1];
        dicenum[1][1]=dicenum[2][1];
        dicenum[2][1]=dicenum[3][1];
        dicenum[3][1]=tmp;
    }
}
int calscore(int dir){
    if(dicenum[3][1]>gamemap[starty][startx]){
        dir=(dir+1)%4;
    }
    else if(dicenum[3][1]<gamemap[starty][startx]){
        dir=(dir+3)%4;
    }
    bool visited[20][20]={false,};
    queue<pair<int,int>> q;
    q.push({starty,startx});
    int cnt=1;
    int basescore=gamemap[starty][startx];
    visited[starty][startx]=true;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny>=0&&ny<N&&nx>=0&&nx<M){
                if(!visited[ny][nx]&&gamemap[ny][nx]==basescore){
                    visited[ny][nx]=true;
                    cnt++;
                    q.push({ny,nx});
                }
            }
        }
    }
    score=score+cnt*basescore;
    return dir;
}
int main(void){
    cin>>N>>M>>dicecnt;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>gamemap[i][j];
        }
    }
    dicenum[0][1]=2;
    dicenum[1][0]=4;
    dicenum[1][1]=1;
    dicenum[1][2]=3;
    dicenum[2][1]=5;
    dicenum[3][1]=6;
    int dir=0;
    for(int i=0;i<dicecnt;i++){
        int ny=starty+dy[dir];
        int nx=startx+dx[dir];
        if(ny>=0&&ny<N&&nx>=0&&nx<M){
            movedice(dir);
        }
        else{
            dir=(dir+2)%4;
            movedice(dir);
        }
        starty=starty+dy[dir];
        startx=startx+dx[dir];
        dir=calscore(dir);
    }
    cout<<score;
    return 0;
}