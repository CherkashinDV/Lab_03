
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#pragma hdrstop
#include "histogram.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-5, -8, -6}, min, max);
    assert(min == -8);
    assert(max == -5);
}
void
test_same() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_one() {
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void
test_middle_1()
{size_t middle_height;
 assert(average_column_height({10,10,10},3.0) == 10);
}
void
test_middle_2()
{size_t middle_height;
 assert(average_column_height({10,100,1},3.0) == 37);
}
int
main() {
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_middle_1();
}
