#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int K,L;
    cin>>K>>L;
    unordered_map<string,int> m;
    for(int i=0;i<L;i++){
        string tmp;
        cin>>tmp;
        m[tmp]=i;
    }
    vector<pair<int,string>> v;
    for(auto e:m){
        v.push_back({e.second,e.first});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i++){
        if(i==K){
            break;
        }
        cout<<v[i].second<<'\n';
    }
    return 0;
}