#include "Maths.h"
#include <math.h>
#include <random>
namespace Maths
{
	const float PI = 3.14159265359f;
	const float DEGREE_RAD = PI / 180.0f;
	const float RAD_DEGREE = 180.0f / PI;
	const int MAX_RAND = RAND_MAX;

	long double Degrees(long double radians) { return radians * RAD_DEGREE; }
	double Degrees(double radians) { return radians * RAD_DEGREE; }
	float Degrees(float radians) { return radians * RAD_DEGREE; }
	double Degrees(long long radians) { return radians * RAD_DEGREE; }
	double Degrees(long radians) { return radians * RAD_DEGREE; }
	float Degrees(int radians) { return radians * RAD_DEGREE; }
	float Degrees(short radians) { return radians * RAD_DEGREE; }
	float Degrees(char radians) { return radians * RAD_DEGREE; }
	float Degrees(unsigned int radians) { return radians * RAD_DEGREE; }
	float Degrees(unsigned short radians) { return radians * RAD_DEGREE; }
	float Degrees(unsigned char radians) { return radians * RAD_DEGREE; }

	long double Radians(long double degrees) { return degrees * DEGREE_RAD; }
	double Radians(double degrees) { return degrees * DEGREE_RAD; }
	float Radians(float degrees) { return degrees * DEGREE_RAD; }
	double Radians(long long degrees) { return degrees * DEGREE_RAD; }
	double Radians(long degrees) { return degrees * DEGREE_RAD; }
	float Radians(int degrees) { return degrees * DEGREE_RAD; }
	float Radians(short degrees) { return degrees * DEGREE_RAD; }
	float Radians(char degrees) { return degrees * DEGREE_RAD; }
	float Radians(unsigned int degrees) { return degrees * DEGREE_RAD; }
	float Radians(unsigned short degrees) { return degrees * DEGREE_RAD; }
	float Radians(unsigned char degrees) { return degrees * DEGREE_RAD; }

	long double Mod(long double a, long double b) { return fmod(a, b); }
	double Mod(double a, double b) { return fmod(a, b); }
	float Mod(float a, float b) { return fmod(a, b); }
	long long Mod(long long a, long long b) { return a % b; }
	long Mod(long a, long b) { return a % b; }
	int Mod(int a, int b) { return a % b; }
	short Mod(short a, short b) { return a % b; }
	char Mod(char a, char b) { return a % b; }
	unsigned int Mod(unsigned int a, unsigned int b) { return a % b; }
	unsigned short Mod(unsigned short a, unsigned short b) { return a % b; }
	unsigned char Mod(unsigned char a, unsigned char b) { return a % b; }

	long double Abs(long double a) { return abs(a); }
	double Abs(double a) { return abs(a); }
	float Abs(float a) { return abs(a); }
	long long Abs(long long a) { return abs(a); }
	long Abs(long a) { return abs(a); }
	int Abs(int a) { return abs(a); }
	short Abs(short a) { return abs(a); }
	char Abs(char a) { return abs(a); }

