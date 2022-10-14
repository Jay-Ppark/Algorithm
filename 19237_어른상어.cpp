#include<iostream>
#include<vector>
using namespace std;
int N, sharknum, smelltime;
int sharksmellmap[20][20];
int smellmap[20][20];
int restshark;
vector<pair<pair<int,int>,int> > shark[401];
vector<int> sharkorder[401][4];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
void deletesmell(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(smellmap[i][j]>=1){
                smellmap[i][j]--;
            }
            if(smellmap[i][j]==0){
                sharksmellmap[i][j]=0;
            }
        }
    }
}
void makesmell(){
    for(int i=1;i<=sharknum;i++){
        if(shark[i].empty()){
            continue;
        }
        int y=shark[i][0].first.first;
        int x=shark[i][0].first.second;
        sharksmellmap[y][x]=i;
        smellmap[y][x]=smelltime+1;
    }
}
void checkshark(){
    bool visited[20][20]={false,};
    for(int i=1;i<=sharknum;i++){
        if(shark[i].empty()){
            continue;
        }
        int y=shark[i][0].first.first;
        int x=shark[i][0].first.second;
        if(!visited[y][x]){
            visited[y][x]=true;
        }
        else{
            restshark--;
            shark[i].pop_back();
        }
    }
}
void moveshark(){
    for(int i=1;i<=sharknum;i++){
        if(shark[i].empty()){
            continue;
        }
        else{
            int y=shark[i][0].first.first;
            int x=shark[i][0].first.second;
            int d=shark[i][0].second;
            bool find=false;
            for(int t=0;t<4;t++){
                int tmpd=sharkorder[i][d][t];
                int ny=y+dy[tmpd];
                int nx=x+dx[tmpd];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                    if(smellmap[ny][nx]==0){
                        shark[i].pop_back();
                        shark[i].push_back({{ny,nx},tmpd});
                        find=true;
                        break;
                    }
                }
            }
            if(!find){
                for(int t=0;t<4;t++){
                    int tmpd=sharkorder[i][d][t];
                    int ny=y+dy[tmpd];
                    int nx=x+dx[tmpd];
                    if(ny>=0&&ny<N&&nx>=0&&nx<N){
                        if(sharksmellmap[ny][nx]==i){
                            shark[i].pop_back();
                            shark[i].push_back({{ny,nx},tmpd});
                            break;
                        }
                    }
                }
            }
        }
    }
}
int main(void){
    cin>>N>>sharknum>>smelltime;
    restshark=sharknum;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sharksmellmap[i][j];
            if(sharksmellmap[i][j]>0){
                shark[sharksmellmap[i][j]].push_back({{i,j},0});
                smellmap[i][j]=smelltime;
            }
        }
    }
    for(int i=1;i<=sharknum;i++){
        int tmpd;
        cin>>tmpd;
        shark[i][0].second=tmpd-1;
    }
    for(int i=1;i<=sharknum;i++){
        for(int d=0;d<4;d++){
            for(int j=0;j<4;j++){
                int tmp;
                cin>>tmp;
                sharkorder[i][d].push_back(tmp-1);
            }
        }
    }
    int ans=0;
    while(true){
        ans++;
        moveshark();
        checkshark();
        if(restshark==1||ans>1000){
            break;
        }
        makesmell();
        deletesmell();
    }
    if(ans>1000){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}