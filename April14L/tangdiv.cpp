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
    int t,n,k,p,i,j,flag,a,b;
    cin>>t;
    int x,y;
    while(t--)
    {
        cin>>n>>k>>p;
        pair<int,int> chef[1000];
        pair<int,int> child[1000];
        FOR(i,k)
        {
            cin>>x>>y;
            chef[i]=make_pair(x,y);
        }
        FOR(i,p)
        {
            cin>>x>>y;
            child[i]=make_pair(x,y);
        }
        //flag=0;
        FOR(i,k)
        {
            x=chef[i].first;
            y=chef[i].second;
            flag=0;
            FOR(j,p)
            {
                a=child[j].first;
                b=child[j].second;
               
                if(b>=a)
                {
                    if(y>=x)
                    {
                        if(x>=a && y<=b)
                        {
                            flag=1;
                            break;
                        }
                    }
                    
                }
                else
                {
                    if(y>=x)
                    {

                        if((x>=a && x<=n && y<=n)||(x>=1 && x<=b && y<=b))
                        {
                            flag=1;
                            break;

                        }
                    }
                    else
                    {
                        
                        if(x>=a && x<=n && y>=1 && y<=b)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }//inner for end...

            if(flag==0)
            {
                cout<<"No\n";
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
    }
    return 0;
}