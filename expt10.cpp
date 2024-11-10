#include <iostream>
#include <vector>
#include <string>
using namespace std;
string LCS(const string &str1, const string &str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;
    int endIndex = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    if (maxLength == 0)
    {
        return "";
    }
    return str1.substr(endIndex - maxLength + 1, maxLength);
}
int main()
{
    string str1, str2;
    cout << "Enter the first line: ";
    getline(cin, str1);
    cout << "Enter the second line: ";
    getline(cin, str2);
    string result = LCS(str1, str2);
    if (result.empty())
    {      cout << "No common substring found." << endl;
    }
    else
    {
        cout << "Longest common substring: " << result << endl;
    }
    return 0;
}
