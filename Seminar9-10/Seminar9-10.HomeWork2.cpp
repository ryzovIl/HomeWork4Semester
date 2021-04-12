#include <iostream>
#include <iomanip>

int main(){
    long double user_input;

    std::cin.imbue(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << "Введите сколько хотите перевести в рубли в формате xxx.xx: ";
    std::cin >> std::get_money(user_input);

    std::cout.imbue(std::locale("ru_RU.UTF-8"));
    std::cout << "Результат: ";
    std::cout << std::showbase << std::put_money(user_input*74);

    return 0;
}//USD -> RUB (12.04.21)
