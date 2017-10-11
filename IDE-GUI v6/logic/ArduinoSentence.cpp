//
// Created by Luis on 30/9/2017.
//

#include <iostream>
#include "ArduinoSentence.h"
#include "QJsonObject"
#include "QJsonDocument"
#include<QtBluetooth>
#include "stdio.h"
#include "mainwindow.h"


bool ArduinoSentence::check(){

}


void ArduinoSentence::execute()
{

    setPara();
QJsonObject object;
    if(name.compare("TurnOn")==0){

        object.insert("Juego",juego);
        object.insert("Type","TurnOn");
        object.insert("Boton",values[0]);
        object.insert("Fil",values[1]);
        object.insert("Col",values[2]);
        object.insert("R",values[3]);
        object.insert("G",values[4]);
        object.insert("B",values[5]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;

    }else if(name.compare("TurnON")==0){

        object.insert("Juego",juego);
        object.insert("Type","TurnON");
        object.insert("Boton",values[0]);
        object.insert("Fil",values[1]);
        object.insert("Col",values[2]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;
    }else if(name.compare("TurnOff")==0){

        ejecutar();
        cout<<"Apagando un led";

        return;
    }else if(name.compare("TurnOFF")==0){

        object.insert("Juego",juego);
        object.insert("Type","TurnOFF");
        object.insert("Boton",values[0]);
        object.insert("Fil",values[1]);
        object.insert("Col",values[2]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;
    }else if(name.compare("SoundOn")==0){

        object.insert("Juego",juego);
        object.insert("Type","SoundOn");
        object.insert("Boton",values[0]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;
    }else if(name.compare("SoundOff")==0){

        object.insert("Juego",juego);
        object.insert("Type","SoundOff");
        object.insert("Boton",values[0]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;
    }else if(name.compare("Maze")==0){

        object.insert("Juego",2);
        object.insert("Type","SoundOff");
        object.insert("Boton",values[0]);
        object.insert("Boton",values[0]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();


        return;
    }else{

        object.insert("Juego",3);
        object.insert("Type","Write");
        object.insert("Text",palabra.c_str());
        object.insert("R",values[1]);
        object.insert("G",values[2]);
        object.insert("B",values[3]);
        QJsonDocument doc(object);
        qDebug(doc.toJson());
        ID->sendMessage(doc.toJson());
        ejecutar();

        return; }




}

void ArduinoSentence::ejecutar()
{
    for(int i = 0; i!=sentences.size(); i++){
        sentences[i]->execute();
    }
}

void ArduinoSentence::closeConnection()
{
    cout << "Cerrando conexion";

}

