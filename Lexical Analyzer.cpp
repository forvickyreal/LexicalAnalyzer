#include <iostream> 
#include<string> 
#include<iostream> 
using namespace std; 
string key[15]={" ","if","do","stop","end","int","bool","float","double","main"}; 
string sym[8]={"=","+","-","*","**",",","(",")"}; 
string mnemonic[14]={"#DIM","#IF","#DO","#STOP","#END","#ID","#INT","#ASSIGN","#PLUS"," #STAR","#POWER","#COMMA","#LPAR","#RPAR"}; 
string identifier[100]; 
string numtable[100]; 
char lexeme; 
string token,text="int main()\n{\n int num=566;\n do{\nif (a>3) \nnum=a**2; \n if(a<3) a=num-4; \nstop;\n}"; 
int pText=0,idnum=0,pos = 0,num=0; 
int Findsym(string str) 
{ 
for(int i=0;i<=8;i++) 
{
if(str==sym[i]) return i+8; 
}
return -1; 
}
void GetChar() 
{ 
lexeme=text[pText]; 
pText++; 
}
void getbe() 
{ 
while(true) 
{
if(lexeme==' '||lexeme=='\n'|| lexeme=='\t')//eliminate spaces 
GetChar(); 
else break; 
} 
}
void Concat() 
{ 
token+=lexeme; 
}
bool IsLetter() 
{ 
if( (lexeme>='a' &&lexeme<='z') ||( lexeme>='A' &&lexeme<='Z'))return true; 
else return false; 
}
bool IsDigit() 
{ 
if( lexeme>='0' &&lexeme<='9') 
return true; 
else return false; 
}
int Reserve() 
{ 
for(int i=0;i<=10;i++) 
{
if(token==key[i]){ 
if(i>4)return 1; 
else return i+1; 
} 
}
return -1; 
}
void Retract() 
{ 
lexeme=' '; 
pText--; 
}
void error(){ 
cout<<"Invalid Character: "<<lexeme<<endl; 
}
void buildlist(){ 
char temp =token[0]-'0'; 
if (temp >= 0 && temp <= 9){ 
int i; 
for (i = 0; i < num; i++) { 
if (token == numtable[i]) { 
pos = i; 
break; 
} 
}
if (i == num) { 
numtable[num] = token; 
pos = num; 
num++; 
} 
}
else{ 
int i; 
for (i = 0; i < idnum; i++) {if (token == identifier[i]&& token!=key[i]){ 
pos=i; 
break; 
}
}
if(i==idnum){ 
identifier[idnum]=token; 
pos = idnum; 
idnum++; 
} 
} 
}
void LexicalAnalyzer() 
{ 
int c; 
token=""; 
GetChar(); 
getbe(); 
if(IsLetter()) 
{ 
while(IsLetter() || IsDigit()) 
{ 
Concat(); 
GetChar(); 
}
Retract(); 
c=Reserve(); 
if(c==-1) 
{ 
buildlist(); 
cout<<"("<<6<<","<<identifier[pos]<<","<<mnemonic[5]<<")"<<endl; 
} 
else cout<<"("<<c<<","<<token<<","<<mnemonic[c-1]<<")"<<endl; 
}
else if(IsDigit()) 
{ 
while(IsDigit()) 
{ 
Concat(); 
GetChar(); 
}
Retract(); 
buildlist(); 
cout<<"("<<7<<","<<numtable[pos]<<","<<mnemonic[6]<<")"<<endl; 
} 
else if(lexeme=='=') cout<<"(8,=,"<<mnemonic[7]<<")"<<endl; 
else if(lexeme=='+') cout<<"(9,+,"<<mnemonic[8]<<")"<<endl; 
else if(lexeme=='*'){ 
Concat(); 
GetChar(); 
int c; 
if(lexeme=='*') 
{ 
Concat(); 
c=Findsym(token); 
cout<<"("<<c<<","<<token<<","<<mnemonic[c-2]<<")"<<endl; 
}
else 
{ 
c=Findsym(token); 
cout<<"("<<c<<","<<token<<","<<mnemonic[c-2]<<")"<<endl; 
Retract(); 
} 
}
else if(lexeme==',') cout<<"(12,,,"<<mnemonic[11]<<")"<<endl; 
else if(lexeme=='(') cout<<"(13,(,"<<mnemonic[12]<<")"<<endl; 
else if(lexeme==')') cout<<"(14,),"<<mnemonic[13]<<")"<<endl; 
else if(lexeme=='#'); 
else error(); 
} 
