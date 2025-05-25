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


bool f(string &s, string &a, string &b) {
    int n = s.size();
    int i = 0;
    for (; i < n; i++) {
        if (s.substr(i, a.size()) == a) {
            i += a.size();
            break;
        }
    }

    for (; i < n; i++) {
        if (s.substr(i, b.size()) == b) return true;
    }
    return false;
}

void solve() {
    string s, a, b;
    cin >> s >> a >> b;
    bool A = f(s, a, b);
    reverse(s.begin(), s.end());
    bool B = f(s, a, b);

    if (A && B)cout << "both";
    else if (A)cout << "forward";
    else if (B)cout << "backward";
    else cout << "fantasy";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
