#include<bits/stdc++.h>
using namespace std;

int coin(int n , int T , vector<int>& arr){

    if(n==0){
        if(T% arr[0]==0){
            return 1;
            }
         return 0;
    }

    int not_pick = coin(n-1,T , arr);
    int pick =0;
    if(arr[n]<=T){
        pick= coin(n, T-arr[n], arr);
    }

    return not_pick +pick;
}

int main(){
    vector<int> arr={  2,3  };

    int target= 4;
    int ans= coin (arr.size()-1, target , arr);
    cout<<ans<<endl;

}





















// #include<bits/stdc++.h>
// using namespace std;

// int coin(int n , int T , vector<int>& arr, vector<vector<int>>&  dp){

//     if(n==0){
//         return (T% arr[0]==0); 
//     }


//     if(dp[n][T]!=-1)
//     return dp[n][T];

//     int not_pick = coin(n-1,T , arr, dp);
//     int pick =0;
//     if(arr[n]<=T){
//         pick= coin(n, T-arr[n], arr  , dp);
//     }

//     return dp[n][T] =  not_pick +pick;
// }

// int main(){
//     vector<int> arr={ 1, 2,3 };

//     int n = arr.size();
//       int target= 4;

//     vector<vector<int>> dp(n, vector<int> (target+1,-1));

  
//     int ans= coin (arr.size()-1, target , arr , dp);
//     cout<<ans<<endl;

// }
















#include<bits/stdc++.h>
using namespace std;

int coin(int T , vector<int>& arr){
    int n= arr.size();
   vector<vector<int>> dp(n, vector<int> (T+1,0));

    for(int i=0; i<=T ; i++){
        if(i%arr[0]==0)
        dp[0][i]=1;
    }

    for(int ind=  1 ; ind<n;ind++){
        for(int t=0;t<=T; t++){

            int not_pick = dp[ind-1][t];

            int pick =0;
            if(arr[ind]<=t){
                pick= dp[ind][t-arr[ind]];
            }

            dp[ind][t] =  not_pick +pick;

        }
    }
    return  dp[n-1][T];

    
}

int main(){
    vector<int> arr={ 1, 2,3 };

    int n = arr.size();
      int target= 4;
  
    int ans= coin (target , arr );
    cout<<ans<<endl;

}














// #include<bits/stdc++.h>
// using namespace std;

// int coin(int T , vector<int>& arr){
//     int n= arr.size();
//    vector<int> prev(T+1,0);


//     for(int i=0; i<=T ; i++){
//         if(i%arr[0]==0)
//         prev[i]=1;
//     }

//     for(int ind=  1 ; ind<n;ind++){
//         vector<int> cur(T+1,0);
//         for(int t=0;t<=T; t++){

//             int not_pick = prev[t];

//             int pick =0;
//             if(arr[ind]<=t){
//                 pick= cur[t-arr[ind]];
//             }

//             cur[t] =  not_pick +pick;

//         }
//         prev = cur;
//     }
//     return  prev[T];

    
// }

// int main(){
//     vector<int> arr={ 1, 2,3 };

//     int n = arr.size();
//       int target= 4;
  
//     int ans= coin (target , arr );
//     cout<<ans<<endl;

// }


