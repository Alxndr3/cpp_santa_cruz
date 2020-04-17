#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
	const int largura_tela = 1000;	// Variáveis do jogo
	const int altura_tela = 800;
	char autor[30] = "Alexandre Cardoso";
	int projeto = 6;
	char assunto[50] = "Fontes e Textos";

	ALLEGRO_DISPLAY *tela; // Inicialização da Allegro5 display
	al_init(); // Iniciando a biblioteca Allegro5
	
	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255); // Criação das variáveis com cores
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 100, 0);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR preto = al_map_rgb(0, 0, 0);

	tela = al_create_display(largura_tela, altura_tela); // Criando a tela
	al_clear_to_color(cor_fundo); // Define a cor de fundo da tela
	
	al_init_font_addon(); // Inicialização de Addons
	al_init_ttf_addon();

	ALLEGRO_FONT *size_16;
	ALLEGRO_FONT *size_32;
	ALLEGRO_FONT *size_56;

	size_16= al_load_font("orbitron-black.ttf", 16, 0); // font loading
	size_32= al_load_font("arial.ttf", 32, 0);
	size_56= al_load_font("orbitron-black.ttf", 56, 0); 

	//Escrita na tela #al_draw_text#
	al_draw_text(size_32, azul, 150, 50, 0, "Ola Pessoal!"); // Escreve a primeira frase
	al_flip_display(); // Apresenta na tela
	al_rest(2.0); // Aguarda 1 segundo

	al_draw_text(size_16, vermelho, 150, 100, 0, "Tudo bem com vocês?");
	al_flip_display(); // Atualiza a tela 
	al_rest(2.0);

	al_draw_textf(size_16, azul, 250, 150, ALLEGRO_ALIGN_RIGHT, "Este é o %d projeto", projeto); // Escreve a terceira frase com variável inteira
	al_flip_display();
	al_rest(2.0);

	al_draw_textf(size_16, vermelho, 150, 200, ALLEGRO_ALIGN_LEFT, "Meu nome é %s", autor);
	al_flip_display();
	al_rest(2.0);

	al_draw_textf(size_56, preto, 300, 300, ALLEGRO_ALIGN_CENTER, "%s", assunto);
	al_flip_display();
	al_rest(2.0);

	al_destroy_display(tela);
	al_destroy_font(size_16);
	al_destroy_font(size_32);
}
