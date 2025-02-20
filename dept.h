#ifndef _DEPT_
#define _DEPT_
#include "../includes/scalar.h"
#include "course.h"
#include "../includes/pair.h"

class dept
{
public:
    dept();
    ~dept();
    void setName(string);
    string getName();
    int *getMaxClass();
    void setMaxClass(int *);
    int *getClassDur();
    void setClassDur(int *);
    int getBreak();
    void setBreak(int);
    void insertCourse(int, course);
    friend ostream &operator<<(ostream &, const dept &);
    bool checkData();
    scalar<duo<int, string>> extractData();

private:
    int *max_class, *class_dur;
    int Break;
    string name;
    scalar<course> *d;
};

#endif