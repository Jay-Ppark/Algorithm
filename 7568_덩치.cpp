#include<iostream>
#include<vector>
using namespace std;
int result[50];
int main(void){
    vector<pair<int,int>> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int w,h;
        cin>>w>>h;
        v.push_back({w,h});
    }
    for(int i=0;i<N;i++){
        result[i]=1;
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(v[i].first<v[j].first&&v[i].second<v[j].second){
                result[i]+=1;
            }
            else if(v[i].first>v[j].first&&v[i].second>v[j].second){
                result[j]+=1;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<result[i]<<' ';
    }
    return 0;
}