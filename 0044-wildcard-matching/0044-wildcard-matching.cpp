#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	vector<vector<int>> dp;
	bool solve(int i, int j, string &s, string &p)
	{
		if(i == s.size())
		{
			// remaining all the chars should be *
			while(j < p.size())
			{
				if(p[j++] != '*')
					return false;
			}
			return true;
		}
		
		if(j == p.size())
			return false;
		
		if(dp[i][j] != -1)
			return dp[i][j];
		
		// match
		if(s[i] == p[j] || p[j] == '?')
			return dp[i][j] = solve(i+1, j+1, s, p);
		
		if(p[j] == '*')
		{
			return dp[i][j] = solve(i+1, j, s, p) | solve(i+1, j+1, s, p) | solve(i, j+1, s, p);
		}
		
		return dp[i][j] = false;
	}

	bool isMatch(string &s, string &p)
	{
		dp.resize(s.size(), vector<int>(p.size(), -1));
		return solve(0, 0, s, p);
	}
};


// int main()
// {
// 	// cout << "Hello world!!!" << endl;
// 	string s = "paaab";
// 	string p = "?*ab";
	
// 	Solution soln;
// 	bool ans = soln.isMatch(s, p);
// 	cout << ans << endl;
// 	bool expected = true;
// 	if(ans == expected)
// 	{
// 		cout << "Pass" << endl;
// 	}else{
// 		cout << "Fail" << endl;
// 	}
// 	return 0;
// }