#include<iostream>
#include<queue>
using namespace std;
int N;
int fishmap[20][20];
int sharky,sharkx;
int sharksize=2;
int eatenfish=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int ans;
bool moveandeat(){
    bool visited[20][20]={false,};
    visited[sharky][sharkx]=true;
    queue<pair<pair<int,int>,int> > q;
    vector<pair<pair<int,int>,pair<int,int>> > fish;
    q.push({{sharky,sharkx},0});
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int c=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny>=0&&ny<N&&nx>=0&&nx<N){
                if(!visited[ny][nx]){
                    if(fishmap[ny][nx]<sharksize&&fishmap[ny][nx]>0){
                        visited[ny][nx]=true;
                        q.push({{ny,nx},c+1});
                        fish.push_back({{ny,nx},{c+1,fishmap[ny][nx]}});
                    }
                    else if(fishmap[ny][nx]==sharksize||fishmap[ny][nx]==0){
                        visited[ny][nx]=true;
                        q.push({{ny,nx},c+1});
                    }
                }
            }
        }
    }
    if(fish.empty()){
        return false;
    }
    else{
        int maxy=fish[0].first.first;
        int maxx=fish[0].first.second;
        int maxcnt=fish[0].second.first;
        int index=0;
        for(int i=1;i<fish.size();i++){
            if(maxcnt>fish[i].second.first){
                maxy=fish[i].first.first;
                maxx=fish[i].first.second;
                maxcnt=fish[i].second.first;
                index=i;
            }
            else if(maxcnt==fish[i].second.first){
                if(maxy>fish[i].first.first){
                    maxy=fish[i].first.first;
                    maxx=fish[i].first.second;
                    maxcnt=fish[i].second.first;
                    index=i;
                }
                else if(maxy==fish[i].first.first){
                    if(maxx>fish[i].first.second){
                        maxy=fish[i].first.first;
                        maxx=fish[i].first.second;
                        maxcnt=fish[i].second.first;
                        index=i;
                    }
                }
            }
        }
        fishmap[sharky][sharkx]=0;
        sharky=maxy;
        sharkx=maxx;
        fishmap[sharky][sharkx]=9;
        ans=ans+maxcnt;
        eatenfish++;
        if(eatenfish==sharksize){
            eatenfish=0;
            sharksize++;
        }
        return true;
    }
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>fishmap[i][j];
            if(fishmap[i][j]==9){
                sharky=i;
                sharkx=j;
            }
        }
    }
    while(true){
        if(!moveandeat()){
            break;
        }
    }
    cout<<ans;
    return 0;
}