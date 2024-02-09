#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

using namespace nlohmann::literals;
using namespace nlohmann;

int main(int argc, char** argv)
{
   json ex1 = json::parse(R"({"pi": 3.131, "happy": true})");

   std::cout << ex1 << std::endl;
   std::ofstream o("pretty.json");
   o << std::setw(4) << ex1 << std::endl;

   return 0;
}
