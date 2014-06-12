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
int a[100005][12];
int ans[100005];
int main() 
{
    int i,n,m,j;
    cin>>n>>m;
    ll x,y,sump=0,sumn=0,temp;
    ans[0]=0;
    string s;
    cin>>s;
    memset(a,0,sizeof a);
    a[0][s[0]-'0']=1;
    for(i=1;i<n;i++)
    {   
        temp=s[i]-'0';
        FOR(j,10)
        {
            if(temp==j)
                a[i][j]=a[i-1][j]+1;
            else
                a[i][j]=a[i-1][j];
        }
    }
    
    for(i=1;i<n;i++)
    {
        temp=s[i]-'0';
        sump=sumn=0;
        FOR(j,10)
        {
            if(a[i][j]>0 && temp>j && j!=temp)
            {
                sump+=(temp-j)*a[i][j];
                
            }
            else if(a[i][j]>0 && temp<j && j!=temp)
            {
                sumn+=(temp-j)*a[i][j];
                
            }
        }
        ans[i]=sump-sumn;

    }
   
    
    while(m--)
    {
        cin>>x;
        x--;
        cout<<ans[x]<<"\n";
    }

    return 0;
}