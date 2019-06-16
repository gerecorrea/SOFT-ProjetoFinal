#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <clocale>
#include <list>
#include <utility>

using namespace std;

#define MAX 100
list <int> codigosAdc;
list <string> loginsAdc;

/* CLASSE RUA */
class Rua{
	string nome;
	string bairro;
	bool congestionamento; 
	bool acidente;
	bool total;

	public:
		Rua (string nome, string bairro);
		void modificaSituacao(bool acidente, bool total, bool congestionamento); 
		void adicionarRuaSistema(string nome, string bairro);
		void removerRuaSistema (string nome, string bairro);

		string getNome();
		void setNome(string nome);
		string getBairro();
		void setBairro(string bairro);
		void setCongestionamento(bool congestionamento);
		bool getCongestionamento();
		void setAcidente(bool acidente);
		bool getAcidente();
		void setTotal(bool total);
		bool getTotal();
		
		void verificarRuasTotal();
		void adicionarRuaGeral(string nome, string bairro);
};

//FUNÇÕES CLASSE RUA
Rua::Rua(string nome, string bairro){ //construtor
	this->nome = nome;
	this->bairro = bairro;
	congestionamento = false;
	acidente=false;
	total=false;//se false é parcial ou não influente

}

void Rua::modificaSituacao(bool acidente, bool total, bool congestionamento){
	this->congestionamento = congestionamento;
	this->total = total;
	this->acidente = acidente;
}

string Rua::getNome(){
	return nome;
}

void Rua::setNome(string nome){
	this->nome=nome;
}

string Rua::getBairro(){
	return bairro;
}

void Rua::setBairro(string bairro){
	this->bairro=bairro;
}

void Rua::setCongestionamento(bool congestionamento){
	this->congestionamento=congestionamento;
}
bool Rua::getCongestionamento(){
	return congestionamento;
}

void Rua::setAcidente(bool acidente){
	this->acidente=acidente;
}

bool Rua::getAcidente(){
	return acidente;
}

void Rua::setTotal(bool total){
	this->total=total;
}

bool Rua::getTotal(){
	return total;
}



/* ----------------------- FIM CLASSE RUA ----------*/
list <Rua> RuaSist; //Declarando a lista de ruas do sistema após a criação da classe da mesma.

//A função aqui abaixo é necessária estar aqui para poder se utilizada na classe cliente.
void printaRuasParaAdc(){
	int cont=0;
	cout << "Lista de ruas: " << endl << endl;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		cont++;
		cout << "[" << cont << "] - " << q->getNome() << ", " << q->getBairro() << "." << endl;
	}
	cout << "[0] - Sair" << endl << endl;
}

/* CLASSE CLIENTE */
class Cliente{
	string nome;
	int cod;
	string email;
	string celular;
	string login;
	string senha;
	list <string> mensagens;//Lista para a caixa de mensagens

	public:
		list <Rua> ruasCliente; //Lista de ruas de cada cliente.


		Cliente (string nome, int cod, string email, string celular, string login, string senha);
		Cliente ();
		
		string getNome ();
		int getCod(); 
		string getEmail();
		string getCelular(); 
		string getLogin(); 
		string getSenha(); 
		void setNome(string nome); 
		void setCod(int cod); 
		void setEmail(string email);
		void setCelular(string celular);
		void setSenha(string senha); 
		void setLogin(string login); 
			
		void verificarRuas(); //Verifica as ruas de cada cliente e seus estados atuais.
		
		void printCliente();
		void printMenuCliente(); 
		void adcMsg(string msg);
		void verCaixa(); 
		void adicionarRua(int NumeroRua);
		void adicionarRua();
		void printRuasCliente();
};

//FUNÇÕES CLIENTE:
Cliente:: Cliente (string nome, int cod, string email, string celular, string login, string senha){
	this->nome = nome;
	this->cod = cod;
	this->email = email;
	this->celular = celular;
	this->login = login;
	this->senha = senha;		
}


