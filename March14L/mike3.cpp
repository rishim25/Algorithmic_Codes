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

int check(int h[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(h[i]!=1)
            return 0;
    }
    return 1;
}

int main() 
{
    int n,m,i,j,x,k;
    cin>>n>>m;
    int a[m+5][20005];
    memset(a,0,sizeof a);
    int b[m+5][m+5];
    for(i=1;i<=m;i++)
    {
        cin>>a[i][0];
        FOR(j,a[i][0])
        {
            cin>>x;
            a[i][x]=1;
        }
    }
    memset(b,0,sizeof b);int cnt=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i!=j)
            for(k=1;k<=n;k++)
            {
                
                if(a[j][k]==1 && a[i][k]==1)
                {
                    cnt=1;
                    break;
                }    
                    
                
            }
            if(cnt==0)
                b[i][j]=1;
            cnt=0;
        }
    }
    
    
    ll pow_set_size = pow(2, m);
    ll counter;
 
    int set[25];
    FOR(i,m)
    set[i]=i+1;
    int maxm=0;
    vector<int> v;
    int flag=0;
    ///////////////http://www.geeksforgeeks.org/power-set/////////////////////
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < m; j++)
       {
           if(counter & (1<<j))
            {
                
                flag=0;
                
                for(k=0;k<v.size();k++)
                {
                    if(b[set[j]][v[k]]!=1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    v.pb(set[j]);
            }

       }
      
       
       if(maxm<v.size())
        maxm=v.size();
    v.clear();
       
    }

    cout<<maxm<<"\n";

    return 0;
}