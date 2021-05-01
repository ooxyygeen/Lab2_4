//
// Created by User on 28.04.2021.
//

#ifndef LAB2_4_DATA_H
#define LAB2_4_DATA_H

struct Data{    //  Player
    char nickname;
    int rank,
    experience,
    donation;

    Data();

    Data(char c, int r, int e, int d);

    bool operator <(const Data& aSecond) const;

    bool operator >(const Data& aSecond) const;

    bool operator <=(const Data& aSecond) const;

    bool operator >=(const Data& aSecond) const;

    bool operator ==(const Data& aSecond) const;
};

#endif //LAB2_4_DATA_H
