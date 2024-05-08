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
    string s;
    cin >> s;
    string cur;
    int r = 1;
    int i = 0;
    cur += s[i++];
    while (i < s.size() && s[i] == '0') cur += s[i++];
    for (; i < s.size();) {
        string nxt;
        nxt += s[i++];
        while (i < s.size() && s[i] == '0') nxt += s[i++];

        if (cur.size() > nxt.size() || (cur.size() == nxt.size() && cur >= nxt)) {
            r++;
        } else {
            r = 1;
        }
        cur += nxt;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
