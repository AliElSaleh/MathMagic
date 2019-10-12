#pragma once

namespace MathMagic
{
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
}