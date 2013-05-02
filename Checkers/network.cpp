#include "network.h"

Network::Network(QObject *parent) :
    QObject(parent)
{
    state = NETWORK_NONE;
}

void Network::connectServer(QString ip, unsigned port)
{
    if (state != NETWORK_NONE) {
        qDebug() << "Error: network state is not NONE: " << state;
        return;
    }
    qDebug() << "[CONNECTING  " << ip << ":" << port << " ... ]";
    if (client != null) client->abort();

    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(ip), port);
    connect(client, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(client, SIGNAL(readyRead()), this, SLOT(socketDataReady()));
    role = NETWORK_CLIENT;
}

void Network::establishServer()
{
    if (state != NETWORK_NONE) {
        qDebug() << "Error: network state is not NONE: " << state;
        return;
    }
    server = new QTcpServer(this);
    qDebug() << "[ESTABLISHING SERVER " << server->serverAddress() << ":" << server->serverPort() << " ...]";
    if (!server->listen(QHostAddress::Any, 5555)) {
        qDebug() << "NOT LISTENING!!!";
        return;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(serverNewConnection()));
    role = NETWORK_SERVER;
}

void Network::sendMySettings()
{
    QDataStream out(client);
    out << mySettings;
}

void Network::setMySettings(GameSettings settings)
{
    this->mySettings = settings;
}

void Network::sendMove(Move move)
{
    qDebug() << "PRAVE POSILAM PO SITI TAH: " << move.getFrom().x << "x" << move.getFrom().y << " => " << move.getTo().x << "x" << move.getTo().y;

    QDataStream out(client);
    out << move;

}


void Network::socketError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "[Socket error: " << client->errorString() << "]";
    emit connectServerFailed();
}

void Network::socketConnected()
{
    state = NETWORK_CONNECTED;
    qDebug() << "[CONNECTING DONE]";
    sendMySettings();
    state = NETWORK_SETUP_SENT;
}

void Network::socketDataReady()
{
    qDebug() << "[DATA READY]";
    if (state == NETWORK_SETUP_SENT) {
        // Moje nastaveni uz odeslano,takze prislo oponentovo nastaveni
        QDataStream in(client);
        GameSettings settings;
        in >> settings;
        this->opponentSettings = settings;
        qDebug() << "[OPPONENT SETTINGS SAVED]";
        emit settingsReceived(settings);
        state = NETWORK_SETUP_RECEIVED;
    } else if (state == NETWORK_SETUP_RECEIVED) {
        // Hra uz je nastavena, vymenene settings, takze prisel move
        QDataStream in(client);
        Move readyMove;
        in >> readyMove;

        qDebug() << "[OPPONENT's MOVE EMITTED]";
        emit moveReady(readyMove);
    } else if (state == NETWORK_CONNECTED){
        // Neni zadne nastaveni vymeneno, jen spojeni ustaveno, tak mi prislo nastaveni (na server) a ja musim odpovedet svym nastavenim
        // KTERE MIMOCHODEM prepisuje zvolenou barvu tou opacnou vuci prichazejici ... zabrani se tim pripadne kolizi
        QDataStream in(client);
        GameSettings settings;
        in >> settings;
        this->opponentSettings = settings;
        this->mySettings.color = (this->opponentSettings.color == PLAYER_W) ? PLAYER_B : PLAYER_W;  // otocit moji barvu nezavisle na tom kterou si uzivatel vyzadal
        qDebug() << "[OPPONENT SETTINGS SAVED]";
        emit settingsReceived(settings);
        sendMySettings();
        state = NETWORK_SETUP_RECEIVED;
    } else {
        throw "Not connected, error";
    }
}

void Network::serverNewConnection()
{

    if (client == null) {
        state = NETWORK_CONNECTED;
        qDebug() << "[NEW SERVER CONNECTION SAVED]";
        client = server->nextPendingConnection();
        connect(client, SIGNAL(readyRead()), this, SLOT(socketDataReady()));
    }
}




