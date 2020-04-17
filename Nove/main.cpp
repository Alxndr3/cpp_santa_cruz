#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// Função principal
int main()
{
	// Variáveis de dimensões da tela
	int tela_largura = 800;
	int tela_altura = 600;

	// Variável e tempo de exibição
	float tempo_exibicao = 5.0;

	// Variáveis da linha
	// Ponto 1 da linha
	int ponto1_x = 10;
	int ponto1_y = 10;
	int ponto2_x = 10;
	int ponto2_y = 50;
	// Espessura da linha
	int espessura_linha = 1;

	// Inicialização da Allegro5 e do Display
	ALLEGRO_DISPLAY *tela = NULL;
	al_init();

	// Inicialização dos addons de instalaçao
	al_init_primitives_addon();
	// Variáveis da cor da linha e da cor do fundo
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR cor_linha = al_map_rgb(0, 0, 0);

	// Criar a tela do joco com as dimensões definidas nas variáveis
	tela = al_create_display(tela_largura, tela_altura);
	// Função que define a cor de fundo da tela
	al_clear_to_color(cor_fundo);

	// Função que desenha a linha
	al_draw_line(ponto1_x, ponto1_y, ponto2_x, ponto2_y, cor_linha, espessura_linha);
	// Função para refresh e apresentação da tela
	al_flip_display();
	// Aguardar 3 segundos
	al_rest(tempo_exibicao);
	// Destruir o ponteiro para *tela do jogo;
	al_destroy_display(tela);

	return 0;
}
