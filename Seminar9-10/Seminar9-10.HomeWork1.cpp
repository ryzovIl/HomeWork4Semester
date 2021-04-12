#include <iostream>
#include <boost/multi_array.hpp>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    typedef boost::multi_array<double, 2> array_type;
    typedef array_type::index index;
    const int rows = 2;
    const int cols = 5;
    std::vector<std::vector<double>> copy_vector = {{1,2,3,4,5},{6,7,8,9,10}};
    array_type A(boost::extents[rows][cols]);
    array_type::element *itr = A.data();

    auto vec_pointer = copy_vector.begin();
    for (int i = 0; i < rows * cols; i++)
        *(itr++) = *(vec_pointer++);

    cout << "Displaying matrix" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
