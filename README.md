# fract-ol

Mandatory part + Bonus part(one more different fractal,
zoom with actual mouse position,color range shift)

Tested on Linux

Success 115/100

<br>

## Project Description

This project is focused on the development of a robust graphical application utilizing the MiniLibX library to render and explore two classic fractals: the Julia set and the Mandelbrot set.<br>
This project seeks to combine mathematical theory with computer graphics to allow users to interactively explore fractal patterns, offering a deep dive into the visually complex world of fractals.<br>
<br>
Fractals are intricate structures that exhibit self-similarity across different scales, making them a fascinating subject for both mathematical research and visual computing.<br>
<br>
This project leverages the computational power of C programming and the graphical capabilities of MiniLibX to create an application that not only displays these fractals but also allows users to manipulate and explore them in real time.<br>
<br>


## Installation

```bash
  git clone https://github.com/sleepychloe/fract-ol.git
  cd Fract_ol
  make
```

if compile fails with message "can't find a suitable X11 include directory",
install it via

```bash
  sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

<br>

## Usage

```bash
  ./fractol Mandelbrot
  ./fractol Julia
  ./fractol Burning_ship
```

<br>

## Keys

```
╔════════════════════════════════╗
║       for every fractal        ║
╠═════════════╦══════════════════╣
║ SCROLL_UP   ║ zoom out         ║
║ SCROLL_DOWN ║ zoom in          ║
║ KEY_ESC     ║ exit             ║
║ KEY_C       ║ change color     ║
╠═════════════╩══════════════════╣
║         for julia set          ║
╠═════════════╦══════════════════╣
║ KEY_1       ║ real num: -      ║
║ KEY_2       ║ real num: +      ║
║ KEY_Q       ║ imaginary num: - ║
║ KEY_W       ║ imaginary num: + ║
╚═════════════╩══════════════════╝
```

<br>

## Screenshots
### Mandelbrot set
![image](https://user-images.githubusercontent.com/78352910/219778092-44a9892f-3d6e-4160-8365-fcb87b33ed4b.png)
![image](https://user-images.githubusercontent.com/78352910/219778255-1b5b0e43-f8a5-4fea-a400-63b282202dbb.png)
![image](https://user-images.githubusercontent.com/78352910/219778300-458f1ddb-7fb6-487f-84e4-7572c3e3e130.png)

<br>

### Julia set
![image](https://user-images.githubusercontent.com/78352910/219778380-beea6694-9601-437b-96ae-7abadab80849.png)
![image](https://user-images.githubusercontent.com/78352910/219778430-5e480cd8-07c8-402f-99a5-dfad144c9c4b.png)
![image](https://user-images.githubusercontent.com/78352910/219778472-87d5a847-f650-4ebd-a344-b43b31b0518e.png)
![image](https://user-images.githubusercontent.com/78352910/219778521-89dd14a1-60cd-48f0-aa36-d06ef97908d3.png)
![image](https://user-images.githubusercontent.com/78352910/219778909-c593e75c-897a-484b-9d2f-eca3b8e1cc0b.png)
![image](https://user-images.githubusercontent.com/78352910/219778957-435eeac7-9f1c-4a91-b723-1d73eb2277fc.png)
![image](https://user-images.githubusercontent.com/78352910/219779006-9ab3648d-a1ab-4c18-a1ea-7344bebdd159.png)
![image](https://user-images.githubusercontent.com/78352910/219779058-456fc5e3-2393-457a-9be7-8535f346e879.png)
![image](https://user-images.githubusercontent.com/78352910/219779098-42c0a50d-f43f-471f-acf0-b7945eb01b86.png)
![image](https://user-images.githubusercontent.com/78352910/219779152-2bc59329-79cc-4db3-a540-194e44ccd316.png)
![image](https://user-images.githubusercontent.com/78352910/219779212-78ce380a-354a-4ad9-b53f-bb09a7ab951d.png)
![image](https://user-images.githubusercontent.com/78352910/219779253-a3dae4d9-34c7-4428-8f3a-1e9aa52cb27a.png)
![image](https://user-images.githubusercontent.com/78352910/219779361-a5262918-96cc-47f1-b416-f06541aff3b7.png)
![image](https://user-images.githubusercontent.com/78352910/219779395-e7df6b85-e8f6-4c1a-9fce-65fcb40d053b.png)

<br>

### Burning ship
![image](https://user-images.githubusercontent.com/78352910/219779545-4fe65973-5ec9-448e-bb35-dfa0502af787.png)
![image](https://user-images.githubusercontent.com/78352910/231275881-2cab7059-1b94-4a0c-ad17-a231f5814f84.png)
![image](https://user-images.githubusercontent.com/78352910/219779654-15f9418b-7798-440d-9f64-44c80c178faf.png)
