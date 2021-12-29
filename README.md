# USB-midi-fader
A simple to build USB midi controller

<p><p><h2> Motivation </h2> </p>
I have been browsing the net for an easy to use USB Midi controller which can be used with my mixing software  <a href='https://mixxx.org'>Mixxx</a>  to be able to mix podcasts on the go. Initially I wanted to buy an off the shelf product from Korg, the <a href='https://www.korg.com/de/products/computergear/nanokontrol2/'>Nanokontrol 2</a>, but they raised their prices to 69€. That's honestly not a lot for a product this powerful, but what if I tell you that I can make it at home for less? Let's say 54€ less? Yes, I paid 15€ for the stuff (without the Arduino clone i already had). Read it on my blog <a href='https://quiescentcurrent.com/blog/post.php?p_id=69'>here</a>.<br>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211229_122932.jpg" alt="" /> Finished fader.</p>

<p><h2> Specifications </h2> </p>

The has a few interesting features, mainly that it can easily be programmed in the Arduino IDE. The LEDs are all separately addressable, which makes them writeable via the computer interface. All switches including the big red one are also connected to the <a href='https://www.tindie.com/products/petl/breadboard-arduino-uno-clone//'>Breadboard Arduino clone</a>.  It doesn't need an external power supply or anything else.  
<ul>
<li>4x 30mm Slider Potentiometers with custom knobs. </li>
<li>7x individually addressable LEDs</li>
<li>1x red/green dual color 10mm LED for RX/TX</li>
<li>1x main switch, software controlled.</li>
<li>3x buttons</li>
<li>3x DPST switches </li>
<li>micro USB to serial connection.</li>
</ul> 


