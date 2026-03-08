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

# INSTALL

## Minesweeper

This guide explains how to set up, build, and run the project on your local machine.

---

## 1. Usage

### 1.1 Prerequisites

- A **C compiler** such as `gcc` or `clang`
- A directory named **boards** in the same folder as the executable (for saving generated boards)

---

## 2. Compilation

```bash
gcc -o minesweeper_gen main.c
```

---

## 3. Execution
### 3.1 Create output directory if it does not exist
```bash
mkdir -p boards
```

### 3.2 Run the program
```bash
./minesweeper_gen
```

---

## 4. Input Example
```bash
====== INPUT ======
Enter dimensions of minesweeper board
Rows(M)    : 10
Columns(N) : 10
Enter number of bombs
Bombs(K)   : 15
```

---

## 5. Important Notes
The program currently uses `scanf` for input. Only integer values should be entered to avoid undefined behavior.
Ensure the number of bombs satisfies:
```bash
K < M × N
```
If `K ≥ M × N`, the bomb placement loop may result in an infinite loop.