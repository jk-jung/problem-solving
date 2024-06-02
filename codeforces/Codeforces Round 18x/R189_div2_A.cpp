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

string s;

bool go(int i) {
    if (i == s.size()) return true;
    bool r = false;
    if (s[i] == '1') {
        r = r || go(i + 1);
        if (i + 1 < s.size() && s[i + 1] == '4') {
            r = r || go(i + 2);
            if (i + 2 < s.size() && s[i + 2] == '4')
                r = r || go(i + 3);
        }
    }

    return r;
}

void solve() {
    cin >> s;
    cout << (go(0) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
