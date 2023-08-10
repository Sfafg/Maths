#pragma once
#include <iosfwd>
#include <iostream>
namespace Maths
{
	template <unsigned int TSize, typename T> struct Vector_Components { T value[TSize]; };
#ifdef _SFAFG_MATHS_VECTOR_IMLPEMENTATION_
	template <typename T> struct Vector_Components<1, T> { union { T value[1]; struct { T x; }; }; };
	template <typename T> struct Vector_Components<2, T> { union { T value[2]; struct { T x, y; }; }; };
	template <typename T> struct Vector_Components<3, T> { union { T value[3]; struct { T x, y, z; }; }; };
	template <typename T> struct Vector_Components<4, T> { union { T value[4]; struct { T x, y, z, w; }; }; };
#endif
	extern double Magnitude(double* begin, double* end);


	template <unsigned int TSize, typename T>
	struct vec : public Vector_Components<TSize, T>
	{
	public:
		static constexpr unsigned int Size() { return TSize; }

	public:
		vec() {}
		vec(T v);
		vec(std::initializer_list<T> data);
		template <typename... OT>
		vec(OT... data)
		{
			constexpr unsigned int argumentCount = sizeof...(data);
			static_assert(argumentCount <= TSize);

			int j = 0;
			for (auto i : std::initializer_list<std::common_type_t<OT...>>{ data... }) this->value[j++] = (T) i;
			for (; j < TSize; j++) this->value[j] = 0;
		}
	public:
		double Magnitude();
		double Length();
		void Normalize();

		T* begin();
		T* end();
		const T* begin() const;
		const T* end() const;

	public:
		template <unsigned int OSize, typename OT>
		operator vec<OSize, OT>();

		T& operator =(const vec<TSize, T>& o);
		T& operator -();

		T& operator +=(const vec<TSize, T>& o);
		T& operator -=(const vec<TSize, T>& o);
		T& operator *=(const vec<TSize, T>& o);
		T& operator /=(const vec<TSize, T>& o);
		T& operator +(const vec<TSize, T>& o);
		T& operator -(const vec<TSize, T>& o);
		T& operator *(const vec<TSize, T>& o);
		T& operator /(const vec<TSize, T>& o);

		bool operator ==(const vec<TSize, T>& o) const;
		bool operator !=(const vec<TSize, T>& o) const;
		bool operator <(const vec<TSize, T>& o) const;
		bool operator <=(const vec<TSize, T>& o) const;
		bool operator >(const vec<TSize, T>& o) const;
		bool operator >=(const vec<TSize, T>& o) const;

		T& operator [](unsigned int index);
		const T& operator [] (unsigned int index) const;
	};
	template <unsigned int TSize, typename T> std::ostream& operator<<(std::ostream& os, const vec<TSize, T>& v);

	typedef vec<2, float> Vector2f;
	typedef vec<3, float> Vector3f;
	typedef vec<4, float> Vector4f;
	typedef vec<2, double> Vector2d;
	typedef vec<3, double> Vector3d;
	typedef vec<4, double> Vector4d;
	typedef vec<2, int> Vector2i;
	typedef vec<3, int> Vector3i;
	typedef vec<4, int> Vector4i;

	template <unsigned int TSize, typename T>
	vec<TSize, T>::vec(T v)
	{
		for (unsigned int i = 0; i < TSize; i++) this->value[i] = v;
	}
	template <unsigned int TSize, typename T>
	vec<TSize, T>::vec(std::initializer_list<T> data)
	{
		memcpy(&this->value, data.begin(), data.size() * sizeof(T));
	}

	template <unsigned int TSize, typename T>
	double vec<TSize, T>::Magnitude()
	{
		return Maths::Magnitude(&this->value[0], TSize);
	}

	template <unsigned int TSize, typename T>
	T& vec<TSize, T>::operator [](unsigned int index) { return this->value[index]; }
	template <unsigned int TSize, typename T>
	const T& vec<TSize, T>::operator [](unsigned int index) const { return this->value[index]; }

	template <unsigned int TSize, typename T>
	std::ostream& operator<<(std::ostream& os, const vec<TSize, T>& v)
	{
		os << "vec" << TSize << typeid(T).name()[0];
		os << '(';
		for (unsigned int i = 0; i < TSize - 1; i++)
		{
			os << v[i] << ", ";
		}
		os << v[TSize - 1];
		os << ')';

		return os;
	}
}