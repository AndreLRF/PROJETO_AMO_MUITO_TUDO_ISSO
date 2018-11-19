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
 		int tempo = 0;
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
     if(vazio_esp()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |      FILA ESPERA VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |         FILA ESPERA           |"<<endl;
    for(aux_esp = head_esp; aux_esp != NULL; aux_esp=aux_esp->proximo){
        cout<<" | "<<aux_esp->nome<<endl;
        cout<<" | NUMERO:"<<aux_esp->numero<<"                     |"<<endl;
        cout<<" | TEMPO: "<<aux_esp->tempo<<" Mins                 |"<<endl;
        cout<<" |_______________________________|"<<endl;
    }}
    cout << endl;
    cout << endl;
    if(vazio_idoso()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |       FILA IDOSO VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |          FILA IDOSO           |"<<endl;
    for(aux_idoso = head_idoso; aux_idoso != NULL; aux_idoso=aux_idoso->proximo){
        cout<<" | "<<aux_idoso->nome<<" - "<< aux_idoso->idade <<" Anos"<<endl;
        cout<<" |_______________________________|"<<endl;
    }}
    cout << endl;
    cout<<endl;
  if(vazio_geral()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |       FILA GERAL VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |          FILA GERAL           |"<<endl;
    for(aux_geral = head_geral; aux_geral != NULL; aux_geral=aux_geral->proximo){
        cout<<" | "<<aux_geral->nome<<" - "<< aux_geral->idade <<" Anos"<<endl;
        cout<<" |_______________________________|"<<endl;
    }}
    cout<<endl;

    system("pause");
    system("CLS");

}

void mostrar_pedidos(){
     if(vazio_ped()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |     FILA PEDIDOS VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |        FILA PEDIDOS           |"<<endl;
    for(aux_ped = head_ped; aux_ped != NULL; aux_ped=aux_ped->proximo){
        cout<<" | NUMERO: "<<aux_ped->numero<<endl;
        cout<<" | OPÇÃO: "<<aux_ped->opcao<<endl;
        cout<<" | VALOR TOTAL: "<<aux_ped->vtotal<<endl;
        cout<<" | TEMPO: "<<aux_ped->tempo<<" Mins"<<endl;
        cout<<" |_______________________________|"<<endl;
    }}
    cout << endl;
    system("pause");
    system("CLS");

}

void mostrar_votos(){
    cout << endl;
    if(vazio_votos()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |     NENHUM VOTO COMPUTADO     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    }else{
    cout<<"  _______________________________"<<endl;
    cout<<" |                               |"<<endl;
    cout<<" |       VOTOS  COMPUTADOS       |"<<endl;
    cout<<" |     OTIMO............"<<votos->nota_o<<" VOTOS  |"<<endl;
    cout<<" |     BOM.............."<<votos->nota_b<<" VOTOS  |"<<endl;
    cout<<" |     MEDIANO.........."<<votos->nota_m<<" VOTOS  |"<<endl;
    cout<<" |     RUIM............."<<votos->nota_r<<" VOTOS  |"<<endl;
    cout<<" |     PESSIMO.........."<<votos->nota_p<<" VOTOS  |"<<endl;
    cout<<" |_______________________________|"<<endl;
    }
    cout<<endl;
    system("pause");
    system("CLS");
}

void encontrar(string nome){
    cout << endl;
    int i=1, j=1,k=0;

    if(aux_idoso!=NULL){
        aux_idoso = head_idoso;
        while (aux_idoso->proximo != NULL && aux_idoso->nome != nome){
            aux_idoso = aux_idoso->proximo;
            i++;
        }
        if(aux_idoso->nome == nome){
            cout<<"  ________________________________________"<<endl;
            cout<<" |                                        |"<<endl;
            cout<<" |ENCONTRADO NA FILA IDOSO NA POSIÇÃO: "<<i<<"  |"<<endl;
            cout<<" |________________________________________|"<<endl;
        }
        }else{
            k=k+1;
        }

        if(aux_geral!=NULL){
            aux_geral = head_geral;

        while (aux_geral->proximo != NULL && aux_geral->nome != nome) {
            aux_geral = aux_geral->proximo;
            j++;
        }
        if(aux_geral->nome == nome){
            cout<<"  ________________________________________"<<endl;
            cout<<" |                                        |"<<endl;
            cout<<" |ENCONTRADO NA FILA GERAL NA POSIÇÃO: "<<j<<"  |"<<endl;
            cout<<" |________________________________________|"<<endl;
        }
        }else{
            k=k+1;
        }
        if(k==2){
            cout<<"  _____________________________________"<<endl;
            cout<<" |                                    |"<<endl;
            cout<<" |  NENHUM NOME FOI CADASTRADO AINDA  |"<<endl;
            cout<<" |____________________________________|"<<endl;
        }
    system("pause");
    system("CLS");

}

