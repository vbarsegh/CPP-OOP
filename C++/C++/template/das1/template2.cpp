#include <iostream>

// template <class T>
template <typename T>//T-n parametri tipna,vory shablon@ nkaragrelu jmk der anhayta,aysinqn kapvac inchvor konkret tvyali tesaki het 
T sq_rect(const T& a, const T& b)
{
    return (a * b);
}
//qani shablony chi ogtagorcvum, ayn chi poxakerpvum meqenayakan kodi


template <typename T>//T-n parametri tipna,vory shablon@ nkaragrelu jmk der anhayta,aysinqn kapvac inchvor konkret tvyali tesaki het 
void swap(T* x, T* y)
{
    T temp = *x;
   *x = *y;
   *y = temp;
}
int main()
{
    //////////////////////////
    int res_1 = sq_rect(3, 5);//int sq_rect<int>(const int& a, const int& b)
    double res_2 = sq_rect(3.7, 5.2);//double sq_rect<double>(const double& a, const double& b)
    short res_3 = sq_rect(6, 7);//int sq_rect<int>(const int& a, const int& b);
    // nkatenq vor int-erov exav vochte short-ov,vorovhetev kampilatori hamar karevora vohte vor 
    // short res_3 ina veragrvum funkciayi veradarcrac arjeqy,ayl vor sq_rect()-in poxancvox argumentnery       T sq_rect(const T& a, const T& b)
    // int tipi en` 6 ev 7,bayc ete hstak nshenq short-i pahy,klni short-ov`
    short res_4 = sq_rect<short>(6, 7);//short sq_rect<short>(const short& a, const short& b)
    double res_5 = sq_rect(4.2f, 7.3f);//float sq_rect<float>(const float& a, const float& b)

    // double res_7 = sq_rect(3, 5.2);//error`:deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
    double res_8 = sq_rect<double>(3, 5.2);//ok
    /////////////////////////////


    ////////////////////////////////////////
    double x = 5.2;
    double y = 7.2;
    swap(&x, &y);//void swap<double>(double* x, double* y);         void swap(T* x, T* y)
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    ////////////////////////////////////////
    return (0);
}

