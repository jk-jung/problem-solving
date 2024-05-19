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
    cin >> n;
    int a = 0, b = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x == 5)a++;
        else b++;
    }
    string r = "";
    for (int i = 0; i < a / 9; i++) {
        for (int j = 0; j < 9; j++)r += "5";
    }
    if (r.empty()) {
        cout << (b ? 0 : -1) << endl;
        return;
    }
    if(b == 0){
        cout << -1 <<endl;
        return;
    }
    r += string(b, '0');
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
