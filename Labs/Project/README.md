# Greenhouse monitoring and control system

### Team members

* Michal Baránek (219836)
* Tadeáš Bařina (223380)
* Alexander Bekeč (221096)
* Ladislav Drápal (223285)

Link to this file in your GitHub repository:

[https://github.com/alexander-bekec/Greenhouse_Project_DE2](https://github.com/alexander-bekec/Greenhouse_Project_DE2)

### Table of contents

* [Project objectives](#objectives)
* [Hardware description](#hardware)
* [Libraries description](#libs)
* [Main application](#main)
* [Video](#video)
* [References](#references)

<a name="objectives"></a>

## Project objectives

Cílem projektu je vytvořit ovládání a monitorování intenzity osvětlení, vlhkosti a teploty ve skleníku. U neinteligentních skleníků (které nemají možnost regulace dochází často k neodborné péči o rostliny, při malé vlhkosti půdy dochází k zasychání rostlin, při velké vlhkosti naopak rostliny chytají plíseň. U obou případů dojde k likvidaci rostlin, takže úroda bude malá nebo v nejhorších případech zcela zanikne. Tomu je ale konec. Bylo vytvořeno monitorování základních veličin ve skleníku. Tyto základní prvky jsou velmi důležité pro správný růst rostlin, zeleniny a ovoce uvnitř skleníku. Díky monitorování ze senzorů jsme schopni za včasu ovládat tyto základní prvky. Správným ovládáním osvětlení, vlhkosti a teploty máme zaručenou velice kvalitní úrodu. Už tedy nebude hrozit žádné zasychání.

<a name="hardware"></a>

## Hardware description

### V projektu byly použity tyto komponenty:
* 1x Mikrokontrolér ATMEGA328P
* 1x Displej Hd44780 (16x2)
* 1x Moisture sensor V1.2
* 1x Fotorezistor GL5549 + rezistor 10k
* 1x I2C vlhkoměr a teploměr DHT12
* 4x červená LED dioda
* 4x rezistor 1k

### Schéma zapojení
![schema](Image/schema.png)

Na obrázku je schéma kompletního zapojení. Ze schématu je vidět, že snímače jsou zapojeny k výstupním pinům PD0-PD3 desky ATMEGA328P. Snímač vlhkosti půdy je připojen přes červenou LED diodu k napájení a signál je posílám přes PIN A0. Tlačítka jsou připojeny k pinu A2. LCD displej má připojení k pinům PB1, PB0 a PD4-PD7. Fotorezistor DHT12 je připojen k pinům SDA a SCL.

### Reálné zapojení
![zapojeni](Image/zapojeni.png)

<a name="libs"></a>

## Libraries description

Knihovny byly použity z laboratorních cvičení z předmětu digitální elektronika 2. Byly to knihovny jako např. `uart.h`, `gpio.h`, `timer.h`, `lcd.h`.

### Seznam použitých knihoven
* [gpio.h](https://github.com/alexander-bekec/Greenhouse_Project_DE2/blob/main/Project/greenhouse_controller_project/greenhouse_controller_project/gpio.h)
* [lcd.h](https://github.com/alexander-bekec/Greenhouse_Project_DE2/blob/main/Project/greenhouse_controller_project/greenhouse_controller_project/lcd.h)
* [timer.h](https://github.com/alexander-bekec/Greenhouse_Project_DE2/blob/main/Project/greenhouse_controller_project/greenhouse_controller_project/timer.h)
* [twi.h](https://github.com/alexander-bekec/Greenhouse_Project_DE2/blob/main/Project/greenhouse_controller_project/greenhouse_controller_project/twi.h)
* [uart.h](https://github.com/alexander-bekec/Greenhouse_Project_DE2/blob/main/Project/greenhouse_controller_project/greenhouse_controller_project/uart.h)

<a name="main"></a>

## Main application

### Stavové diagramy

#### Stavový diagram všech senzorů
![all](Image/Statediagram_komplet.png)

U celkového stavového diagramu je znázorněno přepínání mezi jednotlivými senzory. Přepínání stavů je do uzavřené smyčky, kdy stisknutím pravého tlačítka se pohybujeme do prava a stiskem levého tlačítka vždy o krok zpět (do leva).

#### Stavový diagram pro vlhkost
![Humidity](Image/Humidity2.png)

#### Stavový diagram pro teplotu
![Temperature](Image/Temperature2.png)

#### Stavový diagram pro senzor vlhkosti půdy
![Soil](Image/Soil_moist2.png)

#### Stavový diagram pro senzor úrovně světla
![Light](Image/Light_level.png)

Ostatní stavové diagramy znázorňují stavy každého senzoru zvlášť. Tlačítka do leva a do prava znamenají jak už bylo řečeno přepnutí na další senzor. Horním a dolním tlačítkem se nastavují požadované hodnoty. Horním tlačítkem (Up) zvětšujeme a dolním tlačítkem (Down) snižujeme požadovanou hodnotu. Prostředním tlačítkem (Select) se vracíme do hlavního menu, označené IDLE.

### Popis kódu a simulace

<a name="video"></a>

## Video

[https://www.youtube.com/watch?v=UxhtJv5UaRo](https://www.youtube.com/watch?v=UxhtJv5UaRo)

<a name="references"></a>

## References

1. [Arduino_shield](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/arduino_shield.pdf)
2. [LCDkeypad](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/LCDKeypad%20Shield%20V1.0%20SCH.pdf)
3. [DHT12](https://github.com/alexander-bekec/de2-project/blob/main/Project/sources/DHT12_humidity_temperature_sensor_datasheet.pdf)
4. [GL5549](https://github.com/alexander-bekec/de2-project/blob/main/Project/sources/GL5549_SENBA.pdf)
5. [Soil_moisture](https://github.com/alexander-bekec/de2-project/blob/main/Project/sources/capacitive_soil_moisture_sensor_datasheet.pdf)