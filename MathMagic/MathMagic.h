#pragma once

#include <chrono>

#define FLOAT_MIN		1.175494e-38				// Minimum floating-point value
#define FLOAT_MAX		3.402823e+38				// Maximum floating-point value
#define FLOAT_EPSILON	1.192093e-07				// Smallest possible floating-point value

#define DOUBLE_MAX		1.797693e+308				// Maximum possible double-precision floating-point value

#define SHORT_MIN    (-32768)						// Minimum (signed) short value
#define SHORT_MAX      32767						// Maximum (signed) short value
#define USHORT_MAX     0xffff						// Maximum unsigned short value

#define INT_MIN     (-2147483647 - 1)				// Minimum (signed) int value
#define INT_MAX       2147483647					// Maximum (signed) int value

#define UINT_MAX      0xffffffff					// Maximum unsigned int value

#define LONG_MIN    (-2147483647L - 1)				// Minimum (signed) long value
#define LONG_MAX      2147483647L					// Maximum (signed) long value

#define ULONG_MAX     0xffffffffUL					// Maximum unsigned long value

#define LLONG_MAX     9223372036854775807i64		// Maximum signed long long int value
#define LLONG_MIN   (-9223372036854775807i64 - 1)	// Minimum signed long long int value
#define ULLONG_MAX    0xffffffffffffffffui64		// Maximum unsigned long long int value

#define INT8_MIN     (-127i8 - 1)					// Minimum signed 8 bit value
#define INT8_MAX       127i8						// Maximum signed 8 bit value
#define UINT8_MAX      0xffui8						// Maximum unsigned 8 bit value

#define INT16_MIN    (-32767i16 - 1)				// Minimum signed 16 bit value
#define INT16_MAX      32767i16						// Maximum signed 16 bit value
#define UINT16_MAX     0xffffui16					// Maximum unsigned 16 bit value

#define INT32_MIN    (-2147483647i32 - 1)			// Minimum signed 32 bit value
#define INT32_MAX      2147483647i32				// Maximum signed 32 bit value
#define UINT32_MAX     0xffffffffui32				// Maximum unsigned 32 bit value


#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

