#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cerr << "Invalid count" << endl;
        return (1);
    }
    PmergeMe ctr;
    try{
        ctr.sort(argv);
        // deq.fill_container(argv);
        // vec.fill_container(argv);
        // cout << "Before:  " ;
        // deq.print();

        // double time_vec = vec.calculate_time();
        // // clock_t start_vec = clock();
        // // vec.sort();
        // // clock_t end_vec = clock(); 
        // double time_deq = deq.calculate_time();
        // // clock_t start_deq = clock();
        // // deq.sort();
        // // clock_t end_deq = clock(); 
        
        // cout << "After:   ";
        // deq.print();
        // cout << "Time to process a range of "<< vec.get_ctr_size() <<  " elements with std::vector : " << time_vec << " us" << endl;
        // cout << "Time to process a range of "<< deq.get_ctr_size() <<  " elements with std::deque  : " << time_deq << " us" << endl;
    }
    catch(std::exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}