#include<iostream>
using namespace std;
const int DATMAX=600001;
char dat[DATMAX];
int prv[DATMAX],nxt[DATMAX];
int unused=1;
void insert(int addr,char c){
    dat[unused]=c;
    prv[unused]=addr;
    nxt[unused]=nxt[addr];
    if(nxt[addr]!=-1){
        prv[nxt[addr]]=unused;
    }
    nxt[addr]=unused;
    unused++;
}
void erase(int addr){
    nxt[prv[addr]]=nxt[addr];
    if(nxt[addr] != -1){
        prv[nxt[addr]]=prv[addr];
    }
}
void traversal(){
    int cur=nxt[0];
    while(cur!=-1){
        cout<<dat[cur];
        cur=nxt[cur];
    }
}
int main(void){
    fill(dat,dat+DATMAX,-1);
    fill(prv,prv+DATMAX,-1);
    fill(nxt,nxt+DATMAX,-1);
    string s;
    cin>>s;
    int cursor=0;
    int len=s.size();
    for(int i=0;i<len;i++){
        insert(cursor,s[i]);
        cursor++;
    }
    int order;
    cin>>order;
    for(int t=0;t<order;t++){
        char c;
        cin>>c;
        if(c=='P'){
            char tmp;
            cin>>tmp;
            insert(cursor,tmp);
            cursor=nxt[cursor];
        }
        else if(c=='L'){
            if(prv[cursor]!=-1){
                cursor=prv[cursor];
            }
        }
        else if(c=='D'){
            if(nxt[cursor]!=-1){
                cursor=nxt[cursor];
            }
        }
        else if(c=='B'){
            if(prv[cursor]!=-1){
                erase(cursor);
                cursor=prv[cursor];
            }
        }
    }
    traversal();
    return 0;
}