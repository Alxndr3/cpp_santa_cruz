#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
	// define um ponteiro para a Tela do jogo
	ALLEGRO_DISPLAY *Tela = NULL;
	al_init();
	// cria a Tela de interface para o jogo e define o tamanho da Tela (640, 480)
	Tela = al_create_display (640, 480);
	// define um titulo para a tela
	al_set_window_title (Tela, "Jogo Teste");
	// define a cor de fundo para a Tela, neste caso :verdade
	al_set_window_position (Tela, 0, 0);
	//Definir a posição da janela na tela
	al_clear_to_color (al_map_rgb (0, 100, 0));
	// apresenta a tela no monitor
	al_flip_display();
	// aguarda 2 segundos e depois fecha a tela
	al_rest(2.0);
	// destroi o ponteiro referente a tela
	al_destroy_display(Tela);
	// retorna 0 para o SO. indicando que tudo deu certo
	return 0;
}
