#include <iostream>
#include <memory>

class Human;

class BankCell{
public:
    ~BankCell(){
        std::cout << "I am deleted" << std::endl;
    }

    friend class Human;
private:
    std::weak_ptr<BankCell> prev_owner;
    int number_of_owners = 0;
    long long int bc_value;
};

class Human{
public:
    Human(BankCell& bank_cell, std::string human_n){
        human_name = human_n;
        if (bank_cell.number_of_owners == 0){
            bank_cell.number_of_owners++;
            bank_account = std::make_shared<BankCell>(bank_cell);
            bank_cell.prev_owner = std::shared_ptr<BankCell>(bank_account);
        }else
        {
            bank_account = std::shared_ptr<BankCell>(bank_cell.prev_owner.lock());
            bank_cell.prev_owner = std::shared_ptr<BankCell>(bank_account);
        }
    }
    ~Human(){
        std::cout << human_name << " no longer holds this account" << std::endl;
    }

private:
    std::shared_ptr<BankCell> bank_account;
    std::string human_name;
};

int main(){

    BankCell bc;
    Human ivan(bc, "Ivan");
    Human ilya(bc, "Ilya");

    return 0;
}
//второй раз удаляется weak_ptr