#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int N,K;
int w,h;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
deque<int> glass[100];
void findmin(){
    vector<int> minidx;
    int tmpmin=10001;
    for(int i=0;i<glass[0].size();i++){
        if(tmpmin>glass[0][i]){
            tmpmin=glass[0][i];
            minidx.clear();
            minidx.push_back(i);
        }
        else if(tmpmin==glass[0][i]){
            minidx.push_back(i);
        }
    }
    for(int i=0;i<minidx.size();i++){
        glass[0][minidx[i]]++;
    }
}
bool canlayer(int w,int h){
    if(glass[0].size()-w<h){
        return false;
    }
    else{
        return true;
    }
}
void layerglass(){
    w=1;
    h=1;
    int t=1;
    int tmpw=w;
    int tmph=h;
    while(true){
        if(!canlayer(w,h)){
            break;
        }
        tmpw=w;
        tmph=h;
        if(t%2==1){
            h++;
        }
        else{
            w++;
        }
        for(int i=0;i<tmpw;i++){
            for(int j=0;j<tmph;j++){
                int tmp=glass[j].front();
                glass[j].pop_front();
                glass[h-1-i].push_back(tmp);
            }
        }
        t++;
    }
}
void spreadfish(){
    int tmpglass[100][100]={0,};
    bool visited[100][100]={false,};
    for(int i=0;i<h;i++){
        for(int j=0;j<glass[i].size();j++){
            int tmpy=i;
            int tmpx=j;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                tmpy=i+dy[d];
                tmpx=j+dx[d];
                if(tmpy>=0&&tmpy<h&&tmpx>=0&&tmpx<glass[tmpy].size()&&!visited[tmpy][tmpx]){
                    int diff;
                    if(glass[i][j]>glass[tmpy][tmpx]){
                        diff=glass[i][j]-glass[tmpy][tmpx];
                        diff=diff/5;
                        tmpglass[i][j]=tmpglass[i][j]-diff;
                        tmpglass[tmpy][tmpx]=tmpglass[tmpy][tmpx]+diff;
                    }
                    else{
                        diff=glass[tmpy][tmpx]-glass[i][j];
                        diff=diff/5;
                        tmpglass[tmpy][tmpx]=tmpglass[tmpy][tmpx]-diff;
                        tmpglass[i][j]=tmpglass[i][j]+diff;
                    }
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<glass[i].size();j++){
            glass[i][j]=glass[i][j]+tmpglass[i][j];
        }
    }
}
void flatten(){
    int zerolen=glass[0].size();
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            int tmp=glass[j].front();
            glass[j].pop_front();
            glass[0].push_back(tmp);
        }
    }
    for(int i=w;i<zerolen;i++){
        int tmp=glass[0].front();
        glass[0].pop_front();
        glass[0].push_back(tmp);
    }
}
void layerdivideglass(){
    for(int i=0;i<N/2;i++){
        int tmp=glass[0].front();
        glass[0].pop_front();
        glass[1].push_front(tmp);
    }
    int index=1;
    for(int i=1;i>=0;i--){
        index++;
        for(int j=0;j<N/4;j++){
            int tmp=glass[i].front();
            glass[i].pop_front();
            glass[index].push_front(tmp);
        }
    }
}
int findminmax(){
    int minf=10001;
    int maxf=0;
    for(int i=0;i<glass[0].size();i++){
        if(minf>glass[0][i]){
            minf=glass[0][i];
        }
        if(maxf<glass[0][i]){
            maxf=glass[0][i];
        }
    }
    return maxf-minf;
}
int main(void){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        glass[0].push_back(tmp);
    }
    int t=1;
    while(true){
        findmin();
        layerglass();
        spreadfish();
        flatten();
        layerdivideglass();
        w=N/4;
        h=4;
        spreadfish();
        flatten();
        if(K>=findminmax()){
            break;
        }
        t++;
    }
    cout<<t;
    return 0;
}