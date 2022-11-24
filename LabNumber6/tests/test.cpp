#include "gtest/internal/gtest-port.h"
#include "gtest/internal/gtest-internal.h"
#include "gtest/gtest-message.h"
#include "gtest/gtest-assertion-result.h"
#include "gtest/gtest-test-part.h"
#include "gtest/gtest_pred_impl.h"
#include "gtest/gtest.h"
#include <string>
unsigned long long fast_pow(unsigned long long k, unsigned long long n, unsigned long long t)
{
    unsigned long long output = 1;
    for(int i = 0; n != 0; ++i)
    {
        if(n & 1)
        {
            output *= k;
            output %= t;
        }
        k *= k;
        k %= t;
        n >>= 1;
    }
    return output;
}

int find_number(const std::string& where, const std::string& founded)
{
    int find = 0;
    for(int j = 0; j < where.length(); ++j) {
        if (where[j] == founded[find]) {
            ++find;
        }
    }
    return find;
}

long long SolveTask5(std::string suff, std::string pref, int stroke_size, int modulo) {
        if (suff.length() + pref.length() == stroke_size) {
            return 1 % modulo;
        } else if (suff.length() + pref.length() >= stroke_size) {
            int find1 = find_number(pref, suff);
            int find2 = find_number(suff, pref);
            int find = find1 > find2 ? find1 : find2;
            if (find != 0) {
                int size = suff.length() - find + pref.length();
                if (size == stroke_size) {
                    return 1 % modulo;
                } else if (size > stroke_size) {
                    return 0 % modulo;
                } else {
                    if (suff != pref)
                        return (fast_pow(26, stroke_size - size, modulo) * 2 % modulo) % modulo;
                    else
                        return fast_pow(26, stroke_size - size, modulo);
                }
            } else {
                return 0;
            }
        } else {
            if (suff != pref)
                return (fast_pow(26, stroke_size - suff.length() - pref.length(), modulo) * 2 % modulo) % modulo;
            else
                return (fast_pow(26, stroke_size - suff.length() - pref.length(), modulo));
        }
}

int find_count(const std::string& str, const char symbol)
{
    int count = 0;
    for(const auto it : str)
    {
        if(it == symbol)
        {
            ++count;
        }
    }
    return count;
}

long long SolveTask6(std::string str)
{
    long long output = 1;
    long long division = 1;
    std::string buff;
    for(int i = str.length() - 1; i >= 0; --i)
    {
        if(find_count(buff, str[i]) == 0) {
            int find = find_count(str, str[i]);
            buff.push_back(str[i]);
            output *= i + 1;
            for (; find != 0; --find) {
                division *= find;
            }
        }
        else
            output *= i + 1;
    }
    return output / division;
}

int SolveTask7(std::string str)
{
    int greatest_size = -1;
    char buff = str[0];
    bool flag = false;
    for(int i = 0, j = str.length() - 1; i <= j; ++i, --j)
    {
        if(buff != str[i] || buff != str[j])
        {
            flag = true;
        }
        if(str[i] != str[j])
        {
            greatest_size = str.length();
            break;
        }
    }
    if(greatest_size == str.length())
        return greatest_size;
    else if(flag)
        return str.length() - 1;
    else
        return -1;
}