void pedido(int x){
    int numero,opcao,vtotal,tempo;
    numero = aux;
    aux = aux +1;
    cout<<"  _____________________________________"<<endl;
    cout<<" |                                    |"<<endl;
    cout<<" |      ***FAZENDO PEDIDO***          |"<<endl;
    if(x==1){
        cout<<" |            FILA IDOSO              |"<<endl;
        cout<<" |   CLIENTE: "<<head_idoso->nome<<endl;
        cout<<" |   PEDIDO NUMERO: "<< numero<<endl;
     }else{
        cout<<" |            FILA GERAL              |"<<endl;
        cout<<" |   CLIENTE: "<<head_geral->nome<<endl;
        cout<<" |   PEDIDO NUMERO: "<< numero<<endl;
         }
        cout<<" |____________________________________|"<<endl;
        cout<<" |                                    |"<<endl;
        cout<<" | OPÇÕES:                            |"<<endl;
        cout<<" |  1-HAMBURGUER..................$20 |"<<endl;
        cout<<" |  2-SUCO........................$5  |"<<endl;
        cout<<" |  3-SPBREMESA...................$8  |"<<endl;
        cout<<" | COMBOS:                            |"<<endl;
        cout<<" |  4-HAMBURGUER+SUCO.............$24 |"<<endl;
        cout<<" |  5-HAMBURGUER+SOBREMESA........$26 |"<<endl;
        cout<<" |  6-HAMBURGUER+SUCO+SOBREMESA...$30 |"<<endl;
        cout<<" |  7-SUCO+SOBREMESA..............$12 |"<<endl;
        cout<<" |____________________________________|"<<endl;
        cout<<" | OPÇÂO: ";
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
        aux_ped->tempo = tempo;
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
}

