#include <iostream>

///////////////////////////////////////////////////////////////////////////
// int sq_rect(int a, int b)
// {
//     return (a * b);
// }

// double sq_rect(double a, double b)
// {
//     return (a * b);
// }//vor tarber tiperi hamar nuyn irakanacumy chunenanq(vata vortev unenq kodi krknutyun,u ete mi toxi poxaren lini hskayakan algoitm,mi tex popoxutyun anes,pti etas nuyny erkrordum gtnes anes,vory ham hognacnoxa,dzandzralia u vopshm lav chi) ,stexcvela template gaxapar@
//////////////////////////////////////////////////////////////////////////////


// template <class T>
template <typename T>//T-n parametri tipna,vory shablon@ nkaragrelu jmk der anhayta,aysinqn kapvac inchvor konkret tvyali tesaki het 
T sq_rect(T a, T b)
{
    return (a * b);
}
//qani shablony chi ogtagorcvum, ayn chi poxakerpvum meqenayakan kodi


// template <typename T> T sq_rect(T a, T b)
// {
//     return (a * b);
// }sencel karanq grenq


template <typename T> T sq_rect(T a, T b);//karanq prototipy ste grenq,isk irakanacumy main-ic nerqev

int main()
{
    int res_1 = sq_rect(3, 5);//int sq_rect<int>(int a, int b)
    double res_2 = sq_rect(3.7, 5.2);//double sq_rect<double>(double a, double b)
    short res_3 = sq_rect(6, 7);//int sq_rect<int>(int a, int b);nkatenq vor int-erov exav vochte short-ov,vorovhetev kampilatori hamar karevora vohte vor short res_3 ina veragrvum funkciayi veradarcrac arjeqy,ayl vor sq_rect()-in poxancvox argumentnery int tipi en` 6 ev 7,bayc ete hstak nshenq short-i pahy,klni short-ov`
    short res_4 = sq_rect<short>(6, 7);//short sq_rect<short>(short a, short b)
    double res_5 = sq_rect(4.2f, 7.3f);//float sq_rect<float>(float a, float b)

    // double res_7 = sq_rect(3, 5.2);//error`:deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
    double res_8 = sq_rect<double>(3, 5.2);//ok

    // int x = 5;
    // int y = 7;
    // int res_6 = *sq_rect(&x, &y);//int* sq_rect<int *>(int* a, int* b);bayc esi compile errora
    return (0);
}

template <typename T> T sq_rect(T a, T b)
{
    return (a * b);
}
