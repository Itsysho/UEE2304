//
//  610001022_B.cpp
//  data_structure
//
//  Created by YISHIN HO on 2021/10/11.
//

#include <iostream>
#include <iomanip>

// pseudo code
// algorithm combination
// if (k = 0 || n = k) return 1
// if (n> k> 0) combination(n-1, k) + combination(n-1, k-1)

double combination( int n, int k){
    if(k == 0 || n == k) return 1;
    if(n > k && k > 0) return combination(n - 1, k) + combination(n - 1, k - 1);
    return 0;
}

int main(int argc, const char * argv[]) {
    int m;
    int n;
    while (std::cin >> m >> n) {
        auto ans = combination(m,n);
        std::cout << ans << std::endl;
    }
    return 0;
}
