#ifndef NO_H
#define NO_H
#include<bits/stdc++.h>
using namespace std;
template<class type>
class no
{
public:
    type dado; // dado que será colocado em uma estrutura
    no * next; // ponteiro que apontta para o proximo
    no * previous;//ponteiro que aponta para o anterior
    static no<type> *montano(type *dado);
    static void desmontaNo(no<type> *sair, type *dado);
    no();
};
template<class type>
no<type> *no<type>::montano(type *dado){
    try{
        no<type> *retornar = new no<type>();
        retornar->dado = *dado;
        return retornar;
    }catch(std::bad_alloc &erro){
        throw erro;
    }
    catch(...){
        throw std::string("Erro desconhecido!\n");
    }
}

template<class type>
void no<type>::desmontaNo(no<type> *sair, type *dado){
    *dado =sair->dado;
    delete sair;
}
template<class type>
no<type>::no(){
    previous = NULL;
    next = NULL;
}

#endif // NO_H
