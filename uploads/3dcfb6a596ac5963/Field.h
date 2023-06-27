//
// Created by morit on 28.02.2023.
//
#ifndef UNTITLED5_FIELD_H
#define UNTITLED5_FIELD_H
enum status {
    empty,
    danger,
    heal,
    relict
};

class Field
{
public:
    Field(int default_height, int default_width);
    ~Field();
    enum status** get_array();
    int get_width();
    int get_height();
    int get_relicts();
private:
    enum status** array;
    int relicts;
    int width;
    int height;
};

#endif //UNTITLED5_FIELD_H
