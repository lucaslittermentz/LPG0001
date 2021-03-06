#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

agenda *inicializa_agenda(void) {
	Agenda *ret = NULL;
	
	if (!(ret = (Agenda *) malloc(sizeof(Agenda)))) {
		printf("[inicializa_agenda] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	ret -> contatos = NULL;
	ret -> elementos = 0;
	return ret;
}

void libera_agenda(Agenda *a) {

}

Contato *novo_contato(void) {
	Contato *ret = NULL;

	if (!(ret = (Contato *) malloc(sizeof(Contato)))) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	ret -> nasc.dia = 0;
	ret -> nasc.mes = 0;
	ret -> nasc.ano = 0;
	if (!(ret -> nome = (char *) malloc(sizeof(char) * TAM_NOME))) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	if (!(ret -> telefone = (char *) malloc(sizeof(char) * TAM_TELEFONE))) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	ret -> end = novo_endereco();
	return ret;
}

void inserir_contato(Agenda *a) {
	int tam_atual = a -> elementos;
	Contato **tmp = NULL;

	if (!(tmp = (Contato **) realloc(a -> contatos, (tam_atual +1) * sizeof(Contato *)))) {
		printf("[inserir_contato] Temporariamente sem memória\n");
		return;
	}
	a -> contatos = tmp;
	a -> contatos[a -> elementos - 1] = novo_contato();

	printf("Prezado usuário. Informe os dados para o índice %d\n", a -> elementos);
	printf("Informe dia, mês e ano de nascimento\n");
	scanf("%d%d%d", &a -> contatos[a -> elementos] -> nasc.dia,
					&a -> contatos[a -> elementos] -> nasc.mes,
					&a -> contatos[a -> elementos] -> nasc.ano);
	printf("Informe o nome e telefone\n");
	scanf("%80s%80s", a -> contatos[a -> elementos] -> nome,
				  a -> contatos[a -> elementos] -> telefone);
	printf("Informe seu endereço, complemento e UF\n");
	scanf("%80s%80s%2s", a -> contatos[a -> elementos] -> end -> endereco,
					 a -> contatos[a -> elementos] -> end -> complemento,
					 a -> contatos[a -> elementos] -> end -> UF);

	a -> elementos = a -> elementos + 1;
}

void libera_contato(Contato *c) {
	free(c -> nome);
	free(c -> telefone);
	libera_endereco(end);
	free(c -> end);
	c -> nome = NULL;
	c -> telefone = NULL;
	c -> end = NULL;
	// Não faz nada. Apenas para garantir que não será possível acessar por engano.
	free(c);
}

Endereco *novo_endereco(void) {
	Endereco *ret = NULL;

	if (!(ret = (Endereco *) malloc(sizeof(Endereco)))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	if (!(ret -> endereco = (char *) malloc(sizeof(char) * TAM_ENDERECO))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	if (!(ret -> complemento = (char *) malloc(sizeof(char) * TAM_COMPLEMENTO))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

void libera_endereco(Endereco *end) {
	free(end -> endereco);
	free(end -> complemento);
	end -> endereco = NULL; 
	end -> complemento = NULL;
	// mesma coisa, essas três linhas acima não tem efeito algum, é só neurose.
	free(end);
}

void lista_pessoas(Agenda *a) {

}
