#include <iostream>

#include <chrono>

#include "../MathMagic/MathMagic.h"

using namespace MathMagic;


class Timer
{
public:
	Timer()
	{
		StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		const auto& EndTimePoint = std::chrono::high_resolution_clock::now();

		const long long& Start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimePoint).time_since_epoch().count();
		const long long& End = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

		const auto& Duration = End - Start;

		const double& MS = Duration * 0.001;

		printf("Duration %lld us, %f ms\n", Duration, MS);
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> StartTimePoint;
};

int main()
{
	FVector2D A = FVector2D (0.0f, 0.0f);
	FVector2D B = FVector2D(50.0f, 50.0f);
	const float Dot = FVector2D::Dot(A, B);

	printf("Dot: %f\n", Dot);
	
	std::cout << "\n";

	const FVector2D Normal = A.GetNormal();
	const FVector2D Perp = A.Perpendicular();
	const float Mag = A.Magnitude();
	const float Distance = FVector2D::Distance(A, B);

	FVector3D C = FVector3D(3.0f);
	FVector3D D = FVector3D(3.0f);

	if (C == FVector3D(2.99999999999999f))
		std::cout << "True\n";
	else
		std::cout << "False\n";

	std::cout << "\n";

	printf("Perpendicular: X:%f, Y:%f\n", Perp.X, Perp.Y);
	printf("Normalized: X:%f, Y:%f\n", Normal.X, Normal.Y);
	printf("Magnitude: %f\n", Mag);
	printf("Distance: %f\n", Distance);

	std::cout << "\n";

	std::cout << "End\n";
}
