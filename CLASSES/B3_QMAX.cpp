#include <bits/stdc++.h>
using namespace std;

class QMAX {
private:
    int n;
    vector<int> f;
    vector<int> a;

    void thietlap(int x, int y, int d) {
        if (x == y) {
            f[d] = a[x];
        } else {
            thietlap(x, (x + y) / 2, 2 * d);
            thietlap((x + y) / 2 + 1, y, 2 * d + 1);
            f[d] = max(f[2 * d], f[2 * d + 1]);
        }
    }

    int tinh(int dau, int cuoi, int x, int y, int d) {
        if (dau > y || cuoi < x) {
            return 0;
        } else if (dau <= x && cuoi >= y) {
            return f[d];
        } else {
        	int a = tinh(dau, cuoi, x, (x + y) / 2, 2 * d);
        	int b = tinh(dau, cuoi, (x + y) / 2 + 1, y, 2 * d + 1);
            return max(a,b);
        }
    }

public:
    QMAX(const vector<int>& data) {
        n = data.size() - 1;
        f.resize(4 * n, 0);
        a = data;
        thietlap(1, n, 1);
    }

    int getResult(int dau, int cuoi) {
        return tinh(dau, cuoi, 1, n, 1);
    }
};

int main() {
    int n, m, p, x, y, u;
    cin >> n >> m;

    vector<int> a(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> u;
        a[x] += u;
        a[y + 1] -= u;
    }

    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i];
    }

    QMAX QMAX(a);

    cin >> p;

    for (int i = 1; i <= p; i++) {
        cin >> x >> y;
        int result = QMAX.getResult(x, y);
        cout << result << endl;
    }

    return 0;
}

