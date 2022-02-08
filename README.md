# Outlaw Bass 
Modern interpretation of the Electra MPC Outlaw Bass using an onboard DSP in place of analog modules.  Addresses the UI shortcomings of the original; effects can be changed out without the need to open the back of the guitar, all settings available from the front using display/encoder/buttons.
A digital guitar multi-effect onboard effects project made with Daisy seed and Arduino.  Based (Bassed?) on  jerry20091103/Daisy_Guitar_Pedal.  Using a PedalPCB Terrarium for the input/output buffers and power supply, adding I2C display and eeProm.

## Signal Path
The guitar signal path:
>Guitar Passive (Pickups-Vol/Tone) -> Input Buffer -> Input 0 of Daisy -> Daisy   
>-> Output 0 of Daisy -> Final Ouptut  

## Features
<ul>
  <li>A 128*64 Monochrome LCD (on my bass this is in the upper horn)</li>
  <li>10 presets controlled by encoder. (up and down)</li>
  <li>Each preset has 2 "effect slots", the user can insert any effects they like and arrange them in any order.</li>
  <li>Each effect's settings are set using encoders, one encoder for each slot, clicking the encoder cycles through the settings for the effect.</li>
  <li>Up to 6 parameters for each effect.</li>
  <li>Effect bypass for each slot is controlled by a 3 position toggle.</li>
  <li>Each effect has two sets of parameters (A & B) selected by the toggle.</li>
  <li>Easy UI navigation with four arrow keys and an enter button.</li>
  <li>All presets and options are stored in an external EEPROM chip.</li>
  <li>All control inputs are handled by interrupts.</li>
</ul>

## Controls
2 toggle switches, 2 pushbuttons, and 2 rotary encoders. 

## List of effects
<ul>
  <li>Pitchshifter</li>
  <li>Overdrive</li>
  <li>Fuzz</li>
  <li>Tremolo</li>
  <li>Ring Modulator</li>
  <li>BitCrusher</li>
  <li>Phase Shifter</li>
  <li>Chorus</li>
  <li>Flanger</li>
  <li>Envelope Follower Filter</li>
</ul>

## Dependencies
<ul>
  <li>My fork of <a href=https://github.com/jerry20091103/DaisyDuino>DaisyDuino</a></li>
  <li><a href=https://github.com/evert-arias/EasyButton>EasyButton</a></li>
  <li><a href=https://github.com/mathertel/RotaryEncoder>RotaryEncoder</a></li>
  <li><a href=https://github.com/olikraus/u8g2>u8g2</a></li>
  <li><a href=https://github.com/JChristensen/extEEPROM>extEEPROM</a></li>
</ul>
