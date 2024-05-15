		/* ==========================================================================
		* Universidade Federal de São Carlos - Campus Sorocaba
		* Disciplina: Organização de Recuperação da Informação
		* Prof. Tiago A. Almeida
		*
		* Trabalho 01 - Indexação
		*
		* ========================================================================== *
		*   <<< IMPLEMENTE AQUI!!! COPIE E COLE O CONTEÚDO DESTE ARQUIVO NO AVA >>>
		* ========================================================================== */

		/* Bibliotecas */
		#include "ORI_T01_HEADER.h"

		/* ===========================================================================
		* ================================= FUNÇÕES ================================= */


		/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */


		/* Funções auxiliares para o qsort.
		* Com uma pequena alteração, é possível utilizá-las no bsearch, assim, evitando código duplicado.
		* */

		/* Função de comparação entre chaves do índice corredores_idx */
		int qsort_corredores_idx(const void *a, const void *b) {
			return strcmp( ( (corredores_index *)a )->id_corredor, ( (corredores_index *)b )->id_corredor);
		}

		/* Função de comparação entre chaves do índice veiculos_idx */
		int qsort_veiculos_idx(const void *a, const void *b) {
			return strcmp( ( (veiculos_index *)a )->id_veiculo, ( (veiculos_index *)b )->id_veiculo);
		}

		/* Função de comparação entre chaves do índice pistas_idx */
		int qsort_pistas_idx(const void *a, const void *b) {
			return strcmp( ( (pistas_index *)a )->id_pista, ( (pistas_index *)b )->id_pista);
		}

		/* Função de comparação entre chaves do índice corridas_idx */
		int qsort_corridas_idx(const void *a, const void *b) {
			return strcmp( ( (corridas_index *)a )->id_pista, ( (corridas_index *)b )->id_pista);
		}

		/* Funções de comparação apenas entre data de ocorrencia do índice corridas_idx */
		int qsort_data_idx(const void *a, const void *b){
			return strcmp( ( (corridas_index *)a )->ocorrencia, ( (corridas_index *)b )->ocorrencia);
		}

		/* Função de comparação entre chaves do índice nome_pista_idx */
		int qsort_nome_pista_idx(const void *a, const void *b){
			return strcmp( ( (nome_pista_index *)a )->nome, ( (nome_pista_index *)b )->nome);
		}

		/* Função de comparação entre chaves do índice preco_veiculo_idx */
		int qsort_preco_veiculo_idx(const void *a, const void *b){
			return ( ( (preco_veiculo_index *)a )->preco - ( (preco_veiculo_index *)b )->preco);
		}

		/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
		int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b){
			return strcmp( ( (corredor_veiculos_secundario_index *)a )->chave_secundaria, ( (corredor_veiculos_secundario_index *)b )->chave_secundaria);
		}

		/* Cria o índice respectivo */
		void criar_corredores_idx() {
			if (!corredores_idx)
				corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
		
			if (!corredores_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
				Corredor c = recuperar_registro_corredor(i);
		
				if (strncmp(c.id_corredor, "*|", 2) == 0)
					corredores_idx[i].rrn = -1; // registro excluído
				else
					corredores_idx[i].rrn = i;
		
				strcpy(corredores_idx[i].id_corredor, c.id_corredor);
			}
		
			qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
			printf(INDICE_CRIADO, "corredores_idx");
		}

		void criar_veiculos_idx() {
			if (!veiculos_idx) {
				veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_idx));
			}
		
			if (!veiculos_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
				Veiculo v = recuperar_registro_veiculo(i);
		
				if (strncmp(v.id_veiculo, "*|", 2) == 0) {
					veiculos_idx[i].rrn = -1; // registro excluído
				}
				else {
					veiculos_idx[i].rrn = i;
				}
				strcpy(veiculos_idx[i].id_veiculo, v.id_veiculo);
			}
		
			qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
			printf(INDICE_CRIADO, "veiculos_idx");
		}

		void criar_pistas_idx() {
			if (!pistas_idx) {
				pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_idx));
			}
		
			if (!pistas_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
				Pista p = recuperar_registro_pista(i);
		
				if (strncmp(p.id_pista, "*|", 2) == 0) {
					pistas_idx[i].rrn = -1; // registro excluído
				}
				else {
					pistas_idx[i].rrn = i;
				}
				strcpy(pistas_idx[i].id_pista, p.id_pista);
			}
		
			qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
			printf(INDICE_CRIADO, "pistas_idx");
		}

		void criar_corridas_idx() {
			if (!corridas_idx) {
				corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_idx));
			}
		
			if (!corridas_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_corridas; ++i) {
				Corrida c = recuperar_registro_corrida(i);
		
				if (strncmp(c.id_pista, "*|", 2) == 0) {
					corridas_idx[i].rrn = -1; // registro excluído
				}
				else {
					corridas_idx[i].rrn = i;
				}
				strcpy(corridas_idx[i].ocorrencia, c.ocorrencia);
				strcpy(corridas_idx[i].id_pista, c.id_pista);
				
			}
		
			qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);
			printf(INDICE_CRIADO, "corridas_idx");
		}

		void criar_nome_pista_idx() {
			if (!nome_pista_idx) {
				nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_idx));
			}
		
			if (!nome_pista_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
				Pista p = recuperar_registro_pista(i);
		
				strcpy(nome_pista_idx[i].nome, p.nome);
				strcpy(nome_pista_idx[i].id_pista, p.id_pista);
			}
		
			qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_idx), qsort_nome_pista_idx);
			printf(INDICE_CRIADO, "nome_pista_idx");
		}

		void criar_preco_veiculo_idx() {
			if (!preco_veiculo_idx) {
				preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_idx));
			}
		
			if (!preco_veiculo_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}
		
			for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
				Veiculo v = recuperar_registro_veiculo(i);
		
				preco_veiculo_idx[i].preco = v.preco;
				strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);
			}
		
			qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_idx), qsort_preco_veiculo_idx);
			printf(INDICE_CRIADO, "preco_veiculo_idx");
		}

		void criar_corredor_veiculos_idx() {

			// * Criacao do indice primario

			if(!corredor_veiculos_idx.corredor_veiculos_primario_idx) {
				corredor_veiculos_idx.corredor_veiculos_primario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_idx.corredor_veiculos_primario_idx));
			}

			if(!corredor_veiculos_idx.corredor_veiculos_primario_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}

			// for (unsigned i = 0; i < corredor_veiculos_idx.qtd_registros_primario; ++i) {
			//     Corredor c = recuperar_registro_corredor(i);
		
			//     preco_veiculo_idx[i].preco = v.preco;
			//     strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);
			// }

			// * Criacao do indice secundario

			if(!corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
				corredor_veiculos_idx.corredor_veiculos_secundario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_idx.corredor_veiculos_secundario_idx));
			}

			if(!corredor_veiculos_idx.corredor_veiculos_secundario_idx) {
				printf(ERRO_MEMORIA_INSUFICIENTE);
				exit(1);
			}

			printf(INDICE_CRIADO, "corredor_veiculos_idx");
			
		}

		/* Exibe um registro com base no RRN */
		bool exibir_corredor(int rrn) {
			if (rrn < 0)
				return false;
		
			Corredor c = recuperar_registro_corredor(rrn);
		
			printf("%s, %s, %s, %s, %.2lf\n", c.id_corredor, c.nome, c.apelido, c.cadastro, c.saldo);
			return true;
		}

		bool exibir_veiculo(int rrn) {
			if (rrn < 0) {
				return false;
			}

			Veiculo v = recuperar_registro_veiculo(rrn);

			printf("%s, %s, %s, %s, %d, %d, %d, %.2lf\n", v.id_veiculo, v.marca, v.modelo, v.poder, v.velocidade, v.aceleracao, v.peso, v.preco);
			return true;
		}

		bool exibir_pista(int rrn) {
			if (rrn < 0) {
				return false;
			}

			Pista p = recuperar_registro_pista(rrn);

			printf("%s, %s, %d, %d, %d\n", p.id_pista, p.nome, p.dificuldade, p.distancia, p.recorde);
			return true;
		}

		bool exibir_corrida(int rrn) {
			if (rrn < 0) {
				return false;
			}

			Corrida c = recuperar_registro_corrida(rrn);

			printf("%s, %s, %s, %s", c.id_pista, c.ocorrencia, c.id_corredores, c.id_veiculos);
			return true;
		}

		/* Recupera do arquivo o registro com o RRN informado
		* e retorna os dados nas structs */
		Corredor recuperar_registro_corredor(int rrn) {
			Corredor c;
			char temp[TAM_REGISTRO_CORREDOR + 1], *p;
			strncpy(temp, ARQUIVO_CORREDORES + (rrn * TAM_REGISTRO_CORREDOR), TAM_REGISTRO_CORREDOR);
			temp[TAM_REGISTRO_CORREDOR] = '\0';

			p = strtok(temp, ";");
			strcpy(c.id_corredor, p);
			p = strtok(NULL, ";");
			strcpy(c.nome, p);
			p = strtok(NULL, ";");
			strcpy(c.apelido, p);
			p = strtok(NULL, ";");
			strcpy(c.cadastro, p);
			p = strtok(NULL, ";");
			c.saldo = atof(p);
			p = strtok(NULL, ";");

			for(int i = 0; i < QTD_MAX_VEICULO; ++i)
				c.veiculos[i][0] = '\0';

			if(p[0] != '#') {
				p = strtok(p, "|");

				for(int pos = 0; p; p = strtok(NULL, "|"), ++pos)
					strcpy(c.veiculos[pos], p);
			}

			return c;
		}

		Veiculo recuperar_registro_veiculo(int rrn) {
			Veiculo v;
			char temp[TAM_REGISTRO_VEICULO + 1], *campo;
			strncpy(temp, ARQUIVO_VEICULOS + (rrn * TAM_REGISTRO_VEICULO), TAM_REGISTRO_VEICULO);
			temp[TAM_REGISTRO_VEICULO] = '\0';

			campo = strtok(temp, ";");
			strcpy(v.id_veiculo, campo);
			campo = strtok(NULL, ";");
			strcpy(v.marca, campo);
			campo = strtok(NULL, ";");
			strcpy(v.modelo, campo);
			campo = strtok(NULL, ";");
			strcpy(v.poder, campo);
			campo = strtok(NULL, ";");
			v.velocidade = atoi(campo);
			campo = strtok(NULL, ";");
			v.aceleracao = atoi(campo);
			campo = strtok(NULL, ";");
			v.peso = atoi(campo);
			campo = strtok(NULL, ";");
			v.preco = atof(campo);
			
			return v;
		}

		Pista recuperar_registro_pista(int rrn) {
			Pista p;
			char temp[TAM_REGISTRO_PISTA + 1], *campo;
			strncpy(temp, ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), TAM_REGISTRO_PISTA);
			temp[TAM_REGISTRO_PISTA] = '\0';

			campo = strtok(temp, ";");
			strcpy(p.id_pista, campo);
			campo = strtok(NULL, ";");
			strcpy(p.nome, campo);
			campo = strtok(NULL, ";");
			p.dificuldade = atoi(campo);
			campo = strtok(NULL, ";");
			p.distancia = atoi(campo);
			campo = strtok(NULL, ";");
			p.recorde = atoi(campo);

			return p;
		}

		Corrida recuperar_registro_corrida(int rrn) {
			Corrida c;
			char temp[TAM_REGISTRO_CORRIDA + 1], *campo;
			strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);
			temp[TAM_REGISTRO_CORRIDA] = '\0';

			campo = strtok(temp, ";");
			strcpy(c.id_pista, campo);
			campo = strtok(NULL, ";");
			strcpy(c.ocorrencia, campo);
			campo = strtok(NULL, ";");
			strcpy(c.id_corredores, campo);
			campo = strtok(NULL, ";");
			strcpy(c.id_veiculos, campo);

			return c;
		}

		/* Escreve em seu respectivo arquivo na posição informada (RRN) */
		void escrever_registro_corredor(Corredor c, int rrn) {
			char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
			temp[0] = '\0'; p[0] = '\0';

			strcpy(temp, c.id_corredor);
			strcat(temp, ";");
			strcat(temp, c.nome);
			strcat(temp, ";");
			strcat(temp, c.apelido);
			strcat(temp, ";");
			strcat(temp, c.cadastro);
			strcat(temp, ";");
			sprintf(p, "%013.2lf", c.saldo);
			strcat(temp, p);
			strcat(temp, ";");

			for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
				if(strlen(c.veiculos[i]) > 0) {
					if (k == 0)
						k = 1;
					else
						strcat(temp, "|");
					strcat(temp, c.veiculos[i]);
				}
			}
			strcat(temp, ";");

			strpadright(temp, '#', TAM_REGISTRO_CORREDOR);

			strncpy(ARQUIVO_CORREDORES + rrn*TAM_REGISTRO_CORREDOR, temp, TAM_REGISTRO_CORREDOR);
		}

		void escrever_registro_veiculo(Veiculo v, int rrn) {
			char temp[TAM_REGISTRO_VEICULO + 1], aux[100];
			temp[0] = '\0'; aux[0] = '\0';

			strcpy(temp, v.id_veiculo);
			strcat(temp, ";");
			strcat(temp, v.marca);
			strcat(temp, ";");
			strcat(temp, v.modelo);
			strcat(temp, ";");
			strcat(temp, v.poder);
			strcat(temp, ";");
			sprintf(aux, "%04d", v.velocidade);
			strcat(temp, aux);
			strcat(temp, ";");
			sprintf(aux, "%04d", v.aceleracao);
			strcat(temp, aux);
			strcat(temp, ";");
			sprintf(aux, "%04d", v.peso);
			strcat(temp, aux);
			strcat(temp, ";");
			sprintf(aux, "%013.2lf", v.preco);
			strcat(temp, aux);
			strcat(temp, ";");

			strpadright(temp, '#', TAM_REGISTRO_VEICULO);

			strncpy(ARQUIVO_VEICULOS + rrn*TAM_REGISTRO_VEICULO, temp, TAM_REGISTRO_VEICULO);
		}

		void escrever_registro_pista(Pista p, int rrn) {
			char temp[TAM_REGISTRO_PISTA + 1], aux[100];
			temp[0] = '\0'; aux[0] = '\0';

			strcpy(temp, p.id_pista);
			strcat(temp, ";");
			strcat(temp, p.nome);
			strcat(temp, ";");
			sprintf(aux, "%04d", p.dificuldade);
			strcat(temp, aux);
			strcat(temp, ";");
			sprintf(aux, "%04d", p.distancia);
			strcat(temp, aux);
			strcat(temp, ";");
			sprintf(aux, "%04d", p.recorde);
			strcat(temp, aux);
			strcat(temp, ";");

			strpadright(temp, '#', TAM_REGISTRO_PISTA);

			strncpy(ARQUIVO_PISTAS + rrn*TAM_REGISTRO_PISTA, temp, TAM_REGISTRO_PISTA);
		}

		void escrever_registro_corrida(Corrida i, int rrn) {
			char temp[TAM_REGISTRO_CORRIDA + 1];
			temp[0] = '\0';

			strcpy(temp, i.id_pista);
			strcat(temp, i.ocorrencia);
			strcat(temp, i.id_corredores);
			strcat(temp, i.id_veiculos);

			strncpy(ARQUIVO_CORRIDAS + rrn*TAM_REGISTRO_CORRIDA, temp, TAM_REGISTRO_CORRIDA);
		}

		/* Funções principais */
		void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido){

			// Busca do corredor
			corredores_index *corredor = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);


			// Verificacao de CPF ja existente
			if (!corredor) {
				// Criacao do corredor
				Corredor c;

				strcpy(c.id_corredor, id_corredor);
				strcpy(c.nome, nome);
				strcpy(c.apelido, apelido);
				c.saldo = 0000000000.00;
				current_datetime(c.cadastro);

				// Colocar veiculos do corredor como nulo
				for(int i = 0; i < QTD_MAX_VEICULO; i++) {
					c.veiculos[i][0] = '\0';
				}

				// Atualizacao do indice
				corredores_idx[qtd_registros_corredores].rrn = qtd_registros_corredores;
				strcpy(corredores_idx[qtd_registros_corredores].id_corredor, id_corredor);
				
				// Insercao no arquivo
				escrever_registro_corredor(c, qtd_registros_corredores);

				// Atualizacao da quantidade de registro de corredores
				qtd_registros_corredores++;

				// Ordenacao do indice
				qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

				printf(SUCESSO);
			}
			else { // Caso que ja existe um corredor com este CPF
				printf(ERRO_PK_REPETIDA, id_corredor);
			}

		}

		void remover_corredor_menu(char *id_corredor) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "remover_corredor_menu()");
		}

		void adicionar_saldo_menu(char *id_corredor, double valor) {
			adicionar_saldo(id_corredor, valor, true);
		}

		void adicionar_saldo(char *id_corredor, double valor, bool flag){
			
			// Busca do corredor
			corredores_index *corredor = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

			// Verificacao da existencia do corredor
			if(corredor) {
				if(valor > 0) {
					// Recuperar o corredor do arquivo
					Corredor c = recuperar_registro_corredor(corredor->rrn);

					// Atualizar o saldo
					c.saldo = c.saldo + valor;

					// Atualizar o registro do corredor
					escrever_registro_corredor(c, corredor->rrn);
					printf(SUCESSO);
				}
				else {
					printf(ERRO_VALOR_INVALIDO);
				}
			} 
			else { // Caso em que o corredor nao existe
				printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			}

		}

		void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "comprar_veiculo_menu()");
		}

		void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
			
			// Variavel auxiliar para lidar com valores numericos
			char aux[20];
			aux[0] = '\0';

			// Criacao do veiculo
			Veiculo v;

			// Criacao do ID incremental dos veiculos
			sprintf(aux, "%07d", qtd_registros_veiculos);
			strcpy(v.id_veiculo, aux);

			// Busca de veiculo com mesmo ID
			veiculos_index *veiculo = bsearch(v.id_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);

			// Verificacao de ID ja existente
			if (!veiculo) {

				// Criacao completa do veiculo
				strcpy(v.marca, marca);
				strcpy(v.modelo, modelo);
				strcpy(v.poder, poder);
				v.velocidade = velocidade;
				v.aceleracao = aceleracao;
				v.peso = peso;
				v.preco = preco;
				
				// Atualizacao dos indices
				veiculos_idx[qtd_registros_veiculos].rrn = qtd_registros_veiculos;
				strcpy(veiculos_idx[qtd_registros_veiculos].id_veiculo, v.id_veiculo);

				strcpy(preco_veiculo_idx[qtd_registros_veiculos].id_veiculo, v.id_veiculo);
				preco_veiculo_idx[qtd_registros_veiculos].preco = v.preco;


				// Insercao no arquivo
				escrever_registro_veiculo(v, qtd_registros_veiculos);

				// Atualizacao da quantidade de registro de veiculos
				qtd_registros_veiculos++;

				// Ordenacao dos indices
				qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
				qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);

				printf(SUCESSO);
			}
			else { // caso ja exista um veiculo com esse ID
				printf(ERRO_PK_REPETIDA, v.id_veiculo);
			}
		}

		void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde){
			// Variavel auxiliar para lidar com valores numericos
			char aux[20];
			aux[0] = '\0';

			// Criacao da pista
			Pista p;

			// Criacao do ID incremental das pistas
			sprintf(aux, "%08d", qtd_registros_pistas);
			strcpy(p.id_pista, aux);

			// Busca de pista com mesmo nome
			nome_pista_index *pista = bsearch(nome, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);

			// Verificacao de nome ja existente
			if (!pista) {

				// Criacao completa da pista
				strcpy(p.nome, nome);
				p.dificuldade = !dificuldade ? 1 : dificuldade;
				p.distancia = distancia;
				p.recorde = recorde;
				
				
				// Atualizacao dos indices
				pistas_idx[qtd_registros_pistas].rrn = qtd_registros_pistas;
				strcpy(pistas_idx[qtd_registros_pistas].id_pista, p.id_pista);

				strcpy(nome_pista_idx[qtd_registros_pistas].nome, p.nome);
				strcpy(nome_pista_idx[qtd_registros_pistas].id_pista, p.id_pista);

				// Insercao no arquivo
				escrever_registro_pista(p, qtd_registros_pistas);

				// Atualizacao da quantidade de registro de pistas
				qtd_registros_pistas++;

				// Ordenacao dos indices
				qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
				qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);

				printf(SUCESSO);
			}
			else { // caso ja exista uma pista com esse nome
				printf(ERRO_PK_REPETIDA, nome);
			}
		}

		void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "executar_corrida_menu()");
		}

		/* Busca */
		void buscar_corredor_id_menu(char *id_corredor) {
			corredores_index index;
			strcpy(index.id_corredor, id_corredor);
			corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
			if (found == NULL || found->rrn < 0)
				printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			else
				exibir_corredor(found->rrn);
		}

		void buscar_pista_id_menu(char *id_pista) {
			pistas_index index;
			strcpy(index.id_pista, id_pista);
			// Busca da pista
			pistas_index *found = busca_binaria((void*)&index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
			
			// Caso a pista nao seja encontrada
			if(found == NULL || found->rrn < 0) {
				printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			}
			// Pista encontrada
			else {
				exibir_pista(found->rrn);
			}
		}

		void buscar_pista_nome_menu(char *nome_pista) {
			nome_pista_index n_index;
			strcpy(n_index.nome, nome_pista);

			// Busca do nome
			nome_pista_index *n_found = busca_binaria((void*)&n_index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);
			
			pistas_index p_index;
			strcpy(p_index.id_pista, n_found->id_pista);

			// Busca da pista
			pistas_index *p_found = busca_binaria((void*)&p_index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
			
			// Caso a pista nao seja encontrada
			if(p_found == NULL || p_found->rrn < 0) {
				printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			}
			// Pista encontrada
			else {
				exibir_pista(p_found->rrn);
			}
		}

		/* Listagem */
		void listar_corredores_id_menu() {
			if (qtd_registros_corredores == 0)
				printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
			else
				for (unsigned int i = 0; i < qtd_registros_corredores; i++)
					exibir_corredor(corredores_idx[i].rrn);
		}

		void listar_corredores_modelo_menu(char *modelo){
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "listar_corredores_modelo_menu()");
		}

		void listar_veiculos_compra_menu(char *id_corredor) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "listar_veiculos_compra_menu()");
		}

		void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu()");
		}

		/* Liberar espaço */
		void liberar_espaco_menu() {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "liberar_espaco_menu()");
		}

		/* Imprimir arquivos de dados */
		void imprimir_arquivo_corredores_menu() {
			if (qtd_registros_corredores == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				printf("%s\n", ARQUIVO_CORREDORES);
		}

		void imprimir_arquivo_veiculos_menu() {
			if (qtd_registros_veiculos == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				printf("%s\n", ARQUIVO_VEICULOS);
		}

		void imprimir_arquivo_pistas_menu() {
			if (qtd_registros_pistas == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				printf("%s\n", ARQUIVO_PISTAS);
		}

		void imprimir_arquivo_corridas_menu() {
			if (qtd_registros_corridas == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				printf("%s\n", ARQUIVO_CORRIDAS);
		}

		/* Imprimir índices primários */
		void imprimir_corredores_idx_menu() {
			if (corredores_idx == NULL || qtd_registros_corredores == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				for (unsigned i = 0; i < qtd_registros_corredores; ++i)
					printf("%s, %d\n", corredores_idx[i].id_corredor, corredores_idx[i].rrn);
		}

		void imprimir_veiculos_idx_menu() {
			if (veiculos_idx == NULL || qtd_registros_veiculos == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
					printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
		}

		void imprimir_pistas_idx_menu() {
			if (pistas_idx == NULL || qtd_registros_pistas == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				for (unsigned i = 0; i < qtd_registros_pistas; ++i)
					printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
		}

		void imprimir_corridas_idx_menu() {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corridas_idx_menu()");
		}

		/* Imprimir índices secundários */
		void imprimir_nome_pista_idx_menu() {
			if (nome_pista_idx == NULL || qtd_registros_pistas == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
					char* nome_formatado = strupr(nome_pista_idx[i].nome);
					printf("%s, %s\n", nome_formatado, nome_pista_idx[i].id_pista);
				}
		}

		void imprimir_preco_veiculo_idx_menu() {
			if (preco_veiculo_idx == NULL || qtd_registros_veiculos == 0)
				printf(ERRO_ARQUIVO_VAZIO);
			else
				for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
					printf("%05.2lf, %s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
		}

		void imprimir_corredor_veiculos_secundario_idx_menu() {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_secundario_idx_menu()");
		}

		void imprimir_corredor_veiculos_primario_idx_menu(){
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "imprimir_corredor_veiculos_primario_idx_menu()");
		}

		/* Liberar memória e encerrar programa */
		void liberar_memoria_menu() {

			// Liberar a memoria dos indices
			free(corredores_idx);
			free(veiculos_idx);
			free(pistas_idx);
			free(corridas_idx);
			free(nome_pista_idx);
			free(preco_veiculo_idx);
			free(corredor_veiculos_idx.corredor_veiculos_primario_idx);
			free(corredor_veiculos_idx.corredor_veiculos_secundario_idx);

		}

		void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_insert()");
		}

		bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_secondary_search()");
			return false;
		}

		int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
			/*IMPLEMENTE A FUNÇÃO AQUI*/
			printf(ERRO_NAO_IMPLEMENTADO, "inverted_list_primary_search()");
			return -1;
		}


		void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
			const char *base = (const char *) base0;
			int lim, mid, comp;
			const void* search_num;
			// variavel para manter o ultimo elemento antes da key
			const void* ant;

			if (exibir_caminho) {
				printf("Registros percorridos: ");
			}

			for(lim = nmemb; lim != 0; lim /= 2) {
				mid = lim/2;
				if(lim % 2 == 0) {
					mid++;
				}
				search_num = base + mid * size;
				comp = (*compar)(key, search_num);

				// Exibicao do caminho percorrido pela busca
				if (exibir_caminho) {
					printf("%ld ", (search_num - base0)/size);
				}

				// Caso em que o valor foi encontrado
				if (comp == 0) {

					// Caso para retornar o elemento mais a esquerda se repetido
					if(posicao_caso_repetido == -1) {
						while (search_num != base && (*compar)(key, (const char *)search_num - size) == 0) {
							search_num = (const char*)search_num - size;
						}
					}

					// Caso para retornar o elemento mais a direita se repetido
					if(posicao_caso_repetido == 1) {
						while ((const char*)search_num < (base + nmemb * size) && (*compar)(key, (const char *)search_num + size) == 0) {
							search_num = search_num + size;
						}
					}

					// Caso para retornar o elemento central se repetido
					if(posicao_caso_repetido == 0) {
						const char* first = search_num; 
						const char* last = search_num;

						while (first != base && (*compar)(key, first - size) == 0) {
							first = first - size;
						}

						while (last < (base + nmemb * size) && (*compar)(key, first + size) == 0) {
							last = last + size;
						}

						// Calculo da quantidade de elementos repetidos
						int qtd = (last - first)/size + 1;

						if (qtd % 2 == 0) {
							// Calculo dos indices dos elemento central mais a direita
							search_num = (first + (qtd/2) * size) + size;
						}
						else {
							// Calculo do indice do elemento central
							search_num = first + (qtd/2) * size;

						}
					}
					if (exibir_caminho) printf("\n");
					return (void *) search_num;
				}
				// Caso em que o valor buscado é maior
				if (comp > 0) {
					ant = search_num;
					base = (char *)search_num + size;
					lim--;
				}
			}
			if(exibir_caminho) printf("\n");

			// Tratamento do retorno caso elemento nao seja encontrado

			// Caso para retornar o antecessor
			if(retorno_se_nao_encontrado == -1 && ant) {
				if((const char*)ant != base0 && (*compar)(key, ant) < 0) {
					return (void *) ant;
				}
			}
			// Caso para retornar o sucessor
			else if(retorno_se_nao_encontrado == 1 && ant) {
				const void* next = (const char*)ant + size;
				if(next && (*compar)(key, next) > 0) {
					return (void *) next;
				}
			}

			// Caso de retorno_nao_encontrado == 0
			return(NULL);
		}

		void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
			return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
		}

		char *strpadright(char *str, char pad, unsigned size){
			for (unsigned i = strlen(str); i < size; ++i)
				str[i] = pad;
			str[size] = '\0';
			return str;
		}
		char *strupr(char *str){
			for (char *p = str; *p; ++p)
				*p = toupper(*p);
			return str;
		}
		char *strlower(char *str){
			for (char *p = str; *p; ++p)
				*p = tolower(*p);
			return str;
		}