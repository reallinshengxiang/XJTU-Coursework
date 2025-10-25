#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "3880",
        "10",
        "2400",
        "1340",
        "1499441040",
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
