#ifndef GRAFO_H
#define GRAFO_H
#include<list.h>
#include<bits/stdc++.h>
#include<mypair.h>
#include<aresta.h>
#define INFINITO INT_MAX
//MyPAIR E USADO COMO VERICE ONDE O PRIMEIRO PARAMETRO E O VERTICE E SEGUNDO O PESO
// O INDICE DO VETOR DE PONTEIROS É USADO COMO VERTICE-----------------------
typedef myPair<int,int> celula;
#define INF 1
class Grafo
{
private:
    List<celula> **G;
    int amount;
    void dfs(int vertice, bool *vet);
    void bfs(int &__x, int *vet);
    myPair<int, int> *dijkstra(int u);
public:
    void imprimir();//imprime o grafo
    void insertGrafo(Aresta &vertice);//vertex vetice que ela esta ligada;
    bool buscaEmProfundidade(int &vertex); // função de busca DFS
    void imprimirvertice(int &vertex); // imprimir um vertice
    bool verificaAresta(Aresta &);//verifica se existe uma aresta
    void imprimirVerciceAdj(int &index);//imprimir vertices adijacentes de um determinado vertice
    bool buscaEmLargura(int &__x);
    int MenorCaminho(int origem,int destino);
    void caminho(myPair<int,int> * aux);
    void imprimir(myPair<int,int> * aux);
    int buscar(int * subset,int v){if(subset[v]==-1)return v;return buscar(subset,subset[v]);}
    int imprimirCaminhoMinimo(myPair<int,int> *distance,int u,int v);

    int caminhoMinimo(int u,int v); // u é o inicio e v e o destino

    


    Grafo(int tam);
};
void Grafo::dfs(int vertice, bool *vet) {// busca em profundidade , vet e o vetor para verificar se foi vizidado
    vet[vertice] = true; // marcar que foi vistado

    for(int i=0;i<G[vertice]->size();i++){
        celula ii =G[vertice]->operator [](i);
        if(!vet[ii.first]){cout<<"\nVisitando : "<<ii<<endl;dfs(ii.first,vet);}
    }
}

void Grafo::bfs(int &__x, int *vet){
    celula ii; //  celula auxiliar para pegar o vertice que estamos
    List<int> fila;// fila para usar para percorrer
    fila.push_back(__x); // enquanto tiver elemento
    vet[__x]=0;//vetor de distancias começando desse vertice
    while(!fila.empty()){
        int __u=fila.front();// retira e retorna o elemento
        fila.pop_front();
        for(int i =0; i < G[__u]->size();i++){
            ii = G[__u]->operator [](i); // pegando a celula que estamos
            if(vet[ii.first]==-1){//verificando se ela já foi visitada
                fila.push_back(ii.first); // colocando na fila porque não foi visitado
                vet[ii.first] = vet[__u]+1;// marcando como visitado
                cout<<"VISITANDO : ";
                cout<<ii.first;
                puts("");

            }
        }
    }
}
void Grafo::imprimir(){
    puts("");
    celula aux;
    for(int i=0;i<amount;i++){
        cout<<" ["<<i<<" ] ->";
        for(int j=0;j<G[i]->size();j++){
            aux = G[i]->operator [](j);
            cout<<aux.first<<" -> ";
        }puts("NULL");
    }
}

void Grafo::insertGrafo(Aresta & vertice){
    try{
        if(vertice.vertice<0||vertice.vertice>amount)throw string("Posição de grafo invalida!\n");
        G[vertice.vertice]->push_back(vertice.__celula); // colocando a celula no grafo
    }catch(bad_alloc &erro){
        throw erro;
    }
}

bool Grafo::buscaEmProfundidade(int &vertex){
    if(vertex<0||vertex>amount) throw "Não existe o vertice";
    bool dfs_num[amount];// vetor para marcar o vertice que foi vizidado
    memset(dfs_num,false,sizeof(bool)*amount); // enchendo o vetor com falso
    cout<<"Visitando : "<<vertex<<endl;
    dfs(vertex,dfs_num);// vertex e o o vertice que deve começar
    int i;
   // for(i=0;i<amount;i++)cout<<"  "<<dfs_num[i];
    puts("");
    for(i =0;i<amount;i++){if(!dfs_num[i]){cout<<"Visistando :"<<i<<endl,dfs(i,dfs_num);}};
    return true;
}

void Grafo::imprimirvertice(int &vertex){
    if(vertex<0||vertex>amount) throw ("Não existe o vertice");
    puts("");//pular de linha
    cout<<" ["<<vertex<<"] ->";
    for(int i =0;i<G[vertex]->size();i++){
        celula ii = G[vertex]->operator [](i);
        cout<<ii.first<<" ->";
    }puts("NULL");
}

bool Grafo::verificaAresta(Aresta & verificar){ // vertex é a aresta de origem e celula(destino,peso) a de destino
    for(int i=0;i<G[verificar.vertice]->size();i++){//vertice de origem é uma lista e celula um elemento
        if(verificar.__celula==G[verificar.vertice]->operator[](i))return true;
    }return false;
}

