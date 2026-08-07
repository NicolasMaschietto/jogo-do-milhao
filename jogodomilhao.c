#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define N_BANK 25
#define N_ROUND 15
#define SAFE1 5
#define SAFE2 10

typedef struct {
    const char *texto;
    const char *op[4];
    int correta; 
} Perg;

/* BANCO DE PERGUNTAS (GERADAS COM IA) */
Perg bankF[N_BANK] = {
    {"Qual é a capital do Brasil?", {"São Paulo","Rio de Janeiro","Brasília","Bahia"}, 2},
    {"Quanto é 2+2?", {"3","4","5","6"}, 1},
    {"Qual é a cor do céu?", {"Azul","Verde","Roxo","Vermelho"}, 0},
    {"Quanto é 10*2?", {"15","20","25","30"}, 1},
    {"Qual moeda do Brasil?", {"Dólar","Real","Euro","Peso"}, 1},
    {"Qual Animal que mia?", {"Cachorro","Gato","Vaca","Cavalo"}, 1},
    {"Quantos dias tem 1 semana?", {"5","6","7","8"}, 2},
    {"Qual Planeta que vivemos?", {"Marte","Júpiter","Terra","Vênus"}, 2},
    {"Qual Oposto de alto?", {"Baixo","Pequeno","Largo","Curto"}, 0},
    {"Qual Animal que voa?", {"Peixe","Pássaro","Cobra","Tartaruga"}, 1},
    {"Qual a Cor da grama?", {"Azul","Amarelo","Verde","Rosa"}, 2},
    {"Quanto é 5+5?", {"8","9","10","11"}, 2},
    {"Qual a Primeira letra do alfabeto?", {"A","B","C","D"}, 0},
    {"Quanto é 9-4?", {"3","4","5","6"}, 2},
    {"Qual objeto escreve?", {"Lápis","Garfo","Faca","Copo"}, 0},
    {"Qual a Capital de SP?", {"Santos","Campinas","São Paulo","Jundiaí"}, 2},
    {"Qual a Cor do sol?", {"Amarelo","Roxo","Azul","Verde"}, 0},
    {"Quanto é 2*3?", {"5","6","7","8"}, 1},
    {"Qual é Maior que 10?", {"8","9","10","12"}, 3},
    {"Quem late?", {"Gato","Cachorro","Cavalo","Vaca"}, 1},
    {"Qual a Capital da França?", {"Paris","Londres","Roma","Berlim"}, 0},
    {"A Água é um?", {"Líquido","Sólido","Gasoso","Metal"}, 0},
    {"Quanto é 3+7?", {"9","10","11","12"}, 1},
    {"Qual a Cor do sangue?", {"Azul","Vermelho","Verde","Rosa"}, 1},
    {"Qual é um Mamífero?", {"Tubarão","Golfinho","Cobra","Sapo"}, 1}
};

