#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
    int N;
    cin>>N;
    unordered_map<string,int> m;
    for(int i=0;i<N;i++){
        string name, order;
        cin>>name>>order;
        if(order=="enter"){
            m[name]=1;
        }
        else{
            m[name]=0;
        }
    }
    vector<string> v;
    for(auto e:m){
        if(e.second==1){
            v.push_back(e.first);
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<'\n';
    }
    return 0;
}