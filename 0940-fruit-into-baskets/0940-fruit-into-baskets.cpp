class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int window_start = 0, window_end = 0, max_length = 1;
        unordered_map<int,int> unique_fruits;

        while(window_end < fruits.size()){
            int current_fruit_type = fruits[window_end];
           
            unique_fruits[current_fruit_type]++;

            //better
            // while(unique_fruits.size() > 2){
            //     int start_fruit_type = fruits[window_start];
            //     unique_fruits[start_fruit_type]--;
            //     if(unique_fruits[start_fruit_type] == 0) {
            //         unique_fruits.erase(start_fruit_type);
            //     }
            //     window_start++;
            // }
            
            //optimal
            if(unique_fruits.size() > 2){
                int start_fruit_type = fruits[window_start];
                unique_fruits[start_fruit_type]--;
                if(unique_fruits[start_fruit_type] == 0) {
                    unique_fruits.erase(start_fruit_type);
                }
                window_start++;
            }
            //check needs with optimal
            if(unique_fruits.size() <= 2)
            max_length = max(max_length, window_end - window_start + 1);
            window_end++;
        }

        return max_length;
    }
};