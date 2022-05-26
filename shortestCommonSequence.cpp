
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>> &matrix,int col, int row);

class shortestCommonSupersequence
{
    public:
    shortestCommonSupersequence(string A,string B):A_(A),B_(B),
                                DP(A_.size()+1,vector<int>(B_.size()+1,0)){};
    string Solusion();
  
    private:
    void commanString();
    string A_;
    string B_;
    vector<vector<int>> DP;

};
string shortestCommonSupersequence::Solusion()
{
    commanString();
    int a=A_.size(),b=B_.size();
    string res;
    while(a>0&&b>0)
    {
        if(A_[a-1]==B_[b-1])
        {
            res.push_back(A_[a-1]);
            a--;
            b--;
        }
        else
        {
            if(DP[a][b-1] >= DP[a-1][b])
            {
                res.push_back(B_[b-1]);
                b--;
            }
            else
            {
                res.push_back(A_[a-1]);
                a--;
            }
        }
    }
    while(a>0){
        res.push_back(A_[a-1]);
        a--;
    }
    while(b>0){
        res.push_back(B_[b-1]);
        b--;
    }
    reverse(res.begin(),res.end());
    return res;

}
void shortestCommonSupersequence::commanString()
{
   int size_A = A_.size(), size_B = B_.size();

   for (size_t i = 0; i < size_A; i++)
   {
       for (size_t j = 0; j < size_B; j++)
       {
           if (A_[i] == B_[j])
           {
               DP[i+1][j+1] = 1 + DP[i][j];
           }
           else
           {
             DP[i+1][j+1] =  max(DP[i][j+1],DP[i+1][j]); 
           }           
       }
   }
}
string lcs2(string& A, string& B) ;
string shortestCommonSupersequence2(string& A, string& B) {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs2(A, B)) {
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c;
            i++, j++;
        }
        cout<<"i = "<<i<<" , "<<"j = "<<j<<endl;
        cout<<"res = "<<res<<endl;
        return res  + A.substr(i)+B.substr(j);
    }

string lcs2(string& A, string& B) 
{
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            else
                dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
    return dp[n][m];
}

int main()
{
    
    //shortestCommonSupersequence x = shortestCommonSupersequence("aaac","cab");
    //cout<<x.Solusion();
    string a = "acbcab", b = "abd";
    cout<<shortestCommonSupersequence2(a,b);
    return 0;
}

void printMatrix(vector<vector<int>> &matrix,int col, int row)
{
    int size_A = col, size_B = row;

    for (size_t i = 1; i < size_A; i++)
   {
       for (size_t j = 1; j < size_B; j++)
       {
           cout<<matrix[i][j];
           
       }
       cout<<endl;
   }
}
