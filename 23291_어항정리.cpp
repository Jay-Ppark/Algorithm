#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int N,K;
deque<int> glass[100];
int dx[2]={0,-1};
int dy[2]={1,0};
bool checkf(){
    int minf=987654321;
    int maxf=-987654321;
    for(int i=0;i<glass[0].size();i++){
        if(glass[0][i]>maxf){
            maxf=glass[0][i];
        }
        if(glass[0][i]<minf){
            minf=glass[0][i];
        }
    }
    if(maxf-minf<=K){
        return true;
    }
    else{
        return false;
    }
}
void findmin(){
    int minFish=987654321;
    vector<int> idxmin;
    for(int i=0;i<glass[0].size();i++){
        if(glass[0][i]<minFish){
            idxmin.clear();
            idxmin.push_back(i);
            minFish=glass[0][i];
        }
        else if(glass[0][i]==minFish){
            idxmin.push_back(i);
        }
    }
    for(int i=0;i<idxmin.size();i++){
        glass[0][idxmin[i]]++;
    }
}
bool canlayer(int width,int height){
    if(glass[0].size()-width<height){
        return false;
    }
    return true;
}
int makeglass(){
    int width=1;
    int height=1;
    bool check=false;
    while(1){
        if(canlayer(width,height)==false){
            break;
        }
        int tmpwidth=width;
        for(int i=0;i<width;i++,tmpwidth--){
            int idx=0;
            for(int j=0;j<height;j++,idx++){
                glass[tmpwidth].push_back(glass[idx][i]);
            }
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                glass[i].pop_front();
            }
        }
        if(!check){
            height++;
            check=true;
        }
        else{
            width++;
            check=false;
        }
    }
    return height;
}
void spreadfish(int height){
    deque<int> tmp[100];
    for(int i=0;i<height;i++){
        tmp[i]=glass[i];
    }
    for(int i=height-1;i>=0;i--){
        for(int j=0;j<glass[i].size();j++){
            int x=i;
            int y=j;
            int num=glass[x][y];
            for(int k=0;k<2;k++){
                int ny=y+dy[k];
                int nx=x+dx[k];
                if(nx>=0&&ny<glass[i].size()){
                    int num2=glass[nx][ny];
                    int diff = abs(num-num2) / 5;
                    if(diff>0){
                        if(num>num2){
                            tmp[x][y]=tmp[x][y]-diff;
                            tmp[nx][ny]=tmp[nx][ny]+diff;
                        }
                        else{
                            tmp[nx][ny]=tmp[nx][ny]-diff;
                            tmp[x][y]=tmp[x][y]+diff;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<height;i++){
        glass[i]=tmp[i];
    }
}
void spreadglass(int height){
    int width=glass[height-1].size();
    int size=glass[0].size();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            glass[0].push_back(glass[j][i]);
        }
    }
    for(int i=1;i<height;i++){
        glass[i].clear();
    }
    for(int i=width;i<size;i++){
        glass[0].push_back(glass[0][i]);
    }
    for(int i=0;i<size;i++){
        glass[0].pop_front();
    }
}
void makeglass2(){
    int n = glass[0].size();
    for(int i=0;i<n/2;i++){
        glass[1].push_front(glass[0][i]);
    }
    for(int i=0;i<n/2;i++){
        glass[0].pop_front();
    }
    for(int i=0;i<n/4;i++){
        glass[3].push_front(glass[0][i]);
        glass[2].push_front(glass[1][i]);
    }
    for(int i=0;i<n/4;i++){
        glass[0].pop_front();
        glass[1].pop_front();
    }
}
int main(void){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        glass[0].push_back(tmp);
    }
    int answer=0;
    while(1){
        if(checkf()){
            cout<<answer;
            break;
        }
        findmin();
        int h = makeglass();
        spreadfish(h);
        spreadglass(h);
        makeglass2();
        spreadfish(4);
        spreadglass(4);
        answer++;
    }
    return 0;
}