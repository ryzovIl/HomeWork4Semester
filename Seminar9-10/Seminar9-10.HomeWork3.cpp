#include <iostream>
#include <set>
#include <boost/functional/hash.hpp>

namespace Worker
{
    struct Worker{
        int id;
        int weight;
    };

    std::size_t hash_value(Worker const& worker){
        boost::hash<int> hasher;
        return hasher(worker.id);
    }

    Worker& create_worker(){
        Worker worker = {rand()%1000000+1, rand()%1000000+1};
        return worker;
    }
}

int main() {
    int number;
    int collisions = 0;
    std::set<std::size_t> unique;
    std::size_t code;

    std::cout << "Type in number of objects you want to test" << std::endl;
    std::cin >> number;

    for (int i = 0; i < number; i++) {
        if (unique.find(code = Worker::hash_value(Worker::create_worker())) != unique.end())
            collisions++;
        else
            unique.insert(code);
    }

    std::cout << "Number of collisions: " << collisions << std::endl;
    return 0;
}