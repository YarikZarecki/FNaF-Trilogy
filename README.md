# FNaF Console Edition (C++)

A terminal-based survival horror game inspired by *Five Nights at Freddy's 3*, built entirely from scratch in C++. 

This project was developed to demonstrate low-level system mechanics and core computer science concepts in a practical environment, including:
* **Multi-threading:** Asynchronous timers and non-blocking terminal input.
* **State Machines:** Seamlessly managing game states, menus, and real-time Quick Time Events (QTE).
* **Custom Pathfinding & AI:** Entity tracking and dynamic movement logic for antagonists (Springtrap).

##  Requirements
* UNIX/Linux environment (Ubuntu, WSL, etc.)
* `g++` compiler with **C++17** support
* GNU `make`

##  Build & Run
To compile and play the game, clone the repository and use the provided `Makefile`.

1. **Build the project:**
   ```bash
   make
   ```

2. **Run the game:**

```bash
make run
```
(Alternatively, you can execute ./fnaf_game manually).

3. **Clean temporary build files:**

```bash
make clean
```
## License
All rights to the Five Nights at Freddy's franchise and original concepts belong to Scott Cawthon. This is a non-commercial fan project created for educational portfolio purposes.
