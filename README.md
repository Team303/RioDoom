# RioDoom

A Doom port for the NI RoboRIO to be used by FRC robots. It runs doom headlessly on a separate thread from main robot code, and renders to a camera stream. 

All the Doom code has been stolen from the official Doom source code release (https://github.com/id-Software/DOOM), and some small changes have been made to make it run on 64 bit and without X11.
## WAD Files

In order to run Doom, the engine needs the file that contains all the game data. This file is called `doom.wad`, and since it is part of the game's copyright, I can not include it in the git repository. I'm also *not* supposed to tell you that you can download the file from [here](https://github.com/Akbar30Bill/DOOM_wads).

Before running make sure a valid `doom.wad` file is in the `src/main/deploy` directory. To ensure the file you have is correct (there are many versions), I have included a checksum called `src/main/deploy/doom.wad.md5`. 