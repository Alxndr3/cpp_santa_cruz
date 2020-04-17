#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// Função para desenhar as linhas
void draw_line(int ponto1_x, int ponto1_y, int ponto2_x, int ponto2_y, ALLEGRO_COLOR cor_linha, int espessura_linha, int numero_linhas)
{
	for(int i = 0; i < numero_linhas; i++)
	{
		al_draw_line(ponto1_x, ponto1_y, ponto2_x, ponto2_y, cor_linha, espessura_linha);
		espessura_linha += 1;
		ponto1_x += 10;
		ponto2_x += 10;
		if(espessura_linha < 9) {
			ponto1_x += 10;
			ponto2_x += 10;
		}
		else if(espessura_linha >= 9) {
			ponto1_x += (10 + espessura_linha);
			ponto2_x += (10 + espessura_linha);
		}
		al_flip_display();
		al_rest(0.05);
	}
}

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
	// Quantidade de linhas a serem desenhadas
	int numero_linhas = 25;

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
	draw_line(ponto1_x, ponto1_y, ponto2_x, ponto2_y, cor_linha, espessura_linha, numero_linhas);
	// al_draw_line(ponto1_x, ponto1_y, ponto2_x, ponto2_y, cor_linha, espessura_linha);
	// Função para refresh e apresentação da tela
	al_flip_display();
	// Aguardar 3 segundos
	al_rest(tempo_exibicao);
	// Destruir o ponteiro para *tela do jogo;
	al_destroy_display(tela);

	return 0;
}
