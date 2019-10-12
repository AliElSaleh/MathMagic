#pragma once

#include <chrono>

#include "MathMacros.h"

namespace MathMagic
{
	typedef signed char			int8;
	typedef signed short		int16;
	typedef signed int			int32;
	typedef signed long long	int64;

	typedef unsigned char		uint8;
	typedef unsigned short		uint16;
	typedef unsigned int		uint32;
	typedef unsigned long long	uint64;

	/**
	 * Adds B to A
	 *
	 * @param  A - The first number
	 * @param  B - The second number
	 *
	 * @return  The result of A + B
	*/
	template<typename T>
	T Add(const T& A, const T& B)
	{
		return A + B;
	}

	/**
	 * Subtracts B from A
	 *
	 * @param  A - The first number
	 * @param  B - The second number
	 *
	 * @return  The result of A - B
	*/
	template<typename T>
	T Subtract(const T& A, const T& B)
	{
		return A - B;
	}

	/**
	 * Multiplies A with B
	 *
	 * @param  A - The first number
	 * @param  B - The second number
	 *
	 * @return  The result of A * B
	*/
	template<typename T>
	T Multiply(const T& A, const T& B)
	{
		return A * B;
	}

	/**
	 * Divides A with B
	 *
	 * @param  A - The first number
	 * @param  B - The second number
	 *
	 * @return  The result of A / B
	*/
	template<typename T>
	T Divide(const T& A, const T& B)
	{
		return A / B;
	}

	/**
	 * Finds the square root of X. Implementation of Newton's algorithm
	 *
	 * @param  X - The number to square root
	 *
	 * @return  The square root of X
	*/
	template<typename T>
	T SquareRoot(const T& X) noexcept
	{
		float Guess = 1.0f; // Initial guess

		for (int i = 0; i < 100; ++i)
			Guess -= (Guess*Guess - X) / (2*Guess);

		return Guess;
	}

	/**
	 * Finds the absolute value of X.
	 *
	 * @param  X - The number to get the absolute value of
	 *
	 * @return  The absolute value of X
	*/
	template<typename T>
	constexpr const T& Abs(const T& X) noexcept
	{
		return (X <= (T)0.0f) ? -X : X;
	}

	/**
	 * Floors the value of X to it's nearest lowest integer value.
	 *
	 * @param  X - The number to floor
	 *
	 * @return  The floored value of X
	*/
	template<typename T>
	constexpr const T& Floor(const T& X) noexcept
	{
		if (X > LLONG_MAX || X < LLONG_MIN)
			return X;
		
		const long long& N = (long long)X;
	    const double D = (double)N;

		return X >= 0 ? (T)D : (T)D -1;
	}

	/**
	 * Floors the value of X to it's nearest highest integer value.
	 *
	 * @param  X - The number to ceil
	 *
	 * @return  The ceiled value of X
	*/
	template<typename T>
	constexpr const T& Ceil(const T& X) noexcept
	{
		const int& A = X;
		if ((T)A != X)
			return A+1;

		return (T)X;
	}

	/**
	 * Clamps the value of Value between a minimum and maximum range.
	 *
	 * @param  Value - The number to test
	 * @param  Min - The minimum range
	 * @param  Max - The maximum range
	 *
	 * @return  Min/Max if it was out of range. Otherwise return Value
	*/
	template<typename T>
	constexpr const T& Clamp(const T& Value, const T& Min, const T& Max)
	{
		return Value <= Min ? Min : Value >= Max ? Max : Value;
	}

	/**
	 * Performs a clamped linear interpolation from A to B using Alpha.
	 *
	 * @param  A - The beginning value
	 * @param  B - The end value
	 * @param  Alpha - A range from 0 to 1
	 *
	 * @return  A/B if it was out of range. Otherwise return the result of the Lerp function
	*/
	template<typename T>
	constexpr const T& LerpClamped(const T& A, const T& B, const T& Alpha)
	{
		return Clamp(A + Alpha * (B - A), A, B);
	}

