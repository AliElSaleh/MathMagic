#pragma once

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

		// Returns a reference to the component corresponding to the given index
		T& operator [] (const int& Index)
		{
			return *(reinterpret_cast<float*>(this)+Index);
		}

		// Returns the length/size of this vector
		T Magnitude()
		{
			return SquareRoot(X * X + Y * Y);
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
	};

	// Floating-point vector
	typedef Vector2D<float> FVector2D;

	// Double-precision vector
	typedef Vector2D<double> DVector2D;
}
