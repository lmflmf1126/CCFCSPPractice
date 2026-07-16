#include <iostream>
using namespace std;
const int N=105;
int a[N],b[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d.%d",a+i,b+i);//==> &a[i] &b[i]
    }
    //四舍五入法
for(int i=1;i<=n;i++)
//bool值真为1，假为0
{int res=a[i]+(b[i]>=5);
printf("%d",res);
if(i<n) printf(" ");
}
printf("\n");
//银行家舍入法
for(int i=1;i<=n;i++)
//奇数二进制最后一位为1，偶数二进制最后一位为0
{int res=a[i]+(b[i]>5)+((a[i]&1)&&(b[i]==5));
printf("%d",res);
if(i<n) printf(" ");
}
printf("\n");
return 0;
}