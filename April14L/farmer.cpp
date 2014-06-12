/*
Author :  ARVIND PANDEY
 */
#include <bits/stdc++.h>
using namespace std;

struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;

#define FOR(i,n) for(i=0;i<n;i++)
#define pb(x) push_back(x)
#define ll long long

long long power(long long a, long long n)//////             O(log n)
{
    long long ans = 1;
    while (n) {
        if (n % 2 == 1)
            ans *= a;
        a *= a;
        n /= 2;
    }
    return ans;
}

long long gcd(long long a, long long b)////                 O(log(a+b))
{
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
////////////////////////////////////////////////////////////////////////////////////CODE BEGINS/////////////////////////////////////////////////////////
bool prime[3000];
void seive()
{
    int i,d;
    for(i=2;i<3000;i++)
    {
        d=2;
        while(d*i<3000)
        {
            prime[d*i]=false;
            d++;
        }
    }
}

int main() 
{
    int t,x,y,i;

    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    seive();
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
            for(i=x+y+1;i<3000;i++)
                if(prime[i])
                {
                    cout<<i-(x+y)<<"\n";
                    break;
                }    
        
    }

    return 0;
}