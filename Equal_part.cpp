bool equalPart(int arr[], int n){

  int sum = 0;
   for (int i =0; i<n; i++){
     sum = sum + arr[i];
   }

   if (sum%2!=0){
     return false;
   }

   else{

     sum = sum/2;

     for(int i=0; i<= n; i++){
       for(int j=0; j<= sum; j++){

         if (i ==0 || j==0){

           if(i==0){ //If no elements provided
             dp[i][j] = 0;
           }

           if (j==0){
             dp[i][j] = 1;
           }

         }

         else{
           if(arr[i-1]<=j){

             dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
           }

           else{

             dp[i][j] = dp[i-1][j];
           }
         }

       }
     }

     return dp[n][sum];

   }

}
