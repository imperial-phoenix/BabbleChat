#include <QJsonObject>
#include <QJsonDocument>

#include "client.hpp"

Client::Client(const QString& Host, int Port)
{
   socket_ = new QTcpSocket();
   socket_->connectToHost(Host, Port);

   if (!socket_->waitForConnected())
   {
      qDebug() << "Error: " << socket_->errorString();
   }
}


/*void Client::SendMessage(const QString& Message)
{
   if (socket_->state() == QTcpSocket::ConnectedState)
   {
      // QByteArray block;
      // QDataStream out(&block, QIODevice::WriteOnly);
      // out.setVersion(QDataStream::Qt_5_15);
      // out << Message;
      socket_->write("Hello, server!");
      socket_->flush();
      socket_->waitForBytesWritten();
   }
   else
   {
      qDebug() << "Client is not onnected!";
   }
}*/

void Client::SendRegistationRequest()
{
   QJsonObject jsonRequest;
   jsonRequest["requst_type"] = "registration";
   jsonRequest["login"] = "alina";
   jsonRequest["password"] = "russia";

   QJsonDocument jsonDoc(jsonRequest);
   QByteArray jsonData = jsonDoc.toJson();
   socket_->write(jsonData);
   socket_->flush();
   socket_->waitForBytesWritten();
}
