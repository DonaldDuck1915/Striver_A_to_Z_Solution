// length of longest divisible  subset

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
   bool compare (string  &s1 ,string &s2 ){

        if(s1.size()!=s2.size()+1)return false;
        int first=0, second =0;
        while(first<s1.size()){
            if(s1[first]==s2[second] && second<s2.size()){
                first++;
                second++;
            }
            else {
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())return true;
        return false;
    }
public:

    static bool  comp(string a ,  string b){
        return a.size()<b.size();
    }

    
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),comp);

        int n = words.size();

       

        vector<int> dp(n, 1);

        int maxi = 1;

        for(int index = 0; index < n; index++) {

            for(int prev = 0; prev < index; prev++) {

                if(compare(words[index],words[prev])) {
                    dp[index] = max(dp[index], dp[prev] + 1);
                }
            }

            maxi = max(maxi, dp[index]);
        }
        return maxi;
    }
};

int main() {

    vector<string> nums = {"a","b","ba","bca","bda","bdca"};

//     vector<string> v = {"abc", "a", "abcd"};

// sort(v.begin(), v.end(), Solution::comp);
    

    Solution sol;

    cout << "Length of Longest String Chain =  "
         << sol.longestStrChain(nums) << '\n';

    return 0;
}























#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool compare (string  &s1 ,string &s2 ){

        if(s1.size()!=s2.size()+1)return false;
        int first=0, second =0;
        while(first<s1.size()){
            if(s1[first]==s2[second] && second<s2.size()){
                first++;
                second++;
            }
            else {
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())return true;
        return false;
    }
public:

    
    static bool  comp(string a ,  string b){
        return a.size()<b.size();
    }

    vector<string> longestStrChain(vector<string>& words, vector<int> & hp) {
        int n=  words.size();
        sort (words.begin(),words.end(),comp);

        int  maxi=1;
        vector<int> dp(n,1);
        int  lastindex=0;
        for(int i=0;i<n;i++){
            hp[i]=i;
            for(int  prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    hp[i]=prev;
                }

            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastindex=i;
            }
        }

        vector<string>  temp;
        temp.push_back(words[lastindex]);

        while(hp[lastindex]!=lastindex){
            lastindex=hp[lastindex];
            temp.push_back(words[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

int main() {

    vector<string> nums = {"a","b","ba","bca","bda","bcda"};
    int n=  nums.size();
    

    Solution sol;
    vector<int> hp(n);

  
    vector<string> ans= sol.longestStrChain(nums, hp) ;
    for(auto it : ans)cout<<it<<" ";
    cout<<endl;


    return 0;
}







