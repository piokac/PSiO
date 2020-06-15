#ifndef TICTACTOETCPPROXY_H
#define TICTACTOETCPPROXY_H
#include "tictactoe.h"
#include <SFML/Network.hpp>
class TicTacToeTcpProxy : public TicTacToeAbstract
{
    size_t size_;
    std::string ip_;
    int port_;
    ComFrame last_response_;
    Board board_;

public:
    TicTacToeTcpProxy(size_t size, std::string ip, int port = 2000)
        : size_(size), board_(size, std::vector<Player>(size, Player::null)), ip_(ip), port_(port)
    {}
    void transform_to_board(Player *tab)
    {
        for (int i = 0; i < size_; i++) {
            for (int j = 0; j < size_; j++) {
                board_[i][j] = tab[i * size_ + j];
            }
        }
    }
    std::pair<Player, Status> move(const Position &pos, Player player = Player::null)
    {
        ComFrame request, response;
        request.player = player;
        request.request = Request::move;
        request.position = pos;
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(ip_, port_);
        if (status == sf::Socket::Done) {
            if (socket.send(&request, sizeof(request)) != sf::Socket::Done) {
                // error...
                std::cout << "Send error " << std::endl;
            } else {
                std::size_t received;
                if (socket.receive(&response, sizeof(response), received) != sf::Socket::Done) {
                    last_response_ = response;
                    transform_to_board(last_response_.board);
                    return {last_response_.player, last_response_.status};
                }
            }
        } else {
            std::cout << "TCP error" << std::endl;
        }
        return {last_response_.player, last_response_.status};
    }
    Player active_player() const { return last_response_.player; } //cached
    const std::vector<std::vector<Player>> &state(bool cached = false)
    {
        if (cached) {
            return board_;
        } else {
            ComFrame request, response;

            request.request = Request::status;

            sf::TcpSocket socket;
            sf::Socket::Status status = socket.connect(ip_, port_);
            if (status == sf::Socket::Done) {
                if (socket.send(&request, sizeof(request)) != sf::Socket::Done) {
                    // error...
                    std::cout << "Send error " << std::endl;
                } else {
                    std::size_t received;
                    if (socket.receive(&response, sizeof(response), received) != sf::Socket::Done) {
                        last_response_ = response;
                        transform_to_board(last_response_.board);
                        return board_;
                    }
                }
            } else {
                std::cout << "TCP error" << std::endl;
            }
        }
    }
    Status is_finished() { return last_response_.status; }
    void restart()
    {
        ComFrame request, response;

        request.request = Request::status;

        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(ip_, port_);
        if (status == sf::Socket::Done) {
            if (socket.send(&request, sizeof(request)) != sf::Socket::Done) {
                // error...
                std::cout << "Send error " << std::endl;
            } else {
                std::size_t received;
                if (socket.receive(&response, sizeof(response), received) != sf::Socket::Done) {
                    last_response_ = response;
                    transform_to_board(last_response_.board);
                    return;
                }
            }
        }
    }
};

#endif // TICTACTOETCPPROXY_H
