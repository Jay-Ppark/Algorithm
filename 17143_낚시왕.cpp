#include<iostream>
#include<vector>
using namespace std;
int sharkcnt[101][101];
struct sharkInfo{
    int y,x,s,d,size;
    bool live=true;
};
vector<sharkInfo> shark;
int R,C;
int dy[5]={0,-1,1,0,0};
int dx[5]={0,0,0,1,-1};
int result;
void catchshark(int t){
    for(int i=1;i<=R;i++){
        if(sharkcnt[i][t]>0){
            for(int j=0;j<shark.size();j++){
                if(shark[j].live&&i==shark[j].y&&t==shark[j].x){
                    shark[j].live=false;
                    result=result+shark[j].size;
                    break;
                }
            }
            break;
        }
    }
}
void init(){
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            sharkcnt[i][j]=0;
        }
    }
}
void moveshark(){
    for(int i=0;i<shark.size();i++){
        if(shark[i].live){
            int y=shark[i].y;
            int x=shark[i].x;
            int d=shark[i].d;
            int s=shark[i].s;
            if(d<=2){
                s=s%((R-1)*2);
            }
            else{
                s=s%((C-1)*2);
            }
            for(int j=0;j<s;j++){
                int ny=y+dy[d];
                int nx=x+dx[d];
                if(ny<1||ny>R||nx<1||nx>C){
                    if(d==1){
                        d=2;
                    }
                    else if(d==2){
                        d=1;
                    }
                    else if(d==3){
                        d=4;
                    }
                    else if(d==4){
                        d=3;
                    }
                    ny=y+dy[d];
                    nx=x+dx[d];
                }
                y=ny;
                x=nx;
            }
            sharkcnt[y][x]++;
            shark[i].y=y;
            shark[i].x=x;
            shark[i].d=d;
        }
    }
}
void eatshark(int y,int x){
    int maxsize=-1;
    for(int i=0;i<shark.size();i++){
        if(shark[i].live){
            if(shark[i].y==y&&shark[i].x==x){
                if(maxsize<shark[i].size){
                    maxsize=shark[i].size;
                }
            }
        }
    }
    for(int i=0;i<shark.size();i++){
        if(shark[i].live){
            if(shark[i].y==y&&shark[i].x==x&&shark[i].size!=maxsize){
                shark[i].live=false;
                sharkcnt[y][x]--;
            }
        }
    }
}
int main(void){
    int sharknum;
    cin>>R>>C>>sharknum;
    for(int i=0;i<sharknum;i++){
        sharkInfo stmp;
        cin>>stmp.y>>stmp.x>>stmp.s>>stmp.d>>stmp.size;
        shark.push_back(stmp);
        sharkcnt[stmp.y][stmp.x]++;
    }
    for(int t=1;t<=C;t++){
        catchshark(t);
        init();
        moveshark();
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(sharkcnt[i][j]>1){
                    eatshark(i,j);
                }
            }
        }
    }
    cout<<result;
    return 0;
}