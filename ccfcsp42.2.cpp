#include <iostream>
using namespace std;
//使用long long 防止10^18数据溢出
typedef long long ll;
/**
 * 检查当前入住 c个机器人时，苹果是否够吃m天
 * @param n 初始苹果数量
 * @param k 每日损耗比例
 * @param m 天数
 * @param c 机器人数
 */
 bool check(ll n, int k, int m, ll c) {
    for (int i = 0; i < m; i++) {
        //计算当前变质苹果数量（向上取整）
        ll bad = (n*k+99) / 100;
        n -= bad;
        n -= c;//机器人每天吃c个苹果
        if (n < 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//关闭同步流，提高输入输出效率
    ll n;
    int k, m;
   if(cin >> n >> k >> m) {
   ll l=0,r=n,ans=0;//l是左边界（left），r是右边界（right），ans是答案
   while(l<=r) {
   ll mid=(l+r)>>1;//>>二进制中右移一位相当于除以2
   if(check(n,k,m,mid)) {
ans=mid;
l=mid+1;//如果当前机器人数量可以满足需求，则继续增加机器人数量
}
else {
r=mid-1;//如果当前机器人数量不能满足需求，则减少机器人数量
}
}
cout << ans << "\n";
}
return 0;
}