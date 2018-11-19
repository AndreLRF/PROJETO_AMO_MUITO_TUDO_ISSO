#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale.h>

using namespace std;



typedef struct NO{
 		string nome;
		int idade;
		int numero_pedido;
		struct NO* proximo;
 }*Cliente;

typedef struct NODOIS{
 		int numero;
 		int opcao;
 		int vtotal;
		struct NODOIS* proximo;
 }*Pedido;

typedef struct NOTRES{
 		string nome;
 		int tempo;
 		int numero;
		struct NOTRES* proximo;
 }*Espera;

 typedef struct NOQUATRO{
 		int nota_p;
 		int nota_r;
 		int nota_m;
 		int nota_b;
 		int nota_o;
}*Votos;



static Cliente head_idoso = NULL;
static Cliente tail_idoso = NULL;
static Cliente aux_idoso = NULL;

static Cliente head_geral = NULL;
static Cliente tail_geral = NULL;
static Cliente aux_geral = NULL;

static Pedido head_ped = NULL;
static Pedido tail_ped = NULL;
static Pedido aux_ped = NULL;

static Espera head_esp = NULL;
static Espera tail_esp = NULL;
static Espera aux_esp = NULL;

static Votos votos = NULL;

static int aux = 1;
static int del = 0;

bool vazio_idoso(){
    return head_idoso == NULL;
}
bool vazio_geral(){
    return head_geral == NULL;
}
bool vazio_ped(){
    return head_ped == NULL;
}
bool vazio_esp(){
    return head_esp == NULL;
}
bool vazio_votos(){
    return votos == NULL;
}

void inserir_no_final(string novonome, int novaidade){
    //IDADE ATE 65 ANOS
    if(novaidade<64){
        aux_geral = new NO;
        aux_geral->nome = novonome;
        aux_geral->idade = novaidade;
        aux_geral->proximo = NULL;
        if(vazio_geral()){
            head_geral = aux_geral;
            tail_geral = aux_geral;
        }else{
            tail_geral->proximo = aux_geral;
            tail_geral = aux_geral;
        }
    }else{ //IDADE APOS 65 ANOS
        aux_idoso = new NO;
        aux_idoso->nome = novonome;
        aux_idoso->idade = novaidade;
        aux_idoso->proximo = NULL;
        if(vazio_idoso()){
            head_idoso = aux_idoso;
            tail_idoso = aux_idoso;
        }else{
            tail_idoso->proximo = aux_idoso;
            tail_idoso = aux_idoso;
        }
    }
    system("CLS");

}

void mostrar(){
    cout << endl;
    if(vazio_idoso()) {
        cout<< "FILA DE IDOSOS VAZIA!!!" << endl;
        cout << endl;
    } else {
    cout<<"FILA IDOSOS:"<<endl;
    for(aux_idoso = head_idoso; aux_idoso != NULL; aux_idoso=aux_idoso->proximo){
        cout <<aux_idoso->nome <<" - "<< aux_idoso->idade <<" anos"<<endl;
    }}
    cout<<endl;
  if(vazio_geral()) {
        cout<< "FILA GERAL VAZIA!!!" << endl;
        cout << endl;
    } else {
    cout<<"FILA GERAL:"<<endl;
    for(aux_geral = head_geral; aux_geral != NULL; aux_geral=aux_geral->proximo){
        cout <<aux_geral->nome <<" - "<< aux_geral->idade <<" anos"<<endl;
    }}
    cout<<endl;
    if(vazio_esp()) {
        cout<< "FILA ESPERA VAZIA!!!" << endl;
        cout << endl;
    } else {
    cout<<"FILA Espera:"<<endl;
    for(aux_esp = head_esp; aux_esp != NULL; aux_esp=aux_esp->proximo){
        cout <<aux_esp->nome <<" -no: "<< aux_esp->numero <<" -Tempo: "<< aux_esp->tempo<<" mins"<<endl;
    }}
    system("pause");
    system("CLS");

}

void mostrar_votos(){
    cout << endl;
    if(vazio_votos()) {
        cout<< "NENHUM VOTO COMPUTADO" << endl;
        cout << endl;
    }else{
    cout<<"Votos Computados:"<<endl;
    cout <<"Otimo:    "<<votos->nota_o<<" Votos"<<endl;
    cout <<"Bom:      "<<votos->nota_b<<" Votos"<<endl;
    cout <<"Mediano:  "<<votos->nota_m<<" Votos"<<endl;
    cout <<"Ruim:     "<<votos->nota_r<<" Votos"<<endl;
    cout <<"Pessiomo: "<<votos->nota_p<<" Votos"<<endl;
    }
    cout<<endl;

}

