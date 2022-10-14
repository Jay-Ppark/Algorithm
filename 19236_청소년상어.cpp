#include<iostream>
#include<vector>
using namespace std;
int fishmap[4][4];
vector<pair<pair<int,int>,pair<int,bool>> > fish[17];
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
int ans;
void movefish(){
    for(int i=1;i<=16;i++){
        if(!fish[i][0].second.second){
            continue;
        }
        int y=fish[i][0].first.first;
        int x=fish[i][0].first.second;
        int d=fish[i][0].second.first;
        for(int t=0;t<8;t++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny>=0&&ny<4&&nx>=0&&nx<4){
                if(fishmap[ny][nx]>0){
                    fish[i][0].first.first=ny;
                    fish[i][0].first.second=nx;
                    fish[i][0].second.first=d;
                    fish[fishmap[ny][nx]][0].first.first=y;
                    fish[fishmap[ny][nx]][0].first.second=x;
                    int tmpfishnum=fishmap[y][x];
                    fishmap[y][x]=fishmap[ny][nx];
                    fishmap[ny][nx]=tmpfishnum;
                    break;
                }
                else if(fishmap[ny][nx]==0){
                    fish[i][0].first.first=ny;
                    fish[i][0].first.second=nx;
                    fish[i][0].second.first=d;
                    fishmap[ny][nx]=i;
                    fishmap[y][x]=0;
                    break;
                }
            }
            d=(d+1)%8;
        }
    }
}
void copythings(int orifishmap[4][4],int copyfishmap[4][4],vector<pair<pair<int,int>,pair<int,bool>> > orifish[17],vector<pair<pair<int,int>,pair<int,bool>> > copyfish[17]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            copyfishmap[i][j]=orifishmap[i][j];
        }
    }
    for(int i=1;i<=16;i++){
        copyfish[i]=orifish[i];
    }
}
void DFS(int y,int x,int d,int sum){
    if(ans<sum){
        ans=sum;
    }
    int copyfishmap[4][4]={0,};
    vector<pair<pair<int,int>,pair<int,bool>> > copyfish[17];
    copythings(fishmap,copyfishmap,fish,copyfish);
    movefish();
    for(int i=1;i<=3;i++){
        int ny=y+dy[d]*i;
        int nx=x+dx[d]*i;
        if(ny>=0&&ny<4&&nx>=0&&nx<4){
            if(fishmap[ny][nx]>0){
                int tmpfnum=fishmap[ny][nx];
                fish[tmpfnum][0].second.second=false;
                fishmap[ny][nx]=-1;
                fishmap[y][x]=0;
                int tmpd=fish[tmpfnum][0].second.first;
                DFS(ny,nx,tmpd,sum+tmpfnum);
                fishmap[y][x]=-1;
                fish[tmpfnum][0].second.second=true;
                fishmap[ny][nx]=tmpfnum;
            }
        }
        else{
            break;
        }
    }
    copythings(copyfishmap,fishmap,copyfish,fish);
}
int main(void){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>fishmap[i][j];
            int d;
            cin>>d;
            fish[fishmap[i][j]].push_back({{i,j},{d-1,true}});
        }
    }
    int deadfish=fishmap[0][0];
    fishmap[0][0]=-1;
    ans=deadfish;
    fish[deadfish][0].second.second=false;
    int d=fish[deadfish][0].second.first;
    DFS(0,0,d,ans);
    cout<<ans;
    return 0;
}