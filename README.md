# 🚀 CLI Task Manager (C++)

A simple and practical **Command Line Task Manager** built using C++.
This project helps you manage daily tasks directly from the terminal with clean input handling and persistent storage.

---

## 📌 Features

- ➕ Add multiple tasks at once
- 🎯 Set priority (**High / Medium / Low**)
- ⚡ Flexible input (`h`, `high`, `H`, etc. all work)
- ✔️ Mark tasks as completed
- 🔍 Filter tasks (Completed / Pending)
- 💾 Data saved in a file (persists after closing)
- 🖥️ Clean CLI interface with simple UX

---

## 🛠️ Tech Used

- **C++**
- **File Handling**
- **Vectors & Structs**
- **CLI (Command Line Interface)**

---

## 📂 Project Structure

```
Task-Manager/
│── main.cpp
│── tasks.txt   (auto-generated)
│── README.md
```

---

## ▶️ How to Run

### 1. Clone the repository

```
git clone https://github.com/Manshu369/Task-Manager.git
cd Task-Manager
```

### 2. Compile the code

```
g++ main.cpp -o taskmanager
```

### 3. Run the program

```
./taskmanager
```

---

## 🧠 How It Works

- Tasks are stored using a **struct**
- Data is managed using a **vector**
- All tasks are saved in a file (`tasks.txt`)
- When the program starts → it loads previous tasks
- When you exit → it saves everything

---

## 🔥 Example Usage

```
1. Add Tasks
2. View Tasks
3. Mark Complete
4. Filter Tasks
5. Exit
```

---

## 🚀 Future Improvements

- 🗑️ Delete task
- ✏️ Edit task
- 📅 Add deadlines
- 🔝 Sort by priority
- 🎨 Add colored CLI output
- 🌐 Convert to Web App

---

## 💡 Learning Outcome

This project demonstrates:

- File handling in C++
- Structs and dynamic data handling
- CLI-based user interaction
- Real-world problem solving

---

## 👨‍💻 Author

**Himanshu Agrawal**
GitHub: https://github.com/Manshu369

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub!
