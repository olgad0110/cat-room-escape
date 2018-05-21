#include "game.h"

Game::Game(const float &a_fps, const int &a_display_x, const int &a_display_y) {
  fps = a_fps;
  display_x = a_display_x;
  display_y = a_display_y;

  state = 0;
  world = new world::World("Cat room");
  // cat_handler = new DLHandler("bin/cat.so");
  // manager = new Manager();
}

Game::~Game() {
  delete world;
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

  tiles_bitmap = al_load_bitmap("images/tiles.png");
  cat_bitmap = al_load_bitmap("images/cat.png");

  al_start_timer(timer);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_flip_display();

  // std::string name;
  // int icon_number;
  // std::string icon;
  // std::string input;

  // std::cout << "Welcome to cat room escape!" << std::endl << std::endl;
  // std::cout << "What's your cat name? ";
  // std::cin >> name;

  // std::cout << "What's your cat icon? 1: 🐈   2: 🐅   3: 🐆   ";
  // std::cin >> icon_number;

  // if(icon_number == 1) { icon = "🐈"; } else
  // if(icon_number == 2) { icon = "🐅"; } else
  // if(icon_number == 3) { icon = "🐆"; } else { icon = "🐈"; }

  // cat = cat_handler->create(name, icon);

  // std::cout << std::endl << "Do you want to play? [Y/n] ";
  // do {
  //   std::cin >> input;
  //   if(input == "n") {
  //     state = 0;
  //   } else if(input == "Y") {
  //     state = 1;
  //   } else {
  //     std::cout << "[Y/n]" << std::endl;
  //   }
  // } while(!(input == "Y" || input == "n"));
}

void Game::shutdown_allegro() {
  al_destroy_timer(timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_bitmap(tiles_bitmap);
  al_destroy_bitmap(cat_bitmap);
}

void Game::loop() {
  bool running = true;
  bool redraw = true;
  bool key[4] = { false, false, false, false };
  int cat_x = 128;
  int cat_y = 128;

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
        }
        break;
      case ALLEGRO_EVENT_TIMER:
        if(key[KEY_UP]) { cat_y -= 8; }
        if(key[KEY_DOWN]) { cat_y += 8; }
        if(key[KEY_LEFT]) { cat_x -= 8; }
        if(key[KEY_RIGHT]) { cat_x += 8; }

        redraw = true;
        break;
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        running = false;
        redraw = false;
        break;
      default:
        std::cout << "Unsupported event received: " << event.type;
        break;
    }

    if (redraw && al_is_event_queue_empty(event_queue)) {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      for(int i = 0; i < world->map->grid_size_y; i++) {
        for(int j = 0; j < world->map->grid_size_x; j++) {
          if(world->map->grid[i][j]->name == "wall") {
            al_draw_bitmap_region(tiles_bitmap, 0, 0, 128, 128, 128*j, 128*i, 0);
          } else if(world->map->grid[i][j]->name == "wooden_floor") {
            al_draw_bitmap_region(tiles_bitmap, 128, 0, 128, 128, 128*j, 128*i, 0);
          }
        }
      }

      al_draw_bitmap_region(cat_bitmap, 128, 0, 128, 128, cat_x, cat_y, 0);

      al_flip_display();
      redraw = false;
    }
  }

  // std::string input;
  // std::string printable;

  // while(state == 1) {
  //   system("clear");

  //   std::cout << world->map->draw(cat);

  //   std::cout << std::endl << printable << std::endl;
  //   printable = "";

  //   std::cout << std::endl << "$ ";
  //   std::cin >> input;

  //   if(input == "q") {
  //     state = 0;
  //   } else if(input == "w") {
  //     cat->go_up(world);
  //   } else if(input == "s") {
  //     cat->go_down(world);
  //   } else if(input == "a") {
  //     cat->go_left(world);
  //   } else if(input == "d") {
  //     cat->go_right(world);
  //   } else if(input == "m") {
  //     printable = cat->meow();
  //   } else if(input == "r") {
  //     printable = cat_handler->reload();
  //   }
  // }
}
