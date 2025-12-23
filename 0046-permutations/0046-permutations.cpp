class Solution {
    void permutations(vector<int> ques,
                      vector<int>& asf,
                      vector<vector<int>>& result) {

        // base case
        if (ques.size() == 0) {
            result.push_back(asf);
            return;
        }

        for (int i = 0; i < ques.size(); i++) {
            int val = ques[i];

            // qlpart + qrpart
            vector<int> roq;
            for (int j = 0; j < ques.size(); j++) {
                if (j != i) roq.push_back(ques[j]);
            }

            asf.push_back(val);                 // add to answer so far
            permutations(roq, asf, result);     // faith
            asf.pop_back();                     // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> asf;

        permutations(nums, asf, result);
        return result;
    }
};
