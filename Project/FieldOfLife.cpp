#include "FieldOfLife.h"

FieldOfLife* FieldOfLife::field_ = nullptr;

void FieldOfLife::FillField() {
    {
        for(int i = 0; i < scale_; ++i)
        {
            for(int j = 0; j < scale_; ++j)
            {
                pixels_[i][j] = int('*');
            }
        }
    }
}

std::ostream & operator<<(std::ostream& out, FieldOfLife& field)
{
    for(int i = 0; i < field.scale_; ++i)
    {
        for(int j = 0; j < field.scale_; ++j)
        {
            out << (char)field.pixels_[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

FieldOfLife* FieldOfLife::NewField(short scale) {
    if(field_ == nullptr)
    {
        field_ = new FieldOfLife(scale);
    }
    return field_;
}

FieldOfLife::FieldOfLife(short scale) {
    scale_ = scale;
    delete[] pixels_;
    pixels_ = new char32_t * [scale_];
    for(int i = 0; i < scale_; ++i)
    {
        pixels_[i] = new char32_t [scale_];
    }
    FillField();
}

Point3d::Point3d(int x, int y, int z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

int Point3d::GetXAxis() {
    return x_;
}
