
# cub3D

## Summary
cub3D is a project inspired by the legendary Wolfenstein 3D game, renowned as the first FPS ever. It serves as an introduction to ray-casting, where your objective is to create a dynamic view inside a maze and navigate through it.

---

## Wolfenstein 3D
Developed by Id Software, with contributions from John Carmack and John Romero, Wolfenstein 3D marked the inception of the "First Person Shooter" genre in the gaming industry. With cub3D, you get to relive this historic moment in gaming history.

## Goals
The objectives of cub3D are to learn raycasting. As a graphics project, cub3D enhances your skills in windows, colors, events, and shape filling.

---

## Usage

### Example
A minimalist .cub scene:
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
---

## References


---

## Acknowledgements
- Jan Strozyk
- Elise van Iterson

---

## Current to-do
- invalid fd close() when texture file doesn't exist or is broke
- map considered invalid when player starts facing any direction other than North
- use strcmp to check texture files instead of just checking 1st letter
- ~~add player starting point and view angle to parser~~
- free all the stuff and fix a million leaks
- draw the rest of the owl

