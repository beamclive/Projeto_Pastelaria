#include <iostream>
#include <locale>

using namespace std;

struct Pedido {
	int qtd_pizza; 
	int qtd_queijo; 
	int qtd_frango; 
	int qtd_vento;
	int qtd_pepsi; 
	int qtd_coca; 
}; 

struct Comanda {
	string nome; 
	int senha; 
	Pedido pedido; 
};

struct Estoque {
	int queijo; 
	int presunto; 
	int frango;
};

struct No {
	No *proximo; 
	No *anterior; 
	Comanda comanda; 
};

struct Lista {
	No *inicio; 
	No *fim; 
	int prox_senha; 
};

void iniciar(Lista *, Estoque *); 
void fazer_pedido(Lista *);
//void editar_pedido(Lista *);
//void entregar_pedido(Lista *);

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese"); 
	
	Lista lista;
	Estoque estoque;
	int opcao; 
	bool sair = false; 
	
	iniciar(&lista, &estoque); 

	do {	
		cout << "========== Menu ==========" << endl; 
		cout << "1 - Fazer pedido" << endl; 
		cout << "2 - Editar pedido" << endl; 
		cout << "3 - Entregar pedido" << endl; 
		cout << "4 - Sair" << endl; 
		cout << "Selecione a opção desejada: "; 
		cin >> opcao;
	
		switch (opcao){
			case 1:
				fazer_pedido(&lista);		
					
			case 2: 
				//editar_pedido(&lista);
		
			case 3: 
				//entregar_pedido(&lista); 
	
			case 4: 
				sair = true; 
				break; 
	
			}

	}while(sair == true); 
		
						
		
}


void iniciar (Lista *lista, Estoque *estoque){

	lista->inicio = NULL; 
	lista->fim = NULL; 
	lista->prox_senha = 1;
	
	estoque->queijo = 50000; 
	estoque->presunto = 20000; 
	estoque->frango = 10000;
} 

void fazer_pedido (Lista *lista){
	
	No *novoNo = new No; 	
	
	if (lista->inicio == NULL){
		lista->inicio = lista->fim = novoNo; 
	} else {
		novoNo->anterior = lista->fim;
		lista->fim->proximo = novoNo; 
		lista->fim = novoNo;
	}
	
	string nome; 
	int confirmar; 
	
	do{	
		cout << "Nome do cliente: ";
    	cin >> nome;
    
    	novoNo->comanda.nome = nome;
    
    	novoNo->comanda.senha = lista->prox_senha;
    	lista->prox_senha ++;
    	
    	cout << "Senha: " << novoNo->comanda.senha << endl; 
    
    	cout << "Quantidade de pasteis de pizza: ";
    	cin >> novoNo->comanda.pedido.qtd_pizza;
    
    	cout << "Quantidade de pasteis de queijo: ";
    	cin >> novoNo->comanda.pedido.qtd_queijo;
    
    	cout << "Quantidade de pasteis de frango: ";
    	cin >> novoNo->comanda.pedido.qtd_frango;
    
    	cout << "Quantidade de pasteis de vento: ";
    	cin >> novoNo->comanda.pedido.qtd_vento;
    
    	cout << "Quantidade de refrigerante Pepsi: ";
    	cin >> novoNo->comanda.pedido.qtd_pepsi;
    
    	cout << "Quantidade de refrigerante Coca-Cola: ";
    	cin >> novoNo->comanda.pedido.qtd_coca;
    
    	cout << "Digite 1 para confirmar ou 2 para cadastrar novo pedido: "; 
    	cin >> confirmar; 
    
	}while(confirmar == 2); 
}


//void editar_pedido (){
	
