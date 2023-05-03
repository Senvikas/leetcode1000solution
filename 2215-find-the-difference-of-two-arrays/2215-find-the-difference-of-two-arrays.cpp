class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &nums1, vector<int> &nums2)
        {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            auto it1(nums1.begin());
            auto it2(nums2.begin());

            vector<vector < int>> res(2);

            while (it1 != nums1.end() && it2 != nums2.end())
            {
                if (*it1 == *it2)
                {
                    it1 = findFirstNotEqual(next(it1), nums1.end(), *it1);
                    it2 = findFirstNotEqual(next(it2), nums2.end(), *it2);
                }
                else if (*it1<*it2)
                {
                    res[0].push_back(*it1);
                    it1 = findFirstNotEqual(next(it1), nums1.end(), *it1);
                }
                else
                {
                    res[1].push_back(*it2);
                    it2 = findFirstNotEqual(next(it2), nums2.end(), *it2);
                }
            }

            while (it1 != nums1.end())
            {
                res[0].push_back(*it1);
                it1 = findFirstNotEqual(next(it1), nums1.end(), *it1);
            }

            while (it2 != nums2.end())
            {
                res[1].push_back(*it2);
                it2 = findFirstNotEqual(next(it2), nums2.end(), *it2);
            }

            return res;
        }
    private:
        template < typename It>
        It findFirstNotEqual(It begin, It end, int value)
        {
            for (; begin != end; ++begin)
            {
                if (*begin != value)
                {
                    return begin;
                }
            }

            return end;
        }
};