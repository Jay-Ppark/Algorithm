#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
int N,M,K;
int gamemap[20][20];
int teamidx[20][20];
bool visited[20][20];
deque<pair<int,int>> team[6];
int teamsize[6];
int points[6];
bool hitteam[6];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void maketeam(int index,int y,int x,int cnt){
    //팀 구성
    visited[y][x]=true;
    teamidx[y][x]=index;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0&&ny<N&&nx>=0&&nx<N){
            if(cnt==1&&gamemap[ny][nx]!=2){
                continue;
            }
            else{
                if(!visited[ny][nx]&&gamemap[ny][nx]>0){
                    team[index].push_back({ny,nx});
                    if(gamemap[ny][nx]<=3){
                        if(gamemap[ny][nx]==3){
                            teamsize[index]=cnt+1;
                        }
                        maketeam(index,ny,nx,cnt+1);
                    }
                    else{
                        maketeam(index,ny,nx,cnt);
                    }
                }
            }
        }
    }
}
void findhead(){
    int teamindex=1;
    // head찾기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //머리를 찾은 경우
            if(gamemap[i][j]==1){
                team[teamindex].push_back({i,j});
                //팀 구성하기
                maketeam(teamindex,i,j,1);
                teamindex++;
            }
        }
    }
}
void moveteam(){
    for(int i=1;i<=M;i++){
        int tmpy=team[i].back().first;
        int tmpx=team[i].back().second;
        team[i].pop_back();
        team[i].push_front({tmpy,tmpx});
    }
}
bool getpoints(int index,int y,int x){
    for(int i=0;i<teamsize[index];i++){
        //사람이 맞은 경우
        if(y==team[index][i].first&&x==team[index][i].second){
            points[index]+=(i+1)*(i+1);
            return true;
        }
    }
    return false;
}
void changedir(int index){
    deque<pair<int,int>> tmp;
    int cnt=0;
    while(cnt<teamsize[index]){
        tmp.push_front({team[index].front().first,team[index].front().second});
        team[index].pop_front();
        cnt++;
    }
    while(!team[index].empty()){
        tmp.push_back({team[index].back().first,team[index].back().second});
        team[index].pop_back();
    }
    team[index]=tmp;
}
void throwball(int t){
    //초기화
    for(int i=0;i<=M;i++){
        hitteam[i]=false;
    }
    //네방향 모두 한 경우
    if(t>=4*N){
        t=t%(4*N);
    }
    //왼쪽에서 던지는 경우
    if(t<N){
        for(int i=0;i<N;i++){
            //사람이 있는 경우
            if(teamidx[t][i]>0){
                //공을 맞은 경우
                if(getpoints(teamidx[t][i],t,i)){
                    //방향바꾸기
                    changedir(teamidx[t][i]);
                    break;
                }
            }
        }
    }
    //밑에서 던지는 경우
    else if(t<2*N){
        t=t%N;
        for(int i=N-1;i>=0;i--){
            //사람이 있는 경우
            if(teamidx[i][t]>0){
                //공을 맞은 경우
                if(getpoints(teamidx[i][t],i,t)){
                    //방향바꾸기
                    changedir(teamidx[i][t]);
                    break;
                }
            }
        }
    }
    //오른쪽에서 던지는 경우
    else if(t<3*N){
        t=3*N-1-t;
        for(int i=N-1;i>=0;i--){
            //사람이 있는 경우
            if(teamidx[t][i]>0){
                //공을 맞은 경우
                if(getpoints(teamidx[t][i],t,i)){
                    //방향바꾸기
                    changedir(teamidx[t][i]);
                    break;
                }
            }
        }
    }
    //위에서 던지는 경우
    else{
        t=4*N-1-t;
        for(int i=0;i<N;i++){
            //사람이 있는 경우
            if(teamidx[i][t]>0){
                //공을 맞은 경우
                if(getpoints(teamidx[i][t],i,t)){
                    //방향바꾸기
                    changedir(teamidx[i][t]);
                    break;
                }
            }
        }
    }
}
void show(){
    for(int i=1;i<=M;i++){
        cout<<i<<"멤버들"<<'\n';
        for(int j=0;j<(int)team[i].size();j++){
            cout<<team[i][j].first<<' '<<team[i][j].second<<'\n';
        }
    }
    cout<<"팀크키\n";
    for(int i=1;i<=M;i++){
        cout<<teamsize[i]<<'\n';
    }
    cout<<"경로들\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<teamidx[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main(void){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>gamemap[i][j];
        }
    }
    //팀 생성
    findhead();
    //show();
    int round=0;
    while(round<K){
        //cout<<round<<"round\n";
        //show();
        moveteam();
        //show();
        throwball(round);
        //show();
        round++;
    }
    //show();
    int sum=0;
    for(int i=1;i<=M;i++){
        sum+=points[i];
    }
    cout<<sum;
    return 0;
}