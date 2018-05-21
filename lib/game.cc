#include "game.h"

Game::Game(const float &a_fps, const int &a_display_x, const int &a_display_y) {
  fps = a_fps;
  display_x = a_display_x;
  display_y = a_display_y;

  state = 0;
  initialize_allegro();
  world = new world::World("Cat room");
  manager = new Manager(world);
  // cat_handler = new DLHandler("bin/cat.so");
}

Game::~Game() {
  delete world;
  shutdown_allegro();
  // cat_handler->destroy(cat);
  // delete cat_handler;
}

void Game::initialize_allegro() {
  al_init();
  al_init_image_addon();
  al_install_keyboard();

  display = al_create_display(display_x, display_y);
  al_set_window_title(display, "Cat Room Escape");
  timer = al_create_timer(1.0 / fps);
  event_queue = al_create_event_queue();

  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_start_timer(timer);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_flip_display();
}

void Game::shutdown_allegro() {
  al_destroy_timer(timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
}

void Game::loop() {
  bool running = true;
  bool redraw = true;
  bool key[4] = { false, false, false, false };
  int speed = 4;

  while (running) {
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    switch (event.type) {
      case ALLEGRO_EVENT_KEY_DOWN:
        switch(event.keyboard.keycode) {
          case ALLEGRO_KEY_UP:
            key[KEY_UP] = true;
            break;
          case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN] = true;
            break;
          case ALLEGRO_KEY_LEFT:
            key[KEY_LEFT] = true;
            break;
          case ALLEGRO_KEY_RIGHT:
            key[KEY_RIGHT] = true;
            break;
          case ALLEGRO_KEY_W:
            key[KEY_UP] = true;
            break;
          case ALLEGRO_KEY_S:
            key[KEY_DOWN] = true;
            break;
          case ALLEGRO_KEY_A:
            key[KEY_LEFT] = true;
            break;
          case ALLEGRO_KEY_D:
            key[KEY_RIGHT] = true;
            break;
          case ALLEGRO_KEY_LSHIFT:
            speed = 16;
            break;
        }
        break;
      case ALLEGRO_EVENT_KEY_UP:
        switch(event.keyboard.keycode) {
          case ALLEGRO_KEY_ESCAPE:
            running = false;
            redraw = false;
            break;
          case ALLEGRO_KEY_UP:
            key[KEY_UP] = false;
            break;
          case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN] = false;
            break;
          case ALLEGRO_KEY_LEFT:
            key[KEY_LEFT] = false;
            break;
          case ALLEGRO_KEY_RIGHT:
            key[KEY_RIGHT] = false;
            break;
          case ALLEGRO_KEY_W:
            key[KEY_UP] = false;
            break;
          case ALLEGRO_KEY_S:
            key[KEY_DOWN] = false;
            break;
          case ALLEGRO_KEY_A:
            key[KEY_LEFT] = false;
            break;
          case ALLEGRO_KEY_D:
            key[KEY_RIGHT] = false;
            break;
          case ALLEGRO_KEY_LSHIFT:
            speed = 8;
            break;
        }
        break;
      case ALLEGRO_EVENT_TIMER:
        if(key[KEY_UP]) { manager->move(world->cat, 0, -1, speed); }
        if(key[KEY_DOWN]) { manager->move(world->cat, 0, 1, speed); }
        if(key[KEY_LEFT]) { manager->move(world->cat, -1, 0, speed); }
        if(key[KEY_RIGHT]) { manager->move(world->cat, 1, 0, speed); }

        redraw = true;
        break;
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        running = false;
        redraw = false;
        break;
      default:
        // std::cout << "Unsupported event received: " << event.type << std::endl;
        break;
    }

    if (redraw && al_is_event_queue_empty(event_queue)) {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      world->map->draw();

      al_flip_display();
      redraw = false;
    }
  }
}
