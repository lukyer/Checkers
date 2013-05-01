Todo:

http://harmattan-dev.nokia.com/docs/library/html/qt4/network-fortuneclient.html

git

proc nepouzivat figure class ? Protoze je to zbytecny overhead a hlavne by vznikla komplikace pri posilani MOVE objektu po siti, potrebujeme posilat OD a DO souradnice, ne CO a DO. FIgurka dale neni nijak customizovatelna, takze neni treba ji modelovat jako entitu.

sitovy objekt bude serializovat MOVE objekt a posilat

dodelat NetworkPlayer ....

nejaky delay kdyz hrajou dva ui? Nebo proste pockat az dohrajou a mezitim to bude blokujici ...

zlepsit grafiku
pixmapa pro figurky i pro drag potom
at zmizi pri dragu z puvodni pozice
udelat poradne to podbarvovani pri dragu

refaktoring -> udelat tridu CHECKERS herni logika zvlast!!!

PORESIT PAMET PRI PREKRESLOVANI AT SE NEDELA MILIARDA OBJEKTU !!! UVOLNOVAT NEJAK CHILD


ukonceni hry se nema asi zacylkit hh
jak ogbnovovat gui? timer? At se nezkurvi checkers cistota tridy pomoci signalu


drag drop ikonky zmenit, 1985

pri refresh->start(10); vznikne  artefakt kokot navic tam je
