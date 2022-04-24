#include "histogram.h"
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (size(numbers) > 0)
    {


    min=numbers[0];    // границы корзины
    max = numbers[0];

    for(double number : numbers) // проходимся по всем элементам и находим минимальную и максимальную границу корзины
    {
            if(min>number)
        {
            min=number ;
        }
        else if(max<number)
        {
            max=number;
        }



    }
    }
}
