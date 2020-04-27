#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
//using namespace std;
enum class City {
    None,
    Szczecin,
    Poznan,
    Gdansk,
    Wroclaw,
    Olsztyn,
    Warszawa,
    Krakow,
    Lublin,
    Zamosc
};
const std::vector<std::string> cities{"None",
                                      "Szczecin",
                                      "Poznan",
                                      "Gdansk",
                                      "Wroclaw",
                                      "Olsztyn",
                                      "Warszawa",
                                      "Krakow",
                                      "Lublin",
                                      "Zamosc"};
struct Edge
{
    Edge(City c1, City c2, unsigned int distance) : road(c1, c2), distance_(distance) {}
    std::pair<City, City> road; //edge definition
    unsigned int distance_;     //distance between 2 nodes
};
bool operator==(const Edge &c1, const Edge &c2)
{
    return (c1.road.first == c2.road.first && c1.road.second == c2.road.second)
           || (c1.road.first == c2.road.second && c1.road.second == c2.road.first);
}
bool operator==(const City &c1, const Edge &c2)
{
    return (c1 == c2.road.first) || (c1 == c2.road.second);
}

class Planner
{
    using Distance = unsigned int;
    std::vector<Edge> routes_; //represents edges of the graph
    struct CityInfo
    {
        CityInfo(Distance distance = 0, City city = City::None)
            : distance_(distance), previous_city_(city), visited_(false)
        {}
        Distance distance_;  //cumulated distance in spanning tree
        City previous_city_; // previous city (according cummulated distance)
        bool visited_;       //true if node was visited
    };

    std::map<City, CityInfo> spanning_tree_; //represents values in Dijkstra algorithm

public:
    Planner(const std::vector<Edge> &routes) : routes_(routes) {}
    std::pair<Distance, City> update_distance(const City &from, const Edge &e)
    {
        City to = e.road.first;
        if (from == e.road.first)
            to = e.road.second;
        auto itr = spanning_tree_.find(to);
        if (itr != spanning_tree_.end()) {
            //TODO: update spanning tree node
        } else {
            //TODO: add node to spanning tree
        }
        return {e.distance_, to};
    }

    std::vector<std::pair<Distance, City>> neighbours(const City &c)
    {
        std::vector<std::pair<Distance, City>> res;
        for (const auto &road : routes_) {
            if (c == road) {
                //For connected node:
                //1. update distance
                //2. add to neighbours list
            }
        }
        //        sort neighbours list wrt edge weight
        return res;
    }

    void find_rec(const City &current, const City &to)
    {
        spanning_tree_[current].visited_ = true;
        //1. update neighbours cummulated distance
        //2. visit all nodes which were not visited according DFS

        return;
    }

    Distance find_route(const City &from, const City &to)
    {
        spanning_tree_.clear();
        //insert the root to spanning tree
        spanning_tree_[from] = {0, from};

        //start DFS
        find_rec(from, to);

        //Print results
        std::cout << "Route found, distance: " << spanning_tree_[to].distance_ << std::endl;

        City current = to;
        std::cout << cities[static_cast<int>(current)] << std::endl;
        while (current != from) {
            current = spanning_tree_[current].previous_city_;
            std::cout << cities[static_cast<int>(current)] << std::endl;
        }
        return spanning_tree_[to].distance_;
    }
};

int main()
{
    std::vector<Edge> routes = {{City::Szczecin, City::Poznan, 234},
                                {City::Szczecin, City::Wroclaw, 371},
                                {City::Szczecin, City::Gdansk, 348},
                                {City::Poznan, City::Wroclaw, 178},
                                {City::Poznan, City::Warszawa, 310},
                                {City::Poznan, City::Gdansk, 298},
                                {City::Wroclaw, City::Warszawa, 344},
                                {City::Wroclaw, City::Lublin, 428},
                                {City::Wroclaw, City::Krakow, 268},
                                {City::Krakow, City::Warszawa, 295},
                                {City::Krakow, City::Lublin, 269},
                                {City::Lublin, City::Warszawa, 161},
                                {City::Lublin, City::Zamosc, 89},
                                {City::Olsztyn, City::Warszawa, 213},
                                {City::Olsztyn, City::Gdansk, 156},
                                {City::Gdansk, City::Warszawa, 339}};
    Planner p(routes);
    p.find_route(City::Gdansk, City::Zamosc);

    return 0;
}
