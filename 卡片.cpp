#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int sum=0,i,b;
  for(i=1;;i++){
    for(b=i;b>0;b/=10){
      if(i%10==1){
        sum++;
      }
      if(sum==2021) goto end;
    }
  }
  end:printf("%d",i);
  return 0;
}