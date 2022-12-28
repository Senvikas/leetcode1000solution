class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {
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
                int maxi = q.top();	//pile having max size
                q.pop();
                tot_rem += maxi / 2;
                q.push(maxi - maxi / 2);
            }
            return total_stones - tot_rem;
        }
};