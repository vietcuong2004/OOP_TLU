#include <iostream>
using namespace std;

class Print {
private:
    long L;
    long R;
    long S;
    long n;

public:
    Print(long n, long S);
    bool check(long, long, long);
    void print(long, long, long, long);
    void printResult();
};

Print::Print(long n, long S) : n(n), S(S) {
    R = (n + 1) * n / 2;
    L = 2 - R;
}

bool Print::check(long L, long R, long S) {
    return !(S > R || S < L || S == R - 2 || S == L + 2);
}

void Print::print(long L, long R, long n, long S) {
    if (n == 1) {
        cout << 1;
        return;
    }

    if (check(L + n, R - n, S - n)) {
        print(L + n, R - n, n - 1, S - n);
        cout << "+" << n;
    } else {
        print(L + n, R - n, n - 1, S + n);
        cout << "-" << n;
    }
}

void Print::printResult() {
    if ((S + R) % 2 || !check(L, R, S)) {
        cout << "Impossible";
    } else {
        print(L, R, n, S);
    }
}

int main() {
    long n, S;
    cin >> n >> S;

    Print printObj(n, S);
    printObj.printResult();

    return 0;
}
