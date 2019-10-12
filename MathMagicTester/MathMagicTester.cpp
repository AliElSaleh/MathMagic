#include <iostream>

#include "MathMagic.h"

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
		X = Sin(30.0f);
	}

	printf("%f\n", X);

	std::cout << "\n";

	std::cout << "End\n";
}
