#include "histogram.h"
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (size(numbers) > 0)
    {


    min=numbers[0];    // ������� �������
    max = numbers[0];

    for(double number : numbers) // ���������� �� ���� ��������� � ������� ����������� � ������������ ������� �������
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
