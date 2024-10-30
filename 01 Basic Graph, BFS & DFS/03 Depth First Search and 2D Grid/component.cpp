#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vt[N];

void dfs(int src)
{
    cout << src << " ";
    vt[src] = true;
    for(auto child : v[src])
    {
        if(!vt[child])
            dfs(child);
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
    int c =0;
    for(int i=0; i<n; i++)
    {
        if(vt[i]==false)
        {
            dfs(i);
            c++;
        }
    }
    cout << "Component - " << c << endl;
    return 0;
}


/*
6 5
0 1
1 2
0 2
3 4
3 5
*/