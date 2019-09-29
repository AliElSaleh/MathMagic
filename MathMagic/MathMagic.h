#pragma once

#define FLOAT_MIN		1.175494e-38				// Minimum floating-point value
#define FLOAT_MAX		3.402823e+38				// Maximum floating-point value
#define FLOAT_EPSILON 1.192093e-07					// Smallest possible floating-point value

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

namespace MathMagic
{
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
		float InitialGuess = 1.0f;

		for (int i = 0; i < 100; ++i)
			InitialGuess -= (InitialGuess*InitialGuess - X) / (2*InitialGuess);

		return InitialGuess;
	}

	template<typename T>
	T Abs(const T& X) noexcept
	{
		return (X <= 0.0f) ? 0.0f - X : X;
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
		static T Distance(Vector2D<T>& A, Vector2D<T>& B)
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
			if (Abs(X - B.X) < Tolerance && Abs(Y - B.Y) < Tolerance)
				return true;

			return false;
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

	// Floating-point vector
	typedef Vector2D<float> FVector2D;

	// Double-precision vector
	typedef Vector2D<double> DVector2D;

	// Floating-point vector
	typedef Vector3D<float> FVector3D;

	// Double-precision vector
	typedef Vector3D<double> DVector3D;
}
