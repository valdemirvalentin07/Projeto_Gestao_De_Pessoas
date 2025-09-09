#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <locale.h>





// Defini��o da struct Aluno 

struct Aluno {
	
	std::string nome;
	std::string RA;
	std::string curso;
	double mediaFinal;
	
};

// Fun��o utilit�ria para limpar buffer de entrada 
void limparEntrada() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// cadastro de alunos (vetor passa por refer�ncia ) 

void cadastrarAluno(std::vector<Aluno> &alunos) {
	Aluno novo;
	std::cout << "\n == Cadastrar Aluno ==\n";
	std::cout << "Nome: ";
	std:: getline(std::cin, novo.nome);
	std::cout << "RA: ";
	std::getline(std::cin, novo.RA);
	std::cout << "Curso: ";
	std::getline(std::cin, novo.curso);
	std::cout << "M�dia final: ";
	double mediaFinal;
   	while(true) {
		if (std:: cin >> mediaFinal && mediaFinal >= 0 && mediaFinal <=10){
		
		break;
	} else {
		std::cout << "Valor inv�lido. Digite uma m�dia entre 0 e 10: \n ";
		std::cin.clear();
		limparEntrada();
	}
}
	
	limparEntrada();
	
	novo.mediaFinal = mediaFinal;
	
	//Inserindo no vetor
	alunos.push_back(novo);
	
	std::cout <<"Aluno cadastrado com sucesso!\n";
		
}

// Listagem de alunos (vetor passando por refer�ncia constante)

void listarAlunos(const std::vector<Aluno> &alunos) {
	std::cout << "\n == Lista de Alunos ==\n";
	if(alunos.empty()) {
		std::cout << "Nenhum aluno cadastrado.\n";
		return;
	}
	for (size_t i =0; i < alunos.size(); ++i){
		const Aluno &a = alunos[i];
		std::cout <<"[" << i+1 << "] Nome: " << a.nome
		          <<"| RA:" << a.RA
		          <<"| curso: "<< a.curso
		          <<"| M�dia: " << a.mediaFinal << "\n";
	}
}

// Busca de aluno por RA
// Recebe refer�ncia para vetor (uso obrigat�rio de refer�ncia )
// Retorna o �ndice do aluno no vetor ou -1 caso n�o encontrado 

int buscarPorRA(const std::vector<Aluno> &alunos, const std::string &ra) {
	for(size_t i =0; i < alunos.size(); ++i) {
		if (alunos[i].RA == ra) return static_cast<int>(i);
	}
	return -1;
}

// Atualiza��o da m�dia final de um aluno usando ponteiro para acesso direto
void atualizarMedia(std::vector<Aluno> &alunos) {
	std::cout << "\n== Atualizar M�dia de aluno ==\n";
	
	if(alunos.empty()) {
		std:: cout << "Nenhum aluno cadastrado.\n";
		return;
	}
	std::string ra;
	std::cout << "Informe o RA do aluno: ";
	std::getline(std::cin, ra);
	
	int idx = buscarPorRA(alunos, ra);
	if (idx == -1) {
		std::cout << "Aluno com RA '" << ra << "' n�o encontrado.\n";
		return;
		
	}
	// Obtendo ponteiro para aluno dentro do vetor
	Aluno *pAluno = &alunos[idx];
	
	std::cout << "Alunos encontrado: " << pAluno->nome << " | M�dia Final: " << pAluno->mediaFinal << "\n";
	std::cout << "Nova m�dia: ";
	double nova;
	while(true) {
		if (std:: cin >> nova && nova >= 0 && nova <=10){
		
		break;
	} else {
		std::cout << "Valor inv�lido. Digite uma m�dia entre 0 e 10: \n ";
		std::cin.clear();
		limparEntrada();
	}
}
	limparEntrada();
	//Alterando via ponteiro
	pAluno->mediaFinal= nova;
	std::cout << "M�dia atualizada com sucesso.\n";
	
	}
	
	int main() {
		setlocale(LC_ALL,"PORTUGUESE");
    std::vector<Aluno> alunos;

    cadastrarAluno(alunos);
    listarAlunos(alunos);
    atualizarMedia(alunos);
    listarAlunos(alunos);

    return 0;

}
