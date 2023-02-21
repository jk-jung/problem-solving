#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    string s;
    cin >> s;
    map<char, int> ck;
    for (char x: s) ck[x]++;
    string t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    if (t.size() == 2 && t[0] + 1 == t[1])cout << "No answer\n";
    else if (t.size() == 3 && t[0] + 1 == t[1] && t[1] + 1 == t[2])cout << "No answer\n";
    else {
        string a, b;
        for (int i = 'y'; i >= 'a'; i -= 2)a += string(ck[i], i);
        for (int i = 'z'; i >= 'b'; i -= 2)b += string(ck[i], i);
        for (int i = 0; i < 2; i++) {
            reverse(a.begin(), a.end());
            for (int j = 0; j < 2; j++) {
                reverse(b.begin(), b.end());
                if (a.size() && b.size()) {
                    if (ab(a.back() - b[0]) == 1) continue;
                    cout << a << b << endl;
                    return;
                } else {
                    cout << a << b << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
