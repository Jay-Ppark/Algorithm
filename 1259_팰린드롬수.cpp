#include<iostream>
using namespace std;
int main(void){
    string s;
    while(true){
        cin>>s;
        if(s=="0"){
            break;
        }
        else{
            int l=s.size()/2;
            bool isp=true;
            for(int i=0;i<l;i++){
                if(s[i]!=s[s.size()-1-i]){
                    isp=false;
                    cout<<"no\n";
                    break;
                }
            }
            if(isp){
                cout<<"yes\n";
            }
        }
    }
    return 0;
}