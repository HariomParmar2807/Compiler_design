// show the single line comment
#include<bits/stdc++.h>
using namespace std;
void find_comment(string &st){
    int count =0;
    for(int i=0; st[i]; i++){
        if(st[i] == '/' && st[i+1] == '/'){
            st  = st.substr(i);
            count ++;
            break;
        }else if(st[i] == '/' && st[i+1] == '*'){
            st = st.substr(i);
            count++;
            continue;
        }else if(st[i] == '*' && st[i+1] == '/'){
            st = st.substr(0,i+2);
            count ++;
            break;
        }
    }
    if(count>0)
    cout <<st<<"\n";
}
int main(){
while(1){
    string line;
    cout<<"Enter line=";
    getline(cin,line);
    find_comment(line);
}
    return 0;
}
