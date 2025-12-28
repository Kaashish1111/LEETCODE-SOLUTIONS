class Solution {
public:
    int minimumBoxes(vector<int>& app, vector<int>& cap) {
        sort(app.begin(), app.end());
        sort(cap.begin(), cap.end());

        int i = app.size() - 1;  // apple index
        int j = cap.size() - 1;  // box index
        int cnt = 0;

        while (i >= 0 && j >= 0) {

            // count this box when we start using it
            cnt++;

            // while this box still has capacity and apples remain
            while (j >= 0 && i >= 0 && cap[j] > 0) {
                if (app[i] <= cap[j]) {
                    cap[j] -= app[i];
                    i--;                // apple batch finished
                } else {
                    app[i] -= cap[j];
                    cap[j] = 0;         // box finished
                }
            }

            // move to next box
            j--;
        }

        return cnt;
    }
};
