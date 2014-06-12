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

int calc(int x)
{
    int h=0;
    while(x!=1)
    {
        x=x/2;
        h++;
    }
    return h;
}

int main() 
{
    int n,x,y,hx,hy,temp,maxx,minn,a,b,ans,flag;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        hx=calc(x);
        hy=calc(y);
        if(hx>=hy)
        {
            maxx=hx;
            a=x;b=y;
            minn=hy;
        }    
        else
        {
            minn=hx;a=y;b=x;
            maxx=hy;
        }    
        temp=maxx-minn;
        ans=0,flag=0;
        if(x==y)
            cout<<"0\n";
        else if(a==1 || b==1)
            cout<<temp<<"\n";
        else
        {
            while(temp>0)
                {
                    a=a/2;temp--;ans++;}
            while(a!=1 && b!=1)
            {
                if(a==b)
                {
                    flag=1;
                    break;
                }
                a/=2;
                b/=2;
                ans+=2;
            }
            if(flag)
                cout<<ans<<"\n";
            else
            {
                while(a!=1)
                {
                    a/=2;ans++;
                }
                while(b!=1)
                {
                    b/=2;
                    ans++;
                }
                cout<<ans<<"\n";
            }
        }
    }
    
    return 0;
}