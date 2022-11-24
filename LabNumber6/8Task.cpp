#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int q = 0;
    std::cin >> q;
    for(;q != 0; --q) {
        std::string from;
        std::string into;
        std::string buffer;
        bool go_right = false;
        int count_of_rotation = 0;
        std::string edge_moment = "0";
        std::string edge_count;
        std::cin >> from >> into;
        std::string repeat;
        int iter = from.find(into[0]);
        if(iter == -1)
        {
            std::cout << "NO\n";
        }
        while(iter != -1) {
            buffer.push_back((into[0]));
            if(buffer == into)
            {
                std::cout << "YES\n";
                break;
            }
            for (int count = 1; count <= into.size(); ++count) {
                if (iter == (from.length() - 1) && count == 1) {
                    buffer.push_back(from[iter]);
                    --iter;
                    count_of_rotation++;
                    /*if(buffer.back() == into[count])
                    {
                        break;
                    }*/
                } else if (iter != 0 && iter != from.length() - 1) {
                    if (from[iter - 1] == into[count] && from[iter + 1] == into[count]) {
                        if (count_of_rotation == 0 && go_right == false) {
                            edge_moment.push_back(iter);
                            edge_count.push_back(count);
                            buffer.push_back(from[iter + 1]);
                            ++count_of_rotation;
                            ++iter;
                        } else if(go_right == true){
                            buffer.push_back(from[iter - 1]);
                            --iter;
                        }else{
                            std::cout << "NO";
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
                    }else{
                        break;
                    }
                }else{
                    if(iter == 0)
                    {
                        if (from[iter + 1] == into[count]) {
                        ++iter;
                        buffer.push_back(from[iter]);
                        }
                    }
                    else{
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
            if(buffer != into) {

                for(int f = 0; f < repeat.length(); ++f) {
                    from.erase(from.find(into[0]), 1);
                }
                iter = from.find(into[0]) + repeat.length();
                repeat.push_back(from.find(into[0]));
                count_of_rotation = 0;
                if (repeat.back() != -1 && iter - repeat.length() != -1) {
                    for(int it = 0; it < repeat.length() - 1; ++it)
                    from.insert(repeat[it] + it, 1, into[0]);
                }else{
                    iter = -1;
                    std::cout << "NO\n";
                }
                buffer.erase(0, buffer.length());
            }
            else
            {
                std::cout << "YES\n";
                break;
            }
        }
    }
}
