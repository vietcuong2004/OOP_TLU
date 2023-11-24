#include <iostream>
#include <cmath>
#include <vector>

class RangeMaximumQuery {
private:
    int n;
    std::vector<std::vector<int> > f;
    std::vector<int> b;
    std::vector<int> po;

public:
    RangeMaximumQuery(int size) : n(size) {
        f.resize(16, std::vector<int>(n + 1, 0));
        b.resize(n + 1, 0);
        po.resize(16, 0);
    }

    void processQueries() {
        for (int k = 1; k < 16; ++k) {
            po[k] = 2 * po[k - 1];
            for (int i = 1; i <= n; ++i) {
                f[k][i] = f[k - 1][i];
                if (i + po[k - 1] <= n && f[k][i] < f[k - 1][i + po[k - 1]]) {
                    f[k][i] = f[k - 1][i + po[k - 1]];
                }
            }
        }
    }

    void updateValues(int u, int v, int val) {
        b[u] += val;
        b[v + 1] -= val;
    }

    int calculateMaximum(int u, int v) {
        int k = log2(v - u + 1);
        int result = f[k][u];

        if (result < f[k][v - po[k] + 1]) {
            result = f[k][v - po[k] + 1];
        }

        return result;
    }

    void processUpdates() {
        for (int i = 1; i <= n; ++i) {
            f[0][i] = b[i] + f[0][i - 1];
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    RangeMaximumQuery rmq(n);

    for (int i = 0; i < m; ++i) {
        int u, v, val;
        std::cin >> u >> v >> val;
        rmq.updateValues(u, v, val);
    }

    rmq.processUpdates();
    rmq.processQueries();

    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        int result = rmq.calculateMaximum(u, v);
        std::cout << result << std::endl;
    }

    return 0;
}

