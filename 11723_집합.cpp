#include<iostream>
#include<set>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> s;
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        if(tmp=="add"){
            int a;
            cin>>a;
            s.insert(a);
        }
        else if(tmp=="remove"){
            int a;
            cin>>a;
            s.erase(a);
        }
        else if(tmp=="check"){
            int a;
            cin>>a;
            cout<<s.count(a)<<'\n';
        }
        else if(tmp=="toggle"){
            int a;
            cin>>a;
            if(s.count(a)==0){
                s.insert(a);
            }
            else{
                s.erase(a);
            }
        }
        else if(tmp=="all"){
            for(int j=1;j<=20;j++){
                s.insert(j);
            }
        }
        else if(tmp=="empty"){
            s.clear();
        }
    }
    return 0;
}