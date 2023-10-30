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

int A[6], B[6];

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: a)cin >> x, A[x]++;
    for (int &x: b)cin >> x, B[x]++;

    for (int i = 1; i <= 5; i++) {
        if ((A[i] + B[i]) % 2) {
            cout << -1 << endl;
            return;
        }
    }
    int r = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i == j)continue;
            if (A[i] > B[i] && A[j] < B[j]) {
                int aa = (A[i] + B[i]) / 2;
                int bb = (B[j] + A[j]) / 2;
                int x = min(A[i] - aa, B[j] - bb);
                A[i] -= x;
                B[i] += x;
                A[j] += x;
                B[j] -= x;
                r += x;
            }
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
