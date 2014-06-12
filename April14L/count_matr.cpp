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

int main() 
{
    int t,n,a,b,c,temp;
    cin>>t;
    ll cnt,ans;
    while(t--)
    {
        cin>>n;
        ans=0;
    
            for(a=1;a<=n/2;a++)
            {
                temp=a*(n-a);
                
                for(c=1;c<sqrt(temp);c++)
                {
                    if(temp%c==0)
                        cnt=(temp-1)/c;
                    else
                       cnt=temp/c;
                    
                
                    ans=ans+(cnt-c)*2+1;
                    if(a!=n-a)
                    ans=ans+(cnt-c)*2+1;
                
                }

                    
                
            }
            

            cout<<ans<<"\n";
            
            
        
    }
    return 0;
}