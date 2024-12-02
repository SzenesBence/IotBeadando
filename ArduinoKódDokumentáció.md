1. Makrók és definíciók
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT: A RemoteXY beállítása az ESP8266 WiFi-modulhoz.
#define REMOTEXY_WIFI_SSID "ESP01 DHT11": A WiFi hozzáférési pont neve, amelyet az ESP hoz létre.
#define REMOTEXY_WIFI_PASSWORD "": A hozzáférési pont jelszava (üresen hagyva nincs jelszó).
#define REMOTEXY_SERVER_PORT 6377: A RemoteXY szerver portja a kommunikációhoz.

2.Fontos importált könyvtárak:

<ESP8266WiFi.h>: A WiFi-funkciók kezelése az ESP8266-on.
<RemoteXY.h>: A RemoteXY platform könyvtára a felhasználói interfész és adatkommunikáció kezelésére.
DHTesp.h: A DHT11 szenzor kezeléséhez szükséges könyvtár.


Ez a kód egy ESP8266 WiFi-modulon alapuló hőmérséklet- és páratartalom-mérő rendszer, amely a RemoteXY nevű platform segítségével vizualizálja az adatokat, és a WiFi funkciókat használja eszközök közötti kommunikációra. Az alábbiakban részletezem a kód főbb elemeit és funkcióit:

1. Makrók és definíciók
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT: A RemoteXY beállítása az ESP8266 WiFi-modulhoz.
#define REMOTEXY_WIFI_SSID "ESP01 DHT11": A WiFi hozzáférési pont neve, amelyet az ESP hoz létre.
#define REMOTEXY_WIFI_PASSWORD "": A hozzáférési pont jelszava (üresen hagyva nincs jelszó).
#define REMOTEXY_SERVER_PORT 6377: A RemoteXY szerver portja a kommunikációhoz.
2. Fontos importált könyvtárak
<ESP8266WiFi.h>: A WiFi-funkciók kezelése az ESP8266-on.
<RemoteXY.h>: A RemoteXY platform könyvtára a felhasználói interfész és adatkommunikáció kezelésére.
DHTesp.h: A DHT11 szenzor kezeléséhez szükséges könyvtár.

4. RemoteXY konfiguráció
RemoteXY_CONF[]: Ez egy bináris konfiguráció, amely a RemoteXY interfész elrendezését és funkcióit határozza meg.
RemoteXY struktúra: Tárolja a mérési adatokat:
instrument_01: Hőmérséklet.
instrument_02: Páratartalom.
connect_flag: Kapcsolati állapot.


Ez a kód egy ESP8266 WiFi-modulon alapuló hőmérséklet- és páratartalom-mérő rendszer, amely a RemoteXY nevű platform segítségével vizualizálja az adatokat, és a WiFi funkciókat használja eszközök közötti kommunikációra. Az alábbiakban részletezem a kód főbb elemeit és funkcióit:

1. Makrók és definíciók
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT: A RemoteXY beállítása az ESP8266 WiFi-modulhoz.
#define REMOTEXY_WIFI_SSID "ESP01 DHT11": A WiFi hozzáférési pont neve, amelyet az ESP hoz létre.
#define REMOTEXY_WIFI_PASSWORD "": A hozzáférési pont jelszava (üresen hagyva nincs jelszó).
#define REMOTEXY_SERVER_PORT 6377: A RemoteXY szerver portja a kommunikációhoz.

3. Fontos importált könyvtárak
<ESP8266WiFi.h>: A WiFi-funkciók kezelése az ESP8266-on.
<RemoteXY.h>: A RemoteXY platform könyvtára a felhasználói interfész és adatkommunikáció kezelésére.
DHTesp.h: A DHT11 szenzor kezeléséhez szükséges könyvtár.

4. RemoteXY konfiguráció
RemoteXY_CONF[]: Ez egy bináris konfiguráció, amely a RemoteXY interfész elrendezését és funkcióit határozza meg.
RemoteXY struktúra: Tárolja a mérési adatokat:
instrument_01: Hőmérséklet.
instrument_02: Páratartalom.
connect_flag: Kapcsolati állapot.

5. Változók
WiFi beállítások: Az ESP a következő beállításokat használja hozzáférési pontként:
IP-cím, alhálózati maszk, gateway és DNS beállítások.
MAC-címek kezelése és ellenőrzése (_checkMacAddres).
Hőmérséklet- és páratartalom-értékek:
_dht1_humOut: Páratartalom tárolása.
_dht1_tempOut: Hőmérséklet tárolása.


Ez a kód egy ESP8266 WiFi-modulon alapuló hőmérséklet- és páratartalom-mérő rendszer, amely a RemoteXY nevű platform segítségével vizualizálja az adatokat, és a WiFi funkciókat használja eszközök közötti kommunikációra. Az alábbiakban részletezem a kód főbb elemeit és funkcióit:

