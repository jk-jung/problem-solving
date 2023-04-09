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
    cin >> n;
    if (n == 0)cout << "Y 0 0\n";
    else if (n <= 3)cout << "N\n";
    else {
        double s = 1, e = 2;
        for (int i = 0; i < 300; i++) {
            double m = (s + e) / 2;
            double v = m * (n - m);
            if (v < n)s = m;
            else e = m;
        }
        cout << "Y " << s << " " << n - e << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(15);
    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
