#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <locale.h>





// Definição da struct Aluno 

struct Aluno {
	
	std::string nome;
	std::string RA;
	std::string curso;
	double mediaFinal;
	
};

// Função utilitária para limpar buffer de entrada 
void limparEntrada() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// cadastro de alunos (vetor passa por referência ) 

void cadastrarAluno(std::vector<Aluno> &alunos) {
	Aluno novo;
	std::cout << "\n == Cadastrar Aluno ==\n";
	std::cout << "Nome: ";
	std:: getline(std::cin, novo.nome);
	std::cout << "RA: ";
	std::getline(std::cin, novo.RA);
	std::cout << "Curso: ";
	std::getline(std::cin, novo.curso);
	std::cout << "Média final: ";
	double mediaFinal;
   	while(true) {
		if (std:: cin >> mediaFinal && mediaFinal >= 0 && mediaFinal <=10){
		
		break;
	} else {
		std::cout << "Valor inválido. Digite uma média entre 0 e 10: \n ";
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

// Listagem de alunos (vetor passando por referência constante)

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
		          <<"| Média: " << a.mediaFinal << "\n";
	}
}

// Busca de aluno por RA
// Recebe referência para vetor (uso obrigatório de referência )
// Retorna o índice do aluno no vetor ou -1 caso não encontrado 

int buscarPorRA(const std::vector<Aluno> &alunos, const std::string &ra) {
	for(size_t i =0; i < alunos.size(); ++i) {
		if (alunos[i].RA == ra) return static_cast<int>(i);
	}
	return -1;
}

// Atualização da média final de um aluno usando ponteiro para acesso direto
void atualizarMedia(std::vector<Aluno> &alunos) {
	std::cout << "\n== Atualizar Média de aluno ==\n";
	
	if(alunos.empty()) {
		std:: cout << "Nenhum aluno cadastrado.\n";
		return;
	}
	std::string ra;
	std::cout << "Informe o RA do aluno: ";
	std::getline(std::cin, ra);
	
	int idx = buscarPorRA(alunos, ra);
	if (idx == -1) {
		std::cout << "Aluno com RA '" << ra << "' não encontrado.\n";
		return;
		
	}
	// Obtendo ponteiro para aluno dentro do vetor
	Aluno *pAluno = &alunos[idx];
	
	std::cout << "Alunos encontrado: " << pAluno->nome << " | Média Final: " << pAluno->mediaFinal << "\n";
	std::cout << "Nova média: ";
	double nova;
	while(true) {
		if (std:: cin >> nova && nova >= 0 && nova <=10){
		
		break;
	} else {
		std::cout << "Valor inválido. Digite uma média entre 0 e 10: \n ";
		std::cin.clear();
		limparEntrada();
	}
}
	limparEntrada();
	//Alterando via ponteiro
	pAluno->mediaFinal= nova;
	std::cout << "Média atualizada com sucesso.\n";
	
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
