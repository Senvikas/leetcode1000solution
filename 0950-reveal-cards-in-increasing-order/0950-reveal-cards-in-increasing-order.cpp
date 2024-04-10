class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        // defining a queue for tracking our indices
        queue<int> q;
        
        // defining ans vector which is to be returned
        vector<int> ans(deck.size(), 0);
        // sort the deck so that we can return it in the correct order
        sort(deck.begin(), deck.end());

        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        
        // i tracks the card indices in the ans array
        int i = 0;

        while(!q.empty() && i < deck.size()){
            // The top of the queue represents the card which is being revealed next
            int top = q.front();
            // Remove the revealed card
            q.pop();

            // The revealed card should be next smallest in the sorted deck
            ans[top] = deck[i];
            i++;

            // The card after the revealed card, if exists, should be placed at bottom of the deck
            // i.e. at the back of the queue
            if(q.empty()){
                break;
            }
            
            int second = q.front();
            q.pop();
            q.push(second);
        }

        return ans;

    }
};