void SolveTask8(std::string from, std::string into) {
    std::string buffer;
    bool go_right = false;
    std::string edge_moment = "0";
    std::string edge_count;
    std::string repeat;
    int iter = from.find(into[0]);
    if (iter == -1) {
        try{
            throw 1.5;
        }catch (double a)
        {
            throw a;
        }
        std::cout << "NO\n";
    }
    while (iter != -1) {
        buffer.push_back((into[0]));
        if (buffer == into) {
            try{
                throw 1;
            }catch (int a)
            {
                throw a;
            }
            std::cout << "YES\n";
            break;
        }
        for (int count = 1; count <= into.size(); ++count) {
            if (iter == (from.length() - 1) && count == 1) {
                buffer.push_back(from[iter]);
                //--iter;
                /*if(buffer.back() == into[count])
                {
                    break;
                }*/
            } else if (iter != 0 && iter != from.length() - 1) {
                if (from[iter - 1] == into[count] && from[iter + 1] == into[count]) {
                    if (go_right == false) {
                        edge_moment.push_back(iter);
                        edge_count.push_back(count);
                        buffer.push_back(from[iter + 1]);
                        ++iter;
                    } else {
                        buffer.push_back(from[iter - 1]);
                        --iter;
                    }
                } else if (from[iter - 1] == into[count]) {
                    --iter;
                    buffer.push_back(from[iter]);
                } else if (from[iter + 1] == into[count]) {
                    ++iter;
                    buffer.push_back(from[iter]);
                } else if (edge_moment.empty()) {
                    iter = edge_moment.back();
                    int back = edge_moment.back();
                    buffer.erase(fabs(edge_moment.back() - count), count - fabs(edge_moment.back() - iter));
                    count = edge_count.back() - 1;
                    edge_moment.pop_back();
                    edge_count.pop_back();
                    go_right = true;
                } else {
                    break;
                }
            } else {
                if (iter == 0) {
                    if (from[iter + 1] == into[count]) {
                        ++iter;
                        buffer.push_back(from[iter]);
                    }
                } else {
                    if (from[iter - 1] == into[count]) {
                        --iter;
                        buffer.push_back(from[iter]);
                    }/*else if (buffer != into){
                            std::cout << "NO\n";
                        }
                        else{
                            std::cout << "YES\n";
                        }*/
                }
            }
        }
        if (buffer != into) {

            for (int f = 0; f < repeat.length(); ++f) {
                from.erase(from.find(into[0]), 1);
            }
            iter = from.find(into[0]) + repeat.length();
            repeat.push_back(from.find(into[0]));

            if (repeat.back() != -1 && iter - repeat.length() != -1) {
                for (int it = 0; it < repeat.length() - 1; ++it)
                    from.insert(repeat[it] + it, 1, into[0]);
            } else {
                try{
                    throw 1.5;
                }catch (double a)
                {
                    throw a;
                }
                iter = -1;
                std::cout << "NO\n";
            }
            buffer.erase(0, buffer.length());
        } else {
            try{
                throw 1;
            }catch (int a)
            {
                throw a;
            }
            std::cout << "YES\n";
            break;
        }
    }
}

TEST(TASK5, edge_test)
{
    std::string str1 = "aaaaa";
    std::string str2 = "aaaab";
    ASSERT_EQ(SolveTask5(str1, str2, 5, 4), 0);
    ASSERT_EQ(SolveTask5(str1, str2, 1000000000, 123), 59);
    std::string str3 = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefefabcdefabcdefabcdef";
    std::string str4 = "bcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefefabcdefabcdefabcdefg";
    ASSERT_EQ(SolveTask5(str3, str4, 200, 123), 0);
    ASSERT_EQ(SolveTask5(str3, str4, 202, 123), 52);
    ASSERT_EQ(SolveTask5(str3, str4, 199, 123), 0);
}

TEST(TASK6, edge_test)
{
    std::string str1 = "aggggggggggaag";
    ASSERT_EQ(SolveTask6(str1), 364);
    std::string str2 = "ASSERASSERTION";
    std::string str3 = "ABOBA";
    ASSERT_EQ(SolveTask6(str2), 454053600);
    ASSERT_EQ(SolveTask6(str3), 30);
}

TEST(TASK7, edge_test)
{
    std::string str1 = "aaaaaaaaaaaaaa";
    ASSERT_EQ(SolveTask7(str1), -1);
}

TEST(TASK8, edge_test)
{
    std::string str1 = "sdfghjklddsldsfvdasfsdvdasmfdsvladimfdsvadgvbhynxzcxzczxcvfserwfsdbfhjgjhgmwfgbmlkjhgvbhynxzcxzczxcvfserwfsdbfhjgjhgmwfgbmlkjhgvbhynimfdsvad";
    std::string str2 = "vadavsdfmid";
    ASSERT_THROW(SolveTask8(str1, str2), int); // YES
    str2 = "dsldsfv";
    ASSERT_THROW(SolveTask8(str1, str2), int); // YES
    str2 = "dsldsfvfsdls";
    ASSERT_THROW(SolveTask8(str1, str2), int);
    str2 = "ddavsdfmi";
    ASSERT_THROW(SolveTask8(str1, str2), int);
    str2 = "kldddlkjhgs";
    ASSERT_THROW(SolveTask8(str1, str2), double);
}