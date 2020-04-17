#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
	// Variáveis do jogo
	const int largura_tela = 640;
	const int altura_tela = 480;

	// Inicialização da Allegro Display
	ALLEGRO_DISPLAY *tela;

	// Iniciando a biblioteca da Allegro
	al_init();

	// Criando a tela
	tela = al_create_display(largura_tela, altura_tela);
	// Define a cor de fundo da tela
	al_clear_to_color(al_map_rgb(10, 0, 0));
	
	// Inicialização de addons
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *size_16;
	ALLEGRO_FONT *size_32;
	// Carrega as fontes nas variáveis
	size_16 = al_load_font("orbitron-black.ttf", 16, 0);
	size_32 = al_load_font("arial.ttf", 32, 0);

	// ESCRITA NA TELA
	// Escreve a primeira frase
	al_draw_text(size_32, al_map_rgb(128, 0, 0), 150, 50, 0, "Olá Pessoal!!");
	// Apresenta a frase na tela
	al_flip_display();
	// Aguarda 3 segundos
	al_rest(3.0);
	// Escreve a segunda frase
	al_draw_text(size_16, al_map_rgb(128, 50, 30), 150, 100, 0, "Tudo bem com vocês?");
	// Atualiza a tela
	al_flip_display();
	al_rest(3.0);

	// Destroi a tela
	al_destroy_display(tela);
	// Destroi as fontes
	al_destroy_font(size_16);
	al_destroy_font(size_32);
}
