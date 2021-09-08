# SO_LONG

:books: [Introduction](#introduction)
 
:world_map: [Concept map](#how-it-works)
 
:footprints: [Step by step](#step-by-step)

:joystick: [Time to play](#time-to-play)

:receipt: [Installation](#installation)


## :books: Introduction
The SoLong proyect aims to learn about:
- graphic interface (MinilibX)
- windows, colors, events, textures, sprites...

The result is a 2D game where the player`s goal is to pick up all the collectibles present on the map before escape with the least amount of movements. 
>In my case, Bob-Omb needs to collect all the flames and capture the flag, but it won't be easy because he may run into some Ice-Ombs who will prevent him from exploding.






This top-down view game must follow some *rules*.

#### File rules (main.c/check_file)
- [x] The executable so_long must receive at least one argument, a map.
- [x] The map is a .ber file

In case the executable receives more than one argument my game will work with the first one.

#### Map rules (main.c/check_map)
- [x] There're only 5 possible characters: 0 (empty), 1 (wall), C (collectible), E (exit) and P (player). (There's an exception if enemies are added as bonus)
- [x] The map must be surrounded by walls.
- [x] There's must be at least one exit, one collectible and one player.
- [x] All the rows must have the same length (map is rectangular)

Here's an example of a correct map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
The moment one parsing error pops up, the program must exit and return "Error\n" followed by a message (error_exit.c/printf_error).

#### Game rules
- [x] The W, A, S and D keys will be used to move the main character. (Arrow keys also work)
- [x] Pressing ESC must close the window and quit the program cleanly.
- [x] Cliking on the red cross on the window's frame must close the window and quit the program cleanly.
- [x] Player cannot move into walls.
- [x] Player must pick all the collectibles to unlock the exit.


## :world_map: Concept map
Here you can see a map of how my files are organised in case you want to check some of my code :)
![concept_map](https://user-images.githubusercontent.com/71781441/132043927-31c57166-0ef5-45bd-ab61-9de53ebc99af.jpg)


## :footprints: Step by step

### Step 1: Creating the map
After checking the file, I read the map line by line using get_next_line and saved it in a two-dimensional array (map.c/read_map). Then I checked that everyting is okey with the map at the same time I filled the t_charac struct (map.h/check_map_characters) with some information such as number of collectibles, exits, players...

### Step 2: Initializing the game
I started by initializing the structs needed (t_img and t_game (init_t_structs)) to default values. The t_img struct includes the image identifiers and generate the t_list structs used later for animations. Secondly, the t_game struct includes everything need for the game: identifier of the window and of the connection between the software an the display, player's initial position, player's number of moves, the t_img and t_map structs created before ...
Right after the main fucntions of this proyect are called:
```c
mlx_loop_hook(g.mlx_ptr, ft_reset, (void *)&g);
mlx_hook(g.win_ptr, 17, 0, ft_exit, (void *)&g);    
mlx_key_hook(g.win_ptr, ft_key_hook, (void *)&g);
mlx_loop(g.mlx_ptr);
```
They are essential because they generate the infinite loop where all the events happen and they have the hooks (i.e. functions that gets called whenever an event is triggered) as parameters.

### Step 3: Hooks and events
| FUNCTION | HOOKS TO THE...  | DESCRIPTION  |
| :------: | :--------------: | :----------: |
| `ft_reset` | Loop |This function is hooked to the loop so it renders every frame, meaning it cleans the whole image and print the updated map|
| `ft_exit` | Red cross |This function ends the game when the red cross on the window's frame is clicked |
| `ft_key_hook` | Key | This function handle player's direction depending on the key pressed|

Basically every time one of the following keys W,S,D,A or arrow keys is pressed the program checks if the player can move to the new tile. If the move is possible the tilemap is updated and one move is added to the score.

### Step 4: Enemies and animations


## :joystick: Time to play
Remember you have to catch the flag with minimal movements and avoid at all costs to be reached by Ice-Omb. RUN!!

(add gifs/videos of the game + makefiles rules to play)


## 	:receipt: Instalation

### MiniLibX (Linux)
```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```
You can find more detailed information [here](https://github.com/42Paris/minilibx-linux).

## Manuals