	int Sign(long double a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(double a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(float a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(long long a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(long a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(int a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(short a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(char a) { return (a < 0) ? -1 : (a > 0) ? 1 : 0; }
	int Sign(unsigned int a) { return (a > 0) ? 1 : 0; }
	int Sign(unsigned short a) { return (a > 0) ? 1 : 0; }
	int Sign(unsigned char a) { return (a > 0) ? 1 : 0; }

	long double Min(long double a, long double b) { return (a < b) ? a : b; }
	double Min(double a, double b) { return (a < b) ? a : b; }
	float Min(float a, float b) { return (a < b) ? a : b; }
	long long Min(long long a, long long b) { return (a < b) ? a : b; }
	long Min(long a, long b) { return (a < b) ? a : b; }
	int Min(int a, int b) { return (a < b) ? a : b; }
	short Min(short a, short b) { return (a < b) ? a : b; }
	char Min(char a, char b) { return (a < b) ? a : b; }
	unsigned int Min(unsigned int a, unsigned int b) { return (a < b) ? a : b; }
	unsigned short Min(unsigned short a, unsigned short b) { return (a < b) ? a : b; }
	unsigned char Min(unsigned char a, unsigned char b) { return (a < b) ? a : b; }

	long double Max(long double a, long double b) { return (a > b) ? a : b; }
	double Max(double a, double b) { return (a > b) ? a : b; }
	float Max(float a, float b) { return (a > b) ? a : b; }
	long long Max(long long a, long long b) { return (a > b) ? a : b; }
	long Max(long a, long b) { return (a > b) ? a : b; }
	int Max(int a, int b) { return (a > b) ? a : b; }
	short Max(short a, short b) { return (a > b) ? a : b; }
	char Max(char a, char b) { return (a > b) ? a : b; }
	unsigned int Max(unsigned int a, unsigned int b) { return (a > b) ? a : b; }
	unsigned short Max(unsigned short a, unsigned short b) { return (a > b) ? a : b; }
	unsigned char Max(unsigned char a, unsigned char b) { return (a > b) ? a : b; }

	long double Clamp(long double x, long double min, long double max) { return Min(Max(x, min), max); }
	double Clamp(double x, double min, double max) { return Min(Max(x, min), max); }
	float Clamp(float x, float min, float max) { return Min(Max(x, min), max); }
	long long Clamp(long long x, long long min, long long max) { return Min(Max(x, min), max); }
	long Clamp(long x, long min, long max) { return Min(Max(x, min), max); }
	int Clamp(int x, int min, int max) { return Min(Max(x, min), max); }
	short Clamp(short x, short min, short max) { return Min(Max(x, min), max); }
	char Clamp(char x, char min, char max) { return Min(Max(x, min), max); }
	unsigned int Clamp(unsigned int x, unsigned int min, unsigned int max) { return Min(Max(x, min), max); }
	unsigned short Clamp(unsigned short x, unsigned short min, unsigned short max) { return Min(Max(x, min), max); }
	unsigned char Clamp(unsigned char x, unsigned char min, unsigned char max) { return Min(Max(x, min), max); }

	long double Wrap(long double x, long double min, long double max) { return x + 2 * min - Floor((x + min) / (max - min)) * (max - min); }
	double Wrap(double x, double min, double max) { return x + 2 * min - Floor((x + min) / (max - min)) * (max - min); }
	float Wrap(float x, float min, float max) { return x + 2 * min - Floor((x + min) / (max - min)) * (max - min); }
	long long Wrap(long long x, long long min, long long max) { return x + 2 * min - Floor((x + min) / (long double) (max - min)) * (max - min); }
	long Wrap(long x, long min, long max) { return x + 2 * min - Floor((x + min) / (double) (max - min)) * (max - min); }
	int Wrap(int x, int min, int max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }
	short Wrap(short x, short min, short max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }
	char Wrap(char x, char min, char max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }
	unsigned int Wrap(unsigned int x, unsigned int min, unsigned int max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }
	unsigned short Wrap(unsigned short x, unsigned short min, unsigned short max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }
	unsigned char Wrap(unsigned char x, unsigned char min, unsigned char max) { return x + 2 * min - Floor((x + min) / (float) (max - min)) * (max - min); }

	long double Lerp(long double a, long double b, long double k) { return a * k + b * (1 - k); }
	double Lerp(double a, double b, double k) { return a * k + b * (1 - k); }
	float Lerp(float a, float b, float k) { return a * k + b * (1 - k); }
	long long Lerp(long long a, long long b, double k) { return a * k + b * (1 - k); }
	long Lerp(long a, long b, double k) { return a * k + b * (1 - k); }
	int Lerp(int a, int b, float k) { return a * k + b * (1 - k); }
	short Lerp(short a, short b, float k) { return a * k + b * (1 - k); }
	char Lerp(char a, char b, float k) { return a * k + b * (1 - k); }
	unsigned int Lerp(unsigned int a, unsigned int b, float k) { return a * k + b * (1 - k); }
	unsigned short Lerp(unsigned short a, unsigned short b, float k) { return a * k + b * (1 - k); }
	unsigned char Lerp(unsigned char a, unsigned char b, float k) { return a * k + b * (1 - k); }

	long double Ceil(long double a) { return ceil(a); }
	double Ceil(double a) { return ceil(a); }
	float Ceil(float a) { return ceil(a); }
	long double Round(long double a) { return round(a); }
	double Round(double a) { return round(a); }
	float Round(float a) { return round(a); }
	long double Floor(long double a) { return floor(a); }
	double Floor(double a) { return floor(a); }
	float Floor(float a) { return floor(a); }

	long double Pow(long double a, long double b) { return pow(a, b); }
	double Pow(double a, double b) { return pow(a, b); }
	float Pow(float a, float b) { return pow(a, b); }
	double Pow(long long a, double b) { return pow(a, b); }
	double Pow(long a, double b) { return pow(a, b); }
	float Pow(int a, float b) { return pow(a, b); }
	float Pow(short a, float b) { return pow(a, b); }
	float Pow(char a, float b) { return pow(a, b); }
	float Pow(unsigned int a, float b) { return pow(a, b); }
	float Pow(unsigned short a, float b) { return pow(a, b); }
	float Pow(unsigned char a, float b) { return pow(a, b); }

	long double Sqrt(long double a) { return sqrt(a); }
	double Sqrt(double a) { return sqrt(a); }
	float Sqrt(float a) { return sqrt(a); }
	double Sqrt(long long a) { return sqrt(a); }
	double Sqrt(long a) { return sqrt(a); }
	float Sqrt(int a) { return sqrt(a); }
	float Sqrt(short a) { return sqrt(a); }
	float Sqrt(char a) { return sqrt(a); }
	float Sqrt(unsigned int a) { return sqrt(a); }
	float Sqrt(unsigned short a) { return sqrt(a); }
	float Sqrt(unsigned char a) { return sqrt(a); }

	double Sin(double a) { return sin(a); }
	double Asin(double a) { return asin(a); }
	double Cos(double a) { return cos(a); }
	double Acos(double a) { return acos(a); }
	double Tan(double a) { return tan(a); }
	double Atan(double a) { return atan(a); }

	void Seed(unsigned int seed) { srand(seed); }
	int Random() { return rand(); }
	long double Random(long double max) { return rand() / (double) MAX_RAND * max; }
	long double Random(long double min, long double max) { return rand() / (double) MAX_RAND * (max - min) + min; }
	double Random(double max) { return rand() / (double) MAX_RAND * max; }
	double Random(double min, double max) { return rand() / (double) MAX_RAND * (max - min) + min; }
	float Random(float max) { return rand() / (float) MAX_RAND * max; }
	float Random(float min, float max) { return rand() / (float) MAX_RAND * (max - min) + min; }
	long long Random(long long max) { return Random((double) max); }
	long long Random(long long min, long long max) { return Random((double) min, (double) max); }
	long Random(long max) { return Random((double) max); }
	long Random(long min, long max) { return Random((double) min, (double) max); }
	int Random(int max) { return Random((float) max); }
	int Random(int min, int max) { return Random((float) min, (float) max); }
	short Random(short max) { return Random((float) max); }
	short Random(short min, short max) { return Random((float) min, (float) max); }
	char Random(char max) { return Random((float) max); }
	char Random(char min, char max) { return Random((float) min, (float) max); }
	unsigned int Random(unsigned int max) { return Random((float) max); }
	unsigned int Random(unsigned int min, unsigned int max) { return Random((float) min, (float) max); }
	unsigned short Random(unsigned short max) { return Random((float) max); }
	unsigned short Random(unsigned short min, unsigned short max) { return Random((float) min, (float) max); }
	unsigned char Random(unsigned char max) { return Random((float) max); }
	unsigned char Random(unsigned char min, unsigned char max) { return Random((float) min, (float) max); }

	long double NormalDist(long double mean, long double standardDeviation)
	{
		static std::default_random_engine generator;
		std::normal_distribution<long double> distribution = std::normal_distribution<long double>(mean, standardDeviation);

		return distribution(generator);
	}
	double NormalDist(double mean, double standardDeviation)
	{
		static std::default_random_engine generator;
		std::normal_distribution<double> distribution = std::normal_distribution<double>(mean, standardDeviation);

		return distribution(generator);
	}
	float NormalDist(float mean, float standardDeviation)
	{
		static std::default_random_engine generator;
		std::normal_distribution<float> distribution = std::normal_distribution<float>(mean, standardDeviation);

		return distribution(generator);
	}

}