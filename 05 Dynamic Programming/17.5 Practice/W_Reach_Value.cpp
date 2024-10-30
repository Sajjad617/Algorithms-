#include<bits/stdc++.h>
using namespace std;
bool flag = false;
int f = 1;
void find_value(long long int n, long long int op1)
{
    // int op1=1;
    // int op2=1;
    if(op1==n)
    {
        flag = true;
        return;
    }
    else if(op1>n)
        return;

    if(op1<=n)
    {
        find_value(n, op1*10);
        find_value(n, op1*20);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        flag = false;
        long long int n;
        cin >> n;

        long long int op1=1;
        find_value(n, op1);

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
    return 0;
}