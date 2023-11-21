#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client
{
public:
   Client(const QString& Host, int Port);

   void SendMessage(const QString& Message);

   void SendRegistationRequest();

private:
   QTcpSocket* socket_;
};

#endif // CLIENT_H
