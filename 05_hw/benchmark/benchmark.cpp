#include <iostream>
#include <chrono>
#include "../src/stack.h"

class StackBenchmark
{
public:
	StackBenchmark(size_t limit) : limit(limit)
	{
		initStack(&stack);
	}

	~StackBenchmark()
	{
		destroyStack(&stack);
	}

	void run()
	{
		benchmarkPush();
		benchmarkPop();
	}

private:
	Stack stack;
	size_t limit;

	void benchmarkPush()
	{
		std::cout << "Pushing " << limit << " elements into the stack" << std::endl;

		auto start_time = std::chrono::steady_clock::now();
		for (size_t i = 0; i < limit; ++i)
		{
			push(&stack, 1);
		}
		auto end_time = std::chrono::steady_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		std::cout << "Push time: " << elapsed.count() << " ms" << std::endl;
	}

	void benchmarkPop()
	{
		std::cout << "Popping " << limit << " elements from the stack" << std::endl;

		auto start_time = std::chrono::steady_clock::now();
		for (size_t i = 0; i < limit; ++i)
		{
			pop(&stack);
		}
		auto end_time = std::chrono::steady_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		std::cout << "Pop time: " << elapsed.count() << " ms" << std::endl;
	}
};

int main()
{
	const size_t limit = 10000000;

	StackBenchmark benchmark(limit);
	benchmark.run();

	return 0;
}
