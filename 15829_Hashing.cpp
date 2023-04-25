#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    string s;
    cin>>s;
    long long int ans=0;
    const int M = 1234567891;
    long long int r=1;
    for(int i=0;i<(int)s.size();i++){
        ans+=(s[i]-'a'+1)*r%M;
        r=r*31%M;
    }
    cout<<ans%M;
    return 0;
}