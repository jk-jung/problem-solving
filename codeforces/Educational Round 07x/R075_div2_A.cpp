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
    string r, s;
    cin >> s;
    while (s.size() >= 2) {
        int m = s.size();
        if (s[m - 1] == s[m - 2])s.pop_back(), s.pop_back();
        else r += s.back(), s.pop_back();
    }
    if (!s.empty())r += s.back();
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    cout << r << endl;
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
