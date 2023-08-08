#include <iostream>
#include <Vector.h>

int main()
{
    Vector4f vec({ 0,1,2,3 });
    std::cout << vec.Magnitude();
    return 0;
}