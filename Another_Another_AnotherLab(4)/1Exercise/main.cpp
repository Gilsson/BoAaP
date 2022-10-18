#include <iostream>

/*template <typename T>
std::istream& operator>>(std::istream& in, T* param)
{
    for (int i = 0;;++i) {
        std::cin >> *(param++);
        while(true) {
            if (in.fail() && (char)in.get() == 0) {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Wrong input!\n";
            }
            if (!in.fail()) {
                break;
            }
        }
        if(*(param) != 0)
            break;
    }
    return in;
}*/


int main() {
    const int k = 5;
    int array[k]{};
    for(int count = 0; count < k; ++count)
    {
        std::cin >> array[count];
    }
    int n = 6;
    for(int i = 0; i < n; ++i)
    {
        int tempInt = 0;
        tempInt = array[k - 1];
        for(int count = k - 1; count > 0; --count)
        {
            array[(count) % k] = array[(count - 1)%k];
        }
        array[0] = tempInt;
    }
    for(int count = 0; count < k; ++count)
    {
        std::cout << array[count] << " ";
    }
    return 0;
}
