#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, peoplecnt, fuels;
int drivemap[21][21];
int taxiy, taxix;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int ay=30;
int ax=30;
int afuel=0;
vector<pair<int,int> > home;
int findp=0;
bool findperson(){
    ay=30;
    ax=30;
    afuel=-1;
    queue<pair<pair<int,int>,int> > q;
    bool visited[21][21]={false,};
    q.push({{taxiy,taxix},fuels});
    visited[taxiy][taxix]=true;
    while(!q.empty()){
        int tmpy=q.front().first.first;
        int tmpx=q.front().first.second;
        int tmpf=q.front().second;
        q.pop();
        if(drivemap[tmpy][tmpx]>=1&&tmpf>0){
            if(tmpf>afuel){
                ay=tmpy;
                ax=tmpx;
                afuel=tmpf;
            }
            else if(tmpf==afuel){
                if(ay>tmpy){
                    ay=tmpy;
                    ax=tmpx;
                    afuel=tmpf;
                }
                else if(ay==tmpy){
                    if(ax>tmpx){
                        ay=tmpy;
                        ax=tmpx;
                        afuel=tmpf;
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            int ny=tmpy+dy[i];
            int nx=tmpx+dx[i];
            if(ny>=1&&ny<=N&&nx>=1&&nx<=N){
                if(!visited[ny][nx]&&drivemap[tmpy][tmpx]!=-1){
                    if(tmpf>0){
                        q.push({{ny,nx},tmpf-1});
                        visited[ny][nx]=true;
                    }
                }
            }
        }
    }
    if(ay==30&&ax==30){
        return false;
    }
    else{
        return true;
    }
}
bool gohome(){
    fuels=afuel;
    taxiy=ay;
    taxix=ax;
    int peopleindex=drivemap[ay][ax]-1;
    int hy=home[peopleindex].first;
    int hx=home[peopleindex].second;
    queue<pair<pair<int,int>,int> > q;
    bool visited[21][21]={false,};
    q.push({{taxiy,taxix},fuels});
    visited[taxiy][taxix]=true;
    int fcnt=-1;
    while(!q.empty()){
        int tmpy=q.front().first.first;
        int tmpx=q.front().first.second;
        int tmpf=q.front().second;
        q.pop();
        if(hy==tmpy&&hx==tmpx){
            fcnt=tmpf;
            drivemap[ay][ax]=0;
            taxiy=tmpy;
            taxix=tmpx;
            break;
        }
        for(int i=0;i<4;i++){
            int ny=tmpy+dy[i];
            int nx=tmpx+dx[i];
            if(ny>=1&&ny<=N&&nx>=1&&nx<=N){
                if(!visited[ny][nx]&&drivemap[tmpy][tmpx]!=-1){
                    if(tmpf>0){
                        q.push({{ny,nx},tmpf-1});
                        visited[ny][nx]=true;
                    }
                }
            }
        }
    }
    if(fcnt==-1){
        return false;
    }
    else{
        int r=fuels-fcnt;
        fuels=fuels+r;
        findp++;
        return true;
    }
}
int main(void){
    cin>>N>>peoplecnt>>fuels;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>drivemap[i][j];
            if(drivemap[i][j]==1){
                drivemap[i][j]=-1;
            }
        }
    }
    cin>>taxiy>>taxix;
    for(int i=0;i<peoplecnt;i++){
        int sy,sx,hy,hx;
        cin>>sy>>sx>>hy>>hx;
        drivemap[sy][sx]=i+1;
        home.push_back({hy,hx});
    }
    while(true){
        if(!findperson()){
            break;
        }
        if(!gohome()){
            break;
        }
    }
    if(findp==peoplecnt){
        cout<<fuels;
    }
    else{
        cout<<"-1";
    }
    return 0;
}