string Cliente::getNome (){
	return nome;
}

int Cliente::getCod(){
	return cod;
}

string Cliente::getEmail(){
	return email;
}

string Cliente::getCelular(){
	return celular;
}

string Cliente::getLogin(){
	return login;
}

string Cliente::getSenha(){
	return senha;
}


void Cliente::setNome(string nome){
	this->nome=nome;
}

void Cliente::setCod(int cod){
	this->cod=cod;
}
void Cliente::setEmail(string email){
	this->email=email;
}
void Cliente::setCelular(string celular){ 
	this->celular=celular;
}

void Cliente::setLogin(string login){
	this->login=login;
}

void Cliente::setSenha(string senha){
	this->senha=senha;
}



void Cliente::printCliente(){
	cout << endl << "************* PERFIL CLIENTE *************" << endl << endl;
	cout << "Nome: " << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Celular: " << celular << endl;
	cout << "Codigo: " << cod << endl;
	cout << "Nome de login: " << login << endl;
	cout << "Quantidade de ruas adicionadas: " << ruasCliente.size() << endl;
}

void Cliente::printMenuCliente(){
	cout << endl << "************* MENU DO CLIENTE*************" << endl;
	cout << endl << "Usuario: " << nome << "\t\tCaixa de mensagens: " << mensagens.size() << endl << endl;
	cout << "[1] Adicionar ruas ao cliente." << endl;
	cout << "[2] Verificar ruas do sitema." << endl;
	cout << "[3] Verificar suas ruas adicionadas. " << endl;
	cout << "[4] Ver caixa de mensagens." << endl;
	cout << "[5] Ver perfil do cliente." << endl;
	cout << "[0] Sair da conta." << endl << endl; 
}

void Cliente::adcMsg(string msg){
	mensagens.push_front(msg);
}

void Cliente::verCaixa(){
	bool tem=false;
	cout << endl << "*********** CAIXA DE MENSAGENS ************" << endl << endl;
	while(mensagens.size()!=0){
		cout << mensagens.front() << endl << endl;
		mensagens.pop_front();
		tem=true;
	}
	if(tem==false)
		cout << "Não há mensagens a serem lidas." << endl;
	//As mensagens são excluídas da caixa após serem lidas.	
}


void Cliente::adicionarRua(int NumeroRua){
	int opcao10=0, contador=0,contador2=0;
	bool jatem=false;
	if(NumeroRua==0)
		return;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		contador++;
		if(contador==NumeroRua){
			for(list<Rua>::iterator p=RuaSist.begin(); p!=RuaSist.end(); ++p){
				contador2++;
				if(q == p && contador!=contador2){
					jatem=true;
				}
			}
			if(jatem==false){
				ruasCliente.push_back(*q);
				cout << endl << "Rua adicionada com sucesso." << endl << endl;
			}
			else
				cout << "Rua já existe no sistema." << endl << endl;
		}
	}
}


void Cliente::adicionarRua(){
	int opcao10=0, contador=0,contador2=0;
	bool jatem=false;
	cout << "************** ADIÇÃO DE RUA **************" << endl << endl;
	printaRuasParaAdc();
	cout << endl << "Digite a opção escolhida para ser adicionada: ";
	cin >> opcao10;
	cout << endl;
	if(opcao10==0)
		return;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		contador++;
		if(contador==opcao10){
			for(list<Rua>::iterator p=RuaSist.begin(); p!=RuaSist.end(); ++p){
				contador2++;
				if(q == p && contador!=contador2){
					jatem=true;
				}
			}
			if(jatem==false){
				ruasCliente.push_back(*q);
				cout << endl << "Rua adicionada com sucesso." << endl << endl;
			}
			else
				cout << "Rua já existe no sistema." << endl << endl;
			cout << "****************************************" << endl << endl;	
		}
	}
	if(opcao10 != 0)
		adicionarRua();
}

