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

vi v = {1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1};
vi h = {1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1};

int n, k;

vi gen(vi &t, int x) {
    vi r;
    for (int i = x - 1, st = 0; i >= 0; i--) {
        st ^= t[i];
        r.pb(st);
    }
    reverse(r.begin(), r.end());
    r.pb(0);
    for (int i = x + 1, st = 0; i < n; i++) {
        st ^= t[i - 1];
        r.pb(st);
    }
    return r;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++)cout << v[j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++)cout << h[i] << " ";
        cout << endl;
    }

    int y = 0, x = 0;
    while (k--) {
        int val;
        cin >> val;

        vi yy = gen(h, y);
        vi xx = gen(v, x);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if ((yy[i] ^ xx[j]) == val) {
                    y = i;
                    x = j;
                }
            }
        cout << y + 1 <<" " << x + 1 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //  1 => 0, 1
    //  2 => 2, 3
    //  4 => 4, 5
    //  8 => 6, 7
    // 16 => 8, 9

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) h[i] = 2;
        else if (v[i] == 2) v[i] = 4, h[i] = 8;
        else if (v[i] == 4) v[i] = 16, h[i] = 32;
        else if (v[i] == 8) v[i] = 64, h[i] = 128;
        else if (v[i] == 16) v[i] = 256, h[i] = 512;
    }


    solve();
}