Perg bankM[N_BANK] = {
    {"Qual a Capital da Argentina?", {"Buenos Aires","Rosário","Córdoba","Salta"}, 0},
    {"Qual a Raiz de 144?", {"10","11","12","13"}, 2},
    {"Quem escreveu Dom Casmurro?", {"Machado","Drummond","Clarice","José"}, 0},
    {"Qual o Símbolo do Oxigênio?", {"O","Ox","Og","On"}, 0},
    {"Quantos Estados tem  no Brasil?", {"25","26","27","28"}, 2},
    {"Quem pintou Monalisa?", {"Van Gogh","Picasso","Da Vinci","Monet"}, 2},
    {"Qual o Maior oceano?", {"Atlântico","Índico","Pacífico","Ártico"}, 2},
    {"Qual a Capital do Japão?", {"Osaka","Kyoto","Tóquio","Hiroshima"}, 2},
    {"Quanto é 12*12?", {"132","144","154","164"}, 1},
    {"Que país tem a Maior população?", {"EUA","Índia","China","Rússia"}, 2},
    {"Qual o Gás essencial?", {"Nitrogênio","Oxigênio","Hélio","Hidrogênio"}, 1},
    {"O que Detecta luz?", {"Microfone","Fotodiodo","Alto-falante","Sensor térmico"}, 1},
    {"Qual Planeta possui anéis?", {"Marte","Vênus","Saturno","Mercúrio"}, 2},
    {"Qual o autor de Pequeno Príncipe?", {"Saint-Exupéry","Hugo","Voltaire","Zola"}, 0},
    {"Qual o Idioma da China?", {"Mandarim","Cantonês","Inglês","Espanhol"}, 0},
    {"O que o Higrômetro mede?", {"Temperatura","Pressão","Umidade","Som"}, 2},
    {"Qual o Símbolo do ouro?", {"Au","Ag","Fe","Pb"}, 0},
    {"Qual o Maior país do mundo?", {"China","EUA","Canadá","Rússia"}, 3},
    {"Qual a Velocidade da luz?", {"300k km/s","150k km/s","1M km/s","50k km/s"}, 0},
    {"Água ferve a?", {"50°C","80°C","100°C","120°C"}, 2},
    {"O que faz o rim?", {"Filtra sangue","Faz hormônio","Produz saliva","Aumenta força"}, 0},
    {"Qual vitamina do sol?", {"A","B","C","D"}, 3},
    {"Qual o símbolo do ferro?", {"F","Fe","Fr","Fo"}, 1},
    {"Qual o simbolo do Cálcio ?", {"Ca","Cl","Ce","Cq"}, 0},
    {"Qual é um Planeta vermelho?", {"Vênus","Marte","Terra","Júpiter"}, 1}
};

Perg bankD[N_BANK] = {
    {"Qual a Derivada de x^2?", {"x","2x","1","x^3"}, 1},
    {"Quem foi o primeiro Presidente do Brasil?", {"Vargas","Deodoro da Fonseca","JK","Collor"}, 1},
    {"Em que ano foi a Revolução Francesa?", {"1789","1776","1804","1799"}, 0},
    {"Qual o Valor de pi?", {"3.14","3.41","3.04","3.99"}, 0},
    {"Qual a Capital da Austrália?", {"Sydney","Melbourne","Canberra","Perth"}, 2},
    {"Quem criou as Leis do movimento?", {"Einstein","Newton","Tesla","Galileu"}, 1},
    {"Quem é o autor da Penicilina?", {"Fleming","Pasteur","Curie","Darwin"}, 0},
    {"O que Entropia significa?", {"Ordem","Desordem","Força","Velocidade"}, 1},
    {"Qual o Maior número primo <100?", {"89","83","97","79"}, 2},
    {"Qual o Elemento mais abundante?", {"Hidrogênio","Oxigênio","Carbono","Hélio"}, 0},
    {"Qual a Meia-vida do C14(carbono-14)?", {"5730","2000","10000","4000"}, 0},
    {"Quem é o autor de Guerra e Paz ?", {"Tolstói","Kafka","Camus","King"}, 0},
    {"Qual a Capital da Turquia?", {"Istambul","Ancara","Antalya","Izmir"}, 1},
    {"Qual a equação da Reta geral?", {"ax+by+c=0","y=mx+b","x^2","y=a/x"}, 0},
    {"Quem criou a teoria da Relatividade?", {"Bohr","Einstein","Newton","Fermi"}, 1},
    {"Qual a Unidade de capacitância?", {"Ohm","Henry","Farad","Tesla"}, 2},
    {"O que DNA significa?", {"Nada","Ácido desoxirribonucleico","Proteína","Carboidrato"}, 1},
    {"Qual o Primeiro metal da tabela?", {"H","He","Li","Be"}, 2},
    {"Qual o Maior deserto do Mundo?", {"Saara","Atacama","Gobi","Antártica"}, 3},
    {"O que um Átomo é?", {"Indivisível","Partículas","Energia pura","Peixe"}, 1},
    {"Força =?", {"Massa*Velocidade","Massa*Aceleração","Trabalho","Pressão"}, 1},
    {"Onde Einstein nasceu ?", {"Suíça","Alemanha","EUA","Áustria"}, 1},
    {"Qual a Maior estrela conhecida?", {"Sol","UY Scuti","Sirius","Betelgeuse"}, 1},
    {"Quem fez a Tabela Periódica?", {"Einstein","Bohr","Mendeleev","Curie"}, 2},
    {"Qual a Unidade de energia física?", {"Watt","Newton","Joule","Pascal"}, 2}
};


