# The Litte Rocket Space Graph Explorer
As an huge enthusiast of algorithms and graphics programming I decided to connect both of them and create one application that union those two fields of Computer Science. In such way idea for "The Litte Rocket Space Graph Explorer" appeared.
The-Little-Rocket-Space-Graph-Explorer is a program that visualise path founding algorithm in undirected graph. The algorithm used by The Little Rocket - main character of application - is The Depth First Search algorithm. For detailed description of algorithm see https://algs4.cs.princeton.edu/41graph/.

### Library used :
- Modern OpenGL
- GLFW
- GLM
- SOIL
- ASSIMP

### Things I have learned when making project :
- Basics of OpenGL
- Computer Graphics math algorithms
- Basics of Multithreaded Programming
- Design Patterns in practise
- Organising software architecture 
- Building and linking external libs
- **HOW PROGRAMMING IS AWESOME !!!** (although I have already known it :) )

## User Interface
User Interface is simulated via console and standard input/output. It reminds me about the first project which I was creating when I started to learn programming. Console User Interface asks about general application parameters needed to render a map for little rocket to search. Map represents undirected graph, such solution gives the flexibility for user to test algorithm on diffrent types of undirected graphs. Below you can see screenshot from user interface window. I am planning to improve it and use Qt framework in release 2.0.

![alt text](https://db3pap002files.storage.live.com/y4mDd8sPDQiH8DUNodxNTnTBTHbQrfm4ehhyz13KegRulZU99hb6P7K6voHaCnqK9jeUjItIDCLGtBzg93hyCi_MXWmM8f51iLSe6xpy8vLQmDzVtQrHAJtik8qJk_bWXgwjebjKjW4UDN1utCJNJDBcyaxJl_7zz_PRqUS6mglCGduNoyb_OHnvRR2KftPYZe0FtMx2GhUkxR8T2BT7dtIpQ/con_ui.jpg?psid=1&width=765&height=200)

## Visualisation
When the user will pass ui the application is launching it's main window with visualisation. It may takessome time due to loading of character model. After that procedure the camera is setted behind the model and follows moves of the little rocket. It is possible for user to manipulate camera using :

**W** - to move forward

**S** - to move backward

**A** - to move left

**D** - to move right

**ArrowUp** - to increase movement speed

**ArrowDown** - to decrease movement speed.

During visualisation nodes are colored. Green colored nodes indicate all visited nodes. When the rocket will reach the final node some of nodes are colored red, which indicates that those nodes belongs to the path found by algorithm. Below you can see screenshots which shows how does the application works.

![alt text](https://db3pap002files.storage.live.com/y4mVMvA3MaS0s8AWJgN2nFlNz1GL5VR9GCByFA7rGq-gguvMfIwW0mlFq8bIA3gXwDlRzeC00SSWSN9_fPoxpY-ymqQoSqJ4WNY20mIJ4pB8TUPwBkxlDhgE0js0kPGNypU5-QR-2LQANtm1nLY_Ck1VECEY0Vs4TNbM2VieG2V9XFzKnB1NmqOi5DnLUnLAk5Vj9-9PDA9oFnceojuuN1RAw/over1.jpg?psid=1&width=1202&height=832)

![alt text](https://db3pap002files.storage.live.com/y4mrA_TDyt3ZEU1hzaGixY3nXLo-2AZKty12kD1KkZW2qwuKCxx6kSmfFmOpI7QJf4qRtlxNpPvlLea6GTZgg9Rx1gp-teSHdOSv2xE6PMZ9zPaZ6NJdthjFLR956PtjOQGoxaLifDsPqswK1-6cXzdF1JwdkRs4FF5pEToqfSXvZiQUTX_YKGOIa9gWwfcd8z1tF3mgeyodx7QhQJg_2g6_g/over2.jpg?psid=1&width=1202&height=832)

![alt text](https://db3pap002files.storage.live.com/y4mR3YGpD5fh4cb71ekXalMtYHI9InEYEMVOBWLq4YI6wNnVDLkJD1V7IBDpENPYH5I74xZ7KcqLBJvPLJbhlr4UZ3vnySM7z4_OF7_A2GXvVW8p_aJlBgJa7srLCy2V7V0gCgT336qMPxPgsZ4xL_dY8hpDo_0SBFje15T-FXKjcXLNKUPQWYW8pXkzeS3DEXiD-ZS09jmpMjRTDHCqpMOTg/over3.jpg?psid=1&width=1202&height=832)

![alt text](https://db3pap002files.storage.live.com/y4mvKlQ1SysKxldRvMd6DrxgA4DITrSAc4oTEhKhwrHbd3qYGOHdLl0MgCxsSzcDdOkwXuG5jVSvxrLKbkw8nKaVbanPHks47R_BBsM6PWC2JBFSP5mG_7jKLf96wfYYFZZGi9LFLnrPRCevCZYxBKYhsxXbw8uQQ0eiwPfU_8OgapseUSc9njmTNBAaFu9599ffiScegILJMKT44ESbeK-4w/over4.jpg?psid=1&width=1202&height=832)

To close window and application press ESCAPE key.

## What next ?
If I will find a minute or two, I will improve some things in this project. Here are some ideas :
- Qt Framework will be used to create UI for receiving information about basic application parameters
- More algorithms of searching undirected graph will be visualised - ofcourse user will have a posibility to decide (Breath First Search, British Museum and more...)
- Directed and Weighted graphs with coresponding search algorithms will also appear (A*, Branch & Bound ...)
- Anything else that will nest in my head :)

### Bugs
I tried to write unit tests and test every aspect of application connected with graphics as good as I could. However, bugs may always appeare and I am well aware of that so feel free to inform me about any of them ;).
email : wjlazarski@gmail.com
