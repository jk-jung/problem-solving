#include <string.h>
#include <stdio.h>
#include <math.h>
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


map<int, int> ck;

void sub(int x) {
    if (--ck[x] == 0)ck.erase(x);
}

void add(int x) {
    ck[x]++;
}

void solve() {
    ck.clear();
    int n, d;
    cin >> n >> d;
    vi v(n + 5);
    vector<pi> seg;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        int dif = v[i] - v[i - 1] - 1;
        add(dif);
        seg.pb({-dif, i});
    }
    sort(seg.begin(), seg.end());

    int r = ck.begin()->F;
    for (int i = 1; i <= n; i++) {
        int a = v[i] - v[i - 1] - 1;
        int b = v[i + 1] - v[i] - 1;

        // case 1: in
        if (i < n) {
            int m = (v[i + 1] - v[i - 1] - 2) / 2;

            sub(a), sub(b), add(m);
            r = max(r, ck.begin()->F);
            add(a), add(b), sub(m);
        }

        // case 2: back
        if (i == n) {
            int m = d - v[i - 1] - 1;

            sub(a), add(m);
            r = max(r, ck.begin()->F);
            add(a), sub(m);
        } else if (v[n] != d) {
            int m1 = v[i + 1] - v[i - 1] - 1;
            int m2 = d - v[n] - 1;

            sub(a), sub(b), add(m1), add(m2);
            r = max(r, ck.begin()->F);
            add(a), add(b), sub(m1), sub(m2);
        }

        // case 3: mid
        if (i < n) {
            for (auto &k: seg) {
                if (k.S == i) continue;
                if (k.S == i + 1) continue;
                int x = k.S - 1;
                int y = k.S;

                int c = v[y] - v[x] - 1;
                int m1 = v[i + 1] - v[i - 1] - 1;
                m1 = min(m1, (c - 1) / 2);
                sub(a), sub(b), sub(c), add(m1);
                r = max(r, ck.begin()->F);
                add(a), add(b), add(c), sub(m1);
                break;
            }
        }
    }

    cout << r << endl;
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