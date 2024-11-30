Hő és pára érzékelő:

Eszközök: Wemos 18650 akkumulátortöltő pajzs,ESP-01 USB programozó, ESP8266 Wifi-Modul, Duopont kábel anya/anya.
Szoftverek: FLProg, RemoteXY, Arduino

RemoteXY:
Egy testreszabható applikáció készítésével kezdtünk RemoteXY(https://remotexy.com/) segítségével.
Legelőször az alap konfigurációnknak megadtuk a Wifi Acces pointot, ESP8266 based board-ot, Integrated Wi-Fi-t és az FlProg Ide-t.
![alt text](https://github.com/SzenesBence/IotBeadando/blob/main/kepek/RemoteXY1.png)
A megfelelő indikátorokat beállítottuk és feliratoztuk.
![alt text](https://github.com/SzenesBence/IotBeadando/blob/main/kepek/RemoteXY2.png)
Ezután a GetSourceCodeall letöltjük a sourcodeot amit a remoteXY.txt-ben mellékeltem.


FLPRog:

Először kiválasztjuk az új projektet ami az ESP8266 ESP-01 V090-es modul lesz.
![alt text](https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLProg1.png)
Ezt követően az eléréséi pontunkat engedélyezzünk átnevezzük ESP DHT11-re, az IP címet 192.168.0.1-re változtatjuk.
Ezt követően beillesztünk egy DHT szenzor blokkot a programba és beállítjuk: DPIO0 pint  és a DHT11-es szenzort kiválasztjuk, engedélyezzük a hő és páraérzékelő szenzort, az ismétlési időt most 2 másodpercre állítjuk.
![alt text](https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLProg2.png)
Ezután egy RemoteXY blokkot húzunk be a programba. Az input/output fülön beillesztjük a RemoteXY-on legenerált kódunkat. Ezután megbizonyosodunk róla hogy a port 6377-en fog futni és beillesztjük, ezután véglegesítjük a blokkot és összehúzzuk a hő és páraérzékelő blokkot a RemoteXY blokkal és végül futtatunk.
https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLProg3.png


