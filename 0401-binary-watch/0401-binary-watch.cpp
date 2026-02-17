#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int getBitCount(int n)
	{
		int cnt = 0;
		while(n)
		{
			if(n & 1)
				cnt++;
			n = n >> 1;
		}
		return cnt;
	}

    vector<string> readBinaryWatch(int turnedOn) {
		if(turnedOn >= 9)
			return {};
		vector<string> ans;
		// try making all the times.
		for(int hr=0; hr<=11; hr++)
		{
			int bitNeeded = getBitCount(hr);
			if(bitNeeded > turnedOn)
				continue;
			int remBits = turnedOn - bitNeeded;
			for(int mn=0; mn<=59; mn++)
			{
				bitNeeded = getBitCount(mn);
				if(bitNeeded != remBits)
					continue;
				
				string sHr = to_string(hr);
				string sMn = to_string(mn);
				if(mn < 10)
					sMn = "0" + sMn;
				
				ans.push_back(sHr + ":" + sMn);
			}
		}
		// sort(ans.begin(), ans.end());
		return ans;
    }
};
/*
int main()
{
	//cout << "Hello world" << endl;
	int n = 1;
	Solution soln;
	vector<string> ans    = soln.readBinaryWatch(n);
	vector<string> output = {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"};
	
	for(auto &str: ans)
		cout << str << ", ";
	cout << endl;
	if(ans == output)
	{
		cout << "Pass" << endl;
	}else{
		cout << "Fail" << endl;
	}
	return 0;
}
*/