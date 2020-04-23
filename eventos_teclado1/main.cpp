#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>


int main() {
	int tela_largura = 800;
	int tela_altura = 600;
	bool continuar = true;

	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
	ALLEGRO_EVENT event;
	ALLEGRO_DISPLAY *tela = NULL;
	// Inicialização da Allegro5
	al_init();
	// Inicialização dos Addons
	al_init_primitives_addon();
	al_install_keyboard();
	// Geração da tela
	tela = al_create_display(tela_largura, tela_altura);
	// Cria fila de eventos
	fila_eventos = al_create_event_queue();
	// Registrar os tipos de eventos que queremos captar na fila de enventos criada logo acima
	// **Neste caso estamos indicando que qualquer tecla pressionada será capturada na fila de eventos
	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	// Define cores
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR cor_quadrado = al_map_rgb(0, 255, 0);
	// Limpa tela e apresenta cor de fundo
	al_clear_to_color(cor_fundo);
	// Desenha retângulo
	al_draw_rectangle(20, 20, 50, 50, cor_quadrado, 2);
	// Apresenta tela
	al_flip_display();

	// Loop principal
	while(continuar) {
		al_wait_for_event(fila_eventos, &event);
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				continuar = false;
				std::cout << "A tecla Esc foi pressionada" << std::endl;
				std::cout << "Este Loop será encerrado!" << std::endl;
			}
		}
	}
	// Destrói os ponteiros criados para evitar o consumo desnecessário de memória
	al_destroy_display(tela);

	return 0;
}
