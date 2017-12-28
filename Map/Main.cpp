#include "Map.hpp"

int main()
{
    MapCSen x;
    x["aaa"] = 12;
    std::cout << "caseSensitive\n" << x["aaa"] << std::endl;
    x["bbb"] = 5;
    std::cout << x["bbb"] << std::endl;

    x["ccc"] = x["bbb"];
    std::cout << x["ccc"] << std::endl;
    MapCSen y = x;

    std::cout << y["aaa"] << std::endl;
    std::cout << y["bbb"] << std::endl;
    std::cout << y["ccc"] << std::endl;

    MapCnSen z;
    z["aBc"] = 88;
    z["abc"] = 365;
    std::cout << "caseNotSensitive\n" << z["ABc"] << std::endl;

    //z = y;  //not Allowed
    //y = z; //inaccesible

}
