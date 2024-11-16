#ifndef HAPPSINGLETON_H
#define HAPPSINGLETON_H

#include <QObject>
#include <QTcpServer>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QHttpServer>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HAppSingleton : public QObject
{
    Q_OBJECT
public:
    typedef QJsonObject (*CallbackLambda)(const QJsonObject &data);

    HAppSingleton() = delete;
    HAppSingleton(quint16 port, const CallbackLambda &callback, QObject *parent = nullptr);

    bool tryGrab();

    QNetworkReply *tell(const QJsonObject &data);

signals:

private:
    quint16 m_port;
    QNetworkAccessManager *m_networkAccessManager;
    QTcpServer *m_tcpServer;
    QHttpServer *m_httpServer;
};

HQT_END_NAMESPACE

#endif // HAPPSINGLETON_H
