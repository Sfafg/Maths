#pragma once
namespace Maths
{
	extern const float PI;
	extern const int MAX_RAND;

	extern long double Degrees(long double radians);
	extern double Degrees(double radians);
	extern float Degrees(float radians);
	extern double Degrees(long long radians);
	extern double Degrees(long radians);
	extern float Degrees(int radians);
	extern float Degrees(short radians);
	extern float Degrees(char radians);
	extern float Degrees(unsigned int radians);
	extern float Degrees(unsigned short radians);
	extern float Degrees(unsigned char radians);

	extern long double Radians(long double degrees);
	extern double Radians(double degrees);
	extern float Radians(float degrees);
	extern double Radians(long long degrees);
	extern double Radians(long degrees);
	extern float Radians(int degrees);
	extern float Radians(short degrees);
	extern float Radians(char degrees);
	extern float Radians(unsigned int degrees);
	extern float Radians(unsigned short degrees);
	extern float Radians(unsigned char degrees);

	extern long double Mod(long double a, long double b);
	extern double Mod(double a, double b);
	extern float Mod(float a, float b);
	extern long long Mod(long long a, long long b);
	extern long Mod(long a, long b);
	extern int Mod(int a, int b);
	extern short Mod(short a, short b);
	extern char Mod(char a, char b);
	extern unsigned int Mod(unsigned int a, unsigned int b);
	extern unsigned short Mod(unsigned short a, unsigned short b);
	extern unsigned char Mod(unsigned char a, unsigned char b);

	extern long double Abs(long double a);
	extern double Abs(double a);
	extern float Abs(float a);
	extern long long Abs(long long a);
	extern long Abs(long a);
	extern int Abs(int a);
	extern short Abs(short a);
	extern char Abs(char a);

	extern int Sign(long double a);
	extern int Sign(double a);
	extern int Sign(float a);
	extern int Sign(long long a);
	extern int Sign(long a);
	extern int Sign(int a);
	extern int Sign(short a);
	extern int Sign(char a);
	extern int Sign(unsigned int a);
	extern int Sign(unsigned short a);
	extern int Sign(unsigned char a);

	extern long double Min(long double a, long double b);
	extern double Min(double a, double b);
	extern float Min(float a, float b);
	extern long long Min(long long a, long long b);
	extern long Min(long a, long b);
	extern int Min(int a, int b);
	extern short Min(short a, short b);
	extern char Min(char a, char b);
	extern unsigned int Min(unsigned int a, unsigned int b);
	extern unsigned short Min(unsigned short a, unsigned short b);
	extern unsigned char Min(unsigned char a, unsigned char b);

	extern long double Max(long double a, long double b);
	extern double Max(double a, double b);
	extern float Max(float a, float b);
	extern long long Max(long long a, long long b);
	extern long Max(long a, long b);
	extern int Max(int a, int b);
	extern short Max(short a, short b);
	extern char Max(char a, char b);
	extern unsigned int Max(unsigned int a, unsigned int b);
	extern unsigned short Max(unsigned short a, unsigned short b);
	extern unsigned char Max(unsigned char a, unsigned char b);

	extern long double Clamp(long double x, long double min, long double max);
	extern double Clamp(double x, double min, double max);
	extern float Clamp(float x, float min, float max);
	extern long long Clamp(long long x, long long min, long long max);
	extern long Clamp(long x, long min, long max);
	extern int Clamp(int x, int min, int max);
	extern short Clamp(short x, short min, short max);
	extern char Clamp(char x, char min, char max);
	extern unsigned int Clamp(unsigned int x, unsigned int min, unsigned int max);
	extern unsigned short Clamp(unsigned short x, unsigned short min, unsigned short max);
	extern unsigned char Clamp(unsigned char x, unsigned char min, unsigned char max);

	extern long double Wrap(long double x, long double min, long double max);
	extern double Wrap(double x, double min, double max);
	extern float Wrap(float x, float min, float max);
	extern long long Wrap(long long x, long long min, long long max);
	extern long Wrap(long x, long min, long max);
	extern int Wrap(int x, int min, int max);
	extern short Wrap(short x, short min, short max);
	extern char Wrap(char x, char min, char max);
	extern unsigned int Wrap(unsigned int x, unsigned int min, unsigned int max);
	extern unsigned short Wrap(unsigned short x, unsigned short min, unsigned short max);
	extern unsigned char Wrap(unsigned char x, unsigned char min, unsigned char max);

	extern long double Lerp(long double a, long double b, long double k);
	extern double Lerp(double a, double b, double k);
	extern float Lerp(float a, float b, float k);
	extern long long Lerp(long long a, long long b, double k);
	extern long Lerp(long a, long b, double k);
	extern int Lerp(int a, int b, float k);
	extern short Lerp(short a, short b, float k);
	extern char Lerp(char a, char b, float k);
	extern unsigned int Lerp(unsigned int a, unsigned int b, float k);
	extern unsigned short Lerp(unsigned short a, unsigned short b, float k);
	extern unsigned char Lerp(unsigned char a, unsigned char b, float k);

	extern long double Ceil(long double a);
	extern double Ceil(double a);
	extern float Ceil(float a);
	extern double Round(double a);
	extern float Round(float a);
	extern double Floor(double a);
	extern float Floor(float a);

	extern long double Pow(long double a, long double b);
	extern double Pow(double a, double b);
	extern float Pow(float a, float b);
	extern double Pow(long long a, double b);
	extern double Pow(long a, double b);
	extern float Pow(int a, float b);
	extern float Pow(short a, float b);
	extern float Pow(char a, float b);
	extern float Pow(unsigned int a, float b);
	extern float Pow(unsigned short a, float b);
	extern float Pow(unsigned char a, float b);

	extern long double Sqrt(long double a);
	extern double Sqrt(double a);
	extern float Sqrt(float a);
	extern double Sqrt(long long a);
	extern double Sqrt(long a);
	extern float Sqrt(int a);
	extern float Sqrt(short a);
	extern float Sqrt(char a);
	extern float Sqrt(unsigned int a);
	extern float Sqrt(unsigned short a);
	extern float Sqrt(unsigned char a);

	extern double Sin(double a);
	extern double Asin(double a);
	extern double Cos(double a);
	extern double Acos(double a);
	extern double Tan(double a);
	extern double Atan(double a);

	extern void Seed(unsigned int seed);
	extern int Random();
	extern long double Random(long double max);
	extern long double Random(long double min, long double max);
	extern double Random(double max);
	extern double Random(double min, double max);
	extern float Random(float max);
	extern float Random(float min, float max);
	extern long long Random(long long max);
	extern long long Random(long long min, long long max);
	extern long Random(long max);
	extern long Random(long min, long max);
	extern int Random(int max);
	extern int Random(int min, int max);
	extern short Random(short max);
	extern short Random(short min, short max);
	extern char Random(char max);
	extern char Random(char min, char max);
	extern unsigned int Random(unsigned int max);
	extern unsigned int Random(unsigned int min, unsigned int max);
	extern unsigned short Random(unsigned short max);
	extern unsigned short Random(unsigned short min, unsigned short max);
	extern unsigned char Random(unsigned char max);
	extern unsigned char Random(unsigned char min, unsigned char max);
	extern long double NormalDist(long double mean, long double standardDeviation);
	extern double NormalDist(double mean, double standardDeviation);
	extern float NormalDist(float mean, float standardDeviation);
}