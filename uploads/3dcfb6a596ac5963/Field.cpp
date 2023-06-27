#include "Field.h"
#include <string>

int Field::get_width() {
    return width;
}

int Field::get_height() {
    return height;
}

int Field::get_relicts() {
    return relicts;
}

Field::Field(int default_height, int default_width) {
    relicts = 0;
    width = default_height;
    height = default_width;
    array = new enum status*[height];
    for (int i = 0; i < height; i++) {
        array[i] = new enum status[width];
    }
        while (relicts <= 0) {
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                int random = rand() % 10 + 1;
                if (random <= 4 ){
                    array[i][j] = empty;
                } else if (random <= 8){
                    this->array[i][j] = danger;
                } else if (random == 9){
                    this->array[i][j] = heal;
                } else {
                    this->array[i][j] = relict;
                    relicts++;
                }
            }
        }
    }
}

Field::~Field() {
    for (int i = 0; i < height; i++) {
        delete array[i];
    }
    delete array;
}




enum status** Field::get_array() {
    return array;
}


