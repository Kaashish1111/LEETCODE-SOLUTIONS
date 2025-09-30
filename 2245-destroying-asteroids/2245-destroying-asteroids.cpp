class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end()); 
        long long currMass = mass; 
        
        for (int a : asteroids) {
            if (currMass >= a) {
                currMass += a;
            } else {
                return false;
            }
        }
        return true;
    }
};
