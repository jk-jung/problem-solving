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
    int n, m;
    cin >> n >> m;

    string a, b, t = "10";
    for (int j = 0; j < m; j += 2) {
        a += t;
        reverse(t.begin(), t.end());
        b += t;
    }
    for (int i = 0; i < n; i += 2) {
        for (char x: a)cout << x << " ";
        cout << endl;
        for (char x: b)cout << x << " ";
        cout << endl;
        swap(a, b);
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
