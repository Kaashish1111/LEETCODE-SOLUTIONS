class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0; // Pointers for version1 and version2
        
        while (i < version1.length() || j < version2.length()) {
            int num1 = 0, num2 = 0;

            // Parse the next revision number from version1
            while (i < version1.length() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Parse the next revision number from version2
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare the two revision numbers
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            // Move past the '.' delimiter
            i++;
            j++;
        }

        return 0; // Versions are equal
    }
};
