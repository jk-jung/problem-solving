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
    map<char, int> a;
    for (char x: s) {
        a[x]++;
    }
    if (a.size() > 4 || a.size() == 1 || s.size() < 4) {
        cout << "No";
    } else if (a.size() >= 3) {
        cout << "Yes";
    } else {
        int m = 10;
        for (auto [x, y]: a)m = min(m, y);
        cout << (m == 1 ? "No" : "Yes") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
