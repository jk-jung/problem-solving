#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

class SegmentTree {
public:
    vector<int> d;
    int max_n, size;

    void init(int _max_n) {
        max_n = _max_n;
        for (size = 1; size < max_n; size *= 2);
        d.resize(size * 2 + 5, -1);
    }

    int search(int kth) {
        return search(kth, 0, 1, max_n);
    }

    int search(int kth, int k, int l, int r) {
        int rst;
        if (l == r) {
            rst = r;
        } else {
            int m = (l + r) / 2;
            int ll = k * 2 + 1, rr = k * 2 + 2;
            int sum_l = get_value(ll, l, m);
            int zero_l = m - l + 1 - sum_l;
            d[rr] = get_value(k, l, r) - sum_l;

            if (kth <= zero_l) {
                rst = search(kth, ll, l, m);
            } else {
                rst = search(kth - zero_l, rr, m + 1, r);
            }
        }

        d[k]++;
        return rst;
    }

    int get_value(int k, int l, int r) {
        if (d[k] == -1) {
            cout << "? " << l << " " << r << endl;
            cin >> d[k];
        }
        return d[k];
    }
};


void solve() {
    int n, t;
    cin >> n >> t;
    SegmentTree seg;
    seg.init(n);

    while(t--){
        int k;
        cin >> k;

        int r = seg.search(k);
        cout << "! " << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
