#include <iostream>

#include <array>
#include <memory>

#include "game.h"
#include "user.h"
#include "utils.h"

int main() {
    auto g= std::make_unique<game>();
    //ask for name
    {
        std::string username;
        std::cout << "enter your username \n" ;
        std::cin >> username;
        auto u= make_unique<user>(username);
    }

    while(true) {
        g->check_if_won();
        g->get_board();

        if(g->state()) {
            char choice;
            do {
                std::cout << "would you like to restart? (Y/n)" << std::endl;
                std::cin >> choice;
            }while(std::toupper(choice) != 'N' && std::toupper(choice) != 'Y');

            if(std::toupper(choice) == 'N') break;
            else g->init_game();
        }
        char input;
        std::cin >> input;
        if(input != ';')
            g->move_item(input);
        else
            break;
    }
    std::cout << "thank you for trying my program! \n";
    return 0;
}