1. Makrók és definíciók
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT: A RemoteXY beállítása az ESP8266 WiFi-modulhoz.
#define REMOTEXY_WIFI_SSID "ESP01 DHT11": A WiFi hozzáférési pont neve, amelyet az ESP hoz létre.
#define REMOTEXY_WIFI_PASSWORD "": A hozzáférési pont jelszava (üresen hagyva nincs jelszó).
#define REMOTEXY_SERVER_PORT 6377: A RemoteXY szerver portja a kommunikációhoz.
2. Fontos importált könyvtárak
<ESP8266WiFi.h>: A WiFi-funkciók kezelése az ESP8266-on.
<RemoteXY.h>: A RemoteXY platform könyvtára a felhasználói interfész és adatkommunikáció kezelésére.
DHTesp.h: A DHT11 szenzor kezeléséhez szükséges könyvtár.
3. RemoteXY konfiguráció
RemoteXY_CONF[]: Ez egy bináris konfiguráció, amely a RemoteXY interfész elrendezését és funkcióit határozza meg.
RemoteXY struktúra: Tárolja a mérési adatokat:
instrument_01: Hőmérséklet.
instrument_02: Páratartalom.
connect_flag: Kapcsolati állapot.
4. Változók
WiFi beállítások: Az ESP a következő beállításokat használja hozzáférési pontként:
IP-cím, alhálózati maszk, gateway és DNS beállítások.
MAC-címek kezelése és ellenőrzése (_checkMacAddres).
Hőmérséklet- és páratartalom-értékek:
_dht1_humOut: Páratartalom tárolása.
_dht1_tempOut: Hőmérséklet tárolása.

6. setup() funkció
RemoteXY_Init(): Elindítja a RemoteXY kapcsolatot.
WiFi mód beállítása: Hozzáférési pontként üzemel (WIFI_AP).
Szenzor inicializálása: A DHT11 szenzor a 2-es GPIO pinre csatlakozik.


Ez a kód egy ESP8266 WiFi-modulon alapuló hőmérséklet- és páratartalom-mérő rendszer, amely a RemoteXY nevű platform segítségével vizualizálja az adatokat, és a WiFi funkciókat használja eszközök közötti kommunikációra. Az alábbiakban részletezem a kód főbb elemeit és funkcióit:

1. Makrók és definíciók
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT: A RemoteXY beállítása az ESP8266 WiFi-modulhoz.
#define REMOTEXY_WIFI_SSID "ESP01 DHT11": A WiFi hozzáférési pont neve, amelyet az ESP hoz létre.
#define REMOTEXY_WIFI_PASSWORD "": A hozzáférési pont jelszava (üresen hagyva nincs jelszó).
#define REMOTEXY_SERVER_PORT 6377: A RemoteXY szerver portja a kommunikációhoz.
2. Fontos importált könyvtárak
<ESP8266WiFi.h>: A WiFi-funkciók kezelése az ESP8266-on.
<RemoteXY.h>: A RemoteXY platform könyvtára a felhasználói interfész és adatkommunikáció kezelésére.
DHTesp.h: A DHT11 szenzor kezeléséhez szükséges könyvtár.
3. RemoteXY konfiguráció
RemoteXY_CONF[]: Ez egy bináris konfiguráció, amely a RemoteXY interfész elrendezését és funkcióit határozza meg.
RemoteXY struktúra: Tárolja a mérési adatokat:
instrument_01: Hőmérséklet.
instrument_02: Páratartalom.
connect_flag: Kapcsolati állapot.
4. Változók
WiFi beállítások: Az ESP a következő beállításokat használja hozzáférési pontként:
IP-cím, alhálózati maszk, gateway és DNS beállítások.
MAC-címek kezelése és ellenőrzése (_checkMacAddres).
Hőmérséklet- és páratartalom-értékek:
_dht1_humOut: Páratartalom tárolása.
_dht1_tempOut: Hőmérséklet tárolása.
5. setup() funkció
Ez a funkció az inicializálást végzi:

RemoteXY_Init(): Elindítja a RemoteXY kapcsolatot.
WiFi mód beállítása: Hozzáférési pontként üzemel (WIFI_AP).
Szenzor inicializálása: A DHT11 szenzor a 2-es GPIO pinre csatlakozik.

6. loop() funkció
Folyamatosan figyeli és kezeli az adatokat:

WiFi újracsatlakozás:
Ellenőrzi, hogy szükséges-e az újracsatlakozás (_esp8266WifiModuleApReconnect).
DHT11 adatlekérés:
Minden 2 másodpercben (_isTimer) lekéri a hőmérséklet- és páratartalom-értékeket.
Az értékeket a RemoteXY struktúrába tölti (instrument_01, instrument_02).
RemoteXY interfész kezelése:
RemoteXY_Handler(): Kezeli a RemoteXY-hoz kapcsolódó műveleteket (adatkommunikáció).

MAC-cím kezelés:

_checkMacAddres: Ellenőrzi, hogy a MAC-cím érvényes-e.
_parseMacAddressString: String formátumú MAC-cím feldolgozása.
_compareMacAddreses: Két MAC-cím összehasonlítása.

Helper funkciók:

_esp8266WifiModuleApReconnect: Újrakonfigurálja a WiFi hozzáférési pontot.
hexStrToInt: Hexadecimális string átalakítása számmá.
