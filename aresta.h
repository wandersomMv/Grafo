#ifndef ARESTA_H
#define ARESTA_H
#include<mypair.h>

class Aresta{
public:
    Aresta(){}
    myPair<int,int> __celula;
    int vertice;
    void setCelula(myPair<int,int> & setar){__celula = setar;}
    void setVertice(int & vertex){this->vertice=vertex;}
    friend istream &operator>>(istream & is,Aresta & nova){
        do{
            cout<<"DIGITE O VERTICE DE ORIGEM : ";
            is>>nova.vertice;
            cout<<"DIGITE O VERTICE DE DESTINO : ";
            cin>>nova.__celula.first;
            cout<<"DIGITE O PESO DO VERTICE DE DESTINO : ";
            is>>nova.__celula.second;
        }while(nova.vertice<0||nova.__celula.first<0||nova.__celula.second<0);
        return is;
    }
    bool operator < (Aresta & aresta2)const{
        return __celula.second<aresta2.__celula.second;
    }

};

#endif // ARESTA_H
