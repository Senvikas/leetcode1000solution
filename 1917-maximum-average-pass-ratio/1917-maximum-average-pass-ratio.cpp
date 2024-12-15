class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cls, int extra) {
        priority_queue< pair< double, vector<int>>> maxHeap;

        for(auto &cl: cls)
        {
            int pass = cl[0];
            int total = cl[1];

            double gain = (double)(pass+1)/(total+1) - (double)(pass)/total;
            maxHeap.push({gain, cl});
        }

        while(extra--)
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            vector<int> cl = top.second;

            int pass = cl[0];
            int total = cl[1];

            pass++;
            total++;

            cl = {pass, total};

            // new gain
            double gain = (double)(pass+1)/(total+1) - (double)(pass)/total;
            maxHeap.push({gain, cl});
        }

        double totalSum = 0.0;
        while(!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            vector<int> cl = top.second;

            int pass = cl[0];
            int total = cl[1];

            totalSum += (double)pass/total;
        }

        return totalSum / cls.size();
    }
};