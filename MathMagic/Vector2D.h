#pragma once

#include "MathMacros.h"
#include "MathUtility.h"

namespace MathMagic
{
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
}