#include "testnotation.h"

TestNotation::TestNotation()
{
}

void TestNotation::convert(QVector<Move> vector) {

     QString string;
     QString player;
     int i = 1;
     for(auto m : vector) {
         if (i%2) {
             player = "W";
         } else {
             player = "B";
         }

         string.append(player + " -> from: "+ QString::number(m.getFrom().x+1) +":"+QString::number(m.getFrom().y+1));
         string.append(" to: "+ QString::number(m.getTo().x+1) +":"+QString::number(m.getTo().y+1)+"\n");
         i++;
     }

     this->text = string;

}
