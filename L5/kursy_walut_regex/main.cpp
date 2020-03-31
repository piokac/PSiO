#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

int main()
{
    std::fstream file("../../suplementary/kursy.html");

    if (file.is_open()) {
        std::stringstream str_stream;
        str_stream << file.rdbuf();               //przepisuje zawartość pliku do strumienia
        std::string full_text = str_stream.str(); //zapisuje całą zawartość strumienia do std::string
        std::regex r(
            R"(<td class="bgt[12] right">(\d+) (\w{3})<\/td>\s<td class="bgt[12] right">(\d+,\d+))");

        std::smatch m;
        std::map<std::string, double>
            rates; //map stores exchange rates (a value) and currency symbol (a key)

        while (std::regex_search(full_text, m, r)) {
            //m[0] //full match of regexp
            //m[1] //group 1 - currency units i.e 1, 100, 1000
            //m[2] //group 2 - currency abreviation
            //m[3] //group 3 - exchange rate
            std::string rate = m[3];
            rate = rate.replace(rate.find(','), 1, "."); //replace decimal point
            rates[m[2]] = stod(rate) / stod(m[1]);
            full_text = m.suffix();
        }
        //iterates over map, every element is a std::pair<std::string,double>
        for (auto &el : rates) {
            std::cout << el.first << " - " << el.second << std::endl;
        }
        //alternative range-based for loop with with pair decompose
        for (auto &[key, value] : rates) {
            std::cout << key << " - " << value << std::endl;
        }
    }

    return 0;
}
