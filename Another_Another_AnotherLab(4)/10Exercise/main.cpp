#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int* plugs = new int[N];
    for(int count = 0; count < N; ++count)
    {
        std::cin >> plugs[count];
    }
    int sockets = 0;
    for(int count = 0; count < N; ++count)
    {
        if(plugs[count] > 0) {
            sockets += plugs[count] - 1;
        }
    }
    sockets += 1;
    std::cout << sockets;
    return 0;
}
