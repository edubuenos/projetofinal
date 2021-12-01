#include <iostream>
#include <fstream>
#include "funcoes.h"

using namespace std;
// CADASTRA ALUNO
void cadastroaluno() {
	Aluno cadastroaluno;
	std::cout << "Cadastrar Aluno\n";
	std::cout << "Informe o nome do aluno:\n";
	std::cin  >>  cadastroaluno.nome;
	std::cout << "Informe a matricula do aluno:\n";
	std::cin  >>  cadastroaluno.matricula;
// ARQUIVOS 
	 cadastroaluno.aep1 = 0;
	 cadastroaluno.prova1 = 0;
	 cadastroaluno.aep2 = 0;
	 cadastroaluno.prova2 = 0;
	 cadastroaluno.media = 0;
	 cadastroaluno.sub = 0; 
	 // APROVADO OU REPROVADO
	 cadastroaluno.status = "reprovado";
	
	if (cadastraAluno ( cadastroaluno)) {
		std::cout << "Aluno teste cadastrado\n";
	} else {
		std::cout << "Erro ao cadastrar aluno teste\n";
	}
	
}

void limpaTela() {
    system("cls");
}


void relatorio() {
	std::cout << "Esta fazendo a funcao 2\n";
}

void lerALuno(Aluno aluno) {
    cout <<" Nome: " << aluno.nome << endl
        << " Matricula: " << aluno.matricula << endl
        << " AEP1: " << aluno.aep1 << endl
        << " Prova1: " << aluno.prova1 << endl
        << " AEP2: " << aluno.aep2 << endl
        << " PROVA2: " << aluno.prova2 << endl
        << " SUB1: " << aluno.sub<< endl
        << " Media: " << aluno.media<< endl
        << " Status: " << aluno.status << endl<< endl;
}

