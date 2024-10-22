# Clinica Geralt de Rivia - Binary File System

"Clinica Geralt de Rivia" system looks like a complete C-based implementation of a healthcare management system involving wizards (bruxos), patients, potions, and treatments. The code offers menu-driven options for performing CRUD (Create, Read, Update, Delete) operations on these entities, as well as managing treatments.

Overview

This project implements a healthcare management system for wizards (Bruxos), patients (Pacientes), potions (Pocoes), and treatments (Tratamentos). The data is stored in binary files to ensure persistence between program executions. The system supports CRUD operations (Create, Read, Update, Delete) for each entity, with the file system handling the storage and retrieval of records.


Features

CRUD Operations: Manage wizards, patients, potions, and treatments.
Binary File Storage: All data is saved in .bin files using the C file system (fopen, fwrite, fread, etc.).
Menu-based Interface: A user-friendly, terminal-based menu allows easy navigation through the system.
Error Handling: Ensures that no records are deleted if they are linked to active treatments.


Installation

Clone or download the project files to your local machine.
Ensure that you have a C compiler (like GCC) installed.
Compile the project using the following command:
  gcc main.c Bruxo.c Paciente.c Pocao.c Tratamento.c -o clinica
Run the compiled program:
  ./clinica


License 

@Pwn3ed
This project is open-source. Feel free to modify and distribute it according to your needs.
