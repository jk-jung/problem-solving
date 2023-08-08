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
    string s;
    cin >> n >> s;
    int st = 0, x = 0, y = 0, r = 0;
    for (char c: s) {
        if (c == 'U')y++;
        else if (c == 'D')y--;
        else if (c == 'L')x--;
        else x++;

        int nt = 0;
        if (x < y) nt = 1;
        else if (x > y) nt = -1;

        if (nt) {
            if (st != 0 && nt != st)r++;
            st = nt;
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
