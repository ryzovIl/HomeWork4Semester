#include <iostream>
#include <set>
#include <chrono>
#include <vector>

class Timer
{
private:

    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()){}

    void reset(){
        m_beg = clock_t::now();
    }

    double elapsed() const{
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main() {

    int N;
    std::cout << "Enter number of elements" << std::endl;
    std::cin >> N;

    //Initializing and sorting set

    std::set<int> arr1;
    Timer t;
    for (int i = 0; i < N; i++) {
        arr1.insert(rand() % 100 + 1);
    }
    std::cout << "Elapsed time(set):" << t.elapsed() << std::endl;

    //Initializing and sorting vector with preset size

    std::vector<int> arr2(N);
    t.reset();
    for (auto el:arr2) {
        el = rand() % 100 + 1;
    }
    std::sort(arr2.begin(), arr2.end());
    std::cout << "Elapsed time(vector with preset size):" << t.elapsed() << std::endl;

    //Initializing and sorting vector with preset size

    std::vector<int> arr3;
    t.reset();
    for (int i=0;i<N;i++) {
        arr3.push_back(rand() % 100 + 1);
    }
    std::sort(arr3.begin(), arr3.end());
    std::cout << "Elapsed time(vector without preset size):" << t.elapsed() << std::endl;


    return 0;
}
