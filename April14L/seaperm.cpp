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
    int t,n,i,j,k,x,temp;
    cin>>t;
    ll s;
    pair<int,int >p[2500];
    while(t--)
    {
        cin>>n>>k>>s;
    
        FOR(i,n)
        {
            cin>>x;
            p[i]=make_pair(x,i);
        }
        sort(p,p+n);
        FOR(i,n)
        cout<<p[i].second+1<<" ";    
       
        cout<<"\n";
        
    }
    return 0;
}