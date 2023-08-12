#pragma once
#include <iostream>
#include "Maths.h"
namespace Maths
{
#define TEMPLATE template <unsigned int TSize, typename T>
	TEMPLATE struct Vector_Components { T value[TSize]; };
	TEMPLATE struct vec : public Vector_Components<TSize, T>
	{
		vec();
		explicit vec(T v);
		vec(std::initializer_list<T> data);
		template <typename... OT>
		vec(T v1, OT... data);

	public:
		auto Magnitude() const;
		auto Length() const;
		void Normalize();

		static constexpr unsigned int Size();
		T* begin();
		T* end();
		const T* begin() const;
		const T* end() const;
	public:
		template <typename OT>
		operator vec<TSize, OT>() const;
		template <unsigned int OSize, typename OT>
		explicit operator vec<OSize, OT>() const;

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
		template<typename OT> auto operator +(const vec<TSize, OT>& o) const;
		template<typename OT> auto operator -(const vec<TSize, OT>& o) const;
		template<typename OT> auto operator *(const vec<TSize, OT>& o) const;
		template<typename OT> auto operator /(const vec<TSize, OT>& o) const;
		template<typename OT> auto operator +(const OT& o) const;
		template<typename OT> auto operator -(const OT& o) const;
		template<typename OT> auto operator *(const OT& o) const;
		template<typename OT> auto operator /(const OT& o) const;

		bool operator ==(const vec<TSize, T>& o) const;
		bool operator !=(const vec<TSize, T>& o) const;
		bool operator <(const vec<TSize, T>& o) const;
		bool operator <=(const vec<TSize, T>& o) const;
		bool operator >(const vec<TSize, T>& o) const;
		bool operator >=(const vec<TSize, T>& o) const;

		T& operator [](unsigned int index);
		const T& operator [] (unsigned int index) const;

	private:
		template<typename OT>
		struct OperatorReturnType { using type = typename std::conditional<std::is_integral<T>::value&& std::is_floating_point<OT>::value, OT, T>::type; };
	};
	TEMPLATE std::ostream& operator<<(std::ostream& os, const vec<TSize, T>& v);

	namespace Vector
	{
		TEMPLATE auto Distance(const vec<TSize, T>& a, const vec<TSize, T>& b);
		TEMPLATE auto Length(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Normalized(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Round(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Ceil(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Abs(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Sign(const vec<TSize, T>& a);
		TEMPLATE vec<TSize, T> Clamp(const vec<TSize, T>& a, T min, T max);
		TEMPLATE vec<TSize, T> Clamp(const vec<TSize, T>& a, const vec<TSize, T>& min, const vec<TSize, T>& max);
		TEMPLATE vec<TSize, T> Wrap(const vec<TSize, T>& a, T min, T max);
		TEMPLATE vec<TSize, T> Wrap(const vec<TSize, T>& a, const vec<TSize, T>& min, const vec<TSize, T>& max);
		TEMPLATE vec<TSize, T> Lerp(const vec<TSize, T>& a, const vec<TSize, T>& b, double k);
		TEMPLATE auto Dot(const vec<TSize, T>& a, const vec<TSize, T>& b);
		TEMPLATE vec<TSize, T> Cross(const vec<TSize, T>& a, const vec<TSize, T>& b);
		TEMPLATE vec<TSize, T> Reflect(const vec<TSize, T>& a, const vec<TSize, T>& normal);
		TEMPLATE vec<TSize, T> Angle(const vec<TSize, T>& a, const vec<TSize, T>& b);
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

	TEMPLATE VEC::vec() {}
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
	TEMPLATE template <typename... OT> VEC::vec(T v1, OT... data)
	{
		constexpr unsigned int argumentCount = sizeof...(data);
		static_assert(argumentCount - 1 <= TSize, "Too many arguments in vector constructor!");
		(*this)[0] = v1;
		unsigned int j = 1;
		for (auto i : std::initializer_list<std::common_type_t<OT...>>{ data... }) (*this)[j++] = (T) i;
		for (; j < TSize; j++) (*this)[j] = 0;
	}

	TEMPLATE auto VEC::Magnitude() const
	{
		typename std::conditional<sizeof(T) >= 8, double, float>::type sum = 0;
		for (unsigned int i = 0; i < Size(); i++)sum += (*this)[i] * (*this)[i];
		return sum;
	}
	TEMPLATE auto VEC::Length() const
	{
		return Maths::Sqrt(Magnitude());
	}
	TEMPLATE void VEC::Normalize()
	{
		auto length = Length();
		if (length == 0) return;
		for (unsigned int i = 0; i < Size(); i++)(*this)[i] /= length;
	}

	TEMPLATE constexpr unsigned int VEC::Size()
	{
		return TSize;
	}
	TEMPLATE T* VEC::begin()
	{
		return *this->value[0];
	}
	TEMPLATE T* VEC::end()
	{
		return *this->value[0] + Size();
	}
	TEMPLATE const T* VEC::begin() const
	{
		return *this->value[0];
	}
	TEMPLATE const T* VEC::end() const
	{
		return *this->value[0] + Size();
	}

	TEMPLATE template <typename OT> VEC::operator vec<TSize, OT>() const
	{
		vec<TSize, OT> t;
		for (unsigned int i = 0; i < TSize; i++) t[i] = (*this)[i];

		return t;
	}
	TEMPLATE template <unsigned int OSize, typename OT> VEC::operator vec<OSize, OT>() const
	{
		vec<OSize, OT> t;
		unsigned int i = 0;
		for (i; i < Maths::Min(TSize, OSize); i++) t[i] = (*this)[i];
		for (i; i < Maths::Max(TSize, OSize); i++) t[i] = 0;

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
			(*this)[i] = -(*this)[i];
		return t;
	}
	TEMPLATE template<typename OT> auto VEC::operator +(const vec<TSize, OT>& o)const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t += o;
		return t;
	}
	TEMPLATE template<typename OT> auto VEC::operator -(const vec<TSize, OT>& o)const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t -= o;
		return t;
	}
	TEMPLATE template<typename OT> auto VEC::operator *(const vec<TSize, OT>& o)const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t *= o;
		return t;
	}
	TEMPLATE template<typename OT> auto VEC::operator /(const vec<TSize, OT>& o)const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t /= o;
		return t;
	}
	TEMPLATE template<typename OT> auto  VEC::operator +(const OT& o) const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t += o;
		return t;
	}
	TEMPLATE template<typename OT> auto  VEC::operator -(const OT& o) const
	{
		vec<TSize, typename std::conditional<std::is_integral<T>::value&& std::is_floating_point<OT>::value, OT, T>::type> t = *this;
		t -= o;
		return t;
	}
	TEMPLATE template<typename OT> auto  VEC::operator *(const OT& o) const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t *= o;
		return t;
	}
	TEMPLATE template<typename OT> auto  VEC::operator /(const OT& o) const
	{
		vec<TSize, typename VEC::OperatorReturnType<OT>::type> t = *this;
		t /= o;
		return t;
	}

