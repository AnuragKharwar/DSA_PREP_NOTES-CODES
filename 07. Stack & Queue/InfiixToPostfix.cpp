class Solution
{
public:
  // Function to convert an infix expression to a postfix expression.
  // precedence as per oprand order

  int prec(char c)
  {
    if (c == '^')
      return 3;
    else if (c == '/' || c == '*')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1;
  }
  string infixToPostfix(string s)
  {
    // Your code here
    stack<char> st;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
      {
        ans += s[i]; // add the character by concantenation
      }
      else if (s[i] == '(')
      {
        st.push(s[i]);
      }
      else if (s[i] == ')')
      {
        while (st.top() != '(')
        {
          ans += st.top();
          st.pop();
        }
        st.pop();
      }
      else
      {
        while (!st.empty() && prec(s[i]) <= prec(st.top()))
        {
          ans += st.top();
          st.pop();
        }
        st.push(s[i]);
      }
    }
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }

    return ans;
  }
};