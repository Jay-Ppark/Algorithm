#include<iostream>
using namespace std;
int height,width,testcase;
int dustmap[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int countera;
int clocka;
void movedust(){
    int tmpdustmap[50][50]={0,};
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(dustmap[i][j]<=0){
                continue;
            }
            int cnt=0;
            for(int d=0;d<4;d++){
                int ny=i+dy[d];
                int nx=j+dx[d];
                if(ny>=0&&ny<height&&nx>=0&&nx<width){
                    if(dustmap[ny][nx]!=-1){
                        tmpdustmap[ny][nx]=tmpdustmap[ny][nx]+dustmap[i][j]/5;
                        cnt++;
                    }
                }
            }
            if(cnt>0){
                dustmap[i][j]=dustmap[i][j]-(dustmap[i][j]/5)*cnt;
            }
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(dustmap[i][j]!=-1){
                dustmap[i][j]=dustmap[i][j]+tmpdustmap[i][j];
            }
        }
    }
}
void circulate(){
    int tmpdustmap[50][50]={0,};
    for(int i=1;i<width-1;i++){
        tmpdustmap[countera][i+1]=dustmap[countera][i];
    }
    for(int i=countera;i>=1;i--){
        tmpdustmap[i-1][width-1]=dustmap[i][width-1];
    }
    for(int i=width-1;i>=1;i--){
        tmpdustmap[0][i-1]=dustmap[0][i];
    }
    for(int i=0;i<countera-1;i++){
        tmpdustmap[i+1][0]=dustmap[i][0];
    }
    for(int i=1;i<width-1;i++){
        tmpdustmap[clocka][i+1]=dustmap[clocka][i];
    }
    for(int i=clocka;i<height-1;i++){
        tmpdustmap[i+1][width-1]=dustmap[i][width-1];
    }
    for(int i=width-1;i>=1;i--){
        tmpdustmap[height-1][i-1]=dustmap[height-1][i];
    }
    for(int i=height-1;i>clocka+1;i--){
        tmpdustmap[i-1][0]=dustmap[i][0];
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0||i==countera||i==clocka||i==height-1||j==0||j==width-1){
                dustmap[i][j]=tmpdustmap[i][j];
            }
        }
    }
}
int count(){
    int result=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(dustmap[i][j]>0){
                result=result+dustmap[i][j];
            }
        }
    }
    return result;
}
int main(void){
    cin>>height>>width>>testcase;
    bool found=false;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>dustmap[i][j];
            if(!found&&dustmap[i][j]==-1){
                countera=i;
                clocka=i+1;
                found=true;
            }
        }
    }
    for(int t=0;t<testcase;t++){
        movedust();
        circulate();
    }
    cout<<count();
    return 0;
}