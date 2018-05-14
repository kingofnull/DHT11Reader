# DH11 Reader
#### A simple and clean library to read DHT11 humidity / temprature sensor implimented for `Code Vision AVR v3.12`

### How to use:
1. copy DHT11 diretory to your project root 

2. set sensor pin before include:
```
// set dht11 sensor port and pin should be define before include
#define SPIN C.0
```

3. include library:
```
#include <DHT11/DHT11.h>
```

4. define two variable for humidity and temprature and pass it to `readDHT11` function as pointer.
```
unsigned char hum=0;
char temp=0;
unsigned char crc=0;

//crc will be true if sensor data recieve correctly!
crc=readDHT11(&temp,&hum);
// here you can use data . if crc is true the values are valid.
```

you can use the example which is available in repository.

