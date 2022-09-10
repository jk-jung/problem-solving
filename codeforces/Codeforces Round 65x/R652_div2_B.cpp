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
    int n;
    string s, r, a, b;
    cin >> n >> s;
    int i = 0;
    while (i < n && s[i] == '0')a += s[i++];
    i = n - 1;
    while (i >= 0 && s[i] == '1')b += s[i--];

    if (a.size() + b.size() == n) {
        cout << a + b << endl;
    } else {
        cout << a + "0" + b << endl;
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
