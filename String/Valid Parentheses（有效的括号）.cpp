/* Valid Parentheses（有效的括号） */

/* 第一种 */
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
          if (st.empty()) {
            st.push(s[i]);
          } else {
            if ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')) {
              st.pop();
            } else {
              st.push(s[i]);
            }
          }
        }
        return st.empty();
    }
};

/* 第二种：使用字符串代替栈，实际上与第一种大同小异 */
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
          if (res.size() == 0) {
            res.push_back(s[i]);
          } else {
            int last = res.size() - 1;
            if ((res[last] == '(' && s[i] == ')') || (res[last] == '{' && s[i] == '}') || (res[last] == '[' && s[i] == ']')) {
              res.pop_back();
            } else {
              res.push_back(s[i]);
            }
          }
        }
        return res.size() == 0;
    }
};