#include "main.h"
#include <limits.h>
int _atoi(char *s){
int i=0,sign=1,started=0,res=0,d;
while(s[i]){
if(!started){
if(s[i]=='-')sign*=-1;
else if(s[i]=='+'){}
else if(s[i]>='0'&&s[i]<='9')started=1;
}
if(started){
if(s[i]>='0'&&s[i]<='9'){
d=s[i]-'0';
if(sign==1){
if(res>INT_MAX/10||(res==INT_MAX/10&&d>INT_MAX%10))return INT_MAX;
res=res*10+d;
}else{
if(res< (INT_MIN+d)/10)return INT_MIN;
res=res*10-d;
}
}else if(res!=0|| (sign==-1&&started))break;
}
i++;
}
if(!started)return 0;
if(sign==1)return res>=0?res:INT_MAX;
return res;
}
