#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int k;
    string s;
    cin >> k >> s;
    vi v;
    int n = s.size();
    for (int i = 0; i < (n + 1) / 2; i++) {
        int j = n - i - 1;
        if (s[i] == s[j] && s[i] == '?')v.pb(i);
        else if (s[i] == '?' || s[j] == '?') s[i] = s[j] = s[i] == '?' ? s[j] : s[i];
        else if (s[i] != s[j]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    set<char> used;
    vector<char> need;

    for (char x: s) used.insert(x);
    for (char x = 'a'; x < 'a' + k; x++)if (!used.count(x))need.pb(x);

    if (need.size() > v.size()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int j = v.size() - 1; j >= 0; j--) {
        if (need.empty())need.pb('a');
        int x = v[j];
        int y = n - x - 1;
        s[x] = s[y] = need.back();
        need.pop_back();
    }
    cout << s << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
