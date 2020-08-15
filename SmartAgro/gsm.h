// Universum | Universum Projects > SmartAgro | gprs.h

// Andrei Florian 14/AUG/2019 - 5/JUN/2019

GSMClient client;

char apn[20] = "soracom.io";
char login[8] = "sora";
char password[8] = "sora";

char url[] = "harvest.soracom.io";
char path[] = "/";

void parseData(String dataToSend)
{
  Serial.println("Sending Data");
  Serial.println("________________________________________");

  Serial.println("Sending Data to Soracom");
  Serial.println("  OK - Setting Up Connection");
  if(client.connect(url, 80)) // prepare connection and format send
  {
    Serial.println("  OK - Connection Established, Parsing Data");

    client.println("POST / HTTP/1.1");
    client.println("Host: harvest.soracom.io");
    client.println("User-Agent: Arduino/1.0");
    client.println("Connection: close");
    client.print("Content-Length: ");
    client.println(dataToSend.length());
    client.println("");
    client.println(dataToSend);

    Serial.println("  OK - Data Parsed");
  }

  Serial.println("  OK - Getting Responce");
  Serial.println("");

  // read back from server
  while(1)
  {
    if(client.available()) 
    {
      char c = client.read();
      Serial.print(c);
    }

    if(!client.connected()) 
    {
      break;
    }
  }

  Serial.println("  Success - Data is Parsed");
  Serial.println("________________________________________");
  Serial.println("");
}
