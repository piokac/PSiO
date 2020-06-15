#ifndef TAICTACTOETCPSERVER_H
#define TAICTACTOETCPSERVER_H

#include "tictactoe.h"
#include <SFML/Network.hpp>
class TaicTacToeTcpServer
{
    sf::TcpListener listener;
    TicTacToe game_engine_;
    bool is_initialized_;

public:
    TaicTacToeTcpServer(int port = 2000) : is_initialized_(false), game_engine_(3)
    {
        if (listener.listen(port) != sf::Socket::Done) {
            // error...
        } else {
            is_initialized_ = true;
        }
    }
    void transform_board(const Board &b, Player *tab)
    {
        int i = 0;

        for (auto &row : b) {
            for (auto &el : row) {
                tab[i] = el;
                i++;
            }
        }
    }
    void loop()
    {
        if (is_initialized_) {
            while (1) {
                sf::TcpSocket client;
                if (listener.accept(client) != sf::Socket::Done) {
                    continue;
                }
                std::cout << "Client accepted" << std::endl;
                ComFrame input, output;
                std::size_t received;
                if (client.receive(&input, sizeof(input), received) == sf::Socket::Done) {
                    if (received == sizeof(input)) {
                        switch (input.request) {
                            output = input;
                        case Request::move: {
                            auto [player, status] = game_engine_.move(input.position, input.player);
                            output.player = player;
                            output.status = status;

                            transform_board(game_engine_.state(), output.board);
                        }
                        case Request::status: {
                            output.player = game_engine_.active_player();
                            output.status = game_engine_.is_finished();
                            transform_board(game_engine_.state(), output.board);
                        }
                        case Request::restart: {
                            game_engine_.restart();
                            output.player = game_engine_.active_player();
                            output.status = game_engine_.is_finished();
                            transform_board(game_engine_.state(), output.board);
                        }
                        }
                        if (client.send(&output, sizeof(output)) != sf::Socket::Done) {
                            // error...
                            std::cout << "Send error " << std::endl;
                        }
                    }
                }
            }
        }
    }
};

#endif // TAICTACTOETCPSERVER_H
