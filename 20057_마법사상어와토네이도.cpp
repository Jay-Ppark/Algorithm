#include<iostream>
using namespace std;
int N;
int sandmap[500][500];
int starty, startx;
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
int sy[2][4]={{-1,1,-2,2},{0,0,0,0}};
int sx[2][4]={{0,0,0,0},{-1,1,-2,2}};
int restsand=0;
void movesand(int y,int x,int d){
    int movey=y+dy[d];
    int movex=x+dx[d];
    int tmpsumrest=0;
    int tmpd=0;
    if(d%2==1){
        tmpd=1;
    }
    for(int i=0;i<2;i++){
        int ny=y+sy[tmpd][i];
        int nx=x+sx[tmpd][i];
        int tmp=0;
        tmp=sandmap[movey][movex]*0.01;
        tmpsumrest=tmpsumrest+tmp;
        if(ny<1||ny>N||nx<1||nx>N){
            restsand=restsand+tmp;
        }
        else{
            sandmap[ny][nx]=sandmap[ny][nx]+tmp;
        }
    }
    for(int i=0;i<4;i++){
        int ny=movey+sy[tmpd][i];
        int nx=movex+sx[tmpd][i];
        int tmp=0;
        if(i<2){
            tmp=sandmap[movey][movex]*0.07;
        }
        else{
            tmp=sandmap[movey][movex]*0.02;
        }
        tmpsumrest=tmpsumrest+tmp;
        if(ny<1||ny>N||nx<1||nx>N){
            restsand=restsand+tmp;
        }
        else{
            sandmap[ny][nx]=sandmap[ny][nx]+tmp;
        }
    }
    for(int i=0;i<2;i++){
        int ny=movey+dy[d]+sy[tmpd][i];
        int nx=movex+dx[d]+sx[tmpd][i];
        int tmp=0;
        tmp=sandmap[movey][movex]*0.1;
        tmpsumrest=tmpsumrest+tmp;
        if(ny<1||ny>N||nx<1||nx>N){
            restsand=restsand+tmp;
        }
        else{
            sandmap[ny][nx]=sandmap[ny][nx]+tmp;
        }
    }
    int ny=movey+dy[d]*2;
    int nx=movex+dx[d]*2;
    int tmp=0;
    tmp=sandmap[movey][movex]*0.05;
    tmpsumrest=tmpsumrest+tmp;
    if(ny<1||ny>N||nx<1||nx>N){
        restsand=restsand+tmp;
    }
    else{
        sandmap[ny][nx]=sandmap[ny][nx]+tmp;
    }
    int nny=movey+dy[d];
    int nnx=movex+dx[d];
    if(nny<1||nny>N||nnx<1||nnx>N){
        restsand=restsand+sandmap[movey][movex]-tmpsumrest;
    }
    else{
        sandmap[nny][nnx]=sandmap[nny][nnx]+sandmap[movey][movex]-tmpsumrest;
    }
    sandmap[movey][movex]=0;
}
void movewind(int d){
    int cnt=1;
    bool isfinish=false;
    while(true){
        for(int t=0;t<cnt;t++){
            if(starty==1&&startx==1){
                isfinish=true;
                break;
            }
            movesand(starty,startx,d);
            starty=starty+dy[d];
            startx=startx+dx[d];
        }
        if(isfinish){
            break;
        }
        d=(d+1)%4;
        for(int t=0;t<cnt;t++){
            movesand(starty,startx,d);
            starty=starty+dy[d];
            startx=startx+dx[d];
        }
        d=(d+1)%4;
        cnt++;
    }
}
int main(void){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>sandmap[i][j];
        }
    }
    starty=(N+1)/2;
    startx=(N+1)/2;
    movewind(0);
    cout<<restsand;
    return 0;
}