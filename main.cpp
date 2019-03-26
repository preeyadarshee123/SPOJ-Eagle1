/*
// Author -> Preeyadarshee Dev
//
// train hard win easy :D
// nik is love
// nik is motivation
//
//
*/
//
#include <bits/stdc++.h>
#define mp                    make_pair
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define fr(i,a,b)   for(ll i=a;i<b;i++)
#define f(i,n)                fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n)                rf(i,n,0)
#define inf                  1000000007
#define eps         0.00000000000000001
#define endl                       '\n'

using namespace std;

int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
vector<pair<ll,ll>> adj[100010];
vector<ll> child(100010,-1);
vector<ll> dis(100010,0);
bitset<100010> vis;
ll dfs(ll a)
{
    vis[a]=1;
    ll maxi=-1;
    for(auto i:adj[a])
    {
        if(vis[i.ff]==0)
        {
            dis[i.ff]=dis[a]+i.ss;
            ll val=dfs(i.ff)+i.ss;
            if(maxi<val)
            {
                maxi=val;
                child[a]=i.ff;
            }
        }
    }
    return maxi;
}
void reset()
{
    for(int i=1;i<=100000;i++)
    {
        dis[i]=0;
        child[i]=-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        f(i,n-1)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            adj[a].pb(mp(b,c));
            adj[b].pb(mp(a,c));
        }
        dfs(1);
        ll a=1;
        while(child[a]!=-1)
        {
            a=child[a];
        }
        vis.reset();
        reset();
        dfs(a);
        vis.reset();
        ll temp=a;
        while(child[temp]!=-1)
        {
            vis[temp]=1;
            temp=child[temp];
        }
        ll res=a;
        queue<ll>q;
        while(res!=-1)
        {
            dis[res]=max(dis[res],dis[temp]-dis[res]);
            q.push(res);
            vis[res]=1;
            res=child[res];
        }
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            for(auto i:adj[v])
            {
                if(vis[i.ff]==0)
                {
                    dis[i.ff]=dis[v]+i.ss;
                    vis[i.ff]=1;
                    q.push(i.ff);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<endl;
        vis.reset();
        dis.assign(n+1,0);
        child.assign(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
    }
    
}
