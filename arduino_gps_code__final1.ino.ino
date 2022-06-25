#include <ESP8266HTTPClient.h>
#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <Arduino.h>
SoftwareSerial ss(4, 5); // The serial connection to the GPS device
const char* ssid = "*************"; //ssid of your wifi
const char* password = "*************"; 
float latitude , longitude;
int year , month , date, hour , minute , second;
String date_str="" ;
String time_str; 
String lat_str; 
String lng_str="";
int pm;
String l,lo ;
  WiFiClient client;
  HTTPClient http;
 WiFiServer server(80);

int    HTTP_PORT   = 80;
String HTTP_METHOD = "GET";
char  HOST_NAME[] =  "192.168.137.1";
 // change to your PC's IP address
String PATH_NAME   = "/gps/dota.php";

 float Name=25;
String immatricule="220_tunis_2013";
TinyGPSPlus gps;  // The TinyGPS++ object

void setup() {
  Serial.begin(9600);
 ss.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); //connecting to wifi
  while (WiFi.status() != WL_CONNECTED)// while wifi not connected
  {
    delay(500);
    Serial.print("."); //print "...."
  }
  if(WiFi.status()== WL_CONNECTED){
   Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}
}
void loop() {

  while (ss.available() > 0) //while data is available
  {  
    if (gps.encode(ss.read())) //read gps data
    {
      if (gps.location.isValid() && gps.date.isValid() && gps.time.isValid() ) //check whether gps location is valid
      
        latitude = gps.location.lat();
        lat_str = String(latitude , 6); // latitude location is stored in a string
        longitude = gps.location.lng();
        lng_str = String(longitude , 6); //longitude location is stored in a string
        Serial.println("lattitude");
        Serial.println(lat_str);
        Serial.println("longtitude");
        Serial.println(lng_str);

         date_str = "";
        date = gps.date.day();
        month = gps.date.month();
        year = gps.date.year();
         if (year < 10)
          date_str += '0';
        date_str = String(year); // values of date,month and year are stored in a string
        date_str += "-";
         if (month < 10)
          date_str += '0';
        date_str += String(month); // values of date,month and year are stored in a string
        date_str += "-";
        //Serial.println("date",date_str);
        if (date < 10)
          date_str += '0';
        date_str += String(date);// values of date,month and year are stored in a string
        
       // Serial.println("date",date_str);

       time_str = "";
        hour = gps.time.hour();
        minute = gps.time.minute();
        second = gps.time.second();
      //  minute = (minute + 30); // converting to IST
        if (minute > 59)
        {
          minute = minute - 60;
          hour = hour + 1;
        }
        hour = (hour+1) ;
       /* if (hour > 23)
          hour = hour - 24;   // converting to IST
        if (hour >= 12)  // checking whether AM or PM
          pm = 1;
        else
          pm = 0;
        hour = hour % 12;*/
        if (hour < 10)
          time_str = '0';
        time_str += String(hour); //values of hour,minute and time are stored in a string
        time_str += ":";
        if (minute < 10)
          time_str += '0';
        time_str += String(minute); //values of hour,minute and time are stored in a string
        time_str += ":";
        if (second < 10)
          time_str += '0';
        time_str += String(second); //values of hour,minute and time are stored in a string
String queryString = "?idvehicule=" + String(Name)+"&immatricule=" + String(immatricule)+"&longtitude=" + String(longitude,6)+"&lattitude=" + String(lat_str)+"&gps_date=" +String(date_str)+"&gps_time="+String(time_str);
Serial.println(queryString);
if(client.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");
    // make a HTTP request:
    // send HTTP header
    client.println(HTTP_METHOD + " " + PATH_NAME + queryString + " HTTP/1.1");
  
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header

    while(client.connected()) {
      if(client.available()){
        // read an incoming byte from the server and print it to serial monitor:
        char c = client.read();
        Serial.print(c);
      }
     
    }

    // the server's disconnected, stop the client:
    client.stop();
    Serial.println();
    Serial.println("disconnected");
     //delay de chaque requête 5 minute
 //delay(180000);
 delay(60000);
  } else {// if not connected:
    Serial.println("connection failed");
  }
    } 
  }
} 
