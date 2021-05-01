//
// Created by User on 28.04.2021.
//

#include "data.h"
#include <cstdlib>

Data::Data() {
    nickname = 'A' + rand() % 26;
    rank = rand() % 18 + 1;
    experience = rand() % 100 + 1;
    donation = rand() % 1000001;
}

Data::Data(char c, int r, int e, int d) {
    nickname = c;
    rank = r;
    experience = e;
    donation = d;
}

bool Data::operator<(const Data &aSecond) const {
    if (experience != aSecond.experience)
        return experience < aSecond.experience;
    if (rank != aSecond.rank)
        return rank < aSecond.rank;
    if (donation != aSecond.donation)
        return donation < aSecond.donation;
    return nickname < aSecond.nickname;
}

bool Data::operator==(const Data &aSecond) const {
    return nickname == aSecond.nickname && rank == aSecond.rank
    && experience == aSecond.experience && donation == aSecond.donation;
}

//bool Data::operator>(const Data &aSecond) const {
//    if (experience != aSecond.experience)
//        return experience > aSecond.experience;
//    if (rank != aSecond.rank)
//        return rank > aSecond.rank;
//    if (donation != aSecond.donation)
//        return donation > aSecond.donation;
//    return nickname > aSecond.nickname;
//}

//bool Data::operator<=(const Data &aSecond) const {
//    return !(Data>aSecond);
//}
