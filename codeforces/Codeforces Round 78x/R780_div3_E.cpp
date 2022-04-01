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
    int n, m = 0;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char x: s[i])
            if (x == '1') m++;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        deque<int> q;
        int y = i, cnt = 0;
        for (int j = 0; j < n * 2; j++) {
            int x = s[y][j % n] - '0';
            q.push_back(x);
            if (x == 1)cnt++;
            if (q.size() > n) {
                if (q.front() == 1)cnt--;
                q.pop_front();
            }
            r = max(r, cnt);

            y = (y + 1) % n;
        }
    }

    cout << (m + n - r - r) << endl;
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
