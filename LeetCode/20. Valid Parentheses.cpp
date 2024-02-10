class Solution {
public:

    const string open = "([{";

    bool isOpen(char c) {
        return open.find(c) != string::npos;
    }

    bool isMatch(char op , char cl) {
        if (op == '(')
            return cl == ')';
        if (op == '{')
            return cl == '}';
        if (op == '[')
            return cl == ']';
        return true;    
    }

    bool isValid(string s) {
        stack < char > st;
        for (char c : s) {
            if (isOpen(c))
                st.push(c);
            else if (st.size() && isMatch(st.top() , c))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};
