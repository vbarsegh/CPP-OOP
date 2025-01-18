#include <iostream>
//const_cast-@ const avelacnelu ev constic zrkelu hamara
int main()
{
    // const int a;
    // int* ptr_a = &a;voch const cucichy chi kara cuyc const popoxakani hascei vra
    int a;
    const int* ptr_a = &a;//bayc const cucichy kkara  cuyc ta voch const popoxakani hascei vra
    int *ptr = const_cast<int *>(ptr_a);
    const int* ptr_cnst = const_cast<const int*>(ptr);//kam  const int* ptr_cnst = const_cast<const int*>(&a);

    const double b = 10;
    const double& lnk_b_var = b;
    double& lnk_b = const_cast<double&>(b);//kam double& lnk_b = const_cast<double&>(lnk_b_var);
    const double& lnk_b_const = const_cast<const double&>(lnk_b);

    double d = const_cast<double>(b);//esi compile chi lini,vortev const_cast-ery ogtagorcvum en miayn pointerneri i reference-neri depqum
}