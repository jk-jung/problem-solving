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

void solve() {
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        q.push_back(x);
    }
    vi r(n);
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        while (q.back() != i) {
            int x = q.front();
            q.pop_front();
            q.push_back(x);
            cnt ++;
        }
        q.pop_back();
        r[i - 1] = cnt;
    }
    for (int x: r)cout << x << " ";
    cout << endl;
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
