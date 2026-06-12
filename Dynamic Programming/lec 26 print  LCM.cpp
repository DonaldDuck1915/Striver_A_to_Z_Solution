
#include<bits/stdc++.h>
using namespace std;

string lcs(string & s1, string& s2){

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




    int len = dp[n1][n2];

    string s = "";
    for(int il= 0;il<len; il++)
    s+="#";

    int index= len-1;

    int i= n1;
    int j = n2;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s[index]=s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else{
            i--;
        }      
    }
    return s;

}





int main(){
    string s1="sahil" ;
    string s2="sahilmehmud" ;

    int n1 = s1.size();
    int n2 = s2.size();

    string  ans = lcs(s1,s2);


    cout<<ans;

}
