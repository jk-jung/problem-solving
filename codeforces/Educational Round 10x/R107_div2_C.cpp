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
    int n, q;
    cin >> n >> q;
    vi pos(55);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (pos[x] == 0)pos[x] = i + 1;
    }

    while (q--) {
        int x;
        cin >> x;
        cout << pos[x] << ' ';
        for (int i = 0; i < 55; i++){
            if(pos[i] < pos[x])pos[i]++;
        }
        pos[x] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
