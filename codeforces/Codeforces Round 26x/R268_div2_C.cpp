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
    if (n >= 24) {
        cout << "YES\n";
        cout << "1 - 2 = -1\n";
        cout << "4 - 3 = 1\n";
        cout << "1 + -1 = 0\n";
        for (int i = 5; i <= n; i++) {
            if (i == 24)continue;
            cout << "0 * " << i << " = 0\n";
        }
        cout << "24 + 0 = 24\n";
    } else if (n >= 8) {
        cout << "YES\n";
        cout << "3 * 8 = 24\n";
        cout << "1 - 2 = -1\n";
        cout << "6 - 5 = 1\n";
        cout << "1 + -1 = 0\n";
        cout << "4 * 0 = 0\n";
        cout << "7 * 0 = 0\n";
        for (int i = 9; i <= n; i++)
            cout << "0 * " << i << " = 0\n";
        cout << "24 + 0 = 24\n";
    } else if (n == 4) {
        cout << "YES\n";
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
    } else if (n == 5) {
        cout << "YES\n";
        cout << "5 - 3 = 2\n";
        cout << "2 * 4 = 8\n";
        cout << "1 + 2 = 3\n";
        cout << "8 * 3 = 24\n";
    } else if (n == 6) {
        cout << "YES\n";
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        cout << "6 - 5 = 1\n";
        cout << "24 * 1 = 24\n";
    } else if(n == 7){
        cout << "YES\n";
        cout << "5 - 3 = 2\n";
        cout << "2 * 4 = 8\n";
        cout << "1 + 2 = 3\n";
        cout << "8 * 3 = 24\n";
        cout << "7 - 6 = 1\n";
        cout << "24 * 1 = 24\n";
    }
    else cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
