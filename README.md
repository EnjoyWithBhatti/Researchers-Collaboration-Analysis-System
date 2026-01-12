# 📊 Researchers Collaboration Analysis System (C++)

## 📌 Project Description 
It is a complete **analysis system** that evaluates and visualizes collaborations among researchers.  

The system allows you to:  
- View a detailed report of any researcher along with their collaborations  
- Identify the **easiest way to approach** a researcher based on collaboration strength  
- Retrieve the **top 5 researchers** with the most collaborations  
- Find the **easiest link between two researchers**  
- List all researchers and their collaboration statistics  

The project applies **advanced data structures and algorithms** such as **AVL Trees, Max Heaps, Graphs, and Dijkstra's algorithm** to efficiently process and analyze collaboration data.

---

## 👤 Project Information
- **Course:** Data Structures  
- **Language:** C++  
- **Interface:** Console-based (Text menu)  

---

## 🛠️ Technologies & Data Structures Used
- **C++** (GCC / Visual Studio)  
- **AVL Tree**: Efficient researcher detail search  
- **Max Heap**: Find top researchers based on collaborations  
- **Graph (Adjacency Matrix)**: Store collaborations between researchers  
- **Dijkstra's Algorithm**: Find easiest paths based on collaboration "difficulty"  
- **CSV Parsing**: Read researcher and collaboration data  

---

## ✨ Features
1. **Top 5 Researchers Panel**: Displays the top 5 researchers based on number of collaborations  
2. **Detailed Researcher Report**: Shows personal details, total collaborations, and collaboration partners  
3. **Easiest Links for a Researcher**: Finds the easiest path to all other researchers  
4. **Easiest Link Between Two Researchers**: Finds the shortest/easiest link between any two researchers  
5. **All Researchers Detail**: Lists all researchers with their total collaborations  

---

## 🏗️ Project Structure
```text
Researchers_Collaboration_Analysis_System/
├── Researchers_Collaboration_Analysis_System.cpp  # Main Program
├── author_collaborations_with_data.csv            # Collaboration Matrix among Researchers
├── authors_info.csv                               # Authors Information 
└── README.md                                      # This file
```

## ▶️ How to Run the Project
1. Install a **C++ compiler** (e.g., g++, Visual Studio)  
2. Open terminal or IDE in the project directory  
3. Compile main file
4. Run the program

```bash
# Compile the main file
g++ Researchers_Collaboration_Analysis_System.cpp -o Researchers_Collaboration_Analysis_System

# Run the program
./Researchers_Collaboration_Analysis_System
```

## 🎮 How to Use
1. Launch the program to display the menu  
2. Select from the following options:  
   - **1**: Top 5 Researchers Panel  
   - **2**: Detailed Researcher Report (by ID)  
   - **3**: Easiest Links for a Researcher  
   - **4**: Easiest Link Between Two Researchers  
   - **5**: All Researchers Detail  
   - **0**: Exit  
3. Follow the on-screen instructions to input researcher numbers or IDs  

---

## 🧠 Concepts Used
- **AVL Tree** for efficient searching and traversal  
- **Max Heap** for priority-based top researcher retrieval  
- **Graphs** for storing and analyzing collaborations  
- **Dijkstra’s Algorithm** for shortest/easiest path determination  
- **File I/O & CSV parsing** for reading data  
- **Recursive and iterative traversal methods**  
- **Console-based menu system** for user interaction  

---

## 📚 Learning Outcomes
- Practical implementation of AVL Trees, Heaps, and Graphs  
- Applying Dijkstra’s algorithm to real-world problems  
- Parsing and managing CSV data in C++  
- Developing efficient data retrieval and analysis systems  
- Building a menu-driven console application  
- Working effectively as a **team in a group project**  

---

## 👨‍💻 Authors
This was a **group project** developed by:  
- **Abdul Rafay Bhatti**
- **Iqra Hayder**
- **Abbas Raza**

---

## ⭐ Acknowledgements
This project is developed as part of the **Data Structures** course at **COMSATS University Islamabad** under the supervision of **Dr. Inayat ur Rehman**.

---

## 👤 Abdul Rafay Bhatti
- GitHub: [@EnjoyWithBhatti](https://github.com/EnjoyWithBhatti)
- Facebook: [@Abdul Rafay Bhatti](https://www.facebook.com/abdulrafay.bhatti.7771/)
- Email: rafaybhatti24@gmail.com

⭐ If you found this project helpful, please consider giving it a star! ⭐
