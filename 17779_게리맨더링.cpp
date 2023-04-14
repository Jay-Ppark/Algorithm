#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int arr[21][21];
int dividemap[21][21];
int N;
vector<int> v;
bool chk(int x,int y){
    if(x>=1&&x<=N&&y>=1&&y<=N){
        return true;
    }
    return false;
}
bool divide(int x,int y,int d1,int d2){
    memset(dividemap,0,sizeof(dividemap));
    dividemap[x][y]=5;
    int initx1=x;
    int inity1=y;
    //1 구역
    for(int i=0;i<d1;i++){
        int nx=initx1+1;
        int ny=inity1-1;
        if(!chk(nx,ny)){
            return false;
        }
        initx1=nx;
        inity1=ny;
        for(int j=ny;j<=y;j++){
            dividemap[nx][j]=5;
        }
    }
    //2 구역
    int initx2=x;
    int inity2=y;
    for(int i=0;i<d2;i++){
        int nx=initx2+1;
        int ny=inity2+1;
        if(!chk(nx,ny)){
            return false;
        }
        initx2=nx;
        inity2=ny;
        for(int j=y;j<=ny;j++){
            dividemap[nx][j]=5;
        }
    }
    //3 구역
    int initx3=x+d1;
    int inity3=y-d1;
    for(int i=0;i<d2;i++){
        int nx=initx3+1;
        int ny=inity3+1;
        if(!chk(nx,ny)){
            return false;
        }
        initx3=nx;
        inity3=ny;
        for(int j=ny;j<=y-d1+d2;j++){
            dividemap[nx][j]=5;
        }
    }
    //4 구역
    int initx4=x+d2;
    int inity4=y+d2;
    for(int i=0;i<d1;i++){
        int nx=initx4+1;
        int ny=inity4-1;
        if(!chk(nx,ny)){
            return false;
        }
        initx4=nx;
        inity4=ny;
        for(int j=y-d1+d2;j<=ny;j++){
            dividemap[nx][j]=5;
        }
    }
    return true;
}
int cal1(int x,int y,int d1,int d2){
    int result=0;
    for(int i=1;i<x+d1;i++){
        for(int j=1;j<=y;j++){
            if(dividemap[i][j]!=5){
                result+=arr[i][j];
            }
        }
    }
    return result;
}
int cal2(int x,int y,int d1,int d2){
    int result=0;
    for(int i=1;i<=x+d2;i++){
        for(int j=y+1;j<=N;j++){
            if(dividemap[i][j]!=5){
                result+=arr[i][j];
            }
        }
    }
    return result;
}
int cal3(int x,int y,int d1,int d2){
    int result=0;
    for(int i=x+d1;i<=N;i++){
        for(int j=1;j<y-d1+d2;j++){
            if(dividemap[i][j]!=5){
                result+=arr[i][j];
            }
        }
    }
    return result;
}
int cal4(int x,int y,int d1,int d2){
    int result=0;
    for(int i=x+d2+1;i<=N;i++){
        for(int j=y-d1+d2;j<=N;j++){
            if(dividemap[i][j]!=5){
                result+=arr[i][j];
            }
        }
    }
    return result;
}
int main(void){
    cin>>N;
    int sumarr=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            sumarr+=arr[i][j];
        }
    }
    int minans=1e9;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int d1=1;d1<=18;d1++){
                for(int d2=1;d2<=18;d2++){
                    if(i+d1+d2>N){
                        break;
                    }
                    if(!divide(i,j,d1,d2)){
                        continue;
                    }
                    v.clear();
                    int sum1=cal1(i,j,d1,d2);
                    int sum2=cal2(i,j,d1,d2);
                    int sum3=cal3(i,j,d1,d2);
                    int sum4=cal4(i,j,d1,d2);
                    int sum5=sumarr-sum1-sum2-sum3-sum4;
                    if(sum1>=1&&sum2>=1&&sum3>=1&&sum4>=1&&sum5>=1){
                        vector<int> v;
                        v.push_back(sum1);
                        v.push_back(sum2);
                        v.push_back(sum3);
                        v.push_back(sum4);
                        v.push_back(sum5);
                        sort(v.begin(),v.end());
                        if(minans>v.back()-v.front()){
                            minans=v.back()-v.front();
                        }
                    }
                }
            }
        }
    }
    cout<<minans;
    return 0;
}