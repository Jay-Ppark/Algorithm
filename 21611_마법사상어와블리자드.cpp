#include<iostream>
#include<vector>
using namespace std;
int N, magicnum;
int marblemap[49][49];
int mapnumber[49][49];
int marble[2500];
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
int sharky,sharkx;
vector<pair<int,int>> magic;
int marbleresult[3];
void makemapnumber(){
    int ny=sharky;
    int nx=sharkx;
    int d=0;
    int mnum=1;
    int cnt=1;
    bool needstop=false;
    while(true){
        for(int i=0;i<cnt;i++){
            ny=ny+dy[d];
            nx=nx+dx[d];
            if(ny<0||ny>=N||nx<0||nx>=N){
                needstop=true;
                break;
            }
            mapnumber[ny][nx]=mnum;
            marble[mnum]=marblemap[ny][nx];
            mnum++;
        }
        if(needstop){
            break;
        }
        d=(d+1)%4;
        for(int i=0;i<cnt;i++){
            ny=ny+dy[d];
            nx=nx+dx[d];
            mapnumber[ny][nx]=mnum;
            marble[mnum]=marblemap[ny][nx];
            mnum++;
        }
        d=(d+1)%4;
        cnt++;
    }
}
void domagic(int index){
    int d=magic[index].first;
    int s=magic[index].second;
    int ny=sharky;
    int nx=sharkx;
    for(int i=0;i<s;i++){
        ny=ny+dy[d];
        nx=nx+dx[d];
        marble[mapnumber[ny][nx]]=0;
    }
}
void movemarble(){
    for(int i=1;i<N*N;i++){
        if(marble[i]==0){
            for(int j=i+1;j<N*N;j++){
                if(marble[j]!=0){
                    marble[i]=marble[j];
                    marble[j]=0;
                    break;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            marblemap[i][j]=marble[mapnumber[i][j]];
        }
    }
}
bool explodemarble(){
    bool isfinish=true;
    int prev=0;
    int len=0;
    for(int i=1;i<N*N;i++){
        if(marble[i]==0){
            break;
        }
        if(prev==0){
            prev=1;
            len=1;
        }
        else{
            if(marble[prev]==marble[i]){
                len++;
            }
            else{
                if(len>=4){
                    isfinish=false;
                    for(int j=prev;j<i;j++){
                        marbleresult[marble[j]-1]++;
                        marble[j]=0;
                    }
                }
                len=1;
                prev=i;
            }
        }
    }
    if(len>=4&&prev!=0){
        isfinish=false;
        for(int i=prev;i<prev+len;i++){
            marbleresult[marble[i]-1]++;
            marble[i]=0;
        }
    }
    if(!isfinish){
        return false;
    }
    else{
        return true;
    }
}
void makegroup(){
    int prev=0;
    int len=0;
    int tmp[N*N]={0,};
    int cnt=1;
    for(int i=1;i<N*N;i++){
        if(marble[i]==0){
            break;
        }
        if(prev==0){
            prev=1;
            len=1;
        }
        else{
            if(marble[prev]==marble[i]){
                len++;
            }
            else{
                if(cnt>N*N){
                    break;
                }
                tmp[cnt]=len;
                cnt++;
                if(cnt>N*N){
                    break;
                }
                tmp[cnt]=marble[prev];
                cnt++;
                len=1;
                prev=i;
            }
        }
    }
    if(cnt<N*N){
        tmp[cnt]=len;
        cnt++;
    }
    if(cnt<N*N){
        tmp[cnt]=marble[prev];
    }
    for(int i=0;i<N*N;i++){
        marble[i]=tmp[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            marblemap[i][j]=marble[marblemap[i][j]];
        }
    }
}
int main(void){
    cin>>N>>magicnum;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>marblemap[i][j];
        }
    }
    for(int i=0;i<magicnum;i++){
        int d,s;
        cin>>d>>s;
        if(d==1){
            magic.push_back({3,s});
        }
        else if(d==2){
            magic.push_back({1,s});
        }
        else if(d==3){
            magic.push_back({0,s});
        }
        else{
            magic.push_back({2,s});
        }
    }
    sharky=(N+1)/2-1;
    sharkx=(N+1)/2-1;
    makemapnumber();
    for(int i=0;i<magicnum;i++){
        domagic(i);
        movemarble();
        while(true){
            bool keepgoing=explodemarble();
            movemarble();
            if(keepgoing){
                break;
            }
        }
        makegroup();
    }
    cout<<marbleresult[0]+marbleresult[1]*2+marbleresult[2]*3<<'\n';
    return 0;
}