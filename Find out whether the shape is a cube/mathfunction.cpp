#include <cstdio>
#include <cmath>
using namespace std;

bool is_cube(int volume, int side)
{
    if(volume <= 0 || side <= 0) return false;

    double volume_double = volume;
    double side_double = side;
    double cubic_root = cbrt(volume_double);
    double tolernce = 1e-9;


    if(abs(cubic_root - side_double) <= tolernce) return true;
    else return false;
}

/*bool is_cube(int volume, int side)
{
    return side > 0 && volume > 0 && side * side * side == volume;
}*/

// OR

/*bool is_cube(int volume, int side)
{
    return (volume > 0 || side > 0) * ((side * side * side) == volume);
}*/