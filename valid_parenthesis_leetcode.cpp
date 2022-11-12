#include <bits/stdc++.h>

#define pb             push_back
#define endl "\n" 
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define IO	       { ios_base::sync_with_stdio(false); cin.tie(0); }
#define read(x)	       freopen(x, "r", stdin)
#define write(x)       freopen(x, "w", stdout)

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;


int main() {
    string s;
    cin >> s;
    stack<char> st;

    for (int i{0}; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            st.push(s[i]);
        else
        {
            if (!st.empty())
            {
                char top_layer = st.top();
                if ((top_layer == '(' and s[i] == ')') or (top_layer == '{' and s[i] == '}') or (top_layer == '[' and s[i] == ']'))
                    st.pop();
                else
                {
                    cout << "False" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "False" << endl;
                return 0;
            }
        }
    }
    if (st.empty())
    {
        cout << "True" << endl;
        return 0;
    }
    else
    {
        cout << "False" << endl;
        return 0;
    }
}