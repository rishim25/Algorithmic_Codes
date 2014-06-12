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

long long power(long long a, long long n)//////O(log n)
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

long long gcd(long long a, long long b)////O(log(a+b))
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

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        ll i,n,c=0,c2=0;
        cin>>n;
        ll a;
        FOR(i,n)
        {
            cin>>a;
            if(a==2)
                c2++;
            if(a==1 || a==0)
                continue;
            c++;
        }
        ll ans1=c2*(c2-1)/2;
        ll ans=c*(c-1)/2;
        cout<<ans-ans1<<"\n";
    }
    return 0;
}