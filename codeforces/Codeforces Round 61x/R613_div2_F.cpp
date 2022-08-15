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

const int N = 100000;
int a[N + 1], u[N + 1], cnt[N + 1];
vi d[N + 1];

void update(int k, int ck) {
    for (int x: d[k]) cnt[x] += ck;
}

int get_count(int x) {
    int r = 0;
    for (int i: d[x])r += cnt[i] * u[i];
    return r;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) d[j].push_back(i);
        if (i == 1) u[i] = 1;
        else if (i / d[i][1] % d[i][1] == 0) u[i] = 0;
        else u[i] = -u[i / d[i][1]];
    }

    int n;
    cin >> n;

    ll r = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x] = 1;
        r = max(r, (ll) x);
    }
    for (int g = 1; g <= N; g++) {
        stack<int> st;
        for (int i = N / g; i >= 1; i--) {
            if (!a[g * i]) continue;
            int c = get_count(i);
            while (c) {
                if (gcd(i, st.top()) == 1) {
                    r = max(r, (ll)g * i * st.top());
                    c--;
                }
                update(st.top(), -1);
                st.pop();
            }

            update(i, 1);
            st.push(i);
        }
        while (!st.empty()) {
            update(st.top(), -1);
            st.pop();
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
