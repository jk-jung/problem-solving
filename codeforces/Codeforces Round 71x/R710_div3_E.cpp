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

void make(vi &v, int flag = 0) {
    vi a(v.size());
    a[0] = v[0];
    set<int> ck;
    for (int i = 1; i <= v.size(); i++)ck.insert(i);
    ck.erase(a[0]);
    for (int i = 1; i < v.size(); i++) {

        if (v[i - 1] != v[i])
            a[i] = v[i];
        else {
            if (!flag) a[i] = *ck.begin();
            else {
                auto it = ck.lower_bound(v[i]);
                it --;
                a[i] = *it;
            }
        }

        ck.erase(a[i]);
    }

    for (int x: a)cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    make(v, 0);
    make(v, 1);
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
