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
int n, k, q;
int s[200005];
int t[200005];

void solve() {
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s[a]++;
        s[b + 1]--;
    }

    for (int i = 1; i <= 200000; i++) {
        s[i] += s[i - 1];
        t[i] = t[i - 1];
        if (s[i] >= k)t[i]++;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << t[b] - t[a - 1] << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
