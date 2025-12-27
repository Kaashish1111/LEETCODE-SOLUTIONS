class Solution {
public:
    int bestClosingTime(string cus) {
        int penalty = 0;

        // initial penalty: shop closed all day
        for(char c : cus) {
            if(c == 'Y')
                penalty++;
        }

        int minPenalty = penalty;
        int ans = 0;

        for(int i = 0; i < cus.length(); i++) {
            if(cus[i] == 'Y')
                penalty--;   // opening avoids missing Y
            else
                penalty++;   // opening causes N penalty

            if(penalty < minPenalty) {
                minPenalty = penalty;
                ans = i + 1;
            }
        }

        return ans;
    }
};
