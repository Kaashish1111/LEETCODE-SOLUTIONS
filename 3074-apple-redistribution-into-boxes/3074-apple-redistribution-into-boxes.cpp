class Solution {
public:
    int minimumBoxes(vector<int>& app, vector<int>& cap) {
        sort(cap.begin(), cap.end(),greater<>());
        int totalapp=0;
        for(int appi:app){
            totalapp += appi;
        }
        int cnt=0;
        for(int c:cap){
            if(totalapp<=0){
                break;
            }
            totalapp -=c;
            cnt++;
        }
        return cnt;
    }
};