	TEMPLATE bool VEC::operator ==(const vec<TSize, T>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] != o[i])
				return false;
		return true;
	}
	TEMPLATE bool VEC::operator !=(const vec<TSize, T>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] != o[i])
				return true;
		return false;
	}
	TEMPLATE bool VEC::operator <(const vec<TSize, T>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] >= o[i])
				return false;
		return true;
	}
	TEMPLATE bool VEC::operator <=(const vec<TSize, T>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] > o[i])
				return false;
		return true;
	}
	TEMPLATE bool VEC::operator >(const vec<TSize, T>& o) const
	{
		for (unsigned int i = 0; i < Size(); i++)
			if ((*this)[i] <= o[i])
				return false;
		return true;
	}
	TEMPLATE bool VEC::operator >=(const vec<TSize, T>& o) const
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

	TEMPLATE std::ostream& operator<<(std::ostream& os, const VEC& v)
	{
		os << "vec" << v.Size() << typeid(T).name()[0];
		os << '(';
		for (unsigned int i = 0; i < v.Size() - 1; i++)
		{
			os << v[i] << ", ";
		}
		os << v[v.Size() - 1];
		os << ')';

		return os;
	}

	namespace Vector
	{
		TEMPLATE auto Distance(const VEC& a, const VEC& b)
		{
			return (a - b).Length();
		}
		TEMPLATE auto Length(const VEC& a)
		{
			return a.Length();
		}
		TEMPLATE VEC Normalized(const VEC& a)
		{
			auto t = a;
			t.Normalize();
			return t;
		}
		TEMPLATE VEC Round(const VEC& a)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Round(a[i]);
			}
			return t;
		}
		TEMPLATE VEC Ceil(const VEC& a)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Ceil(a[i]);
			}
			return t;
		}
		TEMPLATE VEC Abs(const VEC& a)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Abs(a[i]);
			}
			return t;
		}
		TEMPLATE VEC Sign(const VEC& a)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Sign(a[i]);
			}
			return t;
		}
		TEMPLATE VEC Clamp(const VEC& a, T min, T max)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Clamp(a[i], min, max);
			}
			return t;
		}
		TEMPLATE VEC Clamp(const VEC& a, const VEC& min, const VEC& max)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Clamp(a[i], min[i], max[i]);
			}
			return t;
		}
		TEMPLATE VEC Wrap(const VEC& a, T min, T max)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Wrap(a[i], min, max);
			}
			return t;
		}
		TEMPLATE VEC Wrap(const VEC& a, const VEC& min, const VEC& max)
		{
			auto t = a;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				t[i] = Maths::Wrap(a[i], min[i], max[i]);
			}
			return t;
		}
		TEMPLATE VEC Lerp(const VEC& a, const vec<TSize, T>& b, double k)
		{
			return a * k + b * (1.0f - k);
		}
		TEMPLATE auto Dot(const VEC& a, const VEC& b)
		{
			double sum = 0;
			for (unsigned int i = 0; i < a.Size(); i++)
			{
				sum += a[i] * b[i];
			}
			return sum;
		}
		TEMPLATE VEC Cross(const VEC& a, const VEC& b);
		TEMPLATE VEC Reflect(const VEC& a, const VEC& normal);
		TEMPLATE VEC Angle(const VEC& a, const VEC& b);
		TEMPLATE VEC Random(T min, T max)
		{
			auto t = VEC();
			for (unsigned int i = 0; i < TSize; i++)
			{
				t[i] = Maths::Random(min, max);
			}
			return t;
		}
		TEMPLATE VEC Random(const VEC& min, const VEC& max)
		{
			auto t = VEC();
			for (unsigned int i = 0; i < TSize; i++)
			{
				t[i] = Maths::Random(min[i], max[i]);
			}
			return t;
		}
		TEMPLATE VEC Random(std::initializer_list<vec<2, T>> componentWiseBounds)
		{
			assert(componentWiseBounds.size() == TSize);
			auto t = VEC();
			for (unsigned int i = 0; i < TSize; i++)
			{
				t[i] = Maths::Random(componentWiseBounds[i].x, componentWiseBounds[i].x);
			}
			return t;
		}
		TEMPLATE VEC Unit();
	}

#undef TEMPLATE
#undef VEC
#pragma endregion // IMPLEMENTATION
}