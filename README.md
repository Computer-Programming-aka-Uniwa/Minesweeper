<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
</p>

---

<p align="center">
  <strong>Computer Programming</strong>
</p>

<h1 align="center">
  Minesweeper
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Nikolaos Vassilas, Professor<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/nikolaos-vassilas/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Georgios Meletiou, Laboratory Teaching Staff<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a>
</p>

</hr>

---

<p align="center">
  Athens, January 2022
</p>

---

<p align="center">
  <img src="https://minesweeper-pro.com/media/minesweeper-tutorial-2.png" width="250"/>
</p>

---

# README

## Minesweeper

A C-based utility that generates a **Minesweeper board** based on user-defined dimensions and bomb counts. The program calculates the proximity numbers for each cell and outputs the resulting board to both the console and a formatted text file.

---

## Table of Contents

| Section | Folder/File | Description |
|------:|-------------|-------------|
| 1 | `INSTALL.md` | Installation and setup instructions |
| 2 | `README.md` | Project overview and usage information |
| 3 | `assign/` | Assignment description and reference images |
| 3.1 | `assign/Minesweeper.png` | Minesweeper assignment image (English) |
| 3.2 | `assign/Ναρκαλιευτής.png` | Minesweeper assignment image (Greek) |
| 4 | `src/` | Source code and resources for the project |
| 4.1 | `src/boards/` | Predefined game boards for testing |
| 4.1.1 | `src/boards/board10x20x20.txt` | Board configuration (10x20 grid with 20 mines) |
| 4.1.2 | `src/boards/board5x4x6.txt` | Board configuration (5x4 grid with 6 mines) |
| 4.2 | `src/minesweeper.c` | Main C source code implementing the Minesweeper game |

---

## 1. Features

- **Dynamic Board Generation:** Allows custom rows (**M**), columns (**N**), and bomb count (**K**).
- **Proximity Logic:** Automatically calculates the number of adjacent bombs for every empty cell (8-neighbor adjacency).
- **Memory Management:** Uses dynamic heap allocation (`calloc`) with error handling and proper memory cleanup to prevent leaks.
- **Dual Output:**
  - Prints a formatted grid to **stdout**
  - Saves the board to a `.txt` file inside a `boards/` directory using a descriptive filename (e.g., `board10x10x15.txt`).

---

## 2. How It Works

### 2.1 Allocation
The board is created as a **2D pointer array (`int**`)** using dynamic memory allocation.

### 2.2 Bomb Placement
Bombs are randomly distributed across the grid using:

- `rand()`
- `srand(time(NULL))`

Bombs are represented internally with the value:
```bash
-1
```

### 2.3 Neighbor Calculation
For each bomb placed, the program scans its **3×3 neighborhood** and increments the values of surrounding non-bomb cells.

### 2.4 Cleanup
All dynamically allocated memory is released before program termination:

- Each allocated row is freed
- The main pointer array is freed