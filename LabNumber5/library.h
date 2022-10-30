#ifndef STATICLIB_LIBRARY_H
#define STATICLIB_LIBRARY_H

void showMatrix(long double** matrix, size_t N);

void sideDiagonal(long double** matrix, size_t N);

void mainDiagonal(long double** matrix, size_t N);

long double** FillMatrix( long long N, bool bParam);

long double PrintNum();

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
};

#endif //STATICLIB_LIBRARY_H
