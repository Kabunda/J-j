#include <iostream>
#include <string>
#include <algorithm>            // reverse
#include <set>

using namespace std;
int rifm(string a, string b)
{
    for (int i = 0; i < 10; i++)
    {
        if (a[i] != b[i])
            return i;
    }
    return 10;
}

int main()
{

    int count_dict;
    string w;
    set <string> dic;
    set <string> ::iterator it,it1,it2;
    cin >> count_dict;
    for (int i = 0; i < count_dict; i++)
    {
        cin >> w;
        reverse(w.begin(), w.end());
        dic.insert(w);
    }

    int count_wrd;
    string ans,a,b;
    cin >> count_wrd;
    for (int i = 0; i < count_wrd; i++)
    {
        cin >> w;
        reverse(w.begin(), w.end());
        it = dic.lower_bound(w);

        if (it == dic.end())
        {
            ans = *--it;
        }
        else {
            it1 = it2 = it;
            if (*it == w)
            {
                it1++;
                it2--;
            }
            else
            {
                it2--;
            }

            if ((it1 == dic.begin()) or (it1 == dic.end()))
                it1 = it2;

            if ((it2 == dic.end()) or (it2 == dic.begin()))
                it2 = it1;

            a = *it1;
            b = *it2;

            if (rifm(a, w) > rifm(b, w))
                ans = a;
            else
                ans = b;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}