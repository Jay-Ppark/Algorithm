#include<iostream>
using namespace std;
int N,M,K,C;
int treemap[20][20];
int tmptreemap[20][20];
int poisonmap[20][20];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int py[4]={-1,-1,1,1};
int px[4]={-1,1,-1,1};
int answer;
void growtree(){
    //기존 정보 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmptreemap[i][j]=treemap[i][j];
        }
    }
    //나무 성장
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(treemap[i][j]>0){
                int ny=i;
                int nx=j;
                int cnt=0;
                for(int d=0;d<4;d++){
                    ny=i+dy[d];
                    nx=j+dx[d];
                    if(ny>=0&&ny<N&&nx>=0&&nx<N){
                        if(treemap[ny][nx]>0){
                            cnt++;
                        }
                    }
                }
                tmptreemap[i][j]+=cnt;
            }
        }
    }
    //성장한 정보 가져오기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            treemap[i][j]=tmptreemap[i][j];
        }
    }
}
void maketree(){
    //기존 정보 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmptreemap[i][j]=treemap[i][j];
        }
    }
    //나무 번식
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(treemap[i][j]>0){
                int ny=i;
                int nx=j;
                int cnt=0;
                for(int d=0;d<4;d++){
                    ny=i+dy[d];
                    nx=j+dx[d];
                    if(ny>=0&&ny<N&&nx>=0&&nx<N){
                        if(treemap[ny][nx]==0&&poisonmap[ny][nx]==0){
                            cnt++;
                        }
                    }
                }
                if(cnt>0){
                    for(int d=0;d<4;d++){
                        ny=i+dy[d];
                        nx=j+dx[d];
                        if(ny>=0&&ny<N&&nx>=0&&nx<N){
                            if(treemap[ny][nx]==0&&poisonmap[ny][nx]==0){
                                tmptreemap[ny][nx]+=treemap[i][j]/cnt;
                            }
                        }
                    }
                }
            }
        }
    }
    //성장한 정보 가져오기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            treemap[i][j]=tmptreemap[i][j];
        }
    }
}
int caltree(int y,int x){
    //몇그루 없앨수 있는지 계산하기
    int result=0;
    if(treemap[y][x]>0){
        result+=treemap[y][x];
        for(int d=0;d<4;d++){
            int ny=y;
            int nx=x;
            int cnt=0;
            while(cnt<K){
                ny+=py[d];
                nx+=px[d];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                //나무가 있는 경우
                    if(treemap[ny][nx]>0){
                        result+=treemap[ny][nx];
                    }
                    //나무가 없는 경우
                    else{
                        break;
                    }
                }
                //범위를 벗어난 경우
                else{
                    break;
                }
                cnt++;
            }
        }
    }
    else{
        return 0;
    }
    return result;
}
void makepoison(int t){
    int tmpmax=-1;
    int y=0;
    int x=0;
    //어디가 가장 많이 없애는지 찾기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(treemap[i][j]>=0){
                int tmp=caltree(i,j);
                if(tmp>tmpmax){
                    tmpmax=tmp;
                    y=i;
                    x=j;
                }
            }
        }
    }
    answer+=tmpmax;
    //제초제 뿌리기
    //나무가 있는 경우
    if(treemap[y][x]>0){
        treemap[y][x]=0;
        poisonmap[y][x]=t;
        for(int d=0;d<4;d++){
            int ny=y;
            int nx=x;
            int cnt=0;
            while(cnt<K){
                ny+=py[d];
                nx+=px[d];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                //나무가 있는 경우
                    if(treemap[ny][nx]>0){
                        treemap[ny][nx]=0;
                        poisonmap[ny][nx]=t;
                    }
                    //나무가 없는 경우
                    else{
                        if(treemap[ny][nx]==0){
                            poisonmap[ny][nx]=t;
                        }
                        break;
                    }
                }
                //범위를 벗어난 경우
                else{
                    break;
                }
                cnt++;
            }
        }
    }
}
//시간 지난 제초제 없애기
void deletepoison(int t){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(poisonmap[i][j]>0&&t-poisonmap[i][j]==C){
                poisonmap[i][j]=0;
            }
        }
    }
}
void show(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<treemap[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<poisonmap[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main(void){
    cin>>N>>M>>K>>C;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>treemap[i][j];
        }
    }
    int growtime=1;
    while(growtime<=M){
        //나무 성장
        growtree();
        //나무 번식
        maketree();
        //제초제 뿌리기
        makepoison(growtime);
        //시간이 지난 제초제 없애기
        deletepoison(growtime);
        growtime++;
    }
    cout<<answer;
    //show();
    return 0;
}