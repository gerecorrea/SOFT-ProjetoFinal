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
list <int> codigosAdc; //Para não repetir os códigos, caso seja feito
void printRuaSistema();

	
/* ANotações de domingo 9/6 19h30:
ENtão, o código está legal, maioria das coisas está funcionando bem. Em geral é bom organizar bem o código, deixá-lo mais limpo e se puder adaptar para n clientes, e não só um como estou fazendo.

ALém disso, acredito não ser válido implementar os veículos pois não são mais influentes no meu código.

Também verificar as funções de teste que tão no main, se deixarei mesmo lá como uma função de adm ou retirar e ver outro jeito de testar isso, fazendo direto no main antes dos laços de interação.

*/

//COMO USAR LISTA DE CLASSES E ITERADOR PARA PRINT, MTO BOM: https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/

//AGORA PARA ORDENARAR COM BASE NO NOME, MEMSO SITE: https://thispointer.com/c-how-to-sort-a-list-of-objects-with-custom-comparator-or-lambda-function/


//AQUI PRINCIPALMENTE PARA TESTES E BACKUP, CASO O MVC NÃO DE CERTO. VALE EM TORNO DE 20% COM MVC. REPARAR NOS NOMES MODIFICADOS DE CLASSE E AFINS.

/*link ppr: https://drive.google.com/drive/folders/1dMZe-vHx6haVFBnMoQcXBs3RLGmDbGWV 
*/

/* Baseado nos protótipos o que foi feito e como está:
- Classe cliente:
	Método construtor: tá ok;
	
	Getters e setters: tá ok;
	
	Login cliente: tá ok, mas aqui já passo direto de uma classe, talvez fosse mais lógico procurar qual classe bata com os dados, instanciando várias (caso dê).
	
	Lista para adc ruas as escolhidas do cliente e printá-las: tá ok
	
	Adc veículos a lista e printá-los: não implementado (não sei se terá)
	
	Verificar lista de ruas do cliente e estados atuais: tá ok
	
	Printar caixa de mensagens: tá ok
	 
- Classe rua
	Método construtor: tá ok já, Acho
	
	Lista para Adc ruas ao sistema: tá ok
	
	Modifica situação de rua: tá ok
	
	Setters e getters: tá ok todos 

- Geral:
	Realiza Cadastro: tá totalemnte ok.
	
	Menu por while, na qual o primeiro laço é do menu inicial, o menu logado do cliente. Em geral tá ok
	
	Modificar estado de uma rua e tal mudança implicar em uma mensagem na caixa de emnsagens do cliente: tá ok

*/

/* CLASSE RUA */
//Eu instanciar uma rua, é adicionar ela ao sistema
class Rua{
	//CTRL F
	string nome;
	string bairro;
	bool congestionamento; 
	bool acidente;
	bool total;