void shuffle_int(int *a, int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }
}

/* ranking  */
void salvar(const char *nome, int valor) {
    FILE *f = fopen("ranking.txt", "a");
    if (!f) return;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(f, "%02d/%02d/%04d %02d:%02d - %s - R$ %d\n",
            tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, nome, valor);
    fclose(f);
}

void verRanking(void) {
    FILE *f = fopen("ranking.txt", "r");
    if (!f) { printf("Nenhum registro ainda.\n"); return; }
    printf("\n===== RANKING =====\n");
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) printf("%s", buf);
    fclose(f);
}

void limparRanking(void) {
    FILE *f = fopen("ranking.txt", "w");
    if (!f) { printf("Erro ao limpar ranking!\n"); return; }
    fclose(f);
    printf("Ranking apagado com sucesso!\n");
}

/*  ajudas */
void mostra_alternativas(Perg *q, int visivel[4]) {
    for (int j = 0; j < 4; ++j) {
        if (visivel[j]) printf("%d) %s\n", j+1, q->op[j]);
        else printf("%d) ---\n", j+1);
    }
}

void ajuda5050(Perg *q, int visivel[4]) {
    int erradas[3], e = 0;
    for (int j = 0; j < 4; j++) if (j != q->correta) erradas[e++] = j;
    // escolher duas erradas para esconder
    int hide1 = erradas[rand() % 3];
    int hide2;
    do { hide2 = erradas[rand() % 3]; } while (hide2 == hide1);
    for (int j = 0; j < 4; ++j) visivel[j] = 1;
    visivel[hide1] = 0;
    visivel[hide2] = 0;
}

void ajudaUniversitarios(Perg *q) {
    printf("Universitários sugerem: provavelmente a alternativa %d) %s\n", q->correta+1, q->op[q->correta]);
}

/* modos*/

