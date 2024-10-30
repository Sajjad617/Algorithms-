#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vt[N];
int cnt=0;
void dfs(int src)
{
    cnt++;
    vt[src] = true;
    for(auto child : v[src])
    {
        if(vt[child]==false)
        {
            dfs(child);
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vt, false, sizeof(vt));
    vector<int> nonec;
    for(int i=0; i<n; i++)
    {
        if(vt[i]==false)
        {
            cnt=0;
            dfs(i);
            nonec.push_back(cnt);
        }
    }
    sort(nonec.begin(), nonec.end());
    for(int x : nonec)
    {
        cout << x << " ";
    }
    // nonec.sort();
    // cout << cnt;
    return 0;
}