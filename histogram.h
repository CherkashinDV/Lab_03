
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include<windows.h>
#pragma hdrstop
#pragma once
#include <vector>

using namespace std;
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double>make_histogram(const vector<double>numbers,double min, double max,size_t number_count,size_t bin_count);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height,string stroke ="red" , string fill="red" );
string average_column_height(const vector<double>& bins,size_t bin_count,size_t height);
void show_histogram_svg(const vector<double>& bins,size_t bin_count);



