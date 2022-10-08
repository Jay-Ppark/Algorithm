#include<iostream>
#include<vector>
using namespace std;
int N,M;
int watermap[51][51];
bool iscloud[51][51];
vector<pair<int,int> > cloudmagic;
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int checky[4]={-1,-1,1,1};
int checkx[4]={-1,1,1,-1};
void movecloud(int index){
    bool tmpcloud[51][51]={false,};
    int d=cloudmagic[index].first;
    int s=cloudmagic[index].second;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(iscloud[i][j]){
                int ny=i;
                int nx=j;
                for(int t=0;t<s;t++){
                    ny=ny+dy[d];
                    nx=nx+dx[d];
                    if(ny>N){
                        ny=ny%N;
                    }
                    else if(ny<=0){
                        ny=N;
                    }
                    if(nx>N){
                        nx=nx%N;
                    }
                    else if(nx<=0){
                        nx=N;
                    }
                }
                tmpcloud[ny][nx]=true;
                watermap[ny][nx]++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            iscloud[i][j]=false;
            iscloud[i][j]=tmpcloud[i][j];
        }
    }
}
void copywater(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(iscloud[i][j]){
                int cnt=0;
                for(int t=0;t<4;t++){
                    int ny=i+checky[t];
                    int nx=j+checkx[t];
                    if(ny>0&&ny<=N&&nx>0&&nx<=N){
                        if(watermap[ny][nx]>0){
                            cnt++;
                        }
                    }
                }
                watermap[i][j]=watermap[i][j]+cnt;
            }
        }
    }
}
void makecloud(){
    bool tmpcloud[51][51]={false,};
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(watermap[i][j]>=2&&!iscloud[i][j]){
                watermap[i][j]=watermap[i][j]-2;
                tmpcloud[i][j]=true;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            iscloud[i][j]=false;
            iscloud[i][j]=tmpcloud[i][j];
        }
    }
}
int calans(){
    int answer=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            answer=answer+watermap[i][j];
        }
    }
    return answer;
}
int main(void){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>watermap[i][j];
        }
    }
    for(int i=0;i<M;i++){
        int d,s;
        cin>>d>>s;
        cloudmagic.push_back({d,s});
    }
    iscloud[N][1]=true;
    iscloud[N][2]=true;
    iscloud[N-1][1]=true;
    iscloud[N-1][2]=true;
    for(int i=0;i<M;i++){
        movecloud(i);
        copywater();
        makecloud();
    }
    cout<<calans();
    return 0;
}