
#include<bits/stdc++.h> 
using namespace std; 

int dp[1005][100005];
bool checkSum(int n, int sum, int arr[]){
    if(n==0){
        if(sum==0) return true;
        else return false;
    }
    // if(sum==0) return true;
    if(dp[n][sum]!=-1) return dp[n][sum];
    // cout << arr[n-1] << "<->"<< sum << "<->"<< n << endl;
    if(arr[n-1] <= sum){
        // cout << "###" << endl;
        bool pick = checkSum(n-1,sum-arr[n-1],arr);
        bool noPick = checkSum(n-1,sum,arr);
        return dp[n][sum] = pick || noPick;
    }
    else{
        // cout << "***" << endl;
        bool noPick = checkSum(n-1,sum,arr);
        return dp[n][sum] = noPick;
    }
    
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N >> sum;
        int arr[N];
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        if(sum==1000)
        {
            cout << "YES" << endl;
        } 
        else if(sum>1000)
        {
            cout << "NO" << endl;
        }
        else
        {
            sum = 1000-sum;
            dp[0][0] = true;
            for(int i=1; i<=sum; i++)
            {
                dp[0][i] = false;
            }

            for(int i=1; i<=N; i++)
            {
                for(int j=0; j<=sum; j++)
                {
                    if(arr[i-1] <= j)
                    {
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            if(dp[N][sum])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0; 
} 

// } Driver Code Ends
