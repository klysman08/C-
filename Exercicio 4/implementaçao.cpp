/**Nome: Klysman Rezende Alves Vieira
   Matricula: 2017108779
   Exercicio 4 - UML e codigo  **/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;


// Classe Editora
// Valores padroes. Trata-se de uma unica editora

class Editora
{
    string nome_ed;
    string endereco_ed;
    int quantPublicacoes_ed;
    int cnpj_ed; /**De acordo com o slide precisa ter*/

public:
    Editora()
    {
        this->nome_ed = "DCC";
        this->endereco_ed = "UFMG";
        this->quantPublicacoes_ed = 5;
        this->cnpj_ed = 123456789; /**Aqui tambem*/
    }

    string getnome()
    {
        return nome_ed;
    }

    string getendereco()
    {
        return endereco_ed;
    }

    int getquantPublicacoes()
    {
        return quantPublicacoes_ed;
    }

    /**Ja que tem um campo para o cnpj, deve ser util ter um metodo para ler o cnpj. Nao fiz um para definir o cnpj pq imagino q isso vai ser
       padroo e determinado no inicio do programa*/
    int getcnpj()
    {
        return cnpj_ed;
    }
};



// Classe que armazena as publicaçoes desejadas pelo Usuario.
// Tem como construtores publicaçoes padrao e outra que recebe os parametros (informacoes da publicacao) do usuario.

class Publicacoes
{
    string nome_pub;
    int edicao_atual;
    string periodicidade; //se é mensal ou semanal
    int data_ultima_ed; //Isso tem que ser data, mas nao consigo compilar com data

public:

    Publicacoes()
    {
        this->nome_pub = "Tecnologia";
        this->edicao_atual = 1;
        this->periodicidade = "Periodicidade Semanal";
        this->data_ultima_ed = 0606201;
    }

    Publicacoes(string nome, int edicao, string periodicidade, int data_ultima_ed)
    {
        this->nome_pub = nome;
        this->edicao_atual = edicao;
        this->periodicidade = periodicidade;
        this->data_ultima_ed = data_ultima_ed;

    }

    void atualizar_campos(string nome, int ed, string periodicidade,int data_ed)
    {
        this->nome_pub = nome;
        this->edicao_atual = ed;
        this->periodicidade = periodicidade;
        this->data_ultima_ed = data_ed;
    }

    void listar_campos() // essa funcao nao esta sendo chamada. nao consigo identificar o problema dessa sintaxe
    {
        cout<< "\nNome da publicacao: " << this->nome_pub << "\nEdicao atual: " << this->edicao_atual << "\nPeriodicidade: " << this->periodicidade << "\nData da ultima edicao: " << this->data_ultima_ed << "\n";
    }

    //Funcoes alternativas

    string getnome_pub()
    {
        return nome_pub;
    }

    int getedicao_atual()
    {
        return edicao_atual;
    }

    string getperiodicidade()
    {
        return periodicidade;
    }

    int getdata_ultima_edicao()
    {
        return data_ultima_ed;
    }

};


/*class Publicacoes : public Editora
{
    string pub1 = "Tecnologia";
    string pub2 = "Ciencias";
    string pub3 = "Biologia";
    string pub4 = "Natureza";
    string pub5 = "Bioengenharia";

public:

    string getpub1()
    {
        return pub1;
    }

    string getpub2()
    {
        return pub2;
    }

    string getpub3()
    {
        return pub3;
    }

    string getpub4()
    {
        return pub4;
    }

    string getpub5()
    {
        return pub5;
    }
};
*/

// Classe Cliente
// Recebe as informacoes do usuario na funcao atualiza_cliente

class Cliente
{

public:
	string nome;
	int idade;
	string endereco;
	int cpf; /**De acordo com o slide precisa ter*/

    Cliente ()
    {
        this->nome = "Klysman";
        this->idade = 22;
        this->endereco = "UFMG";
        this->cpf = 1232233234;
    }

    Cliente (string nome, int idade, string endereco, int cpf)
    {
        this->nome = nome;
        this->idade = idade;
        this->endereco = endereco;
        this->cpf = cpf;
    }

    /*void atualiza_cliente(string nome, int idade, string endereco, int cpf)
    {
        this->nome = nome;
        this->idade = idade;
        this->endereco = endereco;
        this->cpf = cpf;
    }*/

    string getnome()
    {
        return nome;
    }

    int getidade()
    {
        return idade;
    }

    string getendereco()
    {
        return endereco;
    }

    /**Ja que tem um campo cpf, é interessante ter um metodo pra pegar o cpf*/
    int getcpf()
    {
        return cpf;
    }
};

// Classe Assinatura
// Recebe as informacoes do usuario na funcao atualiza_assiantura e set nos atributos

class Assinatura : public Cliente, public Publicacoes
{
    string revista;
    int ed_inicial;
    int num_assinaturas;
    string assinante;

public:

    Assinatura ()
    {
        this->ed_inicial = 1;
        this->num_assinaturas = 1;
    }

    void atualiza_assinatura(string revista, int ed_inicial, int num_assinaturas, string assinante)
    {
        this->revista = revista;
        this->ed_inicial = ed_inicial;
        this->num_assinaturas = num_assinaturas;
        this->assinante = assinante;
    }

