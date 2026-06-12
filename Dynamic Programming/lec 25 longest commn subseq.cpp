#include<bits/stdc++.h>
using namespace std;

int lcs( int i1, int i2 , string & s1, string& s2){

    if(i1 <0 || i2<0)
    return 0;

    if(s1[i1]== s2[i2]){
        return  1 + lcs ( i1-1, i2-1,s1,s2);
    }
    return( max(lcs ( i1-1, i2,s1,s2), lcs ( i1, i2-1,s1,s2)));
}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();

    int ans = lcs(n1-1, n2-1, s1,s2);


    cout<<ans;

}
































#include<bits/stdc++.h>
using namespace std;

int lcs( int i1, int i2 , string & s1, string& s2, vector<vector<int>> &dp){

    if(i1 <0 || i2<0)
    return 0;

    if(dp[i1][i2]!= -1){
        return dp[i1][i2];
    }

    if(s1[i1]== s2[i2]){
        return dp[i1][i2] = 1 + lcs ( i1-1, i2-1,s1,s2 ,dp);
    }
    return( dp[i1][i2] = max(lcs ( i1-1, i2,s1,s2, dp), lcs ( i1, i2-1,s1,s2 , dp)));
}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1,vector<int> (n2,-1));

    int ans = lcs(n1-1, n2-1, s1,s2, dp);


    cout<<ans;

}


































#include<bits/stdc++.h>
using namespace std;

int lcs( int i1, int i2 , string & s1, string& s2, vector<vector<int>> &dp){

    if(i1 ==0 || i2==0)
    return 0;

    if(dp[i1][i2]!= -1){
        return dp[i1][i2];
    }

    if(s1[i1-1]== s2[i2-1]){
        return dp[i1][i2] = 1 + lcs ( i1-1, i2-1,s1,s2 ,dp);
    }
    return( dp[i1][i2] = max(lcs ( i1-1, i2,s1,s2, dp), lcs ( i1, i2-1,s1,s2 , dp)));
}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = lcs(n1, n2, s1,s2, dp);


    cout<<ans;

}
























#include<bits/stdc++.h>
using namespace std;

int lcs(string & s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    
    for(int i1=1; i1<=n1;i1++){
        for(int i2=1;i2<=n2 ;i2++){

        if(s1[i1-1]== s2[i2-1]){
            dp[i1][i2] = 1 + dp[i1-1][i2-1];
        }

        else{
        dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
        }

        }
    }
    return dp[n1][n2];

}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = lcs(s1,s2);


    cout<<ans;

}








































#include<bits/stdc++.h>
using namespace std;

int lcs(string & s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

   vector<int>  prev(n2+1,0) , cur(n2+1,0);
    
    for(int i1=1; i1<=n1;i1++){
        for(int i2=1;i2<=n2 ;i2++){

            if(s1[i1-1]== s2[i2-1])
                cur[i2] = 1 + prev[i2-1];

            else{
            cur[i2] = max(prev[i2], cur[i2-1]);
            }
        } 
        prev= cur;
    }
    return prev[n2];

}



int main(){
    string s1="adebc" ;
    string s2="dcadb" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = lcs(s1,s2);


    cout<<ans;

}