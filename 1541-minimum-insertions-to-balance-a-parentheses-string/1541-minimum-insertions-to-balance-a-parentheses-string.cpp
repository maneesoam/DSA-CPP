class Solution {
public:
int minInsertions(string s) {
int open = 0;
int insertions = 0;


    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open++;
        } 
        else {
            if (i + 1 < s.size() && s[i + 1] == ')') {
                // We have a complete closing pair ))
                if (open > 0) {
                    open--;
                } else {
                    // Insert an opening bracket
                    insertions++;
                }
                i++; // Skip the second ')'
            } 
            else {
                // Only one ')' is available; insert another ')'
                insertions++;

                if (open > 0) {
                    open--;
                } else {
                    // Insert '(' as well
                    insertions++;
                }
            }
        }
    }

    // Each unmatched '(' needs two closing brackets
    return insertions + 2 * open;
}


};
