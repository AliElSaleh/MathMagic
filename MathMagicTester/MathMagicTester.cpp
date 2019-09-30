#include <iostream>

#include <chrono>
#include <algorithm>

#include "../MathMagic/MathMagic.h"

using namespace MathMagic;


typedef std::ratio<1, 1000000000000> pico;
typedef std::chrono::duration<long long, pico> picoseconds;

typedef std::ratio<1, 1000000000000000> femto;
typedef std::chrono::duration<long long, femto> femtoseconds;

typedef std::ratio<1, 1000000000000000000> atto;
typedef std::chrono::duration<long long, atto> attoseconds;

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

		const long long& Duration = std::chrono::duration_cast<attoseconds>(EndTimePoint - StartTimePoint).count();

		const double& US = Duration * 0.000000000001;

		printf("Duration %lld as, %f us\n", Duration, US);
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

	printf("Std Clamp:\n");
	{
		Timer Timer;
		std::clamp(6, 0, 10);
	}
	printf("%i", std::clamp(6, -11, 10));

	std::cout << "\n";

	printf("My Clamp:\n");
	{
		Timer Timer;
		Clamp(6, 0, 10);
	}
	printf("%i", Clamp(6, -11, 10));

	std::cout << "\n";

	std::cout << "End\n";
}
