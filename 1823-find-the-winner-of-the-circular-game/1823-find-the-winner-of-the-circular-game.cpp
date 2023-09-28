class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=0; i<n; i++)arr.push_back(i+1);
        
        int i = 0;
        while (arr.size() > 1) {
        i = (i + k - 1) % arr.size(); // Update i to skip k-1 elements
        auto it = arr.begin() + i;
        //cout << *it << endl;
        arr.erase(it);
    }
        return arr[0];
    }
};