class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);

        for(int i = 0; i<n; i++){
            prev[i] = matrix[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++){
                int best = prev[j];
                if(j > 0) best = min(best, prev[j-1]);
                if(j < n-1) best = min(best, prev[j+1]);
                temp[j] = matrix[i][j] + best;
            }
            prev = temp;
        }
        int minim = INT_MAX;
        for(int i = 0; i<n; i++){
            minim = min(minim, prev[i]);
        }
        return minim;
    }
};