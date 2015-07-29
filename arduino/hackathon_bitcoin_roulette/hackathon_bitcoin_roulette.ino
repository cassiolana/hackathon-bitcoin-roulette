#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x26, 0x9F };
char server[] = "172.16.96.21";
IPAddress ip(192,168,0,177);
EthernetClient client;

int loops = 1;
void setup() {
  Serial.begin(9600);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
}

void loop() {
  Serial.print("--------------------LOOP ");
  Serial.print(loops++);
  Serial.println("------------------------");
  checkSchedule();
  delay(5000);
}

boolean checkSchedule() {
  if (client.connect(server, 8080)) {
    Serial.println("connected");
    client.println("GET /schedule/check HTTP/1.1");
    client.println("Host: 172.16.96.21");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  
  int init = millis();
  int lastRead;
  int timeout = 1000;
  while(client.connected()){
    if (client.available()) {
      char c = client.read();
      Serial.print(c);
      lastRead = millis();
    } else {
      if(millis() - init > timeout) {
        Serial.println();
        Serial.println("End of the response stream");
        break;
      }
    }
  }
  Serial.println();
  Serial.println("disconnecting.");
  client.stop();
  client.flush();
}
