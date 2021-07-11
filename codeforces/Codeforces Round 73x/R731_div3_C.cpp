#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m), r;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)cin >> b[i];

    int A = 0, B = 0;
    while(A < a.size() || B < b.size()){
        bool aa = A < a.size();
        bool bb = B < b.size();
        if (aa && a[A] == 0) {
            r.pb(a[A++]);
            k ++;
        }
        else if(bb && b[B] == 0){
            r.pb(b[B++]);
            k++;
        }
        else if(aa && bb) {
            if(a[A] < b[B]){
                if (a[A] > k) {cout<< -1 << endl; return;}
                r.pb(a[A++]);
            }else {
                if (b[B] > k) {cout<< -1 << endl; return;}
                r.pb(b[B++]);
            }
        }
        else if(aa) {
            if (a[A] > k) {cout<< -1 << endl; return;}
            r.pb(a[A++]);
        }
        else if(bb) {
            if (b[B] > k) {cout<< -1 << endl; return;}
            r.pb(b[B++]);
        }
    }
    for(int i=0;i<r.size();i++){
        cout<< r[i] <<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
