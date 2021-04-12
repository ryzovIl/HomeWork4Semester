#include <iostream>

class Hero{
public:
    Hero(double health, double damage,std::string name):hero_health(health),hero_damage(damage),hero_name(std::move(name)){std::cout << "I am created. My name is " + hero_name << std::endl;}
    void getHit(int damage_done){
        hero_health-=damage_done;
        if (hero_health<= 0 && flag) {
            std::cout << "Oh no! I am dead. Remember my name " << hero_name + "!" << std::endl;
            flag = false;
        }
    }
    void strike(Hero& enemy){
        enemy.getHit(hero_damage*(rand()%100)/100);
    }
private:
    std::string hero_name;
    double hero_health;
    double hero_damage;
    bool flag = true;
};

int main(){

    Hero ivan(10,2,"Ivan");
    Hero ilya(10,50,"Ilya");
    ilya.strike(ivan);
    ilya.strike(ivan);
    ilya.strike(ivan);
    return 0;
}
