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

vector<string> split(string &x) {
    vector<string> r;
    r.pb("");
    char last = x[0];
    for (char c: x) {
        if (c == last) {
            r.back() += c;
        } else {
            r.pb(string(1, c));
            last = c;
        }
    }
    return r;
}

void solve() {
    string a, b;
    cin >> a >> b;
    vector<string> A = split(a);
    vector<string> B = split(b);
    if (A.size() != B.size()) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < A.size(); i++) {
        if (A[i][0] != B[i][0] || !(A[i].size() <= B[i].size() && B[i].size() <= A[i].size() * 2)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
