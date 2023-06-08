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
    vi v(n);
    set<int> ck;
    for (int &x: v)cin >> x, ck.insert(x);
    sort(v.rbegin(), v.rend());

    if (ck.size() == 1) {
        cout << "NO\n";
    } else {
        if (v[0] == v[1]) {
            for (int i = 1; i < n; i++)
                if (v[i] != v[1]) {
                    swap(v[i], v[1]);
                    break;
                }
        }

        cout << "YES\n";
        for (int x: v)cout << x << " ";
        cout << endl;
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
