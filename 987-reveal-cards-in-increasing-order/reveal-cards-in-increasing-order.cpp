class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;

        for (int i = deck.size() - 1; i >= 0; i--) {
            if (!dq.empty()) {
                dq.push_front(dq.back());   // undo "move to bottom"
                dq.pop_back();
            }
            dq.push_front(deck[i]);         // undo "reveal"
        }

        return vector<int>(dq.begin(), dq.end());
    }
};