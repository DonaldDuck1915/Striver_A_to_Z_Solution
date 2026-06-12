#include<bits/stdc++.h>
using namespace std;

//find the length of the Longest Common Substring (LCS)

int lcs(string & s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    int LCS=0;

    
    for(int i1=1; i1<=n1;i1++){
        for(int i2=1;i2<=n2 ;i2++){

        if(s1[i1-1]== s2[i2-1]){
            dp[i1][i2] = 1 + dp[i1-1][i2-1];
            LCS= max(LCS , dp[i1][i2]);
        }

        else{
        dp[i1][i2] = 0;
        }

        }
    }
    return LCS;

}



int main(){
    string s1="abcde" ;
    string s2="dcabc" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = lcs(s1,s2);


    cout<<ans;

}


































#include<bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Substring (LCS)

int lcs(string & s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> prev(n2+1,0) , cur(n2+1,0);
    int LCS=0;

    
    for(int i1=1; i1<=n1;i1++){
        for(int i2=1;i2<=n2 ;i2++){

            if(s1[i1-1]== s2[i2-1]){
                cur[i2] = 1 + prev[i2-1];
                LCS= max(LCS , cur[i2]);
            }
            else{
            cur[i2] = 0;
            }
        }
        prev = cur;
    }
    return LCS;

}



int main(){
    string s1="abcde" ;
    string s2="dcabc" ;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    int ans = lcs(s1,s2);


    cout<<ans;

}
















// print longest common substring 





#include <bits/stdc++.h>
using namespace std;

string lcs(string &s1, string &s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    int maxLen = 0;
    int endIndex = 0;   // ending position in s1

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];

                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    endIndex = i;   // store where it ends
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    // Extract substring
    return s1.substr(endIndex - maxLen, maxLen);
}

int main(){
    string s1 = "abcde";
    string s2 = "dcabc";

    string result = lcs(s1, s2);

    cout << "Longest Common Substring: " << result << endl;
    cout << "Length: " << result.length();
}
