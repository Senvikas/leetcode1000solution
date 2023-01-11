class Solution
{
    public:
        vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
        {
            vector<int> ans;
            int maxScore = 0;
            for (int i = 0; i < 4096; i++)
            {
                vector<int> temp(12, 0);
                int arrows = numArrows;
                for (int j = 11; j >= 0; j--)
                {
                    if (i &(1 << j))
                    {
                        if (arrows <= aliceArrows[j]) continue;
                        int used = aliceArrows[j] + 1;
                        arrows -= used;
                        temp[j] = used;
                    }
                }
                for (int j = 0; j < 12; j++)
                    if (i && (1 << j))
                    {
                        temp[j] += arrows;
                        break;
                    }	//settling remaining arrwos

                int thisScore = 0;
                for (int section = 0; section < 12; section++)
                    if (temp[section] > aliceArrows[section]) thisScore += section;

                if (thisScore > maxScore) maxScore = thisScore, ans = temp;
            }
            return ans;
        }
};