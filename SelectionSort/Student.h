//
// Created by dyq94 on 2018/11/10.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>

using namespace std;


struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {

        return score < otherStudent.score;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "student name" << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //SELECTIONSORT_STUDENT_H
