#ifndef CRUISER_H
#define CRUISER_H

#include "ship.h"

class Cruiser: public Ship
{
    public:
        Cruiser();
        virtual ~Cruiser();
        void setHealth();
        void attack(int damage, Ship* target);
        void setSize();
        void setDamage();
        int getHealth();
        int getSize();
        int getDamage();

    protected:

    private:
};

#endif // CRUISER_H
