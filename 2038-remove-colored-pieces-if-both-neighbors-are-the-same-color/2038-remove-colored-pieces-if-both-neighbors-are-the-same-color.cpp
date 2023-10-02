#include <string>

class Solution {
public:
    bool winnerOfGame(std::string colors) {
        int alice = 0, bob = 0;
        int l = 0;
        
        for (int r = 0; r < colors.length(); ++r) {
            if (colors[l] != colors[r]) {
                l = r;
            }
            
            int extra = r - l + 1 - 2;
            
            if (extra > 0) {
                if (colors[r] == 'A') {
                    alice += 1;
                } else {
                    bob += 1;
                }
            }
        }
        
        return alice > bob;
    }
};
