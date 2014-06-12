#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

using namespace std;



class FastInput {
        public:
                FastInput() {
                        m_dataOffset = 0;
                        m_dataSize = 0;
                        m_v = 0x80000000;
                }
                uint32_t readNext() {
                        if (m_dataOffset == m_dataSize) {
                                int r = read(0, m_buffer, sizeof(m_buffer));
                                if (r <= 0) return m_v;
                                m_dataOffset = 0;
                                m_dataSize = 0;
                                int i = 0;
                                if (m_buffer[0] < '0') {
                                        if (m_v != 0x80000000) {
                                                m_data[m_dataSize++] = m_v;
                                                m_v = 0x80000000;
                                        }
                                        for (; (i < r) && (m_buffer[i] < '0'); ++i);
                                }
                                for (; i < r;) {
                                        if (m_buffer[i] >= '0') {
                                                m_v = m_v * 10 + m_buffer[i] - 48;
                                                ++i;
                                        } else {
                                                m_data[m_dataSize++] = m_v;
                                                m_v = 0x80000000;
                                                for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                                        }
                                }
                        }
                        return m_data[m_dataOffset++];
                }
        public:
                uint8_t m_buffer[32768];
                uint32_t m_data[16384];
                size_t m_dataOffset, m_dataSize;
                uint32_t m_v;
};

class FastOutput {
        public:
                FastOutput() {
                        m_dataOffset = 0;
                }
                ~FastOutput() {
                }
                void Flush() {
                        if (m_dataOffset) {
                                if (write(1, m_data, m_dataOffset));
                                m_dataOffset = 0;
                        }
                }
                void Printline(uint32_t v, char d) {
                        if (m_dataOffset + 11 > sizeof(m_data)) Flush();
                        if (v < 100000) {
                                if (v < 1000) {
                                        if (v < 10) {
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 1;
                                        } else if (v < 100) {
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 2;
                                        } else {
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 3;
                                        }
                                } else {
                                        if (v < 10000) {
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 4;
                                        } else {
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 5;        
                                        }        
                                }
                        } else {
                                if (v < 100000000) {
                                        if (v < 1000000) {
                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 6;
                                        } else if (v < 10000000) {
                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 7;
                                        } else {
                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 8;        
                                        }
                                } else {
                                        if (v < 1000000000) {
                                                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 9;
                                        } else {
                                                m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                
                                                m_data[m_dataOffset + 0] = v + 48;
                                                
                                                m_dataOffset += 10;        
                                        }        
                                }
                        }
                        
                        m_data[m_dataOffset++] = d;
                }
                
                void PrintChar(char d) {
                        if (m_dataOffset + 1 > sizeof(m_data))
                                Flush();
                        m_data[m_dataOffset++] = d;
                }
                 
                
                void ReplaceChar(int offset, char d) {
                        m_data[m_dataOffset + offset] = d;
                }
                
        public:
                uint8_t m_data[32768];                
                size_t m_dataOffset;
                
};
 
 
 
FastInput in;
 
FastOutput out;

#define FOR(i,n) for(i=0;i<n;i++)
#define pb(x) push_back(x)
#define ll long long
#define mod 1000000

ll mulmod(ll a, ll b)
 {
    ll res = 0;
    while (a != 0) {
        if (a & 1) res = (res + b) % mod;
        a >>= 1;
        b = (b << 1) % mod;
    }
    return res;
}
int hash[1000005];
ll str[3000005];
ll temp=0,temp1,temp2;
void sorting(int n)
{
    int i,j;
    temp1=0,temp2=0;
    int cnt=0;
    FOR(i,1000005)
    {
        if(hash[i]>0)
        FOR(j,hash[i])
        {
             if(cnt%2==0)
                temp1+=i;
            else
                temp2+=i;
            cnt++;
        }
    }
    ll ans;
        if(temp1>temp2)
            ans=temp1-temp2;
        else
            ans=temp2-temp1;
      out.Printline(ans,'\n');
out.Flush();
}
////////////////////////////////////////////////////////////////////////////////////CODE BEGINS/////////////////////////////////////////////////////////

int main() {
    int t,i;
    t=in.readNext();
    while(t--)
    {
        ll n,a,b,c,d;
        n=in.readNext();
        a=in.readNext();
        b=in.readNext();
        c=in.readNext();
        d=in.readNext();
        str[0]=d;
        memset(hash,0,sizeof hash);
         hash[d]++;
        for(i=1;i<n;i++)
        {
            temp=str[i-1]*str[i-1];
            temp1=temp*a;
            temp2=str[i-1]*b;
            str[i]=((temp1)+(temp2)+(c))%mod;
             hash[str[i]]++;
        }
        sorting(n);
    }
    return 0;
}