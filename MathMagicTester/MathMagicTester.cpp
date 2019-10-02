#include <iostream>

#include <chrono>
#include <cmath>

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

		const long long& Duration = std::chrono::duration_cast<picoseconds>(EndTimePoint - StartTimePoint).count();

		const double& US = Duration * 0.000001;

		printf("Duration %lld ps, %f us\n", Duration, US);
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

	//printf("Std Lerp:\n");
	//{
	//	Timer Timer;
	//	std::lerp(-12, -11, 10);
	//}
	//printf("%i", std::lerp(-12, -11, 10));

	std::cout << "\n";

	float X = 0.0f;
	int Y = 0;

	std::cout << "\n";

	printf("My rand:\n");
	{
		Timer Timer;
		
		//X = MapClamped(19.0f, 20.0f, 50.0f, 30.0f, 100.0f);
		//X = Lerp(0.0f, 20.0f, 0.5f);
		//X = Normalize(20, 10, 30);
		//X = Distance2D(1.0f, 1.0f, 5.0f, 5.0f);
		//X = Distance3D(1.0f, 1.0f, 1.0f, 5.0f, 5.0f, 5.0f);

		for (int i = 0; i < 100; ++i)
		{
			X = RandDistribution(0, 100, 20);
			printf("%f\n", X);
		}
	}

	//printf("%i\n", Normalize(20, 10, 30));

	//printf("%i", Clamp(-12, -11, 10));

	std::cout << "\n";

	std::cout << "End\n";
}
