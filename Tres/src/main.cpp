#include <allegro5/allegro5.h>

int main()
{
	// define um ponteiro para a Tela do jogo
	ALLEGRO_DISPLAY *Tela = NULL;
	// Inicializa a biblioteca do Allegro5
	al_init();
	// cria a Tela de interface para o jogo e define o tamanho da Tela (640, 480)
	Tela = al_create_display(720, 640);
	// define um titulo para a tela
	al_set_window_title(Tela, "Jogo Teste");
	// define a cor de fundo para a Tela, neste caso :verdade
	al_set_window_position (Tela, 0, 0);
	// Define a tela como fullscreen
	al_set_display_flag (Tela, ALLEGRO_FULLSCREEN_WINDOW, 1);
	// define a cor do fundo da tela par verde
	al_flip_display();
	al_clear_to_color (al_map_rgb(0, 100, 0));
	//apresenta a tela do jogo no monitor
	al_flip_display();
	//aguarda 2 segundo
	al_rest(2.0);
	al_clear_to_color (al_map_rgb (100, 000, 0));
	al_flip_display();
	al_rest(2.0);
	al_clear_to_color (al_map_rgb (000, 000, 100));
	al_flip_display();
	al_rest(2.0);
	// destroi o ponteiro referente a tela
	al_destroy_display(Tela);
	// retorna 0 para o SO. indicando que tudo deu certo

	return 0;
}
