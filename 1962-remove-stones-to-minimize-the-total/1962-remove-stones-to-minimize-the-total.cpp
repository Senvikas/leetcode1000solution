class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {
            int n = piles.size();
            int total_stones = 0;

           	//max_heap
            priority_queue<int> q;
            for (auto stone: piles)
            {
                q.push(stone);
                total_stones += stone;
            }
            int tot_rem = 0;
            while (k--)
            {
                int maxi = q.top();
                q.pop();
                int rem = maxi / 2;
                tot_rem += rem;
                q.push(maxi - rem);
            }
            return total_stones - tot_rem;
        }
};