void encontrar(string nome){
    cout << endl;
    int i=1, j=1;
    aux_idoso = head_idoso;
    while (aux_idoso->proximo != NULL && aux_idoso->nome != nome) {
        aux_idoso = aux_idoso->proximo;
        i++;
    }
    if(aux_idoso->nome == nome)
    {
        cout << "Encontrado na fila de idoso na posicao:" << i << endl;
    }
    else if(aux_idoso->proximo == NULL)
    {
        cout << "Nenhum Nome encontrado na fila de idoso..." << endl;
    }
    cout << endl;
    aux_geral = head_geral;
    while (aux_geral->proximo != NULL && aux_geral->nome != nome) {
        aux_geral = aux_geral->proximo;
        j++;
    }
    if(aux_geral->nome == nome)
    {
        cout << "Encontrado na fila geral na posicao:" << j << endl;
    }
    else if(aux_geral->proximo == NULL)
    {
        cout << "Nenhum Nome encontrado na fila geral..." << endl;
    }

    system("pause");
    system("CLS");

}

void pedido(int x){
    int numero,opcao,vtotal,tempo;
    numero = aux;
    aux = aux +1;
        cout<<" ***FAZENDO PEDIDO***"<<endl;
    if(x==1){
        cout<<" FILA IDOSO"<<endl;
        cout<<" Cliente: "<<head_idoso->nome<<" Pedido Numero: "<< numero<<endl;
     }else{
     cout<<" FILA GERAL"<<endl;
        cout<<" Cliente: "<<head_geral->nome<<" Pedido Numero: "<< numero<<endl;
     }
        cout<<" Opções:"<<endl;
        cout<<"  1-Hamburguer $20"<<endl;
        cout<<"  2-Suco $5"<<endl;
        cout<<"  3-Sobremesa $8"<<endl;
        cout<<" COMBOS:"<<endl;
        cout<<"  4-Hamburguer + Suco $24"<<endl;
        cout<<"  5-Hamburguer + Sobremesa $26"<<endl;
        cout<<"  6-Hamburguer + Suco + Sobremesa $30"<<endl;
        cout<<"  7-Suco +Sobremesa $12"<<endl;
        cin>>opcao;
        switch(opcao){
                case 1:{
                    vtotal=20;
                    tempo=6;
                break;
                }
                case 2:{
                    vtotal=5;
                    tempo=3;
                break;
                }
                case 3:{
                    vtotal=8;
                    tempo=3;
                break;
                }
                case 4:{
                    vtotal=24;
                    tempo=7;
                break;
                }
                case 5:{
                    vtotal=26;
                    tempo=7;
                break;
                }
                case 6:{
                    vtotal=30;
                    tempo=8;
                break;
                }
                case 7:{
                    vtotal=12;
                    tempo=7;
                break;
                }
        }

        aux_esp = new NOTRES;
        aux_esp->numero = numero;
        aux_esp->tempo = tempo;
        if(x==1){
            aux_esp->nome = head_idoso->nome;
            head_idoso->numero_pedido = numero;
           //remover(head_idoso->nome, 1);
        }else{
            aux_esp->nome = head_geral->nome;
            head_geral->numero_pedido = numero;
            //remover(head_geral->nome, 2);
        }
       if(vazio_esp()){
            head_esp = aux_esp;
            tail_esp = aux_esp;
        }else{
            tail_esp->proximo = aux_esp;
            tail_esp = aux_esp;
        }
        aux_ped = new NODOIS;
        aux_ped->numero = numero;
        aux_ped->opcao = opcao;
        aux_ped->vtotal = vtotal;
        aux_ped->proximo = NULL;
        if(vazio_ped()){
            head_ped = aux_ped;
            tail_ped = aux_ped;
        }else{
            tail_ped->proximo = aux_ped;
            tail_ped = aux_ped;
        }
        system("CLS");
}

