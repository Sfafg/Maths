#pragma once
#include <iostream>
#include <assert.h>
#include "Type.h"
#include "Maths.h"

namespace Maths
{
#define TEMPLATE template <unsigned int TSize, typename T>

	// Used to get the x,y,z,w component aliases.
	TEMPLATE struct Vector_Components { T value[TSize]; };
	TEMPLATE struct vec : public Vector_Components<TSize, T>
	{
		vec();
		explicit vec(T v);
		vec(std::initializer_list<T> data);
		template <typename... TOther>
		vec(T v1, TOther... data);

	public:
		TFloat<T> Magnitude() const;
		TFloat<T> Length() const;
		void Normalize();
		vec<TSize, T> Normalized() const;
		static constexpr unsigned int Size();
		T* begin();
		T* end();
		const T* begin() const;
		const T* end() const;

	public:
		template <typename TOther>
		operator vec<TSize, TOther>() const;
		template <unsigned int OSize, typename TOther>
		explicit operator vec<OSize, TOther>() const;

		vec<TSize, T>& operator =(const vec<TSize, T>& o);
		vec<TSize, T>& operator +=(const vec<TSize, T>& o);
		vec<TSize, T>& operator -=(const vec<TSize, T>& o);
		vec<TSize, T>& operator *=(const vec<TSize, T>& o);
		vec<TSize, T>& operator /=(const vec<TSize, T>& o);
		vec<TSize, T>& operator +=(const T& o);
		vec<TSize, T>& operator -=(const T& o);
		vec<TSize, T>& operator *=(const T& o);
		vec<TSize, T>& operator /=(const T& o);
		vec<TSize, T> operator -() const;
		template<typename TOther> auto operator+(const vec<TSize, TOther>& o) const;
		template<typename TOther> auto operator-(const vec<TSize, TOther>& o) const;
		template<typename TOther> auto operator*(const vec<TSize, TOther>& o) const;
		template<typename TOther> auto operator/(const vec<TSize, TOther>& o) const;
		template<typename TOther> auto operator+(const TOther& o) const;
		template<typename TOther> auto operator-(const TOther& o) const;
		template<typename TOther> auto operator*(const TOther& o) const;
		template<typename TOther> auto operator/(const TOther& o) const;
		template<typename TOther> bool operator ==(const vec<TSize, TOther>& o) const;
		template<typename TOther> bool operator !=(const vec<TSize, TOther>& o) const;
		template<typename TOther> bool operator <(const vec<TSize, TOther>& o) const;
		template<typename TOther> bool operator <=(const vec<TSize, TOther>& o) const;
		template<typename TOther> bool operator >(const vec<TSize, TOther>& o) const;
		template<typename TOther> bool operator >=(const vec<TSize, TOther>& o) const;

		T& operator [](unsigned int index);
		const T& operator [] (unsigned int index) const;

	private:
		template<typename OT>
		struct OperatorReturnType { using type = typename std::conditional<std::is_integral<T>::value&& std::is_floating_point<OT>::value, OT, T>::type; };
	};
	template <unsigned int TSize, typename T, typename TOther> auto operator+(const TOther& s, const vec<TSize, T>& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator-(const TOther& s, const vec<TSize, T>& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator*(const TOther& s, const vec<TSize, T>& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator/(const TOther& s, const vec<TSize, T>& v);
	TEMPLATE std::ostream& operator<<(std::ostream& os, const vec<TSize, T>& v);

	namespace Vector
	{
		TEMPLATE TFloat<T> Distance(const vec<TSize, T>& a, const vec<TSize, T>& b);
		TEMPLATE TFloat<T> Length(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Normalized(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Round(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Ceil(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Floor(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Abs(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Sign(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Clamp(const vec<TSize, T>& a, T min, T max);
		TEMPLATE vec<TSize, T> Clamp(const vec<TSize, T>& a, const vec<TSize, T>& min, const vec<TSize, T>& max);
		TEMPLATE vec<TSize, T> Clamp(const vec<TSize, T>& a, std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE vec<TSize, T> Wrap(const vec<TSize, T>& a, T min, T max);
		TEMPLATE vec<TSize, T> Wrap(const vec<TSize, T>& a, const vec<TSize, T>& min, const vec<TSize, T>& max);
		TEMPLATE vec<TSize, T> Wrap(const vec<TSize, T>& a, std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE vec<TSize, T> Lerp(const vec<TSize, T>& a, const vec<TSize, T>& b, float k);
		TEMPLATE TFloat<T> Dot(const vec<TSize, T>& a, const vec<TSize, T>& b);
		template<typename T> vec<3, T> Cross(const vec<3, T>& a, const vec<3, T>& b);
		TEMPLATE vec<TSize, T> Reflect(const vec<TSize, T>& a, const vec<TSize, T>& normal);
		TEMPLATE TFloat<T> Angle(const vec<TSize, T>& a, const vec<TSize, T>& b);
		TEMPLATE vec<TSize, T> Random(T min, T max);
		TEMPLATE vec<TSize, T> Random(const vec<TSize, T>& min, const vec<TSize, T>& max);
		TEMPLATE vec<TSize, T> Random(std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE vec<TSize, T> Unit();
	}
	typedef vec<2, float> vec2f;
	typedef vec<3, float> vec3f;
	typedef vec<4, float> vec4f;
	typedef vec<2, double> vec2d;
	typedef vec<3, double> vec3d;
	typedef vec<4, double> vec4d;
	typedef vec<2, int> vec2i;
	typedef vec<3, int> vec3i;
	typedef vec<4, int> vec4i;

#pragma region // IMPLEMENTATION
	template <typename T> struct Vector_Components<1, T> { union { T value[1]; struct { T x; }; }; };
	template <typename T> struct Vector_Components<2, T> { union { T value[2]; struct { T x, y; }; }; };
	template <typename T> struct Vector_Components<3, T> { union { T value[3]; struct { T x, y, z; }; }; };
	template <typename T> struct Vector_Components<4, T> { union { T value[4]; struct { T x, y, z, w; }; }; };

#define VEC vec<TSize, T>

	TEMPLATE VEC::vec()
	{
		for (unsigned int i = 0; i < TSize; i++) this->value[i] = 0;
	}
	TEMPLATE VEC::vec(T v)
	{
		for (unsigned int i = 0; i < TSize; i++)
			this->value[i] = v;
	}
	TEMPLATE VEC::vec(std::initializer_list<T> data)
	{
		assert(("Too many arguments in vector constructor!", data.size() <= TSize));
		memcpy(begin(), data.begin(), data.size() * sizeof(T));
	}
	TEMPLATE template <typename... TOther> VEC::vec(T v1, TOther... data)
	{
		constexpr unsigned int argumentCount = sizeof...(data);
		static_assert(argumentCount - 1 <= TSize, "Too many arguments in vector constructor!");
		(*this)[0] = v1;
		unsigned int j = 1;
		for (auto i : std::initializer_list<std::common_type_t<TOther...>>{ data... }) (*this)[j++] = (T) i;
		for (; j < TSize; j++) (*this)[j] = 0;
	}


	TEMPLATE TFloat<T> VEC::Magnitude() const
	{
		TFloat<T> sum = 0;
		for (unsigned int i = 0; i < Size(); i++)sum += (*this)[i] * (*this)[i];
		return sum;
	}
	TEMPLATE TFloat<T> VEC::Length() const
	{
		return Maths::Sqrt(Magnitude());
	}
	TEMPLATE void VEC::Normalize()
	{
		TFloat<T> length = Length();
		if (length == 0) return;
		for (unsigned int i = 0; i < Size(); i++)(*this)[i] /= length;
	}
	TEMPLATE VEC VEC::Normalized() const
	{
		auto t = *this;
		t.Normalize();
		return t;
	}
	TEMPLATE constexpr unsigned int VEC::Size()
	{
		return TSize;
	}
	TEMPLATE T* VEC::begin()
	{
		return &this->value[0];
	}
	TEMPLATE T* VEC::end()
	{
		return &this->value[0] + Size();
	}
	TEMPLATE const T* VEC::begin() const
	{
		return &this->value[0];
	}
	TEMPLATE const T* VEC::end() const
	{
		return &this->value[0] + Size();
	}


	TEMPLATE template <typename TOther> VEC::operator vec<TSize, TOther>() const
	{
		vec<TSize, TOther> t;
		for (unsigned int i = 0; i < TSize; i++) t[i] = (*this)[i];

		return t;
	}
	TEMPLATE template <unsigned int OSize, typename TOther> VEC::operator vec<OSize, TOther>() const
	{
		vec<OSize, TOther> t;
		unsigned int i = 0;
		if constexpr (TSize < OSize)
		{
			for (i; i < TSize; i++) t[i] = (*this)[i];
			for (i; i < OSize; i++) t[i] = 0;
		}
		else
		{
			for (i; i < OSize; i++) t[i] = (*this)[i];
		}
		return t;
	}

	TEMPLATE vec<TSize, T>& VEC::operator =(const vec<TSize, T>& o)
	{
		for (unsigned int i = 0; i < Size(); i++)(*this)[i] = o[i];
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator +=(const vec<TSize, T>& o)
	{
		for (unsigned int i = 0; i < Size(); i++)(*this)[i] += o[i];
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator -=(const vec<TSize, T>& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] -= o[i];
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator *=(const vec<TSize, T>& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] *= o[i];
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator /=(const vec<TSize, T>& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] /= o[i];
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator +=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] += o;
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator -=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] -= o;
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator *=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] *= o;
		return *this;
	}
	TEMPLATE vec<TSize, T>& VEC::operator /=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			(*this)[i] /= o;
		return *this;
	}
	TEMPLATE vec<TSize, T> VEC::operator -() const
	{
		vec<TSize, T> t = *this;
		for (unsigned int i = 0; i < Size(); i++)
			t[i] = -(*this)[i];
		return t;
	}
	TEMPLATE template<typename TOther> auto VEC::operator +(const vec<TSize, TOther>& o)const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t += o;
		return t;
	}
	TEMPLATE template<typename TOther> auto VEC::operator -(const vec<TSize, TOther>& o)const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t -= o;
		return t;
	}
	TEMPLATE template<typename TOther> auto VEC::operator *(const vec<TSize, TOther>& o)const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t *= o;
		return t;
	}
	TEMPLATE template<typename TOther> auto VEC::operator /(const vec<TSize, TOther>& o)const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t /= o;
		return t;
	}
	TEMPLATE template<typename TOther> auto  VEC::operator +(const TOther& o) const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t += o;
		return t;
	}
	TEMPLATE template<typename TOther> auto  VEC::operator -(const TOther& o) const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t -= o;
		return t;
	}
	TEMPLATE template<typename TOther> auto  VEC::operator *(const TOther& o) const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t *= o;
		return t;
	}
	TEMPLATE template<typename TOther> auto  VEC::operator /(const TOther& o) const
	{
		vec<TSize, TOp<T, TOther>> t = *this;
		t /= o;
		return t;
	}
	TEMPLATE template<typename TOther>bool VEC::operator ==(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] != o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator !=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] != o[i])
				return true;
		return false;
	}
	TEMPLATE template<typename TOther>bool VEC::operator <(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] >= o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator <=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] > o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator >(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] <= o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator >=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] < o[i])
				return false;
		return true;
	}

	TEMPLATE T& VEC::operator [](unsigned int index)
	{
		return this->value[index];
	}
	TEMPLATE const T& VEC::operator [](unsigned int index) const
	{
		return this->value[index];
	}


	template <unsigned int TSize, typename T, typename TOther> auto operator+(const TOther& s, const vec<TSize, T>& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s + t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator-(const TOther& s, const vec<TSize, T>& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s - t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator*(const TOther& s, const vec<TSize, T>& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s * t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator/(const TOther& s, const vec<TSize, T>& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s / t[i];
		return t;
	}
	TEMPLATE std::ostream& operator<<(std::ostream& os, const VEC& v)
	{
		os << "vec" << v.Size();
		if constexpr (std::is_unsigned<T>::value) os << 'u' << typeid(typename std::make_signed<T>::type).name()[0];
		else os << typeid(T).name()[0];

		os << '(';
		for (unsigned int i = 0; i < v.Size() - 1; i++)
		{
			if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[i] << ",";
			else os << v[i] << ", ";
		}
		if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[v.Size() - 1];
		else os << v[v.Size() - 1];
		os << ')';

		return os;
	}

	TEMPLATE TFloat<T> Vector::Distance(const VEC& a, const VEC& b)
	{
		return (a - b).Length();
	}
	TEMPLATE TFloat<T> Vector::Length(const VEC& a)
	{
		return a.Length();
	}
	TEMPLATE VEC Vector::Normalized(const VEC& a)
	{
		auto t = a;
		t.Normalize();
		return t;
	}
	TEMPLATE VEC Vector::Round(const VEC& a)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Round(a[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Ceil(const VEC& a)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Ceil(a[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Floor(const VEC& a)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Floor(a[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Abs(const VEC& a)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Abs(a[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Sign(const VEC& a)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Sign(a[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Clamp(const VEC& a, T min, T max)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Clamp(a[i], min, max);
		}
		return t;
	}
	TEMPLATE VEC Vector::Clamp(const VEC& a, const VEC& min, const VEC& max)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Clamp(a[i], min[i], max[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Clamp(const vec<TSize, T>& a, std::initializer_list<vec<2, T>> componentWiseBounds)
	{
		assert(componentWiseBounds.size() == TSize);
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Clamp(a[i], componentWiseBounds.begin()[i].x, componentWiseBounds.begin()[i].y);
		}
		return t;
	}
	TEMPLATE VEC Vector::Wrap(const VEC& a, T min, T max)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Wrap(a[i], min, max);
		}
		return t;
	}
	TEMPLATE VEC Vector::Wrap(const VEC& a, const VEC& min, const VEC& max)
	{
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Wrap(a[i], min[i], max[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Wrap(const vec<TSize, T>& a, std::initializer_list<vec<2, T>> componentWiseBounds)
	{
		assert(componentWiseBounds.size() == TSize);
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Wrap(a[i], componentWiseBounds.begin()[i].x, componentWiseBounds.begin()[i].y);
		}
		return t;
	}
	TEMPLATE VEC Vector::Lerp(const VEC& a, const vec<TSize, T>& b, float k)
	{
		return a * k + b * (1.0f - k);
	}
	TEMPLATE TFloat<T> Vector::Dot(const VEC& a, const VEC& b)
	{
		TFloat<T> sum = 0;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			sum += a[i] * b[i];
		}
		return sum;
	}
	template <typename T> vec<3, T> Vector::Cross(const vec<3, T>& a, const vec<3, T>& b)
	{
		return { (a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x) };
	}
	TEMPLATE VEC Vector::Reflect(const VEC& a, const VEC& normal)
	{
		return a - normal * Dot(a, normal) * 2.0f;
	}
	TEMPLATE TFloat<T> Vector::Angle(const VEC& a, const VEC& b)
	{
		return Maths::Acos(Dot(a, b) / (a.Length() * b.Length()));
	}
	TEMPLATE VEC Vector::Random(T min, T max)
	{
		auto t = VEC();
		for (unsigned int i = 0; i < TSize; i++)
		{
			t[i] = Maths::Random(min, max);
		}
		return t;
	}
	TEMPLATE VEC Vector::Random(const VEC& min, const VEC& max)
	{
		auto t = VEC();
		for (unsigned int i = 0; i < TSize; i++)
		{
			t[i] = Maths::Random(min[i], max[i]);
		}
		return t;
	}
	TEMPLATE VEC Vector::Random(std::initializer_list<vec<2, T>> componentWiseBounds)
	{
		assert(componentWiseBounds.size() == TSize);
		auto t = VEC();
		for (unsigned int i = 0; i < TSize; i++)
		{
			t[i] = Maths::Random(componentWiseBounds.begin()[i].x, componentWiseBounds.begin()[i].y);
		}
		return t;
	}
	TEMPLATE VEC Vector::Unit()
	{
		if constexpr (TSize <= 4)
		{
			// Rejection Sampling.
			while (true)
			{
				VEC candidate = Vector::Random<TSize, T>(-1, 1);
				if (candidate.Magnitude() <= 1) return candidate.Normalized();
			}
		}
		else
		{
			// Use standard normal distribution to get uniformally distributed vectors.
			VEC t;
			for (unsigned int i = 0; i < TSize; i++)
			{
				t[i] = Maths::NormalDist(0.0f, 1.0f);
			}
			t.Normalize();
			return t;
		}
	}

#undef TEMPLATE
#undef TOp
#undef TFloat
#undef VEC
#pragma endregion // IMPLEMENTATION
}