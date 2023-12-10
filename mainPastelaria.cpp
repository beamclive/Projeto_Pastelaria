#include <iostream>
#include <locale>
#include <fstream>

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

struct Vendas {
	int qtd_pizza; 
	int qtd_queijo; 
	int qtd_frango; 
	int qtd_vento;
	int qtd_pepsi; 
	int qtd_coca; 
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
	int tamanho_lista;  
};

void iniciar(Lista *, Estoque *, Vendas *); 
void fazer_pedido(Lista *);
void editar_pedido(Lista *);
void entregar_pedido(Lista *, Estoque *, Vendas *);
void relatorio_vendas(Lista *, Estoque *, Vendas *); 

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese"); 
	
	Lista lista;
	Estoque estoque;
	Vendas vendas; 
	int opcao; 
	bool sair = false; 
	
	iniciar(&lista, &estoque, &vendas); 

	do {	
		cout << "\n========== Menu ==========" << endl; 
		cout << "1 - Fazer pedido" << endl; 
		cout << "2 - Editar pedido" << endl; 
		cout << "3 - Entregar pedido" << endl; 
		cout << "4 - Visualizar relatório de vendas" << endl; 
		cout << "5 - Sair" << endl; 
		cout << "Selecione a opção desejada: "; 
		cin >> opcao;
	
		switch (opcao){
			case 1:
				fazer_pedido(&lista);
				break; 		
					
			case 2: 
				editar_pedido(&lista);
				break; 
			case 3: 
				entregar_pedido(&lista, &estoque, &vendas); 
				break; 
			
			case 4:
				relatorio_vendas(&lista, &estoque, &vendas); 
				break; 
				
			case 5: 
				sair = true; 
				break; 
	
			}

	}while(sair != true); 
				
		
}

// função p iniciar a lista e o estoque 
void iniciar (Lista *lista, Estoque *estoque, Vendas *vendas){

	lista->inicio = NULL; 
	lista->fim = NULL; 
	lista->prox_senha = 1;
	
	estoque->queijo = 50000; 
	estoque->presunto = 20000; 
	estoque->frango = 10000;
	
	vendas->qtd_pizza = 0;
	vendas->qtd_queijo = 0;
	vendas->qtd_frango = 0;
	vendas->qtd_vento = 0;
	vendas->qtd_pepsi = 0;
	vendas->qtd_coca = 0;
} 

// função para cadastrar o pedido 
void fazer_pedido (Lista *lista){
	
	No *novoNo = new No; 	
	
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
	
	// incrementa os pedidos
	if (lista->inicio == NULL){
		lista->inicio = lista->fim = novoNo; 
		lista->tamanho_lista ++;
	} else {
		novoNo->anterior = lista->fim;
		lista->fim->proximo = novoNo; 
		lista->fim = novoNo;
		lista->tamanho_lista ++;
	}
	 
}

// editar os pedidos já registrado 
void editar_pedido(Lista *lista){
	
	int senha;
	bool achou = false; 
	
	No *no = lista->inicio; 
	
	cout << "Digite a senha que deseja alterar o pedido: "; 
	cin >> senha; 
	
	for(int i = 0; i < lista->tamanho_lista; i++){
	
		if(senha == no->comanda.senha){	
		
			achou = true; 

			cout << "Nome do cliente: " << no->comanda.nome << endl;      	
    		cout << "Senha: " << no->comanda.senha << endl; 
    
    		cout << "Quantidade de pasteis de pizza: ";
    		cin >> no->comanda.pedido.qtd_pizza;
    
    		cout << "Quantidade de pasteis de queijo: ";
    		cin >> no->comanda.pedido.qtd_queijo;
    
    		cout << "Quantidade de pasteis de frango: ";
    		cin >> no->comanda.pedido.qtd_frango;
    
    		cout << "Quantidade de pasteis de vento: ";
    		cin >> no->comanda.pedido.qtd_vento;
    
    		cout << "Quantidade de refrigerante Pepsi: ";
    		cin >> no->comanda.pedido.qtd_pepsi;
    
    		cout << "Quantidade de refrigerante Coca-Cola: ";
    		cin >> no->comanda.pedido.qtd_coca;
    		
    		cout << "\nPedido alterado!" << endl; 
		}
		
		if(achou == false){
			cout << "\nCliente não encontrado!" << endl;  
		}
	}
}

