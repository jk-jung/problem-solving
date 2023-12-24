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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int a = 0, b = 0, r = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (min(a, b) <= k && j < n) {
            if (s[j] == 'a')a++;
            else b++;
            j++;
        }
        if(min(a, b) > k)r = max(r, j - i - 1);
        else r = max(r, j - i);
        if (s[i] == 'a')a--;
        else b--;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
