#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

//function predicate finds positive values
bool positive(const float &el)
{
    return el > 0;
}

//fixed-type functor:
class Threshold_float
{
    float th_;

public:
    void set_th(float th) { th_ = th; }
    Threshold_float(float th) : th_(th) {}
    bool operator()(const float &el) { return el > th_; } //call operator
};

//template based treshold functor
template<class T>
class Threshold
{
    T th_;

public:
    void set_th(T th) { th_ = th; }
    Threshold(T th) : th_(th) {}
    bool operator()(const T &el) { return el > th_; }
};

void print(std::list<float> elements_list)
{
    for (auto &el : elements_list) {
        std::cout << el << std::endl;
    }
}
int main()
{
    std::vector<float> tab = {-5, 5, 8, -15, 30};
    std::list<float> thresholded_list;
    std::vector<std::string> words = {"ala", "kot", "pies"};
    std::list<std::string> words_list;

    //copies elements above the threshold

    //#1 using predicate function (works only for fixed thershol 0
    std::copy_if(tab.begin(), tab.end(), back_inserter(thresholded_list), positive);
    print(thresholded_list);

    //#2 using lambda expression with threshold in capture list
    float th = 5;
    std::copy_if(tab.begin(), tab.end(), back_inserter(thresholded_list), [th](const float &el) {
        return el > th;
    });
    print(thresholded_list);

    //#3 using a concrete functor
    Threshold_float th_functor_float(5);
    std::copy_if(tab.begin(), tab.end(), back_inserter(thresholded_list), th_functor_float);
    print(thresholded_list);

    //#4 using a generic (template) functor for float type elements
    Threshold<float> th_functor(5);
    std::copy_if(tab.begin(), tab.end(), back_inserter(thresholded_list), th_functor);
    print(thresholded_list);

    th_functor.set_th(0);
    std::copy_if(tab.begin(), tab.end(), back_inserter(thresholded_list), th_functor);
    print(thresholded_list);

    //#5 using a generic (template) functor for string type elements
    Threshold<std::string> th_functor_str("aa");
    std::copy_if(words.begin(), words.end(), back_inserter(words_list), th_functor_str);
    for (auto &el : words_list) {
        std::cout << el << std::endl;
    }

    return 0;
}