	public:
		Rua (string nome, string bairro); //bele
		void modificaSituacao(bool acidente, bool total, bool congestionamento); //bele
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
//FUNÇÕÕES CLASSE RUA
Rua::Rua(string nome, string bairro){ //construtor
	this->nome = nome;
	this->bairro = bairro;
	congestionamento = false;
	acidente=false;
	total=false;//se false é parcial ou não influente, dependendo do congestionamento

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

void Rua::adicionarRuaSistema(string nome, string bairro){
	//RuasDoSistema.push_back()
}


/* ----------------------- FIM CLASSE RUA ----------*/
list <Rua> RuaSist; //Declarando a lista de rua após a criação da mesma.

//essa função aqui para no cliente eu conseguir ler ela
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
	//CTRL F
	string nome;
	int cod;
	string email;
	string celular;
	string login;
	string senha;
	list <string> mensagens;// Para caixa de mensagens
	//int codigosAloc[100000];

	public:
		list <Rua> ruasCliente; //ruas adc do cliente


		//model function
		Cliente (string nome, int cod, string email, string celular, string login, string senha); //bele
		Cliente (); //bele
		//void realizaCadastro (); //bele
		
		string getNome (); //bele
		int getCod(); //bele
		string getEmail(); //bele
		string getCelular(); //bele
		string getLogin(); //bele
		string getSenha(); //bele
		void setNome(string nome); //bele
		void setCod(int cod); //bele
		void setEmail(string email);//bele
		void setCelular(string celular);//bele
		void setSenha(string senha); //bele
		void setLogin(string login); //bele
		
		bool loginCliente (); //ver se nãão seria do main, caso fosse para comparar com os existentes
		
		void adicionarVeiculo(); //?
		void verificarRuas();//verifica ruas aptas a receber informações para o cliente e seus estados atuais
		void verCaixaMensagens(); //bele
		void verVeiculosAdc(); 
		
		void printCliente();//teste, depois modificar
		void printMenuCliente(); //bele
		void adcMsg(string msg); //adiciona mensagem a caixa//bele
		void verCaixa(); //para ver caixa de msg //bele
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
	
	//mensagens = new list<string>; //para caixa de mensagens
	//ou mensagens = new list<string> [500];
}

Cliente:: Cliente(){ //Preciso instanciar os valores, se nãão dáá pau
	//DPS DEIXAR TUDO COMO NULL, MUDEI SÓ PARA FICAR MAIS RÁPIDO DE FAZER OS TESTES
	nome="Geremias Correa";
	cod=0;
	email="gere.c@hotmail.com";
	celular="047996758535";
	login="gerecorrea";
	senha="gerecorrea";
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
void Cliente::setEmail(string email){//atualiza email
	this->email=email;
}
void Cliente::setCelular(string celular){ //atualiza telefone
	this->celular=celular;
}

void Cliente::setLogin(string login){
	this->login=login;
}

void Cliente::setSenha(string senha){
	this->senha=senha;
}



bool Cliente::loginCliente(){
	string loginaux,senhaaux;
	bool loginVal=false;
	cout << "Digite o login: ";
	cin >> loginaux;
	cout << "Digite a senha: ";
	cin >> senhaaux;
	cout << endl <<"******************************************" << endl << endl;
	if(loginaux.compare(getLogin())==0 && loginaux!="NULL"){
		if(senhaaux.compare(getSenha())==0 && senhaaux != "NULL"){
			cout << "Login realizado com sucesso." << endl;
			return true;
		}
		cout << "Senha incorreta." << endl;
	}
	else
		cout << "Login incorreto." << endl;
	return false;

}

void Cliente::printCliente(){//sóó p testar se funfa a adc
	cout << "Nome: " << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Celular: " << celular << endl;
	cout << "Codigo: " << cod << endl;
	cout << "Nome de login: " << login << endl;
}

void Cliente::printMenuCliente(){
	cout << "Usuario: " << nome << "\t\tCaixa de mensagens: " << mensagens.size() << endl << endl;
	cout << "[1] Adicionar ruas ao cliente." << endl;
	cout << "[2] Adicionar veículos ao escolhidos." << endl;//acho que não implementarei
	cout << "[3] Ver suas ruas. " << endl;
	cout << "[4] Ver seus veículos adicionados." << endl;//acho que não implementarei
	cout << "[6] Adc mensagem. //Teste" << endl;
	cout << "[5] Ver caixa de mensagens." << endl;
	cout << "[0] Sair da conta." << endl << endl; 
}

void Cliente::adcMsg(string msg){
	mensagens.push_front(msg);
}

void Cliente::verCaixa(){
	cout << endl << "Caixa de mensagens: " << endl << endl;
	while(mensagens.size()!=0){
		cout << mensagens.front() << endl << endl;//incluir hora na msg
		mensagens.pop_front();
	}
	//As mensagens sim são excluídas da caixa após serem lidas.	
}

void Cliente::adicionarRua(){
	int opcao10=0, contador=0;
	printaRuasParaAdc();
	cout << endl << "Digite a opção escolhida para ser adicionada: ";
	cin >> opcao10;
	if(opcao10==0)
		return;
	for(list<Rua>::iterator q=RuaSist.begin(); q!=RuaSist.end(); ++q){
		contador++;
		if(contador==opcao10){
			ruasCliente.push_back(*q);
			cout << endl << "Rua adicionada com sucesso." << endl << endl;
			cout << "****************************************" << endl << endl;
		}
	}
	if(opcao10 != 0)//volta para adicionar mais
		adicionarRua();
}

void Cliente::printRuasCliente(){
	cout << endl;
	for(list<Rua>::iterator q=ruasCliente.begin(); q!=ruasCliente.end(); ++q){
		cout << "- " << q->getNome() << ", " << q->getBairro() << "." << endl;
		cout  << "Congestionamento: " << q->getCongestionamento() << endl;
		cout  << "Acidente: " << q->getAcidente() << endl;
		cout  << "Bloqueamento total: " << q->getTotal() << endl << endl;
	}
}
/* --------------- FIM CLIENTE ---------------*/

list <Cliente> Clientes;
Cliente *cliente = new Cliente (); //com ponteiro


//CTRL F
//FUNÇÕES FORA DAS CLASSES E MAIN PARA IMPLEMENTAÇÃO

void adicionaRuaSistema (string nome, string bairro /*Rua rua[], int pos*/){ 
	Rua *r1 = new Rua(nome, bairro);    
	RuaSist.push_back(*r1);
	
	//teste aqui
	//Rua *rua[pos] = new Rua();
	//RuaSist.push_back(rua[pos]);
	
	//Para ordenar as ruas depois basta dar um sort?
	cout << "Rua adicionada com sucesso." << endl;
}


void printaRuaSistema(){
	//1 = true, 0 = false;
	cout << "Lista de ruas: " << endl << endl;
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
			cout << "Rua modificada com sucesso." << endl;
			modificou=true;
			for(list<Rua>::iterator p=cliente->ruasCliente.begin(); p!=cliente->ruasCliente.end(); ++p){
				if(p->getNome() == q->getNome() && p->getBairro()==q->getBairro()){
					cliente->ruasCliente.erase(p);//apaga elemento da lista
					cliente->ruasCliente.push_back(*q); //Insiro novamente modificado
					cliente->adcMsg(msg);
				}
			}
			
			//for com iterador sobre as ruas do cliente
		}
	}
	if(modificou==false)
		cout << "Rua não foi encontrada no sistema." << endl;
}