void votar(){
    int opc,aux;
    cout<<"  _____________________________________________________________"<<endl;
    cout<<" |                                                             |"<<endl;
    cout<<" |CLIENTE GOSTARIA DE PARTICIPAR DE UMA PESQUISA DE SATISFAÇÂO?|"<<endl;
    cout<<" |                        1-SIM 2-NÃO                          |"<<endl;
    cout<<" |_____________________________________________________________|"<<endl;
    cout<<" | OPÇÂO: ";
    cin>>opc;
    cout<<endl;
    if(opc==1){
        if(vazio_votos()){
        votos = new NOQUATRO;
        votos->nota_o =0;
        votos->nota_b =0;
        votos->nota_m =0;
        votos->nota_r =0;
        votos->nota_p =0;
        }
    cout<<"  _____________________________________________________________"<<endl;
    cout<<" |                                                             |"<<endl;
    cout<<" |    INDIQUE QUAL SEU NIVEL DE SATISFAÇÃO COM O ATENDIMENTO   |"<<endl;
    cout<<" |            1-PESSIMO 2-RUIM 3-MEDIANO 4-BOM 5-OTIMO         |"<<endl;
    cout<<" |_____________________________________________________________|"<<endl;
    cout<<" | OPÇÂO: ";
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
    system("pause");
    system("CLS");
}

void chamar(int numero_chamado){
     cout << endl;
     if(aux_ped!=NULL){
        aux_ped = head_ped;
        while (aux_ped->proximo != NULL && aux_ped->numero != numero_chamado){
            aux_ped = aux_ped->proximo;
        }
        if(aux_ped->numero == numero_chamado){
           //DELETAR DAS FILAS PEDIDOS E ESPERA
        }

    system("pause");
    system("CLS");
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
    delete votos;

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
    int seletor=-1,idade,numero;
    string nome;

    do{

    cout<<"      _________________      "<<endl;
    cout<<"     ( ' ' ' '  ' ' ' ')     "<<endl;
    cout<<"    (_'_'_'_'_'__'_'_'_')    "<<endl;
    cout<<"    /#/#/#/#/#/#/#/#/#/#    "<<endl;
    cout<<"    =_=_=_=_=_=_=_=_=_=_=   "<<endl;
    cout<<"    ( ORLANDO'S  BURGER )    "<<endl;
    cout<<"    (___________________)    "<<endl;
    cout<<"    @@@@@@@@@@@@@@@@@@@@@   "<<endl;
    cout<<"     ___________________    "<<endl;
    cout<<"    (___________________)   "<<endl;
    cout<<endl;
    cout<<"____________________________"<<endl;
    cout<<"|                          |"<<endl;
    cout<<"|     1- NOVO CLIENTE      |"<<endl;
    cout<<"|    2- BUSCAR NA FILA     |"<<endl;
    cout<<"|     3- FAZER PEDIDO      |"<<endl;
    cout<<"|    4- CHAMAR PEDIDO      |"<<endl;
    cout<<"|    5- MOSTRAR PEDIDOS    |"<<endl;
    cout<<"|     6- MOSTRAR VOTOS     |"<<endl;
    cout<<"|     7- MOSTRAR FILAS     |"<<endl;
    cout<<"|    0- SAIR DO PROGRAMA   |"<<endl;
    cout<<"|__________________________|"<<endl;
    cout<<"| OPÇÂO: ";
    cin>>seletor;
    system("CLS");
    cout<<endl;
    switch(seletor){
            case 1:{
                cout<<"____________________________"<<endl;
                cout<<"|                          |"<<endl;
                cout<<"|      *NOVO  CLIENTE*     |"<<endl;
                cout<<"|    NOME: ";
                cin>>nome;
                cout<<"|    IDADE: ";
                cin>>idade;
                cout<<"|__________________________|"<<endl;
                inserir_no_final(nome,idade);
                break;
                }

            case 2:{
                cout<<"____________________________"<<endl;
                cout<<"|                          |"<<endl;
                cout<<"|    *PESQUISA POR NOME*   |"<<endl;
                cout<<"|  NOME: ";
                cin>>nome;
                cout<<"|__________________________|"<<endl;
                encontrar(nome);
                break;
            }

            case 3:{
                if(vazio_idoso() && vazio_geral()){
                    cout<<"____________________________"<<endl;
                    cout<<"|                          |"<<endl;
                    cout<<"|       FILAS VAZIAS       |"<<endl;
                    cout<<"|__________________________|"<<endl;
                    cout<<endl;
                    system("pause");
                    system("CLS");

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
                cout<<"____________________________"<<endl;
                cout<<"|                          |"<<endl;
                cout<<"|    *CHAMAR POR NUMERO*   |"<<endl;
                cout<<"| NUMERO: ";
                cin>>numero;
                cout<<"|__________________________|"<<endl;
                chamar(numero);
                break;
                }

            case 5:{
                mostrar_pedidos();
                break;
                }


            case 6:{
                mostrar_votos();
                break;
                }
            case 7:{
                mostrar();
                break;
                }
    }

    }while(seletor!=0);
    system("CLS");
    cout<<"  _____   __    __   _______       __    __   __    __   __   ________   _______  "<<endl;
    cout<<" |  _  | |  |  |  | |  ___  |     |  |  |  | |  |  |  | |  | |__   ___| |  ___  | "<<endl;
    cout<<" | |_| | |    /   | | |   | |     |    /   | |  |  |  | |  |    |  |    | |   | | "<<endl;
    cout<<" |  _  | | |   /| | | |   | |     | |   /| | |  |  |  | |  |    |  |    | |   | | "<<endl;
    cout<<" | | | | | |  / | | | |___| |     | |  / | | |  |__|  | |  |    |  |    | |___| | "<<endl;
    cout<<" |_| |_| |_|    |_| |_______|     |_|    |_| |________| |__|    |__|    |_______| "<<endl;
    cout<<"  ________   __    __   ______    _______      __   ______   ______   _______  ___ "<<endl;
    cout<<" |__   ___| |  |  |  | |  ___    |  ___  |    |  | |  ____| |   ___| |  ___  ||   |"<<endl;
    cout<<"    |  |    |  |  |  | | |   | | | |   | |    |  | | |____  | |____  | |   | ||   |"<<endl;
    cout<<"    |  |    |  |  |  | | |   | | | |   | |    |  | |____  | |____  | | |   | ||   |"<<endl;
    cout<<"    |  |    |  |__|  | | |___| | | |___| |    |  |  ____| |  ____| | | |___| |   /"<<endl;
    cout<<"    |__|    |________| |______/  |_______|    |__| |______| |______| |_______| (_)"<<endl;





    system("pause");
    limpar_memorias();
	return 0;
}
