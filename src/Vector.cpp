#define _SFAFG_MATHS_VECTOR_IMLPEMENTATION_
#include "Vector.h"
#include <ios>
namespace Maths
{
    double Magnitude(double* begin, double* end)
    {
        double sum = 0;
        for (double* i = begin; i < end; i++)sum += (*i) * (*i);

        return sum;
    }
}