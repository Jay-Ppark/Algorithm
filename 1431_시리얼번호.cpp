#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
bool comp(string a,string b){
    if(a.length()<b.length()){
        return true;
    }
    else if(a.length()>b.length()){
        return false;
    }
    else{
        int asum=0;
        for(int i=0;i<a.length();i++){
            int tmp=a[i]-48;
            if(tmp<=9){
                asum=asum+tmp;
            }
        }
        int bsum=0;
        for(int i=0;i<b.length();i++){
            int tmp=b[i]-48;
            if(tmp<=9){
                bsum=bsum+tmp;
            }
        }
        if(asum<bsum){
            return true;
        }
        else if(asum>bsum){
            return false;
        }
        else{
            return a<b;
        }
    }
}
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<N;i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}