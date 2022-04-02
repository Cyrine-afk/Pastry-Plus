#ifndef ARDUINO_A_H
#define ARDUINO_A_H

#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>

class arduino_a
{
public:
    arduino_a();
    int connect_arduino();
       int close_arduino();
       int write_to_arduino(QByteArray);
       QString read_from_arduino();
       QSerialPort* getserial();
       QString getarduino_port_name();

private:
       QSerialPort * serial ;
       static const quint16 arduino_uno_vendor_id=9025;
       static const quint16 arduino_uno_producy_id=67;
       QString arduino_port_name;
       bool arduino_is_available;
       QString data;
       QString serialBuffer;
};

#endif // ARDUINO_A_H
