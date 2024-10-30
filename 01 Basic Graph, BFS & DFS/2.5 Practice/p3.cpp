#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> v[1005];
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x;
    cin >> x;
    cout << v[x].size(); 
    return 0;
}