#include <iostream>
#include <vector>

 std::vector<int> binary_search( std::vector<int> big,  std::vector<int> small)
{
    if (big.size() == 1)
    {
        if (big[0] > small[0])
            big.insert(big.begin(), small[0]);
        else
            big.push_back(small[0]);
        return big;
    }
    int i = 1;
    // typename T::iterator middle = (left + right) / 2;
    while (!small.empty())
    {
        std::vector<int>::iterator middle = big.begin() + big.size() / 2;
        std::vector<int>::iterator left = big.begin();
        std::vector<int>::iterator right = big.end() - 1;
        while (left + 1 != right)
        {
            if (small[0] < *middle)
                right = middle;
            else
                left = middle;
            middle = left + std::distance(left, right) / 2;
        }
        big.insert(right, small[0]);
        small.erase(small.begin());
    }
    return big;
}

 std::vector<int> rec (std::vector<int> curr)
{
     std::vector<int> big;
     std::vector<int> small;
    if (curr.size() == 1)
        return big;
    for (size_t i = 0; i < curr.size() - 1; i+=2)
    {
        if (curr[i] > curr[i + 1])
        {
            big.push_back(curr[i]);
            small.push_back(curr[i + 1]);
        }
        else
        {
            big.push_back(curr[i + 1]);
            small.push_back(curr[i]);
        }
    }
    return binary_search(rec(big), small);
}

void print( std::vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        std::cout<<" "<<arr[i];
    std::cout<<std::endl;
}

int main()
{

    std::vector<int> arr = {1, 5, 6, 0};
    std::vector<int> res = rec(arr);
    print(res);
}