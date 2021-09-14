# DH11 Reader
#### A simple and easy library to read DHT11 humidity / temprature data ported for `Code Vision AVR v3.12` 

### How to use:
1. Copy DHT11 diretory to your project root 

2. Set sensor pin before including:
```
// set dht11 sensor port and pin should be define before include
#define SPIN C.0
```

3. Include the library:
```
#include <DHT11/DHT11.h>
```

4. Define two variable for humidity and temprature and pass it to `readDHT11` function as a reference.
```
unsigned char hum=0;
char temp=0;
unsigned char crc=0;

//crc will be true if sensor's data red correctly!
crc=readDHT11(&temp,&hum);
```

For more information take look at example.

