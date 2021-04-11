#include <boost/circular_buffer.hpp>
#include <iostream>
#include <chrono>
#include <ctime>

class User{
public:
    User(std::string email):user_email(std::move(email)){login_time = std::time(0);}
private:
    std::time_t login_time;
    std::string user_email;
};

int main(){
    boost::circular_buffer<User> circularBuffer (10);

    User mike("something@mail.ru");
    circularBuffer.push_back(mike);
    return 0;
}