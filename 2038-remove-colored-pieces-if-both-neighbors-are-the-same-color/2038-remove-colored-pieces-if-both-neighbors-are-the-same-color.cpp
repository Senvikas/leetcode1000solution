class Solution {
public:
    bool winnerOfGame(string c) {
        int alice = 0, bob = 0;
        for(int i=1; i<c.size()-1; i++){
            if(c[i-1] == c[i] && c[i] == c[i+1]){
                if(c[i] == 'A')alice++;
                else bob++;
            }
        }
        //cout << alice << " " << bob << endl;
        return alice > bob;
    }
};