void jogarClassico(const char *nome) {
    int idxF[N_BANK], idxM[N_BANK], idxD[N_BANK];
    for (int i = 0; i < N_BANK; ++i) { idxF[i] = i; idxM[i] = i; idxD[i] = i; }
    shuffle_int(idxF, N_BANK); shuffle_int(idxM, N_BANK); shuffle_int(idxD, N_BANK);

    Perg seq[N_ROUND];
    for (int i = 0; i < 5; ++i) seq[i] = bankF[idxF[i]];
    for (int i = 0; i < 5; ++i) seq[5+i] = bankM[idxM[i]];
    for (int i = 0; i < 5; ++i) seq[10+i] = bankD[idxD[i]];

    int premios[N_ROUND] = {100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000};

    int usado50 = 0, usadoPular = 0, usadoUniv = 0;
    int ganho = 0, seguro = 0;
    char linha[128];

    for (int i = 0; i < N_ROUND; ++i) {
        Perg *q = &seq[i];
        int visivel[4] = {1,1,1,1};

        printf("\nPergunta %d - R$ %d\n", i+1, premios[i]);
        printf("%s\n", q->texto);
        mostra_alternativas(q, visivel);

        printf("\nAjudas: %s %s %s\n",
               usado50 ? "(50/50 USADA)" : "(digite 50 para 50/50)",
               usadoPular ? "(Pular USADO)" : "(digite 99 para Pular)",
               usadoUniv ? "(Univ USADA)" : "(digite 88 para Universitários)");

        int resposta = -1;
        while (1) {
            printf("Resposta (1-4) ou código de ajuda: ");
            if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }
            linha[strcspn(linha, "\n")] = 0;

            if (strcmp(linha, "50") == 0) {
                if (usado50) { printf("50/50 já usada.\n"); continue; }
                usado50 = 1;
                ajuda5050(q, visivel);
                mostra_alternativas(q, visivel);
                continue;
            } else if (strcmp(linha, "99") == 0) {
                if (usadoPular) { printf("Pular já usado.\n"); continue; }
                usadoPular = 1;
                printf("Pergunta pulada (sem ganho, sem perda).\n");
                // pular: passa para próxima pergunta
                goto proxima_pergunta;
            } else if (strcmp(linha, "88") == 0) {
                if (usadoUniv) { printf("Universitários já usado.\n"); continue; }
                usadoUniv = 1;
                ajudaUniversitarios(q);
                continue;
            }

           
            char *endptr;
            long v = strtol(linha, &endptr, 10);
            if (endptr == linha || v < 1 || v > 4) {
                printf("Entrada inválida. Use 1-4 ou 50/99/88.\n");
                continue;
            }
            resposta = (int)v - 1;
            
            if (!visivel[resposta]) {
                printf("Alternativa não disponível (já removida pelo 50/50).\n");
                continue;
            }
            break;
        }

        if (resposta == q->correta) {
            ganho = premios[i];
            if (i+1 == SAFE1) { seguro = premios[SAFE1-1]; printf("Você alcançou o nível seguro 1: R$ %d\n", seguro); }
            if (i+1 == SAFE2) { seguro = premios[SAFE2-1]; printf("Você alcançou o nível seguro 2: R$ %d\n", seguro); }
            printf("Correto! Seu ganho atual: R$ %d\n", ganho);

            // perguntar se quer parar
            printf("Deseja parar e ficar com R$ %d? (s/n): ", ganho);
            if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }
            if (linha[0] == 's' || linha[0] == 'S') {
                printf("Você saiu com R$ %d\n", ganho);
                salvar(nome, ganho);
                return;
            }
        } else {
            printf("Errado! A resposta correta era: %s\n", q->op[q->correta]);
            int final = 0;
            if (i+1 > SAFE2) final = premios[SAFE2-1];
            else if (i+1 > SAFE1) final = premios[SAFE1-1];
            else final = 0;
            printf("Fim de jogo. Você ganhou R$ %d\n", final);
            salvar(nome, final);
            return;
        }

proxima_pergunta:
        ; 
    }

    // venceu todas as 15
    printf("\nPARABÉNS! Você venceu e ganhou R$ %d\n", ganho);
    salvar(nome, ganho);
}



/* Modo Relâmpago (10 perguntas, 10s cada)  */
void jogarRelampago(const char *nome) {
    printf("\n=== MODO RELÂMPAGO ===\n");
    printf("10 perguntas, sem ajudas, 10 segundos cada!\n\n");

    int premios[10] = {100,200,300,500,1000,2000,4000,8000,16000,32000};
    int ganho = 0;

    int idxF[N_BANK], idxM[N_BANK], idxD[N_BANK];
    for (int i=0;i<N_BANK;i++){ idxF[i]=i; idxM[i]=i; idxD[i]=i; }
    shuffle_int(idxF,N_BANK); shuffle_int(idxM,N_BANK); shuffle_int(idxD,N_BANK);

    Perg seq[10];
    for (int i=0;i<4;i++) seq[i] = bankF[idxF[i]];
    for (int i=0;i<3;i++) seq[4+i] = bankM[idxM[i]];
    for (int i=0;i<3;i++) seq[7+i] = bankD[idxD[i]];

    char linha[50];
    for (int i = 0; i < 10; i++) {
        printf("\nPergunta %d - R$ %d\n", i+1, premios[i]);
        printf("%s\n", seq[i].texto);
        for (int j = 0; j < 4; j++) printf("%d) %s\n", j+1, seq[i].op[j]);

        clock_t inicio = clock();
        printf("Resposta (1-4), 10s: ");
        if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }

        double tempo = (double)(clock() - inicio)/CLOCKS_PER_SEC;
        if (tempo > 10) {
            printf("Tempo esgotado!\nVocê saiu com R$ %d\n", ganho);
            salvar(nome, ganho);
            return;
        }

        int r = atoi(linha) - 1;
        if (r == seq[i].correta) {
            ganho = premios[i];
            printf("Correto!\n");
        } else {
            printf("Errado! Correto era %s\n", seq[i].op[seq[i].correta]);
            printf("Você saiu com R$ %d\n", ganho);
            salvar(nome, ganho);
            return;
        }
    }

    printf("\nVOCÊ COMPLETOU O MODO RELÂMPAGO!\nGanhou R$ %d\n", ganho);
    salvar(nome, ganho);
}

