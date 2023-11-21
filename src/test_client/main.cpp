#include "client.hpp"

int main()
{
   Client client("127.0.0.1", 8001);
   //client.SendMessage("Hello, Server!");
   client.SendRegistationRequest();
}
