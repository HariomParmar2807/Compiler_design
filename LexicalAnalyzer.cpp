// Lexical Analyzer
#include<bits/stdc++.h>
using namespace std;

/*int Integer(int integers[])
{
    int Integer[] = {0,1,2,3,4,5,6,7,8,9};
	int i, flag = 0;
    for(int i=0;i<10;i++){
	for(int j = 0; j < 20; ++j){
		if(Integer[i] == integers[j]){
			flag = 1;
			break;
		}
	}
    }
	return flag;
}*/
int Keyword(char tokens[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], tokens) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main()
{
   char tokens[20];int j=0;
   char ch,Operators[]="+-*/%=";
   ifstream fin("Example.txt");
  	while(!fin.eof()){
   		ch = fin.get();
	for(int i = 0; i < 6; ++i){
   			if(ch == Operators[i])
   				cout<<ch<<" is operator\n";
   		}
     if(isalnum(ch))          // Alphanumric
     {
      tokens[j++]=ch;
     }
     else if((ch == ' ' || ch == '\n') && (j != 0)){
   				tokens[j] = '\0';
   				j = 0;

   				if(Keyword(tokens) == 1)
   					cout<<tokens<<" is keyword\n";
   					//else if(Integer(integers) == 1)
   				//	cout<<integers<<" is integer\n";
                else
                    cout<<tokens<<" is identifier"<<endl;
   		}

}
fin.close();
return 0;
}
