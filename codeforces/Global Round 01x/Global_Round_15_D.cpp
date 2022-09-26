#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

vector<int> v;
int n;

bool go(int i, int used, int r) {
    if (i == n) {
        for(int k=0;k<n;k++) {
            if(used >> k & 1) continue;
            if(v[k] == r) return true;
        }
        return false;
    }

    if (go(i + 1, used, r)) return true;
    if (go(i + 1, used | ( 1 << i), r + v[i])) return true;
    if (go(i + 1, used | ( 1 << i), r - v[i])) return true;
    return false;
}

void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i], v[i] = ab(v[i]);
    sort(v.begin(), v.end());

    cout << (go(0, 0, 0) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
