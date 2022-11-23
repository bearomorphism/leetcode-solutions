#include <compare>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

strong_ordering operator<=>(string a, string b) {
    auto x = a.compare(b);
    if (x < 0) return strong_ordering::less;
    if (x == 0) return strong_ordering::equal;
    return strong_ordering::greater;
}

int main() {
    // int a = 1, b = 2;
    string a("123");
    string b("124");

    // auto res = make_tuple(1, 2, 3) <=> make_tuple(1, 2, 4);
    auto res = a <=> b;
    if (res > 0) cout << "a > b";
    else if (res == 0) cout << "a == b";
    else if (res < 0) cout << "a < b";
    cout << '\n';
    return 0;
}

// #include <compare>
// #include <iostream>
// #include <string>
// #include <vector>

// int main() {

//     std::cout << std::endl;

//     int a(2011);
//     int b(2014);
//     auto res = a <=> b;                 // (1)
//     if (res < 0) std::cout << "a < b" << std::endl;
//     else if (res == 0) std::cout << "a == b" << std::endl;
//     else if (res > 0) std::cout << "a > b" << std::endl;

//     std::string str1("2014");
//     std::string str2("2011");
//     auto res2 = str1 <=> str2;          // (2)
//     if (res2 < 0) std::cout << "str1 < str2" << std::endl;
//     else if (res2 == 0) std::cout << "str1 == str2" << std::endl;
//     else if (res2 > 0) std::cout << "str1 > str2" << std::endl;

//     std::vector<int> vec1{1, 2, 3};
//     std::vector<int> vec2{1, 2, 3};
//     auto res3 = vec1 <=> vec2;          // (3)
//     if (res3 < 0) std::cout << "vec1 < vec2" << std::endl;
//     else if (res3 == 0) std::cout << "vec1 == vec2" << std::endl;
//     else if (res3 > 0) std::cout << "vec1 > vec2" << std::endl;

//     std::cout << std::endl;

// }