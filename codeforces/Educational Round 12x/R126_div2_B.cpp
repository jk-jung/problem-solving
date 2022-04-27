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

int d[32768];

void solve() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    int x;
    cin >> x;

    q.push(x);
    d[x] = 0;
    while (q.size()) {
        int k = q.front();
        if (k == 0) break;
        q.pop();
        int x = (k + 1) % 32768;
        int y = (k * 2) % 32768;

        if (d[x] == -1)q.push(x), d[x] = d[k] + 1;
        if (d[y] == -1)q.push(y), d[y] = d[k] + 1;
    }


    cout << d[0] << " ";
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
