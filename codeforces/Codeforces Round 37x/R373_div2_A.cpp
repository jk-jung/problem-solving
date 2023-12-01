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
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    if (n == 1) {
        if(v[0] == 15)
            cout << "DOWN";
        else if(v[0] == 0)
            cout << "UP";
        else
            cout << -1;
    }
    else {
        if(v[n-2] < v[n-1]) {
            cout << (v[n-1] == 15 ? "DOWN" : "UP");
        }else{
            cout << (v[n-1] == 0 ? "UP" : "DOWN");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
