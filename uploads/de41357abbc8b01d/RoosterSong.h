#ifndef ROOSTERSONG_H
#define ROOSTERSONG_H

#include <IAnimalSong.h>


class RoosterSong : public IAnimalSong
{
    public:
        RoosterSong();
        ~RoosterSong();
        char getTypeChar() override;
        int play(std::vector<IAnimalSong*>& animalSongs, int index) override;

    protected:

    private:
};

#endif // ROOSTERSONG_H
