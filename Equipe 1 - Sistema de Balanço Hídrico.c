/** Universidade Federal Rural do Semi�rido
    Disciplina: Algoritmos
    Curso: Bacharelado em Tecnologia da Informa��o
    Docente: Jarbas Vidal 
    Discentes: D�borah Assun��o da Silva Nunes
	           Djalma Medeiros Sobrinho
	           Dyego Magno Oliveira Souza
	           Victor Patrick Jales de Brito 								**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h> // Biblioteca para utilizar acentos
#define NDP 1 // Constante aplicada a Metodologia 2

void menu (void);
int ValidacaoTempo(int m, int a);
void Metodo1();
void EscreveCab1();
void EscreveCabecalho1(FILE *arq);
void EscreveArquivo1(FILE *arq, int dia_arq1, int mes_arq1, int ano_arq1, float UR_arq1, float B_arq1,
                    float V_2_arq1, float V_arq1, float ECA_arq1, float KP_arq1, float ETO_arq1);
void Metodo2();
void EscreveCab2();
void EscreveCabecalho2(FILE *arq);
void EscreveArquivo2(FILE *arq, int dia_arq2, int mes_arq2, int ano_arq2, float tmin_arq2, float tmax_arq2,
                     float tmed_arq2, float irrad_arq2,float irradc_arq2, float ETO_arq2);
void Metodo3();
void EscreveCab3();
void EscreveCabecalho3(FILE *arq);
void EscreveArquivo3(FILE *arq, char mes_arq3[], int ano_arq3, float temp_arq3, float i_Calor_arq3,
                     float ETP_arq3, float ETP_cor_arq3, float Fc_arq3, float expa_arq3);

int main ()
{
    setlocale(LC_ALL, ""); // Ir� configurar o uso de acentos de acordo com o idioma padr�o do S.O.
                           // LC_ALL faz refer�ncia � todos os aspectos da localiza��o
    int escolha;

    do {
        menu();

        printf("\nDigite sua escolha:\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                Metodo1();
                printf("\n");
                break;
            case 2:
                Metodo2();
                printf("\n");
                break;
            case 3:
                Metodo3();
                printf("\n");
                break;
            case 9:
                printf("\nFim do Programa\n\n");
                printf("====Universidade Federal Rural do Semi�rido====\n");
                printf("--------------------------------------------------\n");
                printf("Programa criado pelos alunos:\n");
                printf("\n- D�borah Assun��o");
                printf("\n- Dyego Magno");
                printf("\n- Victor Patrick");
                printf("\n- Djalma Medeiros");
                break;
            default:
                printf ("\nOpera��o inv�lida!\n\n");
        }
       } while (escolha != 9);

      printf("\n\n");

      system("pause");
      return 0;
}

void Metodo1()
{
    printf("\n\nM�TODO TANQUE CLASSE A\n");

    int dia, mes, ano, tempo, i, j, g;

    // Receber valores que estejam dentro do intervalo estabelecido
    printf ("\nDigite o dia:\n");
    do {
        scanf ("%d", &dia);
       } while ((dia > 31) || (dia <= 0));

    printf ("\nDigite o m�s:\n");
    do {
        scanf ("%d", &mes);
       } while ((mes > 12) || (mes <= 0));

    printf ("\nDigite o ano:\n");
    do {
        scanf ("%d", &ano);
       } while (ano <= 0);

    tempo = ValidacaoTempo(mes, ano);

    // Cria��o dos vetores que ser�o utilizados
    float V_2[tempo - dia], UR[tempo - dia], V[tempo - dia], ECA[tempo - dia],
          KP[tempo - dia], ETO[tempo - dia], B = 10;

    // Cria��o de uma vari�vel do tipo FILE para cria��o do arquivo que salvar� as informa��es
    // obtidas com o uso do programa. � necess�rio utilizar ponteiro pois o arquivo ser� constantemente
    // modificado
    FILE *arq = fopen("metodologia1.txt", "w+");

    if(arq != NULL) // Ir� testar se o arquivo foi aberto corretamente
    {

    EscreveCabecalho1(arq); //Fun��o que ir� escrever o cabe�alho no arquivo

    j = 0; // Vari�vel para auxiliar a percorrer todos os vetores criados
    
    int dias_totais[tempo - dia]; // Vari�vel para auxiliar na contagem dos dias no programa

    // Estrutura de repeti��o iniciada no valor da vari�vel dia que ir� percorrer
    // at� o valor da vari�vel tempo
    for (i = dia; i <= tempo; i++)
    {
        if (arq != NULL) // Ir� testar se o arquivo foi aberto corretamente
        {
            printf ("\nDigite a umidade relativa(UR): \n");
            scanf ("%f", &UR[j]);
            printf ("\nDigite a velocidade do vento(m/s):\n");
            scanf ("%f", &V_2[j]);
            printf ("\nDigite o ECA: \n");
            scanf ("%f", &ECA[j]);

            V[j] = V_2[j] * 86.4; // Velocidade recebe a express�o
			KP[j] = 0.482 + (0.024 * log(B)) - (0.000376 * V[j]) + (0.0045 * UR[j]); // KP recebe a express�o
            ETO[j] = ECA[j] * KP[j]; // ETO recebe a express�o
            
            system("cls || clear"); // Ir� limpar a tela do programa

            EscreveCab1(); // Ir� escrever o cabe�alho referente � tabela do m�todo 1
            
			// Atribui��o do valor de i ao vetor dia_totais com aux�lio da vari�vel j
			// para percorrer todos os vetores
			dias_totais[j] = i;  
			
			for(g = 0; g <= j; g++)
            {
                // Apresenta��o dos valores dos vetores relativos ao intervalo
                printf ("%d  |", dias_totais[g]);
                printf ("%d   |", mes);
                printf ("%d |", ano);
                printf ("%.2f  |", UR[g]);
                printf ("%.2f  |", B); // B � uma constante
                printf ("%.2f |", V_2[g]);
                printf ("%.2f |", V[g]);
                printf ("%.2f |", ECA[g]);
                printf ("%.2f|", KP[g]);
                printf ("%.2f         |\n", ETO[g]);
            }
            printf("\n\n");

            // Chamada da fun��o que ir� escrever os valores no arquivo
            EscreveArquivo1(arq, i, mes, ano, UR[j], B, V_2[j], V[j], ECA[j], KP[j], ETO[j]);

            j++;
        }
        else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }
    }
        fclose (arq); // Ir� fechar o arquivo ap�s todas as repeti��es
    }
    else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }
}

void Metodo2()
{
    printf("\n\nM�TODO HARGREAVES E SAMANI\n");

    int dia, mes, ano, tempo, i, j, g;

    // Receber valores que estejam dentro do intervalo estabelecido
    printf ("\nDigite o dia:\n");
    do {
        scanf ("%d", &dia);
       } while ((dia > 31) || (dia <= 0));

    printf ("\nDigite o m�s:\n");
    do {
        scanf ("%d", &mes);
       } while ((mes > 12) || (mes <= 0));

    printf ("\nDigite o ano:\n");
    do {
        scanf ("%d", &ano);
       } while (ano <= 0);

    tempo = ValidacaoTempo(mes, ano);

    // Cria��o dos vetores relativos ao valor da vari�vel tempo
    float temp_min[tempo - dia], temp_max[tempo - dia], temp_med[tempo - dia],
          irrad[tempo - dia], irrad_calc[tempo - dia], ETO[tempo - dia];

    // Cria��o de uma vari�vel do tipo FILE para cria��o do arquivo que salvar� as informa��es
    // obtidas com o uso do programa. � necess�rio utilizar ponteiro pois o arquivo ser� constantemente
    // modificado
    FILE *arq = fopen("metodologia2.txt", "w+");
    

    if(arq != NULL) // Ir� testar se o arquivo foi aberto corretamente
    {

    EscreveCabecalho2(arq); // Fun��o que ir� escrever o cabe�alho no arquivo

    j = 0; // Vari�vel para auxiliar a percorrer todos os vetores criados
    
    int dias_totais[tempo - dia]; // Vari�vel para auxiliar na contagem dos dias no programa

    // Estrutura de repeti��o iniciada no valor da vari�vel dia que ir� percorrer
    // at� o valor da vari�vel tempo
    for (i = dia; i <= tempo; i++)
    {
        if (arq != NULL) // Ir� testar se o arquivo foi aberto corretament
        {
            printf ("\nDigite a temperatura m�nima:\n");
            scanf ("%f", &temp_min[j]);

            printf ("\nDigite a temperatura m�xima:\n");
            scanf ("%f", &temp_max[j]);

            printf ("\nDigite a temperatura m�dia:\n");
            scanf ("%f", &temp_med[j]);

            printf ("\nDigite o valor da irradi�ncia:\n");
            scanf ("%f", &irrad[j]);

            irrad_calc[j] = irrad[j] / 28.9;

            ETO[j] = (0.0023 * irrad_calc[j] * pow(temp_max[j] - temp_min[j], 0.5) * (17.8 + temp_med[j]) * NDP);

            system("cls || clear");

            EscreveCab2(); // Ir� escrever o cabe�alho referente � tabela do m�todo 2
            
            // Atribui��o do valor de i ao vetor dia_totais com aux�lio da vari�vel j
			// para percorrer todos os vetores
			dias_totais[j] = i;

            for(g = 0; g <= j; g++)
            {
                // Apresenta��o dos valores dos vetores relativos ao intervalo
                printf ("\n%d   |", dias_totais[g]);
                printf ("%d   |", mes);
                printf ("%d |", ano);
                printf ("%.2f |", temp_min[g]);
                printf ("%.2f |", temp_max[g]);
                printf ("%.2f |", temp_med[g]);
                printf ("%.2f   |", irrad[g]);
                printf ("%.2f      |", irrad_calc[g]);
                printf ("%.2f|", ETO[g]);
            }
            printf("\n\n");

            // Chamada da fun��o que ir� escrever os valores no arquivo
            EscreveArquivo2(arq, i, mes, ano, temp_min[j], temp_max[j], temp_med[j], irrad[j], irrad_calc[j], ETO[j]);

            j++;
        }
        else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }
    }
        fclose (arq); // Ir� fechar o arquivo ap�s todas as repeti��es
    }
    else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }

    system("pause");
}

void Metodo3()
{
    printf("\nM�TODO THORNTHWAITE\n");

    float temp[12], ETP[12], Fc[12], i_Calor[12], expa[12], ETP_cor[12];
    int i, j, ano;
    char mes[12][5]={"jan", "fev", "mar", "abr", "mai", "jun", "jul", "ago", "set", "out", "nov", "dez"};

    printf ("\nDigite o ano:\n");
    do {
        scanf ("%d", &ano);
       } while (ano <= 0);

    // Cria��o de uma vari�vel do tipo FILE para cria��o do arquivo que salvar� as informa��es
    // obtidas com o uso do programa. � necess�rio utilizar ponteiro pois o arquivo ser� constantemente
    // modificado
    FILE *arq = fopen("metodologia3.txt", "w+");
    

    if(arq != NULL) // Ir� testar se o arquivo foi aberto corretamente
    {

    EscreveCabecalho3(arq); // Fun��o que ir� escrever o cabe�alho no arquivo

    // Calcula tudo que � necessario para obter a evapotranspira��o
    for(i = 0; i < 12; i++)
    {
        if (arq != NULL) // Ir� testar se o arquivo foi aberto corretament
        {
            printf("\nDigite a temperatura do m�s %d: \n", i+1);
            scanf("%f", &temp[i]);

			i_Calor[i] = 12 * pow(temp[i]/5, 1.514);
            expa[i] = ((6.75*0.0000001)*pow(i_Calor[i], 3)) - ((7.71*0.00001)*pow(i_Calor[i], 2)) + ((1.792*0.01)*i_Calor[i]) + 0.49239;
 
            if(temp[i] < 26.5)
            {
                ETP[i] = 16 * powf(10 * temp[i]/i_Calor[i],  expa[i]);
            }
            else
            {
                ETP[i]= -415.85 + (32.24*temp[i]) - (0.43*pow(temp[i], 2));
            }
 
            printf("\nDigite o Fator Corrigido: \n");
            scanf("%f", &Fc[i]);
 
            ETP_cor[i]= ETP[i]*Fc[i];
 
            system("cls || clear");
 
            // Imprime na tela a tabela
            EscreveCab3();
 
            for(j = 0; j <= i; j++)
            {
                printf ("\n %s/%d |", mes[j], ano);
                printf (" %.2f |", temp[j]);
                printf (" %.3f |", i_Calor[j]);
                printf ("  %.2f  |", ETP[j]);
                printf ("     %.2f    |", ETP_cor[j]);
                printf (" %.2f |", Fc[j]);
                printf (" %.3f |", expa[j]);
 
            }
         printf("\n\n");
 
            // Chamada da fun��o que ir� escrever os valores no arquivo
            EscreveArquivo3(arq, mes[i], ano, temp[i], i_Calor[i], ETP[i], ETP_cor[i], Fc[i], expa[i]);
        }
        else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }
    }
        fclose (arq); // Ir� fechar o arquivo ap�s todas as repeti��es
    }
    else
        {
            printf ("\nErro ao criar arquivo. Tente novamente");
        }

    system("pause");
}


// Fun��o para apresentar o menu do programa
void menu()
{
    printf ("----SISTEMA DE BALAN�O H�DRICO----\n\n");
    printf ("1 - M�TODO TANQUE CLASSE A\n");
    printf ("2 - M�TODO HARGREAVES E SAMANI\n");
    printf ("3 - M�TODO THORNTHWAITE\n");
    printf ("9 - SAIR\n");
}

//Fun��o para retornar o n�mero de dias correspondente ao m�s escolhido
int ValidacaoTempo(int m, int a)
{
    switch (m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: // Meses com 31 dias
            return (31);
            break;
        case 4: case 6: case 9: case 11: // Meses com 30 dias
            return (30);
            break;
        default: // Caso especial para Fevereiro
            if (a % 4 == 0 && (a % 400 == 0 || a % 100 != 0)) // Verifica��o para anos bissextos
            {
                return (29);
                break;
            }
            else
            {
                return (28);
                break;
            }
    }
}

void EscreveCab1()
{
    printf ("\nDIA |"); // Escrita do cabe�alho no programa
    printf ("M�S |");
    printf ("ANO  |");
    printf ("UR     |");
    printf ("B      |");
    printf ("V_2  |");
    printf ("V      |");
    printf ("ECA  |");
    printf ("KP  |");
    printf ("ETo (mm/dia) |\n");
}

void EscreveCabecalho1(FILE *arq)
{
    fprintf (arq, "\nDIA |"); // Escrita do cabe�alho no arquivo
    fprintf (arq, "M�S |");
    fprintf (arq, "ANO  |");
    fprintf (arq, "UR     |");
    fprintf (arq, "B   |");
    fprintf (arq, "V_2   |");
    fprintf (arq, "V |");
    fprintf (arq, "ECA |");
    fprintf (arq, "KP |");
    fprintf (arq, "ETo (mm/dia) |\n");
}

void EscreveArquivo1(FILE *arq, int dia_arq1, int mes_arq1, int ano_arq1, float UR_arq1, float B_arq1,
                    float V_2_arq1, float V_arq1, float ECA_arq1, float KP_arq1, float ETO_arq1)
{
    fprintf (arq, "%d   |", dia_arq1); // Escrita dos valores no arquivo
    fprintf (arq, "%d   |", mes_arq1);
    fprintf (arq, "%d |", ano_arq1);
    fprintf (arq, "%.2f |", UR_arq1);
    fprintf (arq, "%.2f |", B_arq1);
    fprintf (arq, "%.2f |", V_2_arq1);
    fprintf (arq, "%.2f   |", V_arq1);
    fprintf (arq, "%.2f      |", ECA_arq1);
    fprintf (arq, "%.2f|", KP_arq1);
    fprintf (arq, "%.2f|", ETO_arq1);
    fprintf (arq, "\n");
}

void EscreveCab2()
{
    printf ("\nDIA |"); // Escrita do cabe�alho no programa
    printf ("M�S |");
    printf ("ANO  |");
    printf ("MIN   |");
    printf ("MAX   |");
    printf ("MED   |");
    printf ("Qo(W/m2) |");
    printf ("Qo(mm/dia) |");
    printf ("ETO |");
}

void EscreveCabecalho2(FILE *arq)
{
    fprintf (arq, "\nDIA |"); // Escrita do cabe�alho no arquivo
    fprintf (arq, "M�S |");
    fprintf (arq, "ANO  |");
    fprintf (arq, "MIN   |");
    fprintf (arq, "MAX   |");
    fprintf (arq, "MED   |");
    fprintf (arq, "Qo(W/m2) |");
    fprintf (arq, "Qo(mm/dia) |");
    fprintf (arq, "ETO |\n");
}

void EscreveArquivo2(FILE *arq, int dia_arq2, int mes_arq2, int ano_arq2, float tmin_arq2, float tmax_arq2,
                     float tmed_arq2, float irrad_arq2,float irradc_arq2, float ETO_arq2)
{
    fprintf (arq, "%d   |", dia_arq2); // Escrita dos valores no arquivo
    fprintf (arq, "%d   |", mes_arq2);
    fprintf (arq, "%d |", ano_arq2);
    fprintf (arq, "%.2f |", tmin_arq2);
    fprintf (arq, "%.2f |", tmax_arq2);
    fprintf (arq, "%.2f |", tmed_arq2);
    fprintf (arq, "%.2f   |", irrad_arq2);
    fprintf (arq, "%.2f      |", irradc_arq2);
    fprintf (arq, "%.2f|", ETO_arq2);
    fprintf (arq, "\n");
}

void EscreveCab3()
{
    printf ("    Mes   |"); // Escrita do cabe�alho no programa
    printf ("   Tm  |");
    printf ("   i     |");
    printf (" ETp(mm) |");
    printf (" ETp_corr(mm) |");
    printf ("  Fc  |");
    printf ("   a   |");
}

void EscreveCabecalho3(FILE *arq)
{
    fprintf (arq, "    Mes   |"); // Escrita do cabe�alho no arquivo
    fprintf (arq, "   Tm  |");
    fprintf (arq, "   i     |");
    fprintf (arq, " ETp(mm) |");
    fprintf (arq, " ETp_corr(mm) |");
    fprintf (arq, "  Fc  |");
    fprintf (arq, "   a   |");
}

void EscreveArquivo3(FILE *arq, char mes_arq3[], int ano_arq3, float temp_arq3, float i_Calor_arq3,
                     float ETP_arq3, float ETP_cor_arq3, float Fc_arq3, float expa_arq3)
{
    fprintf (arq, "\n %s/%d |", mes_arq3, ano_arq3); // Escrita dos valores no arquivo
    fprintf (arq, " %.2f |", temp_arq3);
    fprintf (arq, " %.3f |", i_Calor_arq3);
    fprintf (arq, "  %.2f  |", ETP_arq3);
    fprintf (arq, "     %.2f    |", ETP_cor_arq3);
    fprintf (arq, " %.2f |", Fc_arq3);
    fprintf (arq, " %.3f |", expa_arq3);
}