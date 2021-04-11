#include <iostream>
#include <vector>

class Student{
public:
    Student(std::string name):name(std::move(name)){};
    std::string getName(){return name;}
private:
    std::string name;
};

int main(){

    std::vector<Student> group1;
    std::vector<Student> group2;

    Student ivan("Ivan");
    Student ilya("Ilya");
    Student petya("Petya");
    Student mark("Mark");
    Student dasha("Dasha");
    Student anna("Anna");

    group1.push_back(ilya);
    group1.push_back(dasha);
    group1.push_back(petya);

    group2.push_back(ivan);
    group2.push_back(anna);
    group2.push_back(mark);

    std::vector<Student> group3;

    group3 = group2;
    std::reverse(group1.begin(),group1.end());
    group2 = group1;
    std::reverse(group3.begin(),group3.end());
    group1 = group3;

    for (auto elem:group1)
        std::cout << elem.getName()<<" ";
    std::cout<<std::endl;
    for (auto elem:group2)
        std::cout << elem.getName()<<" ";
    return 0;
}

