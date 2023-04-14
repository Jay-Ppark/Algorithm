#include<iostream>
#include<set>
using namespace std;
int main(void){
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        int K;
        cin>>K;
        multiset<int> s;
        for(int i=0;i<K;i++){
            char c;
            int num;
            cin>>c>>num;
            if(c=='I'){
                s.insert(num);
            }
            else{
                if(s.empty()){
                    continue;
                }
                if(num==1){
                    s.erase(prev(s.end()));
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()){
            cout<<"EMPTY\n";
        }
        else{
            cout<<*prev(s.end())<<' '<<*s.begin();
            cout<<'\n';
        }
    }
    return 0;
}