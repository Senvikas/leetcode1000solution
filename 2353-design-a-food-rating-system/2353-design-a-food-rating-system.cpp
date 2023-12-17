class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>>mp;
    unordered_map<string, string>ms;
    unordered_map<string, int>mr;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            mr[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
            ms[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int prev_rat = mr[food];
        mr[food] = newRating;

        mp[ms[food]].erase({-prev_rat, food});
        mp[ms[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};