/* Modo Sobrevivência (errou 1 vez = acabou) */
void jogarSobrevivencia(const char *nome) {
    printf("\n=== MODO SOBREVIVÊNCIA ===\n");
    printf("Acerte o máximo que puder! Errou 1 vez = acabou.\n");

    int idxF[N_BANK], idxM[N_BANK], idxD[N_BANK];
    for(int i=0;i<N_BANK;i++){ idxF[i]=i; idxM[i]=i; idxD[i]=i; }
    shuffle_int(idxF,N_BANK); shuffle_int(idxM,N_BANK); shuffle_int(idxD,N_BANK);

    int posF=0, posM=0, posD=0;
    int total = 0;
    char linha[50];

    while (1) {
        Perg *q;
        if (total < 20) q = &bankF[idxF[posF++]];
        else if (total < 40) q = &bankM[idxM[posM++]];
        else q = &bankD[idxD[posD++]];

        printf("\nPergunta %d\n", total+1);
        printf("%s\n", q->texto);
        for (int j=0;j<4;j++) printf("%d) %s\n", j+1, q->op[j]);

        printf("Resposta: ");
        if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }
        int r = atoi(linha) - 1;

        if (r == q->correta) {
            total++;
            printf("? Acertou! Total: %d\n", total);
        } else {
            printf("? Errou! A correta era: %s\n", q->op[q->correta]);
            printf("Você acertou %d perguntas.\n", total);
            salvar(nome, total * 100); // score vira dinheiro
            return;
        }
    }
}

/* Modo Prática */
void jogarPratica() {
    printf("\n=== MODO PRÁTICA ===\n");
    printf("1) Fácil\n2) Médio\n3) Difícil\nEscolha: ");

    char linha[10];
    if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); return; }
    int op = atoi(linha);

    Perg *b;
    int tam = N_BANK;

    if (op == 1) b = bankF;
    else if (op == 2) b = bankM;
    else b = bankD;

    printf("\nModo prática iniciado. Digite 0 para sair.\n");
    while (1) {
        int i = rand() % tam;
        printf("\n%s\n", b[i].texto);
        for (int j=0;j<4;j++) printf("%d) %s\n", j+1, b[i].op[j]);

        printf("Resposta: ");
        if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }
        int r = atoi(linha);

        if (r == 0) return;
        if (r-1 == b[i].correta) printf("? Correto!\n");
        else printf("? Errado! Correto era %s\n", b[i].op[b[i].correta]);
    }
}

/* menu */
int main(void) {
    srand((unsigned)time(NULL));
    char nome[128];
    char linha[64];

    printf("Digite seu nome: ");
    if (!fgets(nome, sizeof(nome), stdin)) strcpy(nome, "Jogador");
    nome[strcspn(nome, "\n")] = 0;

    while (1) {
        printf("\nJOGO DO MILHÃO \n");
        printf("1) Modo Clássico\n");
        printf("2) Modo Relâmpago (tempo)\n");
        printf("3) Modo Sobrevivência\n");
        printf("4) Modo Prática\n");
        printf("5) Ver ranking\n");
        printf("6) Limpar ranking\n");
        printf("7) Sair\n");
        printf("Escolha: ");

        if (!fgets(linha, sizeof(linha), stdin)) { clearerr(stdin); continue; }
        int op = atoi(linha);

        if (op == 1) jogarClassico(nome);
        else if (op == 2) jogarRelampago(nome);
        else if (op == 3) jogarSobrevivencia(nome);
        else if (op == 4) jogarPratica();
        else if (op == 5) verRanking();
        else if (op == 6) limparRanking();
        else if (op == 7) { printf("Saindo... boa sorte!\n"); break; }
        else printf("Opção inválida.\n");
    }

    return 0;
}