void Grafo::imprimirVerciceAdj(int &index){
    celula ii;
    puts("");//Função Pular de linha
    cout<<"[ "<<index<<" ] -> ";
    for(int i=0;i<G[index]->size();i++){
        ii = G[index]->operator [](i);
        cout<<"[ "<<ii.first<<" ] -> ";
    }puts("NULL");
}

bool Grafo::buscaEmLargura(int &__x){
    int i;
    if(__x<0||__x>amount) throw ("Não existe o vertice");
    int bfs_num[amount];// vetor para marcar o vertice que foi vizidado
    cout<<"PARTINDO VERTICE : "<<__x<<endl;
    memset(bfs_num,-1,sizeof(int)*amount); // enchendo o vetor com falso
    bfs(__x,bfs_num);
    for(i =0;i<amount;i++)cout<<" "<<bfs_num[i];
    puts("");
    for(i =0;i<amount;i++){if(bfs_num[i]==-1)cout<<"VISITANDO : "<<i<<endl,bfs(i,bfs_num);}
    return true;

}

int Grafo::MenorCaminho(int origem, int destino)
{
    if(origem<0||origem>=amount||destino>=amount||destino<0)throw ("Origem ou destino invalido!\n");
    myPair<int,int> *vet =dijkstra(origem);
    return (vet[destino].second!=INFINITO)? vet[destino].second:INFINITO;
}

myPair<int,int> *Grafo::dijkstra(int u)
{
    myPair<int,int> *VetorDistancia=new myPair<int,int>[amount];  //vetor que armazenara as distancias de todos os vertices
    bool visitados[amount];        //vetor que auxiliarar para verificar se ja foi visitado
    for(int i=0;i<amount;i++)VetorDistancia[i].first =-1,VetorDistancia[i].second=INFINITO;
    memset(visitados,false,sizeof(bool)*amount); //marcadando todos os vertices como não visitado
    VetorDistancia[u].second=0;//marcando a distancia de ele ate ele
    List<myPair<int,int>> filaPriority; // fila de prioridade para fazer heap
    celula ii; // celula para guarda os pesos como prioridade
    ii.first =0;ii.second=u;// pair com peso e vestice de destino
    filaPriority.priority_queue(ii); // colocando celula na fila de prioridade
    while(!filaPriority.empty())
    {
        ii = filaPriority.front();
        filaPriority.pop_front();
        if(!visitados[ii.second])
        {
            visitados[ii.second] = true;//marcando que foi visitado
            for(int i=0;i<G[ii.second]->size();i++)
            {
                celula aux = G[ii.second]->operator [](i); // vetor.first e o antecessor do caminho , vetor. second a distancia minima
                if(VetorDistancia[aux.first].second>VetorDistancia[ii.second].second+aux.second) //verificando se o caminho e menhor
                {
                    VetorDistancia[aux.first].second = VetorDistancia[ii.second].second+aux.second;//atualizando a distancia porque achou uma menos
                    VetorDistancia[aux.first].first = ii.second;//amazenado de onde ele esta vindo(caminho)
                    aux.second =aux.first; // sentando pair para colocar na fila
                    aux.first =VetorDistancia[aux.first].second;
                    filaPriority.priority_queue(aux);
                }
            }

        }
    }

    return VetorDistancia;
}
int Grafo::caminhoMinimo(int u, int v)
{
    if(u<0||u>=amount||v<0||v>=amount) throw("Arestas invalidas !");
    myPair<int,int> *vetorDistancias;
    vetorDistancias = dijkstra(u);
    int w = vetorDistancias[v].second;
    if(w==INT_MAX) return INT_MAX;
     puts("");
    puts("Menor caminho : ");
    cout<<u<<" ";
           imprimirCaminhoMinimo(vetorDistancias,u,v);
    cout<<v;
    puts("");
    delete vetorDistancias;
    return w;
}

inline void Grafo::imprimir(myPair<int, int> *aux) {for(int i =0; i <amount;i++)cout<<aux[i]<<"\n";}

int Grafo::imprimirCaminhoMinimo(myPair<int, int> *distance, int u, int v)
{
    if(u!=distance[v].first){
    int i =imprimirCaminhoMinimo(distance,u,distance[v].first);
    cout<<i<<" ";

    }
   return v;
}
Grafo::Grafo(int tam){
    if(tam<=0)throw std::string("Tamanho não suportado!\n"); // casoo tamanho inválido
    try{
        G= new List<celula>*[tam];// alocando um vetor de ponteiros para lista de celula
        for(int i =0;i<tam;i++){
            G[i]= new List<celula>();// alocando uma lista para cada posição
        }
        amount = tam;
    }catch(std::bad_alloc &erro){//caso falte memoria
        throw erro;
    }catch(string &erro){
        throw erro;
    }catch(...){
        throw std::string("Erro desconhecido!\n");
    }

}


#endif // GRAFO_H
