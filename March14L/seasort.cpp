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

void revrs(int a[],int lptr,int rptr)
{
    int i,j,temp;
    for(i=lptr,j=rptr;i<=j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    
}

int main() 
{
    
    int n,i,j,k,lptr,rptr;
    cin>>n;
    int a[n+5];
    vector<int> l;vector<int> r;
    FOR(i,n)
    cin>>a[i];
    int minm,index;
    FOR(i,n)
    {
        minm=a[i];index=i;
        for(j=i+1;j<n;j++)
        {
            if(minm>a[j])
            {
                minm=a[j];
                index=j;
            }    
        }
        if(i!=index)
        {

        l.pb(i+1);
        // cout<<a[i]<<" "<<a[index]<<"\n";
        r.pb(index+1);
        revrs(a,i,index);
    }
    }
    cout<<l.size()<<"\n";
    FOR(i,l.size())
    cout<<l[i]<<" "<<r[i]<<"\n";
    return 0;
}