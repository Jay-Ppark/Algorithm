#include<iostream>
#include<map>
using namespace std;
int main(void){
    map<string,int> m;
    m["hi"]=123;
    m["bird"]=1000;
    m["gogo"]=165; //{"bird",1000},{"gogo",165},{"hi",123}
    cout<<m.size()<<'\n'; //3
    m["hi"]=-7; //{"bird",1000},{"gogo",165},{"hi",-7}
    if(m.find("hi")!=m.end()){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
    m.erase("bird");//{"gogo",165},{"hi",-7}
    for(auto e:m){
        cout<<e.first<<' '<<e.second<<'\n'; //gogo 165
                                            //hi -7
    }
    auto it1 = m.find("gogo");
    cout<<it1->first<<' '<<it1->second<<'\n';// gogo 165
    return 0;
}