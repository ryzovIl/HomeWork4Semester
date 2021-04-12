#include <iostream>
#include <future>
#include <cmath>
#include <thread>
#include <random>
#include <chrono>
#include <iomanip>
#include <vector>
#include <iterator>
std::mutex mtx;

void MonteCarlo(std::size_t N, std::size_t& count);

double SingleMonteCarlo(std::size_t N);

double MultMonteCarlo(std::size_t N);


int main() {
    std::cout << "Monte Carlo using one thread: " << SingleMonteCarlo(10000) << std::endl;
    std::cout << "Monte Carlo using more threads: " << MultMonteCarlo(10000) << std::endl;
    return 0;
}


void MonteCarlo(std::size_t N, std::size_t& count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::size_t t = 0;
    for (auto i = 0; i < N; ++i)
        if (std::pow(dis(gen), 2) + std::pow(dis(gen), 2) <= 1) {
            t++;
        }
    std::lock_guard<std::mutex> lg(mtx);
    count += t;
}

double SingleMonteCarlo(std::size_t N) {
    std::size_t count = 0;
    MonteCarlo(N, std::ref(count));
    return 4.0 * count / N;
}

double MultMonteCarlo(std::size_t N) {
    if (std::thread::hardware_concurrency() <= 1) {
        std::cout << "More threads" << std::endl;
        return -1.0;
    }

    std::size_t Nthreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::size_t CountN = N / Nthreads;
    std::size_t count = 0;

    for (auto i = 0; i < (Nthreads - 1); i++)
        threads.push_back(std::thread(MonteCarlo, CountN, std::ref(count)));

    MonteCarlo(CountN, std::ref(count));

    for (auto i = 0; i < std::size(threads); i++)
        threads[i].join();

    return 4.0 * count / N;
}