void Cliente::printRuasCliente(){
	bool tem=false;
	cout << endl;
	cout << "*************** RUAS DO CLIENTE *****************" << endl << endl;
	for(list<Rua>::iterator q=ruasCliente.begin(); q!=ruasCliente.end(); ++q){
		cout << "- " << q->getNome() << ", " << q->getBairro() << "." << endl;
		cout  << "Congestionamento: " << q->getCongestionamento() << endl;
		cout  << "Acidente: " << q->getAcidente() << endl;
		cout  << "Bloqueamento total: " << q->getTotal() << endl << endl;
		tem=true;
	}
	if(tem==false)
		cout << endl << "Não há ruas adicionadas ainda." << endl << endl;
	cout << "************************************************" << endl << endl;
}
/* --------------- FIM CLIENTE ---------------*/

list <Cliente> Clientes; //Lista para armazenar os clientes no sistema.

//FUNÇÕES FORA DAS CLASSES E MAIN PARA IMPLEMENTAÇÃO

void adicionaRuaSistema (string nome, string bairro){ 
	Rua *r1 = new Rua(nome, bairro);    
	RuaSist.push_back(*r1);
}

int geraValor(){//Gera um valor de código não repetido para o cliente
	int valor;
	bool registro=false;
	valor = rand()%10000000+1;
	for(list<int>::iterator q = codigosAdc.begin(); q!=codigosAdc.end(); q++){
		if(valor == *q){
			registro=true;
			break;
		}
	}
	if(registro==true)
		geraValor();
	else
		codigosAdc.push_back(valor);
	return valor;
}

void adicionaClienteSistema (string nome, string email, string celular, string login, string senha){
	int cod = geraValor();
	Cliente *c1 = new Cliente(nome, cod, email, celular, login, senha);
	Clientes.push_back(*c1);
}


void printaRuaSistema(){
	cout << endl << "************* RUAS DO SISTEMA ************* " << endl << endl;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		cout << "- " << q->getNome() << ", " << q->getBairro() << "." << endl;
		cout  << "Congestionamento: " << q->getCongestionamento() << endl;
		cout  << "Acidente: " << q->getAcidente() << endl;
		cout  << "Bloqueamento total: " << q->getTotal() << endl << endl;
	}
	cout << endl << "Quantidade de ruas no sistema: " << RuaSist.size() << endl << endl;
}

void modificaRua(string nomerua, string bairrorua, bool congest, bool acidente, bool total, string msg){
	bool modificou=false;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		if(q->getNome() == nomerua && q->getBairro() == bairrorua){
			q->setCongestionamento(congest);
			q->setAcidente(acidente);
			q->setTotal(total);
			modificou=true;
			cout << endl << "Rua modificada com sucesso" << endl;
			//DOUBLE ITERATOR, ITERANDO CADA CLIENTE EM CADA RUA ADICIONADA POR ELE E VENDO SE BATE
			for(list<Cliente>::iterator c1=Clientes.begin(); c1!=Clientes.end(); ++c1){	
				for(list<Rua>::iterator p=c1->ruasCliente.begin(); p!=c1->ruasCliente.end(); ++p){
					if(p->getNome() == q->getNome() && p->getBairro()==q->getBairro()){
							
						c1->ruasCliente.erase(p);
						c1->ruasCliente.push_back(*q); 
						c1->adcMsg(msg);
					}
				}
			}
		}
	}
	if(modificou==false)
		cout << "Rua não foi encontrada no sistema." << endl;
}


