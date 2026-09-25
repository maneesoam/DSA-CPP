class Solution {
public:

    set<string> parseExpr(string &s, int &i) {
        set<string> ans = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip comma

            set<string> temp = parseTerm(s, i);

            // UNION
            ans.insert(temp.begin(), temp.end());
        }

        return ans;
    }

    set<string> parseTerm(string &s, int &i) {
        set<string> ans = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur;

            if (s[i] >= 'a' && s[i] <= 'z') {
                cur.insert(string(1, s[i]));
                i++;
            }
            else if (s[i] == '{') {
                i++; // skip {

                cur = parseExpr(s, i);

                i++; // skip }
            }

            // CONCATENATION
            set<string> temp;

            for (string a : ans)
                for (string b : cur)
                    temp.insert(a + b);

            ans = temp;
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parseExpr(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};