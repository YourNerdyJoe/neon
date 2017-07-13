Neon GBA
========
A per tile light engine for the Gameboy Advanced by Joseph LoManto.

Wrote this about 3 years ago, finally fixed the palette generation and decided to release it.

How it works
============
palgen.exe generates a 256 color palette that includes every mixture of 3 different color lights (plus white).
Each tile stores hows "brightly" it's lit by each color light.
There's 4 brightness levels for each color and 2 for white (that's all that fits in the palette).
This determines the color of the tile on the light's background layer which is mixed with the main background using the gba's hardware alpha blending.

Also included a little trailing/fade-away effect for torches, fire, and things like that.

Feel free to use the code anyway you wish (zlib license so just don't claim it's yours).
Though it'll probably serve you better as a guide than an out-of-the-box library.

There is a simple OOLua-style wrapper for C hiding in there.
Probably the most useful piece of code in there and I don't even know why I wrote it.
