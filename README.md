<h1>SCOP</h1><br />
<br />

<h2>Description</h2>

This project is an introduction to OpenGL. The objective is to create an app capable of rendering 3D wavefront obj file, and of applying them textures by using C and OpenGL.<br/>

Subject: [here](./fr.subject.pdf)<br/>

<h2>Installation</h2><br />
<br />

Requirements: `OpenGL version >= 3.3`.<br/>

You must install the following dependency : `glfw 3.3.2`.</br>

</br>

`make install_glfw`<br />
`make`<br />
<br />

You can now run scop. :)
</br>

<h2>Optionnal Parameters</h2><br />


`-v or --version :` Set OpenGL version. Default: 4.1. Available versions: 3.3, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6 <br/>
`-w or --width <int> :` Set the window width. (min: 320, max: 15360) <br/>
`-h or --height <int> :` Set the window height. (min: 240, max: 8460)<br/>
`-f or --fullscreen :` Fullscreen mode.<br/>
`-t or --texture <name_texture> :` Set the texture by typing the name of the file you want to use (the texture must be in .bmp format and in contents/textures folder).<br/>
`--r or --refresh-rate <int> :` Overwrite refresh rate (MIN:24, MAX: 240, Default: Monitor refresh rate)<br/>

<h2>Mandatory Parameters</h2><br />

`obj`: Path to Wavefront .obj file<br/>

<h2>Controls</h2><br />

Basic keys:<br/>
    - `Escape`: Quit the program.<br/>
    - `Mouse`: Use left click to change cam position.<br/>
    - `ZQSD & Arrow keys`: Move object.<br/>
    - `Scroll`: zoom/unzoom<br/>
Texture & color keys:<br/>
    - `t`: Activate texture<br/>
    - `KP 1 to 3`: Set texture map algo: cubic, spheric, cylindrical<br/>
    - `KP 4 to 6`: Set color type<br/>
    - `KP 7`: Use obj vt mapping<br/>
    - `KP 8`: Flip custom texture<br/>
    - `KP 9`: Use custom texture<br/>
    - `k`: Use default kitty texture<br/>
Special keys:<br/>
    - `KP *`: Sleep rotation<br/>
    - `r`: Reset cam & object positions<br/>

<h2>Examples</h2> <br/>

- without vt mapping in obj file:<br/>
`./scop Contents/Resources/obj/teapot2.obj`<br/>

<img src="screenshots/teapot_face.png"
     alt="teapot faces screenshot"
     style="float: left; margin-right: 10px;" />
<br/>

You can press `t` to apply a kitty texture using texture mapping algorithms (can be changed with KP 1 to 3). You can for example use a smooth texture like `bronze.bmp` to get a better render!<br/>

<img src="screenshots/teapot_kitty.png"
     alt="teapot kitty screenshot"
     style="float: left; margin-right: 10px;" />
<br/>

- With vt mapping in obj file:<br/>
`./scop Contents/Resources/obj/backpack.obj -t diffuse.bmp`, Then press `t` to activate texture, then `KP 7` to use vt mapping described in the obj file, then `KP 8` to flip the texture (some obj need the texture to be flipped.).<br/>

<img src="screenshots/backpack.png"
     alt="backpack vt screenshot"
     style="float: left; margin-right: 10px;" />
<br/>

<h2>Grade</h2>

`125/100`