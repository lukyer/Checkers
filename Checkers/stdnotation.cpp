#include "stdnotation.h"

StdNotation::StdNotation()
{

}

void StdNotation::convert(QVector<Move> vector) // mel by vracet QString
{
    int i=1;
    char delimiter;
    QString string;

    for(auto m : vector) {
        if (i%2) {
            string.append("\n"+QString::number(i/2+1)+ ". ");
        }

        if (m.getTakenFigure().first == NONE) {
            delimiter = '-';
        } else {
            delimiter = 'x';
        }
        string.append( ('a' + m.getFrom().x) + QString::number(m.getFrom().y+1) + delimiter);
        string.append(('a' + m.getTo().x) + QString::number(m.getTo().y+1) + " ");

        i++;
    }
    string.remove(0,1); // neefektivni?
    this->text = string;
}

void StdNotation::saveGame(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << this->text;

    file.close();
}

QVector<Move> StdNotation::loadGame(QString fileName)
{
    QVector<Move> moves;
    QString line;
    QString delimiter;
    Position from;
    Position to;
    char *a;

    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    text.clear();

    while (!in.atEnd()) {
        line= in.readLine() + "\n";
        text += line;

    /*    from.x = QString.toInt(charline.mid(3,1)) - 'a';
        from.y = QString.toInt(line.mid(4,1));
        delimiter = line.mid(5.1);
        to.x = char(line.mid(6,1)) - 'a';
        to.y = line.mid(7,1);

        Move move(from,to);
        moves.append(move);

        from.x = char(line.mid(9,1)) - 'a';
        from.y = line.mid(10,1);
        delimiter = line.mid(11.1);
        to.x = char(line.mid(12,1)) - 'a';
        to.y = line.mid(13,1);

        Move move(from,to);
        moves.append(move);*/
        a = (char *)(line.mid(3,1)).data();
        qDebug() << a;
        line.


    }

    file.close();

    return moves;
}
