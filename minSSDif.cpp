#include<bits/stdc++.h>

using namespace std;

int minSSD(int arr[], int sum, int n){
  int i; int j;
  int **dp = new int*[n+1];
  for(i=0; i<n+1; i++){
    dp[i] = new int[sum+1];
  }

  int *v= new int[sum+1];

  for(i =0; i<=n; i++)
  {
    for( j=0; j<=sum; j++)
    {

      if (i==0  || j==0)
      {

        if(i==0){
        dp[i][j] = 0;
        }

        if (j==0){
          dp[i][j] = 1;
        }

      }

      else
      {

        if(arr[i-1]<=j)
        {
          dp[i][j] = int(dp[i-1][j] || dp[i-1][j-arr[i-1]]);
        }

        else
        {
          dp[i][j] = dp[i-1][j];
        }

      }
    }

    if(i == n)
    {

      for( j=0; j<=sum; j++)
      {
        v[j] = dp[i][j];
      }

    }

  }

  int s;

  for( i = sum; i>=0; i--)
  {
    if(v[i]==1)
    {
      s = i;
      break;
    }
  }

  return s;

}

int main()
{

  int arr[5];
  int r = 0;
  for(int i=0; i<5; i++){
    cin>>arr[i];
    r = r+arr[i];

  }

  int half = r/2;

  int s1 = minSSD(arr, half, 5);

  cout<<"\n"<<r - 2*s1<<"\n";

  return 0;

}
