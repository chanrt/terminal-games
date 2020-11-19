# terminal-games
A set of low-graphical games written wholly in C
TicTacToe, Aliens, Car racing, Obstacle avoidance, Pong, Free-running, Snake Game
Just an experiment on Game Dev using the primitive features of the C language

Files like chan_graphics.c or chan_init.c function as header files and were written by me. They are required for all games except
X_O

The dynamic games are extremely laggy, because they dont utilise the resources of the CPU
Since only one thread of execution is available, only one task in completed at a time
There are a lot of bugs, which haven't been eliminated
A lot of improvements could've been made, but weren't, since better paradigms of Game Dev were available.
