#pragma once
#include <iostream>
#include <assert.h>
#include "Type.h"
#include "Maths.h"
#define TEMPLATE template <unsigned int TSize, typename T>
#define VEC vec<TSize,T>
namespace Maths
{

	// Used to get the x,y,z,w component aliases.
	TEMPLATE struct Vector_Components { T entries[TSize]; };
	TEMPLATE struct vec : public Vector_Components<TSize, T>
	{
		vec();
		explicit vec(T v);
		vec(T const (&data)[TSize]);
		vec(std::initializer_list<T> data);
		template <typename... TOther>
		vec(T v1, TOther... data);

	public:
		TFloat<T> Magnitude() const;
		TFloat<T> Length() const;
		void Normalize();
		VEC Normalized() const;
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

		VEC& operator =(const VEC& o);
		VEC& operator +=(const VEC& o);
		VEC& operator -=(const VEC& o);
		VEC& operator *=(const VEC& o);
		VEC& operator /=(const VEC& o);
		VEC& operator +=(const T& o);
		VEC& operator -=(const T& o);
		VEC& operator *=(const T& o);
		VEC& operator /=(const T& o);
		VEC operator -() const;
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
	template <unsigned int TSize, typename T, typename TOther> auto operator+(const TOther& s, const VEC& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator-(const TOther& s, const VEC& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator*(const TOther& s, const VEC& v);
	template <unsigned int TSize, typename T, typename TOther> auto operator/(const TOther& s, const VEC& v);
	TEMPLATE std::ostream& operator<<(std::ostream& os, const VEC& v);
	TEMPLATE std::istream& operator>>(std::istream& is, VEC& v);

	typedef vec<2, float> vec2;
	typedef vec<3, float> vec3;
	typedef vec<4, float> vec4;
	typedef vec<2, float> vec2f;
	typedef vec<3, float> vec3f;
	typedef vec<4, float> vec4f;
	typedef vec<2, double> vec2d;
	typedef vec<3, double> vec3d;
	typedef vec<4, double> vec4d;
	typedef vec<2, int> vec2i;
	typedef vec<3, int> vec3i;
	typedef vec<4, int> vec4i;

	namespace Vector
	{
		TEMPLATE TFloat<T> Distance(const VEC& a, const VEC& b);
		TEMPLATE TFloat<T> Length(const VEC& a);
		TEMPLATE VEC Normalized(const VEC& a);
		TEMPLATE VEC Round(const VEC& a);
		TEMPLATE VEC Ceil(const VEC& a);
		TEMPLATE VEC Floor(const VEC& a);
		TEMPLATE VEC Abs(const VEC& a);
		TEMPLATE VEC Sign(const VEC& a);
		TEMPLATE VEC Clamp(const VEC& a, T min, T max);
		TEMPLATE VEC Clamp(const VEC& a, const VEC& min, const VEC& max);
		TEMPLATE VEC Clamp(const VEC& a, std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE VEC Wrap(const VEC& a, T min, T max);
		TEMPLATE VEC Wrap(const VEC& a, const VEC& min, const VEC& max);
		TEMPLATE VEC Wrap(const VEC& a, std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE VEC Lerp(const VEC& a, const VEC& b, float k);
		TEMPLATE TFloat<T> Dot(const VEC& a, const VEC& b);
		template<typename T> vec<3, T> Cross(const vec<3, T>& a, const vec<3, T>& b);
		TEMPLATE VEC Reflect(const VEC& a, const VEC& normal);
		TEMPLATE TFloat<T> Angle(const VEC& a, const VEC& b);
		TEMPLATE VEC Random(T min, T max);
		TEMPLATE VEC Random(const VEC& min, const VEC& max);
		TEMPLATE VEC Random(std::initializer_list<vec<2, T>> componentWiseBounds);
		TEMPLATE VEC Unit();
	}

#pragma region // IMPLEMENTATION
	template <typename T> struct Vector_Components<1, T> { union { T entries[1]; struct { T x; }; }; };
	template <typename T> struct Vector_Components<2, T> { union { T entries[2]; struct { T x, y; }; }; };
	template <typename T> struct Vector_Components<3, T> { union { T entries[3]; struct { T x, y, z; }; }; };
	template <typename T> struct Vector_Components<4, T> { union { T entries[4]; struct { T x, y, z, w; }; }; };

	TEMPLATE VEC::vec() {}
	TEMPLATE VEC::vec(T v)
	{
		for (unsigned int i = 0; i < TSize; i++)
			this->entries[i] = v;
	}
	TEMPLATE VEC::vec(T const (&data)[TSize])
	{
		memcpy(begin(), &data[0], TSize * sizeof(T));
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
		for (auto i : std::initializer_list<std::common_type_t<TOther...>>{ data... }) this->entries[j++] = (T) i;
		for (; j < TSize; j++) this->entries[j] = 0;
	}


	TEMPLATE TFloat<T> VEC::Magnitude() const
	{
		TFloat<T> sum = 0;
		for (unsigned int i = 0; i < Size(); i++)sum += this->entries[i] * this->entries[i];
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
		for (unsigned int i = 0; i < Size(); i++)this->entries[i] /= length;
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
		return &this->entries[0];
	}
	TEMPLATE T* VEC::end()
	{
		return &this->entries[0] + Size();
	}
	TEMPLATE const T* VEC::begin() const
	{
		return &this->entries[0];
	}
	TEMPLATE const T* VEC::end() const
	{
		return &this->entries[0] + Size();
	}


	TEMPLATE template <typename TOther> VEC::operator vec<TSize, TOther>() const
	{
		vec<TSize, TOther> t;
		for (unsigned int i = 0; i < TSize; i++) t[i] = this->entries[i];

		return t;
	}
	TEMPLATE template <unsigned int OSize, typename TOther> VEC::operator vec<OSize, TOther>() const
	{
		vec<OSize, TOther> t;
		unsigned int i = 0;
		if constexpr (TSize < OSize)
		{
			for (i; i < TSize; i++) t[i] = this->entries[i];
			for (i; i < OSize; i++) t[i] = 0;
		}
		else
		{
			for (i; i < OSize; i++) t[i] = this->entries[i];
		}
		return t;
	}

	TEMPLATE VEC& VEC::operator =(const VEC& o)
	{
		for (unsigned int i = 0; i < Size(); i++)this->entries[i] = o[i];
		return *this;
	}
	TEMPLATE VEC& VEC::operator +=(const VEC& o)
	{
		for (unsigned int i = 0; i < Size(); i++)this->entries[i] += o[i];
		return *this;
	}
	TEMPLATE VEC& VEC::operator -=(const VEC& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] -= o[i];
		return *this;
	}
	TEMPLATE VEC& VEC::operator *=(const VEC& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] *= o[i];
		return *this;
	}
	TEMPLATE VEC& VEC::operator /=(const VEC& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] /= o[i];
		return *this;
	}
	TEMPLATE VEC& VEC::operator +=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] += o;
		return *this;
	}
	TEMPLATE VEC& VEC::operator -=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] -= o;
		return *this;
	}
	TEMPLATE VEC& VEC::operator *=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] *= o;
		return *this;
	}
	TEMPLATE VEC& VEC::operator /=(const T& o)
	{
		for (unsigned int i = 0; i < Size(); i++)
			this->entries[i] /= o;
		return *this;
	}
	TEMPLATE VEC VEC::operator -() const
	{
		VEC t = *this;
		for (unsigned int i = 0; i < Size(); i++)
			t[i] = -this->entries[i];
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
			if (this->entries[i] != o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator !=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if (this->entries[i] != o[i])
				return true;
		return false;
	}
	TEMPLATE template<typename TOther>bool VEC::operator <(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if (this->entries[i] >= o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator <=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if (this->entries[i] > o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator >(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if (this->entries[i] <= o[i])
				return false;
		return true;
	}
	TEMPLATE template<typename TOther>bool VEC::operator >=(const vec<TSize, TOther>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if (this->entries[i] < o[i])
				return false;
		return true;
	}

	TEMPLATE T& VEC::operator [](unsigned int index)
	{
		return this->entries[index];
	}
	TEMPLATE const T& VEC::operator [](unsigned int index) const
	{
		return this->entries[index];
	}


	template <unsigned int TSize, typename T, typename TOther> auto operator+(const TOther& s, const VEC& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s + t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator-(const TOther& s, const VEC& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s - t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator*(const TOther& s, const VEC& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s * t[i];
		return t;
	}
	template <unsigned int TSize, typename T, typename TOther> auto operator/(const TOther& s, const VEC& v)
	{
		vec<TSize, TOp<T, TOther>> t = v;
		for (unsigned int i = 0; i < TSize; i++)
			t[i] = s / t[i];
		return t;
	}
	TEMPLATE std::ostream& operator<<(std::ostream& os, const VEC& v)
	{

#ifdef COMPACT_IN_OUT
		for (unsigned int i = 0; i < v.Size() - 1; i++)
		{
			if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[i] << ',';
			else os << v[i] << ',';
		}
		if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[v.Size() - 1];
		else os << v[v.Size() - 1];
#else
		os << "vec" << v.Size();
		if constexpr (std::is_unsigned<T>::value) os << 'u' << typeid(typename std::make_signed<T>::type).name()[0];
		else os << typeid(T).name()[0];

		os << '(';
		for (unsigned int i = 0; i < v.Size() - 1; i++)
		{
			if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[i] << ", ";
			else os << v[i] << ", ";
		}
		if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) os << (int) v[v.Size() - 1];
		else os << v[v.Size() - 1];
		os << ')';

#endif
		return os;
	}
	TEMPLATE std::istream& operator>>(std::istream& is, VEC& v)
	{
#ifdef COMPACT_IN_OUT
		for (unsigned int i = 0; i < v.Size(); i++)
		{
			is >> v[i];
		}
#else
		while (true)
		{
			char c = is.get();
			if (is.eof()) return is;
			if (c == '(') break;
		}
		for (unsigned int i = 0; i < v.Size(); i++)
		{
			is >> v[i];
			is.get();
		}
#endif

		return is;
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
	TEMPLATE VEC Vector::Clamp(const VEC& a, std::initializer_list<vec<2, T>> componentWiseBounds)
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
	TEMPLATE VEC Vector::Wrap(const VEC& a, std::initializer_list<vec<2, T>> componentWiseBounds)
	{
		assert(componentWiseBounds.size() == TSize);
		auto t = a;
		for (unsigned int i = 0; i < a.Size(); i++)
		{
			t[i] = Maths::Wrap(a[i], componentWiseBounds.begin()[i].x, componentWiseBounds.begin()[i].y);
		}
		return t;
	}
	TEMPLATE VEC Vector::Lerp(const VEC& a, const VEC& b, float k)
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

#pragma endregion // IMPLEMENTATION
}
#undef TEMPLATE
#undef VEC