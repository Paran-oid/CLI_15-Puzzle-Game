//
// Created by aziz on 10/22/24.
//

#ifndef BOARD_H
#define BOARD_H

#define SIZE 4
#include <algorithm>
#include <vector>
#include <random>
#include "utils.h"
#include <iostream>

class game {
public:
    game()
        :m_board(4, std::vector<int>(4, 0)),
        pos_empty(3, 3),
        m_moves(0),
        m_state(false)
    {
        init_game();
    }

    void init_game();

    void get_board() const;
    void move_item(const char input);
    void check_if_won();
    void reset();

    [[nodiscard]] bool state() const{return m_state;}

    friend class game;

private:
    std::vector<std::vector<int>> m_board;
    std::pair<int, int> pos_empty;
    int m_moves;
    bool m_state;
};
#endif //BOARD_H