void votar(){
    int opc,aux;
    cout<<"CLIENTE GOSTARIA DE PARTICIPAR DE UMA PESQUISA DE SATISFAÇÂO?"<<endl;
    cout<<" 1-SIM 2-NÃO"<<endl;
    cin>>opc;
    if(aux==1){
        if(vazio_votos()){
        votos = new NOQUATRO;
        votos->nota_o =0;
        votos->nota_b =0;
        votos->nota_m =0;
        votos->nota_r =0;
        votos->nota_p =0;
        }
        cout<<"Indique qual seu nivel de satisfação com o atendimento"<<endl;
        cout<<"1-Pessimo 2-Ruim 3-Mediano 4-Bom 5-Otimo "<<endl;
        cin>>aux;
        switch(aux){
            case 1:{
                votos->nota_p=votos->nota_p+1;
                break;
                }
            case 2:{
                votos->nota_r=votos->nota_r+1;
                break;
                }
            case 3:{
                votos->nota_m=votos->nota_m+1;
                break;
                }
            case 4:{
                votos->nota_b=votos->nota_b+1;
                break;
                }
            case 5:{
                votos->nota_o=votos->nota_o+1;
                break;
                }
        }
}

void remover(int x){

        if(x ==1){
        aux_idoso = head_idoso;
        head_idoso = head_idoso->proximo;
        delete aux_idoso;
        }else{
        aux_geral = head_geral;
        head_geral = head_geral->proximo;
        delete aux_geral;

        }
       /* while(aux_idoso->proximo!=NULL && aux_idoso->nome != x){
            prev = aux_idoso;
            aux_idoso = aux_idoso->proximo;
        }
        if(aux_idoso->nome == x) {
            prev->proximo = aux_idoso->proximo;
            delete aux_idoso;
        }
        else if(aux_idoso->proximo == NULL)
        {
            cout << "Nome " << x << " nao encontrado para ser removido." << endl;
        }
    }else{
        aux_geral = head_geral;
        while(aux_geral->proximo != NULL && aux_geral->nome != x){
            prev = aux_geral;
            aux_geral = aux_geral->proximo;
        }
        if(aux_geral->nome == x) {
            prev->proximo = aux_geral->proximo;
            delete aux_geral;
        }
        else if(aux_geral->proximo == NULL)
        {
            cout << "Nome " << x << " nao encontrado para ser removido." << endl;
        }*/

}


void limpar_memorias(){
    Cliente Marvel;
    Cliente RIP;
    Pedido Stan;
    Espera Lee;
    delete aux_geral;
    delete aux_idoso;
    delete aux_ped;
    delete aux_esp;
    delete tail_geral;
    delete tail_idoso;
    delete tail_ped;
    delete tail_esp;
    delete votos

    while (head_geral->proximo != NULL) {
        Marvel = head_geral;
        head_geral = head_geral->proximo;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        Marvel->proximo = NULL;
        delete Marvel;
    }
    while (head_idoso->proximo != NULL) {
        RIP = head_idoso;
        head_idoso = head_idoso->proximo;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        RIP->proximo = NULL;
        delete RIP;
    }
    while (head_ped->proximo != NULL) {
        Stan = head_ped;
        head_ped = head_ped->proximo;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        Stan->proximo = NULL;
        delete Stan;
    }
     while (head_esp->proximo != NULL) {
        Lee = head_esp;
        head_esp = head_esp->proximo;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        Lee->proximo = NULL;
        delete Lee;
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int seletor=-1,idade,a;
    string nome,name;

    do{
    cout<<endl;
    cout<<"1- Novo Cliente"<<endl;
    cout<<"2- Buscar na Fila"<<endl;
    cout<<"3- Fazer Pedido"<<endl;
    cout<<"4- Chamar Pedido"<<endl;
    cout<<"9- Mostrar filas"<<endl;
    cout<<"0- Sair do Programa"<<endl;
    cin>>seletor;
    system("CLS");
    cout<<endl;
    switch(seletor){
            case 1:{
                cout<<"Nome do Cliente:"<<endl;
                cin>>nome;
                cout<<"Idade do Cliente:"<<endl;
                cin>>idade;
                inserir_no_final(nome,idade);
                break;
                }

            case 2:{
                cout<<"Pesquiser por nome do Cliente:"<<endl;
                cin>>nome;
                encontrar(nome);
                break;
            }

            case 3:{
                if(vazio_idoso() && vazio_geral()){
                    cout<<"FILAS VAZIAS"<<endl;
                    cout<<endl;
                }else if( head_idoso!= NULL){
                    pedido(1);
                    votar();
                    remover(1);
                }else{
                    pedido(2);
                    votar();
                    remover(2);
                }
                break;
            }
            case 4:{
                chamar();
                break;
                }


            case 8:{
                mostrar_votos();
                break;
                }
            case 9:{
                mostrar();
                break;
                }
    }

    }while(seletor!=0);
    system("CLS");
    cout<<"BYE"<<endl;
    system("pause");
    limpar_memorias();
	return 0;
}
