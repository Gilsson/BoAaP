#include "gtest/internal/gtest-port.h"
#include "gtest/internal/gtest-internal.h"
#include "gtest/gtest-message.h"
#include "gtest/gtest-assertion-result.h"
#include "gtest/gtest-test-part.h"
#include "gtest/gtest_pred_impl.h"
#include "gtest/gtest.h"
#include "4Task.h"
#include "5Task.h"
#include "7Task.h"
#include "8Task.h"

std::string Solve7Task(int num)
{
    if(num == 0)
        return std::string();
    std::string* a = new std::string[10000];
    std::string* b = new std::string [10000];
    a[0] = "0";
    int counta = 0;
    int countb = 0;
    int sizea = 1;
    int tempsize = 0;
    int sizeb = 0;
    int k = 1;
    int find = num;
    std::string *tempa = new std::string[20000];
    while(find != 0)
    {
        for(int i = 0; i < sizea; ++i)
        {
            b[i] = a[i];
            b[i][0] = '1';
            //std::cout << b[i] << "b\n";
            ++sizeb;
            --find;
            if(find == 0) {
                return b[i];
                break;
            }
        }
        ++k;

        for(int i = 0; i < sizea; ++i)
        {
            a[i] = '0' + a[i];
            //std::cout << a[i] << "a \n";
        }
        tempsize = 0;
        for(int i = 0; i < sizea; ++i)
        {
            auto temp = to_binary_code(a[i], k);
            if(temp[0] == '0') {
                tempa[counta] = temp;
                ++tempsize;
                ++counta;
            }
        }
        for(int i = 0; i < sizeb; ++i)
        {
            auto temp = to_binary_code(b[i], k);
            if(temp[0] == '0') {
                tempa[counta] = temp;
                ++tempsize;
                ++counta;
            }
        }
        /*for(int i = 0; i < counta; ++i)
        {
            std::cout << tempa[i] << " ";
        }*/
        //std::cout << '\n';
        for(int i = 0, count = 0; count < countb; ++i, ++count)
        {

            //   std::cout << a[i] << "a\n";
        }
        counta = 0;
        sizea = tempsize;
        a = tempa;
        sizeb = 0;
    }
}

TEST(Task4, StraighForward)
{
    auto* str = new std::string[10];
    int num = 3999;
    EXPECT_EQ(*ConvertToRim(num), "MMMCMXCIX");
    for(int i = 1; i <= 10; ++i)
    {
        str[i - 1] = *ConvertToRim(i);
    }
    auto* test_str = new std::string[10]{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    EXPECT_EQ(*str, *test_str);
    EXPECT_EQ(*ConvertToRim(0), "");
    EXPECT_EQ(*ConvertToRim(-5), "");
}

TEST(Task5, TestNum)
{
    long long n = 88005553535;
    EXPECT_EQ(CountInterestingInInterval(n), 8800555353);
    n = 0;
    EXPECT_EQ(CountInterestingInInterval(n), 0);
}

TEST(Task7, TestBinDec)
{
    EXPECT_EQ(Solve7Task(10000), "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    EXPECT_EQ(Solve7Task(0), "");
}

TEST(Task8, Test){
    EXPECT_EQ(ToUnrealForm(ConverToThird(30)), "233");
    EXPECT_EQ(ToUnrealForm(ConverToThird(9)), "23");
    EXPECT_EQ(ToUnrealForm(ConverToThird(1)), "1");
    EXPECT_EQ(ToUnrealForm(ConverToThird(81)), "2223");
    EXPECT_EQ(ToUnrealForm(ConverToThird(243)), "22223");
    EXPECT_EQ(ToUnrealForm(ConverToThird(729)), "222223");
}
