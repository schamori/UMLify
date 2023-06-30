#ifndef CATSONG_H
#define CATSONG_H

#include <IAnimalSong.h>


class CatSong : public IAnimalSong
{
    public:
        CatSong();
        ~CatSong();
        char getTypeChar() override;
        int play(std::vector<IAnimalSong*>& animalSongs, int index) override;

    protected:

    private:
};

#endif // CATSONG_H
