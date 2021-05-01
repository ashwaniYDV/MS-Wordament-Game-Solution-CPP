## MS-Wordament-Game-Solution-CPP

### How it works?
Preprocessing is done by generating a TRIE data structure by reading corncob_lowercase.txt which contains meaningful English words. \
Then a normal DFS is done on the input 2D grid and words are compared with our generated TRIE to check meaningful words which can be generated using the input grid.

## Compilation of Source Code
Compile the source code using the following command:
```
g++ game.cpp -o game
```
## Running the application
Run the application using the following command:
```
./game
```
