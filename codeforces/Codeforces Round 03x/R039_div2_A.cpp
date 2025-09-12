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
    int x, y;
    cin >> x >> y;
    int z = x * x + y * y;
    int zz = sqrt(double(z)) + 1e-9;
    if(zz * zz == z || x == 0 || y == 0){
        cout << "black";
        return;
    }
    if(zz % 2){
        if(x * y > 0)cout << "white";
        else cout << "black";
    }else {
        if(x * y > 0)cout << "black";
        else cout << "white";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
