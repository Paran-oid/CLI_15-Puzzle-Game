#include <iostream>
#include <limits>
#include <algorithm>
#include <array>

#include "game.h"
#include "user.h"
#include "utils.h"

int main() {
    game g;
    user u;
    std::array<char,4> keys= {'z', 's', 'q', 'd'};

    char dummy;
    std::cout << "enter your username \n" ;
    std::cin >> u;
    std::cout << "when you want to quit enter ;(press any key to start)" << '\n';
    std::cin >> dummy;

    while(true) {
        g.check_if_won();
        g.get_board();
        if(g.state()) {
            char choice;
            std::cout << "would you like to restart? (Y/n)" << std::endl;
            std::cin >> choice;
            if(std::toupper(choice) == 'N')
                break;
            else
                g.reset();
                continue;
        }
        char input;
        std::cin >> input;
        if(input != ';')
            g.move_item(input);
        else
            break;
    }
    std::cout << "thank you for trying my program! \n";
    return 0;
}
