#include "main.h"
#include <limits.h>
int _atoi(char *s){
int i=0,sign=1,res=0,d,start=0;
while(s[i]){
if(!start){
if(s[i]=='-')sign*=-1;
else if(s[i]=='+'){}
else if(s[i]>='0'&&s[i]<='9')start=1;
}
if(start){
if(s[i]>='0'&&s[i]<='9'){
d=s[i]-'0';
if(sign==1){
if(res>INT_MAX/10||(res==INT_MAX/10&&d>INT_MAX%10))return INT_MAX;
res=res*10+d;
}else{
if(res<(INT_MIN+d)/10)return INT_MIN;
res=res*10-d;
}
}else break;
}
i++;
}
if(!start)return 0;
return res;
}
