

## **Timetable Maker using C++**  

### **Overview**  
The Timetable Generator is a C++-based scheduling system that automates the creation of class timetables for an educational institution. It efficiently assigns subjects, professors, and batches while ensuring no scheduling conflicts. The program optimizes lecture distribution based on professor availability and batch constraints, making it a reliable tool for academic planning.  

### **Features**  
- **Automated Timetable Creation**: Generates weekly schedules for batches based on predefined subjects, professors, and lecture requirements.  
- **Professor-Centric Scheduling**: Assigns lectures based on professor availability while balancing workloads across different batches.  
- **Conflict-Free Allocation**: Prevents scheduling clashes by ensuring proper distribution of subjects and time slots.  
- **Randomized Scheduling Algorithm**: Uses shuffle operations and sorting techniques to create diverse, optimized schedules.  
- **Break Management**: Allocates necessary gaps between lectures to avoid back-to-back sessions for professors and batches.  

### **Technologies & Techniques Used**  
- **C++ Standard Library** (`vector`, `map`, `algorithm`, `random`) for efficient data storage and retrieval.  
- **Sorting and Randomization** (`std::sort`, `std::shuffle`) to ensure fair and non-repetitive scheduling.  
- **Constraint Handling** to prevent clashes in professor availability and batch schedules.  

### **Usage**  
1. Compile the C++ code using `g++ timetable_generator.cpp -o timetable`  
2. Run the program: `./timetable`  
3. Enter the required data: subjects, professors, batches, and lecture distribution.  
4. The program generates and displays a structured timetable.  

