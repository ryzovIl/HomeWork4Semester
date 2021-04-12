#include <iostream>
#include <vector>
#include <random>
#include <set>
int main(){
    //1
    std::vector<int> p1 = {1,2,3,4,5,6,7,8,9,10};
    int element;
    //2
    std::cin>>element;
    while (element != 0){
        p1.push_back(element);
        std::cin>>element;
    }
    //3
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(p1), std::end(p1), rng);
    //4
    std::set<int> s( p1.begin(), p1.end() );
    p1.assign( s.begin(), s.end() );
    //5
    int num_odd = 0;
    for (auto elem:p1)
        elem % 2 ? : num_odd++;
    //6
    auto max = *(std::max_element(p1.begin(), p1.end()));
    auto min = *(std::min_element(p1.begin(), p1.end()));
    //7
    bool flag = true;
    for (auto elem:p1){
        flag = true;
        for (auto elem_test:p1)
            elem % elem_test != 0 || elem_test == elem || elem_test == 1? : flag = false;
        if (flag)
            std::cout << elem <<" is prime" << std::endl;
    }
    //8
    for (auto elem:p1)
        elem*=elem;
    //9
    std::vector<int> p2(p1.size());
    for (int i = 0; i < p2.size(); i++)
        p2[i] = rand() % 100;
    std::cout << "P2 is: ";
    for (auto elem:p2)
        std::cout << elem << " ";
    std::cout << std::endl;
    //10
    int sum = std::accumulate(p2.begin(),p2.end(),0);
    std::cout << "Sum of elements of p2 is "<< sum <<std::endl;
    //11
    for (int i = 0;i < 3; i++)
        p2[i] = 1;
    //12
    std::vector<int> p3(p2.size());
    for (int i = 0; i < p3.size(); i++)
        p3[i] = p1[i] - p2[i];
    //13
    for (int i = 0; i < p3.size(); i++)
        p3[i] < 0 ? p3[i] = 0: p3[i] = p3[i] ;
    //14
    for (int i = 0; i < p3.size(); i++)
        if (p3[i] == 0)
            p3.erase(p3.begin() + i);
    //15
    std::reverse(p3.begin(),p3.end());
    //16
    std::vector<int> max_elem(3);
    std::vector<int> p4(p3);
    for (int i = 0; i < 3; i++) {
        max_elem.push_back(*std::max_element(p4.begin(), p4.end()));
        p4.erase(std::max_element(p4.begin(), p4.end()));
    }
    //17
    std::sort(p1.begin(),p1.end());
    std::sort(p2.begin(),p2.end());
    //18
    std::vector<int> p5(p1);
    p5.insert(p5.end(),p2.begin(),p2.end());
    //20
    std::cout<<"P1: ";
    for (auto elem:p1)
        std::cout << elem << " ";
    std::cout<<"P2: ";
    for (auto elem:p2)
        std::cout << elem << " ";
    return 0;
}
