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
	FVector2D MyVector2D = FVector2D (52.0f, 26.0f);
	FVector2D OtherVector2D = FVector2D(48.0f, 20.0f);
	const float Dot = FVector2D::Dot(MyVector2D, OtherVector2D);

	printf("Dot: %f\n", Dot);
	
	std::cout << "\n";

	const FVector2D Normal = MyVector2D.GetNormal();
	const FVector2D Perp = MyVector2D.Perpendicular();
	const float Mag = MyVector2D.Magnitude();

	printf("Perpendicular: X:%f, Y:%f\n", Perp.X, Perp.Y);
	printf("Normalized: X:%f, Y:%f\n", Normal.X, Normal.Y);
	printf("Magnitude: %f\n", Mag);

	std::cout << "\n";

	std::cout << "End\n";
}
