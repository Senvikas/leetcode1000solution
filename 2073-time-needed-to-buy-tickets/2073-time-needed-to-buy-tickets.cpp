class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        unsigned int time = 0;

        for (unsigned int i = 0; i < tickets.size(); ++i) {
            time += std::clamp(tickets[i], 1, (tickets[k] - (i > k)));
        }

        return time;
    }
};