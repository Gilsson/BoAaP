#include <iostream>

int FindMaxElementIndex(int* array, size_t size);
int FindMinElementIndex(int* array, size_t size);

int main() {
    int size;
    std::cin >> size;
    int* array = new int[size];
    for(int count = 0; count < size; ++count)
    {
        std::cin >> array[count];
    }
    int MaxIndex = FindMaxElementIndex(array, size);
    int MinIndex = FindMinElementIndex(array, size);
    if(MinIndex > MaxIndex)
    {
        int temp;
        temp = MaxIndex;
        MaxIndex = MinIndex;
        MinIndex = temp;
    }
    for (int count = MinIndex + 1; count < MaxIndex; ++count) {
        array[count] = 0;
    }
    if(MaxIndex - MinIndex - 1 > size / 2)
    {
        int* new_array = new int[size - (MaxIndex - MinIndex + 1)];
        int index = 0;
        for(int count = 0; count <= MinIndex; ++count, ++index)
        {
            new_array[index] = array[count];
            std::cout << new_array[index] << " ";
        }
        for(int count = MaxIndex; count < size; ++count, ++index) {
            new_array[index] = array[count];
            std::cout << new_array[index] << " ";
        }
        delete[] new_array;
    }else{
        for(int count = 0; count < size; ++count)
        {
            std::cout << array[count] << " ";
        }
    }
    delete[] array;
    return 0;
}
int FindMaxElementIndex(int* array, size_t size)
{
    int Index = 0;
    int MaxElement = array[0];
    for(int count = 1; count < size; ++count)
    {
        if(MaxElement < array[count])
        {
            MaxElement = array[count];
            Index = count;
        }
    }
    return Index;
}
int FindMinElementIndex(int* array, size_t size)
{
    int Index = 0;
    int MinElement = array[0];
    for(int count = 1; count < size; ++count)
    {
        if(MinElement > array[count])
        {
            MinElement = array[count];
            Index = count;
        }
    }
    return Index;
}