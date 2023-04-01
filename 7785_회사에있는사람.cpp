#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(void){
    map<string,int,greater<>> m;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string name, state;
        cin>>name>>state;
        if(state=="enter"){
            m[name]=1;
        }
        else{
            m[name]=0;
        }
    }
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second==1){
            cout<<it->first<<'\n';
        }
    }
    return 0;
}