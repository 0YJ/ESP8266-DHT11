# How to use this

### get drduino ide
```
sudo apt update
sudo apt upgrade
sudo apt install arduino
```

### install driver CH340/CH341
```
cd CH341SER_LINUX/driver
sudo make -j8
sudo make install
sudo dmesg
```

Then connect ESP8266, open IDE

```
arduino
```

File-Peference add addition [developing board](http://arduino.esp8266.com/stable/package_esp8266com_index.json) 

Toos-Boards-ESP8266-NODE MCU 1.0
Port: /dev/ttyCH341USB0

Update codes and do serial monitoring. 

What to do next: 
Frontend, API, Database. 
