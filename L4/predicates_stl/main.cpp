#include <algorithm>
#include <iostream>
#include <vector>

bool cmp_down(const int &a, const int &b)
{
    return b < a;
}

struct Person
{
    std::string first_name;
    int age;
};
bool cmp_by_name(const Person &a, const Person &b)
{
    return b.first_name < a.first_name;
}
bool cmp_by_age(const Person &a, const Person &b)
{
    return b.age < a.age;
}
void display(const std::vector<Person> person_set)
{
    for (auto &el : person_set) {
        std::cout << el.first_name << " - " << el.age << std::endl;
    }
}
void display(const std::vector<int> &array)
{
    for (auto el : array) {
        std::cout << el << std::endl;
    }
}
int main()
{
    //sorting array of ints
    std::vector<int> tab = {1, 5, -9, 7, 0, 12, -90};
    //sorting in default ascending order
    std::cout << "Ascending order int array sort" << std::endl;
    sort(tab.begin(), tab.end());
    display(tab);

    //sorting in descendinf order usinf predicate function
    std::cout << "Sorting in descendinf order using predicate function" << std::endl;
    sort(tab.begin(), tab.end(), cmp_down);
    display(tab);

    // sorting in descending order using lambda expression predicate
    std::cout << "Sorting in descendinf order using lambda expression predicate" << std::endl;
    sort(tab.begin(), tab.end(), [](const int &e1, const int &e2) { return e2 > e1; });
    display(tab);
    //------------------------------

    //sorting array of structures
    std::cout << "Array of structures example" << std::endl;

    std::vector<Person> subjects = {{"Alan", 20}, {"Michael", 19}, {"Jack", 30}};

    std::cout << "Using function predicate by age" << std::endl;
    sort(subjects.begin(), subjects.end(), cmp_by_age); //sort wrt age (see cmp_by_age(..) predicate
    display(subjects);

    std::cout << "Using function lambda predicate by name" << std::endl;
    sort(subjects.begin(), subjects.end(), [](const Person &a, const Person &b) {
        return a.first_name < b.first_name;
    }); //sort wrt first_name (see also cmp_by_name(..) predicate
    display(subjects);

    return 0;
}
