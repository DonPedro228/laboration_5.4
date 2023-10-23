#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N)
{
    double P = 1.0;
    for (int K = N; K <= 25; K++)
    {
        P *= sqrt(1 + (N * 1.00 / K * 1.00));
    }
    return P;
}
double P1(const int N, const int K, double t)
{
    t = t * sqrt(1 + (N * 1.00 / K * 1.00));
    if (K <= N)
        return t;
    else
        return P1(N, K-1, t);
}
double P2(const int N, const int K)
{
    if (K < N)
        return 1.00;
    else
        return sqrt(1 + (N * 1.00 / K * 1.00)) * P2(N, K - 1);
}
double P3(const int N, const int K)
{
    if (K > 25)
        return 1.00;
    else
        return sqrt(1 + (N * 1.00 / K * 1.00)) * P3(N, K + 1);
}
double P4(const int N, const int K, double t)
{
    t = t * sqrt(1 + (N * 1.00 / K * 1.00));
    if (K >= 25)
        return t;
    else 
        return P4(N, K + 1, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec down --) P1 = " << P1(N, 25, 1.00) << endl;
    cout << "(rec up --) P2 = " << P2(N, 25) << endl;
    cout << "(rec up ++) P3 = " << P3(N, N) << endl;
    cout << "(rec down ++) P4 = " << P4(N, N, 1.00) << endl;
    return 0;
}
