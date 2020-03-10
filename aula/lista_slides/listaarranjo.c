#include "listaarranjo.h"

void FLVazia(tLista *lista)
{
  lista->Ultimo = 0;
}

int Vazia(tLista *lista)
{
  return !lista->Ultimo;
}

void Insere(tItem *item, tLista *lista)
{
  if (!(lista->Ultimo <=  MAXTAM))
  {
    printf("ERRO!! lista possui apenas %d posições.",MAXTAM);
    exit(1);
  }

  lista->Item[lista->Ultimo] = *item;
  lista->Ultimo++;
}

void Retira(Posicao p, tLista *lista, tItem *item)
{
  if (p < 0 || p > lista->Ultimo)
  {
    printf("ERRO!! valor de entrada inválido. A lista adimite posições entre 0 e %d", lista->Ultimo);
    exit(1);
  }
  if (p == lista->Ultimo)
  {
    printf("Ultimo item da lista é retirado");
    lista->Ultimo--;
  }

  for (int i = p; i < lista->Ultimo; i++)
  {
    lista->Item[i] = lista->Item[i + 1];
  }
}

void Imprime(tLista *lista)
{
  if (Vazia(lista))
  {
    printf("Lista Vazia!!");
  }

  for (int i = 0; i <= lista->Ultimo; i++)
  {
    printf("(%d)", lista->Item[i].Chave);
  }
}

int Quantidade(tLista *lista){
  return lista->Ultimo+1;
}

void copiaLista(tLista *listaOrigem, tLista *listaDestino){   
  *listaDestino = *listaOrigem;
}

void partirLista(int p, tLista *listaOrigem, tLista *listaDestino){
  if(p<0 || p> listaOrigem ->Ultimo){
    printf("Impossível concluir partição. Posição não definida (%d)", p);
    exit(1);
  }

  for(int i =0;i<=p;i++){
    listaDestino->Item[i] = listaOrigem->Item[i+p];
  }
  listaDestino->Ultimo=p;
}

tItem Recupera(Posicao p, tLista *lista){
  return lista->Item[p];
}
