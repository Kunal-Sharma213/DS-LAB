#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string\n";
    cin >> s;
    unordered_map<char, char> pair;
    stack<char> st;
    pair.insert({']', '['});
    pair.insert({'}', '{'});
    pair.insert({')', '('});
    for (auto &iter : s)
    {
        try
        {
            if (pair.at(iter))
            {

                if (st.top() == pair[iter])
                {
                    st.pop();
                    continue;
                }
            }
        }
        catch (...)
        {
            st.push(iter);
        }
    }
    if (st.empty())
        cout << "Balanced String\n";
    else
        cout << "Unbalanced String\n";
}