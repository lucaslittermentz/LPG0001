void imprimir(int m[][PROVAS]) {
	int i, j;
	for(i = 0; i < ALUNOS; i++) {
		for(j = 0; j < PROVAS; j++) {
			printf("[%d][%d]=%d\t",i,j,m[i][j]);
		}
		printf("\n");
	}
}

float media_turma(int m[][PROVAS]) {
	int i, j;
	float ret = 0;
	for(i = 0; i < ALUNOS; i++) {
		for(j = 0; j < PROVAS; j++) {
			ret += m[i][j];
		}
	}
	return (ret/(ALUNOS+PROVAS));
}

float media_aluno(int v[]) {
	float ret = 0;
	int i = 0;
	while (i < PROVAS) {
		ret += v[i];
	}
	return ret/PROVAS;
}

int maior_nota(int m[][PROVAS]) {
	int maior = 0;
	int i, j;
	for (i = 0; i < ALUNOS; i++) {
		for (j = 0; j < PROVAS; j++) {
			if (m[i][j] > maior) {
				maior = m[i][j];
			}
		}
	}
	return maior;
}

int menor_nota(int m[][PROVAS]) {
	int menor = 100;
	int i, j;
	for (i = 0; i < ALUNOS; i++) {
		for (j = 0; j < PROVAS; j++) {
			if (m[i][j] < menor) {
				menor = m[i][j];
			}
		}
	}
	return menor;
}

int menu() {
	int ret = -1;
	while(ret<0 || ret>5) {
		printf("Informe 1 para imprimir\n");
		printf("Informe 2 para média da turma\n");
		printf("Informe 3 para maior nota\n");
		printf("Informe 4 para menor nota\n");
		printf("Informe 5 para média dos alunos\n");
		printf("Informe 0 para sair\n");
		scanf("%d",&ret);
	}
	return ret;
}