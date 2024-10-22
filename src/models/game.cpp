//
// Created by aziz on 10/22/24.
//

#include "game.h"
void game::get_board() const {
    for(int i = 0; i < 4; i++)
        std::cout << std::endl;
    std::cout << "moves: " << m_moves << '\n';
    if(!m_state) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(m_board[i][j] != 0)
                    std::cout << '|' <<  m_board[i][j] << '|';
                else
                    std::cout << '|' << ' ' << '|';
            }
            std::cout << '\n';
        }
    }
    else {
        std::cout << "you won!! \n";
    }

}

void game::move_item(char input) {
    ++m_moves;
    switch(input) {
        case 'z':
            if(pos_empty.first != SIZE - 1) {
                std::swap(m_board[pos_empty.first][pos_empty.second], m_board[pos_empty.first + 1][pos_empty.second]);
                ++pos_empty.first;
            }
        break;
        case 's':
            if(pos_empty.first != 0) {
                std::swap(m_board[pos_empty.first][pos_empty.second], m_board[pos_empty.first - 1][pos_empty.second]);
                --pos_empty.first;
                break;
        case 'q':
            if(pos_empty.second != SIZE - 1) {
                std::swap(m_board[pos_empty.first][pos_empty.second], m_board[pos_empty.first][pos_empty.second + 1]);
                ++pos_empty.second;
            }
        break;
        case 'd':
            if(pos_empty.second != 0) {
                std::swap(m_board[pos_empty.first][pos_empty.second], m_board[pos_empty.first][pos_empty.second - 1]);
                --pos_empty.second;
            }
        break;
        default:
            throw std::runtime_error("couldn't process user input!");
            }
    }
}

void game::check_if_won() {
    int expected_val = 1;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(i == SIZE - 1 && j == SIZE - 1) {
                continue;
            }
            if(m_board[i][j] != expected_val) {
                return;
            }
            expected_val++;
        }
    }
    m_state = true;
}

void game::reset() {
    init_game();
}

void game::init_game() {
    std::vector<int> numbers;
    for(int i = 1; i <= 15; i++) {
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<>(1, 15);
    std::shuffle(numbers.begin(), numbers.end(), mt);

    int k = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(i == SIZE - 1 && j == SIZE - 1)
                m_board[i][j] = 0;
            m_board[i][j] = numbers[k++];
        }
    }
}

