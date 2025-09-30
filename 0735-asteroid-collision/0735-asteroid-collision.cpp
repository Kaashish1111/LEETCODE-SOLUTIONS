class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        while (!st.empty() && st.top() > 0 && a < 0) {
            if (abs(st.top()) < abs(a)) {
                st.pop(); // top is smaller, destroy it and check again
                continue;
            } 
            else if (abs(st.top()) == abs(a)) {
                st.pop(); // both destroy
                destroyed = true;
            }
            destroyed = true; // current asteroid destroyed
            break;
        }

        if (!destroyed) st.push(a);
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

};