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

int d[100005];

void solve() {
    for (int i = 2; i <= 500; i++) {
        d[i] = d[i - 1] + i - 1;
    }

    int n;
    cin >> n;
    string r;
    for (char x = 'a'; x <= 'z'; x++) {
        for (int i = 500; i >= 2; i--) {
            if (d[i] <= n) {
                n -= d[i];
                r += string(i, x);
                break;
            }
        }
    }
    if(r.empty())r = "a";
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
