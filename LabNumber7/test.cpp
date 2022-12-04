#include "gtest/internal/gtest-port.h"
#include "gtest/internal/gtest-internal.h"
#include "gtest/gtest-message.h"
#include "gtest/gtest-assertion-result.h"
#include "gtest/gtest-test-part.h"
#include "gtest/gtest_pred_impl.h"
#include "gtest/gtest.h"
#include "4Task.h"
#include "5Task.h"

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
}