// CADASTRO DA NOTA
void cadastronota() {
	limpaTela();
	std::string altmatricula;
	cout << "Digite uma matricula: ";
	cin >> altmatricula;
	//variaveis
	int rodar_arquivo = 0;
	int b = 0;
	std::string str;
	std::fstream arquivo;
	int w =0;
	arquivo.open("banco.csv", std::ios::in);
	// contar numero de linhas do arquivo
	if (!arquivo.is_open()) {
		cout << "Houve um erro ao abrir o arquivo!\n";
	}
	else{
		while (arquivo.good()) {
			rodar_arquivo = arquivo.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
	}
	std::string line;
	std::string linha[b];
	int tamanho = 0;
	arquivo.close();
	std::vector<struct Aluno> alunos(b);

	arquivo.open(".csv", std::ios::in);
	do{
		arquivo >> linha[tamanho];
		tamanho++;
	}while(getline(arquivo, line));
	arquivo.close();

	for(int i = 0; i < b; i++){
		w = 0;
		std::stringstream X(linha[i]);
		while (getline(X, str, ';')){
			if(w == 0){
				alunos[i].nome = str;
			} else if(w == 1){
				alunos[i].matricula = str;
			} else if(w == 2){
				alunos[i].aep1 = std::stof(str);
			} else if(w == 3){
				alunos[i].prova1 = std::stof(str);
			} else if(w == 4){
				alunos[i].aep2 = std::stof(str);
			} else if(w == 5){
				alunos[i].prova2 = std::stof(str);
			} else if(w == 6){
				alunos[i].sub = std::stof(str);
			} else if(w == 7){
				alunos[i].media = std::stof(str);
			} else if(w == 8){
				alunos[i].status = str;
			}
			w++;
		}
	}

	for(int i = 0; i < b; i++){
		if(alunos[i].matricula == altmatricula){

			
            int opcao_notas = 0;
            bool repetir = true;
            while (repetir){
            lerALuno(alunos[i]);
			cout << "Escolha uma das opcoes a seguir: " << endl
		          << "Digite 1 alterar a nota da AEP1" << endl
		          << "Digite 2 alterar a nota da prova1" << endl
		          << "Digite 3 alterar a nota da AEP2" << endl
		          << "Digite 4 alterar a nota da prova2" << endl
		          << "Digite 5 alterar a nota da substitutiva" << endl
				  << "Digite 6 para voltar" << endl;
		          cin >> opcao_notas;
                if(opcao_notas > 0 && opcao_notas < 7) {
                    repetir = false;
                } else {
                    limpaTela();
                    cout << "Opcao Invalida" << endl;
                }
            }
	    	switch(opcao_notas){
	    		case 1:
	    			limpaTela();
	    			cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << endl;
					cout << "Digite a nota da AEP1: ";
					cin >> alunos[i].aep1;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 2:
	    			limpaTela();
	    			cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << endl;
					cout << "Digite a nota da Prova1: ";
					//std::getline(cin,alunos[i].prova1)
					cin >> alunos[i].prova1;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 3:
	    			limpaTela();
	    			cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << endl;
					cout << "Digite a nota da AEP2: ";
					cin >> alunos[i].aep2;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 4:
	    			limpaTela();
	    			cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << endl;
					cout << "Digite a nota da Prova2: ";
					cin >> alunos[i].prova2;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 5:
	    			limpaTela();
	    			cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << endl;
					cout << "Digite a nota da Prova2: ";
					cin >> alunos[i].sub;
					//verificar media
					//se a sub for diferente de 0
					if(alunos[i].sub != 0){
						//se o primeiro bimestre for maior q o segundo
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 6:
	    		    limpaTela();
                break;
			}
		}
	}
	std::ofstream arquivo_new;
	arquivo_new.open("bancoNovo.csv");

	// contar numero de linhas do arquivo
	if (!arquivo_new.is_open()) {
		cout << "Houve um erro ao abrir o arquivo!\n";
	}
	else{
		for(int i = 0; i < b; i++){
			if(alunos[i].media >= 6){
                alunos[i].status = "aprovado";
                arquivo_new << alunos[i].nome << ";"
                        << alunos[i].matricula << ";"
                        << alunos[i].aep1 << ";"
                        << alunos[i].prova1 << ";"
                        << alunos[i].aep2 << ";"
                        << alunos[i].prova2 << ";"
                        << alunos[i].sub << ";"
                        << alunos[i].media << ";"
                        << alunos[i].status << "\n";
			 }else {
                alunos[i].status = "reprovado";
                arquivo_new << alunos[i].nome << ";"
                        << alunos[i].matricula << ";"
                        << alunos[i].aep1 << ";"
                        << alunos[i].prova1 << ";"
                        << alunos[i].aep2 << ";"
                        << alunos[i].prova2 << ";"
                        << alunos[i].sub << ";"
                        << alunos[i].media << ";"
                        << alunos[i].status << "\n";
			}
		}
	}
	arquivo_new.close();
    remove("banco.csv");
	rename("bancoNovo.csv", "banco.csv");
}

void finaliza() {
	std::cout << "Esta finalizando o programa\n";
}

/*void media() {
	Aluno cadastroaluno;
	cadastroaluno.media = cadastroaluno.aep1 + cadastroaluno.prova1;
} */
// CRIA ARQUIVO
bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("banco.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}
	bool realizaLeituraArquivo () {
		
	std::ifstream arquivo;
	arquivo.open("banco.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		int conteudonum = 0;
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			} else if (coluna == 3 && controleColuna == 2) {
				alunos[indexAluno].aep1 = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 3;
			} else if (coluna == 4 && controleColuna == 3) {
				alunos[indexAluno].prova1 = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 4;
			} else if (coluna == 5 && controleColuna == 4) {
				alunos[indexAluno].aep2 = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 5;
			} else if (coluna == 6 && controleColuna == 5) {
				alunos[indexAluno].prova2 = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 6;
			} else if (coluna == 7 && controleColuna == 6) {
				alunos[indexAluno].sub = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 7;
			}  else if (coluna == 8 && controleColuna == 7) {
				alunos[indexAluno].media = std::stof(conteudo);	
				conteudo = "";
				controleColuna = 8;
			} else if (coluna == 9 && controleColuna == 8) {
				alunos[indexAluno].status = conteudo;	
				conteudo = "";
				controleColuna = 9;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	// teste
	for (int i = 0; i < 10; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
		std::cout << "AEP1: " << alunos[i].aep1 << "\n";
		std::cout << "PROVA1: " << alunos[i].prova1 << "\n";
		std::cout << "AEP2: " << alunos[i].aep2 << "\n";
		std::cout << "PROVA2: " << alunos[i].prova2 << "\n";
		std::cout << "SUB: " << alunos[i].sub << "\n";
		std::cout << "MEDIA: " << alunos[i].media << "\n";
		std::cout << "STATUS: " << alunos[i].status << "\n";
	}
	
	return true;
}


// TELA INICIAL
int main() {	
	std::cout << "Bem vindo professor \n";
	int opc = 0;
	while (opc != 4) {
		std::cout << "Selecione as opcoes: \n";
		std::cout << "1 - Cadastrar aluno \n";
		std::cout << "2 - Cadastrar notas de um aluno \n";
		std::cout << "3 - Gerar relatorio \n";
		std::cout << "4 - Para finalizar \n";	
	
		std::cin >> opc;
		system("cls");
		switch (opc) {
			case 1:
				 cadastroaluno();
			break;
			case 2:
				cadastronota();
			break;
			case 3:
				realizaLeituraArquivo();
			break;
			case 4:
				finaliza();
			break;
		}
	}
	limpaTela();
		
	return 0;
}
