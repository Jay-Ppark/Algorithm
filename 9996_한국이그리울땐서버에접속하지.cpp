#include<iostream>
#include<string>
using namespace std;
bool visited[100];
int main(void){
    int n;
    cin>>n;
    string pattern;
    cin>>pattern;
    string leftp;
    string rightp;
    bool findstar=false;
    for(int i=0;i<pattern.length();i++){
        if(pattern[i]=='*'){
            findstar=true;
            continue;
        }
        if(!findstar){
            leftp = leftp + pattern[i];
        }
        else{
            rightp = rightp + pattern[i];
        }
    }
    //cout<<leftp<<rightp;
    for(int i=0;i<n;i++){
        string words;
        cin>>words;
        bool isright=true;
        for(int j=0;j<leftp.length();j++){
            if(leftp[j]!=words[j]){
                cout<<"NE\n";
                isright=false;
                break;
            }
            visited[j]=true;
        }
        if(isright){
            int index=words.length()-1;
            for(int j=rightp.length()-1;j>=0;j--){
                if(visited[index] || rightp[j]!=words[index]){
                    isright=false;
                    break;
                }
                index--;
            }
            if(isright){
                cout<<"DA\n";
            }
            else{
                cout<<"NE\n";
            }
        }
    }
    return 0;
}