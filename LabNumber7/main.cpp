#include <iostream>
#include <fstream>
#include <iomanip>

/*long long BinPow(long long a, long long n, long long p)
{
    if(n == 0)
    {
        return 1;
    }
    if(n % 2 == 1)
    {
        return BinPow(a, n - 1, p) * a % p;
    }else {
        long long b = BinPow(a, n / 2, p);
        return b * b % p;
    }
}*/

int partition(int* arr, int start, int end)
{
    int x = arr[end];
    int i = start - 1;
    for(int j = start; j < end; ++j)
    {
        if(arr[j] <= x)
        {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    return i + 1;
}

void quicksort(int* arr,int start, int end)
{
    if(start < end)
    {
        int q = partition(arr, start, end);
        quicksort(arr, start, q - 1);
        quicksort(arr, q + 1, end);
    }
}

int main()
{
    int n;
    srand(time(NULL));
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 15 - 5;
    }
    for(int i = 0; i < n; ++i)
    {
        std::cout << std::setw(4) << arr[i] << " ";
    }
    int* sum = new int[n];
    int a = 0;
    for(int i = 0; i < n; ++i)
    {
        a += arr[i];
        sum[i] = a;
    }
    std::cout << '\n';
    for(int i = 0; i < n; ++i)
    {
        std::cout << std::setw(4) << sum[i] << " ";
    }
    //std::ofstream out("stas.txt");
   // std::cout << BinPow(120003, 120003, 1000000);
    /*auto p = new int[100000];
    srand(time(NULL));
    for(int i = 0; i < 100000; ++i)
    {
        p[i] = rand() % 100000;
       // out << p[i] << " ";
    }
    out << '\n';
    quicksort(p, 0, 99999);
    for(int i = 0; i < 100000; ++i)
    {
        out << p[i] << " ";
    }*/
    return 0;
}