#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib> 
#include <ctime> 

int threads_count = 20;
int rand_num_limit = 90;
std::vector<std::thread> threads;
std::vector<long long int> fibs(rand_num_limit, -1);


long long int fib(long long int n) {
	long long int res = 0;
	if (fibs.at(n) != -1) {
		return fibs[n];
	}
	else {
		if (n < 0) {
			res = 0;
		}
		else if (n <= 2) {
			res = 1;
		}
		else {
			res = fib(n - 1) + fib(n - 2);
		}
	}
	fibs[n] = res;
	return res;
}


int fact(int n) {
	if (n > 0) {
		return n * fact(n - 1);
	}
	else {
		return 1;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	std::cout << "Homework 91" << std::endl << std::endl;
	for (int i = 0; i < threads_count; i++) {
		long long int res;
		long long int n = rand() % rand_num_limit;
		std::thread t([&res, n]() { 
			res = fib(n); 
			std::cout << res << std::endl;
		});
		threads.push_back(std::move(t));
	}
	for (int i = 0; i < threads_count; i++) {
		threads[i].join();
	}


	std::cout << std::endl << "Homework 90" << std::endl;

	long long int x = 20;
	long long int fibo;
	long long int facto;

	std::thread fibon([&fibo, x]() {
		fibo = fib(x);
	});
	std::thread factor([&facto, x]() {
		facto = fact(x);
	});
	fibon.join();
	factor.join();

	std::cout << x << "! = " << facto << std::endl;
	std::cout << x << "-th fibonacci number is " << fibo << std::endl;

	return 0;
}