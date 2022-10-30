#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
};

long double PrintNum(bool IsSizeInput);

bool recursionCheck(double* arr, int start, int end);

#endif //DYNAMIC_LIBRARY_H
