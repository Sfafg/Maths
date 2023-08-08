#include <iostream>
#include <Vector.h>

int main()
{
    Vector4f vec({ 0,1,2,3 });
    std::cout << vec.Magnitude();

    Vector<int(sizeof(float) > 2), float> v;
    std::cout << ' ' << sizeof(v.Magnitude());
    return 0;
}