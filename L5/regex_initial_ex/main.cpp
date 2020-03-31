#include <iostream>
#include <regex>
#include <vector>

int main()
{
    std::vector<std::string> zips = {"AB12345",
                                     "NY12346-1234",
                                     "N112345",
                                     "NY 12346      -      1234"};
    std::regex r(R"([a-zA-Z]{2}\s*\d{5}(\s*-\s*\d{4})?)");
    for (auto &el : zips) {
        std::smatch m;
        if (std::regex_match(el, m, r)) {
            std::cout << "zip is valid: " << el << std::endl;
        } else {
            std::cout << "error: invalid zip:" << el << std::endl;
        }
    }
    return 0;
}
