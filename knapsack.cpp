// Recursive

int knapsack(int wt[], int val[], int w, int n){

  if (n==0 || w==0)
    return 0;

  else{

    if(wt[n-1]<=w){
      return max( (val[n-1] + knapsack(wt, val, w - wt[n-1], n-1) ) , knapsack(wt, val, w, n-1) )
    }
    else{
          knapsack(wt, val, w, n-1)
    }

  }
}

//Simple as that.

// DP table

// int dp[n+1][w+1];
int knapsack (int wt[], int val[], int w, int n){

  for(int i =0; i<=n; i++){
    for(int j=0; j<=w; j++){

      if (i==0 || j==0){
        dp[i][j] = 0;
      }

      else{
        if(wt[i-1]<=j){
          dp[i][j] = max( (val[i-1] + dp[i-1][j - wt[i-1]]) , dp[i-1][j]);
        }

        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }

  return dp[n][w];
  
}
