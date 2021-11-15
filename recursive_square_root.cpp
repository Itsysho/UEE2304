#include <iostream>
#include <iomanip>
#include <cmath>

// pseudo code
// algorithm squareRoot
// if math.abs( ans^2 - num ) <= tol
//     return ans
// return squareRoot( num, ( ans^2 + num) / (2 * num ), tol )

double squareRoot( int num, double ans, double tol){
    if( fabs( ans * ans - num ) <= tol ) return ans;
    return squareRoot(num, ( ans * ans + num) / (2.0 * ans ), tol);
}

int main(int argc, const char * argv[]) {
    int n;
    while (std::cin >> n) {
        auto ans = squareRoot(n, 1, 0.01);
        std::cout << std::setprecision(2) << std::fixed << ans << std::endl;
    }
    return 0;
}
