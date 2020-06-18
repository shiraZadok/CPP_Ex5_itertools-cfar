//
// Created by shira on 18/06/2020.
//

#include "doctest.h"
#include <string>
#include <iostream>
#include <vector>
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"

using namespace itertools;

TEST_CASE("Test 1") {
    int count = 5;
    for (int i: range(5, 20)) {
                CHECK(i == count++);
    }

    count = 0;
    for (int i: range(0, 10)) {
                CHECK(i == count++);
    }

    count = -30;
    for (int i: range(-30, 10)) {
                CHECK(i == count++);
    }
}

TEST_CASE("Test 2") {
    vector<int> temp = {5, 11, 18, 26};
    int count = 0;
    for (int i: accumulate(range(5, 9))) {
                CHECK(temp[count++] == i);
    }

    temp = {5, 11, 18, 26, 35, 45, 56, 68, 81};
    count = 0;
    for (int i: accumulate(range(5, 14))) {
                CHECK(temp[count++] == i);
    }

    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    vector<float> temp2 = {-1, -0.7, 4.5, -3.8};
    count = 0;
    for (auto i: accumulate(vecFloat)) {   //temp2
        CHECK(temp2[count] - i < 0.01);
        if (count > 0)
            CHECK (temp2[count] != vecFloat[count]);
        count++;
    }
}

TEST_CASE("Test 3") {
    vector<string> sent = {"hello", "world", "my", "name", "is", "shoshana", "I", "like", "music"};
    vector<bool> sentBool = {true, false, true, false, true, false, true, false, true};
    int check = 0;
    for (auto i : compress(sent, sentBool)) {
        if (check%2==0)
            CHECK(sent[check++] == i);
        else
            CHECK(sentBool[check++] == false);

    }

    vector<string> sent2 = {"hello", "world", "my", "name", "is", "shoshana", "I", "like", "music"};
    vector<bool> sentBool2 = {true, false, true, false, true, false, true, false, true};
    int check2 = 0;
    for (auto i : compress(sent2, sentBool2)) {
        if (check2%2==1)
                    CHECK(sent2[check2++] == i);
        else
                    CHECK(sentBool2[check2++] == false);
    }

}

TEST_CASE("Simple Test"){
    for (int i = 0 ;i <100;i++){
                CHECK(i==i);
    }
}


