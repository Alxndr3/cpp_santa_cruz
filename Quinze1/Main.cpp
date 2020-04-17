#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

void caixas_de_mensagens(ALLEGRO_DISPLAY *display) {

	char caixa_titulo [] = "Projeto QUINZE";

	if(al_show_native_message_box(display, caixa_titulo, "Pergunta: ", "Deseja exibir a mensagem de erro?",
			NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
	{
		al_show_native_message_box(display, caixa_titulo, "Então...","Estou exibindo a mensagem de erro",
				NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	else
	{
		al_show_native_message_box(display, caixa_titulo, "Então", "Vamos com essa mensagem de dúvida",
				NULL, ALLEGRO_MESSAGEBOX_QUESTION);
	}
	if(al_show_native_message_box(display, caixa_titulo, "Outra pergunta...", "Vou exibir uma ultima mensagem antes de sair, certo?",
			NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL) == 1)
	{

		al_show_native_message_box(display, caixa_titulo, "Eh a ultima mensagem, prometo!", "FIM DA SEQUENCIA COM OK", NULL,
				ALLEGRO_MESSAGEBOX_WARN);
	}
	else
	{
		al_show_native_message_box(display, caixa_titulo, "Eh a ultima mensagem, prometo!", "FIM DA SEQUENCIA COM CANCEL", NULL,
				ALLEGRO_MESSAGEBOX_WARN);
	}
}

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	al_init();

	al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(0, 100, 0));
	al_flip_display();
	al_show_native_message_box(display, "Projeto QUINZE", "TESTES COM CAIXAS DE DIALOGO", "Pressiona OK para continuar.",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);

	caixas_de_mensagens(display);

	al_rest(2.0);
	al_destroy_display(display);

	return 0;
}
