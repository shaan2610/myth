#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define f(i,n)          for(int i=0;i<n;i++)
#define fr(i,a,b)       for(int i=a;i<=b;i++)
#define P               cout<<
#define I               cin>>
#define pb              push_back
#define mp              make_pair
#define ppb             pop_back()
#define L               length()
#define endl            "\n"
#define vii             vector<pair<int,int> >
#define pii             pair<int,int>
#define vi              vector<int>
#define sd(arr,n)       sort(arr,arr+n,greater<int>())
#define si(arr,n)       sort(arr,arr+n)
#define Si(v)           sort(v.begin(),v.end())
#define Sd(v)           sort(v.begin(), v.end(),sdf)
#define s2i(v)          sort(v.begin(),v.end(),sbs)
#define s2d(v)          sort(v.begin(),v.end(),sbds)
#define desc            greater<int>
#define eif             else if 
#define int             long long int
#define F               first
#define S               second
#define fk              1000000007
#define fk1             998244353
#define pie             3.14159265358979323846
#define dec(x)          fixed<<setprecision(x)
#define sz              size()
#define mi              map<int,int>
#define bs(a,n,x)       binary_search(a,a+n,x)
#define MX(a,n)         *(max_element(a,a+n))
#define MN(a,n)         *(min_element(a,a+n))
#define in(n)           int n;I n
#define inp(a,n)        int a[n];f(xxx,n) I a[xxx]
#define mem(a)          memset(a, -1, sizeof(a))
#define all(v)          v.begin(), v.end()
#define ub(v,x)         std::upper_bound(all(v), x)     //first value greater than x
#define lb(v,x)         std::lower_bound(all(v), x)     //first value greater than or equal to x
#define boost           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TLE             cerr<<endl<<"Time Elasped : "<<1.0 * clock() / CLOCKS_PER_SEC<<endl;
//int fac[MAXN];
//void fact(int x){ fac[0] = 1; fr(i,1,MAXN) fac[i] = fac[i-1]*i%x; }
int invmod(int x, int n, int mod){ if(n==0)  return 1%mod; int half = invmod(x,n/2,mod);half = (half*half)%mod; if(n%2==1)  half = (half*(x%mod))%mod; return half;}
int bin(int a[],int l,int r,int x){ if(l<=r){ int m=l+(r-l)/2; if(a[m]==x) return m; else if (a[m]>x) return bin(a,l,m-1,x); else return bin(a,m+1,r,x);} else return -1;}
int power(int b,int e,int m){ if(e==0) return 1; if(e%2) return b*power(b*b%m,(e-1)/2,m)%m; else return power(b*b%m,e/2,m);}
int power(int b,int e){ if(e==0) return 1; if(e%2) return b*power(b*b,(e-1)/2); else return power(b*b,e/2);}
int ncr(int n, int r, int x) { if (r==0) return 1; int fac[n+1]; fac[0] = 1; fr(i,1,n) fac[i] = fac[i-1]*i%x; return (fac[n]* power(fac[r], x-2, x) % x * power(fac[n-r], x-2, x) % x) % x; }
int ncr(int n,int p){ int r=min(p,n-p),rf=1,ln=1; fr(i,1,r) rf=rf*i; f(i,r) ln=ln*(n-i); return ln/rf;}
bool sbs(pii &a,pii &b){ return (a.S<b.S);}
bool sbds(pii &a,pii &b){ return (a.S>b.S);}
bool sdf(pii &a,pii &b){ return (a.first > b.first); }
int SUM(int a[],int n){ int sum=0; f(i,n) sum+=a[i]; return sum;}
int chkprm(int n){ int x=5,s=sqrt(n); if(n<2)return 0; if(n<4)return 1; if((n&1)==0)return 0; if(n%3==0)return 0; while(x<=s){ if(n%x==0)return 0; x+=2; if(n%x==0)return 0; x+=4; } return 1;}
//vi adj[MAXT];           //*****TREE MOVES*****
//int dep[MAXT],vis[MAXT],dad[MAXT],intime[MAXT],extime[MAXT],timer=0;
//void dfs_cal(int i){ dad[1]=1; intime[i]=timer++; for(auto j: adj[i]){ if(j!=dad[i]){ dad[j]=i;dep[j]=dep[i]+1;dfs_cal(j);}} extime[i]=timer++;}
//int prm[MAXS];                     //****SIEVE MOVES****
//void sieve(){ f(i,MAXS) prm[i]=i; for(int i=4;i<MAXS;i+=2) prm[i]=2; for(int i=3;i<sqrt(MAXS);i+=2){ if(prm[i]==i){ for(int j=i*i;j<MAXS;j+=i) prm[j]=i; }}}
#define MAXT 100005
vi adj1[MAXT],adj2[MAXT],vis(MAXT),ord,comp;//adj2 is reverse adjacency matrix
void dfs1(int x)//Reverse of ord gives topological order
{
	vis[x]=1;
	for(auto i:adj1[x])
		if(!vis[i])
			dfs1(i);
	ord.pb(x);
}
void dfs2(int x)
{
	vis[x]=1;
	comp.pb(x);
	for(auto i:adj2[x])
		if(!vis[i])
			dfs2(i);
}
void myth()
{
                //*******TREE MAI GLOBAL AUR LOCAL VARIABLE KA DHYAN RKHNA*******
    in(n);
    in(m);
    f(i,m)
    {
    	in(u);
    	in(v);
    	adj1[u].pb(v);
    	adj2[v].pb(u);
    }
    fr(i,1,n)
    	if(!vis[i])
    		dfs1(i);
    fr(i,1,n)
    	vis[i]=0;
    f(i,n)
    	if(!vis[ord[n-i-1]])
    	{
    		dfs2(ord[n-i-1]);
    		for(auto i:comp)
    			P i<<" ";
    		P endl;
    		comp.clear();
    	}
}
signed main()
{
    boost
    int test_case=1;
    //I test_case;
    while(test_case--)
    {
        myth();
        P endl;
    }
    TLE
    return 0;
}