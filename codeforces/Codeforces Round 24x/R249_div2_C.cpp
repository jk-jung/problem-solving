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

char a[3005][3005];
int b = 1500;

void solve() {
    int n;
    cin >> n;

    int t = 0;
    int my =b, My = b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        char c = i % 2 == 1 ? '\\' : '/';
        int dx = i % 2 == 0 ? 1 : -1;
        while(x--){
            a[b][t++] = c;
            my = min(my, b);
            My = max(My, b);
            b += dx;
        }
        b -= dx;
    }
    for(int i=My; i>=my; i--){
        for(int j=0;j<t;j++){
            cout << (a[i][j] ? a[i][j] : ' ');
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
