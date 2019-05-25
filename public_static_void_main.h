#ifndef PUBLIC_STATIC_VOID_MAIN_H
#define PUBLIC_STATIC_VOID_MAIN_H
#include<grafo.h>
#include<bits/stdc++.h>
#include<aresta.h>
using namespace std;
class Public_Static_Void_Main
{
public:
    Public_Static_Void_Main();
    void Public_Static_Void_MainC();

};
Public_Static_Void_Main::Public_Static_Void_Main(){
}

void Public_Static_Void_Main::Public_Static_Void_MainC()
{
    int tam_Grafo,qtd_aresta,i;
    Aresta inserir;
    cout<<"Digite o tamanho do grafo : ";
    cin>>tam_Grafo;
    cout<<"Digite a quantidade de aresta do grafo : ";
    cin>>qtd_aresta;
    Grafo grafo(tam_Grafo);
    for(i=0;i<qtd_aresta;i++){
        cin>>inserir;
        grafo.insertGrafo(inserir);
    }
    do{
        cout<<"0 Para sair \n"
              "1 Para imprimir o Grafo\n"
              "2 Para Busca em profundidade DFS\n"
              "3 Para Busca em Largura DFS\n"
              "4 Para Menor caminho\n"
              "5 Para Verificar Aresta\n"
              "6 Para imprimir vertices Adjacentes\n";
        cin>>i;
        switch (i) {
        case 0 : continue;
        case 1:
            grafo.imprimir();
            puts("");
            break;
        case 2:////////////////////////////////////////////////
            try{
            int vertex=-1; // vertece que começara a busca
            cout<<"Digite O vertice de partida";
            cin>>vertex;

            grafo.buscaEmProfundidade(vertex);
            puts("");
        }catch(const char *erro){cerr<<erro<<endl;}
            catch(string & erro){cerr<<erro<<endl;}
            catch(...){cout<<"ERRO DESCONHECIDO!\n";}
            break;
        case 3:
            try{
            int vertex=-1; // vertece que começara a busca
            cout<<"Digite O vertice de partida";
            cin>>vertex;
            grafo.buscaEmLargura(vertex);

        }catch(const char *erro){cerr<<erro<<endl;}
            catch(string & erro){cerr<<erro<<endl;}
            catch(...){cout<<"ERRO DESCONHECIDO!\n";}
            break;
        case 4:
            int origem,destino;
            try{
            cout<<"Digite o vertice de origem :  ";
            cin>>origem;
            cout<<"Digite o vertice de destino: ";
            cin>>destino;
            int custo = grafo.caminhoMinimo(origem,destino);
            if(custo!=INT_MAX)cout<<"CUSTO CAMINHO MINIMO : "<<custo<<" ! \n";
            else puts("NÃO EXISTE CAMINHO MINIMO!\n");

        }catch(const char * erro){cerr<<erro<<endl;}
            catch(string & erro){cerr<<erro<<endl;}
            catch(...){cout<<"ERRO DESCONHECIDO\n";}
            break;
        case 5:
            try{

            cin>>inserir;
            grafo.verificaAresta(inserir);
            grafo.verificaAresta(inserir)?puts("Aresta presente no grafo!"):puts("Nao existe essa aresta");

        }catch(const char * erro){cerr<<erro<<endl;}
            catch(string & erro){cerr<<erro<<endl;}
            catch(...){cout<<"ERRO DESCONHECIDO\n";}
            break;
        case 6:
            try{
            int vertex;
            cout<<"Digite o vertice : ";
            cin>>vertex;
            grafo.imprimirVerciceAdj(vertex);
        }catch(const char * erro){cerr<<erro<<endl;}
            catch(string & erro){cerr<<erro<<endl;}
            catch(...){cout<<"ERRO DESCONHECIDO\n";}

            break;

        default:
            break;
        }


    }while(i>0);

}


#endif // PUBLIC_STATIC_VOID_MAIN_H
