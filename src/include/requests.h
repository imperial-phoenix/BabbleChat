#ifndef REQUESTS_H
#define REQUESTS_H

#include <string>

namespace BabbleChat {

enum class RequestType
{
   Auth,
};

struct Request
{
protected:
   RequestType type_;
};

struct RegistrationRequest : Request
{
private:
   std::string login_;
   std::string password_;
};

struct ReginstationResponse : Request
{
private:
   std::string login_;
   std::string error_msg_;
   bool response_status_;
};

}

#endif // REQUESTS_H