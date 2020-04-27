#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Board
{
    struct Node
    {
        Node() : visited(false), symbol('?') {}
        bool visited;
        char symbol;
    };

    size_t rows_, cols_;
    std::vector<std::vector<Node>> maze;

public:
    Board(size_t r, size_t c) : rows_(r), cols_(c), maze(r, std::vector<Node>(c)) {}
    void update_row(size_t row_id, const std::string &row)
    {
        //        std::cerr << row << std::endl;
        for (int i = 0; i < row.size(); i++) {
            maze[row_id][i].symbol = row[i];
        }
    }
    bool is_exit(size_t r, size_t c)
    {
        return (r == 0 || c == 0 || r == rows_ - 1 || c == cols_ - 1);
    }

    std::vector<std::pair<size_t, size_t>> neighbours(size_t row, size_t col)
    {
        std::vector<std::pair<size_t, size_t>> res;
        if (row > 0)
            if (!maze[row - 1][col].visited && maze[row - 1][col].symbol != '#')
                res.emplace_back(row - 1, col);
        if (col > 0)
            if (!maze[row][col - 1].visited && maze[row][col - 1].symbol != '#')
                res.emplace_back(row, col - 1);
        if (row < rows_ - 1)
            if (!maze[row + 1][col].visited && maze[row + 1][col].symbol != '#')
                res.emplace_back(row + 1, col);
        if (col < cols_ - 1)
            if (!maze[row][col + 1].visited && maze[row][col + 1].symbol != '#')
                res.emplace_back(row, col + 1);

        return res;
    }
    std::vector<std::pair<size_t, size_t>> find_exits(size_t pos_row, size_t pos_col)
    {
        std::vector<std::pair<size_t, size_t>> res;
        //TODO: find exits algorithm

        return res;
    }
};

int main()
{
    int W;
    int H;
    std::cin >> W >> H;
    std::cin.ignore();
    int X;
    int Y;
    std::cin >> X >> Y;
    std::cin.ignore();
    Board maze(W, H);
    for (int i = 0; i < H; i++) {
        std::string R;
        getline(std::cin, R);
        maze.update_row(i, R);
    }

    std::vector<std::pair<size_t, size_t>> res = maze.find_exits(Y, X);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    std::cout << res.size() << std::endl;
    sort(res.begin(), res.end());
    for (auto &[r, c] : res) {
        std::cout << r << " " << c << std::endl;
    }
}
