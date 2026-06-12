// // length of longestbitonicSubseq

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int longestbitonicSubseq(vector<int>& arr) {
//         int  n=arr.size();

//         vector<int> dp1(n,1), dp2(n,1);
//         int maxi=0;

//         for(int i=0;i<n;i++){
//             for(int prev =0;prev<i;prev++){
//                 if(arr[prev]<arr[i]){
//                     dp1[i]=max(dp1[prev]+1, dp1[i]);
//                 }
//             }
//         }

//         for(int j=n-1;j>=0;j--){
//             for(int prev =n-1;prev>j;prev--){
//                 if(arr[j]>arr[prev]){
//                     dp2[j]=max(dp2[j],dp2[prev]+1);
//                 }
//             }
//             maxi=max(maxi,dp1[j]+dp2[j]-1);

//         }
//         return maxi;        
//     }
// };

// int main() {

//     vector<int> nums = {5, 1, 4, 2, 3, 6, 8, 7};

//     Solution sol;

//     cout<<sol.longestbitonicSubseq(nums)<<endl;

    

//     return 0;
// }


























// length of longestbitonicSubseq

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void longestbitonicSubseq(vector<int>& arr) {
        int  n=arr.size();

        vector<int> hsh1(n), hsh2(n);

        vector<int> dp1(n,1), dp2(n,1);
        int maxi=0;

        for(int i=0;i<n;i++){
            hsh1[i]=i;
            for(int prev =0;prev<i;prev++){
                if(arr[prev]<arr[i] && dp1[prev]+1>dp1[i] ){
                    dp1[i]=(dp1[prev]+1);
                    hsh1[i]=prev;
                }
            }
        }
        int lastindex=0;

        for(int j=n-1;j>=0;j--){
            hsh2[j]=j;
            for(int prev =n-1;prev>j;prev--){
                if(arr[j]>arr[prev] && dp2[j]<dp2[prev]+1){
                    dp2[j]=(dp2[prev]+1);
                    hsh2[j]=prev;
                }
            }
            if(maxi<dp1[j]+dp2[j]-1){
                maxi=(dp1[j]+dp2[j]-1);
                lastindex=j;
            }
        }
            int  lastindex2=lastindex;

            vector<int> ans;
            ans.push_back(arr[lastindex]);

            while(hsh1[lastindex]!=lastindex){
                lastindex=hsh1[lastindex];
                ans.push_back(arr[lastindex]);
            }
            reverse(ans.begin(),ans.end()); 
            
            
            while(hsh2[lastindex2]!=lastindex2){
                lastindex2=hsh2[lastindex2];
                ans.push_back(arr[lastindex2]);
            }
            for(auto  it: ans){
            cout<<it<<" ";
            }           
    }
};

int main() {

    vector<int> nums = {1,2,3,4,18,3,20,  2,1,0};

    Solution sol;

    sol.longestbitonicSubseq(nums);

    

    return 0;
}


