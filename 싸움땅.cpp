#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N,M,K;
vector<int> gunmap[20][20];
tuple<int,int,int,int,int> human[31];
int points[31];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void updatehuman(int index,int y,int x,int d,int s,int a){
    human[index]={y,x,d,s,a};
}
int ishuman(int ny,int nx){
    int y,x;
    for(int i=1;i<=M;i++){
        tie(y,x,ignore,ignore,ignore)=human[i];
        if(ny==y&&nx==x){
            return i;
        }
    }
    return 0;
}
tuple<int,int,int> movedir(int y,int x,int d){
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(ny>=0&&ny<N&&nx>=0&&nx<N){
        return {ny,nx,d};
    }
    else{
        d=d+2;
        d=d%4;
        ny=y+dy[d];
        nx=x+dx[d];
        return {ny,nx,d};
    }
}
void getgun(int index){
    int y,x,d,s,a;
    tie(y,x,d,s,a)=human[index];
    //원래 무기가 없는 경우
    if(a==0){
        //칸에 무기가 있는 경우
        if(!gunmap[y][x].empty()){
            sort(gunmap[y][x].begin(),gunmap[y][x].end());
            a=gunmap[y][x].back();
            gunmap[y][x].pop_back();
        }
        //칸에 무기가 없는 경우
    }
    //무기가 있는 경우
    else{
        //칸에 무기가 있는 경우
        if(!gunmap[y][x].empty()){
            sort(gunmap[y][x].begin(),gunmap[y][x].end());
            int tmpa=gunmap[y][x].back();
            //원래 무기가 안좋은 경우
            if(a<tmpa){
                gunmap[y][x].pop_back();
                gunmap[y][x].push_back(a);
                a=tmpa;
            }
            //원래 무기가 좋은 경우
        }
        //칸에 무기가 없는 경우
    }
    updatehuman(index,y,x,d,s,a);
}
void win(int index){
    //가지고 있는 총과 비교
    int y,x,d,s,a;
    tie(y,x,d,s,a)=human[index];
    //총이 있는 경우
    if(a>0){
        //바닥에 총이 있는 경우
        if(!gunmap[y][x].empty()){
            sort(gunmap[y][x].begin(),gunmap[y][x].end());
            int tmpa=gunmap[y][x].back();
            //기존의 총이 안좋은 경우
            if(a<tmpa){
                gunmap[y][x].pop_back();
                gunmap[y][x].push_back(a);
                a=tmpa;
            }
        }
        //바닥에 총이 없는 경우
    }
    //총이 없는 경우
    else{
        //바닥에 총이 있는 경우
        if(!gunmap[y][x].empty()){
            sort(gunmap[y][x].begin(),gunmap[y][x].end());
            a=gunmap[y][x].back();
            gunmap[y][x].pop_back();
        }
        //바닥에 총이 없는 경우
    }
    updatehuman(index,y,x,d,s,a);
}
void lose(int index){
    //총을 버림
    int y,x,d,s,a;
    tie(y,x,d,s,a)=human[index];
    //총이 있는 경우
    if(a>0){
        gunmap[y][x].push_back(a);
        a=0;
    }
    //방향 이동
    int ny=y;
    int nx=x;
    for(int i=0;i<4;i++){
        ny=y+dy[d];
        nx=x+dx[d];
        if(ny>=0&&ny<N&&nx>=0&&nx<N){
            if(ishuman(ny,nx)==0){
                break;
            }
        }
        d++;
        d=d%4;
    }
    //총 줍기
    //총이 있는 경우
    if(!gunmap[ny][nx].empty()){
        sort(gunmap[ny][nx].begin(),gunmap[ny][nx].end());
        a=gunmap[ny][nx].back();
        gunmap[ny][nx].pop_back();
    }
    updatehuman(index,ny,nx,d,s,a);
}
void playgame(){
    for(int i=1;i<=M;i++){
        int y,x,d,s,a;
        tie(y,x,d,s,a)=human[i];
        int ny,nx,nd;
        //이동
        tie(ny,nx,nd)=movedir(y,x,d);
        //이동한 곳 확인
        int index=ishuman(ny,nx);
        updatehuman(i,ny,nx,nd,s,a);
        //이동한 방향에 사람이 없는 경우
        if(index==0){
            getgun(i);
        }
        //이동한 방향에 사람이 있는 경우
        else{
            //비교
            //기존에 있던애
            int stayy,stayx,stayd,stays,staya;
            tie(stayy,stayx,stayd,stays,staya)=human[index];
            //새로온 애가 이긴경우
            if(s+a>stays+staya){
                points[i]+=s+a-stays-staya;
                lose(index);
                win(i);
            }
            //같은 경우
            else if(s+a==stays+staya){
                //새로운 애가 이긴 경우
                if(s>stays){
                    lose(index);
                    win(i);
                }
                //기존 애가 이긴 경우
                else{
                    lose(i);
                    win(index);
                }
            }
            //기존 애가 이긴경우
            else{
                points[index]+=stays+staya-s-a;
                lose(i);
                win(index);
            }
        }
    }
}
int main(void){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            if(tmp!=0){
                gunmap[i][j].push_back(tmp);
            }
        }
    }
    for(int i=1;i<=M;i++){
        int y,x,d,s;
        cin>>y>>x>>d>>s;
        human[i]={y-1,x-1,d,s,0};
    }
    while(K>0){
        playgame();
        K--;
    }
    for(int i=1;i<=M;i++){
        cout<<points[i]<<' ';
    }
    return 0;
}