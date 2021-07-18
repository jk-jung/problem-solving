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

int v[200005];
int L[200005];
int R[200005];
int ck[200005];
int CK = 0;

bool bpm(int u) {
    int x = v[u];
    if (ck[x] == CK) return false;
    ck[x] = CK;

    if (R[x] < 0 || bpm(R[x])) {
        L[u] = x;
        R[x] = u;
        return true;
    }

    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i] = k - 1;
        L[i] = -1;
        R[i] = -1;
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        CK++;
        if (bpm(i)) r++;
    }

    vector<int> un, un2;
    CK++;
    for (int i = 0; i < n; i++) if (L[i] != -1)ck[L[i]] = CK;
    for (int i = 0; i < n; i++) if (ck[i] != CK) un.pb(i);
    for (int i = 0; i < n; i++) if (L[i] == -1)un2.pb(i);

    if (un.size() == 1 && un[0] == un2[0]) {
        int k = un[0];
        L[R[v[k]]] = -1;
        R[v[k]] = -1;
        CK++;
        bpm(k);
    }

    un.clear();
    un2.clear();
    for(int i=0;i<n;i++){
        if(R[i] == -1) {
            if(L[i] == -1) un2.pb(i);
            else un.pb(i);
        }
    }

    if(un2.size() == 1 && un.size() > 0) {
        int kk = un2[0];
        un2[0] = un[0];
        un[0] = kk;
    }

    cout << r << endl;
    for (int i = 0, k = 0, k2 = 0; i < n; i++) {
        if (L[i] == -1) {
            if (R[i] == -1) {
                k2 += 1;
                cout << un2[k2 % un2.size()] + 1 << " ";
            } else {
                cout << un[k++] + 1 << " ";
            }
        } else {
            cout << L[i] + 1 << " ";
        }
    }
    cout << endl;

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
