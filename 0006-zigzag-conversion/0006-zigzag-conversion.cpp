class Solution {
public:
    string convert(string s, int numRows) {
          if (numRows == 1)
            return s;

        string ans;
        vector<string> rows(numRows);
        int k = 0;
        int direction = -1;

        for (char c : s) {
            rows[k] += c;
            if (k == 0 || k == numRows - 1)
                direction *= -1;
            k += direction;
        }

        for (string row : rows)
            ans += row;

        return ans;
    }
};