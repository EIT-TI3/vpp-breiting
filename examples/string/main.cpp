#include <iostream>
#include "strarray.h"

using namespace std;

int main() {
    StrArray s1;
    StrArray s2('a');
    StrArray s3('b', 20);
    std::cout << "s1: " << s1 << endl;
    std::cout << "s2: " << s2 << endl;
    std::cout << "s3: " << s3 << endl;
    return 0;
}
