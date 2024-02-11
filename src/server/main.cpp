#include <iostream>
#include <fstream>

#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

using namespace nlohmann::literals;
using namespace nlohmann;

using namespace boost::asio;
using ip::tcp;


std::string read_(tcp::socket& socket)
{
   boost::asio::streambuf buf;
   boost::asio::read_until(socket, buf, "\n");
   std::string data = boost::asio::buffer_cast<const char*>(buf.data());
   return data;
}


void send_(tcp::socket& socket, const std::string& message)
{
   const std::string msg = message + "\n";
   boost::asio::write(socket, boost::asio::buffer(message));
}


int main()
{
   //json ex1 = json::parse(R"({"request_type": "registration", "login": "ivan", "password": "123Qfaf!q24#"})");

   //std::cout << ex1 << std::endl;
   //std::ofstream o("pretty.json");
   //o << std::setw(4) << ex1 << std::endl;

   /*std::ifstream f("pretty.json");
   json data = json::parse(f);
   std::cout << data << std::endl;

   std::string request_type = data["request_type"];
   std::cout << request_type  << std::endl;

   if ("registration" == request_type)
   {
      std::cout << "It's registration!" << std::endl;
      
   }*/

   boost::asio::io_service io_service;
   
   // listen for new connection
   tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234));

   // socket creation
   tcp::socket socket_(io_service);

   // waiting for connection
   acceptor_.accept(socket_);

   // read operation
   std::string message = read_(socket_);
   std::cout << message << std::endl;

   // write operation
   send_(socket_, "Hello from server!");
   std::cout << "Server sent Hello message to Client!" << std::endl;

   return 0;
}
