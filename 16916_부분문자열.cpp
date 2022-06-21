#include<iostream>
#include<string>
#include<vector>
using namespace std;
string book;
string pattern;
vector<int> failure;
void makefailure(){
    failure.assign(pattern.length(),0);
    int i=1;
    int j=0;
    int patternlen=pattern.length();
    while(i<patternlen){
        if(pattern[i]==pattern[j]){
            failure[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=failure[j-1];
        }
        else{
            failure[j]=0;
            i++;
        }
    }
}
int main(void){
    cin>>book>>pattern;
    makefailure();
    int i=0;
    int j=0;
    int booklen=book.length();
    int patternlen=pattern.length();
    bool check=false;
    while(i<booklen){
        if(book[i]==pattern[j]){
            if(j==patternlen-1){
                cout<<"1";
                check=true;
                break;
            }
            else{
                i++;
                j++;
            }
        }
        else if(j>0){
            j=failure[j-1];
        }
        else{
            i++;
        }
    }
    if(!check){
        cout<<"0";
    }
    return 0;
}