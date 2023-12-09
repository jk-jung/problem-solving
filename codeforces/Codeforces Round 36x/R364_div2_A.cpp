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
    int s = 0;
    for (int &x: v)cin >> x, s += x;
    s /= (n / 2);
    for (int i = 0; i < n; i++) {
        if (v[i] == -1)continue;
        for (int j = i + 1; j < n; j++) {
            if (v[j] == -1)continue;
            if (v[i] + v[j] == s) {
                cout << i + 1 << " " << j + 1 << endl;
                v[i] = v[j] = -1;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
