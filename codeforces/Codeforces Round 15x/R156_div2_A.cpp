#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    vi r(3);
    cin >> n;
    int m = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        r[i % 3] += x;
        m = max(m, r[i % 3]);
    }
    for(int i=0;i<3;i++){
        if(r[i] == m) {
            if(i == 0)cout << "chest";
            if(i == 1)cout << "biceps";
            if(i == 2)cout << "back";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
