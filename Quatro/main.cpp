#include <allegro5/allegro.h>
#include <iostream>

using namespace std;

int main()
{
// Declaração de variáveis e constantes
int largura_tela = 640;
int altura_tela = 480;
int posicao_x = 300;
int posicao_y = 200;

const char titulo[] = "PROJETO QUATRO"; // Título cabeçalho

cout << "---------PROJETO QUATRO----------" << endl;
cout << "Autor: Alexandre Cardoso" << endl;
cout << "Data: 09/01/2020" << endl;

// Bloco principal do programa
cout << "Inicio do bloco principal" << endl;
ALLEGRO_DISPLAY *tela = NULL;

cout << "Inicia a biblioteca ALLEGRO" << endl;
al_init(); // Inicia a biblioteca

cout << "Declara a variável com a cor de fundo da tela" << endl;
ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 100, 0);

cout << "Cria a tela na memória" << endl;
tela = al_create_display(largura_tela, altura_tela); // Cria a tela com tamanho 640x480

cout << "Define o título da tela" << endl;
al_set_window_title(tela, titulo);

cout << "Define a posição da tela no monitor" << endl;
al_set_window_position(tela, posicao_x, posicao_y);

cout << "Define a cor do fundo da tela" << endl;
al_clear_to_color(cor_fundo);

cout << "Atualiza monitor e mostra tela criada." << endl;
al_flip_display();

cout << "Aguarda 5 segundo e fecha a tela." << endl;
al_rest(5.0);

cout << "Destrói a tela criada na memória";
al_destroy_display(tela);

cout << "Fim do bloco principal." << endl;

return 0;
}
