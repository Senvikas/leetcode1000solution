class Solution {
public:

    map<int, map<int, int>> createDiagnolMapping(vector<vector<int>> &jaggedMatrix) {

        map<int, map<int, int>> ret;
        for (int row = 0; row < jaggedMatrix.size(); ++row) {
            for (int column = 0; column < jaggedMatrix[row].size(); ++column) {
                ret[row + column][jaggedMatrix.size() - row - 1] = jaggedMatrix[row][column];
            }
        }
        return ret;
    }
    vector<int> mapToVector(map<int, map<int, int>> omap) {
        vector<int> ret;
        for (pair<int, map<int, int>> diagnol: omap) {
            for (pair<int, int> el: diagnol.second) {
                ret.push_back(el.second);
            }
        }
        return ret;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, map<int, int>> omap = createDiagnolMapping(nums);
        return mapToVector(omap);
    }
};