    void consulta()
    {
        cout<< "\nNome da assinatura: " << this->revista << "\nEdicao atual: " << this->ed_inicial << "\nAssinaturas: " << this->num_assinaturas << "\nAssinante: " << this->assinante << "\n";

    }

    void eliminaAssinatura()
    {

    }


};

// Classe sistema
// Responsavel por receber todas as informacoes do usario e criar os objetos das classes publicacoes, clientes e assinaturas.

/**Aqui precisa ter uma classe Sistema de acordo com o slide (slide 21 da aula - Diagrama de classes).
   Ela nao possui atributos nem construtores, somente metodos. */

class Sistema : public Editora, public Assinatura
{

public:


    void inscreverPublicacao()
    {
        string nome_pub;
        int edicao_atual;
        string periodicidade; //se e mensal ou semanal
        int data_ultima_ed; //Isso tem que ser data, mas nao consigo compilar com data


        cout << "Informe os dados da publicacao \n";
        cout << "Nome da publicacao: ";
        cin >> nome_pub;
        cout << "Edicao: ";
        cin >> edicao_atual;
        cout << "Periodicidade (semanal ou mensal): ";
        cin >> periodicidade;
        cout << "Data da ultima edicao (tudo junto, sem barra, por exemplo 09062019: ";
        cin >> data_ultima_ed;

        atualizar_campos(nome_pub, edicao_atual, periodicidade, data_ultima_ed);  //funcao que atualiza novos valores na classe correspondente

        cout << "\nOk! Seus dados foram armazenados. \n\n";
    }

    Cliente inscreverCliente()
    {
        string nome;
        int idade;
        string endereco;
        int cpf;

        cout << "Informe os dados para cadastro no sistema \n";
        cout << "Seu nome: ";
        cin >> nome;
        cout << "Sua idade: ";
        cin >> idade;
        cout << "Seu endereco: ";
        cin >> endereco;
        cout << "Seu cpf: ";
        cin >> cpf;

        Cliente *c1 = new Cliente(nome, idade, endereco, cpf);
		//client.push_back(*c1);
		//atualiza_cliente(nome, idade, endereco, cpf); //funcao que atualiza novos valores na classe correspondente
		
        cout << "\nOk! Seus dados foram armazenados. \n\n";
    	return *c1;
	}

    void inscreverAssinatura()
    {
        string revista;
        int ed_inicial;
        string assinante;
        int num_assinaturas;

        cout << "Informe os dados para cadastro no sistema \n";
        cout << "Nome da Assinatura: ";
        cin >> revista;
        cout << "Numero da edicao: ";
        cin >> ed_inicial;
        cout << "Assinante: ";
        cin >> assinante;
        cout << "Numero de assinaturas: ";
        cin >> num_assinaturas;

        atualiza_assinatura(revista, ed_inicial, num_assinaturas, assinante); //funcao que atualiza novos valores na classe correspondente
    }
};

void imprime(const vector<Cliente> &lista)  //TENTAR DEUXAR DENTRO DE CADA CLASSE ESPECIFICA PARA QUE OS ATRIBUTOS NAO PRECISEM SER PUBLICOS
{
    for (int i = 0; i < lista.size(); ++i)
    {
        cout << lista[i].nome << endl;
        cout << lista[i].idade << endl;
        cout << lista[i].endereco << endl;
        cout << lista[i].cpf << endl;
    }
}

// Programa principal para o usuario interagir
// Chama as devidas funcoes para setar os valores informados pelo usario.


int main(int argc, char** argv)
{
    int escolha = 0;
    Sistema *s1 = new Sistema();
    Cliente *c1 = new Cliente();
    Publicacoes *p1 = new Publicacoes();
    Assinatura *a1 = new Assinatura();
    
    
    vector<Cliente> client;
    vector<Publicacoes> publica;
    vector<Assinatura> assina;
    
    

    while(1)
	{
        cout << "Informe o que voce deseja. \n\n1 - Cadastrar cliente\n2 - Cadastrar publicacao\n3 - Cadastrar assinatura\n4 - Informacoes de cliente cadastrado\n5 - Sair do Programa\n\n";
        cout << "Escolha: ";
        cin >> escolha;

        if (escolha == 1)
        {
            *c1 = s1->inscreverCliente();
            client.push_back(*c1);
        }
        else if (escolha == 2)
        {
            s1->inscreverPublicacao();
        }
        else if (escolha == 3)
        {
            s1->inscreverAssinatura();
        }
        else if (escolha == 4)
        {
           /*cout<< c1->getnome() << "\n";
           cout<< c1->getcpf() << "\n";
           cout<< c1->getidade() << "\n";
           cout<< c1->getendereco() << "\n";
           cout<< p1->getnome_pub() << "\n";
           cout<< p1->getedicao_atual() << "\n";
           cout<< p1->getperiodicidade() << "\n";
           cout<< p1->getdata_ultima_edicao() << "\n";
			*/
			imprime(client);
        }
        else if (escolha == 5)
        {
            cout << "Saindo do programa. Obrigado por utilizar o sistema. ";
            break;
        }
        else
        {
            cout << "Escolha invalida. Tente novamente. \n\n";
        }
	}
	return 0;
}
