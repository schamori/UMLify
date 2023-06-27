#ifndef HUNTER_H
#define HUNTER_H

#include "ship.h"

class Hunter: public Ship
{
    public:
        Hunter();
        virtual ~Hunter();
        void setHealth();
        void setSize();
        void setDamage();
        void attack(int damage, Ship* target);
        int getHealth();
        int getSize();
        int getDamage();

    protected:

    private:
};

#endif // HUNTER_H
