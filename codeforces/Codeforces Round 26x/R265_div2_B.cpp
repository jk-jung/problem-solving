
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
    deque<int> v(n);
    for (int &x: v)cin >> x;

    while (!v.empty() && v.front() == 0) v.pop_front();
    while (!v.empty() && v.back() == 0) v.pop_back();

    int r = 0;
    int last = 0;
    for (int x: v) {
        r += x == 1;
        if (last == 1 && x == 0) r++;
        last = x;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
