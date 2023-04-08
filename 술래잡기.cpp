#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int N,M,H,K;
vector<int> runner[100][100];
bool treemap[100][100];
tuple<int,int,int> human;
int turnmap[100][100];
int reversemap[100][100];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
bool dir=true;
int answer=0;
void inithuman(){
    int y=N/2;
    int x=N/2;
    int d=3;
    int t=1;
    while(t<=N){
        if(t==N){
            for(int i=0;i<N;i++){
                turnmap[y][x]=d;
                y+=dy[d];
                x+=dx[d];
            }
            break;
        }
        for(int i=0;i<t;i++){
            turnmap[y][x]=d;
            y+=dy[d];
            x+=dx[d];
        }
        d+=1;
        d%=4;
        for(int i=0;i<t;i++){
            turnmap[y][x]=d;
            y+=dy[d];
            x+=dx[d];
        }
        d+=1;
        d%=4;
        t++;
    }
    y=0;
    x=0;
    d=1;
    t=N-1;
    while(t>0){
        if(t==N-1){
            for(int i=0;i<t;i++){
                reversemap[y][x]=d;
                y+=dy[d];
                x+=dx[d];
            }
            d-=1;
            if(d<0){
                d=3;
            }
        }
        for(int i=0;i<t;i++){
            reversemap[y][x]=d;
            y+=dy[d];
            x+=dx[d];
        }
        d-=1;
        if(d<0){
            d=3;
        }
        for(int i=0;i<t;i++){
            reversemap[y][x]=d;
            y+=dy[d];
            x+=dx[d];
        }
        d-=1;
        if(d<0){
            d=3;
        }
        t--;
    }
}
void moverunner(){
    vector<int> nextrunner[100][100];
    int hy,hx;
    tie(hy,hx,ignore)=human;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!runner[i][j].empty()){
                //거리가 3이하인 도망자만 움직임
                if(abs(hy-i)+abs(hx-j)<=3){
                    for(int s=0;s<(int)runner[i][j].size();s++){
                        int d=runner[i][j][s];
                        int ny=i+dy[d];
                        int nx=j+dx[d];
                        //격자 범위안
                        if(ny>=0&&ny<N&&nx>=0&&nx<N){
                            //술래랑 겹치는 경우
                            if(ny==hy&&nx==hx){
                                nextrunner[i][j].push_back(d);
                            }
                            //아닌 경우
                            else{
                                nextrunner[ny][nx].push_back(d);
                            }
                        }
                        //격자 밖
                        else{
                            d+=2;
                            d%=4;
                            ny=i+dy[d];
                            nx=j+dx[d];
                            //술래랑 겹치는 경우
                            if(ny==hy&&nx==hx){
                                nextrunner[i][j].push_back(d);
                            }
                            //아닌 경우
                            else{
                                nextrunner[ny][nx].push_back(d);
                            }
                        }
                    }
                }
                //그대로 머무름
                else{
                    for(int k=0;k<(int)runner[i][j].size();k++){
                        nextrunner[i][j].push_back(runner[i][j][k]);
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            runner[i][j].clear();
            runner[i][j]=nextrunner[i][j];
        }
    }
}
void movehuman(int round){
    int y,x,d;
    tie(y,x,d)=human;
    //새로운 위치 및 방향향
    int ny=y+dy[d];
    int nx=x+dx[d];
    int nd=d;
    //순방향
    if(dir){
        //역방향으로 돌려야함
        if(ny==0&&nx==0){
            dir=false;
            nd=reversemap[ny][nx];
        }
        else{
            nd=turnmap[ny][nx];
        }
    }
    //역방향
    else{
        //순방향으로 돌려야함
        if(ny==(N/2)&&nx==(N/2)){
            dir=true;
            nd=turnmap[ny][nx];
        }
        else{
            nd=reversemap[ny][nx];
        }
    }
    human={ny,nx,nd};
    int catchcnt=0;
    if(!treemap[ny][nx]){
        if(!runner[ny][nx].empty()){
            catchcnt+=runner[ny][nx].size();
            runner[ny][nx].clear();
        }
    }
    for(int i=0;i<2;i++){
        ny+=dy[nd];
        nx+=dx[nd];
        if(ny>=0&&ny<N&&nx>=0&&nx<N){
            if(!treemap[ny][nx]){
                if(!runner[ny][nx].empty()){
                    catchcnt+=runner[ny][nx].size();
                    runner[ny][nx].clear();
                }
            }
        }
    }
    answer=answer+(catchcnt*round);
}
void show(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!runner[i][j].empty()){
                cout<<i<<j<<'\n';
            }
        }
    }
    cout<<"turnmap\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<turnmap[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"reversemap\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<reversemap[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main(void){
    cin>>N>>M>>H>>K;
    //도망자 정보 입력
    for(int i=0;i<M;i++){
        int y,x,d;
        cin>>y>>x>>d;
        runner[y-1][x-1].push_back(d-1);
    }
    //나무 정보 입력
    for(int i=0;i<H;i++){
        int y,x;
        cin>>y>>x;
        treemap[y-1][x-1]=true;
    }
    // 술래 위치 입력
    human={N/2,N/2,3};
    // 술래 방향 저장
    inithuman();
    // 라운드 시작
    int round=1;
    while(round<=K){
        //도망자 움직임
        moverunner();
        movehuman(round);
        round++;
    }
    cout<<answer;
    //show();
    return 0;
}