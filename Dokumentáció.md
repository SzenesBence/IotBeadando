<ins>Hő és pára érzékelő:</ins>
Célja: a hő és páraérzékelés valós időben.

<ins>Csapattagok és szerepük:</ins> 1.Siska Balázs: Iot eszközök összeszerelése, flprog program összerakása, dokumentáció asszisztálása. 2.Szenes Bence: IoT eszközök összeszerelése(részben),flprog program összerakása, dokumentálás.

<ins>Eszközök és céljuk:</ins> Wemos 18650 akkumulátortöltő pajzs: áramellátás, ESP-01 DHT11 DHT22 hőmérséklet páratartalom érzékelő modul: hő és pára érzékelés,ESP-01 USB programozó: programozás , ESP8266 Wifi-Modul: vezetés nélküli kapcsolat biztosítása, Duopont kábel anya/anya és pin header: áramellátása biztosítása az akkumulátorpajzs és a hő és pára érzékelő egység között mint kábel.

<ins>Szoftverek:</ins> FLProg, RemoteXY(webes), Arduino

<ins>Működés menete:</ins>

1. Az ESP8266 hozzáférési pontot hoz létre (SSID: "ESP01 DHT11"), amelyhez más eszközök csatlakozhatnak.

2. A DHT11 szenzorról mért hőmérséklet- és páratartalom-adatokat 2 másodpercenként frissíti.

3. Az adatok a RemoteXY interfészen keresztül érhetők el mobilalkalmazásban.

4. Ha a WiFi kapcsolat megszakad, automatikusan újracsatlakozik.

<ins>Összeállítás menete:</ins>

RemoteXY:
Egy testreszabható applikáció készítésével kezdtünk RemoteXY(https://remotexy.com/) segítségével.
Legelőször az alap konfigurációnknak megadtuk a Wifi Acces pointot, ESP8266 based board-ot, Integrated Wi-Fi-t és az FlProg Ide-t.
<details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/RemoteXY1.png" ></details>
A megfelelő indikátorokat beállítottuk és feliratoztuk.
  <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/RemoteXY2.png" ></details>
Ezután a GetSourceCodeall letöltjük a sourcodeot amit a remoteXY.txt-ben mellékeltem.


FLPRog:

Először kiválasztjuk az új projektet ami az ESP8266 ESP-01 V090-es modul lesz.
  <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLProg1.png" ></details>
Ezt követően az eléréséi pontunkat engedélyezzünk átnevezzük ESP DHT11-re, az IP címet 192.168.0.1-re változtatjuk.
Ezt követően beillesztünk egy DHT szenzor blokkot a programba és beállítjuk: DPIO0 pint  és a DHT11-es szenzort kiválasztjuk, engedélyezzük a hő és páraérzékelő szenzort, az ismétlési időt most 2 másodpercre állítjuk.
     <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLProg2.png" ></details>
Ezután egy RemoteXY blokkot húzunk be a programba. Az input/output fülön beillesztjük a RemoteXY-on legenerált kódunkat. Ezután megbizonyosodunk róla hogy a port 6377-en fog futni és beillesztjük, ezután véglegesítjük a blokkot és összehúzzuk a hő és páraérzékelő blokkot a RemoteXY blokkal és végül futtatunk.
        <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/FLprog3.png" ></details>


Arduino:
(részletesebb kóddokumentációért lásd: https://github.com/SzenesBence/IotBeadando/blob/main/ArduinoK%C3%B3dDokument%C3%A1ci%C3%B3.md )

USB Programozó összecsatlakoztjuka  a Wifi modullal és azt behelyezzük az USB portunkba
   <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/programozo.jpg" ></details>
A projektünk feltöltése utána az FlProg átirányít minket az Arduino IDE-be, ahol beállítjuk a FLASh méretet 1mb-re, valamint az ismétlési metódust dtr(aka nodemcu)-ra, valamint kiválasztjuk a megfelelő Portot, ami nekem most a PORT6. Ezt követően rámegyünk a Feltöltés>Feltöltés programozót használva menüpontra és a program felkerül a wifimodulunkra.
        <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/arduino.png" ></details>
Kivesszük a Wifi modult, hozzáacsatlakoztatjuk a hő és pára érzékelő modulunkhoz és ezt az egységet összekötjük az akkumulátorpajzsal. Fontos: az akkumulátort legalább 4 óráig töltsük mielőtt használnánk.
                 <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/Homero.jpg" ></details>


Ezután letöltjük a RemoteXY appot a PlayÁruházból.Hozzáadunk egy egy új eszközt,beállítjuk a Wifi pontunkat, rácsatlakozunk a 6377-es portunkra és már látjuk is a végeredményt.
        <details> <image src="https://github.com/SzenesBence/IotBeadando/blob/main/kepek/RemoteApp.jpg" ></details>

<ins>Működést bemutató videó:</ins>
https://www.youtube.com/watch?v=2bABDv5wP4c





