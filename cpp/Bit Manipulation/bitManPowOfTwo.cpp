#include <iostream>
using namespace std;
bool powOfTwo(int n){
    return (n && !(n & n - 1));
}
int main(){
    cout << powOfTwo(16) << endl;
    return 0;
}