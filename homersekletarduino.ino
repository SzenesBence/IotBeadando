#define  REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include "flprogUtilites.h"
#include <ESP8266WiFi.h>
#include <RemoteXY.h>
#include "DHTesp.h"
DHTesp _dht1;
extern "C" 
{
    #include "user_interface.h"
}
#define REMOTEXY_WIFI_SSID "ESP01 DHT11"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {255, 0, 0, 8, 0, 120, 0, 19, 0, 0, 0, 0, 31, 1, 106, 200, 1, 1, 4, 0, 71, 14, 12, 78, 78, 56, 0, 1, 24, 75, 0, 0, 0, 0, 0, 0, 72, 66, 0, 0, 32, 65, 0, 0, 32, 65, 0, 0, 0, 64, 24, 0, 71, 16, 103, 75, 75, 56, 0, 6, 24, 75, 0, 0, 160, 65, 0, 0, 160, 66, 0, 0, 32, 65, 0, 0, 32, 65, 0, 0, 0, 64, 24, 0, 129, 19, 69, 69, 12, 64, 17, 72, 197, 145, 109, 195, 169, 114, 115, 195, 169, 107, 108, 101, 116, 0, 129, 19, 161, 70, 12, 64, 17, 80, 195, 161, 114, 97, 116, 97, 114, 116, 97, 108, 111, 109, 0};
struct 
{
    float instrument_01;
    float instrument_02;
    unsigned char connect_flag;
}
 RemoteXY;
#pragma pack(pop)
bool ESPControllerWifiClient_status = 1;
char ESPControllerWifiAP_SSID[40] = "ESP01 DHT11";
char ESPControllerWifiAP_password[40] = "";
bool ESPControllerWifiAP_IsNeedReconect = 0;
bool ESPControllerWifiAP_workStatus = 1;
IPAddress ESPControllerWifiAP_ip(192, 168, 0, 1);
IPAddress  ESPControllerWifiAP_dns (192, 168, 0, 1);
IPAddress  ESPControllerWifiAP_gateway (192, 168, 0, 1);
IPAddress ESPControllerWifiAP_subnet (255, 255, 255, 0);
uint8_t ESPControllerWifiAP_mac[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
WiFiMode _ESPCurrentWifiMode = WIFI_AP_STA;
float _dht1_humOut = 0.00;
float _dht1_tempOut = 0.00;
unsigned long _dht1Tti = 0UL;
void setup()
{
    RemoteXY_Init ();
    WiFi.mode(WIFI_AP);
    _esp8266WifiModuleApReconnect();
    _dht1.setup(2, DHTesp::DHT11);
    _dht1Tti = millis();
}
void loop()
{
    RemoteXY_Handler  ();
    if(ESPControllerWifiAP_IsNeedReconect) 
    {
        _esp8266WifiModuleApReconnect();
        ESPControllerWifiAP_IsNeedReconect = 0;
    }
    //Board:1
    if(flprog::isTimer(_dht1Tti, 2000)) 
    {
        _dht1_humOut = _dht1.getHumidity();
        _dht1_tempOut = _dht1.getTemperature();
        _dht1Tti = millis();
    }
    RemoteXY.instrument_01 = _dht1_tempOut;
    RemoteXY.instrument_02 = _dht1_humOut;
}
int hexStrToInt(String instring)
{
    byte len = instring.length();
    if  (len == 0) return 0;
    int result = 0;
    for (byte i = 0; i < 8; i++)    // только первые 8 цыфар влезуть в uint32
    {
        char ch = instring[i];
        if (ch == 0) break;
        result <<= 4;
        if (isdigit(ch))
        result = result | (ch - '0');
        else result = result | (ch - 'A' + 10);
    }
    return result;
}
void _esp8266WifiModuleApReconnect()
{
    if (_checkMacAddres(ESPControllerWifiAP_mac)) 
    {
         wifi_set_macaddr(1, const_cast<uint8*>(ESPControllerWifiAP_mac));
    }
    WiFi.softAPConfig(ESPControllerWifiAP_ip, ESPControllerWifiAP_gateway, ESPControllerWifiAP_subnet);
    WiFi.softAP(ESPControllerWifiAP_SSID, ESPControllerWifiAP_password);
    if (! (_checkMacAddres(ESPControllerWifiAP_mac))) 
    {
        WiFi.softAPmacAddress(ESPControllerWifiAP_mac);
    }
}
bool _checkMacAddres(byte array[])
{
    bool result = 0;
    for (byte i = 0; i < 6; i++)
    {
        if (array[i] == 255) 
        {
            return 0;
        }
        if (array[i] > 0) 
        {
            result = 1;
        }
    }
    return result;
}
void _parseMacAddressString(String value, byte array[])
{
    int index;
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    byte raz = 0;
    String tempString;
    while ((value.length() > 0) && (raz <= 6)) 
    {
        index = value.indexOf(":");
        if (index == -1) 
        {
            tempString = value;
            value = "";
        }
         else 
        {
            tempString = value.substring(0, index);
            value = value.substring(index + 1);
        }
        buffer[raz] = byte(hexStrToInt(tempString));
        raz++;
    }
    if (_checkMacAddres(buffer))
    {
        for (byte i = 0; i < 6; i++)
        {
            array[i] = buffer[i];
        }
    }
}
bool _compareMacAddreses(byte array1[], byte array2[])
{
    for (byte i = 0; i < 6; i++)
    {
        if (array1[i] != array2[i]) 
        {
            return 0;
        }
    }
    return 1;
}
bool _compareMacAddresWithString(byte array[], String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value,  buffer);
    return _compareMacAddreses(array, buffer);
}
bool _checkMacAddresString(String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value,  buffer);
    return _checkMacAddres(buffer);
}
String _macAddresToString(byte array[])
{
    String result = "";
    String  temp ="";
    for (byte i = 0; i < 6; i++)
    {
        temp=String(array[i],HEX);
        if (temp.length()  < 2) 
        {
            temp = String("0") + temp;
        }
        result = result + temp;
        if (i < 5) 
        {
               result = result + String(":");
        }
    }
    result.toUpperCase();
    return result;
}