// retirar os pedidos da lista 
void entregar_pedido(Lista *lista, Estoque *estoque, Vendas *vendas){	

	int senha;
	bool achou = false; 
	int confirmar; 
	
	No *no = lista->inicio;
	
	cout << "Digite a senha para entregar o pedido: "; 
	cin >> senha; 
	
	for(int i = 0; i < lista->tamanho_lista; i++){
	
		if(senha == lista->inicio->comanda.senha){
		
		achou = true; 
		
		cout << "** Deseja entregar o pedido '" << no->comanda.senha <<  "', do cliente '" << no->comanda.nome << "'?" << endl; 
		cout << "** Digite 1 para confirmar, ou 2 para cancelar a entrega: "; 
		cin >> confirmar;
		
			if (confirmar == 1){
				
				// incrementando no relatório a quantidade de vendas  
				vendas->qtd_pizza = vendas->qtd_pizza + no->comanda.pedido.qtd_pizza; 
				vendas->qtd_queijo = vendas->qtd_queijo + no->comanda.pedido.qtd_queijo;
				vendas->qtd_frango = vendas->qtd_frango + no->comanda.pedido.qtd_frango;
				vendas->qtd_vento = vendas->qtd_vento + no->comanda.pedido.qtd_vento;
				vendas->qtd_coca = vendas->qtd_coca + no->comanda.pedido.qtd_coca;
				vendas->qtd_pepsi = vendas->qtd_pepsi + no->comanda.pedido.qtd_pepsi;
				
				// retirada do estoque
				estoque->queijo = estoque->queijo - (50 * no->comanda.pedido.qtd_queijo) - (30 * no->comanda.pedido.qtd_pizza); 
				estoque->presunto = estoque->presunto - 30 * no->comanda.pedido.qtd_pizza;  
				estoque->frango = estoque->frango - 50 * no->comanda.pedido.qtd_frango; 
				
				// tirar pedido da lista 
				if (no == lista->inicio){
					lista->inicio = no->proximo; 
				} else if (no == lista->fim){
                    lista->fim = no->anterior;
                    lista->fim->proximo = NULL;
                } else {
                    no->anterior->proximo = no->proximo;
                    no->proximo->anterior = no->anterior;
                }
                
                delete no; 
                lista->tamanho_lista --; 
                
                cout << "\nPedido entregue!" << endl; 
			}
		}
		
		if(achou == false){
			cout << "\nCliente não encontrado!" << endl; 
		}
	} 
} 

void relatorio_vendas(Lista *lista, Estoque *estoque, Vendas *vendas){
	
	cout << "\n***** Relatorio de vendas do dia ******" << endl;
	
	cout << "\nBEBIDAS" << endl;
	cout << "=================" << endl; 
	cout << "Coca cola: " << vendas->qtd_coca << endl;
	cout << "Pepsi: " << vendas->qtd_pepsi << endl; 
	
	cout << "\nPASTEIS" << endl;
	cout << "=================" << endl; 
	cout << "Pizza: " << vendas->qtd_pizza << endl;
	cout << "Queijo: " << vendas->qtd_queijo << endl;
	cout << "Frango: " << vendas->qtd_frango << endl;
	cout << "Vento: " << vendas->qtd_vento << endl; 
	
	cout << "\n--- Estoque restante ---" << endl; 
	cout << "Queijo: " << estoque->queijo << endl; 
	cout << "Presunto: " << estoque->presunto << endl;
	cout << "Frango: " << estoque->frango << endl;
	
	// no txt
	ofstream txt;
	txt.open("relatorio_vendas.txt");
	
	txt << "***** Relatorio de vendas do dia ******" << endl;
	
	txt << "\nBEBIDAS" << endl;
	txt << "=================" << endl;
	txt << "Coca cola: " << vendas->qtd_coca << endl;
	txt << "Pepsi: " << vendas->qtd_pepsi << endl;
	
	txt << "\nPASTEIS" << endl;
	txt << "=================" << endl;
	txt << "Pizza: " << vendas->qtd_pizza << endl;
	txt << "Queijo: " << vendas->qtd_queijo << endl; 
	txt << "Frango: " << vendas->qtd_frango << endl;
	txt << "Vento: " << vendas->qtd_vento << endl; 
	
	txt << "\n--- Estoque restante ---" << endl;
	txt << "Queijo: " << estoque->queijo << endl; 
	txt << "Presunto: " << estoque->presunto << endl;
	txt << "Frango: " << estoque->frango << endl;
	
	txt.close(); 
}



