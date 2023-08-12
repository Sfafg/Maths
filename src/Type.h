#pragma once

namespace Maths
{
    template<typename T, typename TOther>
    using TOp = typename std::conditional<std::is_integral<T>::value&& std::is_floating_point<TOther>::value, TOther, T>::type;
    template<typename T>
    using TFloat = typename std::conditional<sizeof(T) <= 4, float, typename std::conditional<sizeof(T) <= 8, double, long double>::type>::type;
}