#ifndef SHIP_H
#define SHIP_H

#include <random>
#include <algorithm>
#include <iostream>

class Ship
{
    public:
        Ship();
        virtual ~Ship();
        virtual void setHealth() = 0;
        virtual void setSize() = 0;
        virtual void setDamage() = 0;
        virtual void attack(int damage, Ship* target) = 0;
        std::string getType();
        int getHealth();
        int getSize();
        int getDamage();
        void reduceHealth(int damage, Ship* target);
        int rollCube();

    protected:
        int covering;
        int size;
        int damage;

    private:

};

#endif // SHIP_H
