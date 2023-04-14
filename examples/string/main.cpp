#include <iostream>
#include "strarray.h"

using namespace std;

int main() {
    StrArray s1;
    StrArray s2('a');
    StrArray s3('b', 20);
    std::cout << "s1: " << s1.start << endl;
    std::cout << "s2: " << s2.start << endl;
    std::cout << "s3: " << s3.start << endl;
    return 0;
}
