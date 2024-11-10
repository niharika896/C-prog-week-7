#include <stdio.h>
struct dob{
    int date;
    int month;
    int year;
};

struct student {
    struct dob dob;
};

int main(){
    struct student student;
    student.dob.date = 27;
    student.dob.month = 8;
    student.dob.year = 2006;

    return 0;
}