#define DEG2RAD(X) (X / 180.0 * PI)
#define RAD2DEG(X) (X * 180.0 / PI)

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

	// Returns A + B
	template<typename T>
	T Add(const T& A, const T& B)
	{
		return A + B;
	}

	// Returns A - B
	template<typename T>
	T Subtract(const T& A, const T& B)
	{
		return A - B;
	}

	// Returns A * B
	template<typename T>
	T Multiply(const T& A, const T& B)
	{
		return A * B;
	}

	// Returns A / B
	template<typename T>
	T Divide(const T& A, const T& B)
	{
		return A / B;
	}

	// Returns the square root of X. Implementation of Newton's algorithm
	template<typename T>
	T SquareRoot(const T& X) noexcept
	{
		float Guess = 1.0f; // Initial guess

		for (int i = 0; i < 100; ++i)
			Guess -= (Guess*Guess - X) / (2*Guess);

		return Guess;
	}

	template<typename T>
	constexpr const T& Abs(const T& X) noexcept
	{
		return (X <= 0.0f) ? 0.0f - X : X;
	}

	template<typename T>
	constexpr const T& Floor(const T& X) noexcept
	{
		if (X > LLONG_MAX || X < LLONG_MIN)
			return X;
		
		const long long& N = (long long)X;
	    const double D = (double)N;

		return X >= 0 ? (T)D : (T)D -1;
	}

	template<typename T>
	constexpr const T& Ceil(const T& X) noexcept
	{
		const int& A = X;
		if ((T)A != X)
			return A+1;

		return (T)X;
	}

	template<typename T>
	constexpr const T& Clamp(const T& Value, const T& Min, const T& Max)
	{
		return Value <= Min ? Min : Value >= Max ? Max : Value;
	}

	template<typename T>
	constexpr const T& LerpClamped(const T& A, const T& B, const T& Alpha)
	{
		return Clamp(A + Alpha * (B - A), A, B);
	}

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

	const int& RandRange(const int& Min, const int& Max)
	{
		return Floor(Min + Random() % 1000/1000.0f * (Max - Min + 1));
	}

	const float& FRandRange(const float& Min, const float& Max)
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
	class Vector2D
	{
	public:
		T X = 0.0f, Y = 0.0f;

		explicit Vector2D(const T& InXY)
		{
			X = InXY;
			Y = InXY;
		}

		Vector2D(const T& InX, const T& InY)
		{
			X = InX;
			Y = InY;
		}

		// Adds the RHS to each component of this vector
		Vector2D<T> operator + (const Vector2D<T>& RHS)
		{
			return Vector2D<T>(X + RHS.X, Y + RHS.Y);
		}
		
		// Subtracts the RHS to each component of this vector
		Vector2D<T> operator - (const Vector2D<T>& RHS)
		{
			return Vector2D<T>(X - RHS.X, Y - RHS.Y);
		}

		// Multiplies the RHS to each component of this vector
		Vector2D<T> operator * (const T& Scalar)
		{
			return Vector2D<T>(X * Scalar, Y * Scalar);
		}

		// Divides the RHS to each component of this vector
		Vector2D<T> operator / (const T& Scalar)
		{
			return Vector2D<T>(X / Scalar, Y / Scalar);
		}

		// Adds the RHS to each component of this vector and sets it
		Vector2D<T>& operator += (const Vector2D<T>& RHS)
		{
			X += RHS.X;
			Y += RHS.Y;
			return *this;
		}

		// Subtracts the RHS to each component of this vector and sets it
		Vector2D<T>& operator -= (const Vector2D<T>& RHS)
		{
			X -= RHS.X;
			Y -= RHS.Y;
			return *this;
		}

		// Multiplies the RHS to each component of this vector and sets it
		Vector2D<T>& operator *= (const T& Scalar)
		{
			X *= Scalar;
			Y *= Scalar;
			return *this;
		}

		// Divides the RHS to each component of this vector and sets it
		Vector2D<T>& operator /= (const T& Scalar)
		{
			X /= Scalar;
			Y /= Scalar;
			return *this;
		}

		// Checks to see if the RHS vector is equal to this vector
		bool operator == (Vector2D<T> RHS)
		{
			return (X == RHS.X && Y == RHS.Y);
		}

		// Returns a reference to the component corresponding to the given index
		T& operator [] (const int& Index)
		{
			return *(reinterpret_cast<float*>(this)+Index);
		}

		// Returns the length (magnitude) of this vector.
		T Magnitude()
		{
			return SquareRoot(X * X + Y * Y);
		}

		// Returns the length/size of this vector, squared
		T MagnitudeSquared()
		{
			return SquareRoot(X * X + Y * Y) * SquareRoot(X * X + Y * Y);
		}

		// Returns the inverse length/size of this vector
		T InverseMagnitude()
		{
			return 1/Magnitude();
		}

		// Returns the dot product of this vector (a scalar value)
		T Dot(Vector2D<T>& Other)
		{
			const Vector2D<T>& NormalizedVector = GetNormal();
			const Vector2D<T>& OtherNormalizedVector = Other.GetNormal();

			return NormalizedVector.X * OtherNormalizedVector.X + NormalizedVector.Y * OtherNormalizedVector.Y;
		}

		// Returns the cross product of this vector (a scalar value)
		T Cross(Vector2D<T>& Other)
		{
			const Vector2D<T>& NormalizedVector = GetNormal();
			const Vector2D<T>& OtherNormalizedVector = Other.GetNormal();

			return NormalizedVector.X * OtherNormalizedVector.X - NormalizedVector.Y * OtherNormalizedVector.Y;
		}

		// Returns the dot product of two vectors (A and B)
		static T Dot(Vector2D<T>& A, Vector2D<T>& B)
		{
			const Vector2D<T>& ANormalized = A.GetNormal();
			const Vector2D<T>& BNormalized = B.GetNormal();

			return ANormalized.X * BNormalized.X + ANormalized.Y * BNormalized.Y;
		}

		// Returns the cross product of two vectors (A and B)
		static T Cross(Vector2D<T>& A, Vector2D<T>& B)
		{
			const Vector2D<T>& ANormalized = A.GetNormal();
			const Vector2D<T>& BNormalized = B.GetNormal();

			return ANormalized.X * BNormalized.X - ANormalized.Y * BNormalized.Y;
		}

		// Returns true if we have normalized this vector
		bool Normalize()
		{
			float InverseMag = InverseMagnitude();

			X *= InverseMag;
			Y *= InverseMag;

			return true;
		}

		// Returns a copy of the normalized version of this vector
		Vector2D<T> GetNormal()
		{
			float InverseMag = InverseMagnitude();

			return Vector2D<T>(X*InverseMag, Y*InverseMag);
		}

		// Returns a copy of the perpendicular version of this vector
		Vector2D<T> Perpendicular()
		{
			return Vector2D<T>(-Y, X);
		}

		// Euclidean distance between two points
		static T Distance(Vector2D<T> A, Vector2D<T> B)
		{
			return SquareRoot((B.X - A.X)*(B.X - A.X) + (B.Y - A.Y)*(B.Y - A.Y));
		}

		// Squared distance between two points
		static T DistanceSquared(Vector2D<T>& A, Vector2D<T>& B)
		{
			return Distance(A, B)*Distance(A, B);
		}

		// Check against another vector for equality, within specified error limits.
		bool Equals(Vector2D<T>& B, const T& Tolerance = FLOAT_EPSILON)
		{
			return (Abs(X - B.X) < Tolerance && Abs(Y - B.Y) < Tolerance);
		}

		// Check vector A against vector B for equality, within specified error limits.
		static bool Equals(Vector2D<T>& A, Vector2D<T>& B, const T& Tolerance = FLOAT_EPSILON)
		{
			return (Abs(A.X - B.X) < Tolerance && Abs(A.Y - B.Y) < Tolerance);
		}

		// Checks whether vector is near to zero within a specified tolerance.
		bool IsNearlyZero(const T& Tolerance = 0.01f)
		{
			return (X <= Tolerance && Y <= Tolerance);
		}

		// Checks whether vector A is near to zero within a specified tolerance.
		static bool IsNearlyZero(Vector2D<T>& A, const T& Tolerance = 0.01f)
		{
			return (A.X <= Tolerance && A.Y <= Tolerance);
		}

		// Checks whether all components of the vector are exactly zero.
		bool IsZero()
		{
			return (X == 0.0f && Y == 0.0f);
		}
	};

	template<typename T>
	class Vector3D
	{
	public:
		T X, Y, Z;
		T R, G, B;

		explicit Vector3D(const T& InXYX)
		{
			X = InXYX;
			Y = InXYX;
			Z = InXYX;

			R = InXYX;
			G = InXYX;
			B = InXYX;
		}

		Vector3D(const T& InX, const T& InY, const T& InZ)
		{
			X = InX;
			Y = InY;
			Z = InZ;

			R = InX;
			G = InY;
			B = InZ;
		}

		// Adds the RHS to each component of this vector
		Vector3D<T> operator + (const Vector3D<T>& RHS)
		{
			return Vector3D<T>(X + RHS.X, Y + RHS.Y, Z + RHS.Z);
		}
		
		// Subtracts the RHS to each component of this vector
		Vector3D<T> operator - (const Vector3D<T>& RHS)
		{
			return Vector3D<T>(X - RHS.X, Y - RHS.Y, Z - RHS.Z);
		}

		// Multiplies the RHS to each component of this vector
		Vector3D<T> operator * (const T& Scalar)
		{
			return Vector3D<T>(X * Scalar, Y * Scalar, Z * Scalar);
		}

		// Divides the RHS to each component of this vector
		Vector3D<T> operator / (const T& Scalar)
		{
			return Vector3D<T>(X / Scalar, Y / Scalar, Z / Scalar);
		}

		// Adds the RHS to each component of this vector and sets it
		Vector3D<T>& operator += (const Vector3D<T>& RHS)
		{
			X += RHS.X;
			Y += RHS.Y;
			Z += RHS.Z;
			return *this;
		}

		// Subtracts the RHS to each component of this vector and sets it
		Vector3D<T>& operator -= (const Vector3D<T>& RHS)
		{
			X -= RHS.X;
			Y -= RHS.Y;
			Z -= RHS.Z;
			return *this;
		}

		// Multiplies the RHS to each component of this vector and sets it
		Vector3D<T>& operator *= (const T& Scalar)
		{
			X *= Scalar;
			Y *= Scalar;
			Z *= Scalar;
			return *this;
		}

		// Divides the RHS to each component of this vector and sets it
		Vector3D<T>& operator /= (const T& Scalar)
		{
			X /= Scalar;
			Y /= Scalar;
			Z /= Scalar;
			return *this;
		}

		// Checks to see if the RHS vector is equal to this vector
		bool operator == (Vector3D<T> RHS)
		{
			return (X == RHS.X && Y == RHS.Y && Z == RHS.Z);
		}

		// Returns a reference to the component corresponding to the given index
		T& operator [] (const int& Index)
		{
			return *(reinterpret_cast<float*>(this)+Index);
		}
	};

	// Floating-point 2D vector
	typedef Vector2D<float> FVector2D;

	// Double-precision 2D vector
	typedef Vector2D<double> DVector2D;

	// Floating-point 3D vector
	typedef Vector3D<float> FVector3D;

	// Double-precision 3D vector
	typedef Vector3D<double> DVector3D;
}
