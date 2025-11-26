# <h1 align="center">University Alumni Management System</h1>

  ----

  ## **ABSTRACT**

  A simple command-line alumni management system written in C. It lets you add, view, search, remove alumni records and persist data to a binary file (alumni_data.txt). The program supports basic fields (ID, name, department, graduation year, email, phone) and includes file-based save/load so entries persist between runs.

  ### **Features of the Program**

**1.Add Alumni**

* Add new alumni with details:
* ID
* Name
* Department
* Graduation Year
* Email
* Phone
* Automatically stored in memory

  **2.View All Alumni**

  *Displays complete alumni list in a structured format

  **3.Search Alumni**

  *Search by Alumni ID.

  **4.Remove Alumni**

*Remove an alumni record by ID.

  **5.Save Data to File**

 * Saves all alumni data to alumni_data.txt in binary format

  **6.Auto Load Data**

 * Automatically loads previously saved data at program startup.

### **Technical Requirements**

**1.Hardware Requirements**

* Minimum 2GB RAM
* Any CPU supporting basic C compilation
* 5MB storage

**2.Software Requirements**

* C Compiler (any one):
* GCC (Recommended)
* MinGW
* Turbo C++
* Visual Studio Code with C extensions
* Windows / Linux / macOS

  **3.File Requirements**

  * Program uses:
  * alumni_data.txt → binary file storing alumni records

## **Functional Requirements**

**1.User Should Be Able To:**

* Insert new alumni data
* Display all alumni records
* Search alumni information by ID
* Delete alumni record
* Save data permanently to a file
* Load previously saved data automatically

**2.System Functions:**

* Maintain array of alumni structs
* File handling for data persistence
* Validation (e.g., ID not found handling)
* Memory management within array limit (200 entries)

### **How to Run the Program**

**1.Step 1: Save the File**

* Save the full C code as:

```bash
alumni_management.c
```

**Linux / macOS**

```bash
gcc alumni_management.c -o alumni

```


**Step 2: Compile the Program**

* Windows (GCC / MinGW)

```bash

gcc alumni_management.c -o alumni
```

*Linux / macOS

```bash

gcc alumni_management.c -o alumni
```

**Step 3: Run the Program**

**Windows

```bash

alumni.exe
```

**Linux / macOS:

```bash

./alumni
```

**Step 4: File Storage**

**After running, a file is created automatically:

```bash

alumni_data.txt
```

** It stores all Alumni data permanently.


### **ScreenShots**




  
