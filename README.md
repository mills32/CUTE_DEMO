CUTE DEMO
---------

UPDATE JUN 2020: 
-Now updated to GBDK 2020 (by Zal0).

-Replaced Homer and Lisa with alien versions by me (Not so cute).

-Added a lot of scanline palette changes (so much cute).

-Added more cuteness to the chips scene and the transition window.

-The boat is now a "good ship lollipop"


With GBDK 2020, c code is faster and smaller, so I could add the extra functions without trouble. 


STORY
-----

Hi everyone, I was updating my shitty "second reality" demo for DMG and CGB, but I just got bored of it, so I started 
this one. This demo contains some of the code I was doing for second reality, for example the roto-zoom scene.

So this is "my" cute demo for the game boy color (Sorry DMG). I say "My" because I use some graphics and code created 
with help from a lot of people, so I hope everybody is in the credits :).

As my programming skills are not the best, and my math skills are way worst than the average human, (lowering my IQ 
score to 90), this demo is made just to be, or try to be, cute and colourful, and there are not a lot of clever 
tricks or code. 


THE CODE
--------

Using ASM was incredibly difficult for me, so I used the horrible, buggy, slow GBDK... Not so bad anymore in 2020!!, and I could add asm code inside c functions, (which is, in my opinion, the best way to do complex things on the game boy, because you get the best of both worlds... Thanks to the people in gbdev forums).

The CGB has an awesome feature called DMA transfer, which is used a LOT in this demo,(thanks again to to the people in gbdev).
This function transfers data to the video ram so fast, you can make little videos simulating everything, from a rotating 
object, a 3D road or a parallax effect. 

DMA transfer needs data to be aligned to 16 bit, but GBDK don't usually align data, so I had to tell the compiler to 
link the graphics data first, this way it always aligns the graphics, and then it stores the functions and everything 
else without disturbing the alignment :).

Custom ASM functions used:

	-DMA transfer: animates bkg tiles (rotating 2D objects, 3d tower and fake parallax). 
	-Change palette every scan line: for static backgrounds.
	-Displaying high colour images: the cute tortoise.
	-Carillon music player: a binary block (no source available), called from whatever bank it is stored.
	-Wait for STAT = 1 and STAT = 2: it was impossible to make the GBDK functions to do this properly.
	
The rest of the code is just c.

As I said before, they didn't install a math chip into my CPU when I was built, so math related stuff is the result of 
a LOT of boring hours (I mean, entire DAYS), trying to fit small things, and solving incredibly stupid mistakes I make...

	-Animal Sounds Toy: The cow goes "Moooo"...  
	-Peter: Ohh I now remember. 

Don't be mad if a lot of strange ways of doing things are present, and the source is a bit unreadable. 

I think I fixed all bugs, except for the last "L" sprite in the word "DENTAL" (Lisa scene), which suffers from the 
10 sprite per scanline limit, and I didn't know how to solve it without destroying the word.  


THE FINAL ROM
-------------

If you want to modify and compile the demo, now I cleaned it up and you can using gbdk 2020 by Zal0!.

When exporting graphics with gbtd and gbmb, you must change the defined arrays in .h files to "const", and copy all created files to graphics/src.

Roto_Map_Anim array was Generated With GBA utils. because gbmb did not support such a big map.

Also note there are some gfx that can't be generated straight forward from the .gbm and .gbr files, for example, the window
and parts of the final scene map, have to be set on top of the sprites manually, because GBMB does not export the 0x8_ properties.

I didn't plan the size, and just by chance it ended up being a 16 bank ROM (256 Kb).
GBDK bank management caused a lot of issues, most of the time, it would jump to random places if you try to wait too long 
while the game boy is reading code from banks 2 and beyond, so this made me change my code and use a lot of bank switching.

About RAM, It looks like the game boy has plenty of ram :). Most variables are located at the beginning, and there are 
some in the middle of WRA0, resulting in less than 1% of usage. 



RESOURCES
---------
Many graphics were drawn by me and a friend, I also used Blender to render animations for the DMA function. 

	-Remember brain... if an animation takes 16 frames to make a prefect loop, go back to frame 1 after drawing frame 15, 
	-Ok. 
	-Or was it frame 0? 
	-ERROR

This demo also uses graphics taken from the internet, some Simpson images (Not anymore), and also the more or less decent 
conversion of the music "Atomic Twist" by Jean-Jacques Perrey & Dana Countryman.
I didn't find the credits for everything, so if you created the fat cute rocket or the cute tortoise, tell me :).

The 3D tower scene was inspired by the youtube channel "Game_Hut" where they explain how a 3D fake tower was made for "Mickey mania" https://www.youtube.com/watch?v=gRzKAe9UtoU&t=37s.

CUTE DEMO was made just for learning purposes and FUN, no comercial use can be done from this.
At the end of CUTE DEMO you'll see a cute credits scene, containing all credits.

Hope you like it

Mills
	
