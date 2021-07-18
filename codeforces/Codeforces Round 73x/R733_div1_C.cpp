#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int n;
int a[100005];
int b[100005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int A = 0;
    int B = 0;
    int pos = n / 4;
    int pos2 = pos;
    int r = 0;

    for (int i = pos; i < n; i++) {
        A += a[i];
        B += b[i];
    }

    while (A < B) {
        r ++ ;
        A += 100;
        n++;
        int after = n / 4;

        if(after != pos ){
            A -= a[pos];
            pos = after;
        }
        while (after < r + pos2 && pos2 >= 0) {
            pos2--;
            if(pos2 >= 0) {
                B += b[pos2];
            }
        }

    }
    cout << r << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
