/*
COMPONENTES:
NOMES: FILIPE ABNER SOARES MELO
       NATA TEIXEIRA SANTOS DE OLIVEIRA
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define cliente 30
#define N_equip 4
#define qtd_chales 20
#define qtd_reserva 100

int editar_reserva (int codigo_reserva[qtd_reserva], int codigo_cliente[cliente], int periodo[qtd_reserva],
                     int pos_reserva, int aux_cod_cliente[qtd_reserva], int codigos_chale[qtd_chales], int verific_chales[qtd_reserva], int aux_cod_chale[qtd_reserva])
{


    int i, j, reserva_input, u = 1, input_new_codigo, get_state, qtd_dias, h, f, input_new_chale, arm, arm2;
    char resposta;

    printf("Digite o codigo da reserva: \n");
    scanf("%d", &reserva_input);


    for ( j = 0; j < qtd_reserva; j++)
    {
        if (reserva_input == codigo_reserva[j])
        {
            h = j;
            u++;
            break;
        }else
        {
            u = 1;
        }
    }
    if (u == 1)
    {
        printf("Codigo de Reserva Invalido \n");
        return 43;
    }

    printf("Deseja editar o codigo do cliente? (S-N)\n");
    scanf("\n%c", &resposta);

    if (resposta == 'S')
    {

        printf("Digite o novo codigo do cliente: \n");
        scanf("%d", &input_new_codigo);

        get_state = seach_cliente( codigo_cliente, input_new_codigo);


        if (get_state != 404)
        {
            aux_cod_cliente[codigo_reserva[h]] = input_new_codigo;

            printf("\nCodigo de cliente atualizado com sucesso. \n");

        }else
        {
            printf("\nCodigo de cliente invalido. \n");
            return 7;
        }
    }

    printf("Deseja editar o codigo do chale? (S-N)\n");
    scanf("\n%c", &resposta);

    if (resposta == 'S')
    {

        printf("Digite o novo codigo do chale: \n");
        scanf("%d", &input_new_chale);


        arm = search_chale(input_new_chale, codigos_chale, qtd_chales);

        if (arm != -1)
        {
            arm2 = search_chale (input_new_chale, verific_chales,qtd_chales);
            if (arm2 == -1)
            {

                verific_chales[h] = input_new_chale;
                printf("\nChale atualizado com sucesso.\n");


            }else
            {
                printf("\nChale ja resevado. \n");
                return 6;
            }

        }else
        {
            printf("\nCodigo de chale invalido.\n");
        }

    }

    printf("Deseja editar a quantidade de dias? (S-N)\n");
    scanf("\n%c", &resposta);

    if (resposta == 'S')
    {
    printf("Digite a nova quantidade de dias: \n");
    scanf("%d", &qtd_dias);

    periodo[codigo_reserva[h]] = qtd_dias;

    printf("\nQuantidade de dias atualizada com sucesso.\n");
    }


    return 98;
}

void pagar_reserva(int codigo_reserva[qtd_reserva],int verific_chales[qtd_reserva],int contador_reservas)
{
    int editor,i,n;
    printf("Digite o codigo da reserva para pagamento: \n");
    scanf("%i",&editor);
        for(i=0;i<contador_reservas;i++)
        {
            n=i;
            if(editor== codigo_reserva[i])
            {
                verific_chales[i]=1;
                printf("Pagamento realizado, Chale disponivel para Reserva novamente! \n");

                break;
            }
        }

        if(editor!=codigo_reserva[n])
        {
            printf("Codigo de Reserva invalido! \n");
        }

}


void buscar_reserva(int codigo_reserva[qtd_reserva],char nome[cliente][100],int codigos_chale[qtd_chales],int aux_cod_cliente[qtd_reserva],int aux_cod_chale[qtd_reserva],
                    int periodo[qtd_reserva],float valor_da_diaria[qtd_chales],float preco_equip[N_equip],int cod_chale_eq[qtd_chales], int verific_chales[qtd_reserva])
{
    int cod_r,i;
    printf("Digite o codigo da reserva: \n");
    scanf("%i",&cod_r);
    for(i=0;i<qtd_reserva;i++)
    {
        if(codigo_reserva[i]==cod_r)
        {

            printf("CODIGO DA RESERVA: %i\n",codigo_reserva[i]);


            printf("NOME DO CLIENTE: %s\n",nome[aux_cod_cliente[i]]);
            printf("CODIGO DO CHALE: %i\n",verific_chales[i]);
            printf("QUANTIDADE DE DIAS: %i \n",periodo[i]);
            if(cod_chale_eq[aux_cod_chale[i]]==0)
            {
                printf("VALOR TOTAL: %.2f \n",periodo[i]*valor_da_diaria[aux_cod_chale[i]]+preco_equip[0]);
            }
            else if(cod_chale_eq[aux_cod_chale[i]]==1)
            {
                printf("VALOR TOTAL: %.2f \n",periodo[i]*valor_da_diaria[aux_cod_chale[i]]+preco_equip[1]);
            }
           else if(cod_chale_eq[aux_cod_chale[i]]==2)
            {
                printf("VALOR TOTAL: %.2f \n",periodo[i]*valor_da_diaria[aux_cod_chale[i]]+preco_equip[2]);
            }
            else if(cod_chale_eq[aux_cod_chale[i]]==3)
            {
                printf("VALOR TOTAL: %.2f \n",periodo[i]*valor_da_diaria[aux_cod_chale[i]]+preco_equip[3]);
            }
            i=qtd_reserva+1;

        }
        else if(i==qtd_reserva-1)
        {
            printf("Codigo de Reserva Invalido \n");
            break;
        }

    }

}

int buscar_cliente(char nome[cliente][100],double telefone[cliente], int get_pos_nome[1])
{
    char n[100];
    int i;
    printf("Digite o nome do cliente: \n");
    scanf("\n%[^\n]s",&n);
    for(i=0;i<cliente;i++)
    {
        if(stricmp(nome[i],n)==0)
        {
            get_pos_nome[0] = i;
            return i;
        }
    }
return -1;
}

void listar_equipamentos(float equipamento[N_equip])
{

    printf("Ar-Condicionado: %.2f \n",equipamento[0]);
    printf("Ventilador De Teto: %.2f \n",equipamento[1]);
    printf("TV: %.2f\n",equipamento[2]);
    printf("Frigobar: %.2f\n",equipamento[3]);

}
int listar_chale(int chale[qtd_chales],float diaria[qtd_chales],int cont,char eq[N_equip],int cod_chale_equip[N_equip], int verific_chales[qtd_reserva] )
{
    int i, u = 1, l, s = 0, result, blu;

    for(i=0;i<cont;i++)
    {
        printf("\nCODIGO CHALE [%i]: %i \n",i+1,chale[i]);
        printf("DIARIA CHALE [%i]: %.2f \n",i+1,diaria[i]);

        if(cod_chale_equip[i]==0)
        {
            printf("EQUIPAMENTO CHALE [%i]: Ar-Condicionado\n",i+1);
        }
        else if(cod_chale_equip[i]==1)
        {
            printf("EQUIPAMENTO CHALE [%i]: Ventilador De Teto\n",i+1);
        }
        else if(cod_chale_equip[i]==2)
        {
            printf("EQUIPAMENTO CHALE [%i]: TV\n",i+1);
        }
        else if(cod_chale_equip[i]==3)
        {
            printf("EQUIPAMENTO CHALE [%i]: Frigobar\n",i+1);
        }



        for ( l = 0; l < 1; l++)
        {
            for ( s = 0; s < qtd_reserva; s++)
            {

                if ( verific_chales[s] == chale[i] )
                {
                    printf("\nreserva: Sim!.\n\n");
                    u++;
                    break;
                }
                else
                {
                    u = 1;
                }

            }

            if (u == 1)
            {
                printf("\nReserva: Nao!.\n\n");
                u = 1;
                break;
            }
        }

    }
    return 8;

}
void funcao_menu()
{
    printf("\n\n--------Menu do sistema---------\n");
    printf("\n====================================\n");
    printf("Digite o numero da opcao desejada: \n\n");
    printf("1. Cadastrar Cliente\n"); 
    // cadastrar usuario    ** maria  marco 300 if(nome1== nomen){ printf("nome ja existente");}
    // adicionar codigo da conta,valor da conta, 
    // atribuir valor da conta ao usuario ** 300 , 300 maria
    // pagar conta (codigo); if (2 contas == codigo){ printf("codigo ja existente");    }
    // listar informacoes do usario --> contas pagas e nao pagas, codigo das contas, valor, data de vencimento...
    //  printf("Para finaizar o programa, digite []\n");
    //
    printf("2. Editar Cliente\n");
    printf("3. Cadastrar Equipamento\n");
    printf("4. Cadastrar Chale\n");
    printf("5. Editar Chale\n");
    printf("6. Fazer Reserva\n");
    printf("7. Editar Reserva\n");
    printf("8. Efetuar pagamento de reserva\n");
    printf("9. Listar todos os equipamentos\n");
    printf("10. Listar todos os Chales:\n");
    printf("11. Buscar cliente por nome:\n");
    printf("12. Buscar reserva por codigo:\n");
    printf("Para finaizar o programa, digite [0]\n");
    printf("=====================================\n");
}
int seach_cliente(int codigo_cliente[cliente],int cod_cliente)
{
    int i;
    for(i=0;i<cliente;i++)
    {
        if(codigo_cliente[i]==cod_cliente)
        {
            return i;
        }

    }
     return 404;
}

int reservar_chale (int contador_reservas, char nome[cliente][100], int codigo_cliente[cliente], int codigos_chale[qtd_chales],
                    int periodo[qtd_reserva],  int chale_reservados[qtd_chales], int cod_cliente, int cod_chale, int codigo_reserva[qtd_reserva],
                    int pos_reserva, int verific_chales[qtd_reserva], int vetor_contador[1], int aux_vetor_cont[1],int aux_cod_cliente[qtd_reserva],int aux_cod_chale[qtd_reserva])

{
    int i, posicao_cliente, posicao_chale,result,result2,result3, pega_v;




    if (contador_reservas < qtd_reserva)
    {

        printf("Digite o codigo do cliente: \n");
        scanf("%i", &cod_cliente);

        result=seach_cliente(codigo_cliente,cod_cliente);
        i=result;
        aux_cod_cliente[pos_reserva] = codigo_cliente[i];

        if(result != 404)
        {



            printf("Digite o codigo do chale: ");
            scanf("%d", &cod_chale);

                result2=search_chale(cod_chale,codigos_chale,qtd_chales);

                aux_cod_chale[pos_reserva]=result2;

                    if(result2 != -1) // se codigo chale existe
                    {

                        result3=search_chale(cod_chale,verific_chales,qtd_reserva);

                        if(result3 == -1)
                        {
                            pega_v = pos_reserva;
                            codigo_reserva[pega_v] = pos_reserva;

                        verific_chales[pos_reserva]=cod_chale;

                        printf("Digite o periodo desejado(em dias): \n");
                        scanf("%d", &periodo[pos_reserva]);
                        printf("Codigo da Reserva: %i \n",codigo_reserva[pega_v]);
                        printf("Reserva efetuada com sucesso. \n" );


                        vetor_contador[0] = vetor_contador[0] + 1;
                        aux_vetor_cont[0] = vetor_contador[0];

                        pos_reserva++;
                        return pos_reserva;


                        }
                        else
                        {
                            printf("Chale ja Reservado! \n");
                        }
                    }
                    else
                    {
                        printf("Codigo de chale inexistente!\n");
                    }
        }
        else
        {
            printf("Codigo de Cliente Inexistente\n");
        }
    }
    else
    {
        printf("Limite de reservas atingido.\n");
    }
    return pos_reserva;
}


int search_chale(int editor,int chal[qtd_chales], int cont1)
{
    int i;
    for(i=0;i<cont1;i++)
    {
        if(chal[i]==editor)
        {
            return i;
        }
    }
    return -1;
}

void editar_chale (int codig_chale[qtd_chales], int cont, float valor_diaria[qtd_chales], int cod_chale_eq[N_equip], int codigo_temp[qtd_chales])
{
    int editor,result, result2, aux_eq, D, novo_temporario;
    char resp, resp2;

    printf("Digite o codigo do chale a ser editado: \n");
    scanf("%i", &editor);
    result = search_chale(editor,codig_chale,cont);

    if(result != -1)
    {

        printf("Digite o novo codigo do chale [%d]: \n", editor);
        scanf("%i", &novo_temporario);

        for ( D = 0; D < qtd_chales; D++)
        {
            if ( novo_temporario == codig_chale[D] )
            {

                printf("Codigo ja existe!\n ");
                return 90;
            }

        }

        codigo_temp[result] = novo_temporario;

        result2 = search_chale(editor,codigo_temp,cont);

        if(result2 == -1)
        {
            codig_chale[result] = codigo_temp[result];

            printf("Deseja editar o valor da diaria tambem? (S-N) \n");
            scanf("\n%c", &resp);

            if (resp == 'S')
            {
            printf("Digite o novo valor da diaria: \n");
            scanf("%f", &valor_diaria[result]);
            printf("Edicao efetuada com sucesso! \n");

            }

            printf("Deseja editar o equipamento tambem? (S-N) \n");
            scanf("\n%c", &resp2);

            if (resp2 == 'S')
            {
                printf("Digite o numero do novo equipamento: \n");
                scanf("%i", &aux_eq);

                if ( aux_eq >=0 && aux_eq < 4 )
                {
                    cod_chale_eq[result] = aux_eq;
                    printf("Edicao efetuada com sucesso! \n");
                }
                else
                {
                    printf("Opcao de equipamento invalida.\n");
                }
            }
        }
        else
        {
            printf("Codigo ja cadastrado anteriormente. \n");
        }
    }
    else
    {
        printf("Codigo nao encontrado. \n");
    }
}
int cadastrar_chale (int cod_chale[qtd_chales], float valor_d[qtd_chales], int cod_chale_eq[qtd_chales],
                     int cont)
{
    int i, codigo_digitado, aux_eq_cadastro;

    printf("Digite o equipamento desejado para o chale: \n\n");
    printf("Digite 0 para ar-condicionado: \n");
    printf("Digite 1 para ventilador de teto: \n");
    printf("Digite 2 para tv: \n");
    printf("Digite 3 para frigobar: \n");
    scanf("%d", &aux_eq_cadastro);

    if (aux_eq_cadastro >= 0 && aux_eq_cadastro < 4)
    {
        cod_chale_eq[cont] = aux_eq_cadastro;

    }
    else
    {
        printf("Opcao de equipamento invalida.\n");
        return cont;

    }

    printf("Digite o codigo do chale: \n" );
    scanf("%i", &codigo_digitado);



    for(i = 0; i < qtd_chales; i++)
    {
        if(codigo_digitado == cod_chale[i])
        {
        printf("Codigo ja em uso, tente novamente.\n");
        return cont;

        }
    }

        cod_chale[cont] = codigo_digitado;

        printf("Digite o valor da diaria: \n" );
        scanf("%f", &valor_d[cont]);
        printf("Chale Cadastrado Com Sucesso! \n");
        cont++;



    return cont;
}
void cadastrar_equip(float preco_equip[N_equip])
{
    printf("Digite o preco do Ar-Condicionado: \n");
    scanf("%f", &preco_equip[0]);
    printf("Digite o preco do Ventilador de Teto: \n");
    scanf("%f", &preco_equip[1]);
    printf("Digite o Preco do Tv: \n");
    scanf("%f", &preco_equip[2]);
    printf("Digite o preco do Frigobar: \n");
    scanf("%f", &preco_equip[3]);
    printf("EQUIPAMENTOS CADASTRADOS COM SUCESSO! \n\n");
}

void editar_cliente(int codigo_cliente[cliente], char nomep[cliente][100],double telf[cliente],int posicao)
{
    int nmr, a;
    char resposta;

        printf("Digite o Codigo do cliente que e necessaria edicao:\n");
        scanf("%i",&nmr);

        a = seach_cliente (codigo_cliente, nmr);

        if (a != 404)
        {
            if(nmr<=posicao)
            {

                printf("Deseja alterar o nome do cliente [%i]? (S-N)\n",nmr);
                scanf("\n%c",&resposta);

                if(resposta=='S')
                {
                    printf("Digite o novo nome do cliente [%i]: \n",nmr);
                    scanf("\n%[^\n]s",&nomep[nmr]);
                    printf("\nO nome do cliente foi alterado!\n");

                }else if(resposta=='N')
                {
                    printf("Sem alteracao no nome do cliente. \n");
                }

                printf("Deseja alterar o numero de telefone do cliente [%i]? (S-N)\n",nmr);
                scanf("\n%c",&resposta);

                if(resposta=='S')
                {
                    printf("Digite o novo numero de telefone: \n");
                    scanf("%lf",&telf[nmr]);
                    printf("\nAlteracoes Salvas!\n");
                }
                else if(resposta=='N')
                {
                    printf("Sem alteracao no numero de telefone. \n");
                }
            }
            else
            {
                printf("Resposta invalida.\n");

            }

        }else
        {
            printf("Codigo nao encontrado. ");
        }
}
void cadastrar_cliente(char nomep[cliente][100],double telf[cliente],int posicao, int codigo_cliente[cliente])
{

    printf("Digite o nome do cliente e seu telefone \n");

    codigo_cliente[posicao] = posicao;

    scanf("\n%[^\n]s",&nomep[posicao]);
    scanf("%lf",&telf[posicao]);
    printf("Codigo de cliente [%i]: \n",posicao);
    printf("Cliente Cadastrado!\n");
}

int main ()
{
    // Chale:
    int codigos_chale[qtd_chales] = {0}, cod_chale_eq[qtd_chales],y,posicao=0, codigo_cliente[cliente]={-1},chale_reservados[qtd_chales],codigo_reserva[qtd_reserva]={-1};
    float valor_da_diaria[qtd_chales],c[qtd_chales], preco_equip[N_equip] = {0};
    char eq[N_equip][20]={{"Ar-Condicionado"},{"Ventilador de Teto"},{"TV"},{"Frigobar"}};

    int i = 0, menu, b = 1, k=1, a=1, j=1, t=0, l=0;
    int cont = 0, contador_reservas = 0, periodo[qtd_reserva], posicao_reserva = 0, vetor_contador[1] = {50}, aux_vetor_cont[1] = {1};


    char nome[cliente][100]={'n'};
    double telefone[cliente];

    int cod_cliente_reservado, get_pos_nome[1], gama = 0;
    int cod_chale_desej_reservado;
    int codigo_temp[qtd_chales];
    int verific_chales[qtd_reserva] = {-50};
    int cod_chale_equip;
    int aux_cod_cliente[qtd_reserva];
    int aux_cod_chale[qtd_reserva];

    printf("\n");
    printf("====================================\n");
    printf("-BEM-VINDO A POUSADA MONTES QUENTES-\n");
    printf("====================================\n");
    printf("  ================================\n");
    printf("      ========================\n");
    printf("            ============\n");
    printf("                ====\n");
    do
    {

    funcao_menu(menu);
    scanf("%d", &menu);

    switch (menu)
    {

        case 1:

            if(posicao<cliente)
            {
                cadastrar_cliente(nome,telefone,posicao, codigo_cliente);
                posicao++;
            }
            else
            {
                printf("\nNao e possivel cadastrar mais que %i clientes \n",cliente);
                break;
            }

            break;
        case 2:
            if(nome[0][0]=='n')
            {
                printf("\nNao ha clientes cadastrados \n");
                break;
            }
            else
            {

                editar_cliente(codigo_cliente, nome,telefone,posicao);

            }

            break;
        case 3:
                    if(a==1)
                    {
                        cadastrar_equip(preco_equip);
                    }
                    else
                    {
                        printf("Nao e possivel cadastrar mais equipamentos! \n");
                        break;
                    }
                    a++;
            break;

        case 4:
        if(cont<qtd_chales)
        {
            if(preco_equip[0] != 0)
            {
                printf("Apos a Realizacao da reserva nao sera possivel editar os chales! \n\n");
                cont = cadastrar_chale (codigos_chale, valor_da_diaria, cod_chale_eq, cont);


            }
            else
            {
                printf("\nE necessario cadastrar os equipamentos.\n");
            }
        }
        else
        {
            printf("Maximo de Chales Cadastrados! \n");
        }
            break;

        case 5:
            if(t==1)
            {
                printf("Nao e possivel editar os chales apos a realizacao da reserva! \n");
                break;
            }
            if(codigos_chale[0] != 0)
            {
            editar_chale (codigos_chale, cont, valor_da_diaria, cod_chale_eq, codigo_temp);
            }
            else
            {
                printf("Nenhum chale cadastrado. \n");
            }


            break;

        case 6:
            if(nome[0][0]=='n')
                {
                    printf("Nao ha Clientes Cadastrados! \n");
                }
                else if(codigos_chale[0] == 0 )
                {
                    printf("Nao ha Chales Cadastrados! \n");
                }
                else if(cont<qtd_chales)
                {
                    printf("E necessario cadastrar Todos Chales antes de fazer uma reserva! \n");

                }
                else
                {

                    posicao_reserva=reservar_chale ( contador_reservas, nome,codigo_cliente, codigos_chale,periodo,chale_reservados,cod_cliente_reservado,
                                                    cod_chale_desej_reservado, codigo_reserva, posicao_reserva, verific_chales, vetor_contador, aux_vetor_cont,
                                                    aux_cod_cliente, aux_cod_chale);

                    t=1;

                    if (vetor_contador[0] == aux_vetor_cont[0])
                    {
                        contador_reservas++;

                        vetor_contador[0] = vetor_contador[0] + 5;
                    }else
                    {
                        printf("Reserva nao efetuada. ");
                    }




                }

            break;

        case 7:
            if(codigo_reserva[0]== -1)
            {
                printf("E necessario realizar uma reserva para realizar a edicao \n");

            }
            else
            {
            editar_reserva (codigo_reserva, codigo_cliente, periodo, posicao_reserva, aux_cod_cliente, codigos_chale,verific_chales, aux_cod_chale);
            }
            break;

        case 8:
            if(codigo_reserva[0]== -1)
            {
                printf("E necessario realizar uma reserva para efetuar o pagamento \n");

            }
            else
            {
                pagar_reserva(codigo_reserva,verific_chales,contador_reservas);
            }

            break;

        case 9:
            if(preco_equip[0] != 0)
            {
                listar_equipamentos(preco_equip);
            }
            else
            {
                printf("\nE necessario cadastrar os equipamentos.\n");
            }
            break;

        case 10:
            if(cont<1)
            {
                printf("E necessario cadastrar ao menos um chale");
            }
            else
            {
                listar_chale(codigos_chale,valor_da_diaria,cont,eq,cod_chale_eq, verific_chales);
            }

            break;

        case 11:

             if(nome[0][0]=='n')
            {
                printf("E necessario cadastrar ao menos um cliente! \n");
                break;
            }
            else
            {
                if(buscar_cliente(nome, telefone, get_pos_nome)==-1)
                {
                    printf("Nome de cliente invalido! \n");
                }
                else
                {
                    gama = get_pos_nome[0];
                    printf("NOME: %s\n",nome[gama]);
                    printf("TELEFONE: %.0lf\n",telefone[gama]);
                }

            }

            break;

        case 12:

            if(codigo_reserva[0]==-1)
            {
                printf("E necessario ter uma reserva para buscar reserva \n");
            }
            else
            {
                buscar_reserva(codigo_reserva,nome,codigos_chale, aux_cod_cliente, aux_cod_chale,periodo,valor_da_diaria,preco_equip,cod_chale_eq, verific_chales);
            }

            break;

        case 0:
            break;

        default:
            printf("Comando invalido, tente novamente.\n");
            break;
    }
    }while(menu != 0);
    return 0;
}
