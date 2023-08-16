#include <iostream>
#include <Vector.h>
#include <Maths.h>

using namespace Maths;
int main()
{
    if (sizeof(vec2f(1, 1).Magnitude()) != sizeof(float)) return __LINE__;
    if (sizeof(vec<2, long long int>(1, 1).Magnitude()) != sizeof(double)) return __LINE__;
    if (vec2f(1, 2).Magnitude() != 5) return __LINE__;
    if (vec2f(1, 2).Length() != Maths::Sqrt(5)) return __LINE__;

    if (vec2f(1, 2).Normalized() != vec2f(0.4472135955f, 0.894427191f)) return __LINE__;

    if (vec2f(1, 1) != vec2i(1, 1)) return __LINE__;
    if (vec2f(1, 1) != (vec2f) vec4i(1, 1, 1, 1)) return __LINE__;
    if (vec4f(1, 1, 0, 0) != (vec4f) vec2i(1, 1)) return __LINE__;

    vec2f v = vec2f(1, 2);
    if (v != vec2f(1, 2)) return __LINE__;
    v += vec2f(2, 2);
    if (v != vec2f(3, 4)) return __LINE__;
    v -= vec2f(2, 2);
    if (v != vec2f(1, 2)) return __LINE__;
    v *= vec2f(2, 2);
    if (v != vec2f(2, 4)) return __LINE__;
    v /= vec2f(2, 2);
    if (v != vec2f(1, 2)) return __LINE__;
    v += 1;
    if (v != vec2f(2, 3)) return __LINE__;
    v -= 1;
    if (v != vec2f(1, 2)) return __LINE__;
    v *= 2;
    if (v != vec2f(2, 4)) return __LINE__;
    v /= 2;
    if (v != vec2f(1, 2)) return __LINE__;
    if (-v != vec2f(-1, -2)) return __LINE__;
    if (vec2f(1, 1) < vec2f(0, 0)) return __LINE__;
    if (vec2f(1, 1) <= vec2f(0, 1)) return __LINE__;
    if (vec2f(1, 1) > vec2f(2, 2)) return __LINE__;
    if (vec2f(1, 1) >= vec2f(2, 1)) return __LINE__;

    if (Vector::Distance(vec2f(1, 0), vec2f(0, 0)) != 1) return __LINE__;
    if (Vector::Length(vec2f(1, 0)) != 1) return __LINE__;
    if (Vector::Normalized(vec2f(1, 0)) != vec2f(1, 0)) return __LINE__;
    if (Vector::Round(vec2f(0.5f, 0.1f)) != vec2f(1, 0)) return __LINE__;
    if (Vector::Ceil(vec2f(0.5f, 0.1f)) != vec2f(1, 1)) return __LINE__;
    if (Vector::Floor(vec2f(0.5f, 0.1f)) != vec2f(0, 0)) return __LINE__;
    if (Vector::Abs(vec2f(-0.5f, 0.1f)) != vec2f(0.5f, 0.1f)) return __LINE__;
    if (Vector::Sign(vec2f(-0.5f, 0.1f)) != vec2f(-1, 1)) return __LINE__;
    if (Vector::Clamp(vec2f(-0.5f, 0.1f), 0.0f, 1.0f) != vec2f(0, 0.1f)) return __LINE__;
    if (Vector::Clamp(vec2f(-0.5f, 0.1f), vec2f(0, 0), vec2f(1, 1)) != vec2f(0, 0.1f)) return __LINE__;
    if (Vector::Clamp(vec2f(-0.5f, 0.1f), { vec2f(0, 1), vec2f(0, 1) }) != vec2f(0, 0.1f)) return __LINE__;
    if (Vector::Wrap(vec2f(-0.5f, 0.1f), 0.0f, 1.0f) != vec2f(0.5f, 0.1f)) return __LINE__;
    if (Vector::Wrap(vec2f(-0.5f, 0.1f), vec2f(0, 0), vec2f(1, 1)) != vec2f(0.5f, 0.1f)) return __LINE__;
    if (Vector::Wrap(vec2f(-0.5f, 0.1f), { vec2f(0, 1), vec2f(0, 1) }) != vec2f(0.5f, 0.1f)) return __LINE__;
    if (Vector::Lerp(vec2f(0, 0), vec2f(1, 1), 0.5f) != vec2f(0.5f, 0.5f)) return __LINE__;
    if (Vector::Dot(vec2f(0, 1), vec2f(1, 0)) != 0) return __LINE__;
    if (Vector::Cross(vec3f(1, 0, 0), vec3f(0, 1, 0)) != vec3f(0, 0, 1)) return __LINE__;
    if (Vector::Reflect(vec2f(1, 1), vec2f(0, 1)) != vec2f(1, -1)) return __LINE__;
    if (Maths::Round(Maths::Degrees(Vector::Angle(vec2f(0, 1), vec2f(1, 0)))) != 90) return __LINE__;

    vec2f lastR;
    for (int i = 0; i < 1000; i++)
    {
        vec2f r = Vector::Random<2, float>(0, 1);
        if (r > vec2f(1, 1) || r < vec2f(0, 0)) return __LINE__;
        if (lastR == r) return  __LINE__;
        lastR = r;
    }
    for (int i = 0; i < 1000; i++)
    {
        vec2f r = Vector::Random<2, float>(vec2f(0, 0), vec2f(1, 1));
        if (r > vec2f(1, 1) || r < vec2f(0, 0)) return __LINE__;
        if (lastR == r) return  __LINE__;
        lastR = r;
    }
    for (int i = 0; i < 1000; i++)
    {
        vec2f r = Vector::Random<2, float>({ vec2f(0, 1), vec2f(0, 1) });
        if (r > vec2f(1, 1) || r < vec2f(0, 0)) return __LINE__;
        if (lastR == r) return  __LINE__;
        lastR = r;
    }
    for (int i = 0; i < 1000; i++)
    {
        vec2f r = Vector::Unit<2, float>();
        if (r.Magnitude() > 1.0001) return __LINE__;
        if (lastR == r) return  __LINE__;
        lastR = r;
    }
    vec<6, float> lastR1;
    for (int i = 0; i < 1000; i++)
    {
        vec<6, float> r = Vector::Unit<6, float>();
        if (r.Magnitude() > 1.0001) return __LINE__;
        if (lastR1 == r) return  __LINE__;
        lastR1 = r;
    }

    return 0;
}