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
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[j] != b[j]) {
                    a[i] = b[i];
                    a[j] = b[j];
                    while (i - 1 >= 0 && a[i - 1] <= a[i])i--;
                    while (j + 1 < n && a[j + 1] >= a[j])j++;

                    cout << i + 1 << " " << j + 1 << endl;
                    return;
                }
            }
        }
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