<p><h2> Hardware </h2> </p>
The hardware was partly lasercut, and partly 3D printed. The lasercutter is a cheap chinese 40W one with a pair of really expensive <a href='https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=762#2534'>thorlabs safety goggles</a>. I used 4mm acrylic glas and grey PLA filament. The fader knobs are pink PLA. <br>
In total the stuff cost me around 15€, including the Arduino clone it would be around 33€. <br><br>

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-cly1{text-align:left;vertical-align:middle}
.tg .tg-lboi{border-color:inherit;text-align:left;vertical-align:middle}
.tg .tg-78by{background-color:#E6E6FF;text-align:left;vertical-align:middle}
.tg .tg-qd3n{background-color:#E6E6FF;border-color:inherit;text-align:left;vertical-align:middle}
.tg .tg-7h26{color:#00E;text-align:left;text-decoration:underline;vertical-align:top}
.tg .tg-0lax{text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-qd3n">Name</th>
    <th class="tg-qd3n">Pcs</th>
    <th class="tg-qd3n">Price</th>
    <th class="tg-78by">Total</th>
    <th class="tg-78by">URL</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-lboi">Switch DPST</td>
    <td class="tg-lboi">4</td>
    <td class="tg-lboi">1.29</td>
    <td class="tg-cly1">5.16</td>
    <td class="tg-7h26"><a href="https://www.conrad.at/de/p/tru-components-kippschalter-250-v-ac-2-a-2-x-ein-ein-rastend-1-st-2304637.html">https://www.conrad.at/de/p/tru-components-kippschalter-250-v-ac-2-a-2-x-ein-ein-rastend-1-st-2304637.html</a></td>
  </tr>
  <tr>
    <td class="tg-lboi">Switch red</td>
    <td class="tg-lboi">1</td>
    <td class="tg-lboi">3.3</td>
    <td class="tg-cly1">3.3</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/312093751996">https://www.ebay.at/itm/312093751996</a></td>
  </tr>
  <tr>
    <td class="tg-lboi">Button switch</td>
    <td class="tg-lboi">3</td>
    <td class="tg-lboi">0.59</td>
    <td class="tg-cly1">1.77</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/223587573763">https://www.ebay.at/itm/223587573763</a></td>
  </tr>
  <tr>
    <td class="tg-lboi">Slider Potentiometer</td>
    <td class="tg-lboi">4</td>
    <td class="tg-lboi">0.89</td>
    <td class="tg-cly1">3.56</td>
    <td class="tg-7h26"><a href="https://www.conrad.at/de/p/tru-components-f3031n-schiebe-potentiometer-10-k-mono-0-1-w-linear-1-st-1567032.html">https://www.conrad.at/de/p/tru-components-f3031n-schiebe-potentiometer-10-k-mono-0-1-w-linear-1-st-1567032.html</a></td>
  </tr>
  <tr>
    <td class="tg-lboi">LED 5mm</td>
    <td class="tg-lboi">7</td>
    <td class="tg-lboi">0.02</td>
    <td class="tg-cly1">0.14</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/124214363745">https://www.ebay.at/itm/124214363745</a></td>
  </tr>
  <tr>
    <td class="tg-cly1">LED 10mm</td>
    <td class="tg-cly1">1</td>
    <td class="tg-cly1">1.26</td>
    <td class="tg-cly1">1.26</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/323443837179">https://www.ebay.at/itm/323443837179</a></td>
  </tr>
  <tr>
    <td class="tg-cly1">Resistor 220 Ohm</td>
    <td class="tg-cly1">3</td>
    <td class="tg-cly1">0.07</td>
    <td class="tg-cly1">0.21</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/372813822157">https://www.ebay.at/itm/372813822157</a></td>
  </tr>
  <tr>
    <td class="tg-cly1">Resistor 1k Ohm</td>
    <td class="tg-cly1">6</td>
    <td class="tg-cly1">0.07</td>
    <td class="tg-cly1">0.42</td>
    <td class="tg-7h26"><a href="https://www.ebay.at/itm/372813822157">https://www.ebay.at/itm/372813822157</a></td>
  </tr>
  <tr>
    <td class="tg-0lax">Screw M3x20 & M3 inserts</td>
    <td class="tg-0lax">4</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">Screw M2.5x6</td>
    <td class="tg-0lax">8</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-cly1">Breadboard BB UNO</td>
    <td class="tg-cly1">1</td>
    <td class="tg-cly1">18</td>
    <td class="tg-cly1">18</td>
    <td class="tg-7h26"><a href="https://www.tindie.com/products/petl/breadboard-arduino-uno-clone/">https://www.tindie.com/products/petl/breadboard-arduino-uno-clone/</a></td>
  </tr>
</tbody>
</table><p align="right"> Bill of materials. </p>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/Render_v1_crop.png" alt="" />Rendering of the case and frontplate.</p>



<h3>Frontplate:</h3>

Luckily SolidWorks can directly export to a .dxf file. This format can be read via the K40 Whisperer software and cut on the lasercutter. I avoided adding any markings on the acrylic, because it looks cleaner this way. Also I couldn't think of anything useful to add, feel free to let me know. 

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211228_152942_crop.jpg" alt="" /> Lasercut frontplate.</p>

The parts all fit perfectly, the LEDs are glued in with a drop off general purpose glue. Don't use Cyanoacrylate glue, it will destroy the acrylic. 

<h3>Case:</h3>
I had to print the case in two parts as my 3D printer would have been too small otherwise. I glued it together with Cyanoacrylate glue, which works surprisingly well. It has four pillars for the M3 inserts, which can be put in with a soldering iron and a steady hand. The opening in the back perfectly fits the micro USB port. the print is quite easy to do for most 3D printers and should be doable with almost all materials. I used colorFabb PLA, grey for the case and pink for the sliders. The sliders have a black stripe in the middle as it looks nice. On the bottom are four 11mm diameter cutouts for 10x4mm rubber feet, this gives the case a better feeling. <br><br>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211229_112011.jpg" alt="" /> 3D printed case with Arduino clone already mounted.</p>


<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211229_151829_crop.jpg" alt="" /> Pink sliders with black stripe.</p>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211229_105410.jpg" alt="" /> Rubber feet on the bottom of the case.</p>

<h3>Schematics:</h3>
All of the connections were soldered directly onto the parts. The current limiting resistors are on the back of the LEDs, the blue ones got 220 Ohm due to their higher forward voltage, the others 1k Ohm. There is a ground rails going all around the back and the sliders also have +5V connected on top. The Arduino clone I had lying around was a perfect fit, as it has all IOs in two rows. <br><br>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/USB_midi_fader_schematics.png" alt="" /> Schematics.</p>


<p><h2> Software </h2> </p>

As most Arduino clones don't have a dedicated USB microcontroller, I opted for a virtual Midi port. This means that the CH340 on my clone opens a virtual COM port on my machine and an additional software converts it into a Midi port. The software used for this is called <a href='https://projectgus.github.io/hairless-midiserial/ '>hairless Midi</a> and works like a charm directly out of the box. It has a Windows, Mac and Linux version, so no stress there. 

<h3>Code:</h3>
Coding wise this project is as simple as it gets. I wrote it as a long loop so it can be easily modified also by non coding people. Just take a look at the <a href='https://github.com/petl/USB-midi-fader '>github</a> page and scroll through. 

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/Screenshot%20from%202021-12-29%2015-30-50.png" alt="" /> Screenshot of the code.</p>

<h3>Mixxx:</h3>

Mixxx is quite chill about different midi inputs. I used the learning wizard to choose the controls I wanted to be controlled by the USB midi controller. It took a couple of minutes to have all the buttons, switches and sliders mapped onto the right elements. Afterwards everything worked like a charm and Mixxx saved my settings in a nice file. <br><br>

<p align="right"><img style="max-width: 100%;" src="https://github.com/petl/USB-midi-fader/blob/main/pictures/Screenshot%20from%202021-12-29%2016-39-31.png" alt="" /> Screenshot with Mixxx and hairless midi.</p>

<p><h2> Conclusion </h2> </p>So that's that, I hope this guide didn't get too long. The text is copied from my blog <a href='https://quiescentcurrent.com/blog/post.php?p_id=69'>here</a>. Thanks to the original <a href='https://www.instructables.com/DIY-USB-Midi-Controller-With-Arduino-a-Beginners-G/'>tutorial</a> I was loosely following.  If you have any questions or feedback just write a message or leave a comment on the <a href='https://quiescentcurrent.com/blog/post.php?p_id=69'>blog post</a>. <3 <br><br>

<p align=\"right\"><img style=\"max-width: 100%;\" src=\"https://github.com/petl/USB-midi-fader/blob/main/pictures/IMG_20211229_122905.jpg\" alt=\"\" />Less glamorous shot of the final product.</p>
</p>            
