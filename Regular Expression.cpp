// a*/a*b* string selected
#include<bits/stdc++.h>
using namespace std;

int StringMatch(string str)
{
    int flag=0;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='a'){
            continue;}
        else if(str[i]=='b' && str[i+1]=='a'){
            i++;
            flag=1;
            break;
        }
        else if(str[i]!='a' && str[i]!='b'){
            flag=1;
            break;}
        }

}
int main()
{
    while(1){
    string str;
    cout<<"Enter string=";
    getline(cin,str);
    if(StringMatch(str)==1)
       cout<<"String Rejected\n";
    else
        cout<<"String Selected\n";
    }
    return 0;
}

