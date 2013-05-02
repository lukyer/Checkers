#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork>
#include "common.h"
#include "move.h"
#include <QMessageBox>


// Network se vzdy instanciue jen pro jednoho hrace ... v nasi hre ... takze se nastavi typ na client nebo server, podle typu pripojeni a celou dobu
// ten ukazatel v Checkers tride (net) ukazuje na Network objekt uzivany pri komunikaci s jednim hracem (sitovym oponentem)
class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    void connectServer(QString ip, unsigned port);
    void setMySettings(GameSettings settings);
    void establishServer();
    void sendMove(Move);


private:
    QTcpSocket *client;         // Staci jen jeden, inicializace v konstruktoru, zanik v destruktoru
    QTcpServer *server;
    GameSettings mySettings;
    GameSettings opponentSettings;
    void sendMySettings();
    NetworkType role;
    NetworkState state;
    
signals:
    void connectServerFailed();
    void moveReady(Move, PlayerType = PLAYER_NETWORK);
    void settingsReceived(GameSettings);

    
public slots:
    void socketError(QAbstractSocket::SocketError);
    void socketConnected();
    void socketDataReady();
    void serverNewConnection();
    
};

#endif // NETWORK_H