	/**
	 * Performs an unclamped linear interpolation from A to B using Alpha.
	 *
	 * @param  A - The beginning value
	 * @param  B - The end value
	 * @param  Alpha - A value between 0.0 and 1.0
	 *
	 * @return  A number between A and B at Alpha
	 * @return
	 * @return Example: A: 50, B: 100, Alpha: 0.5, will return 75
	*/
	template<typename T>
	constexpr const T& Lerp(const T& A, const T& B, const T& Alpha)
	{
		return A + Alpha * (B - A);
	}

	template<typename T>
	constexpr const T& NormalizeClamped(const T& Value, const T& Min, const T& Max)
	{
		return Clamp((Value - Min) / (Max - Min), 0.0f, 1.0f);
	}

	template<typename T>
	constexpr T Normalize(const T& Value, const T& Min, const T& Max)
	{
		return (Value - Min) / (Max - Min);
	}

	template<typename T>
	constexpr const T& MapClamped(const T& Value, const T& InRangeMin, const T& InRangeMax, const T& OutRangeMin, const T& OutRangeMax)
	{
		return Clamp(Lerp(OutRangeMin, OutRangeMax, Normalize(Value, InRangeMin, InRangeMax)), OutRangeMin, OutRangeMax);
	}

	template<typename T>
	constexpr const T& Map(const T& Value, const T& InRangeMin, const T& InRangeMax, const T& OutRangeMin, const T& OutRangeMax)
	{
		return Lerp(OutRangeMin, OutRangeMax, Normalize(Value, InRangeMin, InRangeMax));
	}

	// Returns the distance between two-points
	template<typename T>
	constexpr const T& Distance2D(const T& X0, const T& Y0, const T& X1, const T& Y1)
	{
		return SquareRoot((X1-X0)*(X1-X0) + (Y1-Y0)*(Y1-Y0));
	}

	template<typename T>
	constexpr const T& Distance3D(const T& X0, const T& Y0, const T& Z0, const T& X1, const T& Y1, const T& Z1)
	{
		return SquareRoot((X1-X0)*(X1-X0) + (Y1-Y0)*(Y1-Y0) + (Z1-Z0)*(Z1-Z0));
	}

	long long Random()
	{
		return (48271 * std::chrono::high_resolution_clock::now().time_since_epoch().count() + 1) % INT_MAX;
	}

	int RandRange(const int& Min, const int& Max)
	{
		return Floor<int>(Min + Random() % 1000/1000.0f * (Max - Min + 1));
	}

	float FRandRange(const float& Min, const float& Max)
	{
		return Min + Random() % 1000/1000.0f * (Max - Min);
	}

	template<typename T>
	constexpr const T& RandDistribution(const T& Min, const T& Max, const T& Iterations)
	{
		uint32 Total = 0;

		for (uint32 i = 0; i < Iterations; ++i)
			Total += RandRange(Min, Max);

		return Total / Iterations;
	}

	template<typename T>
	constexpr bool IsNearlyEqual(const T& Value, const T& Target, const T& Tolerance = FLOAT_EPSILON)
	{
		return Abs(Value) == Target - Tolerance;
	}

	template<typename T>
	constexpr const T& DegreesToRadians(const T& Degrees)
	{
		return Degrees / 180.0f * PI;
	}

	template<typename T>
	constexpr const T& RadiansToDegrees(const T& Radians)
	{
		return Radians * 180.0f / PI;
	}

	template<typename T>
	constexpr const T& Round(const T& Value)
	{
		return Value < 0.0f ? int(Value - 0.5f) : int(Value + 0.5f);
	}

	template<typename T>
	constexpr const T& SnapToGrid(const T& Value, const T& GridSize)
	{
		return Round(Value / GridSize) * GridSize;
	}

	template<typename T>
	constexpr T Sin(const T& Value)
	{
		return sin(Value);
	}

	template<typename T>
	constexpr T ASin(const T& Value)
	{
		return asin(Value);
	}

	template<typename T>
	constexpr T Cos(const T& Value)
	{
		return cos(Value);
	}
	
	template<typename T>
	constexpr T ACos(const T& Value)
	{
		return acos(Value);
	}

	template<typename T>
	constexpr T Tan(const T& Value)
	{
		return tan(Value);
	}

	template<typename T>
	constexpr T ATan(const T& Value)
	{
		return atan(Value);
	}

	template<typename T>
	constexpr T ATan2(const T& Y, const T& X)
	{
		return atan2(Y, X);
	}
}