#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class FieldOfLife
{
private:
    short scale_;
    char32_t ** pixels_ = nullptr;
    FieldOfLife(short scale);
    static FieldOfLife* field_;
public:
    /*short GetScale()
    {
        return scale_;
    }
    void SetScale(short scale)
    {
        if(scale > 0)
        {
            scale_ = scale;
        }
    }*/
    FieldOfLife(FieldOfLife& other) = delete;
    void operator=(const FieldOfLife&) = delete;
    static FieldOfLife* NewField(short scale);
    //FieldOfLife(short scale): scale_(scale){};
    /*~FieldOfLife(){
        std::cout << "Destrucrtor";
    }// = delete;*/
    friend std::ostream & operator<<(std::ostream& out, FieldOfLife& field);
private:
    void FillField();
};

struct Point3d{
    int x_;
    int y_;
    int z_;
    Point3d(int x, int y, int z);
    int GetXAxis();
};