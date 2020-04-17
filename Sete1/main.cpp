#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
	const int Largura_t = 640; // Variáveis para resolução da tela 
	const int Altura_t = 480;

	ALLEGRO_DISPLAY *Tela; // Inicialização da Allegro Display

	al_init(); // Inicialização da biblioteca Allegro
	Tela = al_create_display(Largura_t, Altura_t); // Criação da tela 

	al_init_font_addon(); // Inicialização dos addons
	al_init_ttf_addon();

	ALLEGRO_FONT *fonteTitulo1_30 = al_load_font("orbitron-black.ttf", 30, 0); // Carrega as fontes
	ALLEGRO_FONT *fonteTitulo2_45 = al_load_font("orbitron-black.ttf", 45, 0); 
	ALLEGRO_FONT *fonteTitulo3_60 = al_load_font("orbitron-black.ttf", 60, 0);
	ALLEGRO_FONT *fonteTitulo4_75 = al_load_font("orbitron-black.ttf", 75, 0);
	ALLEGRO_FONT *fonteTitulo5_90 = al_load_font("orbitron-black.ttf", 90, 0);
	ALLEGRO_FONT *fonteTitulo6_110 = al_load_font("orbitron-black.ttf", 110, 0); 


	char titulo1 [50] = "PREPARE-SE...";
	char titulo2 [50] = "VOCE";
	char titulo3 [50] = "NUNCA";
	char titulo4 [50] = "VIU";
	char titulo5 [50] = "NADA";
	char titulo6 [50] = "IGUAL";
	
	ALLEGRO_COLOR corVermelho = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR corPreto = al_map_rgb(0, 0, 0);
	
	al_clear_to_color(corVermelho); // Primeira tela
	al_draw_textf(fonteTitulo1_30, corPreto, Largura_t/2 , Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo1);
	al_flip_display();
	al_rest(1.0);
	
	al_clear_to_color(corPreto); // Segunda tela
	al_draw_textf(fonteTitulo2_45, corVermelho, Largura_t/2, Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo2);
	al_flip_display();
	al_rest(0.5);

	al_clear_to_color(corVermelho); // Terceira tela
	al_draw_textf(fonteTitulo3_60, corPreto, Largura_t/2, Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo3);
	al_flip_display();
	al_rest(0.5);

	al_clear_to_color(corPreto); // Quarta tela
	al_draw_textf(fonteTitulo4_75, corVermelho, Largura_t/2, Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo4);
	al_flip_display();
	al_rest(0.5);
	
	al_clear_to_color(corVermelho); // Quinta tela
	al_draw_textf(fonteTitulo5_90, corPreto, Largura_t/2, Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo5);
	al_flip_display();
	al_rest(0.5);
	
	al_clear_to_color(corPreto); // Sexta tela 
	al_draw_textf(fonteTitulo6_110, corVermelho, Largura_t/2, Altura_t/2, ALLEGRO_ALIGN_CENTRE, "%s", titulo6);
	al_flip_display();
	al_rest(0.5);

	al_destroy_font(fonteTitulo1_30);
	al_destroy_font(fonteTitulo2_45);
	al_destroy_font(fonteTitulo3_60);
	al_destroy_font(fonteTitulo4_75);
	al_destroy_font(fonteTitulo5_90);
	al_destroy_font(fonteTitulo6_110);
	al_destroy_display(Tela);
}
