// // LENGTH OF LONGEST SUBSEQUENCE OF STRING 


// #include<bits/stdc++.h>
// using namespace std;

// int lcs( int i1, int i2 , string & s1, string& s2){

//     if(i1<0 || i2<0)return 0;

//     if(s1[i1]==s2[i2])return 1+ lcs(i1-1,i2-1,s1,s2);
//     return max(lcs(i1-1,i2,s1,s2),lcs(i1,i2-1,s1,s2));
// }



// int main(){
//     string s1="adebc" ;
//     string s2="dcadb" ;

//     int n1 = s1.size();
//     int n2 = s2.size();

//     int ans = lcs(n1-1, n2-1, s1,s2);

//     cout<<ans;

// }























// LENGTH OF LONGEST SUBSEQUENCE OF STRING 


// #include<bits/stdc++.h>
// using namespace std;

// int lcs( int i1, int i2 , string & s1, string& s2, vector<vector<int>> &dp){
    

//     if(i1<0 || i2<0)return 0;
//     if(dp[i1][i2]!=-1)return dp[i1][i2];

//     if(s1[i1]==s2[i2])return dp[i1][i2]=1+ lcs(i1-1,i2-1,s1,s2, dp);

//     return dp[i1][i2]=max(lcs(i1-1,i2,s1,s2,dp),lcs(i1,i2-1,s1,s2, dp));
// }



// int main(){
//     string s1="adebc" ;
//     string s2="dcadb" ;

//     int n1 = s1.size();
//     int n2 = s2.size();
//     vector<vector<int>> dp(n1, vector<int> (n2,-1));

//     int ans = lcs(n1-1, n2-1, s1,s2 , dp);
    
//     cout<<ans;

// }

























// #include<bits/stdc++.h>
// using namespace std;

// int lcs( int l, int m , string & s1, string& s2, vector<vector<int>> &dp){
    
//     for(int i1=1;i1<=l;i1++){
//         for( int i2=1;i2<=m;i2++){

//             if(s1[i1-1]==s2[i2-1]) dp[i1][i2]=1+ dp[i1-1][i2-1];

//             else dp[i1][i2]=max(dp[i1-1][i2], dp[i1][i2-1]);

//         }
//     }
//     return dp[l][m];

   
// }



// int main(){
//     string s1="adebc" ;
//     string s2="dcadb" ;

//     int n1 = s1.size();
//     int n2 = s2.size();
//     vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));

//     int ans = lcs(n1, n2, s1,s2 , dp);
    
//     cout<<ans;

// }

















// #include<bits/stdc++.h>
// using namespace std;

// int lcs( int l, int m , string & s1, string& s2){

//     vector<int> cur(m+1,0);
//     vector<int> prev(m+1,0);
    
//     for(int i1=1;i1<=l;i1++){
//         for( int i2=1;i2<=m;i2++){

//             if(s1[i1-1]==s2[i2-1]) cur[i2]=1+ prev[i2-1];

//             else cur[i2]=max(prev[i2], cur[i2-1]);
//         }
//        prev=cur;
//     }
//     return prev[m];
// }



// int main(){
//     string s1="adebc" ;
//     string s2="dcadb" ;

//     int n1 = s1.size();
//     int n2 = s2.size();

//     int ans = lcs(n1, n2, s1,s2 );
    
//     cout<<ans;

// }








































#include<bits/stdc++.h>
using namespace std;

string lcs( int l, int m , string & s1, string& s2, vector<vector<int>> &dp){
    
    for(int i1=1;i1<=l;i1++){
        for( int i2=1;i2<=m;i2++){

            if(s1[i1-1]==s2[i2-1]) dp[i1][i2]=1+ dp[i1-1][i2-1];

            else dp[i1][i2]=max(dp[i1-1][i2], dp[i1][i2-1]);

        }
    }
     int len = dp[l][m];

     string ans="";
     for(int i=0;i<len;i++){
        ans+="#";
     }
     len=len-1;
     while(l>0 && m>0){
        if(s1[l-1]==s2[m-1]){
            ans[len]=s1[l-1];
            len--;
            l--;
            m--;
        }
        else if(dp[l-1][m]>dp[l][m-1]){
            l--;
        }
        else {
            m--;
        }
     }
     return ans;

   
}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));

    string ans = lcs(n1, n2, s1,s2 , dp);
    
    cout<<ans;

}




























#include<bits/stdc++.h>
using namespace std;

int lcs( int l, int m , string & s1, string& s2, vector<vector<int>> &dp){
    int lcs=0;
    
    for(int i1=1;i1<=l;i1++){
        for( int i2=1;i2<=m;i2++){

            if(s1[i1-1]==s2[i2-1]){

                dp[i1][i2]=1+ dp[i1-1][i2-1];
                lcs=max(lcs, dp[i1][i2]);

            } 

            else dp[i1][i2]=0;

        }
    }
   

    return lcs;

   
}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));

    int ans = lcs(n1, n2, s1,s2 , dp);
    
    cout<<ans;

}