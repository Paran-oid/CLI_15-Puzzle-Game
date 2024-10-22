//
// Created by aziz on 10/22/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <algorithm>
#include <vector>
#include <random>
#include "utils.h"
#include <iostream>

const int SIZE = 4;

class game {
public:
    game()
        :m_board(4, std::vector<int>(4, 0)),
        pos_empty(3, 3),
        m_moves(0) {
        init_game();
    }

    void init_game();

    void get_board() const;
    void move_item(char input);
    void check_if_won();
    void reset();

    bool state(){return m_state;}

    friend class game;
private:
    std::vector<std::vector<int>> m_board;
    std::pair<int, int> pos_empty;
    int m_moves;
    bool m_state = false;
};
#endif //BOARD_H
