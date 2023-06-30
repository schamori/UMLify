#ifndef DOGSONG_H
#define DOGSONG_H

#include <IAnimalSong.h>


class DogSong : public IAnimalSong
{
    public:
        DogSong();
        ~DogSong();
        char getTypeChar() override;
        int play(std::vector<IAnimalSong*>& animalSongs, int index) override;

    protected:

    private:
};

#endif // DOGSONG_H
