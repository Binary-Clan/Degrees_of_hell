# Degrees of Hell 💻🎲

### Introduction ⤵️

This a simple board game 🎲. This is not an interactive game 
you can play, but rather a simulation of two (or maybe more) players taking turns over a set number of rounds. 
Play is to be automated - there is no artificial intelligence, and no user input. All output will be text based and 
directed towards the console – there are no graphical elements to this assignment.
In the game, motivated students grind their way inexorably through a computing degree at Scumbag College*. 
Along the way they tackle assessments and have various other misadventures. Success means progression to 
the next year of the course. Lack of success risks dropping out or even worse - being stuck in a cycle of Mitigating 
Circumstances, endlessly repeating the year. Will any student graduate? Find out in “Degrees of Hell" 🧮

### Overview 🔖📑
Although there is no graphical element to the program, it may be helpful for you to think of the game as being 
played on a board comprising 36 spaces arranged in a circle.
Each of the spaces has a name (and some other information) which is contained within the data file degrees.txt.
In your simulation, the game should (initially) have two players. Player 1 is called Vyvyan, and player 2 is called 
Rick. At the start of the game, the pieces are placed on the “Welcome Week” space.
Players also have a year of study, a level of motivation, and a measure of success. Each player starts the game 
with their year = 1, motivation = 1,000 and success = 0. During the game, players are allowed to have negative 
motivation, but not negative success.
A game is played as a series of rounds. During a round, each player takes one turn to spin the spinner. You will 
represent spinning the spinner by generating a random number between 1 and 10 (using the code I have 
provided – see appendix). The player then moves their piece clockwise round the board by the number of spaces
indicated by the spinner.
Different things will happen according to the space landed on, which may result in the player gaining or losing 
motivation and/or success. Exactly what happens on each space depends on how many marks you want…
*Vyvyian, Rick, Neil and Mike were housemates and degree students at Scumbag College in the BBC sitcom The 
Young Ones in the 1980s.
