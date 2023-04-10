#include <stdio.h>
typedef long long int LL;
int n;
LL max(int a,int b)
{
    LL max=a;
    if(b>a) max=b;
    return max;
}
LL C(int a,int b)//a>=b,求组合数
{
    if(b==0||a==b)return 1;
    LL res=1;
    for(int i=a,j=1; j<=b; i--,j++)
    {
        res=(res*i)/j;//这里有细节是先进行res*i这个运算，保证此运算可以整除
        if(res>n)
            return res;
    }
    return res;
}
int check(int k)//在第k斜行二分查找
{
    LL l,r,mid;
    l=2*k;//斜行第一个数都是C(2k,k)
    r=max(n,l);
    //右边界取n是因为一定存在C(n,2)=n此时在第二斜行，第二斜行有从1开始的所有整数
    //取max是保证在二分查找开始前使r>l;
    while(r>l)
    {
        int mid=(l+r)/2;
        if(C(mid,k)>=n) r=mid;
        else l=mid+1;
    }
    if(C(r,k)!=n)//假如找不到，就返回0
   {
       return 0;
   }
    else {
        printf("%lld",(r+1)*r/2+k+1);
        return 1;
    }
}
int main()
{
    scanf("%d",&n);
    //i取16是因为C(34,17)已经超过题目中n的范围
    for(int i=16; ; i--){
        if(check(i))
            break;}
    return 0;
}