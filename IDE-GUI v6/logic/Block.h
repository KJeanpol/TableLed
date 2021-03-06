//
// Created by Jeanpol on 18/9/2017.
//

#ifndef SEMANTICANALYSIS_BLOCK_H
#define SEMANTICANALYSIS_BLOCK_H


#include <vector>
#include <string>
#include<stdio.h>
#include <iostream>
#include "Var.h"
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <QKeyEvent>
#include <QDebug>
#include "mainwindow.h"

using namespace std;

class Block{
public:
    Block* father; 
    int juego;
    int If;
    void setIf(int pif){
        If=pif;
    }
    void setjuego(int pjuego){
        juego=pjuego;
    }
    void setPara();

    bool exit=false;
    void setExit(bool par){
        exit=par;
    }
    //Arduino
    string palabra;
    vector<int> values;
    vector<string> params;
    vector<string> paramtypes;
    void setParams(string pname, string ptype){
        params.push_back(pname);
        paramtypes.push_back(ptype);
     }
    MainWindow* ID;
    void setIDS(MainWindow *pID){
        ID=pID;
    }


    //IF
    vector <string> vals1;
    vector <int> vals2;
    void setVal1(string pname){
        vals1.push_back(pname);
    }
    void setVal2(int val){
        vals2.push_back(val);
    }
    //FOR
    int times;
    //DOW
    string var;
    int valor1;
    int valor2;
    void setVarD(string pvar){
        var=pvar;
    }
    void setValor1(int pval){
        valor1=pval;
    }
    void setValor2(int pval){
        valor2=pval;
    }
    //INCREASE-DECREASE
    string vardec;
    string varinc;
    void setVarDec(string pvar){
        vardec=pvar;
    }
    void setVarInc(string pvar){
        varinc=pvar;
    }

    //BLOCK
    std::vector<Block *> sentences;
    string name;
    std::vector< Var * > Variables;
    std::vector< Var * > INZ;
    Block();
    bool exist(string pname){
        for(int i=0;i!=Variables.size();i++){
            if(Variables[i]->getName().compare(pname)==0){
                return true;
            }
        }return false;
    }
    void setName(string pname){
        this->name=pname;
        cout<<name<<endl;
        return;
    }
    string getName(){
        return name;
    }
    void addVars(Var *pvar);
    bool hasVariable(string pname);
    bool hasBlock();
    int getVar(string pname);
    void addSentence(Block *sentence);
    void setFather(Block *pfather);
    void increase(string pname);
    void decrease(string pname);
    void setVal(string pname, int val);
    bool isInit(string pname);
    virtual ~Block();

    // CodeSentence interface
public:
    virtual void execute();
};


#endif //SEMANTICANALYSIS_BLOCK_H
