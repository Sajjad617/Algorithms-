#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);

    }
    for(int i=0;i<mat[1].size(); i++)
    {
        cout << mat[1][i] << " ";
    }
    return 0;
}