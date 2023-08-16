#pragma once
#include <iostream>
#include "Vector.h"

#define TEMPLATE template <unsigned int TRows, unsigned int TColumns, typename T>
#define MAT mat<TRows, TColumns, T>
namespace Maths
{
    TEMPLATE struct mat
    {
        T entries[TRows][TColumns];

    public:
        mat();
        mat(T const (&data)[TRows][TColumns]);
        mat(std::initializer_list<T> data);
        template <typename... TOther>
        mat(T v1, TOther... data);

    public:
        void Transpose();
        MAT Transposed() const;
        template<typename TOther> vec<TColumns - 1, TOther> Transform(const vec<TColumns - 1, TOther>& v);
        template<typename TOther> vec<TColumns, TOther> Transform(const vec<TColumns, TOther>& v);
        T* begin();
        T* end();
        const T* begin() const;
        const T* end() const;
        static constexpr int Rows() const;
        static constexpr int Columns() const;
        static constexpr int Size() const;
        static constexpr MAT Identity();

    public:
        operator vec<TColumns, T>() const;
        template<typename TOther>
        operator mat<TRows, TColumns, TOther>() const;
        template <unsigned int ORows, unsigned int OColumns, typename TOther>
        explicit operator mat<ORows, OColumns, TOther>() const;

        MAT& operator =(const MAT& o);
        MAT& operator +=(const MAT& o);
        MAT& operator -=(const MAT& o);
        MAT& operator *=(const MAT& o);
        MAT& operator +=(const T& o);
        MAT& operator -=(const T& o);
        MAT& operator *=(const T& o);
        MAT& operator /=(const T& o);
        template<typename TOther> auto operator+(const mat<TRows, TColumns, TOther>& o) const;
        template<typename TOther> auto operator-(const mat<TRows, TColumns, TOther>& o) const;
        template<typename TOther> auto operator*(const mat<TRows, TColumns, TOther>& o) const;
        template<typename TOther> auto operator*(const vec<TRows, TOther>& o) const;
        template<typename TOther> auto operator+(const TOther& o) const;
        template<typename TOther> auto operator-(const TOther& o) const;
        template<typename TOther> auto operator*(const TOther& o) const;
        template<typename TOther> auto operator/(const TOther& o) const;

        auto& operator[] (unsigned int index);
        const auto& operator[] (unsigned int index) const;
    };
    template <unsigned int TColumns, unsigned int TRows, typename T, typename TOther> auto operator+(const TOther& s, const MAT& m);
    template <unsigned int TColumns, unsigned int TRows, typename T, typename TOther> auto operator-(const TOther& s, const MAT& m);
    template <unsigned int TColumns, unsigned int TRows, typename T, typename TOther> auto operator*(const TOther& s, const MAT& m);
    template <unsigned int TColumns, unsigned int TRows, typename T, typename TOther> auto operator/(const TOther& s, const MAT& m);
    TEMPLATE std::ostream& operator<<(std::ostream& os, const MAT& m);
    TEMPLATE std::istream& operator>>(std::istream& is, const MAT& m);

    typedef mat<3, 3, float> mat3x3;
    typedef mat<4, 4, float> mat4x4;
    namespace Matrix
    {
        TEMPLATE MAT Translation(const vec<TColumns, T>& translation);
        TEMPLATE MAT Scale(const vec<TColumns, T>& scale);
        TEMPLATE MAT Rotation(const vec<TColumns, T>& rotationRadians);
        TEMPLATE MAT Shear(const vec<TColumns, T>& shear);
        TEMPLATE MAT Transformation(const vec<TColumns, T>& translation, const vec<TColumns, T>& scale, const vec<TColumns, T>& rotationRadians);
        TEMPLATE MAT InverseTransformation(const vec<TColumns, T>& translation, const vec<TColumns, T>& scale, const vec<TColumns, T>& rotationRadians);

        namespace Projection
        {
            mat4x4 Perspective(float ratio, float fov, float near, float far);
            mat4x4 Orthograpic(float left, float right, float bottom, float top, float near, float far);
        }
    }

}

#undef TEMPLATE;
#undef MAT;