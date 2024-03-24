#include <ctime>
using namespace std;

// Returns a random number in the range 1 .. 10
// Note that I am using casting to convert one data type to another
inline int Random() {
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}