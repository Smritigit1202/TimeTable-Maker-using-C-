#include <iostream>
#include <sstream>
#include <fstream>
#include "timetable.h"
#include "dept.h"

using namespace std;

void rules();

int *parse(string);

int *getInput(dept &);

timetable maketimetable(scalar<duo<int, string>> &, int *, int);