//FUNÇÕES ABAIXO FORA DAS CLASSES E MAIN
void realizaCadastro (){
	int valor;
	bool cond=true, loginRegistrado=false;
	string nome, email, celular, login, senha;
	int cod = geraValor();
	cout << "**************** CADASTRO ****************" << endl;
	cout << endl <<"Digite [0] caso queira voltar." << endl;
	cin.ignore();
	cout << endl << "Digite um nome: ";
	getline(cin,nome);
	cout << "Digite um email: ";
	cin >> email;
	cout << "Digite um celular: ";
	cin >> celular;
	cout << "Digite um nome para login: ";
	cin >> login;
	cout << "Digite uma senha para login: ";
	cin >> senha;
	cout << endl;
	if(nome=="0" || email=="0" || celular=="0" || login == "0" || senha == "0"){
		return;
	}

	for(list<string>::iterator q = loginsAdc.begin(); q!=loginsAdc.end(); q++){
		if(login == *q){
			loginRegistrado=true;
			break;
		}
	}

	if(celular.size()!=12){
		cout << "Celular com número de digitos inválido." << endl << endl;
		cond=false;
	}

	else if (login.size()<6 || login.size()>20 || loginRegistrado == true){
		cout << "Login invalido. Digite um nome para login entre 6 a 20 caracteres. " << endl;
		cond=false;
	}
	else if(senha.size()<6 || senha.size()>30){
		cout << "Senha inválida. Digite uma senha entre 6 a 30 caracteres." << endl;
		cond=false;
	}
	else{
		cond=true;
	}

	if(cond==false){
		loginsAdc.push_back(login);
		realizaCadastro();
	}
	else if (cond==true){
		adicionaClienteSistema(nome,email, celular,login,senha);
		cout << "Cadastro realizado com sucesso." << endl;
	}
}

void testePrintClientes(){ //Apenas para testar os clientes encadeados.
	int cont=0;
	for(list<Cliente>::iterator c1=Clientes.begin(); c1!=Clientes.end(); ++c1){
		cout << "************* PERFIL DO CLIENTE **************" << endl;
		cont++;
		cout << "Cliente " << cont << endl;
		cout << "Nome: " << c1->getNome() << endl;
		cout << "Email: " << c1->getEmail() << endl;
		cout << "Celular: " << c1->getCelular() << endl;
		cout << "Codigo: " << c1->getCod() << endl;
		cout << "Nome de login: " << c1->getLogin() << endl << endl;
		cout << "**********************************************" << endl << endl;
		c1->printRuasCliente();
	}
}


 /***************************************** MAIN ********************************************/
