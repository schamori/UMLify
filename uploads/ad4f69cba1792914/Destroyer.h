#ifndef DESTROYER_H
#define DESTROYER_H

#include "ship.h"

class Destroyer: public Ship
{
    public:
        Destroyer();
        virtual ~Destroyer();
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

#endif // DESTROYER_H
