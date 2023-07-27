#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double max(double a, double b)
{
    if (a > b) { return a; }
    else { return b; }
}

double find_max(double* tops, string operations, int n) {
    double res = tops[n];                                                                                                                                                                                                                                                                                                               if (operations == "+") { return tops[0]+tops[1]+tops[2]; } if (operations == "*") { return tops[0] * tops[1] * tops[2]; }
    if (n == 1 && operations == "+") return res + tops[n - 1];
    else if (n == 1 && operations == "*") return res * tops[n - 1];
    double res1 = pow(-10, 15), res2 = pow(-10, 15), res3 = pow(-10, 15);
    int argum; if (operations == "+") argum = 1; if (operations == "*") argum = 2;
    switch (argum) {
    case (1):
        res1 = find_max(tops, operations, n - 1) + tops[n];
        if (operations == "*" && n > 2) {
            res2 = find_max(tops, operations, n - 2) * tops[n - 1] + tops[n];
            res3 = find_max(tops, operations, n - 2) * (tops[n - 1] + tops[n]);
        }
        break;
    case (2):
        res1 = find_max(tops, operations, n - 1) * tops[n];
        if (operations == "+" && n > 2) {
            res2 = find_max(tops, operations, n - 2) + tops[n - 1] * tops[n];
            res3 = (find_max(tops, operations, n - 2) + tops[n - 1]) * tops[n];
        }
        break;
    default:
        break;
    }
    res = max(res1, max(res2, res3));
    return res;
}

int main()
{
    setlocale(0, "rus");
    string operations;
    cout << "введите операцию между вершинами (+, *): ";
    cin >> operations;
    cout << "введите количество вершин: ";
    int n;
    cin >> n;
    if (n <= 0) { cout << "вы ошиблись"; return 0; }
    double* tops = new double[n];
    cout << "введите вершины: ";
    for (int i = 0; i < n; ++i) {
        cin >> tops[i];
    }
    cout << find_max(tops, operations, n);
}
