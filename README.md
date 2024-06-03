
# cub3D

[![Watch the video](http://img.youtube.com/vi/35gA5YFIUJM/0.jpg)](http://www.youtube.com/watch?v=35gA5YFIUJM)

<a href="http://www.youtube.com/watch?v=35gA5YFIUJM" target="_blank">
    <img src="http://img.youtube.com/vi/35gA5YFIUJM/0.jpg" alt="Watch the video" width="240" height="180" border="10" />
</a>


## Summary
cub3D is a project inspired by the legendary Wolfenstein 3D game, renowned as the first FPS ever. It serves as an introduction to ray-casting, where your objective is to create a dynamic view inside a maze and navigate through it.

---

## Wolfenstein 3D
Developed by Id Software, with contributions from John Carmack and John Romero, Wolfenstein 3D marked the inception of the "First Person Shooter" genre in the gaming industry. With cub3D, you get to relive this historic moment in gaming history.

## Goals
The objectives of cub3D are to learn raycasting. As a graphics project, cub3D enhances your skills in windows, colors, events, and shape filling.

---

## Usage

Clone the git repository
```
git clone git@github.com:evan-ite/cub3d.git
```

Make the project
```
make bonus
```

Play one of the maps from the maps folder
```
./cub3D_bonus maps/hard.cub
```

### Example
A minimalist .cub scene needs 
- 4 .xpm texture files
- 2 RGB colors for floor and ceiling (F, C)
- A valid map surrounded by walls, 1 player and reachable X'es 
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000011100000000001
1000000000000000000100001
1000000000000000000100001
1000000000000000000100001
10000001D1111111111100001
1000000100000000000000001
100000010000E0000X0000001
1000000100000000000000001
1000000100000000000000001
1000000111D11110000000001
1000000100000010000000001
1000000100000010000000001
1000000100X00010000000001
1000000100000010000000001
1111111111111111111111111

```
---

## References

Minilibx: [https://github.com/42Paris/minilibx-linux]

---

## Acknowledgements
- Jan Strozyk
- Elise van Iterson

---

