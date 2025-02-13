# 🍽️ Philosophers – A Deadly Dining Simulation

Welcome to my Philosophers project! Here, I dive into concurrency and synchronization in C, using threads and mutexes to simulate a group of philosophers who need to eat, sleep, and think without starving—or causing deadlocks. Working on this taught me a lot about multi-threaded programming and safe resource sharing.

---

## 📖 Table of Contents

1. [About the Project 🚀](#-about-the-project)
2. [Features ✨](#-features)
3. [Prerequisites 📋](#-prerequisites)
4. [Installation & Setup 💻](#-installation--setup)
5. [Learning Outcomes 📚](#-learning-outcomes)
6. [License ⚖️](#-license)

---

## 🚀 About the Project

In this project, multiple philosophers sit around a virtual table, each equipped with a fork on their left and right. My main goal was to prevent starvation by giving each philosopher enough time to eat, sleep, and think, all while respecting concurrency rules.
I implemented this using **POSIX threads** (pthread_create, etc.) and **mutexes** to synchronize access to shared resources (the forks). The end result is a real-time simulation that tests both my understanding of **multi-threaded** development and the art of balancing concurrency and timing constraints.

---

## ✨ Features

- **Thread-Based Simulation**  
  - Each philosopher runs in its own thread, emphasizing real parallelism.

- **Mutex-Protected Forks**  
  - Fork usage is guarded by mutexes, ensuring only one philosopher can pick a particular fork at a time.  

- **Flexible Runtime Parameters**  
  - You can tweak the number of philosophers, time-to-die, time-to-eat, and more right from the command line.

- **Starvation Prevention**  
  - The simulation stops if any philosopher dies or if everyone has eaten a specified number of meals.

- **Real-Time Logging**  
  - Every philosopher’s action (eating, sleeping, thinking, or dying) is logged with millisecond timestamps.

---

## 📋 Prerequisites

- **A C compiler** (e.g., gcc or cc) supporting -Wall, -Wextra, and -Werror.
- **POSIX Threads library** (usually available on most Unix-like systems).
- **Make** (for the provided Makefile).
- Some familiarity with threads and mutexes is definitely helpful.

---

## 💻 Installation & Setup

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/philosophers.git
   cd philosophers
2. **Build the Project:**  
- I’ve provided a Makefile for easy compilation:
   ```bash
   make
---

## 🏃 Usage

1. **Run the philo program with:**
   ```bash
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
         [number_of_times_each_philosopher_must_eat]
- **number_of_philosophers**: How many philosophers (and forks) you want around the table.
- **time_to_die (ms)**: The max time a philosopher can go without eating before they die.
- **time_to_eat (ms)**: How long it takes for a philosopher to finish eating after picking up both forks.
- **time_to_sleep (ms)**: How long a philosopher sleeps after putting down their forks.
- **number_of_times_each_philosopher_must_eat**: (optional) If provided, the simulation stops once all philosophers have eaten this many times.  


**Exemple**:
Here, I’m running a simulation with 5 philosophers, each having 800 ms before starving, 200 ms to eat, and 200 ms to sleep.   
```./philo 5 800 200 200```

---

## 📚 Learning Outcomes
Here’s what I personally took away from this project:
- **Thread Management**: I learned how to create, join, and detach threads for real concurrent operations.
- **Mutex-Based Synchronization**: It was essential to protect shared resources (forks) and avoid race conditions.
- **Time & Event Handling**: Logging each philosopher’s state with millisecond precision required careful use of system calls.
- **Deadlock Prevention**: Managing resource acquisition (forks) properly is key to avoiding deadlock.
- **Performance & Debugging**: Tracking down concurrency bugs and fine-tuning the simulation made me appreciate the complexity of multi-threaded environments.

## ⚖️ License

This project is distributed under the MIT License. You are free to use, modify, and distribute it under the terms of the license.