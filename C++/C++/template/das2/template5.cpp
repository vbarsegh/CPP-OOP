#include <iostream>

template <typename T, size_t N>
T sum_arr(const T(&arr)[N])//es dzevy mihat jokel inchaaa!!
{
    std::cout << "N = " << N << std::endl;

    T res = 0;
    for (size_t i = 0; i < N; i++)
        res += arr[i];
    return(res);
}

int main()
{
    double data[] = {0.5, 3.2, 7.8, 3, 10.4, 5.6};
    int marks[] = {2,2,3,2,3};
    auto s1 = sum_arr(data);
    auto s2 = sum_arr(marks);

    std::cout << "s1 = " << s1 << "  s2 = " << s2 << std::endl;
}