//FUNÇÕES ABAIXO FORA DAS CLASSES E MAIN JÁ FORAM IMPLEMENTADAS E ESTÃO OK
void realizaCadastro (Cliente *c1){
	int valor;
	bool cond=false;
	string nome, email, celular, login, senha;
	int cod;

	valor = rand()%1000000+1;
	codigosAdc.push_back(valor);
	cod = valor;
	//verificar pela lista de cóódigo para nãão permitir repetir os cóódigos (pois assim há uma pequena possibilidade)
	cout << "Código de registro: " << cod << endl;
	cout << "Digite um nome: ";
	cin >> nome;
	cout << "Digite um email: ";
	cin >> email;
	cout << "Digite um celular: ";
	cin >> celular;
	cout << "Digite um nome para login: ";
	cin >> login;
	cout << "Digite uma senha para login: ";
	cin >> senha;
	//fazer condicionais para ver como o email foi digitado, login já existe, etc?
	if(celular.size()!=12){ //047 - 9 xxxx xxxx
		cout << "Celular com número de digitos inválido." << endl;
		cond=false;
	}
	else if (login.size()<6 || login.size()>20){//ver se já existe tal login?
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
	if(cond==false)
		realizaCadastro(c1);
	else if (cond==true){
		c1->setNome(nome);
		c1->setEmail(email);
		c1->setCelular(celular);
		c1->setCod(cod);
		c1->setLogin(login);
		c1->setSenha(senha);
		cout << "Cadastro realizado com sucesso." << endl;
	}

}


 /***************************************** MAIN ********************************************/
int main() {
	//CTRL F
	//int vetorClientes[MAX];
	list <Rua> RuasDoSistema; //cada instanciaçãão de classe coloco aqui
	list <pair<string,string>> Ruas2;//ver melhor
	int opcao=1, opcao2=1; //opcao é para o menu inicial, opcao2 é logado
	string nome, bairro;
	int r[100], contRua=0;
	bool logado=false;
	//CLIENTE: Acredito que Cliente sóó instancio um, que éé o qu estou trabalhando, como se fosse ele. Acho que instanciar váários pra mudar uma rua e retornar que clientes receberam a mensagem pode ser desnecessáário, mas seria entãão um caso para instanciar vários
	int qtdClientesAtual=0;
	Cliente vetorCliente[MAX];
	//Cliente c2 ("Joao", 899964, "Joaozinho@gmail.com", "47996478452"); //instanciando alguem


	//RUA: a ideia é a função fazer todo, aqui só enviamos os dados necessários, tais quais o nome e bairro, assim como um vetor de ruas dada pela respectiva posição que é incrementada a cada rua adicionada.
	//outra forma: list<Rua> listofRuas = { Rua("22", "Sid"), Rua("3", "Laura"), Rua("43", "Riti"), Rua("30","Angel"), Rua("2", "Laura")};
	
	list <Rua> RuaSistTeste;
	adicionaRuaSistema("Rua Blumenau", "Centro");
	adicionaRuaSistema("Rua Guaira", "Iririu");
	adicionaRuaSistema("Rua Iririú", "Iririú");
	adicionaRuaSistema("Rua Iririú", "Saguaçú");
	adicionaRuaSistema("Rua Pacajus", "Iririú");
	adicionaRuaSistema("Rua Paulo Machilski", "Bom Retiro");
	adicionaRuaSistema("Rua Piratuba", "Saguaçú");
	adicionaRuaSistema("Rua São Paulo", "Centro");
	adicionaRuaSistema("Rua Tuiuti", "Iririú");
	adicionaRuaSistema("Rua Tuiuti", "Aventureiro");
	adicionaRuaSistema("Rua Xaxim", "Iririú");
	
	//void modificaRua(string nomerua, string bairrorua, bool congest, bool acidente, bool total)
	modificaRua("Rua Blumenau","Centro", true, true, false, "Acidente na rua Blumenau. 13h56.");
	modificaRua("Rua Tuiuti","Iririú", true, true, true, "Acidente na rua Tuiuti, Iririú. 17h52.");
	//modificaRua(" ", " ", true, true, true);

	while(opcao!=0){
		//Dps fazer função printMenu para economizar o main.
		cout << "******************************************" << endl;
		cout << " ****** BEM-VINDO AO SISTEMA SIRU ******* //testes" << endl << endl;
		cout << "[1] Login. " << endl;
		cout << "[2] Realizar cadastro." << endl;
		cout << "[3] Adicionar rua ao sistema.//para teste" << endl; //para teste, não fica no final
		cout << "[4] Printa cliente.//só pra teste " << endl;//para teste
		cout << "[5] Printa ruas do sistema." << endl;
		cout << "[6] Modifica situação de rua.//teste" << endl;
		cout << "[0] Sair." << endl << endl;
		cout << "Opção: ";
		cin >> opcao;
		cout << endl << "******************************************" << endl << endl;
		if(opcao == 3){ //nãão testada
			cout << "Digite o nome da rua: " << endl;
			cin >> nome;
			cout << "Digite o bairro da rua " << endl;
			cin >> bairro;
			adicionaRuaSistema(nome, bairro);
			}
		else if (opcao == 1){ //testada
			if(cliente->loginCliente()==true){
				logado=true;
			}
		}
		else if(opcao == 2){  //testada
			//Cliente vetorCliente[0]("Joao", 899964, "Joaozinho@gmail.com", "47996478452");
			realizaCadastro(cliente);
		}
		else if (opcao==4){ //éé para teste
			cliente->printCliente();
		}
		else if (opcao==5){
			printaRuaSistema();
		}
		else if (opcao==6){
			cout << endl << "*******MOD RUA *************" << endl << endl;
			
			//cout << "Digite o nome da rua: ";
			//cin >> nome;
		//	cout << "Digite o nome do bairro: ";
			//cin >> bairro;
			modificaRua("Rua Blumenau", "Centro", true, true , true, "Acidente na rua Blumenau, Centro. 16h54.");
			modificaRua ("Rua Blumenau", "Centro", false, false, false, "Situação estabilizada na rua BLumenau, Centro. 18h32.");
		}
		//...
		cout << endl << "******************************************" << endl << endl;
		if(logado==true){
			opcao2=1;
			while(opcao2!=0){
				cliente->printMenuCliente();
				cout << "Opcao: ";
				cin >> opcao2;
				cout << endl << "******************************************" << endl;
				if(opcao2==1){
					//adicionar ruas ààs marcadas
					cliente->adicionarRua();
				}
				else if(opcao2==3){
					//ver as ruas que está apto a receber notif
					cliente->printRuasCliente();
				}
				else if (opcao2==5){
					//ver caixa de mensagens
					cliente->verCaixa();
				}
				else if (opcao2==6){
					cliente->adcMsg("Acidente na rua Osvaldo Brandão, Parque Guarani. Hora: 18h56.");
					cliente->adcMsg("Acidente na rua Blumenau, Centro. Hora: 19h52.");
				}
				//if 2-adicionar veíículos aos escolhidos
				//if 4-ver seus veiculos adc
				//0-deslogar.
				else if(opcao2==0)
					logado=false;
				cout << endl << "******************************************" << endl;

			}
		}
	}
}
/* Exemplo com dois parametros em list:
link: https://stackoverflow.com/questions/14618065/how-can-you-pass-a-vectorpairint-int-into-a-function 
void someFunc(int x, int y, vector<pair<int, int> > hello);

int main()
{
    int x = 0;
    int y = 5;

    vector<pair<int, int> > helloWorld;
    helloWorld.push_back(make_pair(1,2));

    someFunc(x,y,helloWorld);
}

void someFunc(int x, int y, vector<pair<int, int> > hello)
{
    cout << "I made it." << endl;
}*/