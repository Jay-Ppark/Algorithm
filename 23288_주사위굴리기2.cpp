#include<iostream>
using namespace std;
int N,M;
int gamemap[20][20];
int dice[4][3];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int score;
int starty,startx;
int cnt;
bool visited[20][20];
void Init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=false;
        }
    }
}
void DFS(int x,int y){
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0&&ny<N&&nx>=0&&nx<M){
            if(!visited[ny][nx]&&gamemap[ny][nx]==gamemap[starty][startx]){
                visited[ny][nx]=true;
                cnt++;
                DFS(nx,ny);
            }
        }
    }
}
void calscore(){
    cnt=1;
    Init();
    visited[starty][startx]=true;
    DFS(startx,starty);
    score=score+cnt*gamemap[starty][startx];
}
int rolldice(int d){
    //동
    if(d==0){
        int tmpd=dice[1][1];
        dice[1][1]=dice[1][0];
        dice[1][0]=dice[3][1];
        dice[3][1]=dice[1][2];
        dice[1][2]=tmpd;
    }
    //남
    else if(d==1){
        int tmpd=dice[1][1];
        dice[1][1]=dice[0][1];
        dice[0][1]=dice[3][1];
        dice[3][1]=dice[2][1];
        dice[2][1]=tmpd;
    }
    //서
    else if(d==2){
        int tmpd=dice[1][1];
        dice[1][1]=dice[1][2];
        dice[1][2]=dice[3][1];
        dice[3][1]=dice[1][0];
        dice[1][0]=tmpd;
    }
    //북
    else{
        int tmpd=dice[1][1];
        dice[1][1]=dice[2][1];
        dice[2][1]=dice[3][1];
        dice[3][1]=dice[0][1];
        dice[0][1]=tmpd;
    }
    return dice[3][1];
}
int move(int x, int y,int d){
    bool check = false;
    int ny=y;
    int nx=x;
    while(!check){
        ny=y+dy[d];
        nx=x+dx[d];
        if(ny>=0&&ny<N&&nx>=0&&nx<M){
            check=true;
        }
        else{
            d=d+2;
            d=d%4;
            check=false;
        }
    }
    int A = rolldice(d);
    int B = gamemap[ny][nx];
    starty=ny;
    startx=nx;
    if(A>B){
        d++;
        d=d%4;
        return d;
    }
    else if(A<B){
        d=d+3;
        d=d%4;
        return d;
    }
    else{
        return d;
    }
}
int main(void){
    int K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>gamemap[i][j];
        }
    }
    dice[0][1]=2;
    dice[1][0]=4;
    dice[1][1]=1;
    dice[1][2]=3;
    dice[2][1]=5;
    dice[3][1]=6;
    starty=0;
    startx=0;
    int d=0;
    for(int i=0;i<K;i++){
        d=move(startx,starty,d);
        calscore();
    }
    cout<<score;
    return 0;
}