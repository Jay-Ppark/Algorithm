#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mapnum[101][101];
int numcnt[101];
void show(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cout<<mapnum[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(void){
    int r,c,k;
    cin>>r>>c>>k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>mapnum[i][j];
        }
    }
    int t=0;
    int height=3, width=3;
    while(t<=100){
        if(mapnum[r][c]==k){
            break;
        }
        if(height>=width){
            vector<int> vsize;
            for(int i=1;i<=height;i++){
                vector<pair<int,int>> v;
                for(int j=1;j<=width;j++){
                    if(mapnum[i][j]>0){
                        numcnt[mapnum[i][j]]++;
                    }
                    mapnum[i][j]=0;
                }
                for(int s=1;s<=100;s++){
                    if(numcnt[s]>=1){
                        v.push_back({numcnt[s],s});
                        numcnt[s]=0;
                    }
                }
                sort(v.begin(),v.end());
                int idx=1;
                for(int d=0;d<v.size();d++){
                    if(idx>100){
                        break;
                    }
                    mapnum[i][idx]=v[d].second;
                    idx++;
                    mapnum[i][idx]=v[d].first;
                    idx++;
                }
                vsize.push_back(idx-1);
            }
            sort(vsize.begin(),vsize.end());
            width=vsize.back();
        }
        else{
            vector<int> vsize;
            for(int i=1;i<=width;i++){
                vector<pair<int,int>> v;
                for(int j=1;j<=height;j++){
                    if(mapnum[j][i]>0){
                        numcnt[mapnum[j][i]]++;
                    }
                    mapnum[j][i]=0;
                }
                for(int s=1;s<=100;s++){
                    if(numcnt[s]>=1){
                        v.push_back({numcnt[s],s});
                        numcnt[s]=0;
                    }
                }
                sort(v.begin(),v.end());
                int idx=1;
                for(int d=0;d<v.size();d++){
                    if(idx>100){
                        break;
                    }
                    mapnum[idx][i]=v[d].second;
                    idx++;
                    mapnum[idx][i]=v[d].first;
                    idx++;
                }
                vsize.push_back(idx-1);
            }
            sort(vsize.begin(),vsize.end());
            height=vsize.back();
        }
        t++;
    }
    if(t>=101){
        cout<<-1;
    }
    else{
        cout<<t;
    }
    return 0;
}