int main() {
	int opcao=1, opcao2=1; //opcao é para o menu inicial, opcao2 é logado
	string nome, bairro;
	bool logado=false;

	list <Cliente>::iterator clienteAtual;

	// ************ INCLUSÕES OBRIGATÓRIAS ANTES DO INÍCIO DOS TESTES ************ //

	//ADIÇÃO DE RUAS AO SISTEMA
	//(nome da rua, bairro)
	adicionaRuaSistema("Rua Blumenau", "Centro");
	adicionaRuaSistema("Rua Guaira", "Iririu");
	adicionaRuaSistema("Rua Iririú", "Iririú");
	adicionaRuaSistema("Rua Iririú", "Saguaçú");
	adicionaRuaSistema("Rua Pacajus", "Iririú");
	adicionaRuaSistema("Rua Paulo Machilstzski", "Zona industrial");
	adicionaRuaSistema("Rua Piratuba", "Saguaçú");
	adicionaRuaSistema("Rua São Paulo", "Centro");
	adicionaRuaSistema("Rua Tuiuti", "Iririú");
	adicionaRuaSistema("Rua Tuiuti", "Aventureiro");
	adicionaRuaSistema("Rua Xaxim", "Iririú");

	//ADIÇÃO DE CLIENTES AO SISTEMA
	//(nome, email, celular, login, senha)
	adicionaClienteSistema("Geremias Correa","gere.c@hotmail.com", "047996853547","gerecorrea","gerecorrea");
	adicionaClienteSistema("Paulinho","paulinho@hotmail.com", "047996853547","paulera","paulera");
	adicionaClienteSistema("Victor", "victorkarnopp@hotmail.com", "047999999999", "vitinho", "fazedordecerca");
	adicionaClienteSistema ("Gustavo Bonassa", "gustavo.bonassa@hotmail.com", "047999169194", "gustavinho", "gugu123");
	

	// ************************************************************* //
	// *********************** TESTES ****************************** //


	//TESTE 0
	cout << endl << "0) NESTE TESTE PRINTAREMOS TODAS AS RUAS ADICIONADAS DO SISTEMAS " << endl;
	printaRuaSistema();
	cout << "************************************************" << endl << endl;	

	//TESTE 1
	cout << "1) AQUI PRINTAMOS OS QUATRO CLIENTES NO SISTEMA ANTES DA ADIÇÃO DE QUALQUER COISA EM SUAS CONTAS. DADO PRIMEIRAMENTE POR SEU PERFIL E EM SEGUIDA AS RUAS ADICIONADAS DO MESMO, EM OUTRA TELA." << endl << endl;
	testePrintClientes(); 

	//TESTE 2
	cout << "2) AGORA ADICIONAMOS NO CLIENTE GEREMIAS CORREA ALGUMAS RUAS, QUE IREMOS VERIFICAR POSTERIORMENTE SE FORAM ADICIONADAS COM O PRINTCLIENTE()." << endl << endl;
	clienteAtual = Clientes.begin();
	clienteAtual->adicionarRua(4);
	clienteAtual->adicionarRua(1);
	clienteAtual->adicionarRua(2);
	clienteAtual->adicionarRua(9);
	cout << "********************************************" << endl << endl;
	cout << "2.1) AGORA PRINTANDO O CLIENTE PARA VERIFICAR SEU ESTADO ATUAL " << endl;
	clienteAtual->printCliente();
	cout << endl << "******************************************" << endl << endl;
	
	//TESTE 3
	cout << "3) AGORA PRINTANDO TODOS OS CLIENTES NOVAMENTE, INCLUSIVE SUAS RUAS, PARA VERIFICAR OS MESMOS APÓS TAIS ADICÕES. APENAS O CLIENTE GEREMIAS CORREA SOFRERÁ ALTERAÇÕES REFERENTE AO TESTE 1." << endl << endl;
	testePrintClientes();

	//TESTE 4
	cout << "4) AGORA FAZENDO MODIFICAÇÕES EM ALGUMAS RUAS, PARA VERIFICAR SE SERÁ CORRETAMENTE ENVIADO A CAIXA DE MENSAGENS DOS CLIENTES QUE POSSUEM AS MESMAS ADICIONADAS. NOVAMENTE, COMO SOMENTE O CLIENTE GEREMIAS POSSUIU RUAS ADICIONADAS, ENTÃO O MESMO DEVE TER INCREMENTO NA CAIXA DE MENSAGENS." << endl;
	
	modificaRua("Rua Blumenau","Centro", true, true, false, "Acidente na rua Blumenau. 13h56.");
	modificaRua("Rua Tuiuti","Iririú", true, true, true, "Acidente na rua Tuiuti, Iririú. 17h52.");
	cout << "**************************************************" << endl << endl;

	for(list<Cliente>::iterator q=Clientes.begin(); q!=Clientes.end(); ++q){
		cout << "Cliente atual: " << q->getNome() << endl;
		q->printMenuCliente();
		cout << "*************************************************" << endl << endl;
	}

	//TESTE 5
	cout << "5) NESTE TESTE LEREMOS A CAIXA DE MENSAGENS DO CLIENTE GEREMIAS, CUJO POSSUI AINDA 2 MENSAGENS NÃO LIDAS. APÓS A LEITURA DA MESMA AS MENSAGENS SÃO EXCLUÍDAS, ENTÃO ABRIREMOS ELA DUAS VEZES PARA CONFERÊNCIA." << endl << endl;

	clienteAtual = Clientes.begin();
	cout << "Cliente atual: " << clienteAtual->getNome() << endl;
	clienteAtual->verCaixa();
	clienteAtual->verCaixa();
	cout << endl << "************************************************" << endl << endl;

	cout << endl <<"FIM DOS TESTES UNITÁRIOS" << endl;
}
