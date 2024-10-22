#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <cmath>

void	get_that_r_ery_xary_kongruent(int n0, int lambda, int m, int myu);
void veybal(double veybali_xi[], double arr_r[], int *count, const double T, int hayteri_qanak);
int mutq(double mutq_ti[], double arr_r[], const double T, int count);

using namespace std;

int main()
{
    int n0;

    cout << "n0 = ";
    cin >> n0;
    while (!(n0 > 0 && n0 % 2 == 1))
    {
        cout << "n0 = ";
        cin >> n0;
    }
	int myu;
	do {cout << "myu = ";cin >> myu;}
	while (myu <= 0);
	int k = 6;//vor r-ery 32hat stanam
    int lambda;
    int sign;
    do
	{
		cout << "please write only + or - \nNote:+ is 1, - is -1\n";
    	cin >> sign;
	}while (!(sign == 1 || sign == -1));
	// {
	// 	cout << "please write only + or - \nNote:+ is 1, - is -1\n";
    // 	cin >> sign;
	// }
    int t;
	do {cout << "t = ";cin >> t;}
	while (t < 1);

    switch(sign)
    {
        case(1):
            lambda = 8 * t + 3;
            break;
        case(-1):
            lambda = 8 * t - 3;
            break;
        default:
            cout << "incorrect sign";
            break;
    }
	int m = pow(2, k);
	get_that_r_ery_xary_kongruent(n0 ,lambda, m, myu);
    // get_that_r_ery_kongruent(n0 ,lambda, m);
}

void	get_that_r_ery_xary_kongruent(int n0, int lambda, int m,int myu)
{
	double arr_r[10000];
	int ni = -1;
	int temp = n0;
	int count = 0;
	cout << n0 << " "<< " "<< lambda << " "<< m;
	for (int i = 0; ni != n0; i++)
	{
		ni = (temp * lambda + myu) % m;
		arr_r[i] = (double)ni / m;
		// cout << "n = " << ni << endl;
		cout << "r[" << i << "]= " << arr_r[i] << endl;
		temp = ni;
		count++;
	}
    const double T = 150.0;
    double	mutq_ti[1000];
	int hayteri_qanak = mutq(mutq_ti, arr_r, T, count);
    double	veybali_xi[1000];
    veybal(veybali_xi, arr_r, &count, T, hayteri_qanak);

}

void veybal(double veybali_xi[], double arr_r[], int *count, const double T, int hayteri_qanak)
{
    double ri_mul ;
    const int betta = 3;//kori dzevi parametr
	int alfa = 2;//alfan > 0ic,masshtabayin parametr
    int i = 0;
    int j = 0;
    double foo = -1 *  pow(alfa, -1);
    cout << "foo = "<<pow(betta, -1) <<endl;
    
    while(hayteri_qanak)
    {
        veybali_xi[i] = pow(foo * log(arr_r[i]),pow(betta, -1));
        cout << "erlangi i-in = " << veybali_xi[i] << endl;
        i++;
        hayteri_qanak--;
    }
    cout << "i = " << i << endl;
}


int mutq(double mutq_ti[], double arr_r[], const double T, int count)
{
    // cout << "&? = " << count;
	const int a = 4;
	const int b = 8;
	int	t0 = 0;
	// double	mutq_ti[1000];//muqti t-erna//amen tarr iranic nerkayacnuma tvyal i-rd hayti skzbi jmky
	// arr_ti[0] = 0;
	double arr_tau[1000];
	int i = 0;
    mutq_ti[0] = 0;
    double temp = mutq_ti[0];
	while(temp < T && i < count)//nra hamar vor r-ery karoxa prcac lini bayc der temp poqr ylni T-ic
	{
		// cout << "eee" << endl;
		arr_tau[i] = a + (b - a) * arr_r[i];
		if (i == 0)
			mutq_ti[i] = 0 + arr_tau[i];
		else
        {
            if(mutq_ti[i - 1] + arr_tau[i] < T)
                mutq_ti[i] = mutq_ti[i - 1] + arr_tau[i];
            else
                break;
        }
        // cout << "mutqi ti = " << mutq_ti[i] << endl;
        temp = mutq_ti[i];
		i++;
	}
	int hayteri_qanak = i;//i - 1 che vortev mer mot i-n 0-ica sksvum
	cout << "qanak = " << hayteri_qanak << endl;
    return (hayteri_qanak);
}
