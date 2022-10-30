//
// Created by gilsson on 10/23/22.
//

#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/internal/gtest-port.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/internal/gtest-internal.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-message.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-assertion-result.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-test-part.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest_pred_impl.h"
#include "/home/gilsson/BoAaP/AnotherAnotherAnotherAnother(5)Lab/cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"

int sum(int a, int b)
{
    return a + b;
}

TEST(example, example_Test) {
    EXPECT_EQ(12, sum(4, 8));
}
