#pragma once
#include <type_traits>

namespace
{
	template <unsigned int TSize, typename T> struct Vector_Union { T value[TSize]; };
	template <typename T> struct Vector_Union<1, T> { union { T value[1]; struct { T x; }; }; };
	template <typename T> struct Vector_Union<2, T> { union { T value[2]; struct { T x, y; }; }; };
	template <typename T> struct Vector_Union<3, T> { union { T value[3]; struct { T x, y, z; }; }; };
	template <typename T> struct Vector_Union<4, T> { union { T value[4]; struct { T x, y, z, w; }; }; };
}

template <unsigned int TSize, typename T>
struct Vector : public Vector_Union<TSize, T>
{
public:
	Vector() {}
	Vector(std::initializer_list<T> data) { memcpy(&this->value, data.begin(), data.size() * sizeof(T)); }

public:
	double Magnitude()
	{
		double sum = 0;
		for (int i = 0; i < TSize; i++)
		{
			sum += this->value[i] * this->value[i];
		}

		return sum;
	}
};

typedef Vector<2, float> Vector2f;
typedef Vector<3, float> Vector3f;
typedef Vector<4, float> Vector4f;
typedef Vector<2, double> Vector2d;
typedef Vector<3, double> Vector3d;
typedef Vector<4, double> Vector4d;
typedef Vector<2, int> Vector2i;
typedef Vector<3, int> Vector3i;
typedef Vector<4, int> Vector4i;