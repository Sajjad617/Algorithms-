#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int vt[1005];
int level[1005];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vt[s] = true;
    level[s] = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(auto child : v[p])
        {
            if(!vt[child])
            {
                q.push(child);
                vt[child] = true;
                level[child] = level[p]+1;
            }
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


    int t;
    cin >> t;
    while(t--)
    {
        memset(vt, false, sizeof(vt));
        memset(level, -1, sizeof(level));
        int s, d;
        cin >> s >> d;
        bfs(s);
        cout << level[d] << endl;